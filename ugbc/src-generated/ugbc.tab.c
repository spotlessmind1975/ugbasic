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
  YYSYMBOL_A = 238,                        /* A  */
  YYSYMBOL_B = 239,                        /* B  */
  YYSYMBOL_C = 240,                        /* C  */
  YYSYMBOL_D = 241,                        /* D  */
  YYSYMBOL_E = 242,                        /* E  */
  YYSYMBOL_F = 243,                        /* F  */
  YYSYMBOL_G = 244,                        /* G  */
  YYSYMBOL_H = 245,                        /* H  */
  YYSYMBOL_I = 246,                        /* I  */
  YYSYMBOL_J = 247,                        /* J  */
  YYSYMBOL_K = 248,                        /* K  */
  YYSYMBOL_L = 249,                        /* L  */
  YYSYMBOL_M = 250,                        /* M  */
  YYSYMBOL_N = 251,                        /* N  */
  YYSYMBOL_O = 252,                        /* O  */
  YYSYMBOL_P = 253,                        /* P  */
  YYSYMBOL_Q = 254,                        /* Q  */
  YYSYMBOL_R = 255,                        /* R  */
  YYSYMBOL_S = 256,                        /* S  */
  YYSYMBOL_T = 257,                        /* T  */
  YYSYMBOL_U = 258,                        /* U  */
  YYSYMBOL_V = 259,                        /* V  */
  YYSYMBOL_X = 260,                        /* X  */
  YYSYMBOL_Y = 261,                        /* Y  */
  YYSYMBOL_W = 262,                        /* W  */
  YYSYMBOL_Z = 263,                        /* Z  */
  YYSYMBOL_F1 = 264,                       /* F1  */
  YYSYMBOL_F2 = 265,                       /* F2  */
  YYSYMBOL_F3 = 266,                       /* F3  */
  YYSYMBOL_F4 = 267,                       /* F4  */
  YYSYMBOL_F5 = 268,                       /* F5  */
  YYSYMBOL_F6 = 269,                       /* F6  */
  YYSYMBOL_F7 = 270,                       /* F7  */
  YYSYMBOL_F8 = 271,                       /* F8  */
  YYSYMBOL_BLACK = 272,                    /* BLACK  */
  YYSYMBOL_WHITE = 273,                    /* WHITE  */
  YYSYMBOL_RED = 274,                      /* RED  */
  YYSYMBOL_CYAN = 275,                     /* CYAN  */
  YYSYMBOL_VIOLET = 276,                   /* VIOLET  */
  YYSYMBOL_GREEN = 277,                    /* GREEN  */
  YYSYMBOL_BLUE = 278,                     /* BLUE  */
  YYSYMBOL_YELLOW = 279,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 280,                   /* ORANGE  */
  YYSYMBOL_BROWN = 281,                    /* BROWN  */
  YYSYMBOL_LIGHT = 282,                    /* LIGHT  */
  YYSYMBOL_DARK = 283,                     /* DARK  */
  YYSYMBOL_GREY = 284,                     /* GREY  */
  YYSYMBOL_GRAY = 285,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 286,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 287,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 288,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 289,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 290,                /* TURQUOISE  */
  YYSYMBOL_TAN = 291,                      /* TAN  */
  YYSYMBOL_PINK = 292,                     /* PINK  */
  YYSYMBOL_PEACH = 293,                    /* PEACH  */
  YYSYMBOL_OLIVE = 294,                    /* OLIVE  */
  YYSYMBOL_Identifier = 295,               /* Identifier  */
  YYSYMBOL_String = 296,                   /* String  */
  YYSYMBOL_Integer = 297,                  /* Integer  */
  YYSYMBOL_298_0_ = 298,                   /* "0"  */
  YYSYMBOL_299_1_ = 299,                   /* "1"  */
  YYSYMBOL_300_2_ = 300,                   /* "2"  */
  YYSYMBOL_301_3_ = 301,                   /* "3"  */
  YYSYMBOL_302_4_ = 302,                   /* "4"  */
  YYSYMBOL_303_5_ = 303,                   /* "5"  */
  YYSYMBOL_304_6_ = 304,                   /* "6"  */
  YYSYMBOL_305_7_ = 305,                   /* "7"  */
  YYSYMBOL_306_8_ = 306,                   /* "8"  */
  YYSYMBOL_307_9_ = 307,                   /* "9"  */
  YYSYMBOL_308_ = 308,                     /* " "  */
  YYSYMBOL_YYACCEPT = 309,                 /* $accept  */
  YYSYMBOL_expr = 310,                     /* expr  */
  YYSYMBOL_expr_math = 311,                /* expr_math  */
  YYSYMBOL_term = 312,                     /* term  */
  YYSYMBOL_modula = 313,                   /* modula  */
  YYSYMBOL_factor = 314,                   /* factor  */
  YYSYMBOL_direct_integer = 315,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 316, /* random_definition_simple  */
  YYSYMBOL_random_definition = 317,        /* random_definition  */
  YYSYMBOL_color_enumeration = 318,        /* color_enumeration  */
  YYSYMBOL_key_scancode_alphadigit = 319,  /* key_scancode_alphadigit  */
  YYSYMBOL_key_scancode_function_digit = 320, /* key_scancode_function_digit  */
  YYSYMBOL_key_scancode_definition = 321,  /* key_scancode_definition  */
  YYSYMBOL_exponential = 322,              /* exponential  */
  YYSYMBOL_323_1 = 323,                    /* $@1  */
  YYSYMBOL_324_2 = 324,                    /* $@2  */
  YYSYMBOL_325_3 = 325,                    /* $@3  */
  YYSYMBOL_position = 326,                 /* position  */
  YYSYMBOL_bank_definition_simple = 327,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 328, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 329,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 330, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 331, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 332,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 333, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 334, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 335,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 336,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 337, /* color_definition_expression  */
  YYSYMBOL_color_definition = 338,         /* color_definition  */
  YYSYMBOL_milliseconds = 339,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 340,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 341, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 342,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 343, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 344, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 345,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 346, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 347, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 348,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 349, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 350, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 351,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 352,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 353, /* text_definition_expression  */
  YYSYMBOL_text_definition = 354,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 355,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 356, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 357,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 358, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 359, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 360,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 361, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 362, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 363,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 364,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 365,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 366,         /* gosub_definition  */
  YYSYMBOL_var_definition = 367,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 368,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 369, /* point_definition_expression  */
  YYSYMBOL_point_definition = 370,         /* point_definition  */
  YYSYMBOL_ink_definition = 371,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 372,       /* on_goto_definition  */
  YYSYMBOL_373_4 = 373,                    /* $@4  */
  YYSYMBOL_on_gosub_definition = 374,      /* on_gosub_definition  */
  YYSYMBOL_375_5 = 375,                    /* $@5  */
  YYSYMBOL_on_proc_definition = 376,       /* on_proc_definition  */
  YYSYMBOL_377_6 = 377,                    /* $@6  */
  YYSYMBOL_on_definition = 378,            /* on_definition  */
  YYSYMBOL_379_7 = 379,                    /* $@7  */
  YYSYMBOL_380_8 = 380,                    /* $@8  */
  YYSYMBOL_381_9 = 381,                    /* $@9  */
  YYSYMBOL_every_definition = 382,         /* every_definition  */
  YYSYMBOL_add_definition = 383,           /* add_definition  */
  YYSYMBOL_dimensions = 384,               /* dimensions  */
  YYSYMBOL_datatype = 385,                 /* datatype  */
  YYSYMBOL_dim_definition = 386,           /* dim_definition  */
  YYSYMBOL_387_10 = 387,                   /* $@10  */
  YYSYMBOL_388_11 = 388,                   /* $@11  */
  YYSYMBOL_389_12 = 389,                   /* $@12  */
  YYSYMBOL_dim_definitions = 390,          /* dim_definitions  */
  YYSYMBOL_indexes = 391,                  /* indexes  */
  YYSYMBOL_parameters = 392,               /* parameters  */
  YYSYMBOL_parameters_expr = 393,          /* parameters_expr  */
  YYSYMBOL_values = 394,                   /* values  */
  YYSYMBOL_print_definition = 395,         /* print_definition  */
  YYSYMBOL_396_13 = 396,                   /* $@13  */
  YYSYMBOL_397_14 = 397,                   /* $@14  */
  YYSYMBOL_writing_mode_definition = 398,  /* writing_mode_definition  */
  YYSYMBOL_writing_part_definition = 399,  /* writing_part_definition  */
  YYSYMBOL_writing_definition = 400,       /* writing_definition  */
  YYSYMBOL_locate_definition = 401,        /* locate_definition  */
  YYSYMBOL_cmove_definition = 402,         /* cmove_definition  */
  YYSYMBOL_hscroll_definition = 403,       /* hscroll_definition  */
  YYSYMBOL_vscroll_definition = 404,       /* vscroll_definition  */
  YYSYMBOL_statement = 405,                /* statement  */
  YYSYMBOL_406_15 = 406,                   /* $@15  */
  YYSYMBOL_407_16 = 407,                   /* $@16  */
  YYSYMBOL_408_17 = 408,                   /* $@17  */
  YYSYMBOL_409_18 = 409,                   /* $@18  */
  YYSYMBOL_410_19 = 410,                   /* $@19  */
  YYSYMBOL_411_20 = 411,                   /* $@20  */
  YYSYMBOL_412_21 = 412,                   /* $@21  */
  YYSYMBOL_413_22 = 413,                   /* $@22  */
  YYSYMBOL_statements_no_linenumbers = 414, /* statements_no_linenumbers  */
  YYSYMBOL_415_23 = 415,                   /* $@23  */
  YYSYMBOL_statements_with_linenumbers = 416, /* statements_with_linenumbers  */
  YYSYMBOL_417_24 = 417,                   /* $@24  */
  YYSYMBOL_statements_complex = 418,       /* statements_complex  */
  YYSYMBOL_419_25 = 419,                   /* $@25  */
  YYSYMBOL_program = 420,                  /* program  */
  YYSYMBOL_421_26 = 421                    /* $@26  */
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
#define YYLAST   5218

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  309
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  614
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1128

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   563


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
     305,   306,   307,   308
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
     969,   972,   976,   980,   984,   988,   992,   996,  1000,  1004,
    1008,  1012,  1016,  1021,  1021,  1024,  1027,  1030,  1033,  1036,
    1039,  1043,  1046,  1049,  1052,  1056,  1059,  1062,  1065,  1069,
    1072,  1075,  1078,  1084,  1087,  1090,  1093,  1096,  1101,  1102,
    1105,  1108,  1113,  1116,  1121,  1122,  1125,  1128,  1133,  1136,
    1141,  1142,  1145,  1148,  1151,  1156,  1159,  1162,  1167,  1168,
    1171,  1172,  1173,  1176,  1179,  1182,  1185,  1191,  1194,  1197,
    1203,  1204,  1207,  1210,  1213,  1216,  1219,  1222,  1225,  1228,
    1231,  1234,  1237,  1240,  1243,  1246,  1249,  1254,  1257,  1260,
    1263,  1266,  1269,  1272,  1275,  1278,  1281,  1284,  1287,  1290,
    1293,  1296,  1301,  1302,  1305,  1308,  1311,  1314,  1317,  1323,
    1326,  1332,  1333,  1336,  1341,  1346,  1347,  1350,  1353,  1358,
    1361,  1366,  1367,  1370,  1375,  1380,  1381,  1384,  1387,  1390,
    1395,  1398,  1404,  1405,  1408,  1411,  1414,  1417,  1420,  1425,
    1428,  1431,  1436,  1437,  1439,  1440,  1443,  1446,  1449,  1454,
    1461,  1464,  1470,  1473,  1479,  1482,  1488,  1493,  1494,  1497,
    1502,  1506,  1506,  1511,  1515,  1515,  1520,  1524,  1524,  1529,
    1529,  1532,  1532,  1535,  1535,  1540,  1543,  1546,  1551,  1554,
    1560,  1564,  1571,  1574,  1577,  1580,  1583,  1586,  1589,  1592,
    1595,  1598,  1603,  1603,  1611,  1611,  1619,  1619,  1630,  1631,
    1635,  1639,  1646,  1651,  1656,  1661,  1666,  1671,  1679,  1684,
    1689,  1694,  1699,  1704,  1709,  1713,  1720,  1724,  1731,  1734,
    1738,  1741,  1741,  1745,  1745,  1751,  1755,  1759,  1763,  1767,
    1774,  1778,  1782,  1786,  1790,  1797,  1803,  1806,  1809,  1815,
    1818,  1821,  1827,  1830,  1833,  1836,  1842,  1845,  1851,  1852,
    1853,  1854,  1855,  1856,  1857,  1858,  1859,  1860,  1861,  1862,
    1863,  1864,  1865,  1866,  1869,  1870,  1871,  1872,  1873,  1876,
    1879,  1880,  1881,  1882,  1885,  1888,  1891,  1894,  1897,  1900,
    1903,  1906,  1909,  1912,  1915,  1918,  1921,  1924,  1927,  1930,
    1933,  1936,  1939,  1942,  1945,  1948,  1948,  1953,  1956,  1959,
    1962,  1965,  1968,  1971,  1974,  1977,  1980,  1983,  1986,  1989,
    1992,  1996,  1996,  2001,  2004,  2007,  2010,  2013,  2016,  2020,
    2024,  2028,  2028,  2033,  2033,  2038,  2038,  2043,  2046,  2049,
    2052,  2055,  2056,  2059,  2062,  2065,  2068,  2071,  2074,  2075,
    2076,  2077,  2078,  2081,  2084,  2087,  2090,  2093,  2096,  2099,
    2102,  2103,  2112,  2121,  2121,  2133,  2133,  2150,  2150,  2167,
    2170,  2171,  2175,  2176,  2176,  2180,  2180,  2187,  2187,  2190,
    2191,  2192,  2193,  2197,  2197
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
  "LOCK", "ALT", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K",
  "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "X", "Y", "W",
  "Z", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "BLACK", "WHITE",
  "RED", "CYAN", "VIOLET", "GREEN", "BLUE", "YELLOW", "ORANGE", "BROWN",
  "LIGHT", "DARK", "GREY", "GRAY", "MAGENTA", "PURPLE", "LAVENDER", "GOLD",
  "TURQUOISE", "TAN", "PINK", "PEACH", "OLIVE", "Identifier", "String",
  "Integer", "\"0\"", "\"1\"", "\"2\"", "\"3\"", "\"4\"", "\"5\"", "\"6\"",
  "\"7\"", "\"8\"", "\"9\"", "\" \"", "$accept", "expr", "expr_math",
  "term", "modula", "factor", "direct_integer", "random_definition_simple",
  "random_definition", "color_enumeration", "key_scancode_alphadigit",
  "key_scancode_function_digit", "key_scancode_definition", "exponential",
  "$@1", "$@2", "$@3", "position", "bank_definition_simple",
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
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563
};
#endif

