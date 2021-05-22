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
  YYSYMBOL_BLACK = 196,                    /* BLACK  */
  YYSYMBOL_WHITE = 197,                    /* WHITE  */
  YYSYMBOL_RED = 198,                      /* RED  */
  YYSYMBOL_CYAN = 199,                     /* CYAN  */
  YYSYMBOL_VIOLET = 200,                   /* VIOLET  */
  YYSYMBOL_GREEN = 201,                    /* GREEN  */
  YYSYMBOL_BLUE = 202,                     /* BLUE  */
  YYSYMBOL_YELLOW = 203,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 204,                   /* ORANGE  */
  YYSYMBOL_BROWN = 205,                    /* BROWN  */
  YYSYMBOL_LIGHT = 206,                    /* LIGHT  */
  YYSYMBOL_DARK = 207,                     /* DARK  */
  YYSYMBOL_GREY = 208,                     /* GREY  */
  YYSYMBOL_GRAY = 209,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 210,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 211,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 212,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 213,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 214,                /* TURQUOISE  */
  YYSYMBOL_TAN = 215,                      /* TAN  */
  YYSYMBOL_PINK = 216,                     /* PINK  */
  YYSYMBOL_PEACH = 217,                    /* PEACH  */
  YYSYMBOL_OLIVE = 218,                    /* OLIVE  */
  YYSYMBOL_Identifier = 219,               /* Identifier  */
  YYSYMBOL_String = 220,                   /* String  */
  YYSYMBOL_Integer = 221,                  /* Integer  */
  YYSYMBOL_222_ = 222,                     /* " "  */
  YYSYMBOL_YYACCEPT = 223,                 /* $accept  */
  YYSYMBOL_expr = 224,                     /* expr  */
  YYSYMBOL_expr_math = 225,                /* expr_math  */
  YYSYMBOL_term = 226,                     /* term  */
  YYSYMBOL_modula = 227,                   /* modula  */
  YYSYMBOL_factor = 228,                   /* factor  */
  YYSYMBOL_direct_integer = 229,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 230, /* random_definition_simple  */
  YYSYMBOL_random_definition = 231,        /* random_definition  */
  YYSYMBOL_color_enumeration = 232,        /* color_enumeration  */
  YYSYMBOL_exponential = 233,              /* exponential  */
  YYSYMBOL_234_1 = 234,                    /* $@1  */
  YYSYMBOL_235_2 = 235,                    /* $@2  */
  YYSYMBOL_236_3 = 236,                    /* $@3  */
  YYSYMBOL_position = 237,                 /* position  */
  YYSYMBOL_bank_definition_simple = 238,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 239, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 240,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 241, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 242, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 243,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 244, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 245, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 246,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 247,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 248, /* color_definition_expression  */
  YYSYMBOL_color_definition = 249,         /* color_definition  */
  YYSYMBOL_milliseconds = 250,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 251,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 252, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 253,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 254, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 255, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 256,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 257, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 258, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 259,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 260, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 261, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 262,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 263,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 264, /* text_definition_expression  */
  YYSYMBOL_text_definition = 265,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 266,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 267, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 268,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 269, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 270, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 271,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 272, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 273, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 274,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 275,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 276,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 277,         /* gosub_definition  */
  YYSYMBOL_var_definition = 278,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 279,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 280, /* point_definition_expression  */
  YYSYMBOL_point_definition = 281,         /* point_definition  */
  YYSYMBOL_ink_definition = 282,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 283,       /* on_goto_definition  */
  YYSYMBOL_284_4 = 284,                    /* $@4  */
  YYSYMBOL_on_gosub_definition = 285,      /* on_gosub_definition  */
  YYSYMBOL_286_5 = 286,                    /* $@5  */
  YYSYMBOL_on_proc_definition = 287,       /* on_proc_definition  */
  YYSYMBOL_288_6 = 288,                    /* $@6  */
  YYSYMBOL_on_definition = 289,            /* on_definition  */
  YYSYMBOL_290_7 = 290,                    /* $@7  */
  YYSYMBOL_291_8 = 291,                    /* $@8  */
  YYSYMBOL_292_9 = 292,                    /* $@9  */
  YYSYMBOL_every_definition = 293,         /* every_definition  */
  YYSYMBOL_add_definition = 294,           /* add_definition  */
  YYSYMBOL_dimensions = 295,               /* dimensions  */
  YYSYMBOL_datatype = 296,                 /* datatype  */
  YYSYMBOL_dim_definition = 297,           /* dim_definition  */
  YYSYMBOL_298_10 = 298,                   /* $@10  */
  YYSYMBOL_299_11 = 299,                   /* $@11  */
  YYSYMBOL_300_12 = 300,                   /* $@12  */
  YYSYMBOL_dim_definitions = 301,          /* dim_definitions  */
  YYSYMBOL_indexes = 302,                  /* indexes  */
  YYSYMBOL_parameters = 303,               /* parameters  */
  YYSYMBOL_parameters_expr = 304,          /* parameters_expr  */
  YYSYMBOL_values = 305,                   /* values  */
  YYSYMBOL_print_definition = 306,         /* print_definition  */
  YYSYMBOL_307_13 = 307,                   /* $@13  */
  YYSYMBOL_308_14 = 308,                   /* $@14  */
  YYSYMBOL_writing_mode_definition = 309,  /* writing_mode_definition  */
  YYSYMBOL_writing_part_definition = 310,  /* writing_part_definition  */
  YYSYMBOL_writing_definition = 311,       /* writing_definition  */
  YYSYMBOL_locate_definition = 312,        /* locate_definition  */
  YYSYMBOL_cmove_definition = 313,         /* cmove_definition  */
  YYSYMBOL_hscroll_definition = 314,       /* hscroll_definition  */
  YYSYMBOL_vscroll_definition = 315,       /* vscroll_definition  */
  YYSYMBOL_statement = 316,                /* statement  */
  YYSYMBOL_317_15 = 317,                   /* $@15  */
  YYSYMBOL_318_16 = 318,                   /* $@16  */
  YYSYMBOL_319_17 = 319,                   /* $@17  */
  YYSYMBOL_320_18 = 320,                   /* $@18  */
  YYSYMBOL_321_19 = 321,                   /* $@19  */
  YYSYMBOL_322_20 = 322,                   /* $@20  */
  YYSYMBOL_323_21 = 323,                   /* $@21  */
  YYSYMBOL_324_22 = 324,                   /* $@22  */
  YYSYMBOL_statements_no_linenumbers = 325, /* statements_no_linenumbers  */
  YYSYMBOL_326_23 = 326,                   /* $@23  */
  YYSYMBOL_statements_with_linenumbers = 327, /* statements_with_linenumbers  */
  YYSYMBOL_328_24 = 328,                   /* $@24  */
  YYSYMBOL_statements_complex = 329,       /* statements_complex  */
  YYSYMBOL_330_25 = 330,                   /* $@25  */
  YYSYMBOL_program = 331,                  /* program  */
  YYSYMBOL_332_26 = 332                    /* $@26  */
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
#define YYLAST   3785

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  223
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  110
/* YYNRULES -- Number of rules.  */
#define YYNRULES  512
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  991

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   477


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
     215,   216,   217,   218,   219,   220,   221,   222
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
     576,   579,   582,   585,   588,   591,   594,   597,   600,   604,
     608,   612,   616,   622,   622,   625,   628,   631,   634,   637,
     640,   644,   647,   650,   653,   657,   660,   663,   666,   670,
     673,   676,   679,   685,   688,   691,   694,   697,   702,   703,
     706,   709,   714,   717,   722,   723,   726,   729,   734,   737,
     742,   743,   746,   749,   752,   757,   760,   763,   768,   769,
     772,   773,   774,   777,   780,   783,   788,   791,   794,   800,
     801,   804,   807,   810,   813,   816,   819,   822,   825,   828,
     831,   834,   837,   840,   843,   846,   851,   854,   857,   860,
     863,   866,   869,   872,   875,   878,   881,   884,   887,   890,
     893,   898,   899,   902,   905,   908,   911,   914,   920,   923,
     929,   930,   933,   938,   943,   944,   947,   950,   955,   958,
     963,   964,   967,   972,   977,   978,   981,   984,   987,   992,
     995,  1001,  1002,  1005,  1008,  1011,  1014,  1017,  1022,  1025,
    1028,  1033,  1034,  1036,  1037,  1040,  1043,  1046,  1051,  1058,
    1061,  1067,  1070,  1076,  1079,  1085,  1090,  1091,  1094,  1099,
    1103,  1103,  1108,  1112,  1112,  1117,  1121,  1121,  1126,  1126,
    1129,  1129,  1132,  1132,  1137,  1140,  1143,  1148,  1151,  1157,
    1161,  1168,  1171,  1174,  1177,  1180,  1183,  1186,  1189,  1192,
    1195,  1200,  1200,  1208,  1208,  1216,  1216,  1227,  1228,  1232,
    1236,  1243,  1248,  1253,  1258,  1263,  1268,  1276,  1281,  1286,
    1291,  1296,  1301,  1306,  1310,  1317,  1321,  1328,  1331,  1335,
    1338,  1338,  1342,  1342,  1348,  1352,  1356,  1360,  1364,  1371,
    1375,  1379,  1383,  1387,  1394,  1400,  1403,  1406,  1412,  1415,
    1418,  1424,  1427,  1430,  1433,  1439,  1442,  1448,  1449,  1450,
    1451,  1452,  1453,  1454,  1455,  1456,  1457,  1458,  1459,  1460,
    1461,  1462,  1463,  1466,  1467,  1468,  1469,  1470,  1473,  1476,
    1477,  1478,  1479,  1482,  1485,  1488,  1491,  1494,  1497,  1500,
    1503,  1506,  1509,  1512,  1515,  1518,  1521,  1524,  1527,  1530,
    1533,  1536,  1539,  1542,  1542,  1547,  1550,  1553,  1556,  1559,
    1562,  1565,  1568,  1571,  1574,  1577,  1580,  1583,  1586,  1590,
    1590,  1595,  1598,  1601,  1604,  1607,  1610,  1614,  1618,  1622,
    1622,  1627,  1627,  1632,  1632,  1637,  1640,  1643,  1646,  1649,
    1650,  1653,  1656,  1659,  1662,  1665,  1668,  1669,  1670,  1671,
    1672,  1675,  1678,  1681,  1684,  1687,  1690,  1693,  1696,  1697,
    1706,  1715,  1715,  1727,  1727,  1744,  1744,  1761,  1764,  1765,
    1769,  1770,  1770,  1774,  1774,  1781,  1781,  1784,  1785,  1786,
    1787,  1791,  1791
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
  "BIN", "BIT", "COUNT", "JOYCOUNT", "FIRE", "BLACK", "WHITE", "RED",
  "CYAN", "VIOLET", "GREEN", "BLUE", "YELLOW", "ORANGE", "BROWN", "LIGHT",
  "DARK", "GREY", "GRAY", "MAGENTA", "PURPLE", "LAVENDER", "GOLD",
  "TURQUOISE", "TAN", "PINK", "PEACH", "OLIVE", "Identifier", "String",
  "Integer", "\" \"", "$accept", "expr", "expr_math", "term", "modula",
  "factor", "direct_integer", "random_definition_simple",
  "random_definition", "color_enumeration", "exponential", "$@1", "$@2",
  "$@3", "position", "bank_definition_simple",
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
     475,   476,   477
};
#endif

