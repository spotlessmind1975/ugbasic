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
  YYSYMBOL_RASTER = 22,                    /* RASTER  */
  YYSYMBOL_DONE = 23,                      /* DONE  */
  YYSYMBOL_AT = 24,                        /* AT  */
  YYSYMBOL_COLOR = 25,                     /* COLOR  */
  YYSYMBOL_BORDER = 26,                    /* BORDER  */
  YYSYMBOL_WAIT = 27,                      /* WAIT  */
  YYSYMBOL_NEXT = 28,                      /* NEXT  */
  YYSYMBOL_WITH = 29,                      /* WITH  */
  YYSYMBOL_BANK = 30,                      /* BANK  */
  YYSYMBOL_SPRITE = 31,                    /* SPRITE  */
  YYSYMBOL_DATA = 32,                      /* DATA  */
  YYSYMBOL_FROM = 33,                      /* FROM  */
  YYSYMBOL_OP = 34,                        /* OP  */
  YYSYMBOL_CP = 35,                        /* CP  */
  YYSYMBOL_ENABLE = 36,                    /* ENABLE  */
  YYSYMBOL_DISABLE = 37,                   /* DISABLE  */
  YYSYMBOL_HALT = 38,                      /* HALT  */
  YYSYMBOL_ECM = 39,                       /* ECM  */
  YYSYMBOL_BITMAP = 40,                    /* BITMAP  */
  YYSYMBOL_SCREEN = 41,                    /* SCREEN  */
  YYSYMBOL_ON = 42,                        /* ON  */
  YYSYMBOL_OFF = 43,                       /* OFF  */
  YYSYMBOL_ROWS = 44,                      /* ROWS  */
  YYSYMBOL_VERTICAL = 45,                  /* VERTICAL  */
  YYSYMBOL_SCROLL = 46,                    /* SCROLL  */
  YYSYMBOL_VAR = 47,                       /* VAR  */
  YYSYMBOL_AS = 48,                        /* AS  */
  YYSYMBOL_TEMPORARY = 49,                 /* TEMPORARY  */
  YYSYMBOL_XPEN = 50,                      /* XPEN  */
  YYSYMBOL_YPEN = 51,                      /* YPEN  */
  YYSYMBOL_PEEK = 52,                      /* PEEK  */
  YYSYMBOL_GOTO = 53,                      /* GOTO  */
  YYSYMBOL_HORIZONTAL = 54,                /* HORIZONTAL  */
  YYSYMBOL_MCM = 55,                       /* MCM  */
  YYSYMBOL_COMPRESS = 56,                  /* COMPRESS  */
  YYSYMBOL_EXPAND = 57,                    /* EXPAND  */
  YYSYMBOL_LOOP = 58,                      /* LOOP  */
  YYSYMBOL_REPEAT = 59,                    /* REPEAT  */
  YYSYMBOL_WHILE = 60,                     /* WHILE  */
  YYSYMBOL_TEXT = 61,                      /* TEXT  */
  YYSYMBOL_TILES = 62,                     /* TILES  */
  YYSYMBOL_COLORMAP = 63,                  /* COLORMAP  */
  YYSYMBOL_SELECT = 64,                    /* SELECT  */
  YYSYMBOL_MONOCOLOR = 65,                 /* MONOCOLOR  */
  YYSYMBOL_MULTICOLOR = 66,                /* MULTICOLOR  */
  YYSYMBOL_COLLISION = 67,                 /* COLLISION  */
  YYSYMBOL_IF = 68,                        /* IF  */
  YYSYMBOL_THEN = 69,                      /* THEN  */
  YYSYMBOL_HIT = 70,                       /* HIT  */
  YYSYMBOL_BACKGROUND = 71,                /* BACKGROUND  */
  YYSYMBOL_TO = 72,                        /* TO  */
  YYSYMBOL_RANDOM = 73,                    /* RANDOM  */
  YYSYMBOL_BYTE = 74,                      /* BYTE  */
  YYSYMBOL_WORD = 75,                      /* WORD  */
  YYSYMBOL_POSITION = 76,                  /* POSITION  */
  YYSYMBOL_CODE = 77,                      /* CODE  */
  YYSYMBOL_VARIABLES = 78,                 /* VARIABLES  */
  YYSYMBOL_MS = 79,                        /* MS  */
  YYSYMBOL_CYCLES = 80,                    /* CYCLES  */
  YYSYMBOL_S = 81,                         /* S  */
  YYSYMBOL_HASH = 82,                      /* HASH  */
  YYSYMBOL_WIDTH = 83,                     /* WIDTH  */
  YYSYMBOL_HEIGHT = 84,                    /* HEIGHT  */
  YYSYMBOL_DWORD = 85,                     /* DWORD  */
  YYSYMBOL_PEN = 86,                       /* PEN  */
  YYSYMBOL_CLEAR = 87,                     /* CLEAR  */
  YYSYMBOL_BEG = 88,                       /* BEG  */
  YYSYMBOL_END = 89,                       /* END  */
  YYSYMBOL_GAMELOOP = 90,                  /* GAMELOOP  */
  YYSYMBOL_ENDIF = 91,                     /* ENDIF  */
  YYSYMBOL_UP = 92,                        /* UP  */
  YYSYMBOL_DOWN = 93,                      /* DOWN  */
  YYSYMBOL_LEFT = 94,                      /* LEFT  */
  YYSYMBOL_RIGHT = 95,                     /* RIGHT  */
  YYSYMBOL_DEBUG = 96,                     /* DEBUG  */
  YYSYMBOL_AND = 97,                       /* AND  */
  YYSYMBOL_RANDOMIZE = 98,                 /* RANDOMIZE  */
  YYSYMBOL_GRAPHIC = 99,                   /* GRAPHIC  */
  YYSYMBOL_TEXTMAP = 100,                  /* TEXTMAP  */
  YYSYMBOL_POINT = 101,                    /* POINT  */
  YYSYMBOL_GOSUB = 102,                    /* GOSUB  */
  YYSYMBOL_RETURN = 103,                   /* RETURN  */
  YYSYMBOL_POP = 104,                      /* POP  */
  YYSYMBOL_OR = 105,                       /* OR  */
  YYSYMBOL_ELSE = 106,                     /* ELSE  */
  YYSYMBOL_NOT = 107,                      /* NOT  */
  YYSYMBOL_TRUE = 108,                     /* TRUE  */
  YYSYMBOL_FALSE = 109,                    /* FALSE  */
  YYSYMBOL_DO = 110,                       /* DO  */
  YYSYMBOL_EXIT = 111,                     /* EXIT  */
  YYSYMBOL_WEND = 112,                     /* WEND  */
  YYSYMBOL_UNTIL = 113,                    /* UNTIL  */
  YYSYMBOL_FOR = 114,                      /* FOR  */
  YYSYMBOL_STEP = 115,                     /* STEP  */
  YYSYMBOL_EVERY = 116,                    /* EVERY  */
  YYSYMBOL_MID = 117,                      /* MID  */
  YYSYMBOL_INSTR = 118,                    /* INSTR  */
  YYSYMBOL_UPPER = 119,                    /* UPPER  */
  YYSYMBOL_LOWER = 120,                    /* LOWER  */
  YYSYMBOL_STR = 121,                      /* STR  */
  YYSYMBOL_VAL = 122,                      /* VAL  */
  YYSYMBOL_STRING = 123,                   /* STRING  */
  YYSYMBOL_SPACE = 124,                    /* SPACE  */
  YYSYMBOL_FLIP = 125,                     /* FLIP  */
  YYSYMBOL_CHR = 126,                      /* CHR  */
  YYSYMBOL_ASC = 127,                      /* ASC  */
  YYSYMBOL_LEN = 128,                      /* LEN  */
  YYSYMBOL_POW = 129,                      /* POW  */
  YYSYMBOL_MOD = 130,                      /* MOD  */
  YYSYMBOL_ADD = 131,                      /* ADD  */
  YYSYMBOL_MIN = 132,                      /* MIN  */
  YYSYMBOL_MAX = 133,                      /* MAX  */
  YYSYMBOL_SGN = 134,                      /* SGN  */
  YYSYMBOL_SIGNED = 135,                   /* SIGNED  */
  YYSYMBOL_ABS = 136,                      /* ABS  */
  YYSYMBOL_RND = 137,                      /* RND  */
  YYSYMBOL_COLORS = 138,                   /* COLORS  */
  YYSYMBOL_INK = 139,                      /* INK  */
  YYSYMBOL_TIMER = 140,                    /* TIMER  */
  YYSYMBOL_POWERING = 141,                 /* POWERING  */
  YYSYMBOL_DIM = 142,                      /* DIM  */
  YYSYMBOL_ADDRESS = 143,                  /* ADDRESS  */
  YYSYMBOL_PROC = 144,                     /* PROC  */
  YYSYMBOL_PROCEDURE = 145,                /* PROCEDURE  */
  YYSYMBOL_CALL = 146,                     /* CALL  */
  YYSYMBOL_OSP = 147,                      /* OSP  */
  YYSYMBOL_CSP = 148,                      /* CSP  */
  YYSYMBOL_SHARED = 149,                   /* SHARED  */
  YYSYMBOL_MILLISECOND = 150,              /* MILLISECOND  */
  YYSYMBOL_MILLISECONDS = 151,             /* MILLISECONDS  */
  YYSYMBOL_TICKS = 152,                    /* TICKS  */
  YYSYMBOL_GLOBAL = 153,                   /* GLOBAL  */
  YYSYMBOL_PARAM = 154,                    /* PARAM  */
  YYSYMBOL_PRINT = 155,                    /* PRINT  */
  YYSYMBOL_DEFAULT = 156,                  /* DEFAULT  */
  YYSYMBOL_SPECIFIC = 157,                 /* SPECIFIC  */
  YYSYMBOL_ANSI = 158,                     /* ANSI  */
  YYSYMBOL_USE = 159,                      /* USE  */
  YYSYMBOL_PAPER = 160,                    /* PAPER  */
  YYSYMBOL_INVERSE = 161,                  /* INVERSE  */
  YYSYMBOL_REPLACE = 162,                  /* REPLACE  */
  YYSYMBOL_XOR = 163,                      /* XOR  */
  YYSYMBOL_IGNORE = 164,                   /* IGNORE  */
  YYSYMBOL_NORMAL = 165,                   /* NORMAL  */
  YYSYMBOL_WRITING = 166,                  /* WRITING  */
  YYSYMBOL_ONLY = 167,                     /* ONLY  */
  YYSYMBOL_LOCATE = 168,                   /* LOCATE  */
  YYSYMBOL_CLS = 169,                      /* CLS  */
  YYSYMBOL_HOME = 170,                     /* HOME  */
  YYSYMBOL_CMOVE = 171,                    /* CMOVE  */
  YYSYMBOL_CENTER = 172,                   /* CENTER  */
  YYSYMBOL_CENTRE = 173,                   /* CENTRE  */
  YYSYMBOL_TAB = 174,                      /* TAB  */
  YYSYMBOL_SET = 175,                      /* SET  */
  YYSYMBOL_CUP = 176,                      /* CUP  */
  YYSYMBOL_CDOWN = 177,                    /* CDOWN  */
  YYSYMBOL_CLEFT = 178,                    /* CLEFT  */
  YYSYMBOL_CRIGHT = 179,                   /* CRIGHT  */
  YYSYMBOL_CLINE = 180,                    /* CLINE  */
  YYSYMBOL_XCURS = 181,                    /* XCURS  */
  YYSYMBOL_YCURS = 182,                    /* YCURS  */
  YYSYMBOL_MEMORIZE = 183,                 /* MEMORIZE  */
  YYSYMBOL_REMEMBER = 184,                 /* REMEMBER  */
  YYSYMBOL_HSCROLL = 185,                  /* HSCROLL  */
  YYSYMBOL_VSCROLL = 186,                  /* VSCROLL  */
  YYSYMBOL_BLACK = 187,                    /* BLACK  */
  YYSYMBOL_WHITE = 188,                    /* WHITE  */
  YYSYMBOL_RED = 189,                      /* RED  */
  YYSYMBOL_CYAN = 190,                     /* CYAN  */
  YYSYMBOL_VIOLET = 191,                   /* VIOLET  */
  YYSYMBOL_GREEN = 192,                    /* GREEN  */
  YYSYMBOL_BLUE = 193,                     /* BLUE  */
  YYSYMBOL_YELLOW = 194,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 195,                   /* ORANGE  */
  YYSYMBOL_BROWN = 196,                    /* BROWN  */
  YYSYMBOL_LIGHT = 197,                    /* LIGHT  */
  YYSYMBOL_DARK = 198,                     /* DARK  */
  YYSYMBOL_GREY = 199,                     /* GREY  */
  YYSYMBOL_GRAY = 200,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 201,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 202,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 203,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 204,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 205,                /* TURQUOISE  */
  YYSYMBOL_TAN = 206,                      /* TAN  */
  YYSYMBOL_PINK = 207,                     /* PINK  */
  YYSYMBOL_PEACH = 208,                    /* PEACH  */
  YYSYMBOL_OLIVE = 209,                    /* OLIVE  */
  YYSYMBOL_Identifier = 210,               /* Identifier  */
  YYSYMBOL_String = 211,                   /* String  */
  YYSYMBOL_Integer = 212,                  /* Integer  */
  YYSYMBOL_213_ = 213,                     /* " "  */
  YYSYMBOL_YYACCEPT = 214,                 /* $accept  */
  YYSYMBOL_expr = 215,                     /* expr  */
  YYSYMBOL_expr_math = 216,                /* expr_math  */
  YYSYMBOL_term = 217,                     /* term  */
  YYSYMBOL_modula = 218,                   /* modula  */
  YYSYMBOL_factor = 219,                   /* factor  */
  YYSYMBOL_direct_integer = 220,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 221, /* random_definition_simple  */
  YYSYMBOL_random_definition = 222,        /* random_definition  */
  YYSYMBOL_color_enumeration = 223,        /* color_enumeration  */
  YYSYMBOL_exponential = 224,              /* exponential  */
  YYSYMBOL_225_1 = 225,                    /* $@1  */
  YYSYMBOL_226_2 = 226,                    /* $@2  */
  YYSYMBOL_227_3 = 227,                    /* $@3  */
  YYSYMBOL_position = 228,                 /* position  */
  YYSYMBOL_bank_definition_simple = 229,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 230, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 231,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 232, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 233, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 234,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 235, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 236, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 237,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 238,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 239, /* color_definition_expression  */
  YYSYMBOL_color_definition = 240,         /* color_definition  */
  YYSYMBOL_milliseconds = 241,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 242,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 243, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 244,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 245, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 246, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 247,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 248, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 249, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 250,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 251, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 252, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 253,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 254,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 255, /* text_definition_expression  */
  YYSYMBOL_text_definition = 256,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 257,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 258, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 259,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 260, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 261, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 262,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 263, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 264, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 265,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 266,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 267,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 268,         /* gosub_definition  */
  YYSYMBOL_var_definition = 269,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 270,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 271, /* point_definition_expression  */
  YYSYMBOL_point_definition = 272,         /* point_definition  */
  YYSYMBOL_ink_definition = 273,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 274,       /* on_goto_definition  */
  YYSYMBOL_275_4 = 275,                    /* $@4  */
  YYSYMBOL_on_gosub_definition = 276,      /* on_gosub_definition  */
  YYSYMBOL_277_5 = 277,                    /* $@5  */
  YYSYMBOL_on_proc_definition = 278,       /* on_proc_definition  */
  YYSYMBOL_279_6 = 279,                    /* $@6  */
  YYSYMBOL_on_definition = 280,            /* on_definition  */
  YYSYMBOL_281_7 = 281,                    /* $@7  */
  YYSYMBOL_282_8 = 282,                    /* $@8  */
  YYSYMBOL_283_9 = 283,                    /* $@9  */
  YYSYMBOL_every_definition = 284,         /* every_definition  */
  YYSYMBOL_add_definition = 285,           /* add_definition  */
  YYSYMBOL_dimensions = 286,               /* dimensions  */
  YYSYMBOL_datatype = 287,                 /* datatype  */
  YYSYMBOL_dim_definition = 288,           /* dim_definition  */
  YYSYMBOL_289_10 = 289,                   /* $@10  */
  YYSYMBOL_290_11 = 290,                   /* $@11  */
  YYSYMBOL_291_12 = 291,                   /* $@12  */
  YYSYMBOL_dim_definitions = 292,          /* dim_definitions  */
  YYSYMBOL_indexes = 293,                  /* indexes  */
  YYSYMBOL_parameters = 294,               /* parameters  */
  YYSYMBOL_parameters_expr = 295,          /* parameters_expr  */
  YYSYMBOL_values = 296,                   /* values  */
  YYSYMBOL_print_definition = 297,         /* print_definition  */
  YYSYMBOL_298_13 = 298,                   /* $@13  */
  YYSYMBOL_299_14 = 299,                   /* $@14  */
  YYSYMBOL_use_definition = 300,           /* use_definition  */
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
#define YYLAST   3216

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  214
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  111
/* YYNRULES -- Number of rules.  */
#define YYNRULES  496
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  951

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   468


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
     205,   206,   207,   208,   209,   210,   211,   212,   213
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    76,    76,    77,    81,    85,    88,    91,    94,    97,
     100,   103,   109,   110,   113,   120,   121,   125,   126,   130,
     137,   138,   142,   149,   154,   157,   160,   163,   166,   169,
     172,   177,   182,   186,   190,   194,   198,   202,   206,   210,
     214,   218,   222,   226,   230,   234,   238,   242,   246,   250,
     254,   258,   262,   266,   270,   274,   278,   282,   286,   292,
     292,   303,   303,   314,   317,   320,   329,   333,   340,   344,
     348,   352,   356,   360,   364,   368,   372,   375,   378,   381,
     384,   387,   390,   393,   396,   399,   402,   405,   408,   411,
     414,   417,   420,   423,   426,   429,   432,   435,   438,   441,
     444,   447,   450,   453,   456,   459,   462,   465,   468,   468,
     474,   477,   480,   484,   488,   492,   496,   500,   504,   508,
     512,   516,   519,   522,   525,   528,   531,   534,   537,   540,
     543,   546,   549,   552,   555,   558,   563,   563,   566,   569,
     572,   575,   578,   581,   585,   588,   591,   594,   598,   601,
     604,   607,   611,   614,   617,   620,   626,   629,   632,   635,
     638,   643,   644,   647,   650,   655,   658,   663,   664,   667,
     670,   675,   678,   683,   684,   687,   690,   693,   698,   701,
     704,   709,   710,   713,   714,   715,   718,   721,   724,   729,
     732,   735,   741,   742,   745,   748,   751,   754,   757,   760,
     763,   766,   769,   772,   775,   778,   781,   784,   787,   792,
     795,   798,   801,   804,   807,   810,   813,   816,   819,   822,
     825,   828,   831,   834,   839,   840,   843,   846,   849,   852,
     855,   861,   864,   870,   871,   874,   879,   884,   885,   888,
     891,   896,   899,   904,   905,   908,   913,   918,   919,   922,
     925,   928,   933,   936,   942,   943,   946,   949,   952,   955,
     958,   963,   966,   969,   974,   975,   977,   978,   981,   984,
     987,   992,   999,  1002,  1008,  1011,  1017,  1020,  1026,  1031,
    1032,  1035,  1040,  1044,  1044,  1049,  1053,  1053,  1058,  1062,
    1062,  1067,  1067,  1070,  1070,  1073,  1073,  1078,  1081,  1084,
    1089,  1092,  1098,  1102,  1109,  1112,  1115,  1118,  1121,  1124,
    1127,  1130,  1133,  1136,  1141,  1141,  1149,  1149,  1157,  1157,
    1168,  1169,  1173,  1177,  1184,  1189,  1194,  1199,  1204,  1209,
    1217,  1222,  1227,  1232,  1237,  1242,  1247,  1251,  1258,  1262,
    1269,  1272,  1276,  1279,  1279,  1283,  1283,  1289,  1292,  1298,
    1302,  1306,  1310,  1314,  1321,  1325,  1329,  1333,  1337,  1344,
    1350,  1353,  1356,  1362,  1365,  1368,  1374,  1377,  1380,  1383,
    1389,  1392,  1398,  1399,  1400,  1401,  1402,  1403,  1404,  1405,
    1406,  1407,  1408,  1409,  1410,  1411,  1412,  1413,  1414,  1415,
    1416,  1419,  1422,  1423,  1424,  1425,  1428,  1431,  1434,  1437,
    1440,  1443,  1446,  1449,  1452,  1455,  1458,  1461,  1464,  1467,
    1470,  1473,  1476,  1479,  1482,  1485,  1488,  1488,  1493,  1496,
    1499,  1502,  1505,  1508,  1511,  1514,  1517,  1520,  1523,  1526,
    1529,  1532,  1536,  1536,  1541,  1544,  1547,  1550,  1553,  1556,
    1560,  1564,  1568,  1568,  1573,  1573,  1578,  1578,  1583,  1586,
    1589,  1592,  1595,  1596,  1599,  1602,  1605,  1608,  1611,  1614,
    1615,  1616,  1617,  1618,  1621,  1624,  1627,  1630,  1633,  1636,
    1639,  1642,  1643,  1644,  1653,  1662,  1662,  1674,  1674,  1691,
    1691,  1708,  1711,  1712,  1716,  1717,  1717,  1721,  1721,  1728,
    1728,  1731,  1732,  1733,  1734,  1738,  1738
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
  "DOLLAR", "DIVISION", "RASTER", "DONE", "AT", "COLOR", "BORDER", "WAIT",
  "NEXT", "WITH", "BANK", "SPRITE", "DATA", "FROM", "OP", "CP", "ENABLE",
  "DISABLE", "HALT", "ECM", "BITMAP", "SCREEN", "ON", "OFF", "ROWS",
  "VERTICAL", "SCROLL", "VAR", "AS", "TEMPORARY", "XPEN", "YPEN", "PEEK",
  "GOTO", "HORIZONTAL", "MCM", "COMPRESS", "EXPAND", "LOOP", "REPEAT",
  "WHILE", "TEXT", "TILES", "COLORMAP", "SELECT", "MONOCOLOR",
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
     465,   466,   467,   468
};
#endif