#define YYPACT_NINF (-996)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-594)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -996,    75,  1086,  -996,  -996,  -217,  -206,  3693,    -8,  -996,
     120,  2852,    74,   -12,  3128,  -996,    68,   191,  3693,  -189,
    -122,  -996,  -996,  -996,  2300,   123,    33,  3693,  3693,   -99,
     128,   -32,  -996,   137,   169,  3693,  3693,  -996,   184,   219,
     -47,  3693,   117,   207,  -996,   -17,  -996,  3693,     1,  2576,
     259,    24,  3693,    63,    67,    69,    70,   -67,   -67,  3693,
    3693,   205,    19,  1457,  -996,  -996,  1748,  3693,  3693,   141,
    -996,  -996,  -996,  -996,  3693,  -996,  -996,    41,   309,   344,
      10,  -996,   357,   362,   363,  -996,  -996,  -996,    71,   349,
    2024,  -996,  -996,   330,   331,   332,    83,  -996,  -996,    17,
    -996,  -996,    -4,    -1,  3693,  -996,  -996,   336,   339,   340,
     358,   359,   360,   361,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   374,  -996,  -996,   377,    44,   -35,    21,
     353,   355,   398,   405,   406,   407,   408,  -996,  -996,  -996,
       4,   389,  4521,  -996,   390,   391,   392,   393,   394,   395,
    -996,  -996,   -37,   177,  -996,  -996,  4911,   396,  -996,  -996,
     201,   190,  -996,  -996,  -996,  -996,  -996,  -996,  -996,   161,
    -996,  -996,   -19,   -80,  -996,  -996,  -996,  -996,  -996,  -996,
    -996,  -996,  -996,   162,    28,  -996,  -996,   302,    78,   307,
     296,   188,  -996,  -996,  -996,  3128,   411,  -996,  -996,  -996,
    3128,  3128,  3128,  -996,  -996,  -996,   145,  4911,    -9,    -6,
    -996,  -996,  -996,    -5,   417,    -3,     2,     3,     5,   414,
    -996,  -996,  -996,   175,   231,  -996,  -996,  -996,  3128,  -996,
    -996,   410,  -996,  -996,  -996,  -996,  -996,  3128,   397,   399,
    -996,  -996,  -996,     7,  -996,    61,  -996,  -996,  -996,  -996,
    -996,  3693,  3417,  -996,  -996,   439,  -996,  -996,  -996,  3128,
    -996,  -996,  -996,  3128,   412,  -996,  -996,  -996,   373,  -996,
    -996,  -996,  -996,   300,  3693,  3693,  -996,  -996,  3128,  -996,
    -996,  -996,   413,  -996,  -996,  -996,  -996,  -996,  -996,  -996,
    -996,  3693,  3693,  -996,  -996,  -996,  -996,   441,  -996,  -996,
     297,  -996,  3693,   448,  -996,  -996,  -996,    54,   449,  -996,
     308,   310,   311,    62,   450,  -996,  -996,  -996,  -996,  -996,
    -996,  -996,  -996,  -996,  -996,  -996,   452,  -996,  3693,   455,
    -996,  3693,   456,  -996,  -996,  -996,  3693,  -996,   213,  -996,
    -996,  -996,   235,  -996,  3693,  -996,  -996,  3693,   451,  -996,
    -996,   425,    23,  1272,  -996,  1086,  1086,  -996,   426,   427,
     428,   429,   430,   431,   197,   432,  3693,  3128,  3128,  -996,
    -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,   434,  -996,
    -996,  3693,  -996,  -996,  3693,  -996,  -996,  -996,  3693,  3693,
    3693,  3693,  3693,  3693,  3693,  3693,  3693,  3693,  3693,  3693,
    3693,  3693,  3693,  3693,  3693,  3969,   435,   172,  -996,  -996,
     436,  -996,  -996,   437,   438,  -996,  -996,  -996,  -996,  -996,
    3693,  -996,  3693,  2024,   440,   454,  3693,  3693,  3693,  3693,
    3693,  3693,  -996,  -996,  -996,  -996,  -996,  -996,   261,   262,
    -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,
     227,  -996,  -996,  -996,   232,  -996,  -996,  -996,  -996,  -996,
     256,  -996,  -996,   444,  -996,  -996,  -996,  -996,  -996,  -996,
    -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,
    -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,
    -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,
    -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,
    -996,  3693,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,
    -996,  -996,  -996,   445,  -996,   446,   266,   304,  3969,  3969,
    3969,  3969,  3969,  3969,  3969,  3969,  3969,  3969,  3969,  3969,
    3969,   -62,  4245,  4797,   453,   457,  3128,  -996,  -996,   409,
     415,   416,   418,  -996,  -996,  -996,  -996,  -996,  -996,  -996,
    -996,  -996,  -996,  3128,   459,  -996,  -996,  -996,   443,   417,
     460,   417,   461,   417,   465,   417,   468,   417,  -996,  3693,
     462,  -996,  -996,   271,   273,    40,   150,  -996,  -996,  -996,
     463,   417,   466,  -996,  -996,   276,   279,   165,   183,  -996,
    -996,   467,  -996,  -996,  3128,  -996,  -996,  3128,  3128,  -996,
    -996,  -996,   458,   204,  -996,   493,  3693,  -996,  -996,  -996,
    -996,  3128,  -996,  3693,   495,   501,  -996,  -996,  3128,   442,
     502,  3693,   404,   504,  3693,  -996,  -996,  -996,  -996,  -996,
    -996,   225,  -996,  -996,   472,   494,    63,  -996,   375,  -996,
     -67,   506,    23,   -67,   -43,  -996,  3693,  -996,  3693,  -996,
    -996,  -996,  -996,  -996,  -996,  1086,  -996,  3693,   475,  3693,
    3693,   476,    18,  -996,  1272,  -996,  -996,  3693,   221,   222,
     223,   224,   226,   481,   483,   485,  -996,   486,   488,   489,
     490,   491,  3693,   529,   530,   531,   533,   500,   503,   505,
     507,   535,   508,   509,   510,   511,   512,   536,   538,   513,
     514,   516,   200,   263,   518,  3693,  3693,  3693,   519,    58,
     100,  3693,  3969,   521,   522,   523,   524,   525,   526,  -996,
    -996,   471,   470,  -996,  -996,  -996,  3693,   532,   534,  3693,
    3693,  3693,  3693,   307,   307,   335,   335,   335,   335,   335,
     335,   335,   335,   296,   188,   188,   380,  4797,  4797,  -996,
    -996,   280,   281,  -996,  -996,  3693,   417,  3693,   417,   542,
     543,  3128,   136,  -996,   417,  -996,   417,  -996,   417,  -996,
     417,   154,  -996,  3693,  -996,  -996,  -996,  -996,  -996,  -996,
    -996,  -996,  3693,  -996,   417,  -996,  -996,  -996,  -996,  -996,
    -996,  -996,  -996,   417,  -996,  -996,  -996,  -996,  -996,  -996,
     284,   285,   286,   287,   570,  3693,   577,   537,   539,   447,
    3693,  3693,   579,   581,  -996,   -18,   515,   294,  3693,   583,
    -996,  -996,  -996,   551,   298,   554,  -996,  3693,   312,  3693,
    -996,   -67,   592,  -996,   464,   469,  -996,  -996,  -996,  -996,
    -996,  -996,  3693,   596,   474,   597,   565,  3693,  -996,   601,
    -996,  -996,  -996,  -996,  -996,   313,   315,   316,  -996,  -996,
    -996,  -996,  -996,   574,  3693,  3693,  3693,  3693,  -996,  -996,
    -996,  -996,  3693,  -996,  -996,  -996,  -996,  -996,  3693,  3693,
    -996,  -996,  -996,  4797,   578,  -996,   582,   613,   615,  -996,
    3693,  -996,  3693,   619,   605,  -996,  -996,  -996,  -996,  -996,
    -996,  -996,  -996,   588,  -996,  3693,   479,   590,  -996,  -996,
    4797,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,   338,
     341,  -996,  -996,  -996,  -996,  -996,  -996,   599,  -996,   600,
    -996,   342,   148,  -996,   632,  -996,   633,   634,  -996,   635,
    -996,   636,  -996,   631,  3128,   638,  3693,  3693,   417,  -996,
     606,   607,  3693,   417,  -996,  -996,  3693,  -996,   115,  3693,
     298,   639,   609,   298,   517,   101,   520,   527,  -996,   -67,
    -996,  -996,   611,  3693,  -996,  3693,   640,   614,  3693,  -996,
    -996,  -996,  -996,   616,   617,   126,   144,   618,   620,   622,
     623,  -996,  -996,  3693,  3693,   624,   625,  -996,   626,  -996,
    -996,  -996,  -996,  -996,   376,   378,  -996,   621,  -996,   641,
    -996,  3693,   417,   647,   662,   666,  3693,  -996,  -996,  3693,
    -996,  -996,  -996,   664,   667,   642,   643,   556,  3693,   668,
     604,   645,   298,  -996,   648,  -996,   312,   672,    23,  -996,
    -996,  -996,   677,  -996,  -996,  3693,   678,   651,  -996,  -996,
    3693,  -996,  3693,  -996,  -996,  -996,  -996,  -996,   652,   653,
    -996,  -996,  -996,  -996,  -996,   400,   402,   654,   658,   284,
     285,   286,  -996,  -996,  3693,  3693,  -996,  -996,  3693,   661,
    3693,  3693,  -996,  -996,  -996,  -996,   312,   696,  3693,  -996,
    3693,  -996,   663,   665,  -996,  -996,  -996,  -996,  -996,  -996,
    -996,  -996,  -996,  -996,  -996,  -996,   692,  -996,  -996,  -996,
     312,  -996,  -996,  -996,  -996,  3693,  -996,  -996
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     613,     0,   601,     1,   600,     0,     0,     0,     0,   585,
       0,     0,   549,     0,     0,   576,     0,     0,     0,   384,
       0,   534,   538,   535,     0,     0,     0,     0,     0,     0,
       0,   577,   532,     0,     0,     0,   527,   575,     0,     0,
       0,   582,   584,   530,   533,   540,   537,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   522,   523,     0,     0,     0,     0,
     513,   514,   515,   516,   517,   508,   509,     0,     0,     0,
     597,   605,   602,   609,   611,   614,   525,   526,     0,     0,
       0,   157,   158,     0,     0,     0,     0,   201,   202,     0,
     227,   228,   229,   230,     0,   192,   193,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   194,   203,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   214,   215,   216,
       0,     0,     0,   225,   231,     0,     0,     0,     0,     0,
     232,   233,     0,     0,   237,   247,     0,     0,   239,   245,
       0,     0,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,     0,     0,    49,    54,    55,    56,    57,    58,
      59,    62,    63,     0,   142,   146,   144,   458,     2,    12,
      15,    17,   155,    20,   506,     0,     0,   284,   285,   489,
       0,     0,     0,   298,   299,   491,     0,   306,     0,     0,
     310,   311,   492,     0,     0,     0,     0,     0,     0,     0,
     278,   279,   488,     0,     0,   342,   343,   493,     0,   345,
     346,   347,   351,   352,   494,   374,   375,     0,     0,     0,
     382,   383,   499,     0,   578,     0,   394,   502,   390,   391,
     579,     0,     0,   357,   358,     0,   361,   362,   496,     0,
     365,   366,   497,     0,   368,   372,   373,   498,     0,   567,
     524,   573,   574,   555,     0,     0,   599,   528,     0,   355,
     356,   495,     0,   397,   398,   500,   392,   393,   580,   583,
     542,     0,     0,   541,   544,   545,   539,     0,   416,   417,
       0,   581,     0,     0,   504,   399,   501,   432,   438,   590,
     559,   550,   560,   448,   454,   553,   554,   505,   568,   569,
     570,   468,   466,   465,   467,   469,     0,   571,     0,     0,
     507,     0,     0,   512,   520,   521,     0,   518,     0,   482,
     484,   510,     0,   511,     0,   607,   572,     0,   595,   561,
     558,     0,     0,   601,   603,   601,   601,   145,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      29,    30,    32,    34,    35,    31,    36,   181,     0,   195,
     196,     0,   241,   248,     0,   243,   250,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   197,   200,
       0,   198,   199,     0,     0,   213,   207,   208,   209,   210,
       0,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   234,   238,   242,   244,   111,   112,     0,     0,
     132,   137,   122,   240,   108,   110,   113,   114,   115,   116,
       0,   119,   120,   123,     0,   128,   129,   130,   131,   133,
       0,   135,   136,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,   109,   121,
     252,     0,   246,   249,   251,    60,    47,    50,    51,    52,
      53,    48,    61,   143,   188,     0,   463,   461,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295,   292,     0,
       0,     0,     0,    28,   300,   307,   301,   302,   308,   309,
     303,   304,   305,     0,     0,   290,   291,   490,   255,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   254,     0,
       0,   332,   333,     0,     0,     0,     0,   329,   328,   253,
       0,     0,     0,   317,   318,     0,     0,     0,     0,   314,
     313,     0,   349,   344,     0,   379,   376,     0,     0,   409,
     413,   411,     0,     0,   536,     0,     0,   364,   363,   370,
     367,     0,   529,     0,     0,     0,   354,   353,     0,     0,
     543,     0,     0,     0,     0,   430,   422,   424,   429,   426,
     431,     0,   428,   436,     0,     0,     0,   563,     0,   565,
       0,   449,     0,     0,     0,   476,   477,   479,   480,   519,
     483,   485,   486,   487,   503,   601,   591,     0,     0,     0,
       0,     0,   597,   606,   601,   610,   612,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   183,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   127,
     125,     0,     0,   126,   124,   134,     0,     0,     0,     0,
       0,     0,     0,    13,    14,     5,     7,     8,     9,    10,
       6,     3,     4,    16,    18,    19,     0,     0,     0,    25,
      21,     0,     0,   282,   280,     0,     0,     0,     0,     0,
       0,     0,     0,   260,     0,   272,     0,   264,     0,   268,
       0,   256,   330,     0,   337,   336,   341,   340,   335,   339,
     334,   338,     0,   315,     0,   322,   321,   326,   325,   320,
     324,   319,   323,     0,   350,   348,   380,   377,   381,   378,
       0,     0,     0,     0,   385,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   531,     0,     0,     0,     0,   418,
     423,   425,   427,     0,     0,     0,   439,     0,     0,     0,
     451,     0,   450,   455,   473,   471,   470,   475,   478,   481,
     608,   592,     0,   456,     0,   440,     0,     0,   604,     0,
     154,   147,   149,   153,   151,     0,     0,     0,   156,   160,
     159,   162,   161,     0,     0,     0,     0,     0,   169,   170,
     171,   180,     0,   174,   175,   176,   177,   178,     0,     0,
     190,   191,   182,     0,     0,   186,     0,     0,     0,   217,
       0,   172,     0,     0,    27,   223,   218,   219,   220,   221,
     222,   118,   117,     0,   236,     0,     0,     0,   464,   462,
       0,    23,    26,   283,   281,   297,   294,   296,   293,     0,
       0,   288,   286,   257,   270,   262,   265,   259,   271,   263,
     267,     0,     0,   327,     0,   312,     0,   400,   410,   403,
     414,   406,   412,   386,     0,     0,     0,     0,     0,   556,
       0,     0,     0,     0,   546,   547,     0,   415,     0,     0,
       0,   420,     0,     0,     0,   442,     0,     0,   452,     0,
     474,   472,     0,     0,   562,     0,     0,     0,     0,   148,
     150,   152,   204,     0,     0,     0,     0,     0,     0,     0,
       0,   187,   205,     0,     0,     0,     0,   235,     0,   189,
     139,    24,   289,   287,     0,     0,   273,   258,   269,   261,
     266,     0,     0,     0,     0,     0,     0,   388,   387,     0,
     360,   371,   369,     0,     0,     0,     0,   548,     0,     0,
       0,     0,     0,   433,     0,   564,     0,   443,     0,   552,
     566,   453,     0,   457,   441,     0,     0,     0,   163,   164,
       0,   165,     0,   167,   179,   185,   184,    22,     0,     0,
     173,   226,   141,   275,   277,     0,     0,     0,     0,     0,
       0,     0,   389,   359,     0,     0,   396,   395,     0,     0,
       0,     0,   437,   421,   435,   445,     0,   444,     0,   594,
       0,   211,     0,     0,   212,   206,   274,   276,   331,   316,
     402,   405,   408,   586,   587,   557,     0,   588,   419,   446,
       0,   596,   598,   166,   168,     0,   447,   589
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -996,    -7,  -182,  -183,   173,  -402,   333,  -996,  -996,  -996,
    -996,  -996,  -996,  -140,  -996,  -996,  -996,   492,  -996,  -996,
    -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,
     498,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,
    -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,
    -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,
    -996,  -996,  -996,  -367,  -996,  -365,  -996,  -368,  -996,  -996,
    -996,  -996,  -996,  -996,  -996,  -900,  -351,  -996,  -996,  -996,
    -996,    72,  -725,  -995,   -48,  -720,   -54,  -996,  -996,  -996,
    -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,  -996,
    -996,  -996,  -996,  -996,  -996,  -347,  -996,  -996,  -996,  -343,
    -996,  -996,  -996
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   855,   188,   189,   190,   191,   209,   376,   377,   192,
     508,   509,   510,   193,   525,   738,   739,   590,   220,   221,
     222,   197,   198,   199,   565,   566,   567,   203,   204,   205,
     559,   210,   211,   212,   225,   226,   227,   232,   233,   234,
     279,   280,   281,   256,   257,   258,   260,   261,   262,   265,
     266,   267,   240,   241,   242,   246,   250,   288,   247,   283,
     284,   285,   306,   948,  1023,   950,  1024,   952,  1025,   244,
     810,   812,   811,   301,   304,   972,   643,   308,   644,   645,
     833,   309,   856,   976,   315,   854,   194,   742,   741,   326,
     847,   327,   330,   333,   341,   343,    82,   251,   648,   669,
     837,   839,   351,   668,   352,    83,   674,    84,   353,    85,
     665,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     187,   671,   425,   712,   208,   317,   673,   223,   206,   206,
     316,   243,   675,   676,   345,   917,   346,   255,   214,   916,
     268,   269,   195,   347,   346,   563,   215,   569,   276,   277,
     348,   347,   571,   573,   289,   575,   381,   378,   348,   384,
     296,   410,   300,   216,   420,   305,   432,   844,   523,   756,
    -593,  1095,   187,   318,   635,   408,   329,   292,  -593,   332,
     334,   335,   272,   263,   406,   900,   609,   337,  -138,   650,
    1041,   217,   218,  1044,  -434,     3,   554,   555,    86,   554,
     560,   612,   651,   365,   407,   635,   528,   529,   338,    87,
     530,   788,   531,   532,   533,   534,   535,   387,   228,   901,
     789,  1119,   213,   636,   637,   638,   245,   902,  1046,   613,
     229,   230,   639,   610,   369,   273,   652,   974,   845,   977,
     321,  1047,  1038,   846,   264,  1126,   409,   982,   322,   757,
     293,   270,   987,  1060,   636,   637,   638,   754,   755,   339,
     340,   686,  1093,   639,   556,   557,   558,   556,   557,   561,
     640,  1062,   200,   259,   611,  1048,  1039,   201,   379,   231,
     349,   641,   411,   370,   371,   372,   433,  1061,   349,   642,
     373,   374,   375,   248,   933,   249,   380,   274,   524,   536,
     412,   640,   323,   324,   325,  1063,  1017,   537,   544,   941,
    1008,   934,   641,   547,   549,   551,   421,   202,   520,   382,
     642,   790,   385,  1018,   521,   578,   579,   893,   942,   275,
     791,   541,   542,   580,   278,   543,   799,   581,   582,   935,
     936,   602,   271,   541,   542,   800,   583,   543,   313,   314,
     605,  1019,  1020,   383,   801,   584,   386,   585,   586,   235,
     236,   237,   238,   802,   614,   615,   587,   588,   286,   282,
     287,   239,   617,   319,   320,   516,   619,   589,   517,   518,
    1054,   578,   591,  1053,   290,   519,  -460,   624,   625,   592,
    -460,   626,  -460,   593,   594,   434,   435,   683,   684,   964,
     294,   291,   595,   219,   629,   630,   685,   196,   513,   514,
     564,   596,   570,   597,   598,   633,   297,   572,   574,   302,
     576,   842,   599,   600,  -459,   830,   831,   526,  -459,   527,
    -459,   660,   661,   589,   832,   539,   336,   540,   350,   303,
     904,   655,   850,   731,   657,   732,   350,   858,   733,   659,
     734,   662,   663,   784,   785,   786,   787,   664,   795,   796,
     666,   797,   798,   528,   529,   743,   744,   224,   745,   746,
     747,   748,   749,   750,   751,   752,   342,   344,   307,   687,
     688,   690,   310,   354,   311,   312,   355,   356,   357,   358,
     366,   367,   368,   413,   693,   414,   388,   694,   295,   389,
     390,   695,   696,   697,   698,   699,   700,   701,   702,   703,
     704,   705,   706,   707,   708,   709,   710,   711,   391,   392,
     393,   394,   759,   760,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   718,   404,   719,   720,   405,   415,   723,
     724,   725,   726,   727,   728,   416,   417,   418,   419,   422,
     426,   427,   428,   429,   430,   431,   511,   512,   515,   522,
     538,   546,   553,   206,   577,   604,   616,   621,   622,   607,
     623,   608,   632,   628,   631,   634,   646,   653,   647,   654,
    -551,   649,   656,   658,   667,   670,   677,   714,   678,   679,
     680,   681,   682,   686,   692,   713,   715,   716,   717,   722,
     721,   729,   730,   735,   736,  -140,   740,   765,   761,   771,
     774,   776,   762,   766,   767,   778,   768,   772,   780,   814,
     815,   783,   820,   792,   737,   794,   813,   803,   821,   825,
     827,   828,   834,   841,   835,   852,   857,   824,   860,   861,
     862,   863,   865,   864,   866,   838,   867,   868,   545,   869,
     870,   871,   872,   548,   550,   552,   874,   875,   876,   763,
     877,   878,   882,   888,   879,   889,   880,   568,   881,   883,
     884,   885,   886,   887,   890,   891,   769,   892,   894,   895,
     899,   603,   905,   906,   907,   908,   909,   910,   911,   912,
     606,   920,   782,   914,   915,   923,   924,   929,   930,   947,
     949,   951,   953,   954,   956,   957,   962,   958,   963,   967,
     969,   970,   618,   966,   973,   971,   620,   804,   959,   979,
     806,   808,   840,   983,   985,   843,   986,   975,   988,   816,
     989,   627,   990,   991,   817,   992,   819,   921,   922,  1001,
    1003,   822,  1004,  1002,   826,   984,   902,   829,   541,  1007,
    1009,  1010,   980,  1012,  1014,  1015,  1013,   981,  1016,  1021,
    1022,  -401,  -404,  -407,  1026,  1029,  1042,  1033,  1034,   848,
    1043,   849,  1052,  1055,  1079,  1056,  1075,  1058,  1059,  1064,
     851,  1065,   853,  1066,  1067,  1070,  1071,  1072,  1045,  1080,
     859,  1049,  1073,  1081,  1074,  1088,  1076,  1084,  1050,  1096,
    1085,  1090,  1091,  1086,  1087,   873,  1092,   918,   919,  1094,
    1098,  1100,  1101,  1104,  1105,  1108,  1106,  1097,  1107,  1109,
     689,   691,  1116,  1120,  1123,  1125,  1124,   562,   896,   897,
     898,   753,  1110,  1112,   903,  1111,   601,     0,   836,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   913,
       0,     0,   853,     0,   187,   187,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1000,     0,     0,     0,     0,   925,     0,
     927,     0,     0,     0,   931,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   943,     0,     0,     0,
    1011,     0,     0,     0,     0,   944,     0,     0,     0,     0,
       0,     0,     0,   978,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   955,     0,
       0,     0,     0,   960,   961,     0,     0,     0,     0,     0,
       0,   968,     0,     0,     0,     0,     0,     0,     0,     0,
     853,     0,   853,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   993,   994,   995,
     996,     0,     0,     0,     0,   997,     0,     0,     0,   764,
       0,   998,   999,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1005,     0,  1006,   770,     0,     0,     0,
       0,     0,   773,     0,   775,     0,   777,     0,   779,     0,
     781,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   793,     0,     0,     0,     0,     0,
       0,  1051,     0,     0,     0,     0,     0,   805,     0,     0,
     807,   809,     0,     0,     0,     0,     0,  1027,     0,  1030,
    1031,     0,     0,     0,   818,  1035,     0,     0,     0,  1037,
       0,   823,  1040,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   853,     0,     0,     0,
       0,  1057,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1068,  1069,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1077,     0,     0,     0,     0,  1082,
       0,     0,  1083,     0,     0,     0,     0,     0,     0,     0,
       0,  1089,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1099,     0,
       0,     0,     0,  1102,     0,  1103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1113,  1114,     0,
       0,  1115,     0,  1117,  1118,     0,     0,     0,     0,     4,
       0,  1121,     0,  1122,     0,     0,     5,     6,     0,   926,
       0,   928,     0,     0,   932,     0,     0,   937,     7,   938,
       0,   939,     0,   940,     8,     9,     0,    10,  1127,    11,
      12,     0,    13,    14,     0,     0,     0,   945,     0,     0,
      15,     0,    16,    17,    18,     0,   946,     0,     0,    19,
       0,     0,     0,     0,     0,    20,     0,     0,     0,     0,
      21,    22,    23,    24,    25,    26,     0,     0,   965,     0,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,    29,    30,    31,
       0,    32,     0,     0,    33,    34,    35,     0,    36,    37,
      38,    39,    40,    41,    42,     0,    43,     0,     0,     0,
      44,    45,    46,    47,    48,     0,    49,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,    52,     0,
       0,    53,     0,    54,    55,    56,     0,     0,    57,     0,
       0,     0,    58,     0,    59,     0,     0,    60,    61,     0,
       0,     0,     0,    62,     0,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,    74,     0,     0,
      75,    76,    77,    78,    79,     4,     0,     0,     0,     0,
       0,     0,     5,     6,     0,     0,     0,  1028,     0,     0,
       0,  1032,     0,     0,     7,     0,  1036,     0,     0,     0,
       8,     9,     0,    10,     0,    11,    12,     0,    13,    14,
       0,     0,     0,     0,     0,     0,    15,     0,    16,    17,
      18,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,    20,     0,     0,     0,     0,    21,    22,    23,    24,
      25,    26,     0,     0,     0,     0,    27,     0,     0,     0,
       0,     0,     0,     0,     0,  1078,     0,     0,     0,     0,
       0,     0,    28,    29,    30,    31,     0,    32,     0,     0,
      33,    34,    35,     0,    36,    37,    38,    39,    40,    41,
      42,    80,    43,    81,     0,     0,    44,    45,    46,    47,
      48,     0,    49,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,     0,     0,     0,
       0,     0,     0,     0,    52,     0,     0,    53,     0,    54,
      55,    56,     0,     0,    57,     0,     0,     0,    58,     0,
      59,     0,     0,    60,    61,     0,     0,     0,     0,    62,
       0,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,    74,     0,     0,    75,    76,    77,    78,
      79,     0,     0,     0,   328,     0,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,     0,     0,    95,     0,     0,    96,     0,     0,     0,
       0,     0,     0,     0,    97,    98,     0,    99,     0,     0,
       0,     0,     0,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   672,   104,   105,
     106,     0,     0,     0,     0,     0,     0,     0,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
       0,     0,   119,   120,   121,     0,   122,   123,   124,     0,
     125,   126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   127,     0,   128,     0,   129,     0,
       0,     0,     0,     0,     0,     0,   130,     0,     0,   131,
       0,     0,   132,     0,   133,   134,   135,   136,     0,   137,
     138,     0,     0,     0,     0,   139,   140,   141,   142,     0,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,     0,     0,     0,     0,     0,     0,     0,
     155,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   156,     0,   157,
     158,   159,   160,     0,   161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,     0,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   331,     0,    88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,     0,     0,    95,     0,     0,    96,     0,     0,
       0,     0,     0,     0,     0,    97,    98,     0,    99,     0,
       0,     0,     0,     0,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,     0,     0,     0,     0,     0,     0,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,     0,     0,   119,   120,   121,     0,   122,   123,   124,
       0,   125,   126,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,     0,   128,     0,   129,
       0,     0,     0,     0,     0,     0,     0,   130,     0,     0,
     131,     0,     0,   132,     0,   133,   134,   135,   136,     0,
     137,   138,     0,     0,     0,     0,   139,   140,   141,   142,
       0,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,     0,     0,     0,     0,     0,     0,
       0,   155,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   156,     0,
     157,   158,   159,   160,     0,   161,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,    88,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,     0,     0,     0,     0,
       0,     0,     0,     0,    89,   359,     0,     0,     0,     0,
       0,     0,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,     0,     0,
      95,     0,     0,    96,   360,   361,   362,     0,     0,     0,
       0,    97,    98,   363,    99,     0,     0,     0,     0,     0,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,     0,
       0,     0,     0,     0,     0,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,     0,     0,   119,
     120,   121,   364,   122,   123,   124,     0,   125,   126,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,     0,   128,     0,   129,     0,     0,     0,     0,
       0,     0,     0,   130,     0,     0,   131,     0,     0,   132,
       0,   133,   134,   135,   136,     0,   137,   138,     0,     0,
       0,     0,   139,   140,   141,   142,     0,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
       0,     0,     0,     0,     0,     0,     0,   155,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   156,     0,   157,   158,   159,   160,
       0,   161,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,    88,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,     0,     0,     0,     0,     0,     0,     0,     0,
     252,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,     0,   253,   254,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,     0,     0,    95,     0,     0,    96,
       0,     0,     0,     0,     0,     0,     0,    97,    98,     0,
      99,     0,     0,     0,     0,     0,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,   105,   106,     0,     0,     0,     0,     0,     0,
       0,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,     0,     0,   119,   120,   121,     0,   122,
     123,   124,     0,   125,   126,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,     0,   128,
       0,   129,     0,     0,     0,     0,     0,     0,     0,   130,
       0,     0,   131,     0,     0,   132,     0,   133,   134,   135,
     136,     0,   137,   138,     0,     0,     0,     0,   139,   140,
     141,   142,     0,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,     0,     0,     0,     0,
       0,     0,     0,   155,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     156,     0,   157,   158,   159,   160,     0,   161,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,    88,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,     0,     0,
       0,     0,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,     0,     0,     0,
       0,     0,     0,     0,   298,   299,     0,     0,     0,     0,
       0,     0,    91,    92,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
       0,     0,    95,     0,     0,    96,     0,     0,     0,     0,
       0,     0,     0,    97,    98,     0,    99,     0,     0,     0,
       0,     0,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,     0,     0,     0,     0,     0,     0,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,     0,
       0,   119,   120,   121,     0,   122,   123,   124,     0,   125,
     126,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,     0,   128,     0,   129,     0,     0,
       0,     0,     0,     0,     0,   130,     0,     0,   131,     0,
       0,   132,     0,   133,   134,   135,   136,     0,   137,   138,
       0,     0,     0,     0,   139,   140,   141,   142,     0,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,     0,     0,     0,     0,     0,     0,     0,   155,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   156,     0,   157,   158,
     159,   160,     0,   161,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,    88,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,     0,     0,     0,   206,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,     0,     0,    95,     0,
       0,    96,     0,     0,     0,     0,     0,     0,     0,    97,
      98,     0,    99,     0,     0,     0,     0,     0,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,     0,     0,     0,
       0,     0,     0,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,     0,     0,   119,   120,   121,
       0,   122,   123,   124,     0,   125,   126,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   127,
       0,   128,     0,   129,     0,     0,     0,     0,     0,     0,
       0,   130,     0,     0,   131,     0,     0,   132,     0,   133,
     134,   135,   136,     0,   137,   138,     0,     0,     0,     0,
     139,   140,   141,   142,     0,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,     0,     0,
       0,     0,     0,     0,     0,   155,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   207,     0,   157,   158,   159,   160,     0,   161,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,    88,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,     0,     0,     0,   206,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,     0,     0,    95,     0,     0,    96,     0,     0,
       0,     0,     0,     0,     0,    97,    98,     0,    99,     0,
       0,     0,     0,     0,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,     0,     0,     0,     0,     0,     0,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,     0,     0,   119,   120,   121,     0,   122,   123,   124,
       0,   125,   126,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,     0,   128,     0,   129,
       0,     0,     0,     0,     0,     0,     0,   130,     0,     0,
     131,     0,     0,   132,     0,   133,   134,   135,   136,     0,
     137,   138,     0,     0,     0,     0,   139,   140,   141,   142,
       0,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,     0,     0,     0,     0,     0,     0,
       0,   155,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   156,     0,
     157,   158,   159,   160,     0,   161,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,     0,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   358,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,     0,     0,    95,     0,     0,    96,     0,     0,     0,
       0,     0,     0,     0,    97,    98,     0,    99,     0,     0,
       0,     0,     0,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   105,
     106,     0,     0,     0,     0,     0,     0,     0,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
       0,     0,   119,   120,   121,     0,   122,   123,   124,     0,
     125,   126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   127,     0,   128,     0,   129,     0,
       0,     0,     0,     0,     0,     0,   130,     0,     0,   131,
       0,     0,   132,     0,   133,   134,   135,   136,     0,   137,
     138,     0,     0,     0,     0,   139,   140,   141,   142,     0,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,     0,     0,     0,     0,     0,     0,     0,
     155,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   156,     0,   157,
     158,   159,   160,     0,   161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,    88,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,     0,     0,     0,     0,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,     0,     0,    95,
       0,     0,    96,     0,     0,     0,     0,     0,     0,     0,
      97,    98,     0,    99,     0,     0,     0,     0,     0,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   105,   106,     0,     0,     0,
       0,     0,     0,     0,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,     0,     0,   119,   120,
     121,     0,   122,   123,   124,     0,   125,   126,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     127,     0,   128,     0,   129,     0,     0,     0,     0,     0,
       0,     0,   130,     0,     0,   131,     0,     0,   132,     0,
     133,   134,   135,   136,     0,   137,   138,     0,     0,     0,
       0,   139,   140,   141,   142,     0,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,     0,     0,
       0,     0,     0,     0,     0,     0,   155,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   156,     0,   157,   158,   159,   160,     0,
     161,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    88,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,     0,     0,     0,     0,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,     0,     0,    95,     0,     0,    96,     0,
       0,     0,     0,     0,     0,     0,    97,    98,     0,    99,
       0,     0,     0,     0,     0,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,   106,     0,     0,     0,     0,     0,     0,     0,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,     0,     0,   119,   120,   121,     0,   122,   123,
     124,     0,   125,   126,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   127,     0,   128,     0,
     129,     0,     0,     0,     0,     0,     0,     0,   130,     0,
       0,   131,     0,     0,   132,     0,   133,   134,   135,   136,
       0,   137,   138,     0,     0,     0,     0,   139,   140,   141,
     142,     0,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,     0,     0,     0,     0,     0,     0,
       0,     0,   155,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   156,
       0,   157,   158,   159,   160,     0,   161,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    88,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,     0,     0,
       0,     0,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,     0,
       0,    95,     0,     0,    96,     0,     0,     0,     0,     0,
       0,     0,    97,    98,     0,    99,     0,     0,     0,     0,
       0,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   758,   105,   106,     0,
       0,     0,     0,     0,     0,     0,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,     0,     0,
     119,   120,   121,     0,   122,   123,   124,     0,   125,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   127,     0,   128,     0,   129,     0,     0,     0,
       0,     0,     0,     0,   130,     0,     0,   131,     0,     0,
     132,     0,   133,   134,   135,   136,     0,   137,   138,     0,
       0,     0,     0,   139,   140,   141,   424,     0,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
       0,     0,     0,     0,     0,     0,     0,     0,   155,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   156,     0,   157,   158,   159,
     160,     0,   161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      88,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,     0,     0,     0,     0,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   423,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,     0,     0,    95,     0,     0,
      96,     0,     0,     0,     0,     0,     0,     0,    97,    98,
       0,    99,     0,     0,     0,     0,     0,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   105,   106,     0,     0,     0,     0,     0,
       0,     0,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,     0,     0,   119,   120,   121,     0,
     122,   123,   124,     0,   125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   127,     0,
     128,     0,   129,     0,     0,     0,     0,     0,     0,     0,
     130,     0,     0,   131,     0,     0,   132,     0,   133,   134,
     135,   136,     0,   137,   138,     0,     0,     0,     0,   139,
     140,   141,   424,     0,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,     0,     0,     0,     0,
       0,     0,     0,     0,   155,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   156,     0,   157,   158,   159,   160,     0,   161,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,    88,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     0,
       0,     0,     0,     0,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,     0,     0,    95,     0,     0,    96,     0,     0,     0,
       0,     0,     0,     0,    97,    98,     0,    99,     0,     0,
       0,     0,     0,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   105,
     106,     0,     0,     0,     0,     0,     0,     0,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
       0,     0,   119,   120,   121,     0,   122,   123,   124,     0,
     125,   436,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   127,     0,   128,     0,   129,     0,
       0,     0,     0,     0,     0,     0,   130,     0,     0,   131,
       0,     0,   132,     0,   133,   134,   135,   136,     0,   137,
     138,     0,     0,     0,     0,   139,   140,   141,   424,     0,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   437,     0,     0,     0,     0,   438,     0,   439,
     155,     0,     0,     0,     0,     0,     0,     0,   440,     0,
       0,     0,     0,     0,     0,     0,     0,   156,     0,   157,
     158,   159,   160,     0,   161,     0,     0,     0,     0,   441,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   442,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   443,     0,     0,     0,   444,     0,
     445,   446,   447,   448,   449,   450,     0,   451,   452,     0,
     453,   454,   455,   456,   457,   458,   459,   460,     0,   461,
     462,     0,   463,     0,     0,     0,     0,     0,     0,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507
};