#define YYPACT_NINF (-873)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-492)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -873,    54,  1018,  -873,  -873,  -149,  -119,  2764,   -19,  -873,
      72,  2351,   112,     4,  2351,  -873,    48,   230,  2764,   -77,
    -120,  -873,  -873,  -873,  1951,   176,    37,  2764,  2764,   113,
     -13,  -873,   184,   192,  2764,  2764,  -873,   204,   206,  -107,
    2764,   108,   188,  -873,   -38,  -873,  2764,    44,  2151,   234,
      62,  2764,    64,    66,    68,    73,    35,    35,  2764,  2764,
     224,   -32,  1336,  -873,  -873,  1551,  2764,  2764,   134,  -873,
    -873,  -873,  -873,  2764,  -873,  -873,    52,   262,   303,     9,
    -873,   313,   331,   332,  -873,  -873,  -873,   116,   318,  1751,
    -873,  -873,   304,   305,   306,   179,  -873,  -873,    22,  -873,
    -873,   307,   308,  2764,  -873,  -873,   309,   310,   311,   312,
     314,   315,   339,   340,   341,   342,   343,   344,   346,   348,
     352,   355,   356,  -873,  -873,   357,    75,   -41,    26,   336,
     365,   377,   378,   379,   380,   381,  -873,  -873,  -873,    -8,
     364,  3364,  -873,  -873,  -873,  -873,  -873,  -873,  -873,  -873,
    -873,   202,  -873,  -873,   110,   -93,  -873,  -873,  -873,  -873,
    -873,  -873,  -873,  -873,  -873,   205,    15,  -873,  -873,   158,
     140,   217,   180,    40,  -873,  -873,  -873,  2351,   382,  -873,
    -873,  -873,  2351,  2351,  2351,  -873,  -873,  -873,   190,   -11,
      41,  -873,  -873,  -873,   -16,   326,   -14,    -5,    -3,    -2,
     385,  -873,  -873,  -873,   233,   347,  -873,  -873,  -873,  2351,
    -873,  -873,   376,  -873,  -873,  -873,  -873,  -873,  2351,   368,
     369,  -873,  -873,  -873,    11,  -873,    70,  -873,  -873,  -873,
    -873,  -873,  2764,  2564,  -873,  -873,   407,  -873,  -873,  -873,
    2351,  -873,  -873,  -873,  2351,   387,  -873,  -873,  -873,   349,
    -873,  -873,  -873,   264,  2764,  2764,  -873,  -873,  2351,  -873,
    -873,  -873,   383,  -873,  -873,  -873,  -873,  -873,  -873,  -873,
    -873,  2764,  2764,  -873,  -873,  -873,  -873,   410,  -873,  -873,
     268,  -873,  2764,   418,  -873,  -873,  -873,    51,   421,  -873,
     278,   279,   281,   167,   424,  -873,  -873,  -873,  -873,  -873,
    -873,  -873,  -873,  -873,  -873,  -873,   426,  -873,  2764,   427,
    -873,  2764,   428,  -873,  -873,  -873,  2764,  -873,   197,  -873,
    -873,  -873,   201,  -873,  2764,  -873,  -873,  2764,   423,  -873,
    -873,   399,    14,  1198,  -873,  1018,  1018,  -873,   400,   401,
     402,   403,   405,   406,   102,   408,  2351,  2351,  2351,  -873,
    -873,  -873,  -873,  -873,  -873,  -873,  -873,  -873,   411,  -873,
    -873,  2764,  2764,  -873,  2764,  2764,  2764,  2764,  2764,  2764,
    2764,  2764,  2764,  2764,  2764,  2764,  2764,  2764,  2764,  2764,
    2764,  2964,   412,   220,  -873,  -873,   413,  -873,  -873,   414,
     415,  -873,  -873,  -873,  -873,  -873,  2764,  -873,  2764,  1751,
     416,   430,  -873,  -873,  -873,  -873,  -873,  -873,  -873,  -873,
     419,  -873,   420,   246,   280,  2964,  2964,  2964,  2964,  2964,
    2964,  2964,  2964,  2964,  2964,  2964,  2964,  2964,   -66,  3164,
    3564,   429,   431,  2351,  -873,  -873,   370,   372,   384,   389,
    -873,  -873,  -873,  -873,  -873,  -873,  -873,  -873,  -873,  -873,
    2351,   433,  -873,  -873,  -873,   404,   326,   435,   326,   438,
     326,   439,   326,   440,   326,  -873,  2764,   432,  -873,  -873,
     239,   245,   157,   160,  -873,  -873,  -873,   434,   326,   436,
    -873,  -873,   254,   269,   178,   195,  -873,  -873,   437,  -873,
    -873,  2351,  -873,  -873,  2351,  2351,  -873,  -873,  -873,   425,
     251,  -873,   467,  2764,  -873,  -873,  -873,  -873,  2351,  -873,
    2764,   469,   470,  -873,  -873,  2351,   422,   471,  2764,   373,
     473,  2764,  -873,  -873,  -873,  -873,  -873,  -873,   150,  -873,
    -873,   443,   463,    64,  -873,   335,  -873,    35,   482,    14,
      35,   -40,  -873,  2764,  -873,  2764,  -873,  -873,  -873,  -873,
    -873,  -873,  1018,  -873,  2764,   454,  2764,  2764,   455,    18,
    -873,  1198,  -873,  -873,  2764,   273,   276,   277,   283,   284,
     460,   461,   468,  -873,   474,   476,   477,   478,   479,   480,
    2764,   495,   499,   502,   503,   481,   483,   484,   485,   505,
     486,   487,   488,   489,   490,   514,   523,   492,   493,   494,
      60,   316,   500,  2764,  2764,  2764,   501,    97,    98,  2764,
    2964,   496,  2764,  2764,  2764,  2764,   217,   217,   323,   323,
     323,   323,   323,   323,   323,   323,   180,    40,    40,   353,
    3564,  3564,  -873,  -873,   322,   327,  -873,  -873,  2764,   326,
    2764,   326,   515,   517,  2351,    38,  -873,   326,  -873,   326,
    -873,   326,  -873,   326,    46,  -873,  2764,  -873,  -873,  -873,
    -873,  -873,  -873,  -873,  -873,  2764,  -873,   326,  -873,  -873,
    -873,  -873,  -873,  -873,  -873,  -873,   326,  -873,  -873,  -873,
    -873,  -873,  -873,   333,   334,   337,   345,   538,  2764,   547,
     512,   513,   441,  2764,  2764,   553,   556,  -873,   -50,   491,
     351,  2764,   558,  -873,  -873,  -873,   528,   350,   530,  -873,
    2764,   358,  2764,  -873,    35,   565,  -873,   417,   442,  -873,
    -873,  -873,  -873,  -873,  -873,  2764,   567,   447,   568,   537,
    2764,  -873,   572,  -873,  -873,  -873,  -873,  -873,   359,   362,
     363,  -873,  -873,  -873,  -873,  -873,  -873,   542,  2764,  2764,
    2764,  2764,  -873,  -873,  -873,  -873,  2764,  -873,  -873,  -873,
    -873,  -873,  2764,  2764,  -873,  -873,  -873,  3564,   546,  -873,
     548,   581,   582,  -873,  2764,  -873,  2764,   583,   569,  2764,
     449,   552,  -873,  -873,  3564,  -873,  -873,  -873,  -873,  -873,
    -873,  -873,  -873,   375,   390,  -873,  -873,  -873,  -873,  -873,
    -873,   562,  -873,   570,  -873,   386,   131,  -873,   603,  -873,
     605,   606,  -873,   607,  -873,   608,  -873,   604,  2351,   609,
    2764,  2764,   326,  -873,   580,   584,  2764,   326,  -873,  -873,
    2764,  -873,   155,  2764,   350,   613,   585,   350,   498,   172,
     504,   508,  -873,    35,  -873,  -873,   586,  2764,  -873,  2764,
     615,   587,  2764,  -873,  -873,  -873,  -873,   590,   591,   181,
     182,   593,   595,   596,   597,  -873,  -873,  2764,  2764,   599,
     600,   601,  -873,  -873,  -873,  -873,  -873,   444,   445,  -873,
     588,  -873,   589,  -873,  2764,   326,   634,   635,   636,  2764,
    -873,  -873,  2764,  -873,  -873,  -873,   632,   633,   612,   614,
     529,  2764,   639,   571,   616,   350,  -873,   618,  -873,   358,
     647,    14,  -873,  -873,  -873,   648,  -873,  -873,  2764,   649,
     624,  -873,  -873,  2764,  -873,  2764,  -873,  -873,  -873,  -873,
    -873,   627,   628,  -873,  -873,  -873,  -873,  -873,   448,   450,
     630,   637,   333,   334,   337,  -873,  -873,  2764,  2764,  -873,
    -873,  2764,   638,  2764,  2764,  -873,  -873,  -873,  -873,   358,
     664,  2764,  -873,  2764,  -873,   640,   641,  -873,  -873,  -873,
    -873,  -873,  -873,  -873,  -873,  -873,  -873,  -873,  -873,   659,
    -873,  -873,  -873,   358,  -873,  -873,  -873,  -873,  2764,  -873,
    -873
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     511,     0,   499,     1,   498,     0,     0,     0,     0,   483,
       0,     0,   447,     0,     0,   474,     0,     0,     0,   283,
       0,   432,   436,   433,     0,     0,     0,     0,     0,     0,
     475,   430,     0,     0,     0,   425,   473,     0,     0,     0,
     480,   482,   428,   431,   438,   435,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   421,   422,     0,     0,     0,     0,   412,
     413,   414,   415,   416,   407,   408,     0,     0,     0,   495,
     503,   500,   507,   509,   512,   423,   424,     0,     0,     0,
      84,    85,     0,     0,     0,     0,   128,   129,     0,   148,
     149,   150,   151,     0,   119,   120,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,   130,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,   142,   143,     0,
       0,     0,   146,   152,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,     0,     0,    49,    54,    55,    56,
      57,    58,    59,    62,    63,     0,    68,    72,    70,   357,
       2,    12,    15,    17,    81,    20,   405,     0,     0,   184,
     185,   388,     0,     0,     0,   198,   199,   390,     0,     0,
       0,   209,   210,   391,     0,     0,     0,     0,     0,     0,
       0,   178,   179,   387,     0,     0,   241,   242,   392,     0,
     244,   245,   246,   250,   251,   393,   273,   274,     0,     0,
       0,   281,   282,   398,     0,   476,     0,   293,   401,   289,
     290,   477,     0,     0,   256,   257,     0,   260,   261,   395,
       0,   264,   265,   396,     0,   267,   271,   272,   397,     0,
     465,   471,   472,   453,     0,     0,   497,   426,     0,   254,
     255,   394,     0,   296,   297,   399,   291,   292,   478,   481,
     440,     0,     0,   439,   442,   443,   437,     0,   315,   316,
       0,   479,     0,     0,   403,   298,   400,   331,   337,   488,
     457,   448,   458,   347,   353,   451,   452,   404,   466,   467,
     468,   367,   365,   364,   366,   368,     0,   469,     0,     0,
     406,     0,     0,   411,   419,   420,     0,   417,     0,   381,
     383,   409,     0,   410,     0,   505,   470,     0,   493,   459,
     456,     0,     0,   499,   501,   499,   499,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      29,    30,    32,    34,    35,    31,    36,   108,     0,   122,
     123,     0,     0,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   124,   127,     0,   125,   126,     0,
       0,   140,   134,   135,   136,   137,     0,   145,     0,     0,
       0,     0,    60,    47,    50,    51,    52,    53,    48,    61,
      69,   115,     0,   362,   360,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   195,   192,     0,     0,     0,     0,
      28,   200,   206,   201,   202,   207,   208,   203,   204,   205,
       0,     0,   190,   191,   389,   155,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   154,     0,     0,   231,   232,
       0,     0,     0,     0,   228,   227,   153,     0,     0,     0,
     216,   217,     0,     0,     0,     0,   213,   212,     0,   248,
     243,     0,   278,   275,     0,     0,   308,   312,   310,     0,
       0,   434,     0,     0,   263,   262,   269,   266,     0,   427,
       0,     0,     0,   253,   252,     0,     0,   441,     0,     0,
       0,     0,   329,   321,   323,   328,   325,   330,     0,   327,
     335,     0,     0,     0,   461,     0,   463,     0,   348,     0,
       0,     0,   375,   376,   378,   379,   418,   382,   384,   385,
     386,   402,   499,   489,     0,     0,     0,     0,     0,   495,
     504,   499,   508,   510,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    14,     5,     7,
       8,     9,    10,     6,     3,     4,    16,    18,    19,     0,
       0,     0,    25,    21,     0,     0,   182,   180,     0,     0,
       0,     0,     0,     0,     0,     0,   160,     0,   172,     0,
     164,     0,   168,     0,   156,   229,     0,   236,   235,   240,
     239,   234,   238,   233,   237,     0,   214,     0,   221,   220,
     225,   224,   219,   223,   218,   222,     0,   249,   247,   279,
     276,   280,   277,     0,     0,     0,     0,   284,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   429,     0,     0,
       0,     0,   317,   322,   324,   326,     0,     0,     0,   338,
       0,     0,     0,   350,     0,   349,   354,   372,   370,   369,
     374,   377,   380,   506,   490,     0,   355,     0,   339,     0,
       0,   502,     0,    80,    73,    75,    79,    77,     0,     0,
       0,    83,    82,    87,    86,    89,    88,     0,     0,     0,
       0,     0,    96,    97,    98,   107,     0,   101,   102,   103,
     104,   105,     0,     0,   117,   118,   109,     0,     0,   113,
       0,     0,     0,   144,     0,    99,     0,     0,    27,     0,
       0,     0,   363,   361,     0,    23,    26,   183,   181,   197,
     194,   196,   193,     0,     0,   188,   186,   157,   170,   162,
     165,   159,   171,   163,   167,     0,     0,   226,     0,   211,
       0,   299,   309,   302,   313,   305,   311,   285,     0,     0,
       0,     0,     0,   454,     0,     0,     0,     0,   444,   445,
       0,   314,     0,     0,     0,   319,     0,     0,     0,   341,
       0,     0,   351,     0,   373,   371,     0,     0,   460,     0,
       0,     0,     0,    74,    76,    78,   131,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   132,     0,     0,     0,
       0,     0,   116,    65,    24,   189,   187,     0,     0,   173,
     158,   169,   161,   166,     0,     0,     0,     0,     0,     0,
     287,   286,     0,   259,   270,   268,     0,     0,     0,     0,
     446,     0,     0,     0,     0,     0,   332,     0,   462,     0,
     342,     0,   450,   464,   352,     0,   356,   340,     0,     0,
       0,    90,    91,     0,    92,     0,    94,   106,   112,   111,
      22,     0,     0,   100,   147,    67,   175,   177,     0,     0,
       0,     0,     0,     0,     0,   288,   258,     0,     0,   295,
     294,     0,     0,     0,     0,   336,   320,   334,   344,     0,
     343,     0,   492,     0,   138,     0,     0,   139,   133,   174,
     176,   230,   215,   301,   304,   307,   484,   485,   455,     0,
     486,   318,   345,     0,   494,   496,    93,    95,     0,   346,
     487
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -873,    -7,   -96,   -82,   248,  -365,   360,  -873,  -873,  -873,
    -140,  -873,  -873,  -873,   497,  -873,  -873,  -873,  -873,  -873,
    -873,  -873,  -873,  -873,  -873,  -873,  -873,   506,  -873,  -873,
    -873,  -873,  -873,  -873,  -873,  -873,  -873,  -873,  -873,  -873,
    -873,  -873,  -873,  -873,  -873,  -873,  -873,  -873,  -873,  -873,
    -873,  -873,  -873,  -873,  -873,  -873,  -873,  -873,  -873,  -873,
    -268,  -873,  -265,  -873,  -269,  -873,  -873,  -873,  -873,  -873,
    -873,  -873,  -759,  -329,  -873,  -873,  -873,  -873,   149,  -607,
    -872,   -55,  -604,   -53,  -873,  -873,  -873,  -873,  -873,  -873,
    -873,  -873,  -873,  -873,  -873,  -873,  -873,  -873,  -873,  -873,
    -873,  -873,  -323,  -873,  -873,  -873,  -317,  -873,  -873,  -873
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   728,   170,   171,   172,   173,   190,   356,   357,   174,
     175,   412,   611,   612,   477,   201,   202,   203,   179,   180,
     181,   452,   453,   454,   185,   186,   187,   446,   191,   192,
     193,   206,   207,   208,   213,   214,   215,   259,   260,   261,
     237,   238,   239,   241,   242,   243,   246,   247,   248,   221,
     222,   223,   227,   231,   268,   228,   263,   264,   265,   286,
     812,   886,   814,   887,   816,   888,   225,   683,   685,   684,
     281,   284,   836,   530,   288,   531,   532,   706,   289,   729,
     840,   295,   727,   176,   615,   614,   306,   720,   307,   310,
     313,   321,   323,    81,   232,   535,   556,   710,   712,   331,
     555,   332,    82,   561,    83,   333,    84,   552,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     169,   401,   296,   558,   189,   297,   781,   204,   780,   177,
     560,   224,   450,   325,   456,   326,   600,   236,   562,   563,
     249,   250,   327,   458,   326,   460,   462,   256,   257,   328,
     396,   327,   195,   269,   272,   410,   188,   958,   328,   276,
     196,   280,   358,   522,   285,   629,   386,  -491,   188,   384,
     717,   169,   298,   -64,     3,   309,  -491,   197,   312,   314,
     315,   627,   628,   428,   429,   244,   317,   767,   496,   301,
      85,  -333,   441,   442,   797,   904,   209,   302,   907,   805,
     522,   252,   345,   428,   429,   198,   199,   982,   210,   211,
     499,   798,   523,   524,   525,   382,   363,   318,   806,   229,
      86,   230,   182,   526,   774,   776,   838,   183,   841,   407,
     273,   989,   266,   383,   267,   408,   500,   497,   846,   799,
     800,   385,   718,   851,   441,   447,   630,   719,   245,   523,
     524,   525,   303,   304,   305,   253,   775,   573,   194,   212,
     526,   527,   226,   443,   444,   445,   956,   184,   415,   416,
     319,   320,   417,   528,   418,   419,   420,   421,   422,   498,
     329,   529,   901,   413,   359,   414,   411,   880,   387,   329,
     431,   828,   871,   430,   537,   434,   436,   438,   527,   909,
     570,   571,   360,   274,   881,   397,   388,   538,   923,   925,
     528,   572,   910,   430,   902,   443,   444,   448,   529,   426,
     178,   427,   489,   451,   240,   457,   661,   251,   349,   663,
     715,   492,   882,   883,   459,   662,   461,   463,   664,   539,
     924,   926,   254,   200,   911,   501,   502,   672,   703,   704,
     255,   330,   258,   504,   262,   723,   673,   506,   731,   705,
     330,   423,   917,   916,   674,   778,  -359,   511,   512,   424,
    -359,   513,  -359,   675,   293,   294,   270,   350,   351,   352,
     271,   465,   466,   277,   516,   517,   353,   354,   355,   467,
     299,   300,   282,   468,   469,   520,   216,   217,   218,   219,
    -358,   283,   470,   287,  -358,   290,  -358,   291,   220,   632,
     633,   471,   292,   472,   473,   547,   548,   549,   550,   657,
     658,   542,   474,   475,   544,   659,   660,   322,   403,   546,
     316,   404,   405,   476,   668,   669,   324,   551,   406,   334,
     553,   618,   619,   620,   621,   622,   623,   624,   625,   670,
     671,   415,   416,   616,   617,   335,   336,   337,   338,   574,
     576,   578,   346,   347,   348,   361,   362,   364,   365,   366,
     367,   425,   368,   369,   581,   582,   389,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   205,   465,   478,   370,   371,   372,
     373,   374,   375,   479,   376,   390,   377,   480,   481,   606,
     378,   607,   608,   379,   380,   381,   482,   391,   392,   393,
     394,   395,   398,   402,   275,   483,   409,   484,   485,   491,
     433,   440,   188,   464,   503,   510,   486,   487,   494,   495,
     508,   515,   509,   518,   519,   521,   636,   476,   533,   534,
    -449,   540,   536,   541,   543,   545,   554,   557,   564,   602,
     565,   566,   567,   642,   568,   569,   638,   573,   639,   580,
     601,   603,   604,   605,   609,   610,   645,   -66,   613,   655,
     640,   644,   634,   647,   635,   641,   649,   651,   653,   656,
     687,   686,   665,   667,   688,   676,   693,   694,   698,   700,
     701,   707,   713,   708,   677,   716,   711,   679,   681,   714,
     785,   786,   725,   730,   733,   697,   689,   734,   735,   738,
     739,   690,   748,   692,   736,   737,   749,   740,   695,   750,
     751,   699,   756,   741,   702,   742,   743,   744,   745,   746,
     752,   762,   753,   754,   755,   757,   758,   759,   760,   761,
     763,   764,   765,   766,   779,   768,   721,   432,   722,   769,
     773,   787,   435,   437,   439,   784,   788,   724,   793,   726,
     794,   818,   811,   813,   820,   455,   815,   732,   821,   822,
     826,   782,   783,   827,   817,   833,   834,   830,   837,   490,
     831,   835,   843,   747,   847,   849,   850,   839,   493,   852,
     853,   856,   960,   854,   855,   865,   844,   866,   867,   868,
     776,   873,   428,   823,   875,   877,   770,   771,   772,   848,
     505,   872,   777,   878,   507,   726,   879,   169,   169,   876,
     884,   845,   885,  -300,  -303,  -306,   892,   889,   514,   896,
     905,   938,   939,   897,   906,   915,   919,   864,   918,   921,
     922,   789,   927,   791,   928,   929,   930,   795,   933,   934,
     935,   942,   943,   944,   874,   947,   948,   954,   951,   807,
     908,   949,   953,   950,   959,   955,   912,   957,   808,   842,
     913,   961,   963,   964,   936,   937,   967,   968,   969,   971,
     970,   983,   988,   626,   973,   975,   972,   979,   974,   986,
     987,   819,   709,     0,     0,     0,   824,   825,     0,     0,
       0,     0,     0,     0,   832,     0,   449,     0,     0,     0,
       0,     0,   488,   726,     0,   726,   575,   577,   579,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   857,   858,   859,   860,     0,     0,     0,     0,   861,
       0,     0,     0,     0,     0,   862,   863,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   869,     0,   870,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   914,     0,
       0,     0,     0,   637,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     643,   890,     0,   893,   894,     0,   646,     0,   648,   898,
     650,     0,   652,   900,   654,     0,   903,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   666,     0,
     726,     0,     0,     0,     0,   920,     0,     0,     0,     0,
       0,   678,     0,     0,   680,   682,     0,     0,     0,     0,
     931,   932,     0,     0,     0,     0,     0,     0,   691,     0,
       0,     0,     0,     0,     0,   696,     0,   940,     0,     0,
       0,     0,   945,     0,     0,   946,     0,     0,     0,     0,
       0,     0,     0,     0,   952,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   962,     0,     0,     0,     0,   965,     0,   966,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     976,   977,     0,     0,   978,     0,   980,   981,     0,     0,
       0,     0,     0,     0,   984,     0,   985,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   990,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   790,
       0,   792,     0,     0,   796,     0,     0,   801,     0,   802,
       0,   803,     0,   804,     0,     0,     0,     0,     0,     0,
       0,     4,     0,     0,     0,     0,     0,   809,     5,     6,
       0,     0,     0,     0,     0,     0,   810,     0,     0,     0,
       7,     0,     0,     0,     8,     9,     0,    10,     0,    11,
      12,     0,    13,    14,     0,     0,     0,     0,   829,     0,
      15,     0,    16,    17,    18,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,    20,     0,     0,     0,     0,
      21,    22,    23,    24,    25,    26,     0,     0,     0,     0,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,     0,
      29,    30,     0,    31,     0,     0,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,     0,    42,     0,
       0,     0,    43,    44,    45,    46,    47,     0,    48,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,     0,     0,     0,     0,     0,     0,
       0,    51,     0,     0,    52,     0,    53,    54,    55,     0,
       0,    56,     0,     0,     0,    57,     0,    58,   891,     0,
      59,    60,   895,     0,     0,     0,    61,   899,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,     4,     0,    74,    75,    76,    77,    78,     5,     6,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     0,     0,     0,     8,     9,     0,    10,     0,    11,
      12,     0,    13,    14,     0,     0,     0,    79,     0,    80,
      15,     0,    16,    17,    18,   941,     0,     0,     0,    19,
       0,     0,     0,     0,     0,    20,     0,     0,     0,     0,
      21,    22,    23,    24,    25,    26,     0,     0,     0,     0,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,     0,
      29,    30,     0,    31,     0,     0,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,     0,    42,     0,
       0,     0,    43,    44,    45,    46,    47,     0,    48,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,     0,     0,     0,     0,     0,     0,
       0,    51,     0,   308,    52,    87,    53,    54,    55,     0,
       0,    56,     0,     0,     0,    57,     0,    58,     0,     0,
      59,    60,     0,     0,    88,     0,    61,     0,    62,    63,
      64,    65,    66,    67,    89,    68,    69,    70,    71,    72,
      73,     0,     0,    74,    75,    76,    77,    78,     0,     0,
      90,    91,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    93,     0,     0,
      94,     0,     0,    95,     0,     0,     0,   559,     0,     0,
       0,     0,     0,    96,    97,     0,    98,     0,     0,     0,
       0,     0,    99,   100,   101,   102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   104,   105,
       0,     0,     0,     0,     0,     0,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,     0,   121,   122,   123,     0,
     124,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   126,     0,   127,     0,   128,     0,
       0,     0,     0,     0,     0,     0,   129,     0,     0,   130,
       0,     0,   131,     0,   132,   133,   134,   135,     0,   136,
     137,     0,     0,     0,     0,   138,   139,   140,   141,     0,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,     0,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   311,     0,
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
      87,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,     0,     0,     0,     0,     0,     0,    88,
     339,     0,     0,     0,     0,     0,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,     0,     0,    94,     0,     0,    95,   340,
     341,   342,     0,     0,     0,     0,     0,     0,    96,    97,
     343,    98,     0,     0,     0,     0,     0,    99,   100,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   103,   104,   105,     0,     0,     0,     0,     0,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,     0,     0,     0,   118,   119,   120,
     344,   121,   122,   123,     0,   124,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   126,
       0,   127,     0,   128,     0,     0,     0,     0,     0,     0,
       0,   129,     0,     0,   130,     0,     0,   131,     0,   132,
     133,   134,   135,     0,   136,   137,     0,     0,     0,     0,
     138,   139,   140,   141,     0,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
      87,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,     0,     0,     0,     0,     0,     0,   233,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
       0,   234,   235,     0,     0,     0,     0,     0,     0,     0,
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
      87,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,     0,     0,     0,     0,     0,     0,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,   278,   279,     0,
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
      87,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,     0,     0,     0,     0,     0,     0,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,     0,     0,    94,     0,     0,    95,     0,
       0,     0,     0,     0,     0,     0,     0,   188,    96,    97,
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
       0,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   338,     0,     0,     0,     0,     0,
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
     154,   155,   156,    87,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,     0,     0,     0,     0,
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
     154,   155,   156,    87,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,     0,     0,     0,     0,
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
     118,   119,   120,     0,   121,   122,   123,     0,   124,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   126,     0,   127,     0,   128,     0,     0,     0,
       0,     0,     0,     0,   129,     0,     0,   130,     0,     0,
     131,     0,   132,   133,   134,   135,     0,   136,   137,     0,
       0,     0,     0,   138,   139,   140,   141,     0,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,    87,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,     0,     0,     0,     0,
       0,     0,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,     0,     0,    94,     0,
       0,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,     0,    98,     0,     0,     0,     0,     0,
      99,   100,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   631,   104,   105,     0,     0,
       0,     0,     0,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,     0,   121,   122,   123,     0,   124,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   126,     0,   127,     0,   128,     0,     0,     0,
       0,     0,     0,     0,   129,     0,     0,   130,     0,     0,
     131,     0,   132,   133,   134,   135,     0,   136,   137,     0,
       0,     0,     0,   138,   139,   140,   400,     0,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,    87,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,     0,     0,     0,     0,
       0,     0,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   399,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,   138,   139,   140,   400,     0,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,    87,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,     0,     0,     0,     0,
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
       0,     0,     0,   138,   139,   140,   400,     0,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,     0,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168
};