#define YYPACT_NINF (-819)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-476)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -819,    54,   899,  -819,  -819,  -123,  -120,   -14,  -819,    34,
    2227,    85,    18,  2227,  -819,    67,   215,  2622,   -80,    42,
    -819,  -819,  -819,  1845,   125,    21,  2622,  2622,    75,   -47,
    -819,   123,   134,  2622,  2622,  -819,   171,   193,    69,  2622,
      36,   175,  -819,   -56,  -819,  2622,    43,  2036,   239,    76,
    2622,    79,    98,   104,   108,   -20,   -20,  2622,    48,  2622,
     183,   -27,  1257,  -819,  -819,  1463,  2622,  2622,    90,  -819,
    -819,  -819,  -819,  2622,  -819,  -819,    52,   208,     5,  -819,
     289,   294,   302,  -819,  -819,  -819,  2227,   296,  -819,  -819,
    -819,  2227,  2227,  2227,  -819,  -819,  -819,   110,   306,  1654,
    -819,  -819,   295,   297,   298,   109,   118,  -819,  -819,    -6,
     300,   314,  2622,  -819,  -819,   315,   316,   317,   318,   321,
     341,   342,   343,   344,   345,   346,   348,   350,   353,   354,
     355,   356,  -819,  -819,   357,   133,   -42,    10,   308,   363,
     372,   373,   375,   376,   377,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,   144,  -819,  -819,    73,  -119,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,   206,    12,
    -819,  -819,   -11,   230,   269,   181,   272,    -7,  -819,  -819,
    -819,  -819,  -819,    -9,   320,    -3,    -2,     3,     4,   380,
    -819,  -819,  -819,   231,   349,  -819,  -819,  -819,  2227,  -819,
    -819,   371,  -819,  -819,  -819,  -819,  -819,  2227,   361,   362,
    -819,  -819,  -819,   -17,  -819,    96,  -819,  -819,  -819,  -819,
    -819,  2622,  2431,  -819,  -819,   402,  -819,  -819,  -819,  2227,
    -819,  -819,  -819,  2227,   381,  -819,  -819,  -819,   347,  -819,
    -819,  -819,   264,  2622,  2622,  -819,  -819,  2227,  -819,  -819,
    -819,   378,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    2622,  2622,  -819,  -819,  -819,  -819,   400,  -819,  -819,   266,
    -819,  2622,   412,  -819,  -819,  -819,    39,   413,  -819,   276,
     277,   279,   151,   414,  -819,  -819,   285,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,   420,
    -819,  2622,   421,  -819,  2622,   422,  -819,  -819,  -819,  2622,
    -819,   141,  -819,  -819,  -819,   190,  -819,  -819,  -819,  2622,
     417,  -819,  -819,   397,    46,  1077,  -819,   899,   899,   403,
     407,  2227,  -819,  -819,   365,   367,   368,   369,  -819,   408,
     409,   410,   411,   415,   416,   135,   418,  2227,  2227,  2227,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
     423,  -819,  -819,  2622,  2622,  -819,  2622,  2622,  2622,  2622,
    2622,  2622,  2622,  2622,  2622,  2622,  2622,  2622,  2622,  2622,
    2622,  2622,  2622,  2813,   424,   233,  -819,  -819,   425,  -819,
    -819,   426,   427,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,   428,  -819,   430,  -819,
    -819,  -819,  -819,  -819,  -819,  2813,  2813,  2813,  2813,  2813,
    2813,  2813,  2813,  2813,  2813,  2813,  2813,  2813,  3004,  -819,
    -819,  -819,  2227,   431,  -819,  -819,  -819,   399,   320,   432,
     320,   445,   320,   446,   320,   447,   320,  -819,  2622,   419,
    -819,  -819,   244,   246,    30,    32,  -819,  -819,  -819,   438,
     320,   440,  -819,  -819,   248,   254,    88,   119,  -819,  -819,
     442,  -819,  -819,  2227,  -819,  -819,  2227,  2227,  -819,  -819,
    -819,   406,   267,  -819,   467,  2622,  -819,  -819,  -819,  -819,
    2227,  -819,  2622,   471,   472,  -819,  -819,  2227,   385,   474,
    2622,   382,   476,  2622,  -819,  -819,  -819,  -819,  -819,  -819,
     155,  -819,  -819,   451,   429,    79,  -819,   339,  -819,   -20,
     481,    46,   -20,   271,   274,   -48,  -819,  2622,  -819,  2622,
    -819,  -819,  -819,  -819,  -819,   899,  -819,  2622,   455,  2622,
    2622,   457,    28,  -819,  1077,  -819,  -819,   282,   284,  -819,
    -819,  2622,   320,  2622,   320,  2622,   283,   286,   287,   288,
     290,   461,   462,   466,  -819,   468,   469,   470,   473,   475,
     477,  2622,   499,   500,   502,   504,   478,   479,   480,   485,
     509,   486,   487,   488,   490,   496,   526,   527,   501,   503,
     505,    26,   325,   507,  2622,  2622,  2622,   510,  2622,  2622,
     269,   269,   304,   304,   304,   304,   304,   304,   304,   304,
     181,   272,   272,  -819,   508,   518,  2227,   138,  -819,   320,
    -819,   320,  -819,   320,  -819,   320,    71,  -819,  2622,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  2622,  -819,   320,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,   320,  -819,
    -819,  -819,  -819,  -819,  -819,   329,   338,   358,   359,   536,
    2622,   544,   511,   512,   404,  2622,  2622,   548,   549,  -819,
     -51,   492,   360,  2622,   550,  -819,  -819,  -819,   524,   366,
     531,  -819,  2622,   364,  2622,  -819,   -20,   553,  -819,  2622,
    2622,   405,   433,  -819,  -819,  -819,  -819,  -819,  -819,  2622,
     559,   434,   560,   538,  2622,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,   564,  -819,  -819,  -819,  -819,  -819,   379,   383,
     384,  -819,  -819,  -819,  -819,  -819,  -819,   540,  2622,  2622,
    2622,  2622,  -819,  -819,  -819,  -819,  2622,  -819,  -819,  -819,
    -819,  -819,  2622,  2622,  -819,  -819,  -819,  3004,   542,  -819,
     545,   572,   574,  2622,   439,   554,   387,   388,  -819,  -819,
    -819,  -819,  -819,  -819,   561,  -819,   563,  -819,   390,   154,
    -819,   586,  -819,   587,   592,  -819,   595,  -819,   596,  -819,
     591,  2227,   598,  2622,  2622,   320,  -819,   573,   575,  2622,
     320,  -819,  -819,  2622,  -819,    44,  2622,   366,   600,   576,
     366,   464,   156,   465,   482,  -819,   -20,  -819,  -819,  -819,
    -819,   579,  2622,  -819,  2622,   602,   581,  2622,  -819,  -819,
    -819,  -819,   582,   584,    91,   116,   585,   588,   589,   590,
    -819,  -819,  2622,  2622,   593,  -819,  -819,  -819,  -819,   398,
     435,  -819,   597,  -819,   604,  -819,  2622,   320,   614,   615,
     622,  2622,  -819,  -819,  2622,  -819,  -819,  -819,   618,   621,
     601,   606,   520,  2622,   624,   567,   607,   366,  -819,   608,
    -819,   364,   637,    46,  -819,  -819,  -819,   632,  -819,  -819,
    2622,   634,   613,  -819,  -819,  2622,  -819,  2622,  -819,  -819,
    -819,  -819,  -819,   616,   617,  -819,  -819,  -819,   443,   448,
     623,   625,   329,   338,   358,  -819,  -819,  2622,  2622,  -819,
    -819,  2622,   626,  2622,  2622,  -819,  -819,  -819,  -819,   364,
     642,  2622,  -819,  2622,  -819,   627,   629,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,   640,
    -819,  -819,  -819,   364,  -819,  -819,  -819,  -819,  2622,  -819,
    -819
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     495,     0,   483,     1,   482,     0,     0,     0,   466,     0,
       0,   430,     0,     0,   457,     0,     0,     0,   266,     0,
     415,   419,   416,     0,     0,     0,     0,     0,     0,   458,
     413,     0,     0,     0,   408,   456,     0,     0,     0,   463,
     465,   411,   414,   421,   418,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   404,   405,     0,     0,     0,     0,   395,
     396,   397,   398,   399,   390,   391,     0,     0,   479,   487,
     484,   491,   493,   496,   406,   407,     0,     0,   167,   168,
     373,     0,     0,     0,   181,   182,   375,     0,     0,     0,
      79,    80,     0,     0,     0,     0,     0,   121,   122,     0,
       0,     0,     0,   112,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134,   135,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,    44,
      49,    50,    51,    52,    53,    54,    57,    58,     0,    63,
      67,    65,     0,     2,    12,    15,    17,     0,    76,    20,
     192,   193,   376,     0,     0,     0,     0,     0,     0,     0,
     161,   162,   372,     0,     0,   224,   225,   377,     0,   227,
     228,   229,   233,   234,   378,   256,   257,     0,     0,     0,
     264,   265,   383,     0,   459,     0,   276,   386,   272,   273,
     460,     0,     0,   239,   240,     0,   243,   244,   380,     0,
     247,   248,   381,     0,   250,   254,   255,   382,     0,   448,
     454,   455,   436,     0,     0,   481,   409,     0,   237,   238,
     379,     0,   279,   280,   384,   274,   275,   461,   464,   423,
       0,     0,   422,   425,   426,   420,     0,   298,   299,     0,
     462,     0,     0,   387,   281,   385,   314,   320,   471,   440,
     431,   441,   330,   336,   434,   435,   340,   388,   348,   347,
     472,   449,   450,   451,   352,   350,   349,   351,   353,     0,
     452,     0,     0,   389,     0,     0,   394,   402,   403,     0,
     400,     0,   366,   368,   392,     0,   393,   489,   453,     0,
     477,   442,   439,     0,     0,   483,   485,   483,   483,     0,
       0,     0,   178,   175,     0,     0,     0,     0,    66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      28,    24,    25,    27,    29,    30,    26,    31,   101,    23,
       0,   115,   116,     0,     0,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   117,   120,     0,   118,
     119,     0,     0,   133,   127,   128,   129,   130,    55,    42,
      45,    46,    47,    48,    43,    56,    64,   108,     0,   183,
     189,   184,   185,   190,   191,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   186,
     187,   188,     0,     0,   173,   174,   374,   138,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,     0,     0,
     214,   215,     0,     0,     0,     0,   211,   210,   136,     0,
       0,     0,   199,   200,     0,     0,     0,     0,   196,   195,
       0,   231,   226,     0,   261,   258,     0,     0,   291,   295,
     293,     0,     0,   417,     0,     0,   246,   245,   252,   249,
       0,   410,     0,     0,     0,   236,   235,     0,     0,   424,
       0,     0,     0,     0,   312,   304,   306,   311,   308,   313,
       0,   310,   318,     0,     0,     0,   444,     0,   446,     0,
     331,     0,     0,   345,   343,     0,   360,   361,   363,   364,
     401,   367,   369,   370,   371,   483,   473,     0,     0,     0,
       0,     0,   479,   488,   483,   492,   494,     0,     0,   165,
     163,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,    14,     5,     7,     8,     9,    10,     6,     3,     4,
      16,    18,    19,    21,     0,     0,     0,     0,   143,     0,
     155,     0,   147,     0,   151,     0,   139,   212,     0,   219,
     218,   223,   222,   217,   221,   216,   220,     0,   197,     0,
     204,   203,   208,   207,   202,   206,   201,   205,     0,   232,
     230,   262,   259,   263,   260,     0,     0,     0,     0,   267,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   412,
       0,     0,     0,     0,   300,   305,   307,   309,     0,     0,
       0,   321,     0,     0,     0,   333,     0,   332,   337,     0,
       0,   357,   355,   354,   359,   362,   365,   490,   474,     0,
     338,     0,   322,     0,     0,   486,   166,   164,   180,   177,
     179,   176,     0,    75,    68,    70,    74,    72,     0,     0,
       0,    78,    77,    82,    81,    84,    83,     0,     0,     0,
       0,     0,    91,    92,    93,   100,     0,    94,    95,    96,
      97,    98,     0,     0,   110,   111,   102,     0,     0,   106,
       0,     0,     0,     0,     0,     0,     0,     0,   171,   169,
     140,   153,   145,   148,   142,   154,   146,   150,     0,     0,
     209,     0,   194,     0,   282,   292,   285,   296,   288,   294,
     268,     0,     0,     0,     0,     0,   437,     0,     0,     0,
       0,   427,   428,     0,   297,     0,     0,     0,   302,     0,
       0,     0,   324,     0,     0,   334,     0,   346,   344,   358,
     356,     0,     0,   443,     0,     0,     0,     0,    69,    71,
      73,   124,     0,     0,     0,     0,     0,     0,     0,     0,
     107,   125,     0,     0,     0,   109,    60,   172,   170,     0,
       0,   156,   141,   152,   144,   149,     0,     0,     0,     0,
       0,     0,   270,   269,     0,   242,   253,   251,     0,     0,
       0,     0,   429,     0,     0,     0,     0,     0,   315,     0,
     445,     0,   325,     0,   433,   447,   335,     0,   339,   323,
       0,     0,     0,    85,    86,     0,    87,     0,    89,    99,
     105,   104,    22,     0,     0,    62,   158,   160,     0,     0,
       0,     0,     0,     0,     0,   271,   241,     0,     0,   278,
     277,     0,     0,     0,     0,   319,   303,   317,   327,     0,
     326,     0,   476,     0,   131,     0,     0,   132,   126,   157,
     159,   213,   198,   284,   287,   290,   467,   468,   438,     0,
     469,   301,   328,     0,   478,   480,    88,    90,     0,   329,
     470
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -819,   -10,   -77,   -99,   232,  -317,    86,  -819,  -819,  -819,
    -424,  -819,  -819,  -819,   483,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,   489,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -237,  -819,  -236,  -819,  -235,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -739,  -323,  -819,  -819,  -819,  -819,   153,  -593,
    -818,   -54,  -590,  -365,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -320,  -819,  -819,  -819,  -308,  -819,  -819,
    -819
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   702,   173,   174,   175,   176,   177,   357,   358,   178,
     179,   408,   597,   598,   459,   190,   191,   192,    88,    89,
      90,   434,   435,   436,    94,    95,    96,   414,   180,   181,
     182,   195,   196,   197,   202,   203,   204,   248,   249,   250,
     226,   227,   228,   230,   231,   232,   235,   236,   237,   210,
     211,   212,   216,   220,   257,   217,   252,   253,   254,   275,
     775,   848,   777,   849,   779,   850,   214,   655,   657,   656,
     270,   273,   799,   512,   277,   513,   514,   678,   278,   703,
     803,   284,   701,   287,   690,   689,   290,   299,   694,   300,
     303,   306,   314,   316,    80,   221,   517,   539,   682,   684,
     323,   538,   324,    81,   544,    82,   325,    83,   535,     1,
       2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     172,   541,   285,   193,   613,   543,   755,   213,   754,   317,
      86,   318,   261,   225,   360,   432,   238,   239,   319,   545,
     546,   438,   440,   245,   246,   320,   106,   442,   444,   258,
     388,   106,   406,   747,   318,   265,   478,   269,   691,  -475,
     274,   319,   184,   241,   386,   233,   -59,   286,   320,   291,
     185,   863,   302,   918,     3,   305,   307,   308,   866,  -316,
      91,   869,  -475,   310,   504,    92,   591,   186,   409,   410,
     294,   504,   409,   429,   403,   633,   329,   635,   295,   864,
     404,   332,   334,   336,   634,   479,   636,    84,   262,   346,
      85,   198,   801,   311,   804,   187,   188,   242,   885,   194,
     768,   942,   365,   199,   200,    93,   811,   183,   234,   611,
     612,   816,   692,   505,   506,   507,   481,   693,   387,   769,
     505,   506,   507,   887,   508,   949,   886,   480,   916,   264,
     215,   508,   361,   644,   350,   296,   297,   298,   482,   411,
     412,   413,   645,   411,   412,   430,   312,   313,   389,   229,
     362,   888,   321,   384,   201,   428,   263,   243,   519,   407,
     834,   791,   509,   871,   646,   240,   390,   385,   244,   509,
     760,   520,   330,   647,   510,   321,   872,   333,   335,   337,
     259,   510,   511,   351,   352,   353,   842,   761,   471,   511,
     282,   283,   354,   355,   356,   247,    87,   474,   687,   521,
     426,   433,   427,   843,   873,   288,   289,   439,   441,   561,
     562,   483,   484,   443,   445,   762,   763,   251,   322,   486,
     563,   879,   878,   488,   705,   292,   293,   697,   189,   675,
     676,   844,   845,   493,   494,   531,   532,   495,   415,   416,
     677,   322,   417,   260,   418,   419,   420,   421,   422,   315,
     498,   499,   218,   266,   219,   447,   448,   205,   206,   207,
     208,   502,   399,   449,   309,   400,   401,   450,   451,   209,
     437,  -342,   402,   271,  -341,  -342,   452,  -342,  -341,   255,
    -341,   256,   533,   534,   472,   453,   272,   454,   455,   276,
     523,   526,   524,   475,   528,   326,   456,   457,   327,   530,
     629,   630,   631,   632,   640,   641,   328,   458,   279,   536,
     642,   643,   415,   416,   280,   487,   600,   601,   281,   489,
     331,   549,   338,   829,   807,   808,   339,   423,   391,   347,
     359,   348,   349,   496,   363,   424,   398,   565,   567,   569,
     602,   603,   604,   605,   606,   607,   608,   609,   364,   366,
     367,   368,   369,   572,   573,   370,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   447,   460,   371,   372,   373,   374,   375,
     376,   461,   377,   392,   378,   462,   463,   379,   380,   381,
     382,   383,   393,   394,   464,   395,   396,   397,   405,   425,
     473,   428,   106,   465,   446,   466,   467,   476,   477,   485,
     490,   492,   497,   500,   468,   469,   491,   550,   501,   503,
     515,   522,   614,   516,  -432,   458,   518,   525,   527,   529,
     537,   540,   547,   566,   568,   570,   548,   551,   627,   552,
     553,   554,   555,   593,   556,   557,   558,   617,   658,   680,
     559,   560,   628,   564,   669,   616,   619,   571,   592,   594,
     595,   596,   -61,   649,   599,   685,   651,   653,   688,   621,
     623,   625,   637,   639,   660,   661,   648,   659,   665,   666,
     662,   670,   664,   673,   672,   679,   683,   667,   686,   699,
     671,   704,   706,   674,   707,   713,   718,   719,   714,   715,
     716,   720,   717,   721,   722,   723,   728,   729,   724,   730,
     725,   731,   726,   732,   733,   734,   736,   695,   615,   696,
     735,   737,   738,   739,   618,   740,   620,   698,   622,   700,
     624,   741,   626,   742,   743,   748,   744,   756,   745,   774,
     746,   708,   749,   710,   753,   712,   638,   757,   776,   781,
     920,   783,   786,   784,   785,   789,   790,   796,   797,   650,
     806,   727,   652,   654,   793,   800,   812,   814,   778,   780,
     794,   817,   809,   815,   802,   821,   663,   830,   798,   832,
     831,   833,   813,   668,   750,   751,   752,   835,   700,   836,
     839,   818,   840,   846,   847,   819,   820,   837,   838,  -283,
     810,   841,  -286,  -289,   851,   854,   758,   867,   858,   896,
     859,   868,   870,   874,   877,   880,   881,   883,   770,   884,
     889,   902,   903,   890,   891,   892,   898,   771,   895,   904,
     875,   907,   805,   899,   908,   911,   909,   913,   709,   914,
     711,   910,   915,   917,   919,   921,   897,   923,   924,   943,
     782,   927,   928,   948,   929,   787,   788,   610,   931,   930,
     932,   939,   946,   795,   947,   933,   431,   934,   681,   935,
       0,     0,   700,     0,   700,     0,     0,   470,     0,   286,
     286,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   759,     0,     0,   764,     0,   765,     0,   766,
       0,   767,     0,     0,     0,     0,     0,     0,   822,   823,
     824,   825,     0,     0,     0,   772,   826,     0,     0,     0,
       0,     0,   827,   828,   773,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   876,     0,     0,     0,   792,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   852,     0,   855,   856,     0,     0,     0,     0,   860,
       0,     0,     0,   862,     0,     0,   865,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   700,     0,     0,     0,     0,   882,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   893,   894,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   900,     0,     0,     0,
       0,   905,     0,     0,   906,     0,     0,     0,     0,     0,
       0,     0,     0,   912,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   853,     0,     0,
     922,   857,     0,     0,     0,   925,   861,   926,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   936,   937,     0,
       0,   938,     4,   940,   941,     0,     0,     0,     0,     5,
       6,   944,     0,   945,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     9,     0,    10,    11,     0,    12,
      13,     0,     0,   901,     0,     0,     0,    14,   950,    15,
      16,    17,     0,     0,     0,     0,    18,     0,     0,     0,
       0,     0,    19,     0,     0,     0,     0,    20,    21,    22,
      23,    24,    25,     0,     0,     0,     0,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,     0,    28,    29,     0,
      30,     0,     0,    31,    32,    33,     0,    34,    35,    36,
      37,    38,    39,    40,     0,    41,     0,     0,     0,    42,
      43,    44,    45,    46,     0,    47,    48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,     0,     0,     0,     0,     0,    50,     0,
       0,    51,     0,    52,    53,    54,     0,     0,    55,     0,
       0,     0,    56,     0,    57,     0,     0,     0,    58,    59,
      60,     0,     0,     0,     0,    61,     0,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
       4,     0,    74,    75,    76,    77,     0,     5,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     9,     0,    10,    11,     0,    12,    13,    78,
       0,    79,     0,     0,     0,    14,     0,    15,    16,    17,
       0,     0,     0,     0,    18,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,     0,    28,    29,     0,    30,     0,
       0,    31,    32,    33,     0,    34,    35,    36,    37,    38,
      39,    40,     0,    41,     0,     0,     0,    42,    43,    44,
      45,    46,     0,    47,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,     0,
       0,     0,     0,     0,     0,     0,    50,     0,     0,    51,
       0,    52,    53,    54,     0,     0,    55,     0,     0,     0,
      56,     0,    57,     0,     0,     0,    58,    59,    60,     0,
       0,     0,     0,    61,     0,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,     0,     0,
      74,    75,    76,    77,   301,     0,    97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,     0,     0,     0,     0,     0,   542,     0,     0,
       0,    99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,     0,     0,   104,     0,     0,
     105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     107,   108,     0,   109,     0,     0,     0,     0,     0,     0,
       0,   110,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,     0,     0,     0,   127,
     128,   129,     0,   130,   131,   132,     0,   133,   134,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   135,     0,   136,     0,     0,     0,   137,     0,     0,
       0,     0,     0,     0,     0,   138,     0,     0,   139,     0,
       0,   140,     0,   141,   142,   143,   144,     0,   145,   146,
       0,     0,     0,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     0,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     304,     0,    97,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    99,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     103,     0,     0,   104,     0,     0,   105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   107,   108,     0,   109,
       0,     0,     0,     0,     0,     0,     0,   110,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     112,   113,   114,     0,     0,     0,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,     0,     0,     0,   127,   128,   129,     0,   130,
     131,   132,     0,   133,   134,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   135,     0,   136,
       0,     0,     0,   137,     0,     0,     0,     0,     0,     0,
       0,   138,     0,     0,   139,     0,     0,   140,     0,   141,
     142,   143,   144,     0,   145,   146,     0,     0,     0,     0,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,    97,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,     0,     0,    98,   340,
       0,     0,     0,     0,     0,     0,     0,     0,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,     0,     0,   104,     0,     0,   105,   341,   342,
     343,     0,     0,     0,     0,     0,     0,   107,   108,   344,
     109,     0,     0,     0,     0,     0,     0,     0,   110,   111,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   112,   113,   114,     0,     0,     0,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,     0,     0,     0,   127,   128,   129,   345,
     130,   131,   132,     0,   133,   134,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   135,     0,
     136,     0,     0,     0,   137,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,     0,     0,   140,     0,
     141,   142,   143,   144,     0,   145,   146,     0,     0,     0,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,    97,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,     0,     0,   222,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
       0,   223,   224,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   103,     0,     0,   104,     0,     0,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,   108,
       0,   109,     0,     0,     0,     0,     0,     0,     0,   110,
     111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   112,   113,   114,     0,     0,     0,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,     0,     0,     0,   127,   128,   129,
       0,   130,   131,   132,     0,   133,   134,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   135,
       0,   136,     0,     0,     0,   137,     0,     0,     0,     0,
       0,     0,     0,   138,     0,     0,   139,     0,     0,   140,
       0,   141,   142,   143,   144,     0,   145,   146,     0,     0,
       0,     0,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,    97,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,     0,     0,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      99,     0,     0,     0,     0,     0,     0,     0,   267,   268,
       0,     0,     0,     0,     0,     0,   100,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,     0,     0,   104,     0,     0,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   107,
     108,     0,   109,     0,     0,     0,     0,     0,     0,     0,
     110,   111,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   112,   113,   114,     0,     0,     0,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,     0,     0,     0,   127,   128,
     129,     0,   130,   131,   132,     0,   133,   134,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     135,     0,   136,     0,     0,     0,   137,     0,     0,     0,
       0,     0,     0,     0,   138,     0,     0,   139,     0,     0,
     140,     0,   141,   142,   143,   144,     0,   145,   146,     0,
       0,     0,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,    97,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,     0,
       0,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,     0,     0,   104,     0,     0,
     105,     0,     0,     0,     0,     0,     0,     0,     0,   106,
     107,   108,     0,   109,     0,     0,     0,     0,     0,     0,
       0,   110,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,     0,     0,     0,   127,
     128,   129,     0,   130,   131,   132,     0,   133,   134,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   135,     0,   136,     0,     0,     0,   137,     0,     0,
       0,     0,     0,     0,     0,   138,     0,     0,   139,     0,
       0,   140,     0,   141,   142,   143,   144,     0,   145,   146,
       0,     0,     0,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     0,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      97,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   339,     0,     0,     0,    98,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   103,     0,
       0,   104,     0,     0,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,   108,     0,   109,     0,     0,
       0,     0,     0,     0,     0,   110,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   112,   113,
     114,     0,     0,     0,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
       0,     0,     0,   127,   128,   129,     0,   130,   131,   132,
       0,   133,   134,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   135,     0,   136,     0,     0,
       0,   137,     0,     0,     0,     0,     0,     0,     0,   138,
       0,     0,   139,     0,     0,   140,     0,   141,   142,   143,
     144,     0,   145,   146,     0,     0,     0,     0,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,    97,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,     0,     0,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
       0,     0,   104,     0,     0,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   107,   108,     0,   109,     0,
       0,     0,     0,     0,     0,     0,   110,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   112,
     113,   114,     0,     0,     0,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,     0,     0,     0,   127,   128,   129,     0,   130,   131,
     132,     0,   133,   134,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   135,     0,   136,     0,
       0,     0,   137,     0,     0,     0,     0,     0,     0,     0,
     138,     0,     0,   139,     0,     0,   140,     0,   141,   142,
     143,   144,     0,   145,   146,     0,     0,     0,     0,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,    97,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,     0,     0,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    99,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     103,     0,     0,   104,     0,     0,   105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   107,   108,     0,   109,
       0,     0,     0,     0,     0,     0,     0,   110,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,   114,     0,     0,     0,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,     0,     0,     0,   127,   128,   129,     0,   130,
     131,   132,     0,   133,   134,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   135,     0,   136,
       0,     0,     0,   137,     0,     0,     0,     0,     0,     0,
       0,   138,     0,     0,   139,     0,     0,   140,     0,   141,
     142,   143,   144,     0,   145,   146,     0,     0,     0,     0,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,    97,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,     0,     0,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,     0,     0,   104,     0,     0,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   107,   108,     0,
     109,     0,     0,     0,     0,     0,     0,     0,   110,   111,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,   114,     0,     0,     0,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,     0,     0,     0,   127,   128,   129,     0,
     130,   131,   132,     0,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   135,     0,
     136,     0,     0,     0,   137,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,     0,     0,   140,     0,
     141,   142,   143,   144,     0,   145,   146,     0,     0,     0,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,     0,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171
};