static const yytype_int16 yycheck[] =
{
       7,   352,   142,   405,    11,    59,   353,    14,    26,    26,
      58,    18,   355,   356,     4,   740,     6,    24,    30,   739,
      27,    28,    30,    13,     6,    30,    38,    30,    35,    36,
      20,    13,    30,    30,    41,    30,    40,    20,    20,    40,
      47,    20,    49,    55,    40,    52,    83,    90,    20,   111,
      40,  1046,    59,    60,    31,    90,    63,    74,    40,    66,
      67,    68,    94,    30,    20,     7,    59,    74,    40,     7,
     970,    83,    84,   973,    20,     0,    85,    86,   295,    85,
      86,    20,    20,    90,    40,    31,     8,     9,    47,   295,
      12,    51,    14,    15,    16,    17,    18,   104,    30,    41,
      60,  1096,    28,    80,    81,    82,   295,     7,     7,    48,
      42,    43,    89,   106,    31,   147,    54,   837,   161,   839,
     101,    20,     7,   166,    91,  1120,   161,   852,   109,   191,
     147,   230,   857,     7,    80,    81,    82,   539,   540,    98,
      99,    41,  1042,    89,   153,   154,   155,   153,   154,   155,
     127,     7,    32,    30,   147,    54,    41,    37,   141,    91,
     150,   138,   141,    80,    81,    82,   203,    41,   150,   146,
      87,    88,    89,   295,    38,   297,   159,    40,   150,   101,
     159,   127,   163,   164,   165,    41,    38,   109,   195,    35,
     915,    55,   138,   200,   201,   202,   192,    77,   278,   203,
     146,    51,   203,    55,   284,    30,    31,     7,    54,    40,
      60,    23,    24,    38,    30,    27,    51,    42,    43,    83,
      84,   228,    94,    23,    24,    60,    51,    27,   295,   296,
     237,    83,    84,   237,    51,    60,   237,    62,    63,    48,
      49,    50,    51,    60,   251,   252,    71,    72,   295,    30,
     297,    60,   259,    48,    49,   274,   263,    82,   277,   278,
     985,    30,    31,   983,   147,   284,     0,   274,   275,    38,
       4,   278,     6,    42,    43,    98,    99,    80,    81,   297,
     297,    74,    51,   295,   291,   292,    89,   295,    98,    99,
     295,    60,   295,    62,    63,   302,   295,   295,   295,    40,
     295,   652,    71,    72,     0,    80,    81,     5,     4,     7,
       6,    98,    99,    82,    89,    19,   175,    21,   308,   295,
     722,   328,   665,    96,   331,    98,   308,   674,    96,   336,
      98,    96,    97,    62,    63,    62,    63,   344,    62,    63,
     347,    62,    63,     8,     9,   528,   529,    14,   530,   531,
     532,   533,   534,   535,   536,   537,    47,    13,   295,   366,
     367,   368,   295,     6,   295,   295,     4,     4,   297,    20,
      40,    40,    40,    20,   381,    20,    40,   384,    45,    40,
      40,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,    40,    40,
      40,    40,   542,   543,    40,    40,    40,    40,    40,    40,
      40,    40,    40,   420,    40,   422,   423,    40,    20,   426,
     427,   428,   429,   430,   431,    20,    20,    20,    20,    40,
      40,    40,    40,    40,    40,    40,    40,   236,   277,   277,
     133,    30,   297,    26,    30,    35,     7,    35,    75,    52,
     150,    52,   155,    40,    13,     7,     7,     7,   150,     7,
     150,   150,     7,     7,    13,    40,    40,   295,    41,    41,
      41,    41,    41,    41,    40,    40,    40,    40,    40,    25,
      40,   220,   220,   227,    40,    40,    40,    78,    35,    30,
      30,    30,    35,    78,    78,    30,    78,    54,    30,   295,
       7,    39,     7,    40,   511,    39,    48,    40,     7,     7,
     106,     7,    40,     7,    20,    40,    40,    75,   297,   297,
     297,   297,    41,   297,    41,   150,    41,    41,   195,    41,
      41,    41,    41,   200,   201,   202,     7,     7,     7,   546,
       7,    41,     7,     7,    41,     7,    41,   214,    41,    41,
      41,    41,    41,    41,    41,    41,   563,    41,   295,    41,
      41,   228,    41,    41,    41,    41,    41,    41,    97,    99,
     237,   191,   579,    41,    40,   295,   295,    35,    35,   295,
     295,   295,   295,    13,     7,    48,     7,    48,     7,   295,
       7,    40,   259,    78,    40,   297,   263,   604,   151,     7,
     607,   608,   650,     7,     7,   653,    41,   295,     7,   616,
     297,   278,   297,   297,   621,    41,   623,   757,   758,    41,
       7,   628,     7,    41,   631,   151,     7,   634,    23,    41,
     151,    41,   168,   295,    35,    35,   295,   168,   296,     7,
       7,     7,     7,     7,    13,     7,     7,    41,    41,   656,
      41,   658,    41,    13,     7,    41,    35,    41,    41,    41,
     667,    41,   669,    41,    41,    41,    41,    41,   151,     7,
     677,   151,   296,     7,   296,   119,    35,    13,   151,     7,
      13,    13,    78,    41,    41,   692,    41,   741,   742,    41,
      13,    13,    41,    41,    41,    41,   296,  1048,   296,    41,
     367,   368,    41,     7,    41,    13,    41,   209,   715,   716,
     717,   538,  1079,  1081,   721,  1080,   224,    -1,   646,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   736,
      -1,    -1,   739,    -1,   741,   742,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   893,    -1,    -1,    -1,    -1,   765,    -1,
     767,    -1,    -1,    -1,   771,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   783,    -1,    -1,    -1,
     920,    -1,    -1,    -1,    -1,   792,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   841,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   815,    -1,
      -1,    -1,    -1,   820,   821,    -1,    -1,    -1,    -1,    -1,
      -1,   828,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     837,    -1,   839,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   874,   875,   876,
     877,    -1,    -1,    -1,    -1,   882,    -1,    -1,    -1,   546,
      -1,   888,   889,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   900,    -1,   902,   563,    -1,    -1,    -1,
      -1,    -1,   569,    -1,   571,    -1,   573,    -1,   575,    -1,
     577,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   591,    -1,    -1,    -1,    -1,    -1,
      -1,   979,    -1,    -1,    -1,    -1,    -1,   604,    -1,    -1,
     607,   608,    -1,    -1,    -1,    -1,    -1,   954,    -1,   956,
     957,    -1,    -1,    -1,   621,   962,    -1,    -1,    -1,   966,
      -1,   628,   969,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   983,    -1,    -1,    -1,
      -1,   988,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1003,  1004,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1021,    -1,    -1,    -1,    -1,  1026,
      -1,    -1,  1029,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1038,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1055,    -1,
      -1,    -1,    -1,  1060,    -1,  1062,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1084,  1085,    -1,
      -1,  1088,    -1,  1090,  1091,    -1,    -1,    -1,    -1,     3,
      -1,  1098,    -1,  1100,    -1,    -1,    10,    11,    -1,   766,
      -1,   768,    -1,    -1,   771,    -1,    -1,   774,    22,   776,
      -1,   778,    -1,   780,    28,    29,    -1,    31,  1125,    33,
      34,    -1,    36,    37,    -1,    -1,    -1,   794,    -1,    -1,
      44,    -1,    46,    47,    48,    -1,   803,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      64,    65,    66,    67,    68,    69,    -1,    -1,   825,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,
      -1,    95,    -1,    -1,    98,    99,   100,    -1,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,    -1,    -1,    -1,
     114,   115,   116,   117,   118,    -1,   120,   121,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,
      -1,   145,    -1,   147,   148,   149,    -1,    -1,   152,    -1,
      -1,    -1,   156,    -1,   158,    -1,    -1,   161,   162,    -1,
      -1,    -1,    -1,   167,    -1,   169,   170,   171,   172,   173,
     174,    -1,   176,   177,   178,   179,   180,   181,    -1,    -1,
     184,   185,   186,   187,   188,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    11,    -1,    -1,    -1,   954,    -1,    -1,
      -1,   958,    -1,    -1,    22,    -1,   963,    -1,    -1,    -1,
      28,    29,    -1,    31,    -1,    33,    34,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    46,    47,
      48,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1022,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    91,    92,    93,    -1,    95,    -1,    -1,
      98,    99,   100,    -1,   102,   103,   104,   105,   106,   107,
     108,   295,   110,   297,    -1,    -1,   114,   115,   116,   117,
     118,    -1,   120,   121,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   134,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   142,    -1,    -1,   145,    -1,   147,
     148,   149,    -1,    -1,   152,    -1,    -1,    -1,   156,    -1,
     158,    -1,    -1,   161,   162,    -1,    -1,    -1,    -1,   167,
      -1,   169,   170,   171,   172,   173,   174,    -1,   176,   177,
     178,   179,   180,   181,    -1,    -1,   184,   185,   186,   187,
     188,    -1,    -1,    -1,     7,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    -1,    90,    -1,    -1,
      -1,    -1,    -1,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   295,   111,   112,
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
     233,   234,   235,    -1,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,    -1,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,     7,    -1,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     232,   233,   234,   235,    -1,   237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,     9,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      76,    -1,    -1,    79,    80,    81,    82,    -1,    -1,    -1,
      -1,    87,    88,    89,    90,    -1,    -1,    -1,    -1,    -1,
      96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,   137,   138,   139,   140,   141,    -1,   143,   144,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,    -1,   159,    -1,   161,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   169,    -1,    -1,   172,    -1,    -1,   175,
      -1,   177,   178,   179,   180,    -1,   182,   183,    -1,    -1,
      -1,    -1,   188,   189,   190,   191,    -1,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   230,    -1,   232,   233,   234,   235,
      -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,     9,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
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
     230,    -1,   232,   233,   234,   235,    -1,   237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,     9,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,    -1,
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
     234,   235,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,     9,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    -1,    -1,    -1,    -1,    26,    -1,
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
      -1,   139,   140,   141,    -1,   143,   144,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
      -1,   159,    -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   169,    -1,    -1,   172,    -1,    -1,   175,    -1,   177,
     178,   179,   180,    -1,   182,   183,    -1,    -1,    -1,    -1,
     188,   189,   190,   191,    -1,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   230,    -1,   232,   233,   234,   235,    -1,   237,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,     9,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    30,    -1,
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
     232,   233,   234,   235,    -1,   237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,    -1,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,
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
     233,   234,   235,    -1,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,     9,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
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
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,     9,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
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
     141,    -1,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,   159,    -1,
     161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,    -1,
      -1,   172,    -1,    -1,   175,    -1,   177,   178,   179,   180,
      -1,   182,   183,    -1,    -1,    -1,    -1,   188,   189,   190,
     191,    -1,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,
      -1,   232,   233,   234,   235,    -1,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,     9,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,    -1,    -1,    -1,
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
     235,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
       9,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    76,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      -1,    90,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,   137,    -1,
     139,   140,   141,    -1,   143,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,
     159,    -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     169,    -1,    -1,   172,    -1,    -1,   175,    -1,   177,   178,
     179,   180,    -1,   182,   183,    -1,    -1,    -1,    -1,   188,
     189,   190,   191,    -1,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   230,    -1,   232,   233,   234,   235,    -1,   237,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,     9,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    -1,    90,    -1,    -1,
      -1,    -1,    -1,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,    -1,   135,   136,   137,    -1,   139,   140,   141,    -1,
     143,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,    -1,   159,    -1,   161,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   169,    -1,    -1,   172,
      -1,    -1,   175,    -1,   177,   178,   179,   180,    -1,   182,
     183,    -1,    -1,    -1,    -1,   188,   189,   190,   191,    -1,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,    91,    -1,    -1,    -1,    -1,    96,    -1,    98,
     213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,   232,
     233,   234,   235,    -1,   237,    -1,    -1,    -1,    -1,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   171,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   203,    -1,    -1,    -1,   207,    -1,
     209,   210,   211,   212,   213,   214,    -1,   216,   217,    -1,
     219,   220,   221,   222,   223,   224,   225,   226,    -1,   228,
     229,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   420,   421,     0,     3,    10,    11,    22,    28,    29,
      31,    33,    34,    36,    37,    44,    46,    47,    48,    53,
      59,    64,    65,    66,    67,    68,    69,    74,    90,    91,
      92,    93,    95,    98,    99,   100,   102,   103,   104,   105,
     106,   107,   108,   110,   114,   115,   116,   117,   118,   120,
     121,   134,   142,   145,   147,   148,   149,   152,   156,   158,
     161,   162,   167,   169,   170,   171,   172,   173,   174,   176,
     177,   178,   179,   180,   181,   184,   185,   186,   187,   188,
     295,   297,   405,   414,   416,   418,   295,   295,     9,    30,
      40,    56,    57,    58,    73,    76,    79,    87,    88,    90,
      96,    97,    98,    99,   111,   112,   113,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   135,
     136,   137,   139,   140,   141,   143,   144,   157,   159,   161,
     169,   172,   175,   177,   178,   179,   180,   182,   183,   188,
     189,   190,   191,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   213,   230,   232,   233,   234,
     235,   237,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   310,   311,   312,
     313,   314,   318,   322,   395,    30,   295,   330,   331,   332,
      32,    37,    77,   336,   337,   338,    26,   230,   310,   315,
     340,   341,   342,    28,    30,    38,    55,    83,    84,   295,
     327,   328,   329,   310,   315,   343,   344,   345,    30,    42,
      43,    91,   346,   347,   348,    48,    49,    50,    51,    60,
     361,   362,   363,   310,   378,   295,   364,   367,   295,   297,
     365,   406,    30,    42,    43,   310,   352,   353,   354,    30,
     355,   356,   357,    30,    91,   358,   359,   360,   310,   310,
     230,    94,    94,   147,    40,    40,   310,   310,    30,   349,
     350,   351,    30,   368,   369,   370,   295,   297,   366,   310,
     147,    74,    74,   147,   297,   315,   310,   295,    48,    49,
     310,   382,    40,   295,   383,   310,   371,   295,   386,   390,
     295,   295,   295,   295,   296,   393,   393,   395,   310,    48,
      49,   101,   109,   163,   164,   165,   398,   400,     7,   310,
     401,     7,   310,   402,   310,   310,   175,   310,    47,    98,
      99,   403,    47,   404,    13,     4,     6,    13,    20,   150,
     308,   411,   413,   417,     6,     4,     4,   297,    20,    31,
      80,    81,    82,    89,   138,   310,    40,    40,    40,    31,
      80,    81,    82,    87,    88,    89,   316,   317,    20,   141,
     159,    40,   203,   237,    40,   203,   237,   310,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    20,    40,    90,   161,
      20,   141,   159,    20,    20,    20,    20,    20,    20,    20,
      40,   192,    40,    40,   191,   322,    40,    40,    40,    40,
      40,    40,    83,   203,    98,    99,    30,    91,    96,    98,
     107,   128,   171,   203,   207,   209,   210,   211,   212,   213,
     214,   216,   217,   219,   220,   221,   222,   223,   224,   225,
     226,   228,   229,   231,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   319,   320,
     321,    40,   236,    98,    99,   277,   274,   277,   278,   284,
     278,   284,   277,    20,   150,   323,     5,     7,     8,     9,
      12,    14,    15,    16,    17,    18,   101,   109,   133,    19,
      21,    23,    24,    27,   310,   315,    30,   310,   315,   310,
     315,   310,   315,   297,    85,    86,   153,   154,   155,   339,
      86,   155,   339,    30,   295,   333,   334,   335,   315,    30,
     295,    30,   295,    30,   295,    30,   295,    30,    30,    31,
      38,    42,    43,    51,    60,    62,    63,    71,    72,    82,
     326,    31,    38,    42,    43,    51,    60,    62,    63,    71,
      72,   326,   310,   315,    35,   310,   315,    52,    52,    59,
     106,   147,    20,    48,   310,   310,     7,   310,   315,   310,
     315,    35,    75,   150,   310,   310,   310,   315,    40,   310,
     310,    13,   155,   310,     7,    31,    80,    81,    82,    89,
     127,   138,   146,   385,   387,   388,     7,   150,   407,   150,
       7,    20,    54,     7,     7,   310,     7,   310,     7,   310,
      98,    99,    96,    97,   310,   419,   310,    13,   412,   408,
      40,   385,   295,   414,   415,   418,   418,    40,    41,    41,
      41,    41,    41,    80,    81,    89,    41,   310,   310,   315,
     310,   315,    40,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   314,    40,   295,    40,    40,    40,   310,   310,
     310,    40,    25,   310,   310,   310,   310,   310,   310,   220,
     220,    96,    98,    96,    98,   227,    40,   310,   324,   325,
      40,   397,   396,   312,   312,   311,   311,   311,   311,   311,
     311,   311,   311,   313,   314,   314,   111,   191,   111,   322,
     322,    35,    35,   310,   315,    78,    78,    78,    78,   310,
     315,    30,    54,   315,    30,   315,    30,   315,    30,   315,
      30,   315,   310,    39,    62,    63,    62,    63,    51,    60,
      51,    60,    40,   315,    39,    62,    63,    62,    63,    51,
      60,    51,    60,    40,   310,   315,   310,   315,   310,   315,
     379,   381,   380,    48,   295,     7,   310,   310,   315,   310,
       7,     7,   310,   315,    75,     7,   310,   106,     7,   310,
      80,    81,    89,   389,    40,    20,   390,   409,   150,   410,
     393,     7,   385,   393,    90,   161,   166,   399,   310,   310,
     418,   310,    40,   310,   394,   310,   391,    40,   414,   310,
     297,   297,   297,   297,   297,    41,    41,    41,    41,    41,
      41,    41,    41,   310,     7,     7,     7,     7,    41,    41,
      41,    41,     7,    41,    41,    41,    41,    41,     7,     7,
      41,    41,    41,     7,   295,    41,   310,   310,   310,    41,
       7,    41,     7,   310,   314,    41,    41,    41,    41,    41,
      41,    97,    99,   310,    41,    40,   394,   391,   395,   395,
     191,   322,   322,   295,   295,   310,   315,   310,   315,    35,
      35,   310,   315,    38,    55,    83,    84,   315,   315,   315,
     315,    35,    54,   310,   310,   315,   315,   295,   372,   295,
     374,   295,   376,   295,    13,   310,     7,    48,    48,   151,
     310,   310,     7,     7,   297,   315,    78,   295,   310,     7,
      40,   297,   384,    40,   394,   295,   392,   394,   393,     7,
     168,   168,   391,     7,   151,     7,    41,   391,     7,   297,
     297,   297,    41,   310,   310,   310,   310,   310,   310,   310,
     322,    41,    41,     7,     7,   310,   310,    41,   391,   151,
      41,   322,   295,   295,    35,    35,   296,    38,    55,    83,
      84,     7,     7,   373,   375,   377,    13,   310,   315,     7,
     310,   310,   315,    41,    41,   310,   315,   310,     7,    41,
     310,   384,     7,    41,   384,   151,     7,    20,    54,   151,
     151,   393,    41,   394,   391,    13,    41,   310,    41,    41,
       7,    41,     7,    41,    41,    41,    41,    41,   310,   310,
      41,    41,    41,   296,   296,    35,    35,   310,   315,     7,
       7,     7,   310,   310,    13,    13,    41,    41,   119,   310,
      13,    78,    41,   384,    41,   392,     7,   385,    13,   310,
      13,    41,   310,   310,    41,    41,   296,   296,    41,    41,
     372,   374,   376,   310,   310,   310,    41,   310,   310,   392,
       7,   310,   310,    41,    41,    13,   392,   310
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   309,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   311,   311,   311,   312,   312,   313,   313,   313,
     314,   314,   314,   314,   314,   314,   314,   314,   315,   316,
     316,   316,   316,   316,   316,   316,   317,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     320,   320,   320,   320,   320,   320,   320,   320,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   323,   322,
     324,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   325,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   326,   326,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   328,   328,   328,   328,   328,   329,   329,
     330,   330,   331,   331,   332,   332,   333,   333,   334,   334,
     335,   335,   336,   336,   336,   337,   337,   337,   338,   338,
     339,   339,   339,   340,   340,   340,   340,   341,   341,   341,
     342,   342,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   345,   345,   346,   346,   346,   346,   346,   347,
     347,   348,   348,   349,   350,   351,   351,   352,   352,   353,
     353,   354,   354,   355,   356,   357,   357,   358,   358,   358,
     359,   359,   360,   360,   361,   361,   361,   361,   361,   362,
     362,   362,   363,   363,   364,   364,   364,   364,   364,   364,
     365,   365,   366,   366,   367,   368,   369,   370,   370,   371,
     372,   373,   372,   374,   375,   374,   376,   377,   376,   379,
     378,   380,   378,   381,   378,   382,   382,   382,   383,   383,
     384,   384,   385,   385,   385,   385,   385,   385,   385,   385,
     385,   385,   387,   386,   388,   386,   389,   386,   390,   390,
     391,   391,   392,   392,   392,   392,   392,   392,   393,   393,
     393,   393,   393,   393,   393,   393,   394,   394,   395,   395,
     395,   396,   395,   397,   395,   398,   398,   398,   398,   398,
     399,   399,   399,   399,   399,   400,   401,   401,   401,   402,
     402,   402,   403,   403,   403,   403,   404,   404,   405,   405,
     405,   405,   405,   405,   405,   405,   405,   405,   405,   405,
     405,   405,   405,   405,   405,   405,   405,   405,   405,   405,
     405,   405,   405,   405,   405,   405,   405,   405,   405,   405,
     405,   405,   405,   405,   405,   405,   405,   405,   405,   405,
     405,   405,   405,   405,   405,   406,   405,   405,   405,   405,
     405,   405,   405,   405,   405,   405,   405,   405,   405,   405,
     405,   407,   405,   405,   405,   405,   405,   405,   405,   405,
     405,   408,   405,   409,   405,   410,   405,   405,   405,   405,
     405,   405,   405,   405,   405,   405,   405,   405,   405,   405,
     405,   405,   405,   405,   405,   405,   405,   405,   405,   405,
     405,   405,   405,   411,   405,   412,   405,   413,   405,   405,
     405,   405,   414,   415,   414,   417,   416,   419,   418,   418,
     418,   418,   418,   421,   420
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
       1,     1,     1,     1,     2,     5,     4,     1,     2,     1,
       2,     2,     2,     2,     2,     1,     2,     1,     2,     2,
       2,     2,     2,     1,     1,     2,     3,     4,     5,     4,
       3,     5,     4,     4,     3,     4,     5,     4,     3,     5,
       4,     4,     3,     5,     7,     6,     7,     6,     1,     1,
       3,     4,     3,     4,     1,     1,     3,     4,     3,     4,
       1,     1,     2,     4,     4,     2,     4,     4,     1,     1,
       1,     1,     1,     2,     2,     2,     1,     2,     2,     2,
       1,     1,     4,     2,     2,     3,     7,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     2,     2,
       3,     7,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     2,     1,     1,     1,     3,     2,
       3,     1,     1,     2,     2,     1,     1,     1,     1,     6,
       5,     1,     1,     2,     2,     1,     1,     2,     1,     5,
       2,     5,     1,     1,     1,     1,     2,     3,     3,     2,
       3,     3,     1,     1,     0,     3,     4,     5,     5,     6,
       1,     1,     1,     1,     1,     6,     6,     1,     1,     1,
       1,     0,     4,     1,     0,     4,     1,     0,     4,     0,
       4,     0,     4,     0,     4,     4,     1,     1,     3,     7,
       1,     3,     1,     2,     1,     2,     1,     2,     1,     1,
       1,     1,     0,     5,     0,     6,     0,     6,     1,     3,
       1,     3,     1,     2,     3,     3,     4,     5,     1,     2,
       3,     3,     4,     5,     1,     3,     1,     3,     1,     2,
       2,     0,     4,     0,     4,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     2,     3,     2,     2,     3,     2,
       2,     3,     1,     2,     1,     2,     2,     2,     2,     2,
       3,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     2,     2,     2,     2,     1,     1,
       2,     2,     2,     1,     1,     1,     1,     1,     2,     3,
       2,     2,     1,     1,     2,     2,     2,     1,     2,     3,
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
#line 87 "src/ugbc.y"
                              {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3567 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 91 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3576 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math OP_EQUAL expr_math  */
#line 95 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3584 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math OP_DISEQUAL expr_math  */
#line 98 "src/ugbc.y"
                                      {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3592 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math OP_LT expr_math  */
#line 101 "src/ugbc.y"
                                {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3600 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math OP_LTE expr_math  */
#line 104 "src/ugbc.y"
                                 {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 3608 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math OP_GT expr_math  */
#line 107 "src/ugbc.y"
                                {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3616 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math OP_GTE expr_math  */
#line 110 "src/ugbc.y"
                                 {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3624 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 113 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 3632 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math OP_PLUS term  */
#line 120 "src/ugbc.y"
                             {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3640 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math OP_MINUS term  */
#line 123 "src/ugbc.y"
                              {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3649 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula OP_MULTIPLICATION factor  */
#line 136 "src/ugbc.y"
                                      {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3658 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula OP_DIVISION factor  */
#line 140 "src/ugbc.y"
                                {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3667 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor OP_POW exponential  */
#line 148 "src/ugbc.y"
                                  {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 3676 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor OP_COMMA exponential CP  */
#line 152 "src/ugbc.y"
                                                   {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 3685 "src-generated/ugbc.tab.c"
    break;

  case 23: /* factor: factor HAS BIT exponential  */
#line 156 "src/ugbc.y"
                                   {
        (yyval.string) = variable_bit( _environment, (yyvsp[-3].string), (yyvsp[0].string) )->name;
      }
#line 3693 "src-generated/ugbc.tab.c"
    break;

  case 24: /* factor: factor HAS NOT BIT exponential  */
#line 159 "src/ugbc.y"
                                       {
        (yyval.string) = variable_not( _environment, variable_bit( _environment, (yyvsp[-4].string), (yyvsp[0].string) )->name )->name;
      }
#line 3701 "src-generated/ugbc.tab.c"
    break;

  case 25: /* factor: factor IS exponential  */
#line 162 "src/ugbc.y"
                              {
        (yyval.string) = variable_bit( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
      }
#line 3709 "src-generated/ugbc.tab.c"
    break;

  case 26: /* factor: factor IS NOT exponential  */
#line 165 "src/ugbc.y"
                                  {
        (yyval.string) = variable_not( _environment, variable_bit( _environment, (yyvsp[-3].string), (yyvsp[0].string) )->name )->name;
      }
#line 3717 "src-generated/ugbc.tab.c"
    break;

  case 27: /* factor: BIT exponential OF factor  */
#line 168 "src/ugbc.y"
                                  {
        (yyval.string) = variable_bit( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
      }
#line 3725 "src-generated/ugbc.tab.c"
    break;

  case 28: /* direct_integer: OP_HASH Integer  */
#line 174 "src/ugbc.y"
                    {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 3733 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: BYTE  */
#line 179 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 3741 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: WORD  */
#line 182 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 3749 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition_simple: DWORD  */
#line 185 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 3757 "src-generated/ugbc.tab.c"
    break;

  case 32: /* random_definition_simple: POSITION  */
#line 188 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 3765 "src-generated/ugbc.tab.c"
    break;

  case 33: /* random_definition_simple: COLOR  */
#line 191 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 3773 "src-generated/ugbc.tab.c"
    break;

  case 34: /* random_definition_simple: WIDTH  */
#line 194 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 3781 "src-generated/ugbc.tab.c"
    break;

  case 35: /* random_definition_simple: HEIGHT  */
#line 197 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 3789 "src-generated/ugbc.tab.c"
    break;

  case 36: /* random_definition: random_definition_simple  */
#line 202 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 3797 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: BLACK  */
#line 207 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 3806 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: WHITE  */
#line 211 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 3815 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: RED  */
#line 215 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 3824 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: CYAN  */
#line 219 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 3833 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: VIOLET  */
#line 223 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 3842 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: GREEN  */
#line 227 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 3851 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: BLUE  */
#line 231 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 3860 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: YELLOW  */
#line 235 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 3869 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: ORANGE  */
#line 239 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 3878 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: BROWN  */
#line 243 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 3887 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT RED  */
#line 247 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 3896 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK GREY  */
#line 251 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 3905 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: GREY  */
#line 255 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 3914 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: LIGHT GREEN  */
#line 259 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 3923 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LIGHT BLUE  */
#line 263 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 3932 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: LIGHT GREY  */
#line 267 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 3941 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: DARK BLUE  */
#line 271 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 3950 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: MAGENTA  */
#line 275 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 3959 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: PURPLE  */
#line 279 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 3968 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: LAVENDER  */
#line 283 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 3977 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: GOLD  */
#line 287 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 3986 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: TURQUOISE  */
#line 291 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 3995 "src-generated/ugbc.tab.c"
    break;

  case 59: /* color_enumeration: TAN  */
#line 295 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 4004 "src-generated/ugbc.tab.c"
    break;

  case 60: /* color_enumeration: YELLOW GREEN  */
#line 299 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 4013 "src-generated/ugbc.tab.c"
    break;

  case 61: /* color_enumeration: OLIVE GREEN  */
#line 303 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 4022 "src-generated/ugbc.tab.c"
    break;

  case 62: /* color_enumeration: PINK  */
#line 307 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 4031 "src-generated/ugbc.tab.c"
    break;

  case 63: /* color_enumeration: PEACH  */
#line 311 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 4040 "src-generated/ugbc.tab.c"
    break;

  case 64: /* key_scancode_alphadigit: "0"  */
#line 317 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 0)")->name;
        variable_store( _environment, (yyval.string), KEY_0 );
    }
#line 4049 "src-generated/ugbc.tab.c"
    break;

  case 65: /* key_scancode_alphadigit: "1"  */
#line 321 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 1)")->name;
        variable_store( _environment, (yyval.string), KEY_1 );
    }
#line 4058 "src-generated/ugbc.tab.c"
    break;

  case 66: /* key_scancode_alphadigit: "2"  */
#line 325 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 2)")->name;
        variable_store( _environment, (yyval.string), KEY_2 );
    }
#line 4067 "src-generated/ugbc.tab.c"
    break;

  case 67: /* key_scancode_alphadigit: "3"  */
#line 329 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 3)")->name;
        variable_store( _environment, (yyval.string), KEY_3 );
    }
#line 4076 "src-generated/ugbc.tab.c"
    break;

  case 68: /* key_scancode_alphadigit: "4"  */
#line 333 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 4)")->name;
        variable_store( _environment, (yyval.string), KEY_4 );
    }
#line 4085 "src-generated/ugbc.tab.c"
    break;

  case 69: /* key_scancode_alphadigit: "5"  */
#line 337 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 5)")->name;
        variable_store( _environment, (yyval.string), KEY_5 );
    }
#line 4094 "src-generated/ugbc.tab.c"
    break;

  case 70: /* key_scancode_alphadigit: "6"  */
#line 341 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 6)")->name;
        variable_store( _environment, (yyval.string), KEY_6 );
    }
#line 4103 "src-generated/ugbc.tab.c"
    break;

  case 71: /* key_scancode_alphadigit: "7"  */
#line 345 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 7)")->name;
        variable_store( _environment, (yyval.string), KEY_7 );
    }
#line 4112 "src-generated/ugbc.tab.c"
    break;

  case 72: /* key_scancode_alphadigit: "8"  */
#line 349 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 8)")->name;
        variable_store( _environment, (yyval.string), KEY_8 );
    }
#line 4121 "src-generated/ugbc.tab.c"
    break;

  case 73: /* key_scancode_alphadigit: "9"  */
#line 353 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 9)")->name;
        variable_store( _environment, (yyval.string), KEY_9 );
    }
#line 4130 "src-generated/ugbc.tab.c"
    break;

  case 74: /* key_scancode_alphadigit: A  */
#line 357 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER A)")->name;
        variable_store( _environment, (yyval.string), KEY_A );
    }
#line 4139 "src-generated/ugbc.tab.c"
    break;

  case 75: /* key_scancode_alphadigit: B  */
#line 361 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER B)")->name;
        variable_store( _environment, (yyval.string), KEY_B );
    }
#line 4148 "src-generated/ugbc.tab.c"
    break;

  case 76: /* key_scancode_alphadigit: C  */
#line 365 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER C)")->name;
        variable_store( _environment, (yyval.string), KEY_C );
    }
#line 4157 "src-generated/ugbc.tab.c"
    break;

  case 77: /* key_scancode_alphadigit: D  */
#line 369 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER D)")->name;
        variable_store( _environment, (yyval.string), KEY_D );
    }
#line 4166 "src-generated/ugbc.tab.c"
    break;

  case 78: /* key_scancode_alphadigit: E  */
#line 373 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER E)")->name;
        variable_store( _environment, (yyval.string), KEY_E );
    }
#line 4175 "src-generated/ugbc.tab.c"
    break;

  case 79: /* key_scancode_alphadigit: F  */
#line 377 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER F)")->name;
        variable_store( _environment, (yyval.string), KEY_F );
    }
