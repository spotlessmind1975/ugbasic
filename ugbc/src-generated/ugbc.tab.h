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
    AND = 355,                     /* AND  */
    RANDOMIZE = 356,               /* RANDOMIZE  */
    GRAPHIC = 357,                 /* GRAPHIC  */
    TEXTMAP = 358,                 /* TEXTMAP  */
    POINT = 359,                   /* POINT  */
    GOSUB = 360,                   /* GOSUB  */
    RETURN = 361,                  /* RETURN  */
    POP = 362,                     /* POP  */
    OR = 363,                      /* OR  */
    ELSE = 364,                    /* ELSE  */
    NOT = 365,                     /* NOT  */
    TRUE = 366,                    /* TRUE  */
    FALSE = 367,                   /* FALSE  */
    DO = 368,                      /* DO  */
    EXIT = 369,                    /* EXIT  */
    WEND = 370,                    /* WEND  */
    UNTIL = 371,                   /* UNTIL  */
    FOR = 372,                     /* FOR  */
    STEP = 373,                    /* STEP  */
    EVERY = 374,                   /* EVERY  */
    MID = 375,                     /* MID  */
    INSTR = 376,                   /* INSTR  */
    UPPER = 377,                   /* UPPER  */
    LOWER = 378,                   /* LOWER  */
    STR = 379,                     /* STR  */
    VAL = 380,                     /* VAL  */
    STRING = 381,                  /* STRING  */
    SPACE = 382,                   /* SPACE  */
    FLIP = 383,                    /* FLIP  */
    CHR = 384,                     /* CHR  */
    ASC = 385,                     /* ASC  */
    LEN = 386,                     /* LEN  */
    MOD = 387,                     /* MOD  */
    ADD = 388,                     /* ADD  */
    MIN = 389,                     /* MIN  */
    MAX = 390,                     /* MAX  */
    SGN = 391,                     /* SGN  */
    SIGNED = 392,                  /* SIGNED  */
    ABS = 393,                     /* ABS  */
    RND = 394,                     /* RND  */
    COLORS = 395,                  /* COLORS  */
    INK = 396,                     /* INK  */
    TIMER = 397,                   /* TIMER  */
    POWERING = 398,                /* POWERING  */
    DIM = 399,                     /* DIM  */
    ADDRESS = 400,                 /* ADDRESS  */
    PROC = 401,                    /* PROC  */
    PROCEDURE = 402,               /* PROCEDURE  */
    CALL = 403,                    /* CALL  */
    OSP = 404,                     /* OSP  */
    CSP = 405,                     /* CSP  */
    SHARED = 406,                  /* SHARED  */
    MILLISECOND = 407,             /* MILLISECOND  */
    MILLISECONDS = 408,            /* MILLISECONDS  */
    TICKS = 409,                   /* TICKS  */
    GLOBAL = 410,                  /* GLOBAL  */
    PARAM = 411,                   /* PARAM  */
    PRINT = 412,                   /* PRINT  */
    DEFAULT = 413,                 /* DEFAULT  */
    USE = 414,                     /* USE  */
    PAPER = 415,                   /* PAPER  */
    INVERSE = 416,                 /* INVERSE  */
    REPLACE = 417,                 /* REPLACE  */
    XOR = 418,                     /* XOR  */
    IGNORE = 419,                  /* IGNORE  */
    NORMAL = 420,                  /* NORMAL  */
    WRITING = 421,                 /* WRITING  */
    ONLY = 422,                    /* ONLY  */
    LOCATE = 423,                  /* LOCATE  */
    CLS = 424,                     /* CLS  */
    HOME = 425,                    /* HOME  */
    CMOVE = 426,                   /* CMOVE  */
    CENTER = 427,                  /* CENTER  */
    CENTRE = 428,                  /* CENTRE  */
    TAB = 429,                     /* TAB  */
    SET = 430,                     /* SET  */
    CUP = 431,                     /* CUP  */
    CDOWN = 432,                   /* CDOWN  */
    CLEFT = 433,                   /* CLEFT  */
    CRIGHT = 434,                  /* CRIGHT  */
    CLINE = 435,                   /* CLINE  */
    XCURS = 436,                   /* XCURS  */
    YCURS = 437,                   /* YCURS  */
    MEMORIZE = 438,                /* MEMORIZE  */
    REMEMBER = 439,                /* REMEMBER  */
    HSCROLL = 440,                 /* HSCROLL  */
    VSCROLL = 441,                 /* VSCROLL  */
    TEXTADDRESS = 442,             /* TEXTADDRESS  */
    JOY = 443,                     /* JOY  */
    BIN = 444,                     /* BIN  */
    BIT = 445,                     /* BIT  */
    COUNT = 446,                   /* COUNT  */
    JOYCOUNT = 447,                /* JOYCOUNT  */
    FIRE = 448,                    /* FIRE  */
    JUP = 449,                     /* JUP  */
    JDOWN = 450,                   /* JDOWN  */
    JLEFT = 451,                   /* JLEFT  */
    JRIGHT = 452,                  /* JRIGHT  */
    JFIRE = 453,                   /* JFIRE  */
    INKEY = 454,                   /* INKEY  */
    SCANCODE = 455,                /* SCANCODE  */
    SCAN = 456,                    /* SCAN  */
    SHIFT = 457,                   /* SHIFT  */
    SCANSHIFT = 458,               /* SCANSHIFT  */
    BOTH = 459,                    /* BOTH  */
    SHIFTS = 460,                  /* SHIFTS  */
    NONE = 461,                    /* NONE  */
    LETTER = 462,                  /* LETTER  */
    ASTERISK = 463,                /* ASTERISK  */
    COLON = 464,                   /* COLON  */
    COMMA = 465,                   /* COMMA  */
    COMMODORE = 466,               /* COMMODORE  */
    CONTROL = 467,                 /* CONTROL  */
    CRSR = 468,                    /* CRSR  */
    CURSOR = 469,                  /* CURSOR  */
    DELETE = 470,                  /* DELETE  */
    EQUAL = 471,                   /* EQUAL  */
    FUNCTION = 472,                /* FUNCTION  */
    INSERT = 473,                  /* INSERT  */
    ARROW = 474,                   /* ARROW  */
    MINUS = 475,                   /* MINUS  */
    PERIOD = 476,                  /* PERIOD  */
    PLUS = 477,                    /* PLUS  */
    POUND = 478,                   /* POUND  */
    RUNSTOP = 479,                 /* RUNSTOP  */
    RUN = 480,                     /* RUN  */
    STOP = 481,                    /* STOP  */
    SEMICOLON = 482,               /* SEMICOLON  */
    SLASH = 483,                   /* SLASH  */
    KEY = 484,                     /* KEY  */
    STATE = 485,                   /* STATE  */
    KEYSTATE = 486,                /* KEYSTATE  */
    KEYSHIFT = 487,                /* KEYSHIFT  */
    CAPSLOCK = 488,                /* CAPSLOCK  */
    CAPS = 489,                    /* CAPS  */
    LOCK = 490,                    /* LOCK  */
    ALT = 491,                     /* ALT  */
    INPUT = 492,                   /* INPUT  */
    FREE = 493,                    /* FREE  */
    TILEMAP = 494,                 /* TILEMAP  */
    EMPTY = 495,                   /* EMPTY  */
    TILE = 496,                    /* TILE  */
    EMPTYTILE = 497,               /* EMPTYTILE  */
    PLOT = 498,                    /* PLOT  */
    GR = 499,                      /* GR  */
    CIRCLE = 500,                  /* CIRCLE  */
    DRAW = 501,                    /* DRAW  */
    LINE = 502,                    /* LINE  */
    BOX = 503,                     /* BOX  */
    POLYLINE = 504,                /* POLYLINE  */
    ELLIPSE = 505,                 /* ELLIPSE  */
    CLIP = 506,                    /* CLIP  */
    BACK = 507,                    /* BACK  */
    DEBUG = 508,                   /* DEBUG  */
    CAN = 509,                     /* CAN  */
    A = 510,                       /* A  */
    B = 511,                       /* B  */
    C = 512,                       /* C  */
    D = 513,                       /* D  */
    E = 514,                       /* E  */
    F = 515,                       /* F  */
    G = 516,                       /* G  */
    H = 517,                       /* H  */
    I = 518,                       /* I  */
    J = 519,                       /* J  */
    K = 520,                       /* K  */
    L = 521,                       /* L  */
    M = 522,                       /* M  */
    N = 523,                       /* N  */
    O = 524,                       /* O  */
    P = 525,                       /* P  */
    Q = 526,                       /* Q  */
    R = 527,                       /* R  */
    S = 528,                       /* S  */
    T = 529,                       /* T  */
    U = 530,                       /* U  */
    V = 531,                       /* V  */
    X = 532,                       /* X  */
    Y = 533,                       /* Y  */
    W = 534,                       /* W  */
    Z = 535,                       /* Z  */
    F1 = 536,                      /* F1  */
    F2 = 537,                      /* F2  */
    F3 = 538,                      /* F3  */
    F4 = 539,                      /* F4  */
    F5 = 540,                      /* F5  */
    F6 = 541,                      /* F6  */
    F7 = 542,                      /* F7  */
    F8 = 543,                      /* F8  */
    BLACK = 544,                   /* BLACK  */
    WHITE = 545,                   /* WHITE  */
    RED = 546,                     /* RED  */
    CYAN = 547,                    /* CYAN  */
    VIOLET = 548,                  /* VIOLET  */
    GREEN = 549,                   /* GREEN  */
    BLUE = 550,                    /* BLUE  */
    YELLOW = 551,                  /* YELLOW  */
    ORANGE = 552,                  /* ORANGE  */
    BROWN = 553,                   /* BROWN  */
    LIGHT = 554,                   /* LIGHT  */
    DARK = 555,                    /* DARK  */
    GREY = 556,                    /* GREY  */
    GRAY = 557,                    /* GRAY  */
    MAGENTA = 558,                 /* MAGENTA  */
    PURPLE = 559,                  /* PURPLE  */
    LAVENDER = 560,                /* LAVENDER  */
    GOLD = 561,                    /* GOLD  */
    TURQUOISE = 562,               /* TURQUOISE  */
    TAN = 563,                     /* TAN  */
    PINK = 564,                    /* PINK  */
    PEACH = 565,                   /* PEACH  */
    OLIVE = 566,                   /* OLIVE  */
    Identifier = 567,              /* Identifier  */
    String = 568,                  /* String  */
    Integer = 569                  /* Integer  */
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

#line 383 "src-generated/ugbc.tab.h"

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