static const yytype_int16 yycheck[] =
{
      10,   324,    56,    13,   428,   325,   599,    17,   598,     4,
      24,     6,    68,    23,    20,    24,    26,    27,    13,   327,
     328,    24,    24,    33,    34,    20,    82,    24,    24,    39,
      20,    82,    20,     7,     6,    45,    53,    47,    86,    34,
      50,    13,    24,    90,    86,    24,    34,    57,    20,    59,
      32,     7,    62,   871,     0,    65,    66,    67,   797,    20,
      26,   800,    34,    73,    25,    31,   383,    49,    79,    80,
      97,    25,    79,    80,   193,    45,    86,    45,   105,    35,
     199,    91,    92,    93,    54,   102,    54,   210,   144,    99,
     210,    24,   682,    41,   684,    77,    78,   144,     7,    13,
      29,   919,   112,    36,    37,    71,   699,    22,    87,   426,
     427,   704,   160,    74,    75,    76,    20,   165,   160,    48,
      74,    75,    76,     7,    85,   943,    35,   144,   867,    43,
     210,    85,   138,    45,    25,   162,   163,   164,    42,   150,
     151,   152,    54,   150,   151,   152,    94,    95,   138,    24,
     156,    35,   147,    20,    87,   129,   212,    34,     7,   147,
     753,   212,   123,     7,    45,    90,   156,    34,    34,   123,
      32,    20,    86,    54,   135,   147,    20,    91,    92,    93,
     144,   135,   143,    74,    75,    76,    32,    49,   198,   143,
     210,   211,    83,    84,    85,    24,   210,   207,   521,    48,
      19,   210,    21,    49,    48,   157,   158,   210,   210,    74,
      75,   221,   222,   210,   210,    77,    78,    24,   213,   229,
      85,   814,   812,   233,   544,    42,    43,   535,   210,    74,
      75,    77,    78,   243,   244,    94,    95,   247,     8,     9,
      85,   213,    12,    68,    14,    15,    16,    17,    18,    41,
     260,   261,   210,   210,   212,    24,    25,    42,    43,    44,
      45,   271,   189,    32,   174,   192,   193,    36,    37,    54,
     184,     0,   199,    34,     0,     4,    45,     6,     4,   210,
       6,   212,    92,    93,   198,    54,   210,    56,    57,   210,
       5,   301,     7,   207,   304,     6,    65,    66,     4,   309,
      56,    57,    56,    57,    56,    57,     4,    76,   210,   319,
      56,    57,     8,     9,   210,   229,   415,   416,   210,   233,
      24,   331,   212,   747,   689,   690,    20,    97,    20,    34,
     212,    34,    34,   247,    34,   105,   192,   347,   348,   349,
     417,   418,   419,   420,   421,   422,   423,   424,    34,    34,
      34,    34,    34,   363,   364,    34,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,    24,    25,    34,    34,    34,    34,    34,
      34,    32,    34,    20,    34,    36,    37,    34,    34,    34,
      34,    34,    20,    20,    45,    20,    20,    20,   192,   130,
      29,   129,    82,    54,    24,    56,    57,    46,    46,     7,
      29,   147,    34,    13,    65,    66,    69,   331,   152,     7,
       7,     7,   432,   147,   147,    76,   147,     7,     7,     7,
      13,    34,    29,   347,   348,   349,    29,    72,   448,    72,
      72,    72,    34,   210,    35,    35,    35,    48,    42,    20,
      35,    35,    33,    35,    69,    24,    24,    34,    34,    34,
      34,    34,    34,   473,    34,   519,   476,   477,   522,    24,
      24,    24,    34,    33,     7,   485,    34,   210,     7,     7,
     490,     7,   492,     7,   102,    34,   147,   497,     7,    34,
     500,    34,   210,   503,   210,   212,    35,    35,   212,   212,
     212,    35,   212,    35,    35,    35,     7,     7,    35,     7,
      35,     7,    35,    35,    35,    35,     7,   527,   432,   529,
      35,    35,    35,    35,   438,    35,   440,   537,   442,   539,
     444,    35,   446,     7,     7,   210,    35,    29,    35,   210,
      35,   551,    35,   553,    34,   555,   460,    29,   210,    13,
     873,     7,   148,    42,    42,     7,     7,     7,    34,   473,
       7,   571,   476,   477,    72,    34,     7,     7,   210,   210,
     210,     7,   167,    35,   210,    35,   490,    35,   212,     7,
      35,     7,   148,   497,   594,   595,   596,   148,   598,    35,
      29,   212,    29,     7,     7,   212,   212,   210,   210,     7,
     167,   211,     7,     7,    13,     7,   616,     7,    35,   211,
      35,    35,   148,   148,    35,    13,    35,    35,   628,    35,
      35,     7,     7,    35,    35,    35,    29,   637,    35,     7,
     148,    13,   686,    29,    13,   115,    35,    13,   552,    72,
     554,    35,    35,    35,     7,    13,   211,    13,    35,     7,
     660,    35,    35,    13,   211,   665,   666,   425,    35,   211,
      35,    35,    35,   673,    35,   902,   177,   903,   515,   904,
      -1,    -1,   682,    -1,   684,    -1,    -1,   194,    -1,   689,
     690,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   616,    -1,    -1,   619,    -1,   621,    -1,   623,
      -1,   625,    -1,    -1,    -1,    -1,    -1,    -1,   728,   729,
     730,   731,    -1,    -1,    -1,   639,   736,    -1,    -1,    -1,
      -1,    -1,   742,   743,   648,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   806,    -1,    -1,    -1,   670,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   781,    -1,   783,   784,    -1,    -1,    -1,    -1,   789,
      -1,    -1,    -1,   793,    -1,    -1,   796,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   812,    -1,    -1,    -1,    -1,   817,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   832,   833,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   846,    -1,    -1,    -1,
      -1,   851,    -1,    -1,   854,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   863,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   781,    -1,    -1,
     880,   785,    -1,    -1,    -1,   885,   790,   887,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   907,   908,    -1,
      -1,   911,     3,   913,   914,    -1,    -1,    -1,    -1,    10,
      11,   921,    -1,   923,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    -1,    25,    -1,    27,    28,    -1,    30,
      31,    -1,    -1,   847,    -1,    -1,    -1,    38,   948,    40,
      41,    42,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    -1,    88,    89,    -1,
      91,    -1,    -1,    94,    95,    96,    -1,    98,    99,   100,
     101,   102,   103,   104,    -1,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,    -1,   116,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,
      -1,   142,    -1,   144,   145,   146,    -1,    -1,   149,    -1,
      -1,    -1,   153,    -1,   155,    -1,    -1,    -1,   159,   160,
     161,    -1,    -1,    -1,    -1,   166,    -1,   168,   169,   170,
     171,   172,   173,    -1,   175,   176,   177,   178,   179,   180,
       3,    -1,   183,   184,   185,   186,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    -1,    25,    -1,    27,    28,    -1,    30,    31,   210,
      -1,   212,    -1,    -1,    -1,    38,    -1,    40,    41,    42,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    -1,    88,    89,    -1,    91,    -1,
      -1,    94,    95,    96,    -1,    98,    99,   100,   101,   102,
     103,   104,    -1,   106,    -1,    -1,    -1,   110,   111,   112,
     113,   114,    -1,   116,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,   142,
      -1,   144,   145,   146,    -1,    -1,   149,    -1,    -1,    -1,
     153,    -1,   155,    -1,    -1,    -1,   159,   160,   161,    -1,
      -1,    -1,    -1,   166,    -1,   168,   169,   170,   171,   172,
     173,    -1,   175,   176,   177,   178,   179,   180,    -1,    -1,
     183,   184,   185,   186,     7,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,    -1,   136,   137,   138,    -1,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   154,    -1,   156,    -1,    -1,    -1,   160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   168,    -1,    -1,   171,    -1,
      -1,   174,    -1,   176,   177,   178,   179,    -1,   181,   182,
      -1,    -1,    -1,    -1,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
       7,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,   132,   133,   134,    -1,   136,
     137,   138,    -1,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,   156,
      -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   168,    -1,    -1,   171,    -1,    -1,   174,    -1,   176,
     177,   178,   179,    -1,   181,   182,    -1,    -1,    -1,    -1,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,     9,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    70,    -1,    -1,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,   132,   133,   134,   135,
     136,   137,   138,    -1,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,
     156,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   168,    -1,    -1,   171,    -1,    -1,   174,    -1,
     176,   177,   178,   179,    -1,   181,   182,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,     9,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    70,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,   132,   133,   134,
      -1,   136,   137,   138,    -1,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,
      -1,   156,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   168,    -1,    -1,   171,    -1,    -1,   174,
      -1,   176,   177,   178,   179,    -1,   181,   182,    -1,    -1,
      -1,    -1,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,     9,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,    -1,    -1,   132,   133,
     134,    -1,   136,   137,   138,    -1,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     154,    -1,   156,    -1,    -1,    -1,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   168,    -1,    -1,   171,    -1,    -1,
     174,    -1,   176,   177,   178,   179,    -1,   181,   182,    -1,
      -1,    -1,    -1,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,     9,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,    -1,   136,   137,   138,    -1,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   154,    -1,   156,    -1,    -1,    -1,   160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   168,    -1,    -1,   171,    -1,
      -1,   174,    -1,   176,   177,   178,   179,    -1,   181,   182,
      -1,    -1,    -1,    -1,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    84,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,   132,   133,   134,    -1,   136,   137,   138,
      -1,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   154,    -1,   156,    -1,    -1,
      -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,
      -1,    -1,   171,    -1,    -1,   174,    -1,   176,   177,   178,
     179,    -1,   181,   182,    -1,    -1,    -1,    -1,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,     9,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,    -1,   132,   133,   134,    -1,   136,   137,
     138,    -1,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,   156,    -1,
      -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     168,    -1,    -1,   171,    -1,    -1,   174,    -1,   176,   177,
     178,   179,    -1,   181,   182,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,     9,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,   132,   133,   134,    -1,   136,
     137,   138,    -1,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,   156,
      -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   168,    -1,    -1,   171,    -1,    -1,   174,    -1,   176,
     177,   178,   179,    -1,   181,   182,    -1,    -1,    -1,    -1,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,     9,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,   132,   133,   134,    -1,
     136,   137,   138,    -1,   140,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,
     156,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   168,    -1,    -1,   171,    -1,    -1,   174,    -1,
     176,   177,   178,   179,    -1,   181,   182,    -1,    -1,    -1,
      -1,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   323,   324,     0,     3,    10,    11,    22,    23,    25,
      27,    28,    30,    31,    38,    40,    41,    42,    47,    53,
      58,    59,    60,    61,    62,    63,    68,    86,    88,    89,
      91,    94,    95,    96,    98,    99,   100,   101,   102,   103,
     104,   106,   110,   111,   112,   113,   114,   116,   117,   131,
     139,   142,   144,   145,   146,   149,   153,   155,   159,   160,
     161,   166,   168,   169,   170,   171,   172,   173,   175,   176,
     177,   178,   179,   180,   183,   184,   185,   186,   210,   212,
     308,   317,   319,   321,   210,   210,    24,   210,   232,   233,
     234,    26,    31,    71,   238,   239,   240,     9,    24,    34,
      50,    51,    52,    67,    70,    73,    82,    83,    84,    86,
      94,    95,   107,   108,   109,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   132,   133,   134,
     136,   137,   138,   140,   141,   154,   156,   160,   168,   171,
     174,   176,   177,   178,   179,   181,   182,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   215,   216,   217,   218,   219,   220,   223,   224,
     242,   243,   244,    22,    24,    32,    49,    77,    78,   210,
     229,   230,   231,   215,   220,   245,   246,   247,    24,    36,
      37,    87,   248,   249,   250,    42,    43,    44,    45,    54,
     263,   264,   265,   215,   280,   210,   266,   269,   210,   212,
     267,   309,    24,    36,    37,   215,   254,   255,   256,    24,
     257,   258,   259,    24,    87,   260,   261,   262,   215,   215,
      90,    90,   144,    34,    34,   215,   215,    24,   251,   252,
     253,    24,   270,   271,   272,   210,   212,   268,   215,   144,
      68,    68,   144,   212,   220,   215,   210,    42,    43,   215,
     284,    34,   210,   285,   215,   273,   210,   288,   292,   210,
     210,   210,   210,   211,   295,   295,   215,   297,   157,   158,
     300,   215,    42,    43,    97,   105,   162,   163,   164,   301,
     303,     7,   215,   304,     7,   215,   305,   215,   215,   174,
     215,    41,    94,    95,   306,    41,   307,     4,     6,    13,
      20,   147,   213,   314,   316,   320,     6,     4,     4,   215,
     220,    24,   215,   220,   215,   220,   215,   220,   212,    20,
      25,    74,    75,    76,    85,   135,   215,    34,    34,    34,
      25,    74,    75,    76,    83,    84,    85,   221,   222,   212,
      20,   138,   156,    34,    34,   215,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    20,    34,    86,   160,    20,   138,
     156,    20,    20,    20,    20,    20,    20,    20,   192,   189,
     192,   193,   199,   193,   199,   192,    20,   147,   225,    79,
      80,   150,   151,   152,   241,     8,     9,    12,    14,    15,
      16,    17,    18,    97,   105,   130,    19,    21,   129,    80,
     152,   241,    24,   210,   235,   236,   237,   220,    24,   210,
      24,   210,    24,   210,    24,   210,    24,    24,    25,    32,
      36,    37,    45,    54,    56,    57,    65,    66,    76,   228,
      25,    32,    36,    37,    45,    54,    56,    57,    65,    66,
     228,   215,   220,    29,   215,   220,    46,    46,    53,   102,
     144,    20,    42,   215,   215,     7,   215,   220,   215,   220,
      29,    69,   147,   215,   215,   215,   220,    34,   215,   215,
      13,   152,   215,     7,    25,    74,    75,    76,    85,   123,
     135,   143,   287,   289,   290,     7,   147,   310,   147,     7,
      20,    48,     7,     5,     7,     7,   215,     7,   215,     7,
     215,    94,    95,    92,    93,   322,   215,    13,   315,   311,
      34,   287,   210,   317,   318,   321,   321,    29,    29,   215,
     220,    72,    72,    72,    72,    34,    35,    35,    35,    35,
      35,    74,    75,    85,    35,   215,   220,   215,   220,   215,
     220,    34,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   219,    34,   210,    34,    34,    34,   226,   227,    34,
     217,   217,   216,   216,   216,   216,   216,   216,   216,   216,
     218,   219,   219,   224,   215,   220,    24,    48,   220,    24,
     220,    24,   220,    24,   220,    24,   220,   215,    33,    56,
      57,    56,    57,    45,    54,    45,    54,    34,   220,    33,
      56,    57,    56,    57,    45,    54,    45,    54,    34,   215,
     220,   215,   220,   215,   220,   281,   283,   282,    42,   210,
       7,   215,   215,   220,   215,     7,     7,   215,   220,    69,
       7,   215,   102,     7,   215,    74,    75,    85,   291,    34,
      20,   292,   312,   147,   313,   295,     7,   287,   295,   299,
     298,    86,   160,   165,   302,   215,   215,   321,   215,    34,
     215,   296,   215,   293,    34,   317,   210,   210,   215,   220,
     215,   220,   215,   212,   212,   212,   212,   212,    35,    35,
      35,    35,    35,    35,    35,    35,    35,   215,     7,     7,
       7,     7,    35,    35,    35,    35,     7,    35,    35,    35,
      35,    35,     7,     7,    35,    35,    35,     7,   210,    35,
     215,   215,   215,    34,   296,   293,    29,    29,   215,   220,
      32,    49,    77,    78,   220,   220,   220,   220,    29,    48,
     215,   215,   220,   220,   210,   274,   210,   276,   210,   278,
     210,    13,   215,     7,    42,    42,   148,   215,   215,     7,
       7,   212,   220,    72,   210,   215,     7,    34,   212,   286,
      34,   296,   210,   294,   296,   295,     7,   297,   297,   167,
     167,   293,     7,   148,     7,    35,   293,     7,   212,   212,
     212,    35,   215,   215,   215,   215,   215,   215,   215,   224,
      35,    35,     7,     7,   293,   148,    35,   210,   210,    29,
      29,   211,    32,    49,    77,    78,     7,     7,   275,   277,
     279,    13,   215,   220,     7,   215,   215,   220,    35,    35,
     215,   220,   215,     7,    35,   215,   286,     7,    35,   286,
     148,     7,    20,    48,   148,   148,   295,    35,   296,   293,
      13,    35,   215,    35,    35,     7,    35,     7,    35,    35,
      35,    35,    35,   215,   215,    35,   211,   211,    29,    29,
     215,   220,     7,     7,     7,   215,   215,    13,    13,    35,
      35,   115,   215,    13,    72,    35,   286,    35,   294,     7,
     287,    13,   215,    13,    35,   215,   215,    35,    35,   211,
     211,    35,    35,   274,   276,   278,   215,   215,   215,    35,
     215,   215,   294,     7,   215,   215,    35,    35,    13,   294,
     215
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   214,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   216,   216,   216,   217,   217,   218,   218,   218,
     219,   219,   219,   220,   221,   221,   221,   221,   221,   221,
     221,   222,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   225,
     224,   226,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   227,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   228,   228,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   230,   230,   230,   230,
     230,   231,   231,   232,   232,   233,   233,   234,   234,   235,
     235,   236,   236,   237,   237,   238,   238,   238,   239,   239,
     239,   240,   240,   241,   241,   241,   242,   242,   242,   243,
     243,   243,   244,   244,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   247,   247,   248,   248,   248,   248,
     248,   249,   249,   250,   250,   251,   252,   253,   253,   254,
     254,   255,   255,   256,   256,   257,   258,   259,   259,   260,
     260,   260,   261,   261,   262,   262,   263,   263,   263,   263,
     263,   264,   264,   264,   265,   265,   266,   266,   266,   266,
     266,   266,   267,   267,   268,   268,   269,   270,   271,   272,
     272,   273,   274,   275,   274,   276,   277,   276,   278,   279,
     278,   281,   280,   282,   280,   283,   280,   284,   284,   284,
     285,   285,   286,   286,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   289,   288,   290,   288,   291,   288,
     292,   292,   293,   293,   294,   294,   294,   294,   294,   294,
     295,   295,   295,   295,   295,   295,   295,   295,   296,   296,
     297,   297,   297,   298,   297,   299,   297,   300,   300,   301,
     301,   301,   301,   301,   302,   302,   302,   302,   302,   303,
     304,   304,   304,   305,   305,   305,   306,   306,   306,   306,
     307,   307,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   309,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   310,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   311,   308,   312,   308,   313,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   314,   308,   315,   308,   316,
     308,   308,   308,   308,   317,   318,   317,   320,   319,   322,
     321,   321,   321,   321,   321,   324,   323
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
       1,     1,     2,     2,     2,     1,     1,     1,     1,     1,
       2,     3,     2,     2,     1,     1,     2,     2,     1,     2,
       3,     1,     4,     1,     1,     1,     0,     3,     1,     1,
       2,     1,     2,     2,     3,     2,     2,     5,     5,     6,
       1,     2,     0,     6,     2,     2,     2,     5,     8,     2,
       2,     2,     0,     5,     0,     6,     0,     6,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     1,     2,
       2,     2,     2,     1,     2,     1,     1,     8,     8,     8,
      10,     2,     2,     3,     4,     0,     7,     0,     8,     0,
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
#line 77 "src/ugbc.y"
                              {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2953 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 81 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2962 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 85 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2970 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 88 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2978 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 91 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2986 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 94 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2994 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 97 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3002 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 100 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3010 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 103 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 3018 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 110 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3026 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 113 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3035 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 126 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3044 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 130 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3053 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 138 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 3062 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 142 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 3071 "src-generated/ugbc.tab.c"
    break;

  case 23: /* direct_integer: HASH Integer  */
#line 149 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 3079 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: BYTE  */
#line 154 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 3087 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: WORD  */
#line 157 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 3095 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: DWORD  */
#line 160 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 3103 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: POSITION  */
#line 163 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 3111 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: COLOR  */
#line 166 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 3119 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: WIDTH  */
#line 169 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 3127 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: HEIGHT  */
#line 172 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 3135 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition: random_definition_simple  */
#line 177 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 3143 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: BLACK  */
#line 182 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 3152 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: WHITE  */
#line 186 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 3161 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: RED  */
#line 190 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 3170 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: CYAN  */
#line 194 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 3179 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: VIOLET  */
#line 198 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 3188 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: GREEN  */
#line 202 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 3197 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: BLUE  */
#line 206 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 3206 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: YELLOW  */
#line 210 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 3215 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: ORANGE  */
#line 214 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 3224 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: BROWN  */
#line 218 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 3233 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: LIGHT RED  */
#line 222 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 3242 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: DARK GREY  */
#line 226 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 3251 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: GREY  */
#line 230 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 3260 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT GREEN  */
#line 234 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 3269 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT BLUE  */
#line 238 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 3278 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT GREY  */
#line 242 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 3287 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK BLUE  */
#line 246 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 3296 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: MAGENTA  */
#line 250 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 3305 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: PURPLE  */
#line 254 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 3314 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LAVENDER  */
#line 258 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 3323 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: GOLD  */
#line 262 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 3332 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TURQUOISE  */
#line 266 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 3341 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: TAN  */
#line 270 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 3350 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: YELLOW GREEN  */
#line 274 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 3359 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: OLIVE GREEN  */
#line 278 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 3368 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PINK  */
#line 282 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 3377 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: PEACH  */
#line 286 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 3386 "src-generated/ugbc.tab.c"
    break;

  case 59: /* $@1: %empty  */
#line 292 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 3395 "src-generated/ugbc.tab.c"
    break;

  case 60: /* exponential: Identifier $@1 OP indexes CP  */
#line 296 "src/ugbc.y"
                    {
        Variable * array = variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-4].string) );
        }
        (yyval.string) = variable_move_from_array( _environment, (yyvsp[-4].string) )->name;
    }