#line 4184 "src-generated/ugbc.tab.c"
    break;

  case 80: /* key_scancode_alphadigit: G  */
#line 381 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER G)")->name;
        variable_store( _environment, (yyval.string), KEY_G );
    }
#line 4193 "src-generated/ugbc.tab.c"
    break;

  case 81: /* key_scancode_alphadigit: H  */
#line 385 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER H)")->name;
        variable_store( _environment, (yyval.string), KEY_H );
    }
#line 4202 "src-generated/ugbc.tab.c"
    break;

  case 82: /* key_scancode_alphadigit: I  */
#line 389 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER I)")->name;
        variable_store( _environment, (yyval.string), KEY_I );
    }
#line 4211 "src-generated/ugbc.tab.c"
    break;

  case 83: /* key_scancode_alphadigit: J  */
#line 393 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER J)")->name;
        variable_store( _environment, (yyval.string), KEY_J );
    }
#line 4220 "src-generated/ugbc.tab.c"
    break;

  case 84: /* key_scancode_alphadigit: K  */
#line 397 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER K)")->name;
        variable_store( _environment, (yyval.string), KEY_K );
    }
#line 4229 "src-generated/ugbc.tab.c"
    break;

  case 85: /* key_scancode_alphadigit: L  */
#line 401 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER L)")->name;
        variable_store( _environment, (yyval.string), KEY_L );
    }
