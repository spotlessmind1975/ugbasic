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
  YYSYMBOL_writing_mode_definition = 300,  /* writing_mode_definition  */
  YYSYMBOL_writing_part_definition = 301,  /* writing_part_definition  */
  YYSYMBOL_writing_definition = 302,       /* writing_definition  */
  YYSYMBOL_locate_definition = 303,        /* locate_definition  */
  YYSYMBOL_cmove_definition = 304,         /* cmove_definition  */
  YYSYMBOL_hscroll_definition = 305,       /* hscroll_definition  */
  YYSYMBOL_vscroll_definition = 306,       /* vscroll_definition  */
  YYSYMBOL_statement = 307,                /* statement  */
  YYSYMBOL_308_15 = 308,                   /* $@15  */
  YYSYMBOL_309_16 = 309,                   /* $@16  */
  YYSYMBOL_310_17 = 310,                   /* $@17  */
  YYSYMBOL_311_18 = 311,                   /* $@18  */
  YYSYMBOL_312_19 = 312,                   /* $@19  */
  YYSYMBOL_313_20 = 313,                   /* $@20  */
  YYSYMBOL_314_21 = 314,                   /* $@21  */
  YYSYMBOL_315_22 = 315,                   /* $@22  */
  YYSYMBOL_statements_no_linenumbers = 316, /* statements_no_linenumbers  */
  YYSYMBOL_317_23 = 317,                   /* $@23  */
  YYSYMBOL_statements_with_linenumbers = 318, /* statements_with_linenumbers  */
  YYSYMBOL_319_24 = 319,                   /* $@24  */
  YYSYMBOL_statements_complex = 320,       /* statements_complex  */
  YYSYMBOL_321_25 = 321,                   /* $@25  */
  YYSYMBOL_program = 322,                  /* program  */
  YYSYMBOL_323_26 = 323                    /* $@26  */
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
#define YYLAST   3207

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  214
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  110
/* YYNRULES -- Number of rules.  */
#define YYNRULES  496
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  953

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
     544,   547,   550,   553,   556,   559,   562,   567,   567,   570,
     573,   576,   579,   582,   585,   589,   592,   595,   598,   602,
     605,   608,   611,   615,   618,   621,   624,   630,   633,   636,
     639,   642,   647,   648,   651,   654,   659,   662,   667,   668,
     671,   674,   679,   682,   687,   688,   691,   694,   697,   702,
     705,   708,   713,   714,   717,   718,   719,   722,   725,   728,
     733,   736,   739,   745,   746,   749,   752,   755,   758,   761,
     764,   767,   770,   773,   776,   779,   782,   785,   788,   791,
     796,   799,   802,   805,   808,   811,   814,   817,   820,   823,
     826,   829,   832,   835,   838,   843,   844,   847,   850,   853,
     856,   859,   865,   868,   874,   875,   878,   883,   888,   889,
     892,   895,   900,   903,   908,   909,   912,   917,   922,   923,
     926,   929,   932,   937,   940,   946,   947,   950,   953,   956,
     959,   962,   967,   970,   973,   978,   979,   981,   982,   985,
     988,   991,   996,  1003,  1006,  1012,  1015,  1021,  1024,  1030,
    1035,  1036,  1039,  1044,  1048,  1048,  1053,  1057,  1057,  1062,
    1066,  1066,  1071,  1071,  1074,  1074,  1077,  1077,  1082,  1085,
    1088,  1093,  1096,  1102,  1106,  1113,  1116,  1119,  1122,  1125,
    1128,  1131,  1134,  1137,  1140,  1145,  1145,  1153,  1153,  1161,
    1161,  1172,  1173,  1177,  1181,  1188,  1193,  1198,  1203,  1208,
    1213,  1221,  1226,  1231,  1236,  1241,  1246,  1251,  1255,  1262,
    1266,  1273,  1276,  1280,  1283,  1283,  1287,  1287,  1293,  1297,
    1301,  1305,  1309,  1316,  1320,  1324,  1328,  1332,  1339,  1345,
    1348,  1351,  1357,  1360,  1363,  1369,  1372,  1375,  1378,  1384,
    1387,  1393,  1394,  1395,  1396,  1397,  1398,  1399,  1400,  1401,
    1402,  1403,  1404,  1405,  1406,  1407,  1408,  1411,  1412,  1413,
    1414,  1415,  1418,  1421,  1422,  1423,  1424,  1427,  1430,  1433,
    1436,  1439,  1442,  1445,  1448,  1451,  1454,  1457,  1460,  1463,
    1466,  1469,  1472,  1475,  1478,  1481,  1484,  1487,  1487,  1492,
    1495,  1498,  1501,  1504,  1507,  1510,  1513,  1516,  1519,  1522,
    1525,  1528,  1531,  1535,  1535,  1540,  1543,  1546,  1549,  1552,
    1555,  1559,  1563,  1567,  1567,  1572,  1572,  1577,  1577,  1582,
    1585,  1588,  1591,  1594,  1595,  1598,  1601,  1604,  1607,  1610,
    1613,  1614,  1615,  1616,  1617,  1620,  1623,  1626,  1629,  1632,
    1635,  1638,  1641,  1642,  1651,  1660,  1660,  1672,  1672,  1689,
    1689,  1706,  1709,  1710,  1714,  1715,  1715,  1719,  1719,  1726,
    1726,  1729,  1730,  1731,  1732,  1736,  1736
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
  "TEXTADDRESS", "BLACK", "WHITE", "RED", "CYAN", "VIOLET", "GREEN",
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
     465,   466,   467,   468
};
#endif