static const yytype_int16 yycheck[] =
{
       7,   141,    57,   332,    11,    58,   613,    14,   612,    28,
     333,    18,    28,     4,    28,     6,   381,    24,   335,   336,
      27,    28,    13,    28,     6,    28,    28,    34,    35,    20,
      38,    13,    28,    40,    72,    20,    86,   909,    20,    46,
      36,    48,    20,    29,    51,   111,    20,    38,    86,    90,
      90,    58,    59,    38,     0,    62,    38,    53,    65,    66,
      67,   426,   427,    23,    24,    28,    73,     7,    57,   101,
     219,    20,    83,    84,    36,   834,    28,   109,   837,    33,
      29,    94,    89,    23,    24,    81,    82,   959,    40,    41,
      20,    53,    78,    79,    80,    20,   103,    45,    52,   219,
     219,   221,    30,    89,     7,     7,   710,    35,   712,   202,
     148,   983,   219,    38,   221,   208,    46,   106,   725,    81,
      82,   162,   162,   730,    83,    84,   192,   167,    91,    78,
      79,    80,   164,   165,   166,   148,    39,    39,    26,    91,
      89,   127,   219,   154,   155,   156,   905,    75,     8,     9,
      98,    99,    12,   139,    14,    15,    16,    17,    18,   148,
     151,   147,     7,     5,   142,     7,   151,    36,   142,   151,
     177,   221,   779,   133,     7,   182,   183,   184,   127,     7,
      78,    79,   160,   221,    53,   193,   160,    20,     7,     7,
     139,    89,    20,   133,    39,   154,   155,   156,   147,    19,
     219,    21,   209,   219,    28,   219,    49,    94,    29,    49,
     539,   218,    81,    82,   219,    58,   219,   219,    58,    52,
      39,    39,    38,   219,    52,   232,   233,    49,    78,    79,
      38,   222,    28,   240,    28,   552,    58,   244,   561,    89,
     222,   101,   849,   847,    49,   610,     0,   254,   255,   109,
       4,   258,     6,    58,   219,   220,   148,    78,    79,    80,
      72,    28,    29,   219,   271,   272,    87,    88,    89,    36,
      46,    47,    38,    40,    41,   282,    46,    47,    48,    49,
       0,   219,    49,   219,     4,   219,     6,   219,    58,   429,
     430,    58,   219,    60,    61,    98,    99,    96,    97,    60,
      61,   308,    69,    70,   311,    60,    61,    45,   198,   316,
     176,   201,   202,    80,    60,    61,    13,   324,   208,     6,
     327,   417,   418,   419,   420,   421,   422,   423,   424,    60,
      61,     8,     9,   415,   416,     4,     4,   221,    20,   346,
     347,   348,    38,    38,    38,    38,    38,    38,    38,    38,
      38,   134,    38,    38,   361,   362,    20,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,    14,    28,    29,    38,    38,    38,
      38,    38,    38,    36,    38,    20,    38,    40,    41,   396,
      38,   398,   399,    38,    38,    38,    49,    20,    20,    20,
      20,    20,    38,   201,    44,    58,   201,    60,    61,    33,
      28,   221,    86,    28,     7,   151,    69,    70,    50,    50,
      33,    38,    73,    13,   156,     7,   433,    80,     7,   151,
     151,     7,   151,     7,     7,     7,    13,    38,    38,   219,
      39,    39,    39,   450,    39,    39,    76,    39,    76,    38,
      38,    38,    38,    38,    38,    25,    52,    38,    38,   466,
      76,    28,    33,    28,    33,    76,    28,    28,    28,    37,
     219,    46,    38,    37,     7,    38,     7,     7,     7,   106,
       7,    38,   537,    20,   491,   540,   151,   494,   495,     7,
     630,   631,    38,    38,   221,    73,   503,   221,   221,    39,
      39,   508,     7,   510,   221,   221,     7,    39,   515,     7,
       7,   518,     7,    39,   521,    39,    39,    39,    39,    39,
      39,     7,    39,    39,    39,    39,    39,    39,    39,    39,
       7,    39,    39,    39,    38,   219,   543,   177,   545,    39,
      39,   219,   182,   183,   184,   192,   219,   554,    33,   556,
      33,    13,   219,   219,     7,   195,   219,   564,    46,    46,
       7,   614,   615,     7,   219,     7,    38,    76,    38,   209,
     219,   221,     7,   580,     7,     7,    39,   219,   218,     7,
     221,    39,   911,   221,   221,    39,   169,    39,     7,     7,
       7,    39,    23,   152,   219,    33,   603,   604,   605,   152,
     240,   152,   609,    33,   244,   612,   220,   614,   615,   219,
       7,   169,     7,     7,     7,     7,     7,    13,   258,    39,
       7,    33,    33,    39,    39,    39,    39,   767,    13,    39,
      39,   638,    39,   640,    39,    39,    39,   644,    39,    39,
      39,     7,     7,     7,   784,    13,    13,    76,   119,   656,
     152,    39,    13,    39,     7,    39,   152,    39,   665,   714,
     152,    13,    13,    39,   220,   220,    39,    39,   220,    39,
     220,     7,    13,   425,   942,   944,    39,    39,   943,    39,
      39,   688,   533,    -1,    -1,    -1,   693,   694,    -1,    -1,
      -1,    -1,    -1,    -1,   701,    -1,   190,    -1,    -1,    -1,
      -1,    -1,   205,   710,    -1,   712,   346,   347,   348,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   748,   749,   750,   751,    -1,    -1,    -1,    -1,   756,
      -1,    -1,    -1,    -1,    -1,   762,   763,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   774,    -1,   776,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   843,    -1,
      -1,    -1,    -1,   433,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     450,   818,    -1,   820,   821,    -1,   456,    -1,   458,   826,
     460,    -1,   462,   830,   464,    -1,   833,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   478,    -1,
     847,    -1,    -1,    -1,    -1,   852,    -1,    -1,    -1,    -1,
      -1,   491,    -1,    -1,   494,   495,    -1,    -1,    -1,    -1,
     867,   868,    -1,    -1,    -1,    -1,    -1,    -1,   508,    -1,
      -1,    -1,    -1,    -1,    -1,   515,    -1,   884,    -1,    -1,
      -1,    -1,   889,    -1,    -1,   892,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   901,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   918,    -1,    -1,    -1,    -1,   923,    -1,   925,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     947,   948,    -1,    -1,   951,    -1,   953,   954,    -1,    -1,
      -1,    -1,    -1,    -1,   961,    -1,   963,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   988,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   639,
      -1,   641,    -1,    -1,   644,    -1,    -1,   647,    -1,   649,
      -1,   651,    -1,   653,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    -1,    -1,    -1,    -1,   667,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,   676,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    26,    27,    -1,    29,    -1,    31,
      32,    -1,    34,    35,    -1,    -1,    -1,    -1,   698,    -1,
      42,    -1,    44,    45,    46,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,
      92,    93,    -1,    95,    -1,    -1,    98,    99,   100,    -1,
     102,   103,   104,   105,   106,   107,   108,    -1,   110,    -1,
      -1,    -1,   114,   115,   116,   117,   118,    -1,   120,   121,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   143,    -1,    -1,   146,    -1,   148,   149,   150,    -1,
      -1,   153,    -1,    -1,    -1,   157,    -1,   159,   818,    -1,
     162,   163,   822,    -1,    -1,    -1,   168,   827,   170,   171,
     172,   173,   174,   175,    -1,   177,   178,   179,   180,   181,
     182,     3,    -1,   185,   186,   187,   188,   189,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    26,    27,    -1,    29,    -1,    31,
      32,    -1,    34,    35,    -1,    -1,    -1,   219,    -1,   221,
      42,    -1,    44,    45,    46,   885,    -1,    -1,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,
      92,    93,    -1,    95,    -1,    -1,    98,    99,   100,    -1,
     102,   103,   104,   105,   106,   107,   108,    -1,   110,    -1,
      -1,    -1,   114,   115,   116,   117,   118,    -1,   120,   121,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   143,    -1,     7,   146,     9,   148,   149,   150,    -1,
      -1,   153,    -1,    -1,    -1,   157,    -1,   159,    -1,    -1,
     162,   163,    -1,    -1,    28,    -1,   168,    -1,   170,   171,
     172,   173,   174,   175,    38,   177,   178,   179,   180,   181,
     182,    -1,    -1,   185,   186,   187,   188,   189,    -1,    -1,
      54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      74,    -1,    -1,    77,    -1,    -1,    -1,   219,    -1,    -1,
      -1,    -1,    -1,    87,    88,    -1,    90,    -1,    -1,    -1,
      -1,    -1,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,    -1,   136,   137,   138,    -1,   140,   141,   142,    -1,
     144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   158,    -1,   160,    -1,   162,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,   173,
      -1,    -1,   176,    -1,   178,   179,   180,   181,    -1,   183,
     184,    -1,    -1,    -1,    -1,   189,   190,   191,   192,    -1,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    -1,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,     7,    -1,
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
       9,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    74,    -1,    -1,    77,    78,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      89,    90,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,    -1,   136,   137,   138,
     139,   140,   141,   142,    -1,   144,   145,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,
      -1,   160,    -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   170,    -1,    -1,   173,    -1,    -1,   176,    -1,   178,
     179,   180,   181,    -1,   183,   184,    -1,    -1,    -1,    -1,
     189,   190,   191,   192,    -1,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
       9,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
       9,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    -1,
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
       9,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,    -1,    -1,    28,
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
      -1,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,     9,    -1,    -1,    -1,    -1,    -1,    -1,
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
     206,   207,   208,     9,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
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
     206,   207,   208,     9,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
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
     136,   137,   138,    -1,   140,   141,   142,    -1,   144,   145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   158,    -1,   160,    -1,   162,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   170,    -1,    -1,   173,    -1,    -1,
     176,    -1,   178,   179,   180,   181,    -1,   183,   184,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,     9,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
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
     136,   137,   138,    -1,   140,   141,   142,    -1,   144,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   158,    -1,   160,    -1,   162,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   170,    -1,    -1,   173,    -1,    -1,
     176,    -1,   178,   179,   180,   181,    -1,   183,   184,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,     9,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
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
     206,   207,   208,     9,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
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
     206,   207,   208,    -1,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   331,   332,     0,     3,    10,    11,    22,    26,    27,
      29,    31,    32,    34,    35,    42,    44,    45,    46,    51,
      57,    62,    63,    64,    65,    66,    67,    72,    90,    92,
      93,    95,    98,    99,   100,   102,   103,   104,   105,   106,
     107,   108,   110,   114,   115,   116,   117,   118,   120,   121,
     135,   143,   146,   148,   149,   150,   153,   157,   159,   162,
     163,   168,   170,   171,   172,   173,   174,   175,   177,   178,
     179,   180,   181,   182,   185,   186,   187,   188,   189,   219,
     221,   316,   325,   327,   329,   219,   219,     9,    28,    38,
      54,    55,    56,    71,    74,    77,    87,    88,    90,    96,
      97,    98,    99,   111,   112,   113,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   136,   137,
     138,   140,   141,   142,   144,   145,   158,   160,   162,   170,
     173,   176,   178,   179,   180,   181,   183,   184,   189,   190,
     191,   192,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   224,
     225,   226,   227,   228,   232,   233,   306,    28,   219,   241,
     242,   243,    30,    35,    75,   247,   248,   249,    86,   224,
     229,   251,   252,   253,    26,    28,    36,    53,    81,    82,
     219,   238,   239,   240,   224,   229,   254,   255,   256,    28,
      40,    41,    91,   257,   258,   259,    46,    47,    48,    49,
      58,   272,   273,   274,   224,   289,   219,   275,   278,   219,
     221,   276,   317,    28,    40,    41,   224,   263,   264,   265,
      28,   266,   267,   268,    28,    91,   269,   270,   271,   224,
     224,    94,    94,   148,    38,    38,   224,   224,    28,   260,
     261,   262,    28,   279,   280,   281,   219,   221,   277,   224,
     148,    72,    72,   148,   221,   229,   224,   219,    46,    47,
     224,   293,    38,   219,   294,   224,   282,   219,   297,   301,
     219,   219,   219,   219,   220,   304,   304,   306,   224,    46,
      47,   101,   109,   164,   165,   166,   309,   311,     7,   224,
     312,     7,   224,   313,   224,   224,   176,   224,    45,    98,
      99,   314,    45,   315,    13,     4,     6,    13,    20,   151,
     222,   322,   324,   328,     6,     4,     4,   221,    20,    29,
      78,    79,    80,    89,   139,   224,    38,    38,    38,    29,
      78,    79,    80,    87,    88,    89,   230,   231,    20,   142,
     160,    38,    38,   224,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    20,    38,    90,   162,    20,   142,   160,    20,
      20,    20,    20,    20,    20,    20,    38,   193,    38,    38,
     192,   233,   201,   198,   201,   202,   208,   202,   208,   201,
      20,   151,   234,     5,     7,     8,     9,    12,    14,    15,
      16,    17,    18,   101,   109,   134,    19,    21,    23,    24,
     133,   224,   229,    28,   224,   229,   224,   229,   224,   229,
     221,    83,    84,   154,   155,   156,   250,    84,   156,   250,
      28,   219,   244,   245,   246,   229,    28,   219,    28,   219,
      28,   219,    28,   219,    28,    28,    29,    36,    40,    41,
      49,    58,    60,    61,    69,    70,    80,   237,    29,    36,
      40,    41,    49,    58,    60,    61,    69,    70,   237,   224,
     229,    33,   224,   229,    50,    50,    57,   106,   148,    20,
      46,   224,   224,     7,   224,   229,   224,   229,    33,    73,
     151,   224,   224,   224,   229,    38,   224,   224,    13,   156,
     224,     7,    29,    78,    79,    80,    89,   127,   139,   147,
     296,   298,   299,     7,   151,   318,   151,     7,    20,    52,
       7,     7,   224,     7,   224,     7,   224,    98,    99,    96,
      97,   224,   330,   224,    13,   323,   319,    38,   296,   219,
     325,   326,   329,   329,    38,    39,    39,    39,    39,    39,
      78,    79,    89,    39,   224,   229,   224,   229,   224,   229,
      38,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     228,    38,   219,    38,    38,    38,   224,   224,   224,    38,
      25,   235,   236,    38,   308,   307,   226,   226,   225,   225,
     225,   225,   225,   225,   225,   225,   227,   228,   228,   111,
     192,   111,   233,   233,    33,    33,   224,   229,    76,    76,
      76,    76,   224,   229,    28,    52,   229,    28,   229,    28,
     229,    28,   229,    28,   229,   224,    37,    60,    61,    60,
      61,    49,    58,    49,    58,    38,   229,    37,    60,    61,
      60,    61,    49,    58,    49,    58,    38,   224,   229,   224,
     229,   224,   229,   290,   292,   291,    46,   219,     7,   224,
     224,   229,   224,     7,     7,   224,   229,    73,     7,   224,
     106,     7,   224,    78,    79,    89,   300,    38,    20,   301,
     320,   151,   321,   304,     7,   296,   304,    90,   162,   167,
     310,   224,   224,   329,   224,    38,   224,   305,   224,   302,
      38,   325,   224,   221,   221,   221,   221,   221,    39,    39,
      39,    39,    39,    39,    39,    39,    39,   224,     7,     7,
       7,     7,    39,    39,    39,    39,     7,    39,    39,    39,
      39,    39,     7,     7,    39,    39,    39,     7,   219,    39,
     224,   224,   224,    39,     7,    39,     7,   224,   228,    38,
     305,   302,   306,   306,   192,   233,   233,   219,   219,   224,
     229,   224,   229,    33,    33,   224,   229,    36,    53,    81,
      82,   229,   229,   229,   229,    33,    52,   224,   224,   229,
     229,   219,   283,   219,   285,   219,   287,   219,    13,   224,
       7,    46,    46,   152,   224,   224,     7,     7,   221,   229,
      76,   219,   224,     7,    38,   221,   295,    38,   305,   219,
     303,   305,   304,     7,   169,   169,   302,     7,   152,     7,
      39,   302,     7,   221,   221,   221,    39,   224,   224,   224,
     224,   224,   224,   224,   233,    39,    39,     7,     7,   224,
     224,   302,   152,    39,   233,   219,   219,    33,    33,   220,
      36,    53,    81,    82,     7,     7,   284,   286,   288,    13,
     224,   229,     7,   224,   224,   229,    39,    39,   224,   229,
     224,     7,    39,   224,   295,     7,    39,   295,   152,     7,
      20,    52,   152,   152,   304,    39,   305,   302,    13,    39,
     224,    39,    39,     7,    39,     7,    39,    39,    39,    39,
      39,   224,   224,    39,    39,    39,   220,   220,    33,    33,
     224,   229,     7,     7,     7,   224,   224,    13,    13,    39,
      39,   119,   224,    13,    76,    39,   295,    39,   303,     7,
     296,    13,   224,    13,    39,   224,   224,    39,    39,   220,
     220,    39,    39,   283,   285,   287,   224,   224,   224,    39,
     224,   224,   303,     7,   224,   224,    39,    39,    13,   303,
     224
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   223,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   225,   225,   225,   226,   226,   227,   227,   227,
     228,   228,   228,   228,   228,   228,   228,   228,   229,   230,
     230,   230,   230,   230,   230,   230,   231,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   234,   233,   235,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   236,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   237,   237,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   239,   239,   239,   239,   239,   240,   240,
     241,   241,   242,   242,   243,   243,   244,   244,   245,   245,
     246,   246,   247,   247,   247,   248,   248,   248,   249,   249,
     250,   250,   250,   251,   251,   251,   252,   252,   252,   253,
     253,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   256,   256,   257,   257,   257,   257,   257,   258,   258,
     259,   259,   260,   261,   262,   262,   263,   263,   264,   264,
     265,   265,   266,   267,   268,   268,   269,   269,   269,   270,
     270,   271,   271,   272,   272,   272,   272,   272,   273,   273,
     273,   274,   274,   275,   275,   275,   275,   275,   275,   276,
     276,   277,   277,   278,   279,   280,   281,   281,   282,   283,
     284,   283,   285,   286,   285,   287,   288,   287,   290,   289,
     291,   289,   292,   289,   293,   293,   293,   294,   294,   295,
     295,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   298,   297,   299,   297,   300,   297,   301,   301,   302,
     302,   303,   303,   303,   303,   303,   303,   304,   304,   304,
     304,   304,   304,   304,   304,   305,   305,   306,   306,   306,
     307,   306,   308,   306,   309,   309,   309,   309,   309,   310,
     310,   310,   310,   310,   311,   312,   312,   312,   313,   313,
     313,   314,   314,   314,   314,   315,   315,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   317,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   318,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   319,
     316,   320,   316,   321,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   322,   316,   323,   316,   324,   316,   316,   316,   316,
     325,   326,   325,   328,   327,   330,   329,   329,   329,   329,
     329,   332,   331
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
       2,     1,     1,     1,     4,     2,     1,     6,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     4,     5,     4,
       3,     5,     4,     4,     3,     4,     5,     4,     3,     5,
       4,     4,     3,     5,     7,     6,     7,     6,     1,     1,
       3,     4,     3,     4,     1,     1,     3,     4,     3,     4,
       1,     1,     2,     4,     4,     2,     4,     4,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     2,     2,     1,
       1,     4,     2,     2,     3,     7,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     2,     2,     3,
       7,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     2,     1,     1,     1,     3,     2,     3,
       1,     1,     2,     2,     1,     1,     1,     1,     6,     5,
       1,     1,     2,     2,     1,     1,     2,     1,     5,     2,
       5,     1,     1,     1,     1,     2,     3,     3,     2,     3,
       3,     1,     1,     0,     3,     4,     5,     5,     6,     1,
       1,     1,     1,     1,     6,     6,     1,     1,     1,     1,
       0,     4,     1,     0,     4,     1,     0,     4,     0,     4,
       0,     4,     0,     4,     4,     1,     1,     3,     7,     1,
       3,     1,     2,     1,     2,     1,     2,     1,     1,     1,
       1,     0,     5,     0,     6,     0,     6,     1,     3,     1,
       3,     1,     2,     3,     3,     4,     5,     1,     2,     3,
       3,     4,     5,     1,     3,     1,     3,     1,     2,     2,
       0,     4,     0,     4,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     2,     3,     2,     2,     3,     2,     2,
       3,     1,     2,     1,     2,     2,     2,     2,     2,     3,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     3,     2,     2,     2,     2,     1,     1,     2,
       2,     2,     1,     1,     1,     1,     1,     2,     3,     2,
       2,     1,     1,     2,     2,     1,     2,     3,     1,     4,
       1,     1,     1,     0,     3,     1,     1,     2,     1,     2,
       2,     3,     2,     2,     5,     5,     6,     1,     2,     0,
       6,     2,     2,     2,     5,     8,     2,     2,     2,     0,
       5,     0,     6,     0,     6,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     2,     2,     2,     2,
       1,     2,     1,     1,     8,     8,     8,    10,     2,     3,
       4,     0,     7,     0,     8,     0,     8,     2,     1,     0,
       1,     0,     4,     0,     3,     0,     4,     1,     3,     1,
       3,     0,     2
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
#line 3093 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 84 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3102 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 88 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3110 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 91 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3118 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 94 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3126 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 97 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 3134 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 100 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3142 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 103 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3150 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 106 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 3158 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 113 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3166 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 116 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3175 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 129 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3184 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 133 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3193 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 141 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 3202 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 145 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 3211 "src-generated/ugbc.tab.c"
    break;

  case 23: /* factor: factor HAS BIT exponential  */
#line 149 "src/ugbc.y"
                                   {
        (yyval.string) = variable_bit( _environment, (yyvsp[-3].string), (yyvsp[0].string) )->name;
      }
#line 3219 "src-generated/ugbc.tab.c"
    break;

  case 24: /* factor: factor HAS NOT BIT exponential  */
#line 152 "src/ugbc.y"
                                       {
        (yyval.string) = variable_not( _environment, variable_bit( _environment, (yyvsp[-4].string), (yyvsp[0].string) )->name )->name;
      }
#line 3227 "src-generated/ugbc.tab.c"
    break;

  case 25: /* factor: factor IS exponential  */
#line 155 "src/ugbc.y"
                              {
        (yyval.string) = variable_bit( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
      }
#line 3235 "src-generated/ugbc.tab.c"
    break;

  case 26: /* factor: factor IS NOT exponential  */
#line 158 "src/ugbc.y"
                                  {
        (yyval.string) = variable_not( _environment, variable_bit( _environment, (yyvsp[-3].string), (yyvsp[0].string) )->name )->name;
      }
#line 3243 "src-generated/ugbc.tab.c"
    break;

  case 27: /* factor: BIT exponential OF factor  */
#line 161 "src/ugbc.y"
                                  {
        (yyval.string) = variable_bit( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
      }
#line 3251 "src-generated/ugbc.tab.c"
    break;

  case 28: /* direct_integer: HASH Integer  */
#line 167 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 3259 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: BYTE  */
#line 172 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 3267 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: WORD  */
#line 175 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 3275 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition_simple: DWORD  */
#line 178 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 3283 "src-generated/ugbc.tab.c"
    break;

  case 32: /* random_definition_simple: POSITION  */
#line 181 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 3291 "src-generated/ugbc.tab.c"
    break;

  case 33: /* random_definition_simple: COLOR  */
#line 184 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 3299 "src-generated/ugbc.tab.c"
    break;

  case 34: /* random_definition_simple: WIDTH  */
#line 187 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 3307 "src-generated/ugbc.tab.c"
    break;

  case 35: /* random_definition_simple: HEIGHT  */
#line 190 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 3315 "src-generated/ugbc.tab.c"
    break;

  case 36: /* random_definition: random_definition_simple  */
#line 195 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 3323 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: BLACK  */
#line 200 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 3332 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: WHITE  */
#line 204 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 3341 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: RED  */
#line 208 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 3350 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: CYAN  */
#line 212 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 3359 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: VIOLET  */
#line 216 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 3368 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: GREEN  */
#line 220 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 3377 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: BLUE  */
#line 224 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 3386 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: YELLOW  */
#line 228 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 3395 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: ORANGE  */
#line 232 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 3404 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: BROWN  */
#line 236 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 3413 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT RED  */
#line 240 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 3422 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK GREY  */
#line 244 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 3431 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: GREY  */
#line 248 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 3440 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: LIGHT GREEN  */
#line 252 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 3449 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LIGHT BLUE  */
#line 256 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 3458 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: LIGHT GREY  */
#line 260 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 3467 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: DARK BLUE  */
#line 264 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 3476 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: MAGENTA  */
#line 268 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 3485 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: PURPLE  */
#line 272 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 3494 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: LAVENDER  */
#line 276 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 3503 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: GOLD  */
#line 280 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 3512 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: TURQUOISE  */
#line 284 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 3521 "src-generated/ugbc.tab.c"
    break;

  case 59: /* color_enumeration: TAN  */
#line 288 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 3530 "src-generated/ugbc.tab.c"
    break;

  case 60: /* color_enumeration: YELLOW GREEN  */
#line 292 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 3539 "src-generated/ugbc.tab.c"
    break;

  case 61: /* color_enumeration: OLIVE GREEN  */
#line 296 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 3548 "src-generated/ugbc.tab.c"
    break;

  case 62: /* color_enumeration: PINK  */
#line 300 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 3557 "src-generated/ugbc.tab.c"
    break;

  case 63: /* color_enumeration: PEACH  */
#line 304 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 3566 "src-generated/ugbc.tab.c"
    break;

  case 64: /* $@1: %empty  */
#line 310 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 3575 "src-generated/ugbc.tab.c"
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
#line 3587 "src-generated/ugbc.tab.c"
    break;

  case 66: /* $@2: %empty  */
#line 321 "src/ugbc.y"
                        {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 3596 "src-generated/ugbc.tab.c"
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
#line 3608 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: Identifier  */
#line 332 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 3616 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: Identifier DOLLAR  */
#line 335 "src/ugbc.y"
                        { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 3624 "src-generated/ugbc.tab.c"
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
#line 3638 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: MINUS Integer  */
#line 347 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3647 "src-generated/ugbc.tab.c"
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
#line 3659 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP BYTE CP Integer  */
#line 358 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3668 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP SIGNED BYTE CP Integer  */
#line 362 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3677 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP WORD CP Integer  */
#line 366 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3686 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: OP SIGNED WORD CP Integer  */
#line 370 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3695 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: OP DWORD CP Integer  */
#line 374 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3704 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: OP SIGNED DWORD CP Integer  */
#line 378 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3713 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: OP POSITION CP Integer  */
#line 382 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3722 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: OP COLOR CP Integer  */
#line 386 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3731 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: color_enumeration  */
#line 390 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3739 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: PEEK OP direct_integer CP  */
#line 393 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3747 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: PEEK OP expr CP  */
#line 396 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3755 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: XPEN  */
#line 399 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3763 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: YPEN  */
#line 402 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3771 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: COLLISION OP direct_integer CP  */
#line 405 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3779 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: COLLISION OP expr CP  */
#line 408 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3787 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: HIT OP direct_integer CP  */
#line 411 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3795 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: HIT OP expr CP  */
#line 414 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3803 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: LEFT OP expr COMMA expr CP  */
#line 417 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3811 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 420 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3819 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: MID OP expr COMMA expr CP  */
#line 423 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3827 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 426 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3835 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: INSTR OP expr COMMA expr CP  */
#line 429 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3843 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 432 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3851 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: UPPER OP expr CP  */
#line 435 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3859 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: LOWER OP expr CP  */
#line 438 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3867 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: STR OP expr CP  */
#line 441 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3875 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: BIN OP expr CP  */
#line 444 "src/ugbc.y"
                     {
        (yyval.string) = variable_bin( _environment, (yyvsp[-1].string), NULL )->name;
    }
#line 3883 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: BIN OP expr COMMA expr CP  */
#line 447 "src/ugbc.y"
                                {
        (yyval.string) = variable_bin( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3891 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: SPACE OP expr CP  */
#line 450 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3899 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: FLIP OP expr CP  */
#line 453 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3907 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: CHR OP expr CP  */
#line 456 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3915 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: ASC OP expr CP  */
#line 459 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3923 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: LEN OP expr CP  */
#line 462 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3931 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: STRING OP expr COMMA expr CP  */
#line 465 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3939 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: VAL OP expr CP  */
#line 468 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3947 "src-generated/ugbc.tab.c"
    break;

  case 108: /* exponential: RANDOM random_definition  */
#line 471 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3955 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: RND OP expr CP  */
#line 474 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 3963 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: OP expr CP  */
#line 477 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3971 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: MAX OP expr COMMA expr CP  */
#line 480 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3979 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: MIN OP expr COMMA expr CP  */
#line 483 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3987 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: PARAM OP Identifier CP  */
#line 486 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3995 "src-generated/ugbc.tab.c"
    break;

  case 114: /* exponential: PARAM DOLLAR OP Identifier CP  */
#line 489 "src/ugbc.y"
                                    {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 4003 "src-generated/ugbc.tab.c"
    break;

  case 115: /* $@3: %empty  */
#line 492 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 4011 "src-generated/ugbc.tab.c"
    break;

  case 116: /* exponential: Identifier OSP $@3 values CSP  */
#line 494 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 4020 "src-generated/ugbc.tab.c"
    break;

  case 117: /* exponential: SGN OP expr CP  */
#line 498 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 4028 "src-generated/ugbc.tab.c"
    break;

  case 118: /* exponential: ABS OP expr CP  */
#line 501 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 4036 "src-generated/ugbc.tab.c"
    break;

  case 119: /* exponential: TRUE  */
#line 504 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 4045 "src-generated/ugbc.tab.c"
    break;

  case 120: /* exponential: FALSE  */
#line 508 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 4054 "src-generated/ugbc.tab.c"
    break;

  case 121: /* exponential: COLORS  */
#line 512 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 4063 "src-generated/ugbc.tab.c"
    break;

  case 122: /* exponential: PEN COLORS  */
#line 516 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 4072 "src-generated/ugbc.tab.c"
    break;

  case 123: /* exponential: PEN DEFAULT  */
#line 520 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 4081 "src-generated/ugbc.tab.c"
    break;

  case 124: /* exponential: DEFAULT PEN  */
#line 524 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 4090 "src-generated/ugbc.tab.c"
    break;

  case 125: /* exponential: PAPER COLORS  */
#line 528 "src/ugbc.y"
                   {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 4099 "src-generated/ugbc.tab.c"
    break;

  case 126: /* exponential: PAPER DEFAULT  */
#line 532 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 4108 "src-generated/ugbc.tab.c"
    break;

  case 127: /* exponential: DEFAULT PAPER  */
#line 536 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 4117 "src-generated/ugbc.tab.c"
    break;

  case 128: /* exponential: WIDTH  */
#line 540 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 4125 "src-generated/ugbc.tab.c"
    break;

  case 129: /* exponential: HEIGHT  */
#line 543 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 4133 "src-generated/ugbc.tab.c"
    break;

  case 130: /* exponential: TIMER  */
#line 546 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 4141 "src-generated/ugbc.tab.c"
    break;

  case 131: /* exponential: PEN DOLLAR OP expr CP  */
#line 549 "src/ugbc.y"
                            {
        (yyval.string) = text_get_pen( _environment, (yyvsp[-1].string) )->name;
    }
#line 4149 "src-generated/ugbc.tab.c"
    break;

  case 132: /* exponential: PAPER DOLLAR OP expr CP  */
#line 552 "src/ugbc.y"
                              {
        (yyval.string) = text_get_paper( _environment, (yyvsp[-1].string) )->name;
    }
#line 4157 "src-generated/ugbc.tab.c"
    break;

  case 133: /* exponential: CMOVE DOLLAR OP expr COMMA expr CP  */
#line 555 "src/ugbc.y"
                                         {
        (yyval.string) = text_get_cmove( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4165 "src-generated/ugbc.tab.c"
    break;

  case 134: /* exponential: CUP DOLLAR  */
#line 558 "src/ugbc.y"
                 {
        (yyval.string) = text_get_cmove_direct( _environment, 0, -1 )->name;
    }
#line 4173 "src-generated/ugbc.tab.c"
    break;

  case 135: /* exponential: CDOWN DOLLAR  */
#line 561 "src/ugbc.y"
                   {
        (yyval.string) = text_get_cmove_direct( _environment, 0, 1 )->name;
    }
#line 4181 "src-generated/ugbc.tab.c"
    break;

  case 136: /* exponential: CLEFT DOLLAR  */
#line 564 "src/ugbc.y"
                   {
        (yyval.string) = text_get_cmove_direct( _environment, -1, 0 )->name;
    }
#line 4189 "src-generated/ugbc.tab.c"
    break;

  case 137: /* exponential: CRIGHT DOLLAR  */
#line 567 "src/ugbc.y"
                    {
        (yyval.string) = text_get_cmove_direct( _environment, 1, 0 )->name;
    }
#line 4197 "src-generated/ugbc.tab.c"
    break;

  case 138: /* exponential: AT DOLLAR OP expr COMMA expr CP  */
#line 570 "src/ugbc.y"
                                      {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4205 "src-generated/ugbc.tab.c"
    break;

  case 139: /* exponential: LOCATE DOLLAR OP expr COMMA expr CP  */
#line 573 "src/ugbc.y"
                                          {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4213 "src-generated/ugbc.tab.c"
    break;

  case 140: /* exponential: TAB DOLLAR  */
#line 576 "src/ugbc.y"
                 {
        (yyval.string) = text_get_tab( _environment )->name;
    }
#line 4221 "src-generated/ugbc.tab.c"
    break;

  case 141: /* exponential: XCURS  */
#line 579 "src/ugbc.y"
            {
        (yyval.string) = text_get_xcurs( _environment )->name;
    }
#line 4229 "src-generated/ugbc.tab.c"
    break;

  case 142: /* exponential: YCURS  */
#line 582 "src/ugbc.y"
            {
        (yyval.string) = text_get_ycurs( _environment )->name;
    }
#line 4237 "src-generated/ugbc.tab.c"
    break;

  case 143: /* exponential: TEXTADDRESS  */
#line 585 "src/ugbc.y"
                  {
        (yyval.string) = strdup( "TEXTADDRESS" );
    }
#line 4245 "src-generated/ugbc.tab.c"
    break;

  case 144: /* exponential: JOY OP expr CP  */
#line 588 "src/ugbc.y"
                     {
        (yyval.string) = joy( _environment, (yyvsp[-1].string) )->name;
    }
#line 4253 "src-generated/ugbc.tab.c"
    break;

  case 145: /* exponential: JOY COUNT  */
#line 591 "src/ugbc.y"
                {
        (yyval.string) = strdup( "JOYCOUNT");
    }
#line 4261 "src-generated/ugbc.tab.c"
    break;

  case 146: /* exponential: JOYCOUNT  */
#line 594 "src/ugbc.y"
               {
        (yyval.string) = strdup( "JOYCOUNT");
    }
#line 4269 "src-generated/ugbc.tab.c"
    break;

  case 147: /* exponential: BIT OP expr COMMA expr CP  */
#line 597 "src/ugbc.y"
                                {
        (yyval.string) = variable_bit( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4277 "src-generated/ugbc.tab.c"
    break;

  case 148: /* exponential: UP  */
#line 600 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(UP)" )->name;
        variable_store( _environment, (yyval.string), JOY_UP );
    }
#line 4286 "src-generated/ugbc.tab.c"
    break;

  case 149: /* exponential: DOWN  */
#line 604 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(DOWN)" )->name;
        variable_store( _environment, (yyval.string), JOY_DOWN );
    }
#line 4295 "src-generated/ugbc.tab.c"
    break;

  case 150: /* exponential: LEFT  */
#line 608 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(LEFT)" )->name;
        variable_store( _environment, (yyval.string), JOY_LEFT );
    }
#line 4304 "src-generated/ugbc.tab.c"
    break;

  case 151: /* exponential: RIGHT  */
#line 612 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(RIGHT)" )->name;
        variable_store( _environment, (yyval.string), JOY_RIGHT );
    }
#line 4313 "src-generated/ugbc.tab.c"
    break;

  case 152: /* exponential: FIRE  */
#line 616 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(FIRE)" )->name;
        variable_store( _environment, (yyval.string), JOY_FIRE );
    }
#line 4322 "src-generated/ugbc.tab.c"
    break;

  case 155: /* bank_definition_simple: AT direct_integer  */
#line 625 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4330 "src-generated/ugbc.tab.c"
    break;

  case 156: /* bank_definition_simple: Identifier AT direct_integer  */
#line 628 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4338 "src-generated/ugbc.tab.c"
    break;

  case 157: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 631 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 4346 "src-generated/ugbc.tab.c"
    break;

  case 158: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 634 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 4354 "src-generated/ugbc.tab.c"
    break;

  case 159: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 637 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4362 "src-generated/ugbc.tab.c"
    break;

  case 160: /* bank_definition_simple: DATA AT direct_integer  */
#line 640 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4370 "src-generated/ugbc.tab.c"
    break;

  case 161: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 644 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 4378 "src-generated/ugbc.tab.c"
    break;

  case 162: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 647 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 4386 "src-generated/ugbc.tab.c"
    break;

  case 163: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 650 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4394 "src-generated/ugbc.tab.c"
    break;

  case 164: /* bank_definition_simple: CODE AT direct_integer  */
#line 653 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4402 "src-generated/ugbc.tab.c"
    break;

  case 165: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 657 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4410 "src-generated/ugbc.tab.c"
    break;

  case 166: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 660 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4418 "src-generated/ugbc.tab.c"
    break;

  case 167: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 663 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4426 "src-generated/ugbc.tab.c"
    break;

  case 168: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 666 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4434 "src-generated/ugbc.tab.c"
    break;

  case 169: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 670 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4442 "src-generated/ugbc.tab.c"
    break;

  case 170: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 673 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4450 "src-generated/ugbc.tab.c"
    break;

  case 171: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 676 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4458 "src-generated/ugbc.tab.c"
    break;

  case 172: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 679 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4466 "src-generated/ugbc.tab.c"
    break;

  case 173: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 685 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4474 "src-generated/ugbc.tab.c"
    break;

  case 174: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 688 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4482 "src-generated/ugbc.tab.c"
    break;

  case 175: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 691 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4490 "src-generated/ugbc.tab.c"
    break;

  case 176: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 694 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4498 "src-generated/ugbc.tab.c"
    break;

  case 177: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 697 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4506 "src-generated/ugbc.tab.c"
    break;

  case 180: /* raster_definition_simple: Identifier AT direct_integer  */
#line 706 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 4514 "src-generated/ugbc.tab.c"
    break;

  case 181: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 709 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 4522 "src-generated/ugbc.tab.c"
    break;

  case 182: /* raster_definition_expression: Identifier AT expr  */
#line 714 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4530 "src-generated/ugbc.tab.c"
    break;

  case 183: /* raster_definition_expression: AT expr WITH Identifier  */
#line 717 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4538 "src-generated/ugbc.tab.c"
    break;

  case 186: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 726 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 4546 "src-generated/ugbc.tab.c"
    break;

  case 187: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 729 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 4554 "src-generated/ugbc.tab.c"
    break;

  case 188: /* next_raster_definition_expression: Identifier AT expr  */
#line 734 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 4562 "src-generated/ugbc.tab.c"
    break;

  case 189: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 737 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4570 "src-generated/ugbc.tab.c"
    break;

  case 192: /* color_definition_simple: BORDER direct_integer  */
#line 746 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 4578 "src-generated/ugbc.tab.c"
    break;

  case 193: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 749 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4586 "src-generated/ugbc.tab.c"
    break;

  case 194: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 752 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4594 "src-generated/ugbc.tab.c"
    break;

  case 195: /* color_definition_expression: BORDER expr  */
#line 757 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 4602 "src-generated/ugbc.tab.c"
    break;

  case 196: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 760 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4610 "src-generated/ugbc.tab.c"
    break;

  case 197: /* color_definition_expression: SPRITE expr TO expr  */
#line 763 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4618 "src-generated/ugbc.tab.c"
    break;

  case 203: /* wait_definition_simple: direct_integer CYCLES  */
#line 777 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 4626 "src-generated/ugbc.tab.c"
    break;

  case 204: /* wait_definition_simple: direct_integer TICKS  */
#line 780 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 4634 "src-generated/ugbc.tab.c"
    break;

  case 205: /* wait_definition_simple: direct_integer milliseconds  */
#line 783 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 4642 "src-generated/ugbc.tab.c"
    break;

  case 206: /* wait_definition_expression: expr CYCLES  */
#line 788 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 4650 "src-generated/ugbc.tab.c"
    break;

  case 207: /* wait_definition_expression: expr TICKS  */
#line 791 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 4658 "src-generated/ugbc.tab.c"
    break;

  case 208: /* wait_definition_expression: expr milliseconds  */
#line 794 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 4666 "src-generated/ugbc.tab.c"
    break;

  case 211: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 804 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 4674 "src-generated/ugbc.tab.c"
    break;

  case 212: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 807 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 4682 "src-generated/ugbc.tab.c"
    break;

  case 213: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 810 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 4690 "src-generated/ugbc.tab.c"
    break;

  case 214: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 813 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4698 "src-generated/ugbc.tab.c"
    break;

  case 215: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 816 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 4706 "src-generated/ugbc.tab.c"
    break;

  case 216: /* sprite_definition_simple: direct_integer ENABLE  */
#line 819 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 4714 "src-generated/ugbc.tab.c"
    break;

  case 217: /* sprite_definition_simple: direct_integer DISABLE  */
#line 822 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 4722 "src-generated/ugbc.tab.c"
    break;

  case 218: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 825 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4730 "src-generated/ugbc.tab.c"
    break;

  case 219: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 828 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4738 "src-generated/ugbc.tab.c"
    break;

  case 220: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 831 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4746 "src-generated/ugbc.tab.c"
    break;

  case 221: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 834 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4754 "src-generated/ugbc.tab.c"
    break;

  case 222: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 837 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4762 "src-generated/ugbc.tab.c"
    break;

  case 223: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 840 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4770 "src-generated/ugbc.tab.c"
    break;

  case 224: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 843 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4778 "src-generated/ugbc.tab.c"
    break;

  case 225: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 846 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4786 "src-generated/ugbc.tab.c"
    break;

  case 226: /* sprite_definition_expression: expr DATA FROM expr  */
#line 851 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4794 "src-generated/ugbc.tab.c"
    break;

  case 227: /* sprite_definition_expression: expr MULTICOLOR  */
#line 854 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4802 "src-generated/ugbc.tab.c"
    break;

  case 228: /* sprite_definition_expression: expr MONOCOLOR  */
#line 857 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4810 "src-generated/ugbc.tab.c"
    break;

  case 229: /* sprite_definition_expression: expr COLOR expr  */
#line 860 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4818 "src-generated/ugbc.tab.c"
    break;

  case 230: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 863 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 4826 "src-generated/ugbc.tab.c"
    break;

  case 231: /* sprite_definition_expression: expr ENABLE  */
#line 866 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 4834 "src-generated/ugbc.tab.c"
    break;

  case 232: /* sprite_definition_expression: expr DISABLE  */
#line 869 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 4842 "src-generated/ugbc.tab.c"
    break;

  case 233: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 872 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4850 "src-generated/ugbc.tab.c"
    break;

  case 234: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 875 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4858 "src-generated/ugbc.tab.c"
    break;

  case 235: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 878 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4866 "src-generated/ugbc.tab.c"
    break;

  case 236: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 881 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4874 "src-generated/ugbc.tab.c"
    break;

  case 237: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 884 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4882 "src-generated/ugbc.tab.c"
    break;

  case 238: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 887 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4890 "src-generated/ugbc.tab.c"
    break;

  case 239: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 890 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4898 "src-generated/ugbc.tab.c"
    break;

  case 240: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 893 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4906 "src-generated/ugbc.tab.c"
    break;

  case 243: /* bitmap_definition_simple: AT direct_integer  */
#line 902 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4914 "src-generated/ugbc.tab.c"
    break;

  case 244: /* bitmap_definition_simple: ENABLE  */
#line 905 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 4922 "src-generated/ugbc.tab.c"
    break;

  case 245: /* bitmap_definition_simple: DISABLE  */
#line 908 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 4930 "src-generated/ugbc.tab.c"
    break;

  case 246: /* bitmap_definition_simple: CLEAR  */
#line 911 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 4938 "src-generated/ugbc.tab.c"
    break;

  case 247: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 914 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 4946 "src-generated/ugbc.tab.c"
    break;

  case 248: /* bitmap_definition_expression: AT expr  */
#line 920 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4954 "src-generated/ugbc.tab.c"
    break;

  case 249: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 923 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 4962 "src-generated/ugbc.tab.c"
    break;

  case 252: /* textmap_definition_simple: AT direct_integer  */
#line 933 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4970 "src-generated/ugbc.tab.c"
    break;

  case 253: /* textmap_definition_expression: AT expr  */
#line 938 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4978 "src-generated/ugbc.tab.c"
    break;

  case 256: /* text_definition_simple: ENABLE  */
#line 947 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 4986 "src-generated/ugbc.tab.c"
    break;

  case 257: /* text_definition_simple: DISABLE  */
#line 950 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 4994 "src-generated/ugbc.tab.c"
    break;

  case 258: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 955 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 5002 "src-generated/ugbc.tab.c"
    break;

  case 259: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 958 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 5010 "src-generated/ugbc.tab.c"
    break;

  case 262: /* tiles_definition_simple: AT direct_integer  */
#line 967 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 5018 "src-generated/ugbc.tab.c"
    break;

  case 263: /* tiles_definition_expression: AT expr  */
#line 972 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 5026 "src-generated/ugbc.tab.c"
    break;

  case 266: /* colormap_definition_simple: AT direct_integer  */
#line 981 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 5034 "src-generated/ugbc.tab.c"
    break;

  case 267: /* colormap_definition_simple: CLEAR  */
#line 984 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 5042 "src-generated/ugbc.tab.c"
    break;

  case 268: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 987 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 5050 "src-generated/ugbc.tab.c"
    break;

  case 269: /* colormap_definition_expression: AT expr  */
#line 992 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 5058 "src-generated/ugbc.tab.c"
    break;

  case 270: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 995 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 5066 "src-generated/ugbc.tab.c"
    break;

  case 273: /* screen_definition_simple: ON  */
#line 1005 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 5074 "src-generated/ugbc.tab.c"
    break;

  case 274: /* screen_definition_simple: OFF  */
#line 1008 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 5082 "src-generated/ugbc.tab.c"
    break;

  case 275: /* screen_definition_simple: ROWS direct_integer  */
#line 1011 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 5090 "src-generated/ugbc.tab.c"
    break;

  case 276: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 1014 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 5098 "src-generated/ugbc.tab.c"
    break;

  case 277: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 1017 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 5106 "src-generated/ugbc.tab.c"
    break;

  case 278: /* screen_definition_expression: ROWS expr  */
#line 1022 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 5114 "src-generated/ugbc.tab.c"
    break;

  case 279: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 1025 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 5122 "src-generated/ugbc.tab.c"
    break;

  case 280: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 1028 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 5130 "src-generated/ugbc.tab.c"
    break;

  case 284: /* var_definition_simple: Identifier ON Identifier  */
#line 1037 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 5138 "src-generated/ugbc.tab.c"
    break;

  case 285: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 1040 "src/ugbc.y"
                                    {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 5146 "src-generated/ugbc.tab.c"
    break;

  case 286: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 1043 "src/ugbc.y"
                                                   {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 5154 "src-generated/ugbc.tab.c"
    break;

  case 287: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 1046 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 5164 "src-generated/ugbc.tab.c"
    break;

  case 288: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 1051 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 5174 "src-generated/ugbc.tab.c"
    break;

  case 289: /* goto_definition: Identifier  */
#line 1058 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 5182 "src-generated/ugbc.tab.c"
    break;

  case 290: /* goto_definition: Integer  */
#line 1061 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 5190 "src-generated/ugbc.tab.c"
    break;

  case 291: /* gosub_definition: Identifier  */
#line 1067 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 5198 "src-generated/ugbc.tab.c"
    break;

  case 292: /* gosub_definition: Integer  */
#line 1070 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 5206 "src-generated/ugbc.tab.c"
    break;

  case 294: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 1079 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 5214 "src-generated/ugbc.tab.c"
    break;

  case 295: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 1085 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 5222 "src-generated/ugbc.tab.c"
    break;

  case 298: /* ink_definition: expr  */
#line 1094 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 5230 "src-generated/ugbc.tab.c"
    break;

  case 299: /* on_goto_definition: Identifier  */
#line 1099 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 5239 "src-generated/ugbc.tab.c"
    break;

  case 300: /* $@4: %empty  */
#line 1103 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 5247 "src-generated/ugbc.tab.c"
    break;

  case 302: /* on_gosub_definition: Identifier  */
#line 1108 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 5256 "src-generated/ugbc.tab.c"
    break;

  case 303: /* $@5: %empty  */
#line 1112 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 5264 "src-generated/ugbc.tab.c"
    break;

  case 305: /* on_proc_definition: Identifier  */
#line 1117 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 5273 "src-generated/ugbc.tab.c"
    break;

  case 306: /* $@6: %empty  */
#line 1121 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 5281 "src-generated/ugbc.tab.c"
    break;

  case 308: /* $@7: %empty  */
#line 1126 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 5289 "src-generated/ugbc.tab.c"
    break;

  case 310: /* $@8: %empty  */
#line 1129 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 5297 "src-generated/ugbc.tab.c"
    break;

  case 312: /* $@9: %empty  */
#line 1132 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 5305 "src-generated/ugbc.tab.c"
    break;

  case 314: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1137 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 5313 "src-generated/ugbc.tab.c"
    break;

  case 315: /* every_definition: ON  */
#line 1140 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 5321 "src-generated/ugbc.tab.c"
    break;

  case 316: /* every_definition: OFF  */
#line 1143 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 5329 "src-generated/ugbc.tab.c"
    break;

  case 317: /* add_definition: Identifier COMMA expr  */
#line 1148 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 5337 "src-generated/ugbc.tab.c"
    break;

  case 318: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 1151 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5345 "src-generated/ugbc.tab.c"
    break;

  case 319: /* dimensions: Integer  */
#line 1157 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 5354 "src-generated/ugbc.tab.c"
    break;

  case 320: /* dimensions: Integer COMMA dimensions  */
#line 1161 "src/ugbc.y"
                               {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 5363 "src-generated/ugbc.tab.c"
    break;

  case 321: /* datatype: BYTE  */
#line 1168 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 5371 "src-generated/ugbc.tab.c"
    break;

  case 322: /* datatype: SIGNED BYTE  */
#line 1171 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 5379 "src-generated/ugbc.tab.c"
    break;

  case 323: /* datatype: WORD  */
#line 1174 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 5387 "src-generated/ugbc.tab.c"
    break;

  case 324: /* datatype: SIGNED WORD  */
#line 1177 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 5395 "src-generated/ugbc.tab.c"
    break;

  case 325: /* datatype: DWORD  */
#line 1180 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 5403 "src-generated/ugbc.tab.c"
    break;

  case 326: /* datatype: SIGNED DWORD  */
#line 1183 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 5411 "src-generated/ugbc.tab.c"
    break;

  case 327: /* datatype: ADDRESS  */
#line 1186 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 5419 "src-generated/ugbc.tab.c"
    break;

  case 328: /* datatype: POSITION  */
#line 1189 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 5427 "src-generated/ugbc.tab.c"
    break;

  case 329: /* datatype: COLOR  */
#line 1192 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 5435 "src-generated/ugbc.tab.c"
    break;

  case 330: /* datatype: STRING  */
#line 1195 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 5443 "src-generated/ugbc.tab.c"
    break;

  case 331: /* $@10: %empty  */
#line 1200 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5452 "src-generated/ugbc.tab.c"
    break;

  case 332: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1203 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 5462 "src-generated/ugbc.tab.c"
    break;

  case 333: /* $@11: %empty  */
#line 1208 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5471 "src-generated/ugbc.tab.c"
    break;

  case 334: /* dim_definition: Identifier $@11 DOLLAR OP dimensions CP  */
#line 1211 "src/ugbc.y"
                                {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 5481 "src-generated/ugbc.tab.c"
    break;

  case 335: /* $@12: %empty  */
#line 1216 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5490 "src-generated/ugbc.tab.c"
    break;

  case 336: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1219 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 5500 "src-generated/ugbc.tab.c"
    break;

  case 339: /* indexes: expr  */
#line 1232 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5509 "src-generated/ugbc.tab.c"
    break;

  case 340: /* indexes: expr COMMA indexes  */
#line 1236 "src/ugbc.y"
                         {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5518 "src-generated/ugbc.tab.c"
    break;

  case 341: /* parameters: Identifier  */
#line 1243 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5528 "src-generated/ugbc.tab.c"
    break;

  case 342: /* parameters: Identifier DOLLAR  */
#line 1248 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5538 "src-generated/ugbc.tab.c"
    break;

  case 343: /* parameters: Identifier AS datatype  */
#line 1253 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5548 "src-generated/ugbc.tab.c"
    break;

  case 344: /* parameters: Identifier COMMA parameters  */
#line 1258 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5558 "src-generated/ugbc.tab.c"
    break;

  case 345: /* parameters: Identifier DOLLAR COMMA parameters  */
#line 1263 "src/ugbc.y"
                                         {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5568 "src-generated/ugbc.tab.c"
    break;

  case 346: /* parameters: Identifier AS datatype COMMA parameters  */
#line 1268 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5578 "src-generated/ugbc.tab.c"
    break;

  case 347: /* parameters_expr: Identifier  */
#line 1276 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5588 "src-generated/ugbc.tab.c"
    break;

  case 348: /* parameters_expr: Identifier DOLLAR  */
#line 1281 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5598 "src-generated/ugbc.tab.c"
    break;

  case 349: /* parameters_expr: Identifier AS datatype  */
#line 1286 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5608 "src-generated/ugbc.tab.c"
    break;

  case 350: /* parameters_expr: Identifier COMMA parameters_expr  */
#line 1291 "src/ugbc.y"
                                       {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5618 "src-generated/ugbc.tab.c"
    break;

  case 351: /* parameters_expr: Identifier DOLLAR COMMA parameters_expr  */
#line 1296 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5628 "src-generated/ugbc.tab.c"
    break;

  case 352: /* parameters_expr: Identifier AS datatype COMMA parameters_expr  */
#line 1301 "src/ugbc.y"
                                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5638 "src-generated/ugbc.tab.c"
    break;

  case 353: /* parameters_expr: String  */
#line 1306 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5647 "src-generated/ugbc.tab.c"
    break;

  case 354: /* parameters_expr: String COMMA parameters_expr  */
#line 1310 "src/ugbc.y"
                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5656 "src-generated/ugbc.tab.c"
    break;

  case 355: /* values: expr  */
#line 1317 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5665 "src-generated/ugbc.tab.c"
    break;

  case 356: /* values: expr COMMA values  */
#line 1321 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5674 "src-generated/ugbc.tab.c"
    break;

  case 357: /* print_definition: expr  */
#line 1328 "src/ugbc.y"
         {
        print( _environment, (yyvsp[0].string), 1 );
    }
#line 5682 "src-generated/ugbc.tab.c"
    break;

  case 358: /* print_definition: expr COMMA  */
#line 1331 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5691 "src-generated/ugbc.tab.c"
    break;

  case 359: /* print_definition: expr SEMICOLON  */
#line 1335 "src/ugbc.y"
                   {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5699 "src-generated/ugbc.tab.c"
    break;

  case 360: /* $@13: %empty  */
#line 1338 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5708 "src-generated/ugbc.tab.c"
    break;

  case 362: /* $@14: %empty  */
#line 1342 "src/ugbc.y"
                    {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5716 "src-generated/ugbc.tab.c"
    break;

  case 364: /* writing_mode_definition: REPLACE  */
#line 1348 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing REPLACE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_REPLACE );
    }
#line 5725 "src-generated/ugbc.tab.c"
    break;

  case 365: /* writing_mode_definition: OR  */
#line 1352 "src/ugbc.y"
         {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing OR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_OR );
    }
#line 5734 "src-generated/ugbc.tab.c"
    break;

  case 366: /* writing_mode_definition: XOR  */
#line 1356 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing XOR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_XOR );
    }
#line 5743 "src-generated/ugbc.tab.c"
    break;

  case 367: /* writing_mode_definition: AND  */
#line 1360 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing AND)" )->name;
          variable_store( _environment, (yyval.string), WRITING_AND );
    }
#line 5752 "src-generated/ugbc.tab.c"
    break;

  case 368: /* writing_mode_definition: IGNORE  */
#line 1364 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing IGNORE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_IGNORE );
    }
#line 5761 "src-generated/ugbc.tab.c"
    break;

  case 369: /* writing_part_definition: NORMAL  */
#line 1371 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing NORMAL)" )->name;
          variable_store( _environment, (yyval.string), WRITING_NORMAL );
    }
#line 5770 "src-generated/ugbc.tab.c"
    break;

  case 370: /* writing_part_definition: PAPER  */
#line 1375 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5779 "src-generated/ugbc.tab.c"
    break;

  case 371: /* writing_part_definition: PAPER ONLY  */
#line 1379 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5788 "src-generated/ugbc.tab.c"
    break;

  case 372: /* writing_part_definition: PEN  */
#line 1383 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5797 "src-generated/ugbc.tab.c"
    break;

  case 373: /* writing_part_definition: PEN ONLY  */
#line 1387 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5806 "src-generated/ugbc.tab.c"
    break;

  case 374: /* writing_definition: writing_mode_definition COMMA writing_part_definition  */
#line 1394 "src/ugbc.y"
                                                          {
        text_writing( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5814 "src-generated/ugbc.tab.c"
    break;

  case 375: /* locate_definition: COMMA expr  */
#line 1400 "src/ugbc.y"
                {
        text_locate( _environment, NULL, (yyvsp[0].string) );
    }
#line 5822 "src-generated/ugbc.tab.c"
    break;

  case 376: /* locate_definition: expr COMMA  */
#line 1403 "src/ugbc.y"
                 {
        text_locate( _environment, (yyvsp[-1].string), NULL );
    }
#line 5830 "src-generated/ugbc.tab.c"
    break;

  case 377: /* locate_definition: expr COMMA expr  */
#line 1406 "src/ugbc.y"
                      {
        text_locate( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5838 "src-generated/ugbc.tab.c"
    break;

  case 378: /* cmove_definition: COMMA expr  */
#line 1412 "src/ugbc.y"
                {
        text_cmove( _environment, NULL, (yyvsp[0].string) );
    }
#line 5846 "src-generated/ugbc.tab.c"
    break;

  case 379: /* cmove_definition: expr COMMA  */
#line 1415 "src/ugbc.y"
                 {
        text_cmove( _environment, (yyvsp[-1].string), NULL );
    }
#line 5854 "src-generated/ugbc.tab.c"
    break;

  case 380: /* cmove_definition: expr COMMA expr  */
#line 1418 "src/ugbc.y"
                      {
        text_cmove( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5862 "src-generated/ugbc.tab.c"
    break;

  case 381: /* hscroll_definition: LEFT  */
#line 1424 "src/ugbc.y"
         {
        text_hscroll_line( _environment, -1 );
    }
#line 5870 "src-generated/ugbc.tab.c"
    break;

  case 382: /* hscroll_definition: SCREEN LEFT  */
#line 1427 "src/ugbc.y"
                  {
        text_hscroll_screen( _environment, -1 );
    }
#line 5878 "src-generated/ugbc.tab.c"
    break;

  case 383: /* hscroll_definition: RIGHT  */
#line 1430 "src/ugbc.y"
            {
        text_hscroll_line( _environment, 1 );
    }
#line 5886 "src-generated/ugbc.tab.c"
    break;

  case 384: /* hscroll_definition: SCREEN RIGHT  */
#line 1433 "src/ugbc.y"
                   {
        text_hscroll_screen( _environment, 1 );
    }
#line 5894 "src-generated/ugbc.tab.c"
    break;

  case 385: /* vscroll_definition: SCREEN UP  */
#line 1439 "src/ugbc.y"
                {
        text_vscroll_screen( _environment, -1 );
    }
#line 5902 "src-generated/ugbc.tab.c"
    break;

  case 386: /* vscroll_definition: SCREEN DOWN  */
#line 1442 "src/ugbc.y"
                  {
        text_vscroll_screen( _environment, 1 );
    }
#line 5910 "src-generated/ugbc.tab.c"
    break;

  case 402: /* statement: TEXTADDRESS ASSIGN expr  */
#line 1463 "src/ugbc.y"
                            {
      variable_move( _environment, (yyvsp[0].string), "ADDRESS" );
  }
#line 5918 "src-generated/ugbc.tab.c"
    break;

  case 407: /* statement: MEMORIZE  */
#line 1470 "src/ugbc.y"
             {
      text_memorize( _environment );
  }
#line 5926 "src-generated/ugbc.tab.c"
    break;

  case 408: /* statement: REMEMBER  */
#line 1473 "src/ugbc.y"
             {
      text_remember( _environment );
  }
#line 5934 "src-generated/ugbc.tab.c"
    break;

  case 412: /* statement: CUP  */
#line 1479 "src/ugbc.y"
        {
      text_cmove_direct( _environment, 0, -1 );
  }
#line 5942 "src-generated/ugbc.tab.c"
    break;

  case 413: /* statement: CDOWN  */
#line 1482 "src/ugbc.y"
          {
      text_cmove_direct( _environment, 0, 1 );
  }
#line 5950 "src-generated/ugbc.tab.c"
    break;

  case 414: /* statement: CLEFT  */
#line 1485 "src/ugbc.y"
          {
      text_cmove_direct( _environment, -1, 0 );
  }
#line 5958 "src-generated/ugbc.tab.c"
    break;

  case 415: /* statement: CRIGHT  */
#line 1488 "src/ugbc.y"
           {
      text_cmove_direct( _environment, 1, 0 );
  }
#line 5966 "src-generated/ugbc.tab.c"
    break;

  case 416: /* statement: CLINE  */
#line 1491 "src/ugbc.y"
          {
      text_cline( _environment, NULL );
  }
#line 5974 "src-generated/ugbc.tab.c"
    break;

  case 417: /* statement: CLINE expr  */
#line 1494 "src/ugbc.y"
               {
      text_cline( _environment, (yyvsp[0].string) );
  }
#line 5982 "src-generated/ugbc.tab.c"
    break;

  case 418: /* statement: SET TAB expr  */
#line 1497 "src/ugbc.y"
                 {
      text_set_tab( _environment, (yyvsp[0].string) );
  }
#line 5990 "src-generated/ugbc.tab.c"
    break;

  case 419: /* statement: CENTER expr  */
#line 1500 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 5998 "src-generated/ugbc.tab.c"
    break;

  case 420: /* statement: CENTRE expr  */
#line 1503 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 6006 "src-generated/ugbc.tab.c"
    break;

  case 421: /* statement: CLS  */
#line 1506 "src/ugbc.y"
        {
      text_cls( _environment );
  }
#line 6014 "src-generated/ugbc.tab.c"
    break;

  case 422: /* statement: HOME  */
#line 1509 "src/ugbc.y"
         {
      text_home( _environment );
  }
#line 6022 "src-generated/ugbc.tab.c"
    break;

  case 423: /* statement: INC Identifier  */
#line 1512 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 6030 "src-generated/ugbc.tab.c"
    break;

  case 424: /* statement: DEC Identifier  */
#line 1515 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 6038 "src-generated/ugbc.tab.c"
    break;

  case 425: /* statement: RANDOMIZE  */
#line 1518 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 6046 "src-generated/ugbc.tab.c"
    break;

  case 426: /* statement: RANDOMIZE expr  */
#line 1521 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 6054 "src-generated/ugbc.tab.c"
    break;

  case 427: /* statement: IF expr THEN  */
#line 1524 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 6062 "src-generated/ugbc.tab.c"
    break;

  case 428: /* statement: ELSE  */
#line 1527 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 6070 "src-generated/ugbc.tab.c"
    break;

  case 429: /* statement: ELSE IF expr THEN  */
#line 1530 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 6078 "src-generated/ugbc.tab.c"
    break;

  case 430: /* statement: ENDIF  */
#line 1533 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 6086 "src-generated/ugbc.tab.c"
    break;

  case 431: /* statement: DO  */
#line 1536 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 6094 "src-generated/ugbc.tab.c"
    break;

  case 432: /* statement: LOOP  */
#line 1539 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 6102 "src-generated/ugbc.tab.c"
    break;

  case 433: /* $@15: %empty  */
#line 1542 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 6110 "src-generated/ugbc.tab.c"
    break;

  case 434: /* statement: WHILE $@15 expr  */
#line 1544 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 6118 "src-generated/ugbc.tab.c"
    break;

  case 435: /* statement: WEND  */
#line 1547 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 6126 "src-generated/ugbc.tab.c"
    break;

  case 436: /* statement: REPEAT  */
#line 1550 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 6134 "src-generated/ugbc.tab.c"
    break;

  case 437: /* statement: UNTIL expr  */
#line 1553 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 6142 "src-generated/ugbc.tab.c"
    break;

  case 438: /* statement: EXIT  */
#line 1556 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 6150 "src-generated/ugbc.tab.c"
    break;

  case 439: /* statement: EXIT PROC  */
#line 1559 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 6158 "src-generated/ugbc.tab.c"
    break;

  case 440: /* statement: POP PROC  */
#line 1562 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 6166 "src-generated/ugbc.tab.c"
    break;

  case 441: /* statement: EXIT IF expr  */
#line 1565 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 6174 "src-generated/ugbc.tab.c"
    break;

  case 442: /* statement: EXIT Integer  */
#line 1568 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 6182 "src-generated/ugbc.tab.c"
    break;

  case 443: /* statement: EXIT direct_integer  */
#line 1571 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 6190 "src-generated/ugbc.tab.c"
    break;

  case 444: /* statement: EXIT IF expr COMMA Integer  */
#line 1574 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 6198 "src-generated/ugbc.tab.c"
    break;

  case 445: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1577 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 6206 "src-generated/ugbc.tab.c"
    break;

  case 446: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1580 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 6214 "src-generated/ugbc.tab.c"
    break;

  case 447: /* statement: NEXT  */
#line 1583 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 6222 "src-generated/ugbc.tab.c"
    break;

  case 448: /* statement: PROCEDURE Identifier  */
#line 1586 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 6231 "src-generated/ugbc.tab.c"
    break;

  case 449: /* $@16: %empty  */
#line 1590 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6239 "src-generated/ugbc.tab.c"
    break;

  case 450: /* statement: PROCEDURE Identifier $@16 OSP parameters CSP  */
#line 1592 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6247 "src-generated/ugbc.tab.c"
    break;

  case 451: /* statement: SHARED parameters_expr  */
#line 1595 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 6255 "src-generated/ugbc.tab.c"
    break;

  case 452: /* statement: GLOBAL parameters_expr  */
#line 1598 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 6263 "src-generated/ugbc.tab.c"
    break;

  case 453: /* statement: END PROC  */
#line 1601 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 6271 "src-generated/ugbc.tab.c"
    break;

  case 454: /* statement: END PROC OSP expr CSP  */
#line 1604 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 6279 "src-generated/ugbc.tab.c"
    break;

  case 455: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1607 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 6287 "src-generated/ugbc.tab.c"
    break;

  case 456: /* statement: Identifier " "  */
#line 1610 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 6296 "src-generated/ugbc.tab.c"
    break;

  case 457: /* statement: PROC Identifier  */
#line 1614 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 6305 "src-generated/ugbc.tab.c"
    break;

  case 458: /* statement: CALL Identifier  */
#line 1618 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 6314 "src-generated/ugbc.tab.c"
    break;

  case 459: /* $@17: %empty  */
#line 1622 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6322 "src-generated/ugbc.tab.c"
    break;

  case 460: /* statement: Identifier OSP $@17 values CSP  */
#line 1624 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6330 "src-generated/ugbc.tab.c"
    break;

  case 461: /* $@18: %empty  */
#line 1627 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6338 "src-generated/ugbc.tab.c"
    break;

  case 462: /* statement: PROC Identifier OSP $@18 values CSP  */
#line 1629 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6346 "src-generated/ugbc.tab.c"
    break;

  case 463: /* $@19: %empty  */
#line 1632 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6354 "src-generated/ugbc.tab.c"
    break;

  case 464: /* statement: CALL Identifier OSP $@19 values CSP  */
#line 1634 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6362 "src-generated/ugbc.tab.c"
    break;

  case 465: /* statement: PEN expr  */
#line 1637 "src/ugbc.y"
             {
      text_pen( _environment, (yyvsp[0].string) );
  }
#line 6370 "src-generated/ugbc.tab.c"
    break;

  case 466: /* statement: PAPER expr  */
#line 1640 "src/ugbc.y"
               {
      text_paper( _environment, (yyvsp[0].string) );
  }
#line 6378 "src-generated/ugbc.tab.c"
    break;

  case 467: /* statement: INVERSE ON  */
#line 1643 "src/ugbc.y"
               {
      CRITICAL_NOT_SUPPORTED("INVERSE");
  }
#line 6386 "src-generated/ugbc.tab.c"
    break;

  case 468: /* statement: INVERSE OFF  */
#line 1646 "src/ugbc.y"
                {
      CRITICAL_NOT_SUPPORTED("INVERSE");
  }
#line 6394 "src-generated/ugbc.tab.c"
    break;

  case 470: /* statement: Identifier COLON  */
#line 1650 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 6402 "src-generated/ugbc.tab.c"
    break;

  case 471: /* statement: BEG GAMELOOP  */
#line 1653 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 6410 "src-generated/ugbc.tab.c"
    break;

  case 472: /* statement: END GAMELOOP  */
#line 1656 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 6418 "src-generated/ugbc.tab.c"
    break;

  case 473: /* statement: GRAPHIC  */
#line 1659 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 6426 "src-generated/ugbc.tab.c"
    break;

  case 474: /* statement: HALT  */
#line 1662 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 6434 "src-generated/ugbc.tab.c"
    break;

  case 475: /* statement: END  */
#line 1665 "src/ugbc.y"
        {
      end( _environment );
  }
#line 6442 "src-generated/ugbc.tab.c"
    break;

  case 480: /* statement: RETURN  */
#line 1672 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 6450 "src-generated/ugbc.tab.c"
    break;

  case 481: /* statement: RETURN expr  */
#line 1675 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 6458 "src-generated/ugbc.tab.c"
    break;

  case 482: /* statement: POP  */
#line 1678 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 6466 "src-generated/ugbc.tab.c"
    break;

  case 483: /* statement: DONE  */
#line 1681 "src/ugbc.y"
          {
      return 0;
  }
#line 6474 "src-generated/ugbc.tab.c"
    break;

  case 484: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1684 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6482 "src-generated/ugbc.tab.c"
    break;

  case 485: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1687 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6490 "src-generated/ugbc.tab.c"
    break;

  case 486: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1690 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 6498 "src-generated/ugbc.tab.c"
    break;

  case 487: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1693 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6506 "src-generated/ugbc.tab.c"
    break;

  case 489: /* statement: Identifier ASSIGN expr  */
#line 1697 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 6520 "src-generated/ugbc.tab.c"
    break;

  case 490: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1706 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 6534 "src-generated/ugbc.tab.c"
    break;

  case 491: /* $@20: %empty  */
#line 1715 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6543 "src-generated/ugbc.tab.c"
    break;

  case 492: /* statement: Identifier $@20 OP indexes CP ASSIGN expr  */
#line 1719 "src/ugbc.y"
                                {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 6556 "src-generated/ugbc.tab.c"
    break;

  case 493: /* $@21: %empty  */
#line 1727 "src/ugbc.y"
                      {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6565 "src-generated/ugbc.tab.c"
    break;

  case 494: /* statement: Identifier DOLLAR $@21 OP indexes CP ASSIGN expr  */
#line 1730 "src/ugbc.y"
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
#line 6584 "src-generated/ugbc.tab.c"
    break;

  case 495: /* $@22: %empty  */
#line 1744 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6593 "src-generated/ugbc.tab.c"
    break;

  case 496: /* statement: Identifier $@22 datatype OP indexes CP ASSIGN expr  */
#line 1747 "src/ugbc.y"
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
#line 6612 "src-generated/ugbc.tab.c"
    break;

  case 497: /* statement: DEBUG expr  */
#line 1761 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 6620 "src-generated/ugbc.tab.c"
    break;

  case 500: /* statements_no_linenumbers: statement  */
#line 1769 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 6626 "src-generated/ugbc.tab.c"
    break;

  case 501: /* $@23: %empty  */
#line 1770 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 6632 "src-generated/ugbc.tab.c"
    break;

  case 503: /* $@24: %empty  */
#line 1774 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 6640 "src-generated/ugbc.tab.c"
    break;

  case 504: /* statements_with_linenumbers: Integer $@24 statements_no_linenumbers  */
#line 1776 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 6648 "src-generated/ugbc.tab.c"
    break;

  case 505: /* $@25: %empty  */
#line 1781 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 6656 "src-generated/ugbc.tab.c"
    break;

  case 511: /* $@26: %empty  */
#line 1791 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 6662 "src-generated/ugbc.tab.c"
    break;


#line 6666 "src-generated/ugbc.tab.c"

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

#line 1793 "src/ugbc.y"


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

    variable_import( _environment, "JOYCOUNT", VT_BYTE );
    variable_global( _environment, "JOYCOUNT" );    

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