#line 4238 "src-generated/ugbc.tab.c"
    break;

  case 86: /* key_scancode_alphadigit: M  */
#line 405 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER M)")->name;
        variable_store( _environment, (yyval.string), KEY_M );
    }
#line 4247 "src-generated/ugbc.tab.c"
    break;

  case 87: /* key_scancode_alphadigit: N  */
#line 409 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER N)")->name;
        variable_store( _environment, (yyval.string), KEY_N );
    }
#line 4256 "src-generated/ugbc.tab.c"
    break;

  case 88: /* key_scancode_alphadigit: O  */
#line 413 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER O)")->name;
        variable_store( _environment, (yyval.string), KEY_O );
    }
#line 4265 "src-generated/ugbc.tab.c"
    break;

  case 89: /* key_scancode_alphadigit: P  */
#line 417 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER P)")->name;
        variable_store( _environment, (yyval.string), KEY_P );
    }
#line 4274 "src-generated/ugbc.tab.c"
    break;

  case 90: /* key_scancode_alphadigit: Q  */
#line 421 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER Q)")->name;
        variable_store( _environment, (yyval.string), KEY_Q );
    }
#line 4283 "src-generated/ugbc.tab.c"
    break;

  case 91: /* key_scancode_alphadigit: R  */
#line 425 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER R)")->name;
        variable_store( _environment, (yyval.string), KEY_R );
    }
#line 4292 "src-generated/ugbc.tab.c"
    break;

  case 92: /* key_scancode_alphadigit: S  */
#line 429 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER S)")->name;
        variable_store( _environment, (yyval.string), KEY_S );
    }
#line 4301 "src-generated/ugbc.tab.c"
    break;

  case 93: /* key_scancode_alphadigit: T  */
#line 433 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER T)")->name;
        variable_store( _environment, (yyval.string), KEY_T );
    }
#line 4310 "src-generated/ugbc.tab.c"
    break;

  case 94: /* key_scancode_alphadigit: U  */
#line 437 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER U)")->name;
        variable_store( _environment, (yyval.string), KEY_U );
    }
#line 4319 "src-generated/ugbc.tab.c"
    break;

  case 95: /* key_scancode_alphadigit: V  */
#line 441 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER V)")->name;
        variable_store( _environment, (yyval.string), KEY_V );
    }
#line 4328 "src-generated/ugbc.tab.c"
    break;

  case 96: /* key_scancode_alphadigit: X  */
#line 445 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER X)")->name;
        variable_store( _environment, (yyval.string), KEY_X );
    }
#line 4337 "src-generated/ugbc.tab.c"
    break;

  case 97: /* key_scancode_alphadigit: Y  */
#line 449 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER Y)")->name;
        variable_store( _environment, (yyval.string), KEY_Y );
    }
#line 4346 "src-generated/ugbc.tab.c"
    break;

  case 98: /* key_scancode_alphadigit: W  */
#line 453 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER W)")->name;
        variable_store( _environment, (yyval.string), KEY_W );
    }
#line 4355 "src-generated/ugbc.tab.c"
    break;

  case 99: /* key_scancode_alphadigit: Z  */
#line 457 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER Z)")->name;
        variable_store( _environment, (yyval.string), KEY_Z );
    }
#line 4364 "src-generated/ugbc.tab.c"
    break;

  case 100: /* key_scancode_function_digit: F1  */
#line 464 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode F1)")->name;
        variable_store( _environment, (yyval.string), KEY_F1 );
    }
#line 4373 "src-generated/ugbc.tab.c"
    break;

  case 101: /* key_scancode_function_digit: F2  */
#line 468 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode F2)")->name;
        variable_store( _environment, (yyval.string), KEY_F2 );
    }
#line 4382 "src-generated/ugbc.tab.c"
    break;

  case 102: /* key_scancode_function_digit: F3  */
#line 472 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode F3)")->name;
        variable_store( _environment, (yyval.string), KEY_F3 );
    }
#line 4391 "src-generated/ugbc.tab.c"
    break;

  case 103: /* key_scancode_function_digit: F4  */
#line 476 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode F4)")->name;
        variable_store( _environment, (yyval.string), KEY_F4 );
    }
#line 4400 "src-generated/ugbc.tab.c"
    break;

  case 104: /* key_scancode_function_digit: F5  */
#line 480 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode F5)")->name;
        variable_store( _environment, (yyval.string), KEY_F5 );
    }
#line 4409 "src-generated/ugbc.tab.c"
    break;

  case 105: /* key_scancode_function_digit: F6  */
#line 484 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode F6)")->name;
        variable_store( _environment, (yyval.string), KEY_F6 );
    }
#line 4418 "src-generated/ugbc.tab.c"
    break;

  case 106: /* key_scancode_function_digit: F7  */
#line 488 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode F7)")->name;
        variable_store( _environment, (yyval.string), KEY_F7 );
    }
#line 4427 "src-generated/ugbc.tab.c"
    break;

  case 107: /* key_scancode_function_digit: F8  */
#line 492 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode F8)")->name;
        variable_store( _environment, (yyval.string), KEY_F8 );
    }
#line 4436 "src-generated/ugbc.tab.c"
    break;

  case 108: /* key_scancode_definition: NONE  */
#line 498 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode NONE)")->name;
        variable_store( _environment, (yyval.string), KEY_NONE );
    }
#line 4445 "src-generated/ugbc.tab.c"
    break;

  case 109: /* key_scancode_definition: key_scancode_alphadigit  */
#line 502 "src/ugbc.y"
                              {
        (yyval.string) = (yyvsp[0].string);
    }
#line 4453 "src-generated/ugbc.tab.c"
    break;

  case 110: /* key_scancode_definition: ASTERISK  */
#line 505 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode ASTERISK)")->name;
        variable_store( _environment, (yyval.string), KEY_ASTERISK );
    }
#line 4462 "src-generated/ugbc.tab.c"
    break;

  case 111: /* key_scancode_definition: AT  */
#line 509 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode AT)")->name;
        variable_store( _environment, (yyval.string), KEY_AT );
    }
#line 4471 "src-generated/ugbc.tab.c"
    break;

  case 112: /* key_scancode_definition: CLEAR  */
#line 513 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode CLEAR)")->name;
        variable_store( _environment, (yyval.string), KEY_CLEAR );
    }
#line 4480 "src-generated/ugbc.tab.c"
    break;

  case 113: /* key_scancode_definition: COLON  */
#line 517 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode COLON)")->name;
        variable_store( _environment, (yyval.string), KEY_COLON );
    }
#line 4489 "src-generated/ugbc.tab.c"
    break;

  case 114: /* key_scancode_definition: COMMA  */
#line 521 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode COMMA)")->name;
        variable_store( _environment, (yyval.string), KEY_COMMA );
    }
#line 4498 "src-generated/ugbc.tab.c"
    break;

  case 115: /* key_scancode_definition: COMMODORE  */
#line 525 "src/ugbc.y"
                {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode COMMODORE)")->name;
        variable_store( _environment, (yyval.string), KEY_COMMODORE );
    }
#line 4507 "src-generated/ugbc.tab.c"
    break;

  case 116: /* key_scancode_definition: CONTROL  */
#line 529 "src/ugbc.y"
              {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode CONTROL)")->name;
        variable_store( _environment, (yyval.string), KEY_CONTROL );
    }
#line 4516 "src-generated/ugbc.tab.c"
    break;

  case 117: /* key_scancode_definition: CRSR LEFT RIGHT  */
#line 533 "src/ugbc.y"
                      {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode CRSR LEFT RIGHT)")->name;
        variable_store( _environment, (yyval.string), KEY_CRSR_LEFT_RIGHT );
    }
#line 4525 "src-generated/ugbc.tab.c"
    break;

  case 118: /* key_scancode_definition: CRSR UP DOWN  */
#line 537 "src/ugbc.y"
                   {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode CRSR UP DOWN)")->name;
        variable_store( _environment, (yyval.string), KEY_CRSR_UP_DOWN );
    }
#line 4534 "src-generated/ugbc.tab.c"
    break;

  case 119: /* key_scancode_definition: DELETE  */
#line 541 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DELETE)")->name;
        variable_store( _environment, (yyval.string), KEY_DELETE );
    }
#line 4543 "src-generated/ugbc.tab.c"
    break;

  case 120: /* key_scancode_definition: EQUAL  */
#line 545 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode EQUAL)")->name;
        variable_store( _environment, (yyval.string), KEY_EQUAL );
    }
#line 4552 "src-generated/ugbc.tab.c"
    break;

  case 121: /* key_scancode_definition: key_scancode_function_digit  */
#line 549 "src/ugbc.y"
                                  {
        (yyval.string) = (yyvsp[0].string);
    }
#line 4560 "src-generated/ugbc.tab.c"
    break;

  case 122: /* key_scancode_definition: HOME  */
#line 552 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode HOME)")->name;
        variable_store( _environment, (yyval.string), KEY_HOME );
    }
#line 4569 "src-generated/ugbc.tab.c"
    break;

  case 123: /* key_scancode_definition: INSERT  */
#line 556 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode INSERT)")->name;
        variable_store( _environment, (yyval.string), KEY_INSERT );
    }
#line 4578 "src-generated/ugbc.tab.c"
    break;

  case 124: /* key_scancode_definition: ARROW LEFT  */
#line 560 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode ARROW LEFT)")->name;
        variable_store( _environment, (yyval.string), KEY_LEFT_ARROW );
    }
#line 4587 "src-generated/ugbc.tab.c"
    break;

  case 125: /* key_scancode_definition: LEFT ARROW  */
#line 564 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode ARROW LEFT)")->name;
        variable_store( _environment, (yyval.string), KEY_LEFT_ARROW );
    }
#line 4596 "src-generated/ugbc.tab.c"
    break;

  case 126: /* key_scancode_definition: ARROW UP  */
#line 568 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode ARROW UP)")->name;
        variable_store( _environment, (yyval.string), KEY_UP_ARROW );
    }
#line 4605 "src-generated/ugbc.tab.c"
    break;

  case 127: /* key_scancode_definition: UP ARROW  */
#line 572 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode ARROW UP)")->name;
        variable_store( _environment, (yyval.string), KEY_UP_ARROW );
    }
#line 4614 "src-generated/ugbc.tab.c"
    break;

  case 128: /* key_scancode_definition: MINUS  */
#line 576 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode MINUS)")->name;
        variable_store( _environment, (yyval.string), KEY_MINUS );
    }
#line 4623 "src-generated/ugbc.tab.c"
    break;

  case 129: /* key_scancode_definition: PERIOD  */
#line 580 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode PERIOD)")->name;
        variable_store( _environment, (yyval.string), KEY_PERIOD );
    }
#line 4632 "src-generated/ugbc.tab.c"
    break;

  case 130: /* key_scancode_definition: PLUS  */
#line 584 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode PLUS)")->name;
        variable_store( _environment, (yyval.string), KEY_PLUS );
    }
#line 4641 "src-generated/ugbc.tab.c"
    break;

  case 131: /* key_scancode_definition: POUND  */
#line 588 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode POUND)")->name;
        variable_store( _environment, (yyval.string), KEY_POUND );
    }
#line 4650 "src-generated/ugbc.tab.c"
    break;

  case 132: /* key_scancode_definition: RETURN  */
#line 592 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode RETURN)")->name;
        variable_store( _environment, (yyval.string), KEY_RETURN );
    }
#line 4659 "src-generated/ugbc.tab.c"
    break;

  case 133: /* key_scancode_definition: RUNSTOP  */
#line 596 "src/ugbc.y"
              {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode RUNSTOP)")->name;
        variable_store( _environment, (yyval.string), KEY_RUNSTOP );        
    }
#line 4668 "src-generated/ugbc.tab.c"
    break;

  case 134: /* key_scancode_definition: RUN STOP  */
#line 600 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode RUNSTOP)")->name;
        variable_store( _environment, (yyval.string), KEY_RUNSTOP );        
    }
#line 4677 "src-generated/ugbc.tab.c"
    break;

  case 135: /* key_scancode_definition: SEMICOLON  */
#line 604 "src/ugbc.y"
                {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode SEMICOLON)")->name;
        variable_store( _environment, (yyval.string), KEY_SEMICOLON );
    }
#line 4686 "src-generated/ugbc.tab.c"
    break;

  case 136: /* key_scancode_definition: SLASH  */
#line 608 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode SLASH)")->name;
        variable_store( _environment, (yyval.string), KEY_SLASH );        
    }
#line 4695 "src-generated/ugbc.tab.c"
    break;

  case 137: /* key_scancode_definition: SPACE  */
#line 612 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode SPACE)")->name;
        variable_store( _environment, (yyval.string), KEY_SPACE );        
    }
#line 4704 "src-generated/ugbc.tab.c"
    break;

  case 138: /* $@1: %empty  */
#line 618 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 4713 "src-generated/ugbc.tab.c"
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
#line 4725 "src-generated/ugbc.tab.c"
    break;

  case 140: /* $@2: %empty  */