#define YYPACT_NINF (-831)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-476)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -831,    65,   916,  -831,  -831,  -137,  -120,  2613,   -19,  -831,
      35,  2218,    94,     7,  2218,  -831,    51,   190,  2613,   -73,
     -59,  -831,  -831,  -831,  1836,   120,    12,  2613,  2613,    57,
     -37,  -831,   124,   137,  2613,  2613,  -831,   153,   158,   -16,
    2613,    63,   156,  -831,   -33,  -831,  2613,    19,  2027,   217,
      52,  2613,    69,    83,    86,    95,    38,    38,  2613,  2613,
     207,    76,  1248,  -831,  -831,  1454,  2613,  2613,    98,  -831,
    -831,  -831,  -831,  2613,  -831,  -831,     6,   235,   268,    10,
    -831,   277,   302,   303,  -831,  -831,  -831,    96,   289,  1645,
    -831,  -831,   279,   280,   281,   189,  -831,  -831,   -10,   283,
     284,  2613,  -831,  -831,   285,   295,   301,   304,   305,   306,
     307,   308,   309,   310,   311,   314,   334,   335,   336,   337,
     338,  -831,  -831,   339,    64,   -40,    -5,   291,   317,   318,
     356,   357,   358,   361,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,   193,  -831,  -831,    54,  -116,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,   194,    18,
    -831,  -831,   192,   172,   181,   203,   252,  -831,  -831,  -831,
    2218,   359,  -831,  -831,  -831,  2218,  2218,  2218,  -831,  -831,
    -831,   171,    50,    61,  -831,  -831,  -831,   -12,   312,    -3,
      -1,     0,     1,   362,  -831,  -831,  -831,   342,   380,  -831,
    -831,  -831,  2218,  -831,  -831,   360,  -831,  -831,  -831,  -831,
    -831,  2218,   344,   345,  -831,  -831,  -831,   -25,  -831,    36,
    -831,  -831,  -831,  -831,  -831,  2613,  2422,  -831,  -831,   382,
    -831,  -831,  -831,  2218,  -831,  -831,  -831,  2218,   363,  -831,
    -831,  -831,   324,  -831,  -831,  -831,   248,  2613,  2613,  -831,
    -831,  2218,  -831,  -831,  -831,   366,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  2613,  2613,  -831,  -831,  -831,  -831,
     385,  -831,  -831,   249,  -831,  2613,   396,  -831,  -831,  -831,
      49,   397,  -831,   259,   262,   264,    67,   407,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,   408,
    -831,  2613,   409,  -831,  2613,   413,  -831,  -831,  -831,  2613,
    -831,   160,  -831,  -831,  -831,   191,  -831,  2613,  -831,  -831,
    2613,   414,  -831,  -831,   386,    20,  1093,  -831,   916,   916,
    -831,   387,   393,   394,   395,   398,   400,    79,   403,  2218,
    2218,  2218,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,   405,  -831,  -831,  2613,  2613,  -831,  2613,  2613,  2613,
    2613,  2613,  2613,  2613,  2613,  2613,  2613,  2613,  2613,  2613,
    2613,  2613,  2613,  2613,  2804,   406,   222,  -831,  -831,   410,
    -831,  -831,   415,   416,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,   417,  -831,   418,
     263,   276,  2804,  2804,  2804,  2804,  2804,  2804,  2804,  2804,
    2804,  2804,  2804,  2804,  2804,  2995,   412,   419,  2218,  -831,
    -831,   370,   375,   381,   383,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  2218,   430,  -831,  -831,  -831,
     384,   312,   433,   312,   434,   312,   435,   312,   436,   312,
    -831,  2613,   428,  -831,  -831,   230,   232,    26,    77,  -831,
    -831,  -831,   429,   312,   431,  -831,  -831,   234,   241,   116,
     121,  -831,  -831,   439,  -831,  -831,  2218,  -831,  -831,  2218,
    2218,  -831,  -831,  -831,   420,   256,  -831,   461,  2613,  -831,
    -831,  -831,  -831,  2218,  -831,  2613,   464,   468,  -831,  -831,
    2218,   421,   469,  2613,   374,   471,  2613,  -831,  -831,  -831,
    -831,  -831,  -831,   130,  -831,  -831,   444,   460,    69,  -831,
     341,  -831,    38,   475,    20,    38,   -26,  -831,  2613,  -831,
    2613,  -831,  -831,  -831,  -831,  -831,  -831,   916,  -831,  2613,
     448,  2613,  2613,   449,    29,  -831,  1093,  -831,  -831,  2613,
     273,   275,   278,   282,   286,   456,   459,   465,  -831,   467,
     470,   472,   473,   474,   476,  2613,   490,   493,   497,   498,
     477,   478,   479,   480,   500,   481,   482,   484,   486,   488,
     504,   519,   492,   494,   499,    27,   326,   501,  2613,  2613,
    2613,   503,  2613,  2613,  2613,  2613,   181,   181,   292,   292,
     292,   292,   292,   292,   292,   292,   203,   252,   252,  -831,
     329,   330,  -831,  -831,  2613,   312,  2613,   312,   511,   513,
    2218,    71,  -831,   312,  -831,   312,  -831,   312,  -831,   312,
      97,  -831,  2613,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  2613,  -831,   312,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,   312,  -831,  -831,  -831,  -831,  -831,  -831,   340,
     343,   346,   347,   533,  2613,   541,   506,   509,   422,  2613,
    2613,   547,   548,  -831,   -52,   489,   349,  2613,   554,  -831,
    -831,  -831,   530,   354,   532,  -831,  2613,   364,  2613,  -831,
      38,   561,  -831,   404,   423,  -831,  -831,  -831,  -831,  -831,
    -831,  2613,   562,   424,   565,   539,  2613,  -831,   569,  -831,
    -831,  -831,  -831,  -831,   367,   368,   378,  -831,  -831,  -831,
    -831,  -831,  -831,   542,  2613,  2613,  2613,  2613,  -831,  -831,
    -831,  -831,  2613,  -831,  -831,  -831,  -831,  -831,  2613,  2613,
    -831,  -831,  -831,  2995,   550,  -831,   555,   585,   586,  2613,
     445,   559,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
     388,   389,  -831,  -831,  -831,  -831,  -831,  -831,   566,  -831,
     567,  -831,   390,   142,  -831,   593,  -831,   595,   596,  -831,
     597,  -831,   598,  -831,   599,  2218,   601,  2613,  2613,   312,
    -831,   570,   574,  2613,   312,  -831,  -831,  2613,  -831,    56,
    2613,   354,   604,   578,   354,   466,    73,   483,   487,  -831,
      38,  -831,  -831,   580,  2613,  -831,  2613,   605,   581,  2613,
    -831,  -831,  -831,  -831,   583,   584,   104,   107,   587,   588,
     590,   591,  -831,  -831,  2613,  2613,   592,  -831,  -831,  -831,
    -831,   411,   426,  -831,   600,  -831,   603,  -831,  2613,   312,
     614,   622,   624,  2613,  -831,  -831,  2613,  -831,  -831,  -831,
     625,   626,   606,   607,   524,  2613,   628,   571,   609,   354,
    -831,   610,  -831,   364,   640,    20,  -831,  -831,  -831,   635,
    -831,  -831,  2613,   636,   615,  -831,  -831,  2613,  -831,  2613,
    -831,  -831,  -831,  -831,  -831,   616,   617,  -831,  -831,  -831,
     443,   447,   619,   620,   340,   343,   346,  -831,  -831,  2613,
    2613,  -831,  -831,  2613,   623,  2613,  2613,  -831,  -831,  -831,
    -831,   364,   643,  2613,  -831,  2613,  -831,   629,   630,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,   647,  -831,  -831,  -831,   364,  -831,  -831,  -831,  -831,
    2613,  -831,  -831
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     495,     0,   483,     1,   482,     0,     0,     0,     0,   467,
       0,     0,   431,     0,     0,   458,     0,     0,     0,   267,
       0,   416,   420,   417,     0,     0,     0,     0,     0,     0,
     459,   414,     0,     0,     0,   409,   457,     0,     0,     0,
     464,   466,   412,   415,   422,   419,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   405,   406,     0,     0,     0,     0,   396,
     397,   398,   399,   400,   391,   392,     0,     0,     0,   479,
     487,   484,   491,   493,   496,   407,   408,     0,     0,     0,
      79,    80,     0,     0,     0,     0,   121,   122,     0,     0,
       0,     0,   112,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   135,   136,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,    44,
      49,    50,    51,    52,    53,    54,    57,    58,     0,    63,
      67,    65,   341,     2,    12,    15,    17,    76,    20,   389,
       0,     0,   168,   169,   372,     0,     0,     0,   182,   183,
     374,     0,     0,     0,   193,   194,   375,     0,     0,     0,
       0,     0,     0,     0,   162,   163,   371,     0,     0,   225,
     226,   376,     0,   228,   229,   230,   234,   235,   377,   257,
     258,     0,     0,     0,   265,   266,   382,     0,   460,     0,
     277,   385,   273,   274,   461,     0,     0,   240,   241,     0,
     244,   245,   379,     0,   248,   249,   380,     0,   251,   255,
     256,   381,     0,   449,   455,   456,   437,     0,     0,   481,
     410,     0,   238,   239,   378,     0,   280,   281,   383,   275,
     276,   462,   465,   424,     0,     0,   423,   426,   427,   421,
       0,   299,   300,     0,   463,     0,     0,   387,   282,   384,
     315,   321,   472,   441,   432,   442,   331,   337,   435,   436,
     388,   450,   451,   452,   351,   349,   348,   350,   352,     0,
     453,     0,     0,   390,     0,     0,   395,   403,   404,     0,
     401,     0,   365,   367,   393,     0,   394,     0,   489,   454,
       0,   477,   443,   440,     0,     0,   483,   485,   483,   483,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    28,    24,    25,    27,    29,    30,    26,    31,
     101,     0,   115,   116,     0,     0,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   117,   120,     0,
     118,   119,     0,     0,   133,   127,   128,   129,   130,    55,
      42,    45,    46,    47,    48,    43,    56,    64,   108,     0,
     346,   344,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   179,
     176,     0,     0,     0,     0,    23,   184,   190,   185,   186,
     191,   192,   187,   188,   189,     0,     0,   174,   175,   373,
     139,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     138,     0,     0,   215,   216,     0,     0,     0,     0,   212,
     211,   137,     0,     0,     0,   200,   201,     0,     0,     0,
       0,   197,   196,     0,   232,   227,     0,   262,   259,     0,
       0,   292,   296,   294,     0,     0,   418,     0,     0,   247,
     246,   253,   250,     0,   411,     0,     0,     0,   237,   236,
       0,     0,   425,     0,     0,     0,     0,   313,   305,   307,
     312,   309,   314,     0,   311,   319,     0,     0,     0,   445,
       0,   447,     0,   332,     0,     0,     0,   359,   360,   362,
     363,   402,   366,   368,   369,   370,   386,   483,   473,     0,
       0,     0,     0,     0,   479,   488,   483,   492,   494,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    14,     5,     7,
       8,     9,    10,     6,     3,     4,    16,    18,    19,    21,
       0,     0,   166,   164,     0,     0,     0,     0,     0,     0,
       0,     0,   144,     0,   156,     0,   148,     0,   152,     0,
     140,   213,     0,   220,   219,   224,   223,   218,   222,   217,
     221,     0,   198,     0,   205,   204,   209,   208,   203,   207,
     202,   206,     0,   233,   231,   263,   260,   264,   261,     0,
       0,     0,     0,   268,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   413,     0,     0,     0,     0,   301,   306,
     308,   310,     0,     0,     0,   322,     0,     0,     0,   334,
       0,   333,   338,   356,   354,   353,   358,   361,   364,   490,
     474,     0,   339,     0,   323,     0,     0,   486,     0,    75,
      68,    70,    74,    72,     0,     0,     0,    78,    77,    82,
      81,    84,    83,     0,     0,     0,     0,     0,    91,    92,
      93,   100,     0,    94,    95,    96,    97,    98,     0,     0,
     110,   111,   102,     0,     0,   106,     0,     0,     0,     0,
       0,     0,   347,   345,   167,   165,   181,   178,   180,   177,
       0,     0,   172,   170,   141,   154,   146,   149,   143,   155,
     147,   151,     0,     0,   210,     0,   195,     0,   283,   293,
     286,   297,   289,   295,   269,     0,     0,     0,     0,     0,
     438,     0,     0,     0,     0,   428,   429,     0,   298,     0,
       0,     0,   303,     0,     0,     0,   325,     0,     0,   335,
       0,   357,   355,     0,     0,   444,     0,     0,     0,     0,
      69,    71,    73,   124,     0,     0,     0,     0,     0,     0,
       0,     0,   107,   125,     0,     0,     0,   109,    60,   173,
     171,     0,     0,   157,   142,   153,   145,   150,     0,     0,
       0,     0,     0,     0,   271,   270,     0,   243,   254,   252,
       0,     0,     0,     0,   430,     0,     0,     0,     0,     0,
     316,     0,   446,     0,   326,     0,   434,   448,   336,     0,
     340,   324,     0,     0,     0,    85,    86,     0,    87,     0,
      89,    99,   105,   104,    22,     0,     0,    62,   159,   161,
       0,     0,     0,     0,     0,     0,     0,   272,   242,     0,
       0,   279,   278,     0,     0,     0,     0,   320,   304,   318,
     328,     0,   327,     0,   476,     0,   131,     0,     0,   132,
     126,   158,   160,   214,   199,   285,   288,   291,   468,   469,
     439,     0,   470,   302,   329,     0,   478,   480,    88,    90,
       0,   330,   471
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -831,    -7,   -82,   -99,   255,  -304,    84,  -831,  -831,  -831,
    -412,  -831,  -831,  -831,   463,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,   485,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -240,  -831,  -236,  -831,  -235,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -733,  -324,  -831,  -831,  -831,  -831,   154,  -588,
    -830,   -55,  -583,   -50,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -314,  -831,  -831,  -831,  -310,  -831,  -831,  -831
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   704,   163,   164,   165,   166,   183,   349,   350,   167,
     168,   399,   591,   592,   462,   194,   195,   196,   172,   173,
     174,   437,   438,   439,   178,   179,   180,   431,   184,   185,
     186,   199,   200,   201,   206,   207,   208,   252,   253,   254,
     230,   231,   232,   234,   235,   236,   239,   240,   241,   214,
     215,   216,   220,   224,   261,   221,   256,   257,   258,   279,
     779,   850,   781,   851,   783,   852,   218,   659,   661,   660,
     274,   277,   803,   515,   281,   516,   517,   682,   282,   705,
     807,   288,   703,   169,   595,   594,   299,   696,   300,   303,
     306,   314,   316,    81,   225,   520,   541,   686,   688,   324,
     540,   325,    82,   546,    83,   326,    84,   537,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     162,   543,   289,   609,   182,   751,   170,   197,   290,   750,
     351,   217,   545,   435,   318,   379,   319,   229,   547,   548,
     242,   243,   441,   320,   443,   445,   447,   249,   250,   481,
     321,   181,   188,   262,   743,   319,   265,   237,   397,   269,
     189,   273,   320,   920,   278,  -475,   507,   377,   311,   321,
     181,   162,   291,   -59,   245,   302,   484,   190,   305,   307,
     308,   693,   175,   865,  -475,     3,   310,   176,   868,  -317,
     585,   871,   637,    85,   522,   507,   202,   394,   482,   485,
     873,   638,   338,   395,   375,   191,   192,   523,   203,   204,
      86,   944,   866,   874,   356,   508,   509,   510,   198,   376,
     238,   312,   313,   805,   764,   808,   511,   177,   246,   607,
     608,   887,   266,   813,   889,   951,   524,   187,   818,   378,
     483,   765,   875,   639,   508,   509,   510,   772,   268,   352,
     426,   427,   640,   694,   380,   511,   918,   219,   695,   205,
     888,   426,   432,   890,   512,   233,   773,   353,   244,   766,
     767,   222,   381,   223,   555,   556,   513,   415,   322,   247,
     795,   836,   648,   416,   514,   557,   398,   650,   419,   421,
     423,   649,   248,   512,   294,   844,   651,   322,   251,   267,
     402,   403,   295,   255,   404,   513,   405,   406,   407,   408,
     409,   171,   845,   514,   259,   474,   260,   400,   436,   401,
     691,   428,   429,   430,   477,   679,   680,   442,   263,   444,
     446,   448,   428,   429,   433,   342,   681,   193,   486,   487,
     846,   847,   413,   323,   414,   264,   489,   699,   881,   270,
     491,   880,   707,   209,   210,   211,   212,   296,   297,   298,
     496,   497,   323,   390,   498,   213,   391,   392,   286,   287,
     292,   293,   275,   393,   417,   532,   533,   501,   502,   420,
     422,   424,   276,  -343,   343,   344,   345,  -343,   505,  -343,
     410,   309,   440,   346,   347,   348,  -342,   315,   411,   280,
    -342,   317,  -342,   327,   534,   535,   475,   633,   634,   635,
     636,   644,   645,   283,   527,   478,   284,   529,   646,   647,
     402,   403,   531,   596,   597,   285,   328,   329,   330,   331,
     536,   382,   412,   538,   339,   340,   341,   490,   354,   355,
     357,   492,   598,   599,   600,   601,   602,   603,   604,   605,
     358,   831,   559,   561,   563,   499,   359,   383,   384,   360,
     361,   362,   363,   364,   365,   366,   367,   566,   567,   368,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   450,   451,   369,
     370,   371,   372,   373,   374,   452,   385,   386,   387,   453,
     454,   388,   415,   425,   418,   389,   396,   449,   455,   488,
     476,   479,   480,   493,   494,   181,   495,   456,   503,   457,
     458,   500,   504,   506,   518,   450,   463,   519,   459,   460,
    -433,   612,   521,   464,   525,   526,   528,   465,   466,   461,
     530,   542,   549,   560,   562,   564,   467,   539,   618,   550,
     551,   552,   587,   621,   553,   468,   554,   469,   470,   558,
     565,   586,   610,   614,   631,   588,   471,   472,   615,   611,
     589,   590,   -61,   593,   616,   620,   617,   461,   623,   625,
     627,   629,   632,   662,   641,   643,   663,   689,   664,   653,
     692,   669,   655,   657,   652,   670,   674,   676,   677,   683,
     684,   665,   690,   701,   706,   709,   666,   710,   668,   687,
     711,   673,   714,   671,   712,   715,   675,   724,   713,   678,
     725,   716,   613,   717,   726,   727,   718,   732,   719,   720,
     721,   738,   722,   728,   729,   730,   731,   733,   734,   619,
     735,   697,   736,   698,   737,   622,   739,   624,   740,   626,
     741,   628,   700,   630,   702,   742,   744,   745,   749,   754,
     755,   760,   708,   761,   752,   753,   785,   642,   787,   788,
     778,   922,   789,   780,   793,   794,   782,   784,   723,   798,
     654,   800,   797,   656,   658,   801,   802,   804,   810,   814,
     811,   790,   816,   815,   806,   817,   819,   667,   823,   820,
     821,   746,   747,   748,   672,   702,   832,   162,   162,   812,
     822,   833,   834,   835,   837,   838,   841,   842,   839,   840,
     848,   843,   849,  -284,  -287,  -290,   860,   756,   856,   758,
     861,   869,   853,   762,   870,   872,   879,   883,   882,   885,
     886,   904,   898,   891,   892,   774,   893,   894,   897,   905,
     900,   906,   876,   901,   775,   809,   877,   899,   909,   910,
     913,   915,   911,   912,   916,   917,   919,   921,   923,   925,
     945,   926,   929,   930,   931,   933,   934,   786,   932,   941,
     950,   473,   791,   792,   935,   948,   949,   606,   434,   936,
     799,   937,   685,     0,     0,     0,     0,     0,     0,   702,
       0,   702,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   757,
       0,   759,     0,     0,   763,     0,     0,   768,     0,   769,
       0,   770,     0,   771,     0,     0,     0,   824,   825,   826,
     827,     0,     0,     0,     0,   828,     0,   776,     0,     0,
       0,   829,   830,     0,     0,     0,   777,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   878,     0,     0,   796,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   854,     0,
     857,   858,     0,     0,     0,     0,   862,     0,     0,     0,
     864,     0,     0,   867,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   702,     0,     0,
       0,     0,   884,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   895,   896,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   902,     0,     0,     0,     0,   907,     0,     0,   908,
       0,     0,     0,     0,     0,     0,     0,     0,   914,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   855,
       0,     0,     0,   859,     0,   924,     0,     0,   863,     0,
     927,     0,   928,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   938,   939,     0,     0,   940,     0,   942,   943,
       0,     0,     0,     0,     0,     0,   946,     0,   947,     4,
       0,     0,     0,     0,     0,     0,     5,     6,     0,     0,
       0,     0,     0,   903,     0,     0,     0,     0,     7,     8,
       9,     0,    10,   952,    11,    12,     0,    13,    14,     0,
       0,     0,     0,     0,     0,    15,     0,    16,    17,    18,
       0,     0,     0,     0,    19,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,    21,    22,    23,    24,    25,
      26,     0,     0,     0,     0,    27,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,     0,    29,    30,     0,    31,     0,
       0,    32,    33,    34,     0,    35,    36,    37,    38,    39,
      40,    41,     0,    42,     0,     0,     0,    43,    44,    45,
      46,    47,     0,    48,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,     0,
       0,     0,     0,     0,     0,     0,    51,     0,     0,    52,
       0,    53,    54,    55,     0,     0,    56,     0,     0,     0,
      57,     0,    58,     0,     0,    59,    60,     0,     0,     0,
       0,    61,     0,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,    72,    73,     4,     0,    74,    75,
      76,    77,    78,     5,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     9,     0,    10,
       0,    11,    12,     0,    13,    14,    79,     0,    80,     0,
       0,     0,    15,     0,    16,    17,    18,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     0,    20,     0,     0,
       0,     0,    21,    22,    23,    24,    25,    26,     0,     0,
       0,     0,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      28,     0,    29,    30,     0,    31,     0,     0,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,     0,
      42,     0,     0,     0,    43,    44,    45,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,     0,    51,     0,     0,    52,     0,    53,    54,
      55,     0,     0,    56,     0,     0,     0,    57,     0,    58,
       0,     0,    59,    60,     0,   301,     0,    87,    61,     0,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,    72,    73,    88,     0,    74,    75,    76,    77,    78,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,     0,   544,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    93,     0,     0,    94,
       0,     0,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,     0,    98,     0,     0,     0,     0,
       0,     0,     0,    99,   100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,     0,     0,
       0,   116,   117,   118,     0,   119,   120,   121,     0,   122,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,     0,   125,     0,   126,     0,     0,
       0,     0,     0,     0,     0,   127,     0,     0,   128,     0,
       0,   129,     0,   130,   131,   132,   133,     0,   134,   135,
       0,     0,     0,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,     0,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   304,     0,    87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
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
     146,   147,   148,   149,    87,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,     0,     0,     0,
      88,   332,     0,     0,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    93,     0,     0,    94,     0,     0,    95,
     333,   334,   335,     0,     0,     0,     0,     0,     0,    96,
      97,   336,    98,     0,     0,     0,     0,     0,     0,     0,
      99,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,     0,     0,     0,   116,   117,
     118,   337,   119,   120,   121,     0,   122,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     124,     0,   125,     0,   126,     0,     0,     0,     0,     0,
       0,     0,   127,     0,     0,   128,     0,     0,   129,     0,
     130,   131,   132,   133,     0,   134,   135,     0,     0,     0,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    87,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,     0,     0,
       0,   226,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    89,     0,   227,   228,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    93,     0,     0,    94,     0,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,     0,    98,     0,     0,     0,     0,     0,     0,
       0,    99,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,     0,     0,     0,   116,
     117,   118,     0,   119,   120,   121,     0,   122,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   124,     0,   125,     0,   126,     0,     0,     0,     0,
       0,     0,     0,   127,     0,     0,   128,     0,     0,   129,
       0,   130,   131,   132,   133,     0,   134,   135,     0,     0,
       0,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    87,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,     0,
       0,     0,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
     271,   272,     0,     0,     0,     0,     0,     0,    90,    91,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,     0,     0,    94,     0,
       0,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,     0,    98,     0,     0,     0,     0,     0,
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
     143,   144,   145,   146,   147,   148,   149,    87,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
       0,     0,     0,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    93,     0,     0,    94,
       0,     0,    95,     0,     0,     0,     0,     0,     0,     0,
       0,   181,    96,    97,     0,    98,     0,     0,     0,     0,
       0,     0,     0,    99,   100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,     0,     0,
       0,   116,   117,   118,     0,   119,   120,   121,     0,   122,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,     0,   125,     0,   126,     0,     0,
       0,     0,     0,     0,     0,   127,     0,     0,   128,     0,
       0,   129,     0,   130,   131,   132,   133,     0,   134,   135,
       0,     0,     0,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,     0,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,    87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   331,     0,     0,     0,     0,    88,     0,     0,
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
     148,   149,    87,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,     0,     0,     0,    88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
     147,   148,   149,    87,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,     0,     0,     0,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,     0,     0,    94,     0,     0,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
       0,    98,     0,     0,     0,     0,     0,     0,     0,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   102,   103,     0,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,     0,     0,     0,   116,   117,   118,
       0,   119,   120,   121,     0,   122,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   124,
       0,   125,     0,   126,     0,     0,     0,     0,     0,     0,
       0,   127,     0,     0,   128,     0,     0,   129,     0,   130,
     131,   132,   133,     0,   134,   135,     0,     0,     0,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    87,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,     0,     0,     0,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    93,     0,     0,    94,     0,     0,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,     0,    98,     0,     0,     0,     0,     0,     0,     0,
      99,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   102,   103,     0,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,     0,     0,     0,   116,   117,
     118,     0,   119,   120,   121,     0,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     124,     0,   125,     0,   126,     0,     0,     0,     0,     0,
       0,     0,   127,     0,     0,   128,     0,     0,   129,     0,
     130,   131,   132,   133,     0,   134,   135,     0,     0,     0,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161
};