#line 3407 "src-generated/ugbc.tab.c"
    break;

  case 61: /* $@2: %empty  */
#line 303 "src/ugbc.y"
                        {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 3416 "src-generated/ugbc.tab.c"
    break;

  case 62: /* exponential: Identifier DOLLAR $@2 OP indexes CP  */
#line 307 "src/ugbc.y"
                    {
        Variable * array = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-5].string) );
        }
        (yyval.string) = variable_move_from_array( _environment, (yyvsp[-5].string) )->name;
    }
#line 3428 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: Identifier  */
#line 314 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 3436 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: Identifier DOLLAR  */
#line 317 "src/ugbc.y"
                        { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 3444 "src-generated/ugbc.tab.c"
    break;

  case 65: /* exponential: Integer  */
#line 320 "src/ugbc.y"
              { 
        if ( (yyvsp[0].integer) < 0 ) {
            (yyval.string) = variable_temporary( _environment, VT_SWORD, "(signed integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        } else {
            (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        }
      }
#line 3458 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: MINUS Integer  */
#line 329 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3467 "src-generated/ugbc.tab.c"
    break;

  case 67: /* exponential: String  */
#line 333 "src/ugbc.y"
             { 
        outline1("; (expr string: \"%s\")", (yyvsp[0].string) );
        (yyval.string) = variable_temporary( _environment, VT_STRING, "(string value)" )->name;
        outline1("; %s", (yyval.string) );
        variable_store_string( _environment, (yyval.string), (yyvsp[0].string) );
        outline2("; variable stored: %s = %s", (yyval.string), (yyvsp[0].string) );
      }
#line 3479 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: OP BYTE CP Integer  */
#line 340 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3488 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: OP SIGNED BYTE CP Integer  */
#line 344 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3497 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: OP WORD CP Integer  */
#line 348 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3506 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: OP SIGNED WORD CP Integer  */
#line 352 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3515 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: OP DWORD CP Integer  */
#line 356 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3524 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP SIGNED DWORD CP Integer  */
#line 360 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3533 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP POSITION CP Integer  */
#line 364 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3542 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP COLOR CP Integer  */
#line 368 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3551 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: color_enumeration  */
#line 372 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3559 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: PEEK OP direct_integer CP  */
#line 375 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3567 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: PEEK OP expr CP  */
#line 378 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3575 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: XPEN  */
#line 381 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3583 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: YPEN  */
#line 384 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3591 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: COLLISION OP direct_integer CP  */
#line 387 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3599 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: COLLISION OP expr CP  */
#line 390 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3607 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: HIT OP direct_integer CP  */
#line 393 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3615 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: HIT OP expr CP  */
#line 396 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3623 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: LEFT OP expr COMMA expr CP  */
#line 399 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3631 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 402 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3639 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: MID OP expr COMMA expr CP  */
#line 405 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3647 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 408 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3655 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: INSTR OP expr COMMA expr CP  */
#line 411 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3663 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 414 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3671 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: UPPER OP expr CP  */
#line 417 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3679 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: LOWER OP expr CP  */
#line 420 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3687 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: STR OP expr CP  */
#line 423 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3695 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: SPACE OP expr CP  */
#line 426 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3703 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: FLIP OP expr CP  */
#line 429 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3711 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: CHR OP expr CP  */
#line 432 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3719 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: ASC OP expr CP  */
#line 435 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3727 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: LEN OP expr CP  */
#line 438 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3735 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: STRING OP expr COMMA expr CP  */
#line 441 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3743 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: VAL OP expr CP  */
#line 444 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3751 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: RANDOM random_definition  */
#line 447 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3759 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: RND OP expr CP  */
#line 450 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 3767 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: OP expr CP  */
#line 453 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3775 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: MAX OP expr COMMA expr CP  */
#line 456 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3783 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: MIN OP expr COMMA expr CP  */
#line 459 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3791 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: PARAM OP Identifier CP  */
#line 462 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3799 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: PARAM DOLLAR OP Identifier CP  */
#line 465 "src/ugbc.y"
                                    {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3807 "src-generated/ugbc.tab.c"
    break;

  case 108: /* $@3: %empty  */
#line 468 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 3815 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: Identifier OSP $@3 values CSP  */
#line 470 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 3824 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: SGN OP expr CP  */
#line 474 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 3832 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: ABS OP expr CP  */
#line 477 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 3840 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: TRUE  */
#line 480 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3849 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: FALSE  */
#line 484 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3858 "src-generated/ugbc.tab.c"
    break;

  case 114: /* exponential: COLORS  */
#line 488 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 3867 "src-generated/ugbc.tab.c"
    break;

  case 115: /* exponential: PEN COLORS  */
#line 492 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3876 "src-generated/ugbc.tab.c"
    break;

  case 116: /* exponential: PEN DEFAULT  */
#line 496 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3885 "src-generated/ugbc.tab.c"
    break;

  case 117: /* exponential: DEFAULT PEN  */
#line 500 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3894 "src-generated/ugbc.tab.c"
    break;

  case 118: /* exponential: PAPER COLORS  */
#line 504 "src/ugbc.y"
                   {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3903 "src-generated/ugbc.tab.c"
    break;

  case 119: /* exponential: PAPER DEFAULT  */
#line 508 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3912 "src-generated/ugbc.tab.c"
    break;

  case 120: /* exponential: DEFAULT PAPER  */
#line 512 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3921 "src-generated/ugbc.tab.c"
    break;

  case 121: /* exponential: WIDTH  */
#line 516 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 3929 "src-generated/ugbc.tab.c"
    break;

  case 122: /* exponential: HEIGHT  */
#line 519 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 3937 "src-generated/ugbc.tab.c"
    break;

  case 123: /* exponential: TIMER  */
#line 522 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 3945 "src-generated/ugbc.tab.c"
    break;

  case 124: /* exponential: PEN DOLLAR OP expr CP  */
#line 525 "src/ugbc.y"
                            {
        (yyval.string) = text_get_pen( _environment, (yyvsp[-1].string) )->name;
    }
#line 3953 "src-generated/ugbc.tab.c"
    break;

  case 125: /* exponential: PAPER DOLLAR OP expr CP  */
#line 528 "src/ugbc.y"
                              {
        (yyval.string) = text_get_paper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3961 "src-generated/ugbc.tab.c"
    break;

  case 126: /* exponential: CMOVE DOLLAR OP expr COMMA expr CP  */
#line 531 "src/ugbc.y"
                                         {
        (yyval.string) = text_get_cmove( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3969 "src-generated/ugbc.tab.c"
    break;

  case 127: /* exponential: CUP DOLLAR  */
#line 534 "src/ugbc.y"
                 {
        (yyval.string) = text_get_cmove_direct( _environment, 0, -1 )->name;
    }
#line 3977 "src-generated/ugbc.tab.c"
    break;

  case 128: /* exponential: CDOWN DOLLAR  */
#line 537 "src/ugbc.y"
                   {
        (yyval.string) = text_get_cmove_direct( _environment, 0, 1 )->name;
    }
#line 3985 "src-generated/ugbc.tab.c"
    break;

  case 129: /* exponential: CLEFT DOLLAR  */
#line 540 "src/ugbc.y"
                   {
        (yyval.string) = text_get_cmove_direct( _environment, -1, 0 )->name;
    }
#line 3993 "src-generated/ugbc.tab.c"
    break;

  case 130: /* exponential: CRIGHT DOLLAR  */
#line 543 "src/ugbc.y"
                    {
        (yyval.string) = text_get_cmove_direct( _environment, 1, 0 )->name;
    }
#line 4001 "src-generated/ugbc.tab.c"
    break;

  case 131: /* exponential: AT DOLLAR OP expr COMMA expr CP  */
#line 546 "src/ugbc.y"
                                      {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4009 "src-generated/ugbc.tab.c"
    break;

  case 132: /* exponential: LOCATE DOLLAR OP expr COMMA expr CP  */
#line 549 "src/ugbc.y"
                                          {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4017 "src-generated/ugbc.tab.c"
    break;

  case 133: /* exponential: TAB DOLLAR  */
#line 552 "src/ugbc.y"
                 {
        (yyval.string) = text_get_tab( _environment )->name;
    }
#line 4025 "src-generated/ugbc.tab.c"
    break;

  case 134: /* exponential: XCURS  */
#line 555 "src/ugbc.y"
            {
        (yyval.string) = text_get_xcurs( _environment )->name;
    }
#line 4033 "src-generated/ugbc.tab.c"
    break;

  case 135: /* exponential: YCURS  */
#line 558 "src/ugbc.y"
            {
        (yyval.string) = text_get_ycurs( _environment )->name;
    }
#line 4041 "src-generated/ugbc.tab.c"
    break;

  case 138: /* bank_definition_simple: AT direct_integer  */
#line 566 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4049 "src-generated/ugbc.tab.c"
    break;

  case 139: /* bank_definition_simple: Identifier AT direct_integer  */
#line 569 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4057 "src-generated/ugbc.tab.c"
    break;

  case 140: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 572 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 4065 "src-generated/ugbc.tab.c"
    break;

  case 141: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 575 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 4073 "src-generated/ugbc.tab.c"
    break;

  case 142: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 578 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4081 "src-generated/ugbc.tab.c"
    break;

  case 143: /* bank_definition_simple: DATA AT direct_integer  */
#line 581 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4089 "src-generated/ugbc.tab.c"
    break;

  case 144: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 585 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 4097 "src-generated/ugbc.tab.c"
    break;

  case 145: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 588 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 4105 "src-generated/ugbc.tab.c"
    break;

  case 146: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 591 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4113 "src-generated/ugbc.tab.c"
    break;

  case 147: /* bank_definition_simple: CODE AT direct_integer  */
#line 594 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4121 "src-generated/ugbc.tab.c"
    break;

  case 148: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 598 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4129 "src-generated/ugbc.tab.c"
    break;

  case 149: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 601 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4137 "src-generated/ugbc.tab.c"
    break;

  case 150: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 604 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4145 "src-generated/ugbc.tab.c"
    break;

  case 151: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 607 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4153 "src-generated/ugbc.tab.c"
    break;

  case 152: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 611 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4161 "src-generated/ugbc.tab.c"
    break;

  case 153: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 614 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4169 "src-generated/ugbc.tab.c"
    break;

  case 154: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 617 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4177 "src-generated/ugbc.tab.c"
    break;

  case 155: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 620 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4185 "src-generated/ugbc.tab.c"
    break;

  case 156: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 626 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4193 "src-generated/ugbc.tab.c"
    break;

  case 157: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 629 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4201 "src-generated/ugbc.tab.c"
    break;

  case 158: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 632 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4209 "src-generated/ugbc.tab.c"
    break;

  case 159: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 635 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4217 "src-generated/ugbc.tab.c"
    break;

  case 160: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 638 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4225 "src-generated/ugbc.tab.c"
    break;

  case 163: /* raster_definition_simple: Identifier AT direct_integer  */
#line 647 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 4233 "src-generated/ugbc.tab.c"
    break;

  case 164: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 650 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 4241 "src-generated/ugbc.tab.c"
    break;

  case 165: /* raster_definition_expression: Identifier AT expr  */
#line 655 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4249 "src-generated/ugbc.tab.c"
    break;

  case 166: /* raster_definition_expression: AT expr WITH Identifier  */
#line 658 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4257 "src-generated/ugbc.tab.c"
    break;

  case 169: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 667 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 4265 "src-generated/ugbc.tab.c"
    break;

  case 170: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 670 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 4273 "src-generated/ugbc.tab.c"
    break;

  case 171: /* next_raster_definition_expression: Identifier AT expr  */
#line 675 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 4281 "src-generated/ugbc.tab.c"
    break;

  case 172: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 678 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4289 "src-generated/ugbc.tab.c"
    break;

  case 175: /* color_definition_simple: BORDER direct_integer  */
#line 687 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 4297 "src-generated/ugbc.tab.c"
    break;

  case 176: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 690 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4305 "src-generated/ugbc.tab.c"
    break;

  case 177: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 693 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4313 "src-generated/ugbc.tab.c"
    break;

  case 178: /* color_definition_expression: BORDER expr  */
#line 698 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 4321 "src-generated/ugbc.tab.c"
    break;

  case 179: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 701 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4329 "src-generated/ugbc.tab.c"
    break;

  case 180: /* color_definition_expression: SPRITE expr TO expr  */
#line 704 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4337 "src-generated/ugbc.tab.c"
    break;

  case 186: /* wait_definition_simple: direct_integer CYCLES  */
#line 718 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 4345 "src-generated/ugbc.tab.c"
    break;

  case 187: /* wait_definition_simple: direct_integer TICKS  */
#line 721 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 4353 "src-generated/ugbc.tab.c"
    break;

  case 188: /* wait_definition_simple: direct_integer milliseconds  */
#line 724 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 4361 "src-generated/ugbc.tab.c"
    break;

  case 189: /* wait_definition_expression: expr CYCLES  */
#line 729 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 4369 "src-generated/ugbc.tab.c"
    break;

  case 190: /* wait_definition_expression: expr TICKS  */
#line 732 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 4377 "src-generated/ugbc.tab.c"
    break;

  case 191: /* wait_definition_expression: expr milliseconds  */
#line 735 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 4385 "src-generated/ugbc.tab.c"
    break;

  case 194: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 745 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 4393 "src-generated/ugbc.tab.c"
    break;

  case 195: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 748 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 4401 "src-generated/ugbc.tab.c"
    break;

  case 196: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 751 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 4409 "src-generated/ugbc.tab.c"
    break;

  case 197: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 754 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4417 "src-generated/ugbc.tab.c"
    break;

  case 198: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 757 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 4425 "src-generated/ugbc.tab.c"
    break;

  case 199: /* sprite_definition_simple: direct_integer ENABLE  */
#line 760 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 4433 "src-generated/ugbc.tab.c"
    break;

  case 200: /* sprite_definition_simple: direct_integer DISABLE  */
#line 763 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 4441 "src-generated/ugbc.tab.c"
    break;

  case 201: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 766 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4449 "src-generated/ugbc.tab.c"
    break;

  case 202: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 769 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4457 "src-generated/ugbc.tab.c"
    break;

  case 203: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 772 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4465 "src-generated/ugbc.tab.c"
    break;

  case 204: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 775 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4473 "src-generated/ugbc.tab.c"
    break;

  case 205: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 778 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4481 "src-generated/ugbc.tab.c"
    break;

  case 206: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 781 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4489 "src-generated/ugbc.tab.c"
    break;

  case 207: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 784 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4497 "src-generated/ugbc.tab.c"
    break;

  case 208: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 787 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4505 "src-generated/ugbc.tab.c"
    break;

  case 209: /* sprite_definition_expression: expr DATA FROM expr  */
#line 792 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4513 "src-generated/ugbc.tab.c"
    break;

  case 210: /* sprite_definition_expression: expr MULTICOLOR  */
#line 795 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4521 "src-generated/ugbc.tab.c"
    break;

  case 211: /* sprite_definition_expression: expr MONOCOLOR  */
#line 798 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4529 "src-generated/ugbc.tab.c"
    break;

  case 212: /* sprite_definition_expression: expr COLOR expr  */
#line 801 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4537 "src-generated/ugbc.tab.c"
    break;

  case 213: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 804 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 4545 "src-generated/ugbc.tab.c"
    break;

  case 214: /* sprite_definition_expression: expr ENABLE  */
#line 807 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 4553 "src-generated/ugbc.tab.c"
    break;

  case 215: /* sprite_definition_expression: expr DISABLE  */
#line 810 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 4561 "src-generated/ugbc.tab.c"
    break;

  case 216: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 813 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4569 "src-generated/ugbc.tab.c"
    break;

  case 217: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 816 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4577 "src-generated/ugbc.tab.c"
    break;

  case 218: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 819 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4585 "src-generated/ugbc.tab.c"
    break;

  case 219: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 822 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4593 "src-generated/ugbc.tab.c"
    break;

  case 220: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 825 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4601 "src-generated/ugbc.tab.c"
    break;

  case 221: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 828 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4609 "src-generated/ugbc.tab.c"
    break;

  case 222: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 831 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4617 "src-generated/ugbc.tab.c"
    break;

  case 223: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 834 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4625 "src-generated/ugbc.tab.c"
    break;

  case 226: /* bitmap_definition_simple: AT direct_integer  */
#line 843 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4633 "src-generated/ugbc.tab.c"
    break;

  case 227: /* bitmap_definition_simple: ENABLE  */
#line 846 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 4641 "src-generated/ugbc.tab.c"
    break;

  case 228: /* bitmap_definition_simple: DISABLE  */
#line 849 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 4649 "src-generated/ugbc.tab.c"
    break;

  case 229: /* bitmap_definition_simple: CLEAR  */
#line 852 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 4657 "src-generated/ugbc.tab.c"
    break;

  case 230: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 855 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 4665 "src-generated/ugbc.tab.c"
    break;

  case 231: /* bitmap_definition_expression: AT expr  */
#line 861 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4673 "src-generated/ugbc.tab.c"
    break;

  case 232: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 864 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 4681 "src-generated/ugbc.tab.c"
    break;

  case 235: /* textmap_definition_simple: AT direct_integer  */
#line 874 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4689 "src-generated/ugbc.tab.c"
    break;

  case 236: /* textmap_definition_expression: AT expr  */
#line 879 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4697 "src-generated/ugbc.tab.c"
    break;

  case 239: /* text_definition_simple: ENABLE  */
#line 888 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 4705 "src-generated/ugbc.tab.c"
    break;

  case 240: /* text_definition_simple: DISABLE  */
#line 891 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 4713 "src-generated/ugbc.tab.c"
    break;

  case 241: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 896 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4721 "src-generated/ugbc.tab.c"
    break;

  case 242: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 899 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4729 "src-generated/ugbc.tab.c"
    break;

  case 245: /* tiles_definition_simple: AT direct_integer  */
#line 908 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 4737 "src-generated/ugbc.tab.c"
    break;

  case 246: /* tiles_definition_expression: AT expr  */
#line 913 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 4745 "src-generated/ugbc.tab.c"
    break;

  case 249: /* colormap_definition_simple: AT direct_integer  */
#line 922 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 4753 "src-generated/ugbc.tab.c"
    break;

  case 250: /* colormap_definition_simple: CLEAR  */
#line 925 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 4761 "src-generated/ugbc.tab.c"
    break;

  case 251: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 928 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4769 "src-generated/ugbc.tab.c"
    break;

  case 252: /* colormap_definition_expression: AT expr  */
#line 933 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4777 "src-generated/ugbc.tab.c"
    break;

  case 253: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 936 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4785 "src-generated/ugbc.tab.c"
    break;

  case 256: /* screen_definition_simple: ON  */
#line 946 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 4793 "src-generated/ugbc.tab.c"
    break;

  case 257: /* screen_definition_simple: OFF  */
#line 949 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 4801 "src-generated/ugbc.tab.c"
    break;

  case 258: /* screen_definition_simple: ROWS direct_integer  */
#line 952 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 4809 "src-generated/ugbc.tab.c"
    break;

  case 259: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 955 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4817 "src-generated/ugbc.tab.c"
    break;

  case 260: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 958 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4825 "src-generated/ugbc.tab.c"
    break;

  case 261: /* screen_definition_expression: ROWS expr  */
#line 963 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 4833 "src-generated/ugbc.tab.c"
    break;

  case 262: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 966 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4841 "src-generated/ugbc.tab.c"
    break;

  case 263: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 969 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4849 "src-generated/ugbc.tab.c"
    break;

  case 267: /* var_definition_simple: Identifier ON Identifier  */
#line 978 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 4857 "src-generated/ugbc.tab.c"
    break;

  case 268: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 981 "src/ugbc.y"
                                    {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 4865 "src-generated/ugbc.tab.c"
    break;

  case 269: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 984 "src/ugbc.y"
                                                   {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 4873 "src-generated/ugbc.tab.c"
    break;

  case 270: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 987 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 4883 "src-generated/ugbc.tab.c"
    break;

  case 271: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 992 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 4893 "src-generated/ugbc.tab.c"
    break;

  case 272: /* goto_definition: Identifier  */
#line 999 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 4901 "src-generated/ugbc.tab.c"
    break;

  case 273: /* goto_definition: Integer  */
#line 1002 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 4909 "src-generated/ugbc.tab.c"
    break;

  case 274: /* gosub_definition: Identifier  */
#line 1008 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 4917 "src-generated/ugbc.tab.c"
    break;

  case 275: /* gosub_definition: Integer  */
#line 1011 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 4925 "src-generated/ugbc.tab.c"
    break;

  case 277: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 1020 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 4933 "src-generated/ugbc.tab.c"
    break;

  case 278: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 1026 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 4941 "src-generated/ugbc.tab.c"
    break;

  case 281: /* ink_definition: expr  */
#line 1035 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 4949 "src-generated/ugbc.tab.c"
    break;

  case 282: /* on_goto_definition: Identifier  */
#line 1040 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 4958 "src-generated/ugbc.tab.c"
    break;

  case 283: /* $@4: %empty  */
#line 1044 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 4966 "src-generated/ugbc.tab.c"
    break;

  case 285: /* on_gosub_definition: Identifier  */
#line 1049 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 4975 "src-generated/ugbc.tab.c"
    break;

  case 286: /* $@5: %empty  */
#line 1053 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 4983 "src-generated/ugbc.tab.c"
    break;

  case 288: /* on_proc_definition: Identifier  */
#line 1058 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 4992 "src-generated/ugbc.tab.c"
    break;

  case 289: /* $@6: %empty  */
#line 1062 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 5000 "src-generated/ugbc.tab.c"
    break;

  case 291: /* $@7: %empty  */
#line 1067 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 5008 "src-generated/ugbc.tab.c"
    break;

  case 293: /* $@8: %empty  */
#line 1070 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 5016 "src-generated/ugbc.tab.c"
    break;

  case 295: /* $@9: %empty  */
#line 1073 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 5024 "src-generated/ugbc.tab.c"
    break;

  case 297: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1078 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 5032 "src-generated/ugbc.tab.c"
    break;

  case 298: /* every_definition: ON  */
#line 1081 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 5040 "src-generated/ugbc.tab.c"
    break;

  case 299: /* every_definition: OFF  */
#line 1084 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 5048 "src-generated/ugbc.tab.c"
    break;

  case 300: /* add_definition: Identifier COMMA expr  */
#line 1089 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 5056 "src-generated/ugbc.tab.c"
    break;

  case 301: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 1092 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5064 "src-generated/ugbc.tab.c"
    break;

  case 302: /* dimensions: Integer  */
#line 1098 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 5073 "src-generated/ugbc.tab.c"
    break;

  case 303: /* dimensions: Integer COMMA dimensions  */
#line 1102 "src/ugbc.y"
                               {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 5082 "src-generated/ugbc.tab.c"
    break;

  case 304: /* datatype: BYTE  */
#line 1109 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 5090 "src-generated/ugbc.tab.c"
    break;

  case 305: /* datatype: SIGNED BYTE  */
#line 1112 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 5098 "src-generated/ugbc.tab.c"
    break;

  case 306: /* datatype: WORD  */
#line 1115 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 5106 "src-generated/ugbc.tab.c"
    break;

  case 307: /* datatype: SIGNED WORD  */
#line 1118 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 5114 "src-generated/ugbc.tab.c"
    break;

  case 308: /* datatype: DWORD  */
#line 1121 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 5122 "src-generated/ugbc.tab.c"
    break;

  case 309: /* datatype: SIGNED DWORD  */
#line 1124 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 5130 "src-generated/ugbc.tab.c"
    break;

  case 310: /* datatype: ADDRESS  */
#line 1127 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 5138 "src-generated/ugbc.tab.c"
    break;

  case 311: /* datatype: POSITION  */
#line 1130 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 5146 "src-generated/ugbc.tab.c"
    break;

  case 312: /* datatype: COLOR  */
#line 1133 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 5154 "src-generated/ugbc.tab.c"
    break;

  case 313: /* datatype: STRING  */
#line 1136 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 5162 "src-generated/ugbc.tab.c"
    break;

  case 314: /* $@10: %empty  */
#line 1141 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5171 "src-generated/ugbc.tab.c"
    break;

  case 315: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1144 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 5181 "src-generated/ugbc.tab.c"
    break;

  case 316: /* $@11: %empty  */
#line 1149 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5190 "src-generated/ugbc.tab.c"
    break;

  case 317: /* dim_definition: Identifier $@11 DOLLAR OP dimensions CP  */
#line 1152 "src/ugbc.y"
                                {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 5200 "src-generated/ugbc.tab.c"
    break;

  case 318: /* $@12: %empty  */
#line 1157 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5209 "src-generated/ugbc.tab.c"
    break;

  case 319: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1160 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 5219 "src-generated/ugbc.tab.c"
    break;

  case 322: /* indexes: expr  */
#line 1173 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5228 "src-generated/ugbc.tab.c"
    break;

  case 323: /* indexes: expr COMMA indexes  */
#line 1177 "src/ugbc.y"
                         {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5237 "src-generated/ugbc.tab.c"
    break;

  case 324: /* parameters: Identifier  */
#line 1184 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5247 "src-generated/ugbc.tab.c"
    break;

  case 325: /* parameters: Identifier DOLLAR  */
#line 1189 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5257 "src-generated/ugbc.tab.c"
    break;

  case 326: /* parameters: Identifier AS datatype  */
#line 1194 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5267 "src-generated/ugbc.tab.c"
    break;

  case 327: /* parameters: Identifier COMMA parameters  */
#line 1199 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5277 "src-generated/ugbc.tab.c"
    break;

  case 328: /* parameters: Identifier DOLLAR COMMA parameters  */
#line 1204 "src/ugbc.y"
                                         {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5287 "src-generated/ugbc.tab.c"
    break;

  case 329: /* parameters: Identifier AS datatype COMMA parameters  */
#line 1209 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5297 "src-generated/ugbc.tab.c"
    break;

  case 330: /* parameters_expr: Identifier  */
#line 1217 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5307 "src-generated/ugbc.tab.c"
    break;

  case 331: /* parameters_expr: Identifier DOLLAR  */
#line 1222 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5317 "src-generated/ugbc.tab.c"
    break;

  case 332: /* parameters_expr: Identifier AS datatype  */
#line 1227 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5327 "src-generated/ugbc.tab.c"
    break;

  case 333: /* parameters_expr: Identifier COMMA parameters_expr  */
#line 1232 "src/ugbc.y"
                                       {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5337 "src-generated/ugbc.tab.c"
    break;

  case 334: /* parameters_expr: Identifier DOLLAR COMMA parameters_expr  */
#line 1237 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5347 "src-generated/ugbc.tab.c"
    break;

  case 335: /* parameters_expr: Identifier AS datatype COMMA parameters_expr  */
#line 1242 "src/ugbc.y"
                                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5357 "src-generated/ugbc.tab.c"
    break;

  case 336: /* parameters_expr: String  */
#line 1247 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5366 "src-generated/ugbc.tab.c"
    break;

  case 337: /* parameters_expr: String COMMA parameters_expr  */
#line 1251 "src/ugbc.y"
                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5375 "src-generated/ugbc.tab.c"
    break;

  case 338: /* values: expr  */
#line 1258 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5384 "src-generated/ugbc.tab.c"
    break;

  case 339: /* values: expr COMMA values  */
#line 1262 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5393 "src-generated/ugbc.tab.c"
    break;

  case 340: /* print_definition: expr  */
#line 1269 "src/ugbc.y"
         {
        print( _environment, (yyvsp[0].string), 1 );
    }
#line 5401 "src-generated/ugbc.tab.c"
    break;

  case 341: /* print_definition: expr COMMA  */
#line 1272 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5410 "src-generated/ugbc.tab.c"
    break;

  case 342: /* print_definition: expr SEMICOLON  */
#line 1276 "src/ugbc.y"
                   {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5418 "src-generated/ugbc.tab.c"
    break;

  case 343: /* $@13: %empty  */
#line 1279 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5427 "src-generated/ugbc.tab.c"
    break;

  case 345: /* $@14: %empty  */
#line 1283 "src/ugbc.y"
                    {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5435 "src-generated/ugbc.tab.c"
    break;

  case 347: /* use_definition: ANSI  */
#line 1289 "src/ugbc.y"
         {
        use_ansi( _environment );
    }
#line 5443 "src-generated/ugbc.tab.c"
    break;

  case 348: /* use_definition: SPECIFIC  */
#line 1292 "src/ugbc.y"
             {
        use_specific( _environment );
  }
#line 5451 "src-generated/ugbc.tab.c"
    break;

  case 349: /* writing_mode_definition: REPLACE  */
#line 1298 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing REPLACE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_REPLACE );
    }
#line 5460 "src-generated/ugbc.tab.c"
    break;

  case 350: /* writing_mode_definition: OR  */
#line 1302 "src/ugbc.y"
         {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing OR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_OR );
    }
#line 5469 "src-generated/ugbc.tab.c"
    break;

  case 351: /* writing_mode_definition: XOR  */
#line 1306 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing XOR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_XOR );
    }
#line 5478 "src-generated/ugbc.tab.c"
    break;

  case 352: /* writing_mode_definition: AND  */
#line 1310 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing AND)" )->name;
          variable_store( _environment, (yyval.string), WRITING_AND );
    }
#line 5487 "src-generated/ugbc.tab.c"
    break;

  case 353: /* writing_mode_definition: IGNORE  */
#line 1314 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing IGNORE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_IGNORE );
    }
#line 5496 "src-generated/ugbc.tab.c"
    break;

  case 354: /* writing_part_definition: NORMAL  */
#line 1321 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing NORMAL)" )->name;
          variable_store( _environment, (yyval.string), WRITING_NORMAL );
    }
#line 5505 "src-generated/ugbc.tab.c"
    break;

  case 355: /* writing_part_definition: PAPER  */
#line 1325 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5514 "src-generated/ugbc.tab.c"
    break;

  case 356: /* writing_part_definition: PAPER ONLY  */
#line 1329 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5523 "src-generated/ugbc.tab.c"
    break;

  case 357: /* writing_part_definition: PEN  */
#line 1333 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5532 "src-generated/ugbc.tab.c"
    break;

  case 358: /* writing_part_definition: PEN ONLY  */
#line 1337 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5541 "src-generated/ugbc.tab.c"
    break;

  case 359: /* writing_definition: writing_mode_definition COMMA writing_part_definition  */
#line 1344 "src/ugbc.y"
                                                          {
        text_writing( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5549 "src-generated/ugbc.tab.c"
    break;

  case 360: /* locate_definition: COMMA expr  */
#line 1350 "src/ugbc.y"
                {
        text_locate( _environment, NULL, (yyvsp[0].string) );
    }
#line 5557 "src-generated/ugbc.tab.c"
    break;

  case 361: /* locate_definition: expr COMMA  */
#line 1353 "src/ugbc.y"
                 {
        text_locate( _environment, (yyvsp[-1].string), NULL );
    }
#line 5565 "src-generated/ugbc.tab.c"
    break;

  case 362: /* locate_definition: expr COMMA expr  */
#line 1356 "src/ugbc.y"
                      {
        text_locate( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5573 "src-generated/ugbc.tab.c"
    break;

  case 363: /* cmove_definition: COMMA expr  */
#line 1362 "src/ugbc.y"
                {
        text_cmove( _environment, NULL, (yyvsp[0].string) );
    }
#line 5581 "src-generated/ugbc.tab.c"
    break;

  case 364: /* cmove_definition: expr COMMA  */
#line 1365 "src/ugbc.y"
                 {
        text_cmove( _environment, (yyvsp[-1].string), NULL );
    }
#line 5589 "src-generated/ugbc.tab.c"
    break;

  case 365: /* cmove_definition: expr COMMA expr  */
#line 1368 "src/ugbc.y"
                      {
        text_cmove( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5597 "src-generated/ugbc.tab.c"
    break;

  case 366: /* hscroll_definition: LEFT  */
#line 1374 "src/ugbc.y"
         {
        text_hscroll_line( _environment, -1 );
    }
#line 5605 "src-generated/ugbc.tab.c"
    break;

  case 367: /* hscroll_definition: SCREEN LEFT  */
#line 1377 "src/ugbc.y"
                  {
        text_hscroll_screen( _environment, -1 );
    }
#line 5613 "src-generated/ugbc.tab.c"
    break;

  case 368: /* hscroll_definition: RIGHT  */
#line 1380 "src/ugbc.y"
            {
        text_hscroll_line( _environment, 1 );
    }
#line 5621 "src-generated/ugbc.tab.c"
    break;

  case 369: /* hscroll_definition: SCREEN RIGHT  */
#line 1383 "src/ugbc.y"
                   {
        text_hscroll_screen( _environment, 1 );
    }
#line 5629 "src-generated/ugbc.tab.c"
    break;

  case 370: /* vscroll_definition: SCREEN UP  */
#line 1389 "src/ugbc.y"
                {
        text_vscroll_screen( _environment, -1 );
    }
#line 5637 "src-generated/ugbc.tab.c"
    break;

  case 371: /* vscroll_definition: SCREEN DOWN  */
#line 1392 "src/ugbc.y"
                  {
        text_vscroll_screen( _environment, 1 );
    }
#line 5645 "src-generated/ugbc.tab.c"
    break;

  case 390: /* statement: MEMORIZE  */
#line 1416 "src/ugbc.y"
             {
      text_memorize( _environment );
  }
#line 5653 "src-generated/ugbc.tab.c"
    break;

  case 391: /* statement: REMEMBER  */
#line 1419 "src/ugbc.y"
             {
      text_remember( _environment );
  }
#line 5661 "src-generated/ugbc.tab.c"
    break;

  case 395: /* statement: CUP  */
#line 1425 "src/ugbc.y"
        {
      text_cmove_direct( _environment, 0, -1 );
  }
#line 5669 "src-generated/ugbc.tab.c"
    break;

  case 396: /* statement: CDOWN  */
#line 1428 "src/ugbc.y"
          {
      text_cmove_direct( _environment, 0, 1 );
  }
#line 5677 "src-generated/ugbc.tab.c"
    break;

  case 397: /* statement: CLEFT  */
#line 1431 "src/ugbc.y"
          {
      text_cmove_direct( _environment, -1, 0 );
  }
#line 5685 "src-generated/ugbc.tab.c"
    break;

  case 398: /* statement: CRIGHT  */
#line 1434 "src/ugbc.y"
           {
      text_cmove_direct( _environment, 1, 0 );
  }
#line 5693 "src-generated/ugbc.tab.c"
    break;

  case 399: /* statement: CLINE  */
#line 1437 "src/ugbc.y"
          {
      text_cline( _environment, NULL );
  }
#line 5701 "src-generated/ugbc.tab.c"
    break;

  case 400: /* statement: CLINE expr  */
#line 1440 "src/ugbc.y"
               {
      text_cline( _environment, (yyvsp[0].string) );
  }
#line 5709 "src-generated/ugbc.tab.c"
    break;

  case 401: /* statement: SET TAB expr  */
#line 1443 "src/ugbc.y"
                 {
      text_set_tab( _environment, (yyvsp[0].string) );
  }
#line 5717 "src-generated/ugbc.tab.c"
    break;

  case 402: /* statement: CENTER expr  */
#line 1446 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 5725 "src-generated/ugbc.tab.c"
    break;

  case 403: /* statement: CENTRE expr  */
#line 1449 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 5733 "src-generated/ugbc.tab.c"
    break;

  case 404: /* statement: CLS  */
#line 1452 "src/ugbc.y"
        {
      text_cls( _environment );
  }
#line 5741 "src-generated/ugbc.tab.c"
    break;

  case 405: /* statement: HOME  */
#line 1455 "src/ugbc.y"
         {
      text_home( _environment );
  }
#line 5749 "src-generated/ugbc.tab.c"
    break;

  case 406: /* statement: INC Identifier  */
#line 1458 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 5757 "src-generated/ugbc.tab.c"
    break;

  case 407: /* statement: DEC Identifier  */
#line 1461 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 5765 "src-generated/ugbc.tab.c"
    break;

  case 408: /* statement: RANDOMIZE  */
#line 1464 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 5773 "src-generated/ugbc.tab.c"
    break;

  case 409: /* statement: RANDOMIZE expr  */
#line 1467 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 5781 "src-generated/ugbc.tab.c"
    break;

  case 410: /* statement: IF expr THEN  */
#line 1470 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5789 "src-generated/ugbc.tab.c"
    break;

  case 411: /* statement: ELSE  */
#line 1473 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 5797 "src-generated/ugbc.tab.c"
    break;

  case 412: /* statement: ELSE IF expr THEN  */
#line 1476 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5805 "src-generated/ugbc.tab.c"
    break;

  case 413: /* statement: ENDIF  */
#line 1479 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 5813 "src-generated/ugbc.tab.c"
    break;

  case 414: /* statement: DO  */
#line 1482 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 5821 "src-generated/ugbc.tab.c"
    break;

  case 415: /* statement: LOOP  */
#line 1485 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 5829 "src-generated/ugbc.tab.c"
    break;

  case 416: /* $@15: %empty  */
#line 1488 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 5837 "src-generated/ugbc.tab.c"
    break;

  case 417: /* statement: WHILE $@15 expr  */
#line 1490 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 5845 "src-generated/ugbc.tab.c"
    break;

  case 418: /* statement: WEND  */
#line 1493 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 5853 "src-generated/ugbc.tab.c"
    break;

  case 419: /* statement: REPEAT  */
#line 1496 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 5861 "src-generated/ugbc.tab.c"
    break;

  case 420: /* statement: UNTIL expr  */
#line 1499 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 5869 "src-generated/ugbc.tab.c"
    break;

  case 421: /* statement: EXIT  */
#line 1502 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 5877 "src-generated/ugbc.tab.c"
    break;

  case 422: /* statement: EXIT PROC  */
#line 1505 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 5885 "src-generated/ugbc.tab.c"
    break;

  case 423: /* statement: POP PROC  */
#line 1508 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 5893 "src-generated/ugbc.tab.c"
    break;

  case 424: /* statement: EXIT IF expr  */
#line 1511 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 5901 "src-generated/ugbc.tab.c"
    break;

  case 425: /* statement: EXIT Integer  */
#line 1514 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5909 "src-generated/ugbc.tab.c"
    break;

  case 426: /* statement: EXIT direct_integer  */
#line 1517 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5917 "src-generated/ugbc.tab.c"
    break;

  case 427: /* statement: EXIT IF expr COMMA Integer  */
#line 1520 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5925 "src-generated/ugbc.tab.c"
    break;

  case 428: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1523 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5933 "src-generated/ugbc.tab.c"
    break;

  case 429: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1526 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5941 "src-generated/ugbc.tab.c"
    break;

  case 430: /* statement: NEXT  */
#line 1529 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 5949 "src-generated/ugbc.tab.c"
    break;

  case 431: /* statement: PROCEDURE Identifier  */
#line 1532 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 5958 "src-generated/ugbc.tab.c"
    break;

  case 432: /* $@16: %empty  */
#line 1536 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5966 "src-generated/ugbc.tab.c"
    break;

  case 433: /* statement: PROCEDURE Identifier $@16 OSP parameters CSP  */
#line 1538 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5974 "src-generated/ugbc.tab.c"
    break;

  case 434: /* statement: SHARED parameters_expr  */
#line 1541 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 5982 "src-generated/ugbc.tab.c"
    break;

  case 435: /* statement: GLOBAL parameters_expr  */
#line 1544 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 5990 "src-generated/ugbc.tab.c"
    break;

  case 436: /* statement: END PROC  */
#line 1547 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 5998 "src-generated/ugbc.tab.c"
    break;

  case 437: /* statement: END PROC OSP expr CSP  */
#line 1550 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 6006 "src-generated/ugbc.tab.c"
    break;

  case 438: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1553 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 6014 "src-generated/ugbc.tab.c"
    break;

  case 439: /* statement: Identifier " "  */
#line 1556 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 6023 "src-generated/ugbc.tab.c"
    break;

  case 440: /* statement: PROC Identifier  */
#line 1560 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 6032 "src-generated/ugbc.tab.c"
    break;

  case 441: /* statement: CALL Identifier  */
#line 1564 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 6041 "src-generated/ugbc.tab.c"
    break;

  case 442: /* $@17: %empty  */
#line 1568 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6049 "src-generated/ugbc.tab.c"
    break;

  case 443: /* statement: Identifier OSP $@17 values CSP  */
#line 1570 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6057 "src-generated/ugbc.tab.c"
    break;

  case 444: /* $@18: %empty  */
#line 1573 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6065 "src-generated/ugbc.tab.c"
    break;

  case 445: /* statement: PROC Identifier OSP $@18 values CSP  */
#line 1575 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6073 "src-generated/ugbc.tab.c"
    break;

  case 446: /* $@19: %empty  */
#line 1578 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6081 "src-generated/ugbc.tab.c"
    break;

  case 447: /* statement: CALL Identifier OSP $@19 values CSP  */
#line 1580 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6089 "src-generated/ugbc.tab.c"
    break;

  case 448: /* statement: PEN expr  */
#line 1583 "src/ugbc.y"
             {
      text_pen( _environment, (yyvsp[0].string) );
  }
#line 6097 "src-generated/ugbc.tab.c"
    break;

  case 449: /* statement: PAPER expr  */
#line 1586 "src/ugbc.y"
               {
      text_paper( _environment, (yyvsp[0].string) );
  }
#line 6105 "src-generated/ugbc.tab.c"
    break;

  case 450: /* statement: INVERSE ON  */
#line 1589 "src/ugbc.y"
               {
      text_inverse( _environment, 1 );
  }
#line 6113 "src-generated/ugbc.tab.c"
    break;

  case 451: /* statement: INVERSE OFF  */
#line 1592 "src/ugbc.y"
                {
      text_inverse( _environment, 0 );
  }
#line 6121 "src-generated/ugbc.tab.c"
    break;

  case 453: /* statement: Identifier COLON  */
#line 1596 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 6129 "src-generated/ugbc.tab.c"
    break;

  case 454: /* statement: BEG GAMELOOP  */
#line 1599 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 6137 "src-generated/ugbc.tab.c"
    break;

  case 455: /* statement: END GAMELOOP  */
#line 1602 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 6145 "src-generated/ugbc.tab.c"
    break;

  case 456: /* statement: GRAPHIC  */
#line 1605 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 6153 "src-generated/ugbc.tab.c"
    break;

  case 457: /* statement: HALT  */
#line 1608 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 6161 "src-generated/ugbc.tab.c"
    break;

  case 458: /* statement: END  */
#line 1611 "src/ugbc.y"
        {
      end( _environment );
  }
#line 6169 "src-generated/ugbc.tab.c"
    break;

  case 463: /* statement: RETURN  */
#line 1618 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 6177 "src-generated/ugbc.tab.c"
    break;

  case 464: /* statement: RETURN expr  */
#line 1621 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 6185 "src-generated/ugbc.tab.c"
    break;

  case 465: /* statement: POP  */
#line 1624 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 6193 "src-generated/ugbc.tab.c"
    break;

  case 466: /* statement: DONE  */
#line 1627 "src/ugbc.y"
          {
      return 0;
  }
#line 6201 "src-generated/ugbc.tab.c"
    break;

  case 467: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1630 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6209 "src-generated/ugbc.tab.c"
    break;

  case 468: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1633 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6217 "src-generated/ugbc.tab.c"
    break;

  case 469: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1636 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 6225 "src-generated/ugbc.tab.c"
    break;

  case 470: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1639 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6233 "src-generated/ugbc.tab.c"
    break;

  case 473: /* statement: Identifier ASSIGN expr  */
#line 1644 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 6247 "src-generated/ugbc.tab.c"
    break;

  case 474: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1653 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 6261 "src-generated/ugbc.tab.c"
    break;

  case 475: /* $@20: %empty  */
#line 1662 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6270 "src-generated/ugbc.tab.c"
    break;

  case 476: /* statement: Identifier $@20 OP indexes CP ASSIGN expr  */
#line 1666 "src/ugbc.y"
                                {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 6283 "src-generated/ugbc.tab.c"
    break;

  case 477: /* $@21: %empty  */
#line 1674 "src/ugbc.y"
                      {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6292 "src-generated/ugbc.tab.c"
    break;

  case 478: /* statement: Identifier DOLLAR $@21 OP indexes CP ASSIGN expr  */
#line 1677 "src/ugbc.y"
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
#line 6311 "src-generated/ugbc.tab.c"
    break;

  case 479: /* $@22: %empty  */
#line 1691 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6320 "src-generated/ugbc.tab.c"
    break;

  case 480: /* statement: Identifier $@22 datatype OP indexes CP ASSIGN expr  */
#line 1694 "src/ugbc.y"
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
#line 6339 "src-generated/ugbc.tab.c"
    break;

  case 481: /* statement: DEBUG expr  */
#line 1708 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 6347 "src-generated/ugbc.tab.c"
    break;

  case 484: /* statements_no_linenumbers: statement  */
#line 1716 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 6353 "src-generated/ugbc.tab.c"
    break;

  case 485: /* $@23: %empty  */
#line 1717 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 6359 "src-generated/ugbc.tab.c"
    break;

  case 487: /* $@24: %empty  */
#line 1721 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 6367 "src-generated/ugbc.tab.c"
    break;

  case 488: /* statements_with_linenumbers: Integer $@24 statements_no_linenumbers  */
#line 1723 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 6375 "src-generated/ugbc.tab.c"
    break;

  case 489: /* $@25: %empty  */
#line 1728 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 6383 "src-generated/ugbc.tab.c"
    break;

  case 495: /* $@26: %empty  */
#line 1738 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 6389 "src-generated/ugbc.tab.c"
    break;


#line 6393 "src-generated/ugbc.tab.c"

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

#line 1740 "src/ugbc.y"


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