#line 629 "src/ugbc.y"
                           {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 4734 "src-generated/ugbc.tab.c"
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
#line 4746 "src-generated/ugbc.tab.c"
    break;

  case 142: /* exponential: Identifier  */
#line 640 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 4754 "src-generated/ugbc.tab.c"
    break;

  case 143: /* exponential: Identifier OP_DOLLAR  */
#line 643 "src/ugbc.y"
                           { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 4762 "src-generated/ugbc.tab.c"
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
#line 4776 "src-generated/ugbc.tab.c"
    break;

  case 145: /* exponential: OP_MINUS Integer  */
#line 655 "src/ugbc.y"
                       { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 4785 "src-generated/ugbc.tab.c"
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
#line 4797 "src-generated/ugbc.tab.c"
    break;

  case 147: /* exponential: OP BYTE CP Integer  */
#line 666 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 4806 "src-generated/ugbc.tab.c"
    break;

  case 148: /* exponential: OP SIGNED BYTE CP Integer  */
#line 670 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 4815 "src-generated/ugbc.tab.c"
    break;

  case 149: /* exponential: OP WORD CP Integer  */
#line 674 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 4824 "src-generated/ugbc.tab.c"
    break;

  case 150: /* exponential: OP SIGNED WORD CP Integer  */
#line 678 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 4833 "src-generated/ugbc.tab.c"
    break;

  case 151: /* exponential: OP DWORD CP Integer  */
#line 682 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 4842 "src-generated/ugbc.tab.c"
    break;

  case 152: /* exponential: OP SIGNED DWORD CP Integer  */
#line 686 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 4851 "src-generated/ugbc.tab.c"
    break;

  case 153: /* exponential: OP POSITION CP Integer  */
#line 690 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 4860 "src-generated/ugbc.tab.c"
    break;

  case 154: /* exponential: OP COLOR CP Integer  */
#line 694 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 4869 "src-generated/ugbc.tab.c"
    break;

  case 155: /* exponential: color_enumeration  */
#line 698 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 4877 "src-generated/ugbc.tab.c"
    break;

  case 156: /* exponential: PEEK OP expr CP  */
#line 701 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 4885 "src-generated/ugbc.tab.c"
    break;

  case 157: /* exponential: XPEN  */
#line 704 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 4893 "src-generated/ugbc.tab.c"
    break;

  case 158: /* exponential: YPEN  */
#line 707 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 4901 "src-generated/ugbc.tab.c"
    break;

  case 159: /* exponential: COLLISION OP direct_integer CP  */
#line 710 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 4909 "src-generated/ugbc.tab.c"
    break;

  case 160: /* exponential: COLLISION OP expr CP  */
#line 713 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 4917 "src-generated/ugbc.tab.c"
    break;

  case 161: /* exponential: HIT OP direct_integer CP  */
#line 716 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 4925 "src-generated/ugbc.tab.c"
    break;

  case 162: /* exponential: HIT OP expr CP  */
#line 719 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 4933 "src-generated/ugbc.tab.c"
    break;

  case 163: /* exponential: LEFT OP expr OP_COMMA expr CP  */
#line 722 "src/ugbc.y"
                                    {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4941 "src-generated/ugbc.tab.c"
    break;

  case 164: /* exponential: RIGHT OP expr OP_COMMA expr CP  */
#line 725 "src/ugbc.y"
                                     {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4949 "src-generated/ugbc.tab.c"
    break;

  case 165: /* exponential: MID OP expr OP_COMMA expr CP  */
#line 728 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 4957 "src-generated/ugbc.tab.c"
    break;

  case 166: /* exponential: MID OP expr OP_COMMA expr OP_COMMA expr CP  */
#line 731 "src/ugbc.y"
                                                 {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4965 "src-generated/ugbc.tab.c"
    break;

  case 167: /* exponential: INSTR OP expr OP_COMMA expr CP  */
#line 734 "src/ugbc.y"
                                     {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 4973 "src-generated/ugbc.tab.c"
    break;

  case 168: /* exponential: INSTR OP expr OP_COMMA expr OP_COMMA expr CP  */
#line 737 "src/ugbc.y"
                                                   {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4981 "src-generated/ugbc.tab.c"
    break;

  case 169: /* exponential: UPPER OP expr CP  */
#line 740 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 4989 "src-generated/ugbc.tab.c"
    break;

  case 170: /* exponential: LOWER OP expr CP  */
#line 743 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 4997 "src-generated/ugbc.tab.c"
    break;

  case 171: /* exponential: STR OP expr CP  */
#line 746 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 5005 "src-generated/ugbc.tab.c"
    break;

  case 172: /* exponential: BIN OP expr CP  */
#line 749 "src/ugbc.y"
                     {
        (yyval.string) = variable_bin( _environment, (yyvsp[-1].string), NULL )->name;
    }
#line 5013 "src-generated/ugbc.tab.c"
    break;

  case 173: /* exponential: BIN OP expr OP_COMMA expr CP  */
#line 752 "src/ugbc.y"
                                   {
        (yyval.string) = variable_bin( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5021 "src-generated/ugbc.tab.c"
    break;

  case 174: /* exponential: SPACE OP expr CP  */
#line 755 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 5029 "src-generated/ugbc.tab.c"
    break;

  case 175: /* exponential: FLIP OP expr CP  */
#line 758 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 5037 "src-generated/ugbc.tab.c"
    break;

  case 176: /* exponential: CHR OP expr CP  */
#line 761 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 5045 "src-generated/ugbc.tab.c"
    break;

  case 177: /* exponential: ASC OP expr CP  */
#line 764 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 5053 "src-generated/ugbc.tab.c"
    break;

  case 178: /* exponential: LEN OP expr CP  */
#line 767 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 5061 "src-generated/ugbc.tab.c"
    break;

  case 179: /* exponential: STRING OP expr OP_COMMA expr CP  */
#line 770 "src/ugbc.y"
                                      {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5069 "src-generated/ugbc.tab.c"
    break;

  case 180: /* exponential: VAL OP expr CP  */
#line 773 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 5077 "src-generated/ugbc.tab.c"
    break;

  case 181: /* exponential: RANDOM random_definition  */
#line 776 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 5085 "src-generated/ugbc.tab.c"
    break;

  case 182: /* exponential: RND OP expr CP  */
#line 779 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 5093 "src-generated/ugbc.tab.c"
    break;

  case 183: /* exponential: OP expr CP  */
#line 782 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 5101 "src-generated/ugbc.tab.c"
    break;

  case 184: /* exponential: MAX OP expr OP_COMMA expr CP  */
#line 785 "src/ugbc.y"
                                   {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5109 "src-generated/ugbc.tab.c"
    break;

  case 185: /* exponential: MIN OP expr OP_COMMA expr CP  */
#line 788 "src/ugbc.y"
                                   {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5117 "src-generated/ugbc.tab.c"
    break;

  case 186: /* exponential: PARAM OP Identifier CP  */
#line 791 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 5125 "src-generated/ugbc.tab.c"
    break;

  case 187: /* exponential: PARAM OP_DOLLAR OP Identifier CP  */
#line 794 "src/ugbc.y"
                                       {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 5133 "src-generated/ugbc.tab.c"
    break;

  case 188: /* $@3: %empty  */
#line 797 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5141 "src-generated/ugbc.tab.c"
    break;

  case 189: /* exponential: Identifier OSP $@3 values CSP  */
#line 799 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 5150 "src-generated/ugbc.tab.c"
    break;

  case 190: /* exponential: SGN OP expr CP  */
#line 803 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 5158 "src-generated/ugbc.tab.c"
    break;

  case 191: /* exponential: ABS OP expr CP  */
#line 806 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 5166 "src-generated/ugbc.tab.c"
    break;

  case 192: /* exponential: TRUE  */
#line 809 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 5175 "src-generated/ugbc.tab.c"
    break;

  case 193: /* exponential: FALSE  */
#line 813 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 0 );
    }
#line 5184 "src-generated/ugbc.tab.c"
    break;

  case 194: /* exponential: COLORS  */
#line 817 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 5193 "src-generated/ugbc.tab.c"
    break;

  case 195: /* exponential: PEN COLORS  */
#line 821 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 5202 "src-generated/ugbc.tab.c"
    break;

  case 196: /* exponential: PEN DEFAULT  */
#line 825 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 5211 "src-generated/ugbc.tab.c"
    break;

  case 197: /* exponential: DEFAULT PEN  */
#line 829 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 5220 "src-generated/ugbc.tab.c"
    break;

  case 198: /* exponential: PAPER COLORS  */
#line 833 "src/ugbc.y"
                   {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 5229 "src-generated/ugbc.tab.c"
    break;

  case 199: /* exponential: PAPER DEFAULT  */
#line 837 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 5238 "src-generated/ugbc.tab.c"
    break;

  case 200: /* exponential: DEFAULT PAPER  */
#line 841 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 5247 "src-generated/ugbc.tab.c"
    break;

  case 201: /* exponential: WIDTH  */
#line 845 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 5255 "src-generated/ugbc.tab.c"
    break;

  case 202: /* exponential: HEIGHT  */
#line 848 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 5263 "src-generated/ugbc.tab.c"
    break;

  case 203: /* exponential: TIMER  */
#line 851 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 5271 "src-generated/ugbc.tab.c"
    break;

  case 204: /* exponential: PEN OP_DOLLAR OP expr CP  */
#line 854 "src/ugbc.y"
                               {
        (yyval.string) = text_get_pen( _environment, (yyvsp[-1].string) )->name;
    }
#line 5279 "src-generated/ugbc.tab.c"
    break;

  case 205: /* exponential: PAPER OP_DOLLAR OP expr CP  */
#line 857 "src/ugbc.y"
                                 {
        (yyval.string) = text_get_paper( _environment, (yyvsp[-1].string) )->name;
    }
#line 5287 "src-generated/ugbc.tab.c"
    break;

  case 206: /* exponential: CMOVE OP_DOLLAR OP expr OP_COMMA expr CP  */
#line 860 "src/ugbc.y"
                                               {
        (yyval.string) = text_get_cmove( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5295 "src-generated/ugbc.tab.c"
    break;

  case 207: /* exponential: CUP OP_DOLLAR  */
#line 863 "src/ugbc.y"
                    {
        (yyval.string) = text_get_cmove_direct( _environment, 0, -1 )->name;
    }
#line 5303 "src-generated/ugbc.tab.c"
    break;

  case 208: /* exponential: CDOWN OP_DOLLAR  */
#line 866 "src/ugbc.y"
                      {
        (yyval.string) = text_get_cmove_direct( _environment, 0, 1 )->name;
    }
#line 5311 "src-generated/ugbc.tab.c"
    break;

  case 209: /* exponential: CLEFT OP_DOLLAR  */
#line 869 "src/ugbc.y"
                      {
        (yyval.string) = text_get_cmove_direct( _environment, -1, 0 )->name;
    }
#line 5319 "src-generated/ugbc.tab.c"
    break;

  case 210: /* exponential: CRIGHT OP_DOLLAR  */
#line 872 "src/ugbc.y"
                       {
        (yyval.string) = text_get_cmove_direct( _environment, 1, 0 )->name;
    }
#line 5327 "src-generated/ugbc.tab.c"
    break;

  case 211: /* exponential: AT OP_DOLLAR OP expr OP_COMMA expr CP  */
#line 875 "src/ugbc.y"
                                            {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5335 "src-generated/ugbc.tab.c"
    break;

  case 212: /* exponential: LOCATE OP_DOLLAR OP expr OP_COMMA expr CP  */
#line 878 "src/ugbc.y"
                                                {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5343 "src-generated/ugbc.tab.c"
    break;

  case 213: /* exponential: TAB OP_DOLLAR  */
#line 881 "src/ugbc.y"
                    {
        (yyval.string) = text_get_tab( _environment )->name;
    }
#line 5351 "src-generated/ugbc.tab.c"
    break;

  case 214: /* exponential: XCURS  */
#line 884 "src/ugbc.y"
            {
        (yyval.string) = text_get_xcurs( _environment )->name;
    }
#line 5359 "src-generated/ugbc.tab.c"
    break;

  case 215: /* exponential: YCURS  */
#line 887 "src/ugbc.y"
            {
        (yyval.string) = text_get_ycurs( _environment )->name;
    }
#line 5367 "src-generated/ugbc.tab.c"
    break;

  case 216: /* exponential: TEXTADDRESS  */
#line 890 "src/ugbc.y"
                  {
        (yyval.string) = strdup( "TEXTADDRESS" );
    }
#line 5375 "src-generated/ugbc.tab.c"
    break;

  case 217: /* exponential: JOY OP expr CP  */
#line 893 "src/ugbc.y"
                     {
        (yyval.string) = joy( _environment, (yyvsp[-1].string) )->name;
    }
#line 5383 "src-generated/ugbc.tab.c"
    break;

  case 218: /* exponential: JUP OP expr CP  */
#line 896 "src/ugbc.y"
                     {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_UP )->name;
    }
#line 5391 "src-generated/ugbc.tab.c"
    break;

  case 219: /* exponential: JDOWN OP expr CP  */
#line 899 "src/ugbc.y"
                       {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_DOWN )->name;
    }
#line 5399 "src-generated/ugbc.tab.c"
    break;

  case 220: /* exponential: JLEFT OP expr CP  */
#line 902 "src/ugbc.y"
                       {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_LEFT )->name;
    }
#line 5407 "src-generated/ugbc.tab.c"
    break;

  case 221: /* exponential: JRIGHT OP expr CP  */
#line 905 "src/ugbc.y"
                        {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_RIGHT )->name;
    }
#line 5415 "src-generated/ugbc.tab.c"
    break;

  case 222: /* exponential: JFIRE OP expr CP  */
#line 908 "src/ugbc.y"
                       {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_FIRE )->name;
    }
#line 5423 "src-generated/ugbc.tab.c"
    break;

  case 223: /* exponential: FIRE OP expr CP  */
#line 911 "src/ugbc.y"
                      {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_FIRE )->name;
    }
#line 5431 "src-generated/ugbc.tab.c"
    break;

  case 224: /* exponential: JOY COUNT  */
#line 914 "src/ugbc.y"
                {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(JOYCOUNT)" )->name;
        variable_store( _environment, (yyval.string), JOY_COUNT );
    }
#line 5440 "src-generated/ugbc.tab.c"
    break;

  case 225: /* exponential: JOYCOUNT  */
#line 918 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(JOYCOUNT)" )->name;
        variable_store( _environment, (yyval.string), JOY_COUNT );
    }
#line 5449 "src-generated/ugbc.tab.c"
    break;

  case 226: /* exponential: BIT OP expr OP_COMMA expr CP  */
#line 922 "src/ugbc.y"
                                   {
        (yyval.string) = variable_bit( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5457 "src-generated/ugbc.tab.c"
    break;

  case 227: /* exponential: UP  */
#line 925 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(UP)" )->name;
        variable_store( _environment, (yyval.string), JOY_UP );
    }
#line 5466 "src-generated/ugbc.tab.c"
    break;

  case 228: /* exponential: DOWN  */
#line 929 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(DOWN)" )->name;
        variable_store( _environment, (yyval.string), JOY_DOWN );
    }
#line 5475 "src-generated/ugbc.tab.c"
    break;

  case 229: /* exponential: LEFT  */
#line 933 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(LEFT)" )->name;
        variable_store( _environment, (yyval.string), JOY_LEFT );
    }
#line 5484 "src-generated/ugbc.tab.c"
    break;

  case 230: /* exponential: RIGHT  */
#line 937 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(RIGHT)" )->name;
        variable_store( _environment, (yyval.string), JOY_RIGHT );
    }
#line 5493 "src-generated/ugbc.tab.c"
    break;

  case 231: /* exponential: FIRE  */
#line 941 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(FIRE)" )->name;
        variable_store( _environment, (yyval.string), JOY_FIRE );
    }
#line 5502 "src-generated/ugbc.tab.c"
    break;

  case 232: /* exponential: INKEY  */
#line 945 "src/ugbc.y"
            {
        (yyval.string) = inkey( _environment )->name;
    }
#line 5510 "src-generated/ugbc.tab.c"
    break;

  case 233: /* exponential: SCANCODE  */
#line 948 "src/ugbc.y"
               {
        (yyval.string) = scancode( _environment )->name;
    }
#line 5518 "src-generated/ugbc.tab.c"
    break;

  case 234: /* exponential: SCAN CODE  */
#line 951 "src/ugbc.y"
                {
        (yyval.string) = scancode( _environment )->name;
    }
#line 5526 "src-generated/ugbc.tab.c"
    break;

  case 235: /* exponential: KEY STATE OP expr CP  */
#line 954 "src/ugbc.y"
                           {
        (yyval.string) = key_state( _environment, (yyvsp[-1].string) )->name;
    }
#line 5534 "src-generated/ugbc.tab.c"
    break;

  case 236: /* exponential: KEYSTATE OP expr CP  */
#line 957 "src/ugbc.y"
                          {
        (yyval.string) = key_state( _environment, (yyvsp[-1].string) )->name;
    }
#line 5542 "src-generated/ugbc.tab.c"
    break;

  case 237: /* exponential: SCANSHIFT  */
#line 960 "src/ugbc.y"
                {
        (yyval.string) = scanshift( _environment )->name;
    }
#line 5550 "src-generated/ugbc.tab.c"
    break;

  case 238: /* exponential: SCAN SHIFT  */
#line 963 "src/ugbc.y"
                 {
        (yyval.string) = scanshift( _environment )->name;
    }
#line 5558 "src-generated/ugbc.tab.c"
    break;

  case 239: /* exponential: KEYSHIFT  */
#line 966 "src/ugbc.y"
               {
        (yyval.string) = keyshift( _environment )->name;
    }
#line 5566 "src-generated/ugbc.tab.c"
    break;

  case 240: /* exponential: KEY SHIFT  */
#line 969 "src/ugbc.y"
                {
        (yyval.string) = keyshift( _environment )->name;
    }
#line 5574 "src-generated/ugbc.tab.c"
    break;

  case 241: /* exponential: LEFT SHIFT  */
#line 972 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT LEFT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_LEFT );
    }
#line 5583 "src-generated/ugbc.tab.c"
    break;

  case 242: /* exponential: SHIFT LEFT  */
#line 976 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT LEFT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_LEFT );
    }
#line 5592 "src-generated/ugbc.tab.c"
    break;

  case 243: /* exponential: RIGHT SHIFT  */
#line 980 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT RIGHT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_RIGHT );
    }
#line 5601 "src-generated/ugbc.tab.c"
    break;

  case 244: /* exponential: SHIFT RIGHT  */
#line 984 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT RIGHT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_RIGHT );
    }
#line 5610 "src-generated/ugbc.tab.c"
    break;

  case 245: /* exponential: CAPSLOCK  */
#line 988 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT CAPSLOCK)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_CAPSLOCK );
    }
#line 5619 "src-generated/ugbc.tab.c"
    break;

  case 246: /* exponential: CAPS LOCK  */
#line 992 "src/ugbc.y"
                {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT CAPSLOCK)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_CAPSLOCK );
    }
#line 5628 "src-generated/ugbc.tab.c"
    break;

  case 247: /* exponential: CONTROL  */
#line 996 "src/ugbc.y"
              {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT CONTROL)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_CONTROL );
    }
#line 5637 "src-generated/ugbc.tab.c"
    break;

  case 248: /* exponential: LEFT ALT  */
#line 1000 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT LEFT ALT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_LEFT_ALT );
    }
#line 5646 "src-generated/ugbc.tab.c"
    break;

  case 249: /* exponential: ALT LEFT  */
#line 1004 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT LEFT ALT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_LEFT_ALT );
    }
#line 5655 "src-generated/ugbc.tab.c"
    break;

  case 250: /* exponential: RIGHT ALT  */
#line 1008 "src/ugbc.y"
                {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT RIGHT ALT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_RIGHT_ALT );
    }
#line 5664 "src-generated/ugbc.tab.c"
    break;

  case 251: /* exponential: ALT RIGHT  */
#line 1012 "src/ugbc.y"
                {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT RIGHT ALT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_RIGHT_ALT );
    }
#line 5673 "src-generated/ugbc.tab.c"
    break;

  case 252: /* exponential: KEY key_scancode_definition  */
#line 1016 "src/ugbc.y"
                                  {
        (yyval.string) = (yyvsp[0].string);
    }
#line 5681 "src-generated/ugbc.tab.c"
    break;

  case 255: /* bank_definition_simple: AT direct_integer  */
#line 1024 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 5689 "src-generated/ugbc.tab.c"
    break;

  case 256: /* bank_definition_simple: Identifier AT direct_integer  */
#line 1027 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 5697 "src-generated/ugbc.tab.c"
    break;

  case 257: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 1030 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 5705 "src-generated/ugbc.tab.c"
    break;

  case 258: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 1033 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 5713 "src-generated/ugbc.tab.c"
    break;

  case 259: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 1036 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 5721 "src-generated/ugbc.tab.c"
    break;

  case 260: /* bank_definition_simple: DATA AT direct_integer  */