static const yytype_int16 yycheck[] =
{
       7,   325,    57,   415,    11,   593,    25,    14,    58,   592,
      20,    18,   326,    25,     4,    20,     6,    24,   328,   329,
      27,    28,    25,    13,    25,    25,    25,    34,    35,    54,
      20,    83,    25,    40,     7,     6,    69,    25,    20,    46,
      33,    48,    13,   873,    51,    35,    26,    87,    42,    20,
      83,    58,    59,    35,    91,    62,    20,    50,    65,    66,
      67,    87,    27,     7,    35,     0,    73,    32,   801,    20,
     374,   804,    46,   210,     7,    26,    25,   193,   103,    43,
       7,    55,    89,   199,    20,    78,    79,    20,    37,    38,
     210,   921,    36,    20,   101,    75,    76,    77,    14,    35,
      88,    95,    96,   686,    33,   688,    86,    72,   145,   413,
     414,     7,   145,   701,     7,   945,    49,    23,   706,   159,
     145,    50,    49,    46,    75,    76,    77,    30,    44,   139,
      80,    81,    55,   159,   139,    86,   869,   210,   164,    88,
      36,    80,    81,    36,   124,    25,    49,   157,    91,    78,
      79,   210,   157,   212,    75,    76,   136,   130,   148,    35,
     212,   749,    46,   170,   144,    86,   148,    46,   175,   176,
     177,    55,    35,   124,    98,    33,    55,   148,    25,   212,
       8,     9,   106,    25,    12,   136,    14,    15,    16,    17,
      18,   210,    50,   144,   210,   202,   212,     5,   210,     7,
     524,   151,   152,   153,   211,    75,    76,   210,   145,   210,
     210,   210,   151,   152,   153,    26,    86,   210,   225,   226,
      78,    79,    19,   213,    21,    69,   233,   537,   816,   210,
     237,   814,   546,    43,    44,    45,    46,   161,   162,   163,
     247,   248,   213,   189,   251,    55,   192,   193,   210,   211,
      43,    44,    35,   199,   170,    95,    96,   264,   265,   175,
     176,   177,   210,     0,    75,    76,    77,     4,   275,     6,
      98,   173,   188,    84,    85,    86,     0,    42,   106,   210,
       4,    13,     6,     6,    93,    94,   202,    57,    58,    57,
      58,    57,    58,   210,   301,   211,   210,   304,    57,    58,
       8,     9,   309,   402,   403,   210,     4,     4,   212,    20,
     317,    20,   131,   320,    35,    35,    35,   233,    35,    35,
      35,   237,   404,   405,   406,   407,   408,   409,   410,   411,
      35,   743,   339,   340,   341,   251,    35,    20,    20,    35,
      35,    35,    35,    35,    35,    35,    35,   354,   355,    35,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,    25,    26,    35,
      35,    35,    35,    35,    35,    33,    20,    20,    20,    37,
      38,    20,   130,   212,    25,   192,   192,    25,    46,     7,
      30,    47,    47,    30,    70,    83,   148,    55,    13,    57,
      58,    35,   153,     7,     7,    25,    26,   148,    66,    67,
     148,   418,   148,    33,     7,     7,     7,    37,    38,    77,
       7,    35,    35,   339,   340,   341,    46,    13,   435,    36,
      36,    36,   210,    49,    36,    55,    36,    57,    58,    36,
      35,    35,    30,    73,   451,    35,    66,    67,    73,    30,
      35,    35,    35,    35,    73,    25,    73,    77,    25,    25,
      25,    25,    34,    43,    35,    34,   210,   522,     7,   476,
     525,     7,   479,   480,    35,     7,     7,   103,     7,    35,
      20,   488,     7,    35,    35,   212,   493,   212,   495,   148,
     212,    70,    36,   500,   212,    36,   503,     7,   212,   506,
       7,    36,   418,    36,     7,     7,    36,     7,    36,    36,
      36,     7,    36,    36,    36,    36,    36,    36,    36,   435,
      36,   528,    36,   530,    36,   441,     7,   443,    36,   445,
      36,   447,   539,   449,   541,    36,   210,    36,    35,   210,
     210,    30,   549,    30,   594,   595,    13,   463,     7,    43,
     210,   875,    43,   210,     7,     7,   210,   210,   565,   210,
     476,     7,    73,   479,   480,    35,   212,    35,     7,     7,
     166,   149,     7,   149,   210,    36,     7,   493,    36,   212,
     212,   588,   589,   590,   500,   592,    36,   594,   595,   166,
     212,    36,     7,     7,   149,    36,    30,    30,   210,   210,
       7,   211,     7,     7,     7,     7,    36,   614,     7,   616,
      36,     7,    13,   620,    36,   149,    36,    36,    13,    36,
      36,     7,   211,    36,    36,   632,    36,    36,    36,     7,
      30,     7,   149,    30,   641,   690,   149,   211,    13,    13,
     116,    13,    36,    36,    73,    36,    36,     7,    13,    13,
       7,    36,    36,    36,   211,    36,    36,   664,   211,    36,
      13,   198,   669,   670,   904,    36,    36,   412,   183,   905,
     677,   906,   518,    -1,    -1,    -1,    -1,    -1,    -1,   686,
      -1,   688,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   615,
      -1,   617,    -1,    -1,   620,    -1,    -1,   623,    -1,   625,
      -1,   627,    -1,   629,    -1,    -1,    -1,   724,   725,   726,
     727,    -1,    -1,    -1,    -1,   732,    -1,   643,    -1,    -1,
      -1,   738,   739,    -1,    -1,    -1,   652,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   810,    -1,    -1,   674,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   785,    -1,
     787,   788,    -1,    -1,    -1,    -1,   793,    -1,    -1,    -1,
     797,    -1,    -1,   800,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   814,    -1,    -1,
      -1,    -1,   819,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   834,   835,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   848,    -1,    -1,    -1,    -1,   853,    -1,    -1,   856,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   865,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   785,
      -1,    -1,    -1,   789,    -1,   882,    -1,    -1,   794,    -1,
     887,    -1,   889,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   909,   910,    -1,    -1,   913,    -1,   915,   916,
      -1,    -1,    -1,    -1,    -1,    -1,   923,    -1,   925,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,   849,    -1,    -1,    -1,    -1,    22,    23,
      24,    -1,    26,   950,    28,    29,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    41,    42,    43,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    -1,    89,    90,    -1,    92,    -1,
      -1,    95,    96,    97,    -1,    99,   100,   101,   102,   103,
     104,   105,    -1,   107,    -1,    -1,    -1,   111,   112,   113,
     114,   115,    -1,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,    -1,   143,
      -1,   145,   146,   147,    -1,    -1,   150,    -1,    -1,    -1,
     154,    -1,   156,    -1,    -1,   159,   160,    -1,    -1,    -1,
      -1,   165,    -1,   167,   168,   169,   170,   171,   172,    -1,
     174,   175,   176,   177,   178,   179,     3,    -1,   182,   183,
     184,   185,   186,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,    26,
      -1,    28,    29,    -1,    31,    32,   210,    -1,   212,    -1,
      -1,    -1,    39,    -1,    41,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    -1,    89,    90,    -1,    92,    -1,    -1,    95,    96,
      97,    -1,    99,   100,   101,   102,   103,   104,   105,    -1,
     107,    -1,    -1,    -1,   111,   112,   113,   114,   115,    -1,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   140,    -1,    -1,   143,    -1,   145,   146,
     147,    -1,    -1,   150,    -1,    -1,    -1,   154,    -1,   156,
      -1,    -1,   159,   160,    -1,     7,    -1,     9,   165,    -1,
     167,   168,   169,   170,   171,   172,    -1,   174,   175,   176,
     177,   178,   179,    25,    -1,   182,   183,   184,   185,   186,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    71,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    85,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,    -1,    -1,
      -1,   133,   134,   135,    -1,   137,   138,   139,    -1,   141,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   155,    -1,   157,    -1,   159,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   167,    -1,    -1,   170,    -1,
      -1,   173,    -1,   175,   176,   177,   178,    -1,   180,   181,
      -1,    -1,    -1,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,     7,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
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
     196,   197,   198,   199,     9,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,    -1,    -1,    -1,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    71,    -1,    -1,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,    -1,    -1,    -1,   133,   134,
     135,   136,   137,   138,   139,    -1,   141,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     155,    -1,   157,    -1,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   167,    -1,    -1,   170,    -1,    -1,   173,    -1,
     175,   176,   177,   178,    -1,   180,   181,    -1,    -1,    -1,
      -1,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,     9,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    71,    -1,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    85,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,   109,   110,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,    -1,    -1,    -1,   133,
     134,   135,    -1,   137,   138,   139,    -1,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   155,    -1,   157,    -1,   159,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   167,    -1,    -1,   170,    -1,    -1,   173,
      -1,   175,   176,   177,   178,    -1,   180,   181,    -1,    -1,
      -1,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,     9,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    71,    -1,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    -1,    87,    -1,    -1,    -1,    -1,    -1,
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
     193,   194,   195,   196,   197,   198,   199,     9,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    71,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,    -1,    -1,
      -1,   133,   134,   135,    -1,   137,   138,   139,    -1,   141,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   155,    -1,   157,    -1,   159,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   167,    -1,    -1,   170,    -1,
      -1,   173,    -1,   175,   176,   177,   178,    -1,   180,   181,
      -1,    -1,    -1,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     198,   199,     9,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     197,   198,   199,     9,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    71,    -1,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,
      -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,    -1,    -1,    -1,   133,   134,   135,
      -1,   137,   138,   139,    -1,   141,   142,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,
      -1,   157,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   167,    -1,    -1,   170,    -1,    -1,   173,    -1,   175,
     176,   177,   178,    -1,   180,   181,    -1,    -1,    -1,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,     9,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    71,    -1,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      85,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,    -1,    -1,    -1,   133,   134,
     135,    -1,   137,   138,   139,    -1,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     155,    -1,   157,    -1,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   167,    -1,    -1,   170,    -1,    -1,   173,    -1,
     175,   176,   177,   178,    -1,   180,   181,    -1,    -1,    -1,
      -1,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   322,   323,     0,     3,    10,    11,    22,    23,    24,
      26,    28,    29,    31,    32,    39,    41,    42,    43,    48,
      54,    59,    60,    61,    62,    63,    64,    69,    87,    89,
      90,    92,    95,    96,    97,    99,   100,   101,   102,   103,
     104,   105,   107,   111,   112,   113,   114,   115,   117,   118,
     132,   140,   143,   145,   146,   147,   150,   154,   156,   159,
     160,   165,   167,   168,   169,   170,   171,   172,   174,   175,
     176,   177,   178,   179,   182,   183,   184,   185,   186,   210,
     212,   307,   316,   318,   320,   210,   210,     9,    25,    35,
      51,    52,    53,    68,    71,    74,    84,    85,    87,    95,
      96,   108,   109,   110,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   133,   134,   135,   137,
     138,   139,   141,   142,   155,   157,   159,   167,   170,   173,
     175,   176,   177,   178,   180,   181,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   215,   216,   217,   218,   219,   223,   224,   297,
      25,   210,   232,   233,   234,    27,    32,    72,   238,   239,
     240,    83,   215,   220,   242,   243,   244,    23,    25,    33,
      50,    78,    79,   210,   229,   230,   231,   215,   220,   245,
     246,   247,    25,    37,    38,    88,   248,   249,   250,    43,
      44,    45,    46,    55,   263,   264,   265,   215,   280,   210,
     266,   269,   210,   212,   267,   308,    25,    37,    38,   215,
     254,   255,   256,    25,   257,   258,   259,    25,    88,   260,
     261,   262,   215,   215,    91,    91,   145,    35,    35,   215,
     215,    25,   251,   252,   253,    25,   270,   271,   272,   210,
     212,   268,   215,   145,    69,    69,   145,   212,   220,   215,
     210,    43,    44,   215,   284,    35,   210,   285,   215,   273,
     210,   288,   292,   210,   210,   210,   210,   211,   295,   295,
     297,   215,    43,    44,    98,   106,   161,   162,   163,   300,
     302,     7,   215,   303,     7,   215,   304,   215,   215,   173,
     215,    42,    95,    96,   305,    42,   306,    13,     4,     6,
      13,    20,   148,   213,   313,   315,   319,     6,     4,     4,
     212,    20,    26,    75,    76,    77,    86,   136,   215,    35,
      35,    35,    26,    75,    76,    77,    84,    85,    86,   221,
     222,    20,   139,   157,    35,    35,   215,    35,    35,    35,
      35,    35,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    20,    35,    87,   159,    20,
     139,   157,    20,    20,    20,    20,    20,    20,    20,   192,
     189,   192,   193,   199,   193,   199,   192,    20,   148,   225,
       5,     7,     8,     9,    12,    14,    15,    16,    17,    18,
      98,   106,   131,    19,    21,   130,   215,   220,    25,   215,
     220,   215,   220,   215,   220,   212,    80,    81,   151,   152,
     153,   241,    81,   153,   241,    25,   210,   235,   236,   237,
     220,    25,   210,    25,   210,    25,   210,    25,   210,    25,
      25,    26,    33,    37,    38,    46,    55,    57,    58,    66,
      67,    77,   228,    26,    33,    37,    38,    46,    55,    57,
      58,    66,    67,   228,   215,   220,    30,   215,   220,    47,
      47,    54,   103,   145,    20,    43,   215,   215,     7,   215,
     220,   215,   220,    30,    70,   148,   215,   215,   215,   220,
      35,   215,   215,    13,   153,   215,     7,    26,    75,    76,
      77,    86,   124,   136,   144,   287,   289,   290,     7,   148,
     309,   148,     7,    20,    49,     7,     7,   215,     7,   215,
       7,   215,    95,    96,    93,    94,   215,   321,   215,    13,
     314,   310,    35,   287,   210,   316,   317,   320,   320,    35,
      36,    36,    36,    36,    36,    75,    76,    86,    36,   215,
     220,   215,   220,   215,   220,    35,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   219,    35,   210,    35,    35,
      35,   226,   227,    35,   299,   298,   217,   217,   216,   216,
     216,   216,   216,   216,   216,   216,   218,   219,   219,   224,
      30,    30,   215,   220,    73,    73,    73,    73,   215,   220,
      25,    49,   220,    25,   220,    25,   220,    25,   220,    25,
     220,   215,    34,    57,    58,    57,    58,    46,    55,    46,
      55,    35,   220,    34,    57,    58,    57,    58,    46,    55,
      46,    55,    35,   215,   220,   215,   220,   215,   220,   281,
     283,   282,    43,   210,     7,   215,   215,   220,   215,     7,
       7,   215,   220,    70,     7,   215,   103,     7,   215,    75,
      76,    86,   291,    35,    20,   292,   311,   148,   312,   295,
       7,   287,   295,    87,   159,   164,   301,   215,   215,   320,
     215,    35,   215,   296,   215,   293,    35,   316,   215,   212,
     212,   212,   212,   212,    36,    36,    36,    36,    36,    36,
      36,    36,    36,   215,     7,     7,     7,     7,    36,    36,
      36,    36,     7,    36,    36,    36,    36,    36,     7,     7,
      36,    36,    36,     7,   210,    36,   215,   215,   215,    35,
     296,   293,   297,   297,   210,   210,   215,   220,   215,   220,
      30,    30,   215,   220,    33,    50,    78,    79,   220,   220,
     220,   220,    30,    49,   215,   215,   220,   220,   210,   274,
     210,   276,   210,   278,   210,    13,   215,     7,    43,    43,
     149,   215,   215,     7,     7,   212,   220,    73,   210,   215,
       7,    35,   212,   286,    35,   296,   210,   294,   296,   295,
       7,   166,   166,   293,     7,   149,     7,    36,   293,     7,
     212,   212,   212,    36,   215,   215,   215,   215,   215,   215,
     215,   224,    36,    36,     7,     7,   293,   149,    36,   210,
     210,    30,    30,   211,    33,    50,    78,    79,     7,     7,
     275,   277,   279,    13,   215,   220,     7,   215,   215,   220,
      36,    36,   215,   220,   215,     7,    36,   215,   286,     7,
      36,   286,   149,     7,    20,    49,   149,   149,   295,    36,
     296,   293,    13,    36,   215,    36,    36,     7,    36,     7,
      36,    36,    36,    36,    36,   215,   215,    36,   211,   211,
      30,    30,   215,   220,     7,     7,     7,   215,   215,    13,
      13,    36,    36,   116,   215,    13,    73,    36,   286,    36,
     294,     7,   287,    13,   215,    13,    36,   215,   215,    36,
      36,   211,   211,    36,    36,   274,   276,   278,   215,   215,
     215,    36,   215,   215,   294,     7,   215,   215,    36,    36,
      13,   294,   215
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
     224,   224,   224,   224,   224,   224,   224,   228,   228,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   230,   230,   230,
     230,   230,   231,   231,   232,   232,   233,   233,   234,   234,
     235,   235,   236,   236,   237,   237,   238,   238,   238,   239,
     239,   239,   240,   240,   241,   241,   241,   242,   242,   242,
     243,   243,   243,   244,   244,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   247,   247,   248,   248,   248,
     248,   248,   249,   249,   250,   250,   251,   252,   253,   253,
     254,   254,   255,   255,   256,   256,   257,   258,   259,   259,
     260,   260,   260,   261,   261,   262,   262,   263,   263,   263,
     263,   263,   264,   264,   264,   265,   265,   266,   266,   266,
     266,   266,   266,   267,   267,   268,   268,   269,   270,   271,
     272,   272,   273,   274,   275,   274,   276,   277,   276,   278,
     279,   278,   281,   280,   282,   280,   283,   280,   284,   284,
     284,   285,   285,   286,   286,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   289,   288,   290,   288,   291,
     288,   292,   292,   293,   293,   294,   294,   294,   294,   294,
     294,   295,   295,   295,   295,   295,   295,   295,   295,   296,
     296,   297,   297,   297,   298,   297,   299,   297,   300,   300,
     300,   300,   300,   301,   301,   301,   301,   301,   302,   303,
     303,   303,   304,   304,   304,   305,   305,   305,   305,   306,
     306,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   308,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   309,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   310,   307,   311,   307,   312,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   313,   307,   314,   307,   315,
     307,   307,   307,   307,   316,   317,   316,   319,   318,   321,
     320,   320,   320,   320,   320,   323,   322
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
       2,     7,     7,     2,     1,     1,     1,     1,     1,     2,
       3,     4,     5,     4,     3,     5,     4,     4,     3,     4,
       5,     4,     3,     5,     4,     4,     3,     5,     7,     6,
       7,     6,     1,     1,     3,     4,     3,     4,     1,     1,
       3,     4,     3,     4,     1,     1,     2,     4,     4,     2,
       4,     4,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     2,     1,     1,     4,     2,     2,     3,     7,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     2,     2,     3,     7,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     2,     1,     1,
       1,     3,     2,     3,     1,     1,     2,     2,     1,     1,
       1,     1,     6,     5,     1,     1,     2,     2,     1,     1,
       2,     1,     5,     2,     5,     1,     1,     1,     1,     2,
       3,     3,     2,     3,     3,     1,     1,     0,     3,     4,
       5,     5,     6,     1,     1,     1,     1,     1,     6,     6,
       1,     1,     1,     1,     0,     4,     1,     0,     4,     1,
       0,     4,     0,     4,     0,     4,     0,     4,     4,     1,
       1,     3,     7,     1,     3,     1,     2,     1,     2,     1,
       2,     1,     1,     1,     1,     0,     5,     0,     6,     0,
       6,     1,     3,     1,     3,     1,     2,     3,     3,     4,
       5,     1,     2,     3,     3,     4,     5,     1,     3,     1,
       3,     1,     2,     2,     0,     4,     0,     4,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     3,     2,
       2,     3,     2,     2,     3,     1,     2,     1,     2,     2,
       2,     2,     2,     3,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     3,     2,     2,     2,
       2,     1,     1,     2,     2,     2,     1,     1,     1,     1,
       1,     2,     3,     2,     2,     1,     1,     2,     2,     1,
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
#line 78 "src/ugbc.y"
                              {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2946 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 82 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2955 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 86 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2963 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 89 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2971 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 92 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2979 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 95 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2987 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 98 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2995 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 101 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3003 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 104 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 3011 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 111 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3019 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 114 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3028 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 127 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3037 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 131 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3046 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 139 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 3055 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 143 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 3064 "src-generated/ugbc.tab.c"
    break;

  case 23: /* direct_integer: HASH Integer  */
#line 150 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 3072 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: BYTE  */
#line 155 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 3080 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: WORD  */
#line 158 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 3088 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: DWORD  */
#line 161 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 3096 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: POSITION  */
#line 164 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 3104 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: COLOR  */
#line 167 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 3112 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: WIDTH  */
#line 170 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 3120 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: HEIGHT  */
#line 173 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 3128 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition: random_definition_simple  */
#line 178 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 3136 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: BLACK  */
#line 183 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 3145 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: WHITE  */
#line 187 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 3154 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: RED  */
#line 191 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 3163 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: CYAN  */
#line 195 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 3172 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: VIOLET  */
#line 199 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 3181 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: GREEN  */
#line 203 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 3190 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: BLUE  */
#line 207 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 3199 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: YELLOW  */
#line 211 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 3208 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: ORANGE  */
#line 215 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 3217 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: BROWN  */
#line 219 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 3226 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: LIGHT RED  */
#line 223 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 3235 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: DARK GREY  */
#line 227 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 3244 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: GREY  */
#line 231 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 3253 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT GREEN  */
#line 235 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 3262 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT BLUE  */
#line 239 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 3271 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT GREY  */
#line 243 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 3280 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK BLUE  */
#line 247 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 3289 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: MAGENTA  */
#line 251 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 3298 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: PURPLE  */
#line 255 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 3307 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LAVENDER  */
#line 259 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 3316 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: GOLD  */
#line 263 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 3325 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TURQUOISE  */
#line 267 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 3334 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: TAN  */
#line 271 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 3343 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: YELLOW GREEN  */
#line 275 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 3352 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: OLIVE GREEN  */
#line 279 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 3361 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PINK  */
#line 283 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 3370 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: PEACH  */
#line 287 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 3379 "src-generated/ugbc.tab.c"
    break;

  case 59: /* $@1: %empty  */
#line 293 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 3388 "src-generated/ugbc.tab.c"
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
#line 3400 "src-generated/ugbc.tab.c"
    break;

  case 61: /* $@2: %empty  */
#line 304 "src/ugbc.y"
                        {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 3409 "src-generated/ugbc.tab.c"
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
#line 3421 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: Identifier  */
#line 315 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 3429 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: Identifier DOLLAR  */
#line 318 "src/ugbc.y"
                        { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 3437 "src-generated/ugbc.tab.c"
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
#line 3451 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: MINUS Integer  */
#line 330 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3460 "src-generated/ugbc.tab.c"
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
#line 3472 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: OP BYTE CP Integer  */
#line 341 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3481 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: OP SIGNED BYTE CP Integer  */
#line 345 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3490 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: OP WORD CP Integer  */
#line 349 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3499 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: OP SIGNED WORD CP Integer  */
#line 353 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3508 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: OP DWORD CP Integer  */
#line 357 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3517 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP SIGNED DWORD CP Integer  */
#line 361 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3526 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP POSITION CP Integer  */
#line 365 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3535 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP COLOR CP Integer  */
#line 369 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3544 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: color_enumeration  */
#line 373 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3552 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: PEEK OP direct_integer CP  */
#line 376 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3560 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: PEEK OP expr CP  */
#line 379 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3568 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: XPEN  */
#line 382 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3576 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: YPEN  */
#line 385 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3584 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: COLLISION OP direct_integer CP  */
#line 388 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3592 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: COLLISION OP expr CP  */
#line 391 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3600 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: HIT OP direct_integer CP  */
#line 394 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3608 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: HIT OP expr CP  */
#line 397 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3616 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: LEFT OP expr COMMA expr CP  */
#line 400 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3624 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 403 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3632 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: MID OP expr COMMA expr CP  */
#line 406 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3640 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 409 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3648 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: INSTR OP expr COMMA expr CP  */
#line 412 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3656 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 415 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3664 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: UPPER OP expr CP  */
#line 418 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3672 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: LOWER OP expr CP  */
#line 421 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3680 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: STR OP expr CP  */
#line 424 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3688 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: SPACE OP expr CP  */
#line 427 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3696 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: FLIP OP expr CP  */
#line 430 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3704 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: CHR OP expr CP  */
#line 433 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3712 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: ASC OP expr CP  */
#line 436 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3720 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: LEN OP expr CP  */
#line 439 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3728 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: STRING OP expr COMMA expr CP  */
#line 442 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3736 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: VAL OP expr CP  */
#line 445 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3744 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: RANDOM random_definition  */
#line 448 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3752 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: RND OP expr CP  */
#line 451 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 3760 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: OP expr CP  */
#line 454 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3768 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: MAX OP expr COMMA expr CP  */
#line 457 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3776 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: MIN OP expr COMMA expr CP  */
#line 460 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3784 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: PARAM OP Identifier CP  */
#line 463 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3792 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: PARAM DOLLAR OP Identifier CP  */
#line 466 "src/ugbc.y"
                                    {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3800 "src-generated/ugbc.tab.c"
    break;

  case 108: /* $@3: %empty  */
#line 469 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 3808 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: Identifier OSP $@3 values CSP  */
#line 471 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 3817 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: SGN OP expr CP  */
#line 475 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 3825 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: ABS OP expr CP  */
#line 478 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 3833 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: TRUE  */
#line 481 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3842 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: FALSE  */
#line 485 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3851 "src-generated/ugbc.tab.c"
    break;

  case 114: /* exponential: COLORS  */
#line 489 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 3860 "src-generated/ugbc.tab.c"
    break;

  case 115: /* exponential: PEN COLORS  */
#line 493 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3869 "src-generated/ugbc.tab.c"
    break;

  case 116: /* exponential: PEN DEFAULT  */
#line 497 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3878 "src-generated/ugbc.tab.c"
    break;

  case 117: /* exponential: DEFAULT PEN  */
#line 501 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3887 "src-generated/ugbc.tab.c"
    break;

  case 118: /* exponential: PAPER COLORS  */
#line 505 "src/ugbc.y"
                   {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3896 "src-generated/ugbc.tab.c"
    break;

  case 119: /* exponential: PAPER DEFAULT  */
#line 509 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3905 "src-generated/ugbc.tab.c"
    break;

  case 120: /* exponential: DEFAULT PAPER  */
#line 513 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3914 "src-generated/ugbc.tab.c"
    break;

  case 121: /* exponential: WIDTH  */
#line 517 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 3922 "src-generated/ugbc.tab.c"
    break;

  case 122: /* exponential: HEIGHT  */
#line 520 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 3930 "src-generated/ugbc.tab.c"
    break;

  case 123: /* exponential: TIMER  */
#line 523 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 3938 "src-generated/ugbc.tab.c"
    break;

  case 124: /* exponential: PEN DOLLAR OP expr CP  */
#line 526 "src/ugbc.y"
                            {
        (yyval.string) = text_get_pen( _environment, (yyvsp[-1].string) )->name;
    }
#line 3946 "src-generated/ugbc.tab.c"
    break;

  case 125: /* exponential: PAPER DOLLAR OP expr CP  */
#line 529 "src/ugbc.y"
                              {
        (yyval.string) = text_get_paper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3954 "src-generated/ugbc.tab.c"
    break;

  case 126: /* exponential: CMOVE DOLLAR OP expr COMMA expr CP  */
#line 532 "src/ugbc.y"
                                         {
        (yyval.string) = text_get_cmove( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3962 "src-generated/ugbc.tab.c"
    break;

  case 127: /* exponential: CUP DOLLAR  */
#line 535 "src/ugbc.y"
                 {
        (yyval.string) = text_get_cmove_direct( _environment, 0, -1 )->name;
    }
#line 3970 "src-generated/ugbc.tab.c"
    break;

  case 128: /* exponential: CDOWN DOLLAR  */
#line 538 "src/ugbc.y"
                   {
        (yyval.string) = text_get_cmove_direct( _environment, 0, 1 )->name;
    }
#line 3978 "src-generated/ugbc.tab.c"
    break;

  case 129: /* exponential: CLEFT DOLLAR  */
#line 541 "src/ugbc.y"
                   {
        (yyval.string) = text_get_cmove_direct( _environment, -1, 0 )->name;
    }
#line 3986 "src-generated/ugbc.tab.c"
    break;

  case 130: /* exponential: CRIGHT DOLLAR  */
#line 544 "src/ugbc.y"
                    {
        (yyval.string) = text_get_cmove_direct( _environment, 1, 0 )->name;
    }
#line 3994 "src-generated/ugbc.tab.c"
    break;

  case 131: /* exponential: AT DOLLAR OP expr COMMA expr CP  */
#line 547 "src/ugbc.y"
                                      {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4002 "src-generated/ugbc.tab.c"
    break;

  case 132: /* exponential: LOCATE DOLLAR OP expr COMMA expr CP  */
#line 550 "src/ugbc.y"
                                          {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4010 "src-generated/ugbc.tab.c"
    break;

  case 133: /* exponential: TAB DOLLAR  */
#line 553 "src/ugbc.y"
                 {
        (yyval.string) = text_get_tab( _environment )->name;
    }
#line 4018 "src-generated/ugbc.tab.c"
    break;

  case 134: /* exponential: XCURS  */
#line 556 "src/ugbc.y"
            {
        (yyval.string) = text_get_xcurs( _environment )->name;
    }
#line 4026 "src-generated/ugbc.tab.c"
    break;

  case 135: /* exponential: YCURS  */
#line 559 "src/ugbc.y"
            {
        (yyval.string) = text_get_ycurs( _environment )->name;
    }
#line 4034 "src-generated/ugbc.tab.c"
    break;

  case 136: /* exponential: TEXTADDRESS  */
#line 562 "src/ugbc.y"
                  {
        (yyval.string) = strdup( "TEXTADDRESS" );
    }
#line 4042 "src-generated/ugbc.tab.c"
    break;

  case 139: /* bank_definition_simple: AT direct_integer  */
#line 570 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4050 "src-generated/ugbc.tab.c"
    break;

  case 140: /* bank_definition_simple: Identifier AT direct_integer  */
#line 573 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4058 "src-generated/ugbc.tab.c"
    break;

  case 141: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 576 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 4066 "src-generated/ugbc.tab.c"
    break;

  case 142: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 579 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 4074 "src-generated/ugbc.tab.c"
    break;

  case 143: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 582 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4082 "src-generated/ugbc.tab.c"
    break;

  case 144: /* bank_definition_simple: DATA AT direct_integer  */
#line 585 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4090 "src-generated/ugbc.tab.c"
    break;

  case 145: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 589 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 4098 "src-generated/ugbc.tab.c"
    break;

  case 146: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 592 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 4106 "src-generated/ugbc.tab.c"
    break;

  case 147: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 595 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4114 "src-generated/ugbc.tab.c"
    break;

  case 148: /* bank_definition_simple: CODE AT direct_integer  */
#line 598 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4122 "src-generated/ugbc.tab.c"
    break;

  case 149: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 602 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4130 "src-generated/ugbc.tab.c"
    break;

  case 150: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 605 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4138 "src-generated/ugbc.tab.c"
    break;

  case 151: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 608 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4146 "src-generated/ugbc.tab.c"
    break;

  case 152: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 611 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4154 "src-generated/ugbc.tab.c"
    break;

  case 153: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 615 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4162 "src-generated/ugbc.tab.c"
    break;

  case 154: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 618 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4170 "src-generated/ugbc.tab.c"
    break;

  case 155: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 621 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4178 "src-generated/ugbc.tab.c"
    break;

  case 156: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 624 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4186 "src-generated/ugbc.tab.c"
    break;

  case 157: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 630 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4194 "src-generated/ugbc.tab.c"
    break;

  case 158: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 633 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4202 "src-generated/ugbc.tab.c"
    break;

  case 159: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 636 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4210 "src-generated/ugbc.tab.c"
    break;

  case 160: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 639 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4218 "src-generated/ugbc.tab.c"
    break;

  case 161: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 642 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4226 "src-generated/ugbc.tab.c"
    break;

  case 164: /* raster_definition_simple: Identifier AT direct_integer  */
#line 651 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 4234 "src-generated/ugbc.tab.c"
    break;

  case 165: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 654 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 4242 "src-generated/ugbc.tab.c"
    break;

  case 166: /* raster_definition_expression: Identifier AT expr  */
#line 659 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4250 "src-generated/ugbc.tab.c"
    break;

  case 167: /* raster_definition_expression: AT expr WITH Identifier  */
#line 662 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4258 "src-generated/ugbc.tab.c"
    break;

  case 170: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 671 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 4266 "src-generated/ugbc.tab.c"
    break;

  case 171: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 674 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 4274 "src-generated/ugbc.tab.c"
    break;

  case 172: /* next_raster_definition_expression: Identifier AT expr  */
#line 679 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 4282 "src-generated/ugbc.tab.c"
    break;

  case 173: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 682 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4290 "src-generated/ugbc.tab.c"
    break;

  case 176: /* color_definition_simple: BORDER direct_integer  */
#line 691 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 4298 "src-generated/ugbc.tab.c"
    break;

  case 177: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 694 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4306 "src-generated/ugbc.tab.c"
    break;

  case 178: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 697 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4314 "src-generated/ugbc.tab.c"
    break;

  case 179: /* color_definition_expression: BORDER expr  */
#line 702 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 4322 "src-generated/ugbc.tab.c"
    break;

  case 180: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 705 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4330 "src-generated/ugbc.tab.c"
    break;

  case 181: /* color_definition_expression: SPRITE expr TO expr  */
#line 708 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4338 "src-generated/ugbc.tab.c"
    break;

  case 187: /* wait_definition_simple: direct_integer CYCLES  */
#line 722 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 4346 "src-generated/ugbc.tab.c"
    break;

  case 188: /* wait_definition_simple: direct_integer TICKS  */
#line 725 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 4354 "src-generated/ugbc.tab.c"
    break;

  case 189: /* wait_definition_simple: direct_integer milliseconds  */
#line 728 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 4362 "src-generated/ugbc.tab.c"
    break;

  case 190: /* wait_definition_expression: expr CYCLES  */
#line 733 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 4370 "src-generated/ugbc.tab.c"
    break;

  case 191: /* wait_definition_expression: expr TICKS  */
#line 736 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 4378 "src-generated/ugbc.tab.c"
    break;

  case 192: /* wait_definition_expression: expr milliseconds  */
#line 739 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 4386 "src-generated/ugbc.tab.c"
    break;

  case 195: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 749 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 4394 "src-generated/ugbc.tab.c"
    break;

  case 196: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 752 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 4402 "src-generated/ugbc.tab.c"
    break;

  case 197: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 755 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 4410 "src-generated/ugbc.tab.c"
    break;

  case 198: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 758 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4418 "src-generated/ugbc.tab.c"
    break;

  case 199: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 761 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 4426 "src-generated/ugbc.tab.c"
    break;

  case 200: /* sprite_definition_simple: direct_integer ENABLE  */
#line 764 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 4434 "src-generated/ugbc.tab.c"
    break;

  case 201: /* sprite_definition_simple: direct_integer DISABLE  */
#line 767 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 4442 "src-generated/ugbc.tab.c"
    break;

  case 202: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 770 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4450 "src-generated/ugbc.tab.c"
    break;

  case 203: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 773 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4458 "src-generated/ugbc.tab.c"
    break;

  case 204: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 776 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4466 "src-generated/ugbc.tab.c"
    break;

  case 205: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 779 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4474 "src-generated/ugbc.tab.c"
    break;

  case 206: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 782 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4482 "src-generated/ugbc.tab.c"
    break;

  case 207: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 785 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4490 "src-generated/ugbc.tab.c"
    break;

  case 208: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 788 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4498 "src-generated/ugbc.tab.c"
    break;

  case 209: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 791 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4506 "src-generated/ugbc.tab.c"
    break;

  case 210: /* sprite_definition_expression: expr DATA FROM expr  */
#line 796 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4514 "src-generated/ugbc.tab.c"
    break;

  case 211: /* sprite_definition_expression: expr MULTICOLOR  */
#line 799 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4522 "src-generated/ugbc.tab.c"
    break;

  case 212: /* sprite_definition_expression: expr MONOCOLOR  */
#line 802 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4530 "src-generated/ugbc.tab.c"
    break;

  case 213: /* sprite_definition_expression: expr COLOR expr  */
#line 805 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4538 "src-generated/ugbc.tab.c"
    break;

  case 214: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 808 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 4546 "src-generated/ugbc.tab.c"
    break;

  case 215: /* sprite_definition_expression: expr ENABLE  */
#line 811 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 4554 "src-generated/ugbc.tab.c"
    break;

  case 216: /* sprite_definition_expression: expr DISABLE  */
#line 814 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 4562 "src-generated/ugbc.tab.c"
    break;

  case 217: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 817 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4570 "src-generated/ugbc.tab.c"
    break;

  case 218: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 820 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4578 "src-generated/ugbc.tab.c"
    break;

  case 219: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 823 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4586 "src-generated/ugbc.tab.c"
    break;

  case 220: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 826 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4594 "src-generated/ugbc.tab.c"
    break;

  case 221: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 829 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4602 "src-generated/ugbc.tab.c"
    break;

  case 222: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 832 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4610 "src-generated/ugbc.tab.c"
    break;

  case 223: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 835 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4618 "src-generated/ugbc.tab.c"
    break;

  case 224: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 838 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4626 "src-generated/ugbc.tab.c"
    break;

  case 227: /* bitmap_definition_simple: AT direct_integer  */
#line 847 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4634 "src-generated/ugbc.tab.c"
    break;

  case 228: /* bitmap_definition_simple: ENABLE  */
#line 850 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 4642 "src-generated/ugbc.tab.c"
    break;

  case 229: /* bitmap_definition_simple: DISABLE  */
#line 853 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 4650 "src-generated/ugbc.tab.c"
    break;

  case 230: /* bitmap_definition_simple: CLEAR  */
#line 856 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 4658 "src-generated/ugbc.tab.c"
    break;

  case 231: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 859 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 4666 "src-generated/ugbc.tab.c"
    break;

  case 232: /* bitmap_definition_expression: AT expr  */
#line 865 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4674 "src-generated/ugbc.tab.c"
    break;

  case 233: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 868 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 4682 "src-generated/ugbc.tab.c"
    break;

  case 236: /* textmap_definition_simple: AT direct_integer  */
#line 878 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4690 "src-generated/ugbc.tab.c"
    break;

  case 237: /* textmap_definition_expression: AT expr  */
#line 883 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4698 "src-generated/ugbc.tab.c"
    break;

  case 240: /* text_definition_simple: ENABLE  */
#line 892 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 4706 "src-generated/ugbc.tab.c"
    break;

  case 241: /* text_definition_simple: DISABLE  */
#line 895 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 4714 "src-generated/ugbc.tab.c"
    break;

  case 242: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 900 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4722 "src-generated/ugbc.tab.c"
    break;

  case 243: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 903 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4730 "src-generated/ugbc.tab.c"
    break;

  case 246: /* tiles_definition_simple: AT direct_integer  */
#line 912 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 4738 "src-generated/ugbc.tab.c"
    break;

  case 247: /* tiles_definition_expression: AT expr  */
#line 917 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 4746 "src-generated/ugbc.tab.c"
    break;

  case 250: /* colormap_definition_simple: AT direct_integer  */
#line 926 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 4754 "src-generated/ugbc.tab.c"
    break;

  case 251: /* colormap_definition_simple: CLEAR  */
#line 929 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 4762 "src-generated/ugbc.tab.c"
    break;

  case 252: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 932 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4770 "src-generated/ugbc.tab.c"
    break;

  case 253: /* colormap_definition_expression: AT expr  */
#line 937 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4778 "src-generated/ugbc.tab.c"
    break;

  case 254: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 940 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4786 "src-generated/ugbc.tab.c"
    break;

  case 257: /* screen_definition_simple: ON  */
#line 950 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 4794 "src-generated/ugbc.tab.c"
    break;

  case 258: /* screen_definition_simple: OFF  */
#line 953 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 4802 "src-generated/ugbc.tab.c"
    break;

  case 259: /* screen_definition_simple: ROWS direct_integer  */
#line 956 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 4810 "src-generated/ugbc.tab.c"
    break;

  case 260: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 959 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4818 "src-generated/ugbc.tab.c"
    break;

  case 261: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 962 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4826 "src-generated/ugbc.tab.c"
    break;

  case 262: /* screen_definition_expression: ROWS expr  */
#line 967 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 4834 "src-generated/ugbc.tab.c"
    break;

  case 263: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 970 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4842 "src-generated/ugbc.tab.c"
    break;

  case 264: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 973 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4850 "src-generated/ugbc.tab.c"
    break;

  case 268: /* var_definition_simple: Identifier ON Identifier  */
#line 982 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 4858 "src-generated/ugbc.tab.c"
    break;

  case 269: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 985 "src/ugbc.y"
                                    {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 4866 "src-generated/ugbc.tab.c"
    break;

  case 270: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 988 "src/ugbc.y"
                                                   {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 4874 "src-generated/ugbc.tab.c"
    break;

  case 271: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 991 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 4884 "src-generated/ugbc.tab.c"
    break;

  case 272: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 996 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 4894 "src-generated/ugbc.tab.c"
    break;

  case 273: /* goto_definition: Identifier  */
#line 1003 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 4902 "src-generated/ugbc.tab.c"
    break;

  case 274: /* goto_definition: Integer  */
#line 1006 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 4910 "src-generated/ugbc.tab.c"
    break;

  case 275: /* gosub_definition: Identifier  */
#line 1012 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 4918 "src-generated/ugbc.tab.c"
    break;

  case 276: /* gosub_definition: Integer  */
#line 1015 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 4926 "src-generated/ugbc.tab.c"
    break;

  case 278: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 1024 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 4934 "src-generated/ugbc.tab.c"
    break;

  case 279: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 1030 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 4942 "src-generated/ugbc.tab.c"
    break;

  case 282: /* ink_definition: expr  */
#line 1039 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 4950 "src-generated/ugbc.tab.c"
    break;

  case 283: /* on_goto_definition: Identifier  */
#line 1044 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 4959 "src-generated/ugbc.tab.c"
    break;

  case 284: /* $@4: %empty  */
#line 1048 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 4967 "src-generated/ugbc.tab.c"
    break;

  case 286: /* on_gosub_definition: Identifier  */
#line 1053 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 4976 "src-generated/ugbc.tab.c"
    break;

  case 287: /* $@5: %empty  */
#line 1057 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 4984 "src-generated/ugbc.tab.c"
    break;

  case 289: /* on_proc_definition: Identifier  */
#line 1062 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 4993 "src-generated/ugbc.tab.c"
    break;

  case 290: /* $@6: %empty  */
#line 1066 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 5001 "src-generated/ugbc.tab.c"
    break;

  case 292: /* $@7: %empty  */
#line 1071 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 5009 "src-generated/ugbc.tab.c"
    break;

  case 294: /* $@8: %empty  */
#line 1074 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 5017 "src-generated/ugbc.tab.c"
    break;

  case 296: /* $@9: %empty  */
#line 1077 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 5025 "src-generated/ugbc.tab.c"
    break;

  case 298: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1082 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 5033 "src-generated/ugbc.tab.c"
    break;

  case 299: /* every_definition: ON  */
#line 1085 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 5041 "src-generated/ugbc.tab.c"
    break;

  case 300: /* every_definition: OFF  */
#line 1088 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 5049 "src-generated/ugbc.tab.c"
    break;

  case 301: /* add_definition: Identifier COMMA expr  */
#line 1093 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 5057 "src-generated/ugbc.tab.c"
    break;

  case 302: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 1096 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5065 "src-generated/ugbc.tab.c"
    break;

  case 303: /* dimensions: Integer  */
#line 1102 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 5074 "src-generated/ugbc.tab.c"
    break;

  case 304: /* dimensions: Integer COMMA dimensions  */
#line 1106 "src/ugbc.y"
                               {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 5083 "src-generated/ugbc.tab.c"
    break;

  case 305: /* datatype: BYTE  */
#line 1113 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 5091 "src-generated/ugbc.tab.c"
    break;

  case 306: /* datatype: SIGNED BYTE  */
#line 1116 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 5099 "src-generated/ugbc.tab.c"
    break;

  case 307: /* datatype: WORD  */
#line 1119 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 5107 "src-generated/ugbc.tab.c"
    break;

  case 308: /* datatype: SIGNED WORD  */
#line 1122 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 5115 "src-generated/ugbc.tab.c"
    break;

  case 309: /* datatype: DWORD  */
#line 1125 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 5123 "src-generated/ugbc.tab.c"
    break;

  case 310: /* datatype: SIGNED DWORD  */
#line 1128 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 5131 "src-generated/ugbc.tab.c"
    break;

  case 311: /* datatype: ADDRESS  */
#line 1131 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 5139 "src-generated/ugbc.tab.c"
    break;

  case 312: /* datatype: POSITION  */
#line 1134 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 5147 "src-generated/ugbc.tab.c"
    break;

  case 313: /* datatype: COLOR  */
#line 1137 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 5155 "src-generated/ugbc.tab.c"
    break;

  case 314: /* datatype: STRING  */
#line 1140 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 5163 "src-generated/ugbc.tab.c"
    break;

  case 315: /* $@10: %empty  */
#line 1145 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5172 "src-generated/ugbc.tab.c"
    break;

  case 316: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1148 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 5182 "src-generated/ugbc.tab.c"
    break;

  case 317: /* $@11: %empty  */
#line 1153 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5191 "src-generated/ugbc.tab.c"
    break;

  case 318: /* dim_definition: Identifier $@11 DOLLAR OP dimensions CP  */
#line 1156 "src/ugbc.y"
                                {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 5201 "src-generated/ugbc.tab.c"
    break;

  case 319: /* $@12: %empty  */
#line 1161 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5210 "src-generated/ugbc.tab.c"
    break;

  case 320: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1164 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 5220 "src-generated/ugbc.tab.c"
    break;

  case 323: /* indexes: expr  */
#line 1177 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5229 "src-generated/ugbc.tab.c"
    break;

  case 324: /* indexes: expr COMMA indexes  */
#line 1181 "src/ugbc.y"
                         {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5238 "src-generated/ugbc.tab.c"
    break;

  case 325: /* parameters: Identifier  */
#line 1188 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5248 "src-generated/ugbc.tab.c"
    break;

  case 326: /* parameters: Identifier DOLLAR  */
#line 1193 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5258 "src-generated/ugbc.tab.c"
    break;

  case 327: /* parameters: Identifier AS datatype  */
#line 1198 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5268 "src-generated/ugbc.tab.c"
    break;

  case 328: /* parameters: Identifier COMMA parameters  */
#line 1203 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5278 "src-generated/ugbc.tab.c"
    break;

  case 329: /* parameters: Identifier DOLLAR COMMA parameters  */
#line 1208 "src/ugbc.y"
                                         {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5288 "src-generated/ugbc.tab.c"
    break;

  case 330: /* parameters: Identifier AS datatype COMMA parameters  */
#line 1213 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5298 "src-generated/ugbc.tab.c"
    break;

  case 331: /* parameters_expr: Identifier  */
#line 1221 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5308 "src-generated/ugbc.tab.c"
    break;

  case 332: /* parameters_expr: Identifier DOLLAR  */
#line 1226 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5318 "src-generated/ugbc.tab.c"
    break;

  case 333: /* parameters_expr: Identifier AS datatype  */
#line 1231 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5328 "src-generated/ugbc.tab.c"
    break;

  case 334: /* parameters_expr: Identifier COMMA parameters_expr  */
#line 1236 "src/ugbc.y"
                                       {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5338 "src-generated/ugbc.tab.c"
    break;

  case 335: /* parameters_expr: Identifier DOLLAR COMMA parameters_expr  */
#line 1241 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5348 "src-generated/ugbc.tab.c"
    break;

  case 336: /* parameters_expr: Identifier AS datatype COMMA parameters_expr  */
#line 1246 "src/ugbc.y"
                                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5358 "src-generated/ugbc.tab.c"
    break;

  case 337: /* parameters_expr: String  */
#line 1251 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5367 "src-generated/ugbc.tab.c"
    break;

  case 338: /* parameters_expr: String COMMA parameters_expr  */
#line 1255 "src/ugbc.y"
                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5376 "src-generated/ugbc.tab.c"
    break;

  case 339: /* values: expr  */
#line 1262 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5385 "src-generated/ugbc.tab.c"
    break;

  case 340: /* values: expr COMMA values  */
#line 1266 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5394 "src-generated/ugbc.tab.c"
    break;

  case 341: /* print_definition: expr  */
#line 1273 "src/ugbc.y"
         {
        print( _environment, (yyvsp[0].string), 1 );
    }
#line 5402 "src-generated/ugbc.tab.c"
    break;

  case 342: /* print_definition: expr COMMA  */
#line 1276 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5411 "src-generated/ugbc.tab.c"
    break;

  case 343: /* print_definition: expr SEMICOLON  */
#line 1280 "src/ugbc.y"
                   {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5419 "src-generated/ugbc.tab.c"
    break;

  case 344: /* $@13: %empty  */
#line 1283 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5428 "src-generated/ugbc.tab.c"
    break;

  case 346: /* $@14: %empty  */
#line 1287 "src/ugbc.y"
                    {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5436 "src-generated/ugbc.tab.c"
    break;

  case 348: /* writing_mode_definition: REPLACE  */
#line 1293 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing REPLACE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_REPLACE );
    }
#line 5445 "src-generated/ugbc.tab.c"
    break;

  case 349: /* writing_mode_definition: OR  */
#line 1297 "src/ugbc.y"
         {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing OR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_OR );
    }
#line 5454 "src-generated/ugbc.tab.c"
    break;

  case 350: /* writing_mode_definition: XOR  */
#line 1301 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing XOR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_XOR );
    }
#line 5463 "src-generated/ugbc.tab.c"
    break;

  case 351: /* writing_mode_definition: AND  */
#line 1305 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing AND)" )->name;
          variable_store( _environment, (yyval.string), WRITING_AND );
    }
#line 5472 "src-generated/ugbc.tab.c"
    break;

  case 352: /* writing_mode_definition: IGNORE  */
#line 1309 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing IGNORE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_IGNORE );
    }
#line 5481 "src-generated/ugbc.tab.c"
    break;

  case 353: /* writing_part_definition: NORMAL  */
#line 1316 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing NORMAL)" )->name;
          variable_store( _environment, (yyval.string), WRITING_NORMAL );
    }
#line 5490 "src-generated/ugbc.tab.c"
    break;

  case 354: /* writing_part_definition: PAPER  */
#line 1320 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5499 "src-generated/ugbc.tab.c"
    break;

  case 355: /* writing_part_definition: PAPER ONLY  */
#line 1324 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5508 "src-generated/ugbc.tab.c"
    break;

  case 356: /* writing_part_definition: PEN  */
#line 1328 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5517 "src-generated/ugbc.tab.c"
    break;

  case 357: /* writing_part_definition: PEN ONLY  */
#line 1332 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5526 "src-generated/ugbc.tab.c"
    break;

  case 358: /* writing_definition: writing_mode_definition COMMA writing_part_definition  */
#line 1339 "src/ugbc.y"
                                                          {
        text_writing( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5534 "src-generated/ugbc.tab.c"
    break;

  case 359: /* locate_definition: COMMA expr  */
#line 1345 "src/ugbc.y"
                {
        text_locate( _environment, NULL, (yyvsp[0].string) );
    }
#line 5542 "src-generated/ugbc.tab.c"
    break;

  case 360: /* locate_definition: expr COMMA  */
#line 1348 "src/ugbc.y"
                 {
        text_locate( _environment, (yyvsp[-1].string), NULL );
    }
#line 5550 "src-generated/ugbc.tab.c"
    break;

  case 361: /* locate_definition: expr COMMA expr  */
#line 1351 "src/ugbc.y"
                      {
        text_locate( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5558 "src-generated/ugbc.tab.c"
    break;

  case 362: /* cmove_definition: COMMA expr  */
#line 1357 "src/ugbc.y"
                {
        text_cmove( _environment, NULL, (yyvsp[0].string) );
    }
#line 5566 "src-generated/ugbc.tab.c"
    break;

  case 363: /* cmove_definition: expr COMMA  */
#line 1360 "src/ugbc.y"
                 {
        text_cmove( _environment, (yyvsp[-1].string), NULL );
    }
#line 5574 "src-generated/ugbc.tab.c"
    break;

  case 364: /* cmove_definition: expr COMMA expr  */
#line 1363 "src/ugbc.y"
                      {
        text_cmove( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5582 "src-generated/ugbc.tab.c"
    break;

  case 365: /* hscroll_definition: LEFT  */
#line 1369 "src/ugbc.y"
         {
        text_hscroll_line( _environment, -1 );
    }
#line 5590 "src-generated/ugbc.tab.c"
    break;

  case 366: /* hscroll_definition: SCREEN LEFT  */
#line 1372 "src/ugbc.y"
                  {
        text_hscroll_screen( _environment, -1 );
    }
#line 5598 "src-generated/ugbc.tab.c"
    break;

  case 367: /* hscroll_definition: RIGHT  */
#line 1375 "src/ugbc.y"
            {
        text_hscroll_line( _environment, 1 );
    }
#line 5606 "src-generated/ugbc.tab.c"
    break;

  case 368: /* hscroll_definition: SCREEN RIGHT  */
#line 1378 "src/ugbc.y"
                   {
        text_hscroll_screen( _environment, 1 );
    }
#line 5614 "src-generated/ugbc.tab.c"
    break;

  case 369: /* vscroll_definition: SCREEN UP  */
#line 1384 "src/ugbc.y"
                {
        text_vscroll_screen( _environment, -1 );
    }
#line 5622 "src-generated/ugbc.tab.c"
    break;

  case 370: /* vscroll_definition: SCREEN DOWN  */
#line 1387 "src/ugbc.y"
                  {
        text_vscroll_screen( _environment, 1 );
    }
#line 5630 "src-generated/ugbc.tab.c"
    break;

  case 386: /* statement: TEXTADDRESS ASSIGN expr  */
#line 1408 "src/ugbc.y"
                            {
      variable_move( _environment, (yyvsp[0].string), "ADDRESS" );
  }
#line 5638 "src-generated/ugbc.tab.c"
    break;

  case 391: /* statement: MEMORIZE  */
#line 1415 "src/ugbc.y"
             {
      text_memorize( _environment );
  }
#line 5646 "src-generated/ugbc.tab.c"
    break;

  case 392: /* statement: REMEMBER  */
#line 1418 "src/ugbc.y"
             {
      text_remember( _environment );
  }
#line 5654 "src-generated/ugbc.tab.c"
    break;

  case 396: /* statement: CUP  */
#line 1424 "src/ugbc.y"
        {
      text_cmove_direct( _environment, 0, -1 );
  }
#line 5662 "src-generated/ugbc.tab.c"
    break;

  case 397: /* statement: CDOWN  */
#line 1427 "src/ugbc.y"
          {
      text_cmove_direct( _environment, 0, 1 );
  }
#line 5670 "src-generated/ugbc.tab.c"
    break;

  case 398: /* statement: CLEFT  */
#line 1430 "src/ugbc.y"
          {
      text_cmove_direct( _environment, -1, 0 );
  }
#line 5678 "src-generated/ugbc.tab.c"
    break;

  case 399: /* statement: CRIGHT  */
#line 1433 "src/ugbc.y"
           {
      text_cmove_direct( _environment, 1, 0 );
  }
#line 5686 "src-generated/ugbc.tab.c"
    break;

  case 400: /* statement: CLINE  */
#line 1436 "src/ugbc.y"
          {
      text_cline( _environment, NULL );
  }
#line 5694 "src-generated/ugbc.tab.c"
    break;

  case 401: /* statement: CLINE expr  */
#line 1439 "src/ugbc.y"
               {
      text_cline( _environment, (yyvsp[0].string) );
  }
#line 5702 "src-generated/ugbc.tab.c"
    break;

  case 402: /* statement: SET TAB expr  */
#line 1442 "src/ugbc.y"
                 {
      text_set_tab( _environment, (yyvsp[0].string) );
  }
#line 5710 "src-generated/ugbc.tab.c"
    break;

  case 403: /* statement: CENTER expr  */
#line 1445 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 5718 "src-generated/ugbc.tab.c"
    break;

  case 404: /* statement: CENTRE expr  */
#line 1448 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 5726 "src-generated/ugbc.tab.c"
    break;

  case 405: /* statement: CLS  */
#line 1451 "src/ugbc.y"
        {
      text_cls( _environment );
  }
#line 5734 "src-generated/ugbc.tab.c"
    break;

  case 406: /* statement: HOME  */
#line 1454 "src/ugbc.y"
         {
      text_home( _environment );
  }
#line 5742 "src-generated/ugbc.tab.c"
    break;

  case 407: /* statement: INC Identifier  */
#line 1457 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 5750 "src-generated/ugbc.tab.c"
    break;

  case 408: /* statement: DEC Identifier  */
#line 1460 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 5758 "src-generated/ugbc.tab.c"
    break;

  case 409: /* statement: RANDOMIZE  */
#line 1463 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 5766 "src-generated/ugbc.tab.c"
    break;

  case 410: /* statement: RANDOMIZE expr  */
#line 1466 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 5774 "src-generated/ugbc.tab.c"
    break;

  case 411: /* statement: IF expr THEN  */
#line 1469 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5782 "src-generated/ugbc.tab.c"
    break;

  case 412: /* statement: ELSE  */
#line 1472 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 5790 "src-generated/ugbc.tab.c"
    break;

  case 413: /* statement: ELSE IF expr THEN  */
#line 1475 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5798 "src-generated/ugbc.tab.c"
    break;

  case 414: /* statement: ENDIF  */
#line 1478 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 5806 "src-generated/ugbc.tab.c"
    break;

  case 415: /* statement: DO  */
#line 1481 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 5814 "src-generated/ugbc.tab.c"
    break;

  case 416: /* statement: LOOP  */
#line 1484 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 5822 "src-generated/ugbc.tab.c"
    break;

  case 417: /* $@15: %empty  */
#line 1487 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 5830 "src-generated/ugbc.tab.c"
    break;

  case 418: /* statement: WHILE $@15 expr  */
#line 1489 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 5838 "src-generated/ugbc.tab.c"
    break;

  case 419: /* statement: WEND  */
#line 1492 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 5846 "src-generated/ugbc.tab.c"
    break;

  case 420: /* statement: REPEAT  */
#line 1495 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 5854 "src-generated/ugbc.tab.c"
    break;

  case 421: /* statement: UNTIL expr  */
#line 1498 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 5862 "src-generated/ugbc.tab.c"
    break;

  case 422: /* statement: EXIT  */
#line 1501 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 5870 "src-generated/ugbc.tab.c"
    break;

  case 423: /* statement: EXIT PROC  */
#line 1504 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 5878 "src-generated/ugbc.tab.c"
    break;

  case 424: /* statement: POP PROC  */
#line 1507 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 5886 "src-generated/ugbc.tab.c"
    break;

  case 425: /* statement: EXIT IF expr  */
#line 1510 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 5894 "src-generated/ugbc.tab.c"
    break;

  case 426: /* statement: EXIT Integer  */
#line 1513 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5902 "src-generated/ugbc.tab.c"
    break;

  case 427: /* statement: EXIT direct_integer  */
#line 1516 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5910 "src-generated/ugbc.tab.c"
    break;

  case 428: /* statement: EXIT IF expr COMMA Integer  */
#line 1519 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5918 "src-generated/ugbc.tab.c"
    break;

  case 429: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1522 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5926 "src-generated/ugbc.tab.c"
    break;

  case 430: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1525 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5934 "src-generated/ugbc.tab.c"
    break;

  case 431: /* statement: NEXT  */
#line 1528 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 5942 "src-generated/ugbc.tab.c"
    break;

  case 432: /* statement: PROCEDURE Identifier  */
#line 1531 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 5951 "src-generated/ugbc.tab.c"
    break;

  case 433: /* $@16: %empty  */
#line 1535 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5959 "src-generated/ugbc.tab.c"
    break;

  case 434: /* statement: PROCEDURE Identifier $@16 OSP parameters CSP  */
#line 1537 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5967 "src-generated/ugbc.tab.c"
    break;

  case 435: /* statement: SHARED parameters_expr  */
#line 1540 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 5975 "src-generated/ugbc.tab.c"
    break;

  case 436: /* statement: GLOBAL parameters_expr  */
#line 1543 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 5983 "src-generated/ugbc.tab.c"
    break;

  case 437: /* statement: END PROC  */
#line 1546 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 5991 "src-generated/ugbc.tab.c"
    break;

  case 438: /* statement: END PROC OSP expr CSP  */
#line 1549 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5999 "src-generated/ugbc.tab.c"
    break;

  case 439: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1552 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 6007 "src-generated/ugbc.tab.c"
    break;

  case 440: /* statement: Identifier " "  */
#line 1555 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 6016 "src-generated/ugbc.tab.c"
    break;

  case 441: /* statement: PROC Identifier  */
#line 1559 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 6025 "src-generated/ugbc.tab.c"
    break;

  case 442: /* statement: CALL Identifier  */
#line 1563 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 6034 "src-generated/ugbc.tab.c"
    break;

  case 443: /* $@17: %empty  */
#line 1567 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6042 "src-generated/ugbc.tab.c"
    break;

  case 444: /* statement: Identifier OSP $@17 values CSP  */
#line 1569 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6050 "src-generated/ugbc.tab.c"
    break;

  case 445: /* $@18: %empty  */
#line 1572 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6058 "src-generated/ugbc.tab.c"
    break;

  case 446: /* statement: PROC Identifier OSP $@18 values CSP  */
#line 1574 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6066 "src-generated/ugbc.tab.c"
    break;

  case 447: /* $@19: %empty  */
#line 1577 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6074 "src-generated/ugbc.tab.c"
    break;

  case 448: /* statement: CALL Identifier OSP $@19 values CSP  */
#line 1579 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6082 "src-generated/ugbc.tab.c"
    break;

  case 449: /* statement: PEN expr  */
#line 1582 "src/ugbc.y"
             {
      text_pen( _environment, (yyvsp[0].string) );
  }
#line 6090 "src-generated/ugbc.tab.c"
    break;

  case 450: /* statement: PAPER expr  */
#line 1585 "src/ugbc.y"
               {
      text_paper( _environment, (yyvsp[0].string) );
  }
#line 6098 "src-generated/ugbc.tab.c"
    break;

  case 451: /* statement: INVERSE ON  */
#line 1588 "src/ugbc.y"
               {
      CRITICAL_NOT_SUPPORTED("INVERSE");
  }
#line 6106 "src-generated/ugbc.tab.c"
    break;

  case 452: /* statement: INVERSE OFF  */
#line 1591 "src/ugbc.y"
                {
      CRITICAL_NOT_SUPPORTED("INVERSE");
  }
#line 6114 "src-generated/ugbc.tab.c"
    break;

  case 454: /* statement: Identifier COLON  */
#line 1595 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 6122 "src-generated/ugbc.tab.c"
    break;

  case 455: /* statement: BEG GAMELOOP  */
#line 1598 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 6130 "src-generated/ugbc.tab.c"
    break;

  case 456: /* statement: END GAMELOOP  */
#line 1601 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 6138 "src-generated/ugbc.tab.c"
    break;

  case 457: /* statement: GRAPHIC  */
#line 1604 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 6146 "src-generated/ugbc.tab.c"
    break;

  case 458: /* statement: HALT  */
#line 1607 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 6154 "src-generated/ugbc.tab.c"
    break;

  case 459: /* statement: END  */
#line 1610 "src/ugbc.y"
        {
      end( _environment );
  }
#line 6162 "src-generated/ugbc.tab.c"
    break;

  case 464: /* statement: RETURN  */
#line 1617 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 6170 "src-generated/ugbc.tab.c"
    break;

  case 465: /* statement: RETURN expr  */
#line 1620 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 6178 "src-generated/ugbc.tab.c"
    break;

  case 466: /* statement: POP  */
#line 1623 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 6186 "src-generated/ugbc.tab.c"
    break;

  case 467: /* statement: DONE  */
#line 1626 "src/ugbc.y"
          {
      return 0;
  }
#line 6194 "src-generated/ugbc.tab.c"
    break;

  case 468: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1629 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6202 "src-generated/ugbc.tab.c"
    break;

  case 469: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1632 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6210 "src-generated/ugbc.tab.c"
    break;

  case 470: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1635 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 6218 "src-generated/ugbc.tab.c"
    break;

  case 471: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1638 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6226 "src-generated/ugbc.tab.c"
    break;

  case 473: /* statement: Identifier ASSIGN expr  */
#line 1642 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 6240 "src-generated/ugbc.tab.c"
    break;

  case 474: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1651 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 6254 "src-generated/ugbc.tab.c"
    break;

  case 475: /* $@20: %empty  */
#line 1660 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6263 "src-generated/ugbc.tab.c"
    break;

  case 476: /* statement: Identifier $@20 OP indexes CP ASSIGN expr  */
#line 1664 "src/ugbc.y"
                                {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 6276 "src-generated/ugbc.tab.c"
    break;

  case 477: /* $@21: %empty  */
#line 1672 "src/ugbc.y"
                      {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6285 "src-generated/ugbc.tab.c"
    break;

  case 478: /* statement: Identifier DOLLAR $@21 OP indexes CP ASSIGN expr  */
#line 1675 "src/ugbc.y"
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
#line 6304 "src-generated/ugbc.tab.c"
    break;

  case 479: /* $@22: %empty  */
#line 1689 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6313 "src-generated/ugbc.tab.c"
    break;

  case 480: /* statement: Identifier $@22 datatype OP indexes CP ASSIGN expr  */
#line 1692 "src/ugbc.y"
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
#line 6332 "src-generated/ugbc.tab.c"
    break;

  case 481: /* statement: DEBUG expr  */
#line 1706 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 6340 "src-generated/ugbc.tab.c"
    break;

  case 484: /* statements_no_linenumbers: statement  */
#line 1714 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 6346 "src-generated/ugbc.tab.c"
    break;

  case 485: /* $@23: %empty  */
#line 1715 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 6352 "src-generated/ugbc.tab.c"
    break;

  case 487: /* $@24: %empty  */
#line 1719 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 6360 "src-generated/ugbc.tab.c"
    break;

  case 488: /* statements_with_linenumbers: Integer $@24 statements_no_linenumbers  */
#line 1721 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 6368 "src-generated/ugbc.tab.c"
    break;

  case 489: /* $@25: %empty  */
#line 1726 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 6376 "src-generated/ugbc.tab.c"
    break;

  case 495: /* $@26: %empty  */
#line 1736 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 6382 "src-generated/ugbc.tab.c"
    break;


#line 6386 "src-generated/ugbc.tab.c"

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

#line 1738 "src/ugbc.y"


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

