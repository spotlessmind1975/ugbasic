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
    OP_SEMICOLON = 260,            /* OP_SEMICOLON  */
    OP_COLON = 261,                /* OP_COLON  */
    OP_COMMA = 262,                /* OP_COMMA  */
    OP_PLUS = 263,                 /* OP_PLUS  */
    OP_MINUS = 264,                /* OP_MINUS  */
    OP_INC = 265,                  /* OP_INC  */
    OP_DEC = 266,                  /* OP_DEC  */
    OP_EQUAL = 267,                /* OP_EQUAL  */
    OP_ASSIGN = 268,               /* OP_ASSIGN  */
    OP_LT = 269,                   /* OP_LT  */
    OP_LTE = 270,                  /* OP_LTE  */
    OP_GT = 271,                   /* OP_GT  */
    OP_GTE = 272,                  /* OP_GTE  */
    OP_DISEQUAL = 273,             /* OP_DISEQUAL  */
    OP_MULTIPLICATION = 274,       /* OP_MULTIPLICATION  */
    OP_DOLLAR = 275,               /* OP_DOLLAR  */
    OP_DIVISION = 276,             /* OP_DIVISION  */
    QM = 277,                      /* QM  */
    HAS = 278,                     /* HAS  */
    IS = 279,                      /* IS  */
    OF = 280,                      /* OF  */
    OP_HASH = 281,                 /* OP_HASH  */
    OP_POW = 282,                  /* OP_POW  */
    RASTER = 283,                  /* RASTER  */
    DONE = 284,                    /* DONE  */
    AT = 285,                      /* AT  */
    COLOR = 286,                   /* COLOR  */
    BORDER = 287,                  /* BORDER  */
    WAIT = 288,                    /* WAIT  */
    NEXT = 289,                    /* NEXT  */
    WITH = 290,                    /* WITH  */
    BANK = 291,                    /* BANK  */
    SPRITE = 292,                  /* SPRITE  */
    DATA = 293,                    /* DATA  */
    FROM = 294,                    /* FROM  */
    OP = 295,                      /* OP  */
    CP = 296,                      /* CP  */
    ENABLE = 297,                  /* ENABLE  */
    DISABLE = 298,                 /* DISABLE  */
    HALT = 299,                    /* HALT  */
    ECM = 300,                     /* ECM  */
    BITMAP = 301,                  /* BITMAP  */
    SCREEN = 302,                  /* SCREEN  */
    ON = 303,                      /* ON  */
    OFF = 304,                     /* OFF  */
    ROWS = 305,                    /* ROWS  */
    VERTICAL = 306,                /* VERTICAL  */
    SCROLL = 307,                  /* SCROLL  */
    VAR = 308,                     /* VAR  */
    AS = 309,                      /* AS  */
    TEMPORARY = 310,               /* TEMPORARY  */
    XPEN = 311,                    /* XPEN  */
    YPEN = 312,                    /* YPEN  */
    PEEK = 313,                    /* PEEK  */
    GOTO = 314,                    /* GOTO  */
    HORIZONTAL = 315,              /* HORIZONTAL  */
    MCM = 316,                     /* MCM  */
    COMPRESS = 317,                /* COMPRESS  */
    EXPAND = 318,                  /* EXPAND  */
    LOOP = 319,                    /* LOOP  */
    REPEAT = 320,                  /* REPEAT  */
    WHILE = 321,                   /* WHILE  */
    TEXT = 322,                    /* TEXT  */
    TILES = 323,                   /* TILES  */
    COLORMAP = 324,                /* COLORMAP  */
    SELECT = 325,                  /* SELECT  */
    MONOCOLOR = 326,               /* MONOCOLOR  */
    MULTICOLOR = 327,              /* MULTICOLOR  */
    COLLISION = 328,               /* COLLISION  */
    IF = 329,                      /* IF  */
    THEN = 330,                    /* THEN  */
    HIT = 331,                     /* HIT  */
    BACKGROUND = 332,              /* BACKGROUND  */
    TO = 333,                      /* TO  */
    RANDOM = 334,                  /* RANDOM  */
    BYTE = 335,                    /* BYTE  */
    WORD = 336,                    /* WORD  */
    POSITION = 337,                /* POSITION  */
    CODE = 338,                    /* CODE  */
    VARIABLES = 339,               /* VARIABLES  */
    MS = 340,                      /* MS  */
    CYCLES = 341,                  /* CYCLES  */
    S = 342,                       /* S  */
    WIDTH = 343,                   /* WIDTH  */
    HEIGHT = 344,                  /* HEIGHT  */
    DWORD = 345,                   /* DWORD  */
    PEN = 346,                     /* PEN  */
    CLEAR = 347,                   /* CLEAR  */
    BEG = 348,                     /* BEG  */
    END = 349,                     /* END  */
    GAMELOOP = 350,                /* GAMELOOP  */
    ENDIF = 351,                   /* ENDIF  */
    UP = 352,                      /* UP  */
    DOWN = 353,                    /* DOWN  */
    LEFT = 354,                    /* LEFT  */
    RIGHT = 355,                   /* RIGHT  */
    DEBUG = 356,                   /* DEBUG  */
    AND = 357,                     /* AND  */
    RANDOMIZE = 358,               /* RANDOMIZE  */
    GRAPHIC = 359,                 /* GRAPHIC  */
    TEXTMAP = 360,                 /* TEXTMAP  */
    POINT = 361,                   /* POINT  */
    GOSUB = 362,                   /* GOSUB  */
    RETURN = 363,                  /* RETURN  */
    POP = 364,                     /* POP  */
    OR = 365,                      /* OR  */
    ELSE = 366,                    /* ELSE  */
    NOT = 367,                     /* NOT  */
    TRUE = 368,                    /* TRUE  */
    FALSE = 369,                   /* FALSE  */
    DO = 370,                      /* DO  */
    EXIT = 371,                    /* EXIT  */
    WEND = 372,                    /* WEND  */
    UNTIL = 373,                   /* UNTIL  */
    FOR = 374,                     /* FOR  */
    STEP = 375,                    /* STEP  */
    EVERY = 376,                   /* EVERY  */
    MID = 377,                     /* MID  */
    INSTR = 378,                   /* INSTR  */
    UPPER = 379,                   /* UPPER  */
    LOWER = 380,                   /* LOWER  */
    STR = 381,                     /* STR  */
    VAL = 382,                     /* VAL  */
    STRING = 383,                  /* STRING  */
    SPACE = 384,                   /* SPACE  */
    FLIP = 385,                    /* FLIP  */
    CHR = 386,                     /* CHR  */
    ASC = 387,                     /* ASC  */
    LEN = 388,                     /* LEN  */
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
    JUP = 451,                     /* JUP  */
    JDOWN = 452,                   /* JDOWN  */
    JLEFT = 453,                   /* JLEFT  */
    JRIGHT = 454,                  /* JRIGHT  */
    JFIRE = 455,                   /* JFIRE  */
    INKEY = 456,                   /* INKEY  */
    SCANCODE = 457,                /* SCANCODE  */
    SCAN = 458,                    /* SCAN  */
    SHIFT = 459,                   /* SHIFT  */
    SCANSHIFT = 460,               /* SCANSHIFT  */
    BOTH = 461,                    /* BOTH  */
    SHIFTS = 462,                  /* SHIFTS  */
    BLACK = 463,                   /* BLACK  */
    WHITE = 464,                   /* WHITE  */
    RED = 465,                     /* RED  */
    CYAN = 466,                    /* CYAN  */
    VIOLET = 467,                  /* VIOLET  */
    GREEN = 468,                   /* GREEN  */
    BLUE = 469,                    /* BLUE  */
    YELLOW = 470,                  /* YELLOW  */
    ORANGE = 471,                  /* ORANGE  */
    BROWN = 472,                   /* BROWN  */
    LIGHT = 473,                   /* LIGHT  */
    DARK = 474,                    /* DARK  */
    GREY = 475,                    /* GREY  */
    GRAY = 476,                    /* GRAY  */
    MAGENTA = 477,                 /* MAGENTA  */
    PURPLE = 478,                  /* PURPLE  */
    LAVENDER = 479,                /* LAVENDER  */
    GOLD = 480,                    /* GOLD  */
    TURQUOISE = 481,               /* TURQUOISE  */
    TAN = 482,                     /* TAN  */
    PINK = 483,                    /* PINK  */
    PEACH = 484,                   /* PEACH  */
    OLIVE = 485,                   /* OLIVE  */
    Identifier = 486,              /* Identifier  */
    String = 487,                  /* String  */
    Integer = 488                  /* Integer  */
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

#line 302 "src-generated/ugbc.tab.h"

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