#line 1039 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 5729 "src-generated/ugbc.tab.c"
    break;

  case 261: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 1043 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 5737 "src-generated/ugbc.tab.c"
    break;

  case 262: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 1046 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 5745 "src-generated/ugbc.tab.c"
    break;

  case 263: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 1049 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 5753 "src-generated/ugbc.tab.c"
    break;

  case 264: /* bank_definition_simple: CODE AT direct_integer  */
#line 1052 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 5761 "src-generated/ugbc.tab.c"
    break;

  case 265: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 1056 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 5769 "src-generated/ugbc.tab.c"
    break;

  case 266: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 1059 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 5777 "src-generated/ugbc.tab.c"
    break;

  case 267: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 1062 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 5785 "src-generated/ugbc.tab.c"
    break;

  case 268: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 1065 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 5793 "src-generated/ugbc.tab.c"
    break;

  case 269: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 1069 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 5801 "src-generated/ugbc.tab.c"
    break;

  case 270: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 1072 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 5809 "src-generated/ugbc.tab.c"
    break;

  case 271: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 1075 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 5817 "src-generated/ugbc.tab.c"
    break;

  case 272: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 1078 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 5825 "src-generated/ugbc.tab.c"
    break;

  case 273: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 1084 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 5833 "src-generated/ugbc.tab.c"
    break;

  case 274: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 1087 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 5841 "src-generated/ugbc.tab.c"
    break;

  case 275: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 1090 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 5849 "src-generated/ugbc.tab.c"
    break;

  case 276: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 1093 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 5857 "src-generated/ugbc.tab.c"
    break;

  case 277: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 1096 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 5865 "src-generated/ugbc.tab.c"
    break;

  case 280: /* raster_definition_simple: Identifier AT direct_integer  */
#line 1105 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 5873 "src-generated/ugbc.tab.c"
    break;

  case 281: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 1108 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 5881 "src-generated/ugbc.tab.c"
    break;

  case 282: /* raster_definition_expression: Identifier AT expr  */
#line 1113 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5889 "src-generated/ugbc.tab.c"
    break;

  case 283: /* raster_definition_expression: AT expr WITH Identifier  */
#line 1116 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5897 "src-generated/ugbc.tab.c"
    break;

  case 286: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 1125 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 5905 "src-generated/ugbc.tab.c"
    break;

  case 287: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 1128 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 5913 "src-generated/ugbc.tab.c"
    break;

  case 288: /* next_raster_definition_expression: Identifier AT expr  */
#line 1133 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 5921 "src-generated/ugbc.tab.c"
    break;

  case 289: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 1136 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5929 "src-generated/ugbc.tab.c"
    break;

  case 292: /* color_definition_simple: BORDER direct_integer  */
#line 1145 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 5937 "src-generated/ugbc.tab.c"
    break;

  case 293: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 1148 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 5945 "src-generated/ugbc.tab.c"
    break;

  case 294: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 1151 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 5953 "src-generated/ugbc.tab.c"
    break;

  case 295: /* color_definition_expression: BORDER expr  */
#line 1156 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 5961 "src-generated/ugbc.tab.c"
    break;

  case 296: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 1159 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 5969 "src-generated/ugbc.tab.c"
    break;

  case 297: /* color_definition_expression: SPRITE expr TO expr  */
#line 1162 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 5977 "src-generated/ugbc.tab.c"
    break;

  case 303: /* wait_definition_simple: direct_integer CYCLES  */
#line 1176 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 5985 "src-generated/ugbc.tab.c"
    break;

  case 304: /* wait_definition_simple: direct_integer TICKS  */
#line 1179 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 5993 "src-generated/ugbc.tab.c"
    break;

  case 305: /* wait_definition_simple: direct_integer milliseconds  */
#line 1182 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 6001 "src-generated/ugbc.tab.c"
    break;

  case 306: /* wait_definition_simple: KEY  */
#line 1185 "src/ugbc.y"
          {
      wait_key( _environment );
    }
#line 6009 "src-generated/ugbc.tab.c"
    break;

  case 307: /* wait_definition_expression: expr CYCLES  */
#line 1191 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 6017 "src-generated/ugbc.tab.c"
    break;

  case 308: /* wait_definition_expression: expr TICKS  */
#line 1194 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 6025 "src-generated/ugbc.tab.c"
    break;

  case 309: /* wait_definition_expression: expr milliseconds  */
#line 1197 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 6033 "src-generated/ugbc.tab.c"
    break;

  case 312: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 1207 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 6041 "src-generated/ugbc.tab.c"
    break;

  case 313: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 1210 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 6049 "src-generated/ugbc.tab.c"
    break;

  case 314: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 1213 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 6057 "src-generated/ugbc.tab.c"
    break;

  case 315: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 1216 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 6065 "src-generated/ugbc.tab.c"
    break;

  case 316: /* sprite_definition_simple: direct_integer position OP direct_integer OP_COMMA direct_integer CP  */
