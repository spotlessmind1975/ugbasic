/* A Bison parser, made by GNU Bison 3.7.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_GENERATED_UGBC_TAB_H_INCLUDED
# define YY_YY_SRC_GENERATED_UGBC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    Remark = 258,                  /* Remark  */
    NewLine = 259,                 /* NewLine  */
    SEMICOLON = 260,               /* SEMICOLON  */
    COLON = 261,                   /* COLON  */
    COMMA = 262,                   /* COMMA  */
    PLUS = 263,                    /* PLUS  */
    MINUS = 264,                   /* MINUS  */
    INC = 265,                     /* INC  */
    DEC = 266,                     /* DEC  */
    EQUAL = 267,                   /* EQUAL  */
    ASSIGN = 268,                  /* ASSIGN  */
    LT = 269,                      /* LT  */
    LTE = 270,                     /* LTE  */
    GT = 271,                      /* GT  */
    GTE = 272,                     /* GTE  */
    DISEQUAL = 273,                /* DISEQUAL  */
    MULTIPLICATION = 274,          /* MULTIPLICATION  */
    DOLLAR = 275,                  /* DOLLAR  */
    DIVISION = 276,                /* DIVISION  */
    QM = 277,                      /* QM  */
    HAS = 278,                     /* HAS  */
    IS = 279,                      /* IS  */
    OF = 280,                      /* OF  */
    RASTER = 281,                  /* RASTER  */
    DONE = 282,                    /* DONE  */
    AT = 283,                      /* AT  */
    COLOR = 284,                   /* COLOR  */
    BORDER = 285,                  /* BORDER  */
    WAIT = 286,                    /* WAIT  */
    NEXT = 287,                    /* NEXT  */
    WITH = 288,                    /* WITH  */
    BANK = 289,                    /* BANK  */
    SPRITE = 290,                  /* SPRITE  */
    DATA = 291,                    /* DATA  */
    FROM = 292,                    /* FROM  */
    OP = 293,                      /* OP  */
    CP = 294,                      /* CP  */
    ENABLE = 295,                  /* ENABLE  */
    DISABLE = 296,                 /* DISABLE  */
    HALT = 297,                    /* HALT  */
    ECM = 298,                     /* ECM  */
    BITMAP = 299,                  /* BITMAP  */
    SCREEN = 300,                  /* SCREEN  */
    ON = 301,                      /* ON  */
    OFF = 302,                     /* OFF  */
    ROWS = 303,                    /* ROWS  */
    VERTICAL = 304,                /* VERTICAL  */
    SCROLL = 305,                  /* SCROLL  */
    VAR = 306,                     /* VAR  */
    AS = 307,                      /* AS  */
    TEMPORARY = 308,               /* TEMPORARY  */
    XPEN = 309,                    /* XPEN  */
    YPEN = 310,                    /* YPEN  */
    PEEK = 311,                    /* PEEK  */
    GOTO = 312,                    /* GOTO  */
    HORIZONTAL = 313,              /* HORIZONTAL  */
    MCM = 314,                     /* MCM  */
    COMPRESS = 315,                /* COMPRESS  */
    EXPAND = 316,                  /* EXPAND  */
    LOOP = 317,                    /* LOOP  */
    REPEAT = 318,                  /* REPEAT  */
    WHILE = 319,                   /* WHILE  */
    TEXT = 320,                    /* TEXT  */
    TILES = 321,                   /* TILES  */
    COLORMAP = 322,                /* COLORMAP  */
    SELECT = 323,                  /* SELECT  */
    MONOCOLOR = 324,               /* MONOCOLOR  */
    MULTICOLOR = 325,              /* MULTICOLOR  */
    COLLISION = 326,               /* COLLISION  */
    IF = 327,                      /* IF  */
    THEN = 328,                    /* THEN  */
    HIT = 329,                     /* HIT  */
    BACKGROUND = 330,              /* BACKGROUND  */
    TO = 331,                      /* TO  */
    RANDOM = 332,                  /* RANDOM  */
    BYTE = 333,                    /* BYTE  */
    WORD = 334,                    /* WORD  */
    POSITION = 335,                /* POSITION  */
    CODE = 336,                    /* CODE  */
    VARIABLES = 337,               /* VARIABLES  */
    MS = 338,                      /* MS  */
    CYCLES = 339,                  /* CYCLES  */
    S = 340,                       /* S  */
    HASH = 341,                    /* HASH  */
    WIDTH = 342,                   /* WIDTH  */
    HEIGHT = 343,                  /* HEIGHT  */
    DWORD = 344,                   /* DWORD  */
    PEN = 345,                     /* PEN  */
    CLEAR = 346,                   /* CLEAR  */
    BEG = 347,                     /* BEG  */
    END = 348,                     /* END  */
    GAMELOOP = 349,                /* GAMELOOP  */
    ENDIF = 350,                   /* ENDIF  */
    UP = 351,                      /* UP  */
    DOWN = 352,                    /* DOWN  */
    LEFT = 353,                    /* LEFT  */
    RIGHT = 354,                   /* RIGHT  */
    DEBUG = 355,                   /* DEBUG  */
    AND = 356,                     /* AND  */
    RANDOMIZE = 357,               /* RANDOMIZE  */
    GRAPHIC = 358,                 /* GRAPHIC  */
    TEXTMAP = 359,                 /* TEXTMAP  */
    POINT = 360,                   /* POINT  */
    GOSUB = 361,                   /* GOSUB  */
    RETURN = 362,                  /* RETURN  */
    POP = 363,                     /* POP  */
    OR = 364,                      /* OR  */
    ELSE = 365,                    /* ELSE  */
    NOT = 366,                     /* NOT  */
    TRUE = 367,                    /* TRUE  */
    FALSE = 368,                   /* FALSE  */
    DO = 369,                      /* DO  */
    EXIT = 370,                    /* EXIT  */
    WEND = 371,                    /* WEND  */
    UNTIL = 372,                   /* UNTIL  */
    FOR = 373,                     /* FOR  */
    STEP = 374,                    /* STEP  */
    EVERY = 375,                   /* EVERY  */
    MID = 376,                     /* MID  */
    INSTR = 377,                   /* INSTR  */
    UPPER = 378,                   /* UPPER  */
    LOWER = 379,                   /* LOWER  */
    STR = 380,                     /* STR  */
    VAL = 381,                     /* VAL  */
    STRING = 382,                  /* STRING  */
    SPACE = 383,                   /* SPACE  */
    FLIP = 384,                    /* FLIP  */
    CHR = 385,                     /* CHR  */
    ASC = 386,                     /* ASC  */
    LEN = 387,                     /* LEN  */
    POW = 388,                     /* POW  */
    MOD = 389,                     /* MOD  */
    ADD = 390,                     /* ADD  */
    MIN = 391,                     /* MIN  */
    MAX = 392,                     /* MAX  */
    SGN = 393,                     /* SGN  */
    SIGNED = 394,                  /* SIGNED  */
    ABS = 395,                     /* ABS  */
    RND = 396,                     /* RND  */
    COLORS = 397,                  /* COLORS  */
    INK = 398,                     /* INK  */
    TIMER = 399,                   /* TIMER  */
    POWERING = 400,                /* POWERING  */
    DIM = 401,                     /* DIM  */
    ADDRESS = 402,                 /* ADDRESS  */
    PROC = 403,                    /* PROC  */
    PROCEDURE = 404,               /* PROCEDURE  */
    CALL = 405,                    /* CALL  */
    OSP = 406,                     /* OSP  */
    CSP = 407,                     /* CSP  */
    SHARED = 408,                  /* SHARED  */
    MILLISECOND = 409,             /* MILLISECOND  */
    MILLISECONDS = 410,            /* MILLISECONDS  */
    TICKS = 411,                   /* TICKS  */
    GLOBAL = 412,                  /* GLOBAL  */
    PARAM = 413,                   /* PARAM  */
    PRINT = 414,                   /* PRINT  */
    DEFAULT = 415,                 /* DEFAULT  */
    USE = 416,                     /* USE  */
    PAPER = 417,                   /* PAPER  */
    INVERSE = 418,                 /* INVERSE  */
    REPLACE = 419,                 /* REPLACE  */
    XOR = 420,                     /* XOR  */
    IGNORE = 421,                  /* IGNORE  */
    NORMAL = 422,                  /* NORMAL  */
    WRITING = 423,                 /* WRITING  */
    ONLY = 424,                    /* ONLY  */
    LOCATE = 425,                  /* LOCATE  */
    CLS = 426,                     /* CLS  */
    HOME = 427,                    /* HOME  */
    CMOVE = 428,                   /* CMOVE  */
    CENTER = 429,                  /* CENTER  */
    CENTRE = 430,                  /* CENTRE  */
    TAB = 431,                     /* TAB  */
    SET = 432,                     /* SET  */
    CUP = 433,                     /* CUP  */
    CDOWN = 434,                   /* CDOWN  */
    CLEFT = 435,                   /* CLEFT  */
    CRIGHT = 436,                  /* CRIGHT  */
    CLINE = 437,                   /* CLINE  */
    XCURS = 438,                   /* XCURS  */
    YCURS = 439,                   /* YCURS  */
    MEMORIZE = 440,                /* MEMORIZE  */
    REMEMBER = 441,                /* REMEMBER  */
    HSCROLL = 442,                 /* HSCROLL  */
    VSCROLL = 443,                 /* VSCROLL  */
    TEXTADDRESS = 444,             /* TEXTADDRESS  */
    JOY = 445,                     /* JOY  */
    BIN = 446,                     /* BIN  */
    BIT = 447,                     /* BIT  */
    COUNT = 448,                   /* COUNT  */
    JOYCOUNT = 449,                /* JOYCOUNT  */
    FIRE = 450,                    /* FIRE  */
    BLACK = 451,                   /* BLACK  */
    WHITE = 452,                   /* WHITE  */
    RED = 453,                     /* RED  */
    CYAN = 454,                    /* CYAN  */
    VIOLET = 455,                  /* VIOLET  */
    GREEN = 456,                   /* GREEN  */
    BLUE = 457,                    /* BLUE  */
    YELLOW = 458,                  /* YELLOW  */
    ORANGE = 459,                  /* ORANGE  */
    BROWN = 460,                   /* BROWN  */
    LIGHT = 461,                   /* LIGHT  */
    DARK = 462,                    /* DARK  */
    GREY = 463,                    /* GREY  */
    GRAY = 464,                    /* GRAY  */
    MAGENTA = 465,                 /* MAGENTA  */
    PURPLE = 466,                  /* PURPLE  */
    LAVENDER = 467,                /* LAVENDER  */
    GOLD = 468,                    /* GOLD  */
    TURQUOISE = 469,               /* TURQUOISE  */
    TAN = 470,                     /* TAN  */
    PINK = 471,                    /* PINK  */
    PEACH = 472,                   /* PEACH  */
    OLIVE = 473,                   /* OLIVE  */
    Identifier = 474,              /* Identifier  */
    String = 475,                  /* String  */
    Integer = 476                  /* Integer  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "src/ugbc.y"

    int integer;
    char * string;

#line 290 "src-generated/ugbc.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void * _environment);

#endif /* !YY_YY_SRC_GENERATED_UGBC_TAB_H_INCLUDED  */