#line 1219 "src/ugbc.y"
                                                                         {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 6073 "src-generated/ugbc.tab.c"
    break;

  case 317: /* sprite_definition_simple: direct_integer ENABLE  */
#line 1222 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 6081 "src-generated/ugbc.tab.c"
    break;

  case 318: /* sprite_definition_simple: direct_integer DISABLE  */
#line 1225 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 6089 "src-generated/ugbc.tab.c"
    break;

  case 319: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 1228 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 6097 "src-generated/ugbc.tab.c"
    break;

  case 320: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 1231 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 6105 "src-generated/ugbc.tab.c"
    break;

  case 321: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 1234 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 6113 "src-generated/ugbc.tab.c"
    break;

  case 322: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 1237 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 6121 "src-generated/ugbc.tab.c"
    break;

  case 323: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 1240 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 6129 "src-generated/ugbc.tab.c"
    break;

  case 324: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 1243 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 6137 "src-generated/ugbc.tab.c"
    break;

  case 325: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 1246 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 6145 "src-generated/ugbc.tab.c"
    break;

  case 326: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 1249 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 6153 "src-generated/ugbc.tab.c"
    break;

  case 327: /* sprite_definition_expression: expr DATA FROM expr  */
#line 1254 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6161 "src-generated/ugbc.tab.c"
    break;

  case 328: /* sprite_definition_expression: expr MULTICOLOR  */
#line 1257 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 6169 "src-generated/ugbc.tab.c"
    break;

  case 329: /* sprite_definition_expression: expr MONOCOLOR  */
#line 1260 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 6177 "src-generated/ugbc.tab.c"
    break;

  case 330: /* sprite_definition_expression: expr COLOR expr  */
#line 1263 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 6185 "src-generated/ugbc.tab.c"
    break;

  case 331: /* sprite_definition_expression: expr position OP expr OP_COMMA expr CP  */
#line 1266 "src/ugbc.y"
                                           {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 6193 "src-generated/ugbc.tab.c"
    break;

  case 332: /* sprite_definition_expression: expr ENABLE  */
#line 1269 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 6201 "src-generated/ugbc.tab.c"
    break;

  case 333: /* sprite_definition_expression: expr DISABLE  */
#line 1272 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 6209 "src-generated/ugbc.tab.c"
    break;

  case 334: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 1275 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 6217 "src-generated/ugbc.tab.c"
    break;

  case 335: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 1278 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 6225 "src-generated/ugbc.tab.c"
    break;

  case 336: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 1281 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 6233 "src-generated/ugbc.tab.c"
    break;

  case 337: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 1284 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 6241 "src-generated/ugbc.tab.c"
    break;

  case 338: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 1287 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 6249 "src-generated/ugbc.tab.c"
    break;

  case 339: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 1290 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 6257 "src-generated/ugbc.tab.c"
    break;

  case 340: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 1293 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 6265 "src-generated/ugbc.tab.c"
    break;

  case 341: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 1296 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 6273 "src-generated/ugbc.tab.c"
    break;

  case 344: /* bitmap_definition_simple: AT direct_integer  */
#line 1305 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 6281 "src-generated/ugbc.tab.c"
    break;

  case 345: /* bitmap_definition_simple: ENABLE  */
#line 1308 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 6289 "src-generated/ugbc.tab.c"
    break;

  case 346: /* bitmap_definition_simple: DISABLE  */
#line 1311 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 6297 "src-generated/ugbc.tab.c"
    break;

  case 347: /* bitmap_definition_simple: CLEAR  */
#line 1314 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 6305 "src-generated/ugbc.tab.c"
    break;

  case 348: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 1317 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 6313 "src-generated/ugbc.tab.c"
    break;

  case 349: /* bitmap_definition_expression: AT expr  */
#line 1323 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 6321 "src-generated/ugbc.tab.c"
    break;

  case 350: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 1326 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 6329 "src-generated/ugbc.tab.c"
    break;

  case 353: /* textmap_definition_simple: AT direct_integer  */
#line 1336 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 6337 "src-generated/ugbc.tab.c"
    break;

  case 354: /* textmap_definition_expression: AT expr  */
#line 1341 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 6345 "src-generated/ugbc.tab.c"
    break;

  case 357: /* text_definition_simple: ENABLE  */
#line 1350 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 6353 "src-generated/ugbc.tab.c"
    break;

  case 358: /* text_definition_simple: DISABLE  */
#line 1353 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 6361 "src-generated/ugbc.tab.c"
    break;

  case 359: /* text_definition_expression: AT expr OP_COMMA expr OP_COMMA expr  */
#line 1358 "src/ugbc.y"
                                         {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 6369 "src-generated/ugbc.tab.c"
    break;

  case 360: /* text_definition_expression: expr OP_COMMA expr OP_COMMA expr  */
#line 1361 "src/ugbc.y"
                                      {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 6377 "src-generated/ugbc.tab.c"
    break;

  case 363: /* tiles_definition_simple: AT direct_integer  */
#line 1370 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 6385 "src-generated/ugbc.tab.c"
    break;

  case 364: /* tiles_definition_expression: AT expr  */
#line 1375 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 6393 "src-generated/ugbc.tab.c"
    break;

  case 367: /* colormap_definition_simple: AT direct_integer  */
#line 1384 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 6401 "src-generated/ugbc.tab.c"
    break;

  case 368: /* colormap_definition_simple: CLEAR  */
#line 1387 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 6409 "src-generated/ugbc.tab.c"
    break;

  case 369: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 1390 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 6417 "src-generated/ugbc.tab.c"
    break;

  case 370: /* colormap_definition_expression: AT expr  */
#line 1395 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 6425 "src-generated/ugbc.tab.c"
    break;

  case 371: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 1398 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 6433 "src-generated/ugbc.tab.c"
    break;

  case 374: /* screen_definition_simple: ON  */
#line 1408 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 6441 "src-generated/ugbc.tab.c"
    break;

  case 375: /* screen_definition_simple: OFF  */
#line 1411 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 6449 "src-generated/ugbc.tab.c"
    break;

  case 376: /* screen_definition_simple: ROWS direct_integer  */
#line 1414 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 6457 "src-generated/ugbc.tab.c"
    break;

  case 377: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 1417 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 6465 "src-generated/ugbc.tab.c"
    break;

  case 378: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 1420 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 6473 "src-generated/ugbc.tab.c"
    break;

  case 379: /* screen_definition_expression: ROWS expr  */
#line 1425 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 6481 "src-generated/ugbc.tab.c"
    break;

  case 380: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 1428 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 6489 "src-generated/ugbc.tab.c"
    break;

  case 381: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 1431 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 6497 "src-generated/ugbc.tab.c"
    break;

  case 385: /* var_definition_simple: Identifier ON Identifier  */
#line 1440 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 6505 "src-generated/ugbc.tab.c"
    break;

  case 386: /* var_definition_simple: Identifier OP_DOLLAR ON Identifier  */
#line 1443 "src/ugbc.y"
                                       {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 6513 "src-generated/ugbc.tab.c"
    break;

  case 387: /* var_definition_simple: Identifier ON Identifier OP_ASSIGN direct_integer  */
#line 1446 "src/ugbc.y"
                                                      {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 6521 "src-generated/ugbc.tab.c"
    break;

  case 388: /* var_definition_simple: Identifier ON Identifier OP_ASSIGN expr  */
#line 1449 "src/ugbc.y"
                                            {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 6531 "src-generated/ugbc.tab.c"
    break;

  case 389: /* var_definition_simple: Identifier OP_DOLLAR ON Identifier OP_ASSIGN expr  */
#line 1454 "src/ugbc.y"
                                                      {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 6541 "src-generated/ugbc.tab.c"
    break;

  case 390: /* goto_definition: Identifier  */
#line 1461 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 6549 "src-generated/ugbc.tab.c"
    break;

  case 391: /* goto_definition: Integer  */
#line 1464 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 6557 "src-generated/ugbc.tab.c"
    break;

  case 392: /* gosub_definition: Identifier  */
#line 1470 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 6565 "src-generated/ugbc.tab.c"
    break;

  case 393: /* gosub_definition: Integer  */
#line 1473 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 6573 "src-generated/ugbc.tab.c"
    break;

  case 395: /* point_definition_simple: AT OP direct_integer OP_COMMA direct_integer CP  */
#line 1482 "src/ugbc.y"
                                                      {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 6581 "src-generated/ugbc.tab.c"
    break;

  case 396: /* point_definition_expression: AT OP expr OP_COMMA expr CP  */
#line 1488 "src/ugbc.y"
                                  {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 6589 "src-generated/ugbc.tab.c"
    break;

  case 399: /* ink_definition: expr  */
#line 1497 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 6597 "src-generated/ugbc.tab.c"
    break;

  case 400: /* on_goto_definition: Identifier  */
#line 1502 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 6606 "src-generated/ugbc.tab.c"
    break;

  case 401: /* $@4: %empty  */
#line 1506 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 6614 "src-generated/ugbc.tab.c"
    break;

  case 403: /* on_gosub_definition: Identifier  */
#line 1511 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 6623 "src-generated/ugbc.tab.c"
    break;

  case 404: /* $@5: %empty  */
#line 1515 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 6631 "src-generated/ugbc.tab.c"
    break;

  case 406: /* on_proc_definition: Identifier  */
#line 1520 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 6640 "src-generated/ugbc.tab.c"
    break;

  case 407: /* $@6: %empty  */
#line 1524 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 6648 "src-generated/ugbc.tab.c"
    break;

  case 409: /* $@7: %empty  */
#line 1529 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 6656 "src-generated/ugbc.tab.c"
    break;

  case 411: /* $@8: %empty  */
#line 1532 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 6664 "src-generated/ugbc.tab.c"
    break;

  case 413: /* $@9: %empty  */
#line 1535 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 6672 "src-generated/ugbc.tab.c"
    break;

  case 415: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1540 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 6680 "src-generated/ugbc.tab.c"
    break;

  case 416: /* every_definition: ON  */
#line 1543 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 6688 "src-generated/ugbc.tab.c"
    break;

  case 417: /* every_definition: OFF  */
#line 1546 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 6696 "src-generated/ugbc.tab.c"
    break;

  case 418: /* add_definition: Identifier OP_COMMA expr  */
#line 1551 "src/ugbc.y"
                             {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 6704 "src-generated/ugbc.tab.c"
    break;

  case 419: /* add_definition: Identifier OP_COMMA expr OP_COMMA expr TO expr  */
#line 1554 "src/ugbc.y"
                                                     {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 6712 "src-generated/ugbc.tab.c"
    break;

  case 420: /* dimensions: Integer  */
#line 1560 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 6721 "src-generated/ugbc.tab.c"
    break;

  case 421: /* dimensions: Integer OP_COMMA dimensions  */
#line 1564 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 6730 "src-generated/ugbc.tab.c"
    break;

  case 422: /* datatype: BYTE  */
#line 1571 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 6738 "src-generated/ugbc.tab.c"
    break;

  case 423: /* datatype: SIGNED BYTE  */
#line 1574 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 6746 "src-generated/ugbc.tab.c"
    break;

  case 424: /* datatype: WORD  */
#line 1577 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 6754 "src-generated/ugbc.tab.c"
    break;

  case 425: /* datatype: SIGNED WORD  */
#line 1580 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 6762 "src-generated/ugbc.tab.c"
    break;

  case 426: /* datatype: DWORD  */
#line 1583 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 6770 "src-generated/ugbc.tab.c"
    break;

  case 427: /* datatype: SIGNED DWORD  */
#line 1586 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 6778 "src-generated/ugbc.tab.c"
    break;

  case 428: /* datatype: ADDRESS  */
#line 1589 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 6786 "src-generated/ugbc.tab.c"
    break;

  case 429: /* datatype: POSITION  */
#line 1592 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 6794 "src-generated/ugbc.tab.c"
    break;

  case 430: /* datatype: COLOR  */
#line 1595 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 6802 "src-generated/ugbc.tab.c"
    break;

  case 431: /* datatype: STRING  */
#line 1598 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 6810 "src-generated/ugbc.tab.c"
    break;

  case 432: /* $@10: %empty  */
#line 1603 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 6819 "src-generated/ugbc.tab.c"
    break;

  case 433: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1606 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 6829 "src-generated/ugbc.tab.c"
    break;

  case 434: /* $@11: %empty  */
#line 1611 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 6838 "src-generated/ugbc.tab.c"
    break;

  case 435: /* dim_definition: Identifier $@11 OP_DOLLAR OP dimensions CP  */
#line 1614 "src/ugbc.y"
                                   {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 6848 "src-generated/ugbc.tab.c"
    break;

  case 436: /* $@12: %empty  */
#line 1619 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 6857 "src-generated/ugbc.tab.c"
    break;

  case 437: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1622 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 6867 "src-generated/ugbc.tab.c"
    break;

  case 440: /* indexes: expr  */
#line 1635 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 6876 "src-generated/ugbc.tab.c"
    break;

  case 441: /* indexes: expr OP_COMMA indexes  */
#line 1639 "src/ugbc.y"
                            {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 6885 "src-generated/ugbc.tab.c"
    break;

  case 442: /* parameters: Identifier  */
#line 1646 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6895 "src-generated/ugbc.tab.c"
    break;

  case 443: /* parameters: Identifier OP_DOLLAR  */
#line 1651 "src/ugbc.y"
                           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6905 "src-generated/ugbc.tab.c"
    break;

  case 444: /* parameters: Identifier AS datatype  */
#line 1656 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6915 "src-generated/ugbc.tab.c"
    break;

  case 445: /* parameters: Identifier OP_COMMA parameters  */
#line 1661 "src/ugbc.y"
                                     {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6925 "src-generated/ugbc.tab.c"
    break;

  case 446: /* parameters: Identifier OP_DOLLAR OP_COMMA parameters  */
#line 1666 "src/ugbc.y"
                                               {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6935 "src-generated/ugbc.tab.c"
    break;

  case 447: /* parameters: Identifier AS datatype OP_COMMA parameters  */
#line 1671 "src/ugbc.y"
                                                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6945 "src-generated/ugbc.tab.c"
    break;

  case 448: /* parameters_expr: Identifier  */
#line 1679 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6955 "src-generated/ugbc.tab.c"
    break;

  case 449: /* parameters_expr: Identifier OP_DOLLAR  */
#line 1684 "src/ugbc.y"
                           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6965 "src-generated/ugbc.tab.c"
    break;

  case 450: /* parameters_expr: Identifier AS datatype  */
#line 1689 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6975 "src-generated/ugbc.tab.c"
    break;

  case 451: /* parameters_expr: Identifier OP_COMMA parameters_expr  */
#line 1694 "src/ugbc.y"
                                          {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6985 "src-generated/ugbc.tab.c"
    break;

  case 452: /* parameters_expr: Identifier OP_DOLLAR OP_COMMA parameters_expr  */
#line 1699 "src/ugbc.y"
                                                    {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6995 "src-generated/ugbc.tab.c"
    break;

  case 453: /* parameters_expr: Identifier AS datatype OP_COMMA parameters_expr  */
#line 1704 "src/ugbc.y"
                                                      {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 7005 "src-generated/ugbc.tab.c"
    break;

  case 454: /* parameters_expr: String  */
#line 1709 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 7014 "src-generated/ugbc.tab.c"
    break;

  case 455: /* parameters_expr: String OP_COMMA parameters_expr  */
#line 1713 "src/ugbc.y"
                                      {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 7023 "src-generated/ugbc.tab.c"
    break;

  case 456: /* values: expr  */
#line 1720 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 7032 "src-generated/ugbc.tab.c"
    break;

  case 457: /* values: expr OP_COMMA values  */
#line 1724 "src/ugbc.y"
                           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 7041 "src-generated/ugbc.tab.c"
    break;

  case 458: /* print_definition: expr  */
#line 1731 "src/ugbc.y"
         {
        print( _environment, (yyvsp[0].string), 1 );
    }
#line 7049 "src-generated/ugbc.tab.c"
    break;

  case 459: /* print_definition: expr OP_COMMA  */
#line 1734 "src/ugbc.y"
                  {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 7058 "src-generated/ugbc.tab.c"
    break;

  case 460: /* print_definition: expr OP_SEMICOLON  */
#line 1738 "src/ugbc.y"
                      {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 7066 "src-generated/ugbc.tab.c"
    break;

  case 461: /* $@13: %empty  */
#line 1741 "src/ugbc.y"
                  {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 7075 "src-generated/ugbc.tab.c"
    break;

  case 463: /* $@14: %empty  */
#line 1745 "src/ugbc.y"
                       {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 7083 "src-generated/ugbc.tab.c"
    break;

  case 465: /* writing_mode_definition: REPLACE  */
#line 1751 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing REPLACE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_REPLACE );
    }
#line 7092 "src-generated/ugbc.tab.c"
    break;

  case 466: /* writing_mode_definition: OR  */
#line 1755 "src/ugbc.y"
         {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing OR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_OR );
    }
#line 7101 "src-generated/ugbc.tab.c"
    break;

  case 467: /* writing_mode_definition: XOR  */
#line 1759 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing XOR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_XOR );
    }
#line 7110 "src-generated/ugbc.tab.c"
    break;

  case 468: /* writing_mode_definition: AND  */
#line 1763 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing AND)" )->name;
          variable_store( _environment, (yyval.string), WRITING_AND );
    }
#line 7119 "src-generated/ugbc.tab.c"
    break;

  case 469: /* writing_mode_definition: IGNORE  */
#line 1767 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing IGNORE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_IGNORE );
    }
#line 7128 "src-generated/ugbc.tab.c"
    break;

  case 470: /* writing_part_definition: NORMAL  */
#line 1774 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing NORMAL)" )->name;
          variable_store( _environment, (yyval.string), WRITING_NORMAL );
    }
#line 7137 "src-generated/ugbc.tab.c"
    break;

  case 471: /* writing_part_definition: PAPER  */
#line 1778 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 7146 "src-generated/ugbc.tab.c"
    break;

  case 472: /* writing_part_definition: PAPER ONLY  */
#line 1782 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 7155 "src-generated/ugbc.tab.c"
    break;

  case 473: /* writing_part_definition: PEN  */
#line 1786 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 7164 "src-generated/ugbc.tab.c"
    break;

  case 474: /* writing_part_definition: PEN ONLY  */
#line 1790 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 7173 "src-generated/ugbc.tab.c"
    break;

  case 475: /* writing_definition: writing_mode_definition OP_COMMA writing_part_definition  */
#line 1797 "src/ugbc.y"
                                                             {
        text_writing( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 7181 "src-generated/ugbc.tab.c"
    break;

  case 476: /* locate_definition: OP_COMMA expr  */
#line 1803 "src/ugbc.y"
                   {
        text_locate( _environment, NULL, (yyvsp[0].string) );
    }
#line 7189 "src-generated/ugbc.tab.c"
    break;

  case 477: /* locate_definition: expr OP_COMMA  */
#line 1806 "src/ugbc.y"
                    {
        text_locate( _environment, (yyvsp[-1].string), NULL );
    }
#line 7197 "src-generated/ugbc.tab.c"
    break;

  case 478: /* locate_definition: expr OP_COMMA expr  */
#line 1809 "src/ugbc.y"
                         {
        text_locate( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 7205 "src-generated/ugbc.tab.c"
    break;

  case 479: /* cmove_definition: OP_COMMA expr  */
#line 1815 "src/ugbc.y"
                   {
        text_cmove( _environment, NULL, (yyvsp[0].string) );
    }
#line 7213 "src-generated/ugbc.tab.c"
    break;

  case 480: /* cmove_definition: expr OP_COMMA  */
#line 1818 "src/ugbc.y"
                    {
        text_cmove( _environment, (yyvsp[-1].string), NULL );
    }
#line 7221 "src-generated/ugbc.tab.c"
    break;

  case 481: /* cmove_definition: expr OP_COMMA expr  */
#line 1821 "src/ugbc.y"
                         {
        text_cmove( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 7229 "src-generated/ugbc.tab.c"
    break;

  case 482: /* hscroll_definition: LEFT  */
#line 1827 "src/ugbc.y"
         {
        text_hscroll_line( _environment, -1 );
    }
#line 7237 "src-generated/ugbc.tab.c"
    break;

  case 483: /* hscroll_definition: SCREEN LEFT  */
#line 1830 "src/ugbc.y"
                  {
        text_hscroll_screen( _environment, -1 );
    }
#line 7245 "src-generated/ugbc.tab.c"
    break;

  case 484: /* hscroll_definition: RIGHT  */
#line 1833 "src/ugbc.y"
            {
        text_hscroll_line( _environment, 1 );
    }
#line 7253 "src-generated/ugbc.tab.c"
    break;

  case 485: /* hscroll_definition: SCREEN RIGHT  */
#line 1836 "src/ugbc.y"
                   {
        text_hscroll_screen( _environment, 1 );
    }
#line 7261 "src-generated/ugbc.tab.c"
    break;

  case 486: /* vscroll_definition: SCREEN UP  */
#line 1842 "src/ugbc.y"
                {
        text_vscroll_screen( _environment, -1 );
    }
#line 7269 "src-generated/ugbc.tab.c"
    break;

  case 487: /* vscroll_definition: SCREEN DOWN  */
#line 1845 "src/ugbc.y"
                  {
        text_vscroll_screen( _environment, 1 );
    }
#line 7277 "src-generated/ugbc.tab.c"
    break;

  case 503: /* statement: TEXTADDRESS OP_ASSIGN expr  */
#line 1866 "src/ugbc.y"
                               {
      variable_move( _environment, (yyvsp[0].string), "ADDRESS" );
  }
#line 7285 "src-generated/ugbc.tab.c"
    break;

  case 508: /* statement: MEMORIZE  */
#line 1873 "src/ugbc.y"
             {
      text_memorize( _environment );
  }
#line 7293 "src-generated/ugbc.tab.c"
    break;

  case 509: /* statement: REMEMBER  */
#line 1876 "src/ugbc.y"
             {
      text_remember( _environment );
  }
#line 7301 "src-generated/ugbc.tab.c"
    break;

  case 513: /* statement: CUP  */
#line 1882 "src/ugbc.y"
        {
      text_cmove_direct( _environment, 0, -1 );
  }
#line 7309 "src-generated/ugbc.tab.c"
    break;

  case 514: /* statement: CDOWN  */
#line 1885 "src/ugbc.y"
          {
      text_cmove_direct( _environment, 0, 1 );
  }
#line 7317 "src-generated/ugbc.tab.c"
    break;

  case 515: /* statement: CLEFT  */
#line 1888 "src/ugbc.y"
          {
      text_cmove_direct( _environment, -1, 0 );
  }
#line 7325 "src-generated/ugbc.tab.c"
    break;

  case 516: /* statement: CRIGHT  */
#line 1891 "src/ugbc.y"
           {
      text_cmove_direct( _environment, 1, 0 );
  }
#line 7333 "src-generated/ugbc.tab.c"
    break;

  case 517: /* statement: CLINE  */
#line 1894 "src/ugbc.y"
          {
      text_cline( _environment, NULL );
  }
#line 7341 "src-generated/ugbc.tab.c"
    break;

  case 518: /* statement: CLINE expr  */
#line 1897 "src/ugbc.y"
               {
      text_cline( _environment, (yyvsp[0].string) );
  }
#line 7349 "src-generated/ugbc.tab.c"
    break;

  case 519: /* statement: SET TAB expr  */
#line 1900 "src/ugbc.y"
                 {
      text_set_tab( _environment, (yyvsp[0].string) );
  }
#line 7357 "src-generated/ugbc.tab.c"
    break;

  case 520: /* statement: CENTER expr  */
#line 1903 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 7365 "src-generated/ugbc.tab.c"
    break;

  case 521: /* statement: CENTRE expr  */
#line 1906 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 7373 "src-generated/ugbc.tab.c"
    break;

  case 522: /* statement: CLS  */
#line 1909 "src/ugbc.y"
        {
      text_cls( _environment );
  }
#line 7381 "src-generated/ugbc.tab.c"
    break;

  case 523: /* statement: HOME  */
#line 1912 "src/ugbc.y"
         {
      text_home( _environment );
  }
#line 7389 "src-generated/ugbc.tab.c"
    break;

  case 524: /* statement: CLEAR KEY  */
#line 1915 "src/ugbc.y"
              {
      clear_key( _environment );
  }
#line 7397 "src-generated/ugbc.tab.c"
    break;

  case 525: /* statement: OP_INC Identifier  */
#line 1918 "src/ugbc.y"
                      {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 7405 "src-generated/ugbc.tab.c"
    break;

  case 526: /* statement: OP_DEC Identifier  */
#line 1921 "src/ugbc.y"
                      {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 7413 "src-generated/ugbc.tab.c"
    break;

  case 527: /* statement: RANDOMIZE  */
#line 1924 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 7421 "src-generated/ugbc.tab.c"
    break;

  case 528: /* statement: RANDOMIZE expr  */
#line 1927 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 7429 "src-generated/ugbc.tab.c"
    break;

  case 529: /* statement: IF expr THEN  */
#line 1930 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 7437 "src-generated/ugbc.tab.c"
    break;

  case 530: /* statement: ELSE  */
#line 1933 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 7445 "src-generated/ugbc.tab.c"
    break;

  case 531: /* statement: ELSE IF expr THEN  */
#line 1936 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 7453 "src-generated/ugbc.tab.c"
    break;

  case 532: /* statement: ENDIF  */
#line 1939 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 7461 "src-generated/ugbc.tab.c"
    break;

  case 533: /* statement: DO  */
#line 1942 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 7469 "src-generated/ugbc.tab.c"
    break;

  case 534: /* statement: LOOP  */
#line 1945 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 7477 "src-generated/ugbc.tab.c"
    break;

  case 535: /* $@15: %empty  */
#line 1948 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 7485 "src-generated/ugbc.tab.c"
    break;

  case 536: /* statement: WHILE $@15 expr  */
#line 1950 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 7493 "src-generated/ugbc.tab.c"
    break;

  case 537: /* statement: WEND  */
#line 1953 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 7501 "src-generated/ugbc.tab.c"
    break;

  case 538: /* statement: REPEAT  */
#line 1956 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 7509 "src-generated/ugbc.tab.c"
    break;

  case 539: /* statement: UNTIL expr  */
#line 1959 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 7517 "src-generated/ugbc.tab.c"
    break;

  case 540: /* statement: EXIT  */
#line 1962 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 7525 "src-generated/ugbc.tab.c"
    break;

  case 541: /* statement: EXIT PROC  */
#line 1965 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 7533 "src-generated/ugbc.tab.c"
    break;

  case 542: /* statement: POP PROC  */
#line 1968 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 7541 "src-generated/ugbc.tab.c"
    break;

  case 543: /* statement: EXIT IF expr  */
#line 1971 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 7549 "src-generated/ugbc.tab.c"
    break;

  case 544: /* statement: EXIT Integer  */
#line 1974 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 7557 "src-generated/ugbc.tab.c"
    break;

  case 545: /* statement: EXIT direct_integer  */
#line 1977 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 7565 "src-generated/ugbc.tab.c"
    break;

  case 546: /* statement: EXIT IF expr OP_COMMA Integer  */
#line 1980 "src/ugbc.y"
                                  {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 7573 "src-generated/ugbc.tab.c"
    break;

  case 547: /* statement: EXIT IF expr OP_COMMA direct_integer  */
#line 1983 "src/ugbc.y"
                                         {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 7581 "src-generated/ugbc.tab.c"
    break;

  case 548: /* statement: FOR Identifier OP_ASSIGN expr TO expr  */
#line 1986 "src/ugbc.y"
                                          {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 7589 "src-generated/ugbc.tab.c"
    break;

  case 549: /* statement: NEXT  */
#line 1989 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 7597 "src-generated/ugbc.tab.c"
    break;

  case 550: /* statement: PROCEDURE Identifier  */
#line 1992 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 7606 "src-generated/ugbc.tab.c"
    break;

  case 551: /* $@16: %empty  */
#line 1996 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 7614 "src-generated/ugbc.tab.c"
    break;

  case 552: /* statement: PROCEDURE Identifier $@16 OSP parameters CSP  */
#line 1998 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 7622 "src-generated/ugbc.tab.c"
    break;

  case 553: /* statement: SHARED parameters_expr  */
#line 2001 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 7630 "src-generated/ugbc.tab.c"
    break;

  case 554: /* statement: GLOBAL parameters_expr  */
#line 2004 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 7638 "src-generated/ugbc.tab.c"
    break;

  case 555: /* statement: END PROC  */
#line 2007 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 7646 "src-generated/ugbc.tab.c"
    break;

  case 556: /* statement: END PROC OSP expr CSP  */
#line 2010 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 7654 "src-generated/ugbc.tab.c"
    break;

  case 557: /* statement: FOR Identifier OP_ASSIGN expr TO expr STEP expr  */
#line 2013 "src/ugbc.y"
                                                    {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 7662 "src-generated/ugbc.tab.c"
    break;

  case 558: /* statement: Identifier " "  */
#line 2016 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 7671 "src-generated/ugbc.tab.c"
    break;

  case 559: /* statement: PROC Identifier  */
#line 2020 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 7680 "src-generated/ugbc.tab.c"
    break;

  case 560: /* statement: CALL Identifier  */
#line 2024 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 7689 "src-generated/ugbc.tab.c"
    break;

  case 561: /* $@17: %empty  */
#line 2028 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 7697 "src-generated/ugbc.tab.c"
    break;

  case 562: /* statement: Identifier OSP $@17 values CSP  */
#line 2030 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 7705 "src-generated/ugbc.tab.c"
    break;

  case 563: /* $@18: %empty  */
#line 2033 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 7713 "src-generated/ugbc.tab.c"
    break;

  case 564: /* statement: PROC Identifier OSP $@18 values CSP  */
#line 2035 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 7721 "src-generated/ugbc.tab.c"
    break;

  case 565: /* $@19: %empty  */
#line 2038 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 7729 "src-generated/ugbc.tab.c"
    break;

  case 566: /* statement: CALL Identifier OSP $@19 values CSP  */
#line 2040 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 7737 "src-generated/ugbc.tab.c"
    break;

  case 567: /* statement: PEN expr  */
#line 2043 "src/ugbc.y"
             {
      text_pen( _environment, (yyvsp[0].string) );
  }
#line 7745 "src-generated/ugbc.tab.c"
    break;

  case 568: /* statement: PAPER expr  */
#line 2046 "src/ugbc.y"
               {
      text_paper( _environment, (yyvsp[0].string) );
  }
#line 7753 "src-generated/ugbc.tab.c"
    break;

  case 569: /* statement: INVERSE ON  */
#line 2049 "src/ugbc.y"
               {
      CRITICAL_NOT_SUPPORTED("INVERSE");
  }
#line 7761 "src-generated/ugbc.tab.c"
    break;

  case 570: /* statement: INVERSE OFF  */
#line 2052 "src/ugbc.y"
                {
      CRITICAL_NOT_SUPPORTED("INVERSE");
  }
#line 7769 "src-generated/ugbc.tab.c"
    break;

  case 572: /* statement: Identifier OP_COLON  */
#line 2056 "src/ugbc.y"
                        {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 7777 "src-generated/ugbc.tab.c"
    break;

  case 573: /* statement: BEG GAMELOOP  */
#line 2059 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 7785 "src-generated/ugbc.tab.c"
    break;

  case 574: /* statement: END GAMELOOP  */
#line 2062 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 7793 "src-generated/ugbc.tab.c"
    break;

  case 575: /* statement: GRAPHIC  */
#line 2065 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 7801 "src-generated/ugbc.tab.c"
    break;

  case 576: /* statement: HALT  */
#line 2068 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 7809 "src-generated/ugbc.tab.c"
    break;

  case 577: /* statement: END  */
#line 2071 "src/ugbc.y"
        {
      end( _environment );
  }
#line 7817 "src-generated/ugbc.tab.c"
    break;

  case 582: /* statement: RETURN  */
#line 2078 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 7825 "src-generated/ugbc.tab.c"
    break;

  case 583: /* statement: RETURN expr  */
#line 2081 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 7833 "src-generated/ugbc.tab.c"
    break;

  case 584: /* statement: POP  */
#line 2084 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 7841 "src-generated/ugbc.tab.c"
    break;

  case 585: /* statement: DONE  */
#line 2087 "src/ugbc.y"
          {
      return 0;
  }
#line 7849 "src-generated/ugbc.tab.c"
    break;

  case 586: /* statement: LEFT OP expr OP_COMMA expr CP OP_ASSIGN expr  */
#line 2090 "src/ugbc.y"
                                                 {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 7857 "src-generated/ugbc.tab.c"
    break;

  case 587: /* statement: RIGHT OP expr OP_COMMA expr CP OP_ASSIGN expr  */
#line 2093 "src/ugbc.y"
                                                  {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 7865 "src-generated/ugbc.tab.c"
    break;

  case 588: /* statement: MID OP expr OP_COMMA expr CP OP_ASSIGN expr  */
#line 2096 "src/ugbc.y"
                                                {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 7873 "src-generated/ugbc.tab.c"
    break;

  case 589: /* statement: MID OP expr OP_COMMA expr OP_COMMA expr CP OP_ASSIGN expr  */
#line 2099 "src/ugbc.y"
                                                              {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 7881 "src-generated/ugbc.tab.c"
    break;

  case 591: /* statement: Identifier OP_ASSIGN expr  */
#line 2103 "src/ugbc.y"
                              {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 7895 "src-generated/ugbc.tab.c"
    break;

  case 592: /* statement: Identifier OP_DOLLAR OP_ASSIGN expr  */
#line 2112 "src/ugbc.y"
                                        {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 7909 "src-generated/ugbc.tab.c"
    break;

  case 593: /* $@20: %empty  */
#line 2121 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 7918 "src-generated/ugbc.tab.c"
    break;

  case 594: /* statement: Identifier $@20 OP indexes CP OP_ASSIGN expr  */
#line 2125 "src/ugbc.y"
                                   {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 7931 "src-generated/ugbc.tab.c"
    break;

  case 595: /* $@21: %empty  */
#line 2133 "src/ugbc.y"
                         {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 7940 "src-generated/ugbc.tab.c"
    break;

  case 596: /* statement: Identifier OP_DOLLAR $@21 OP indexes CP OP_ASSIGN expr  */
#line 2136 "src/ugbc.y"
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
#line 7959 "src-generated/ugbc.tab.c"
    break;

  case 597: /* $@22: %empty  */
#line 2150 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 7968 "src-generated/ugbc.tab.c"
    break;

  case 598: /* statement: Identifier $@22 datatype OP indexes CP OP_ASSIGN expr  */
#line 2153 "src/ugbc.y"
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
#line 7987 "src-generated/ugbc.tab.c"
    break;

  case 599: /* statement: DEBUG expr  */
#line 2167 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 7995 "src-generated/ugbc.tab.c"
    break;

  case 602: /* statements_no_linenumbers: statement  */
#line 2175 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 8001 "src-generated/ugbc.tab.c"
    break;

  case 603: /* $@23: %empty  */
#line 2176 "src/ugbc.y"
                         { ((Environment *)_environment)->yylineno = yylineno; }
#line 8007 "src-generated/ugbc.tab.c"
    break;

  case 605: /* $@24: %empty  */
#line 2180 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 8015 "src-generated/ugbc.tab.c"
    break;

  case 606: /* statements_with_linenumbers: Integer $@24 statements_no_linenumbers  */
#line 2182 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 8023 "src-generated/ugbc.tab.c"
    break;

  case 607: /* $@25: %empty  */
#line 2187 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 8031 "src-generated/ugbc.tab.c"
    break;

  case 613: /* $@26: %empty  */
#line 2197 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 8037 "src-generated/ugbc.tab.c"
    break;


#line 8041 "src-generated/ugbc.tab.c"

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

#line 2199 "src/ugbc.y"


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

