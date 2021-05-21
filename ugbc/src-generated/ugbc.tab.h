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
    RASTER = 278,                  /* RASTER  */
    DONE = 279,                    /* DONE  */
    AT = 280,                      /* AT  */
    COLOR = 281,                   /* COLOR  */
    BORDER = 282,                  /* BORDER  */
    WAIT = 283,                    /* WAIT  */
    NEXT = 284,                    /* NEXT  */
    WITH = 285,                    /* WITH  */
    BANK = 286,                    /* BANK  */
    SPRITE = 287,                  /* SPRITE  */
    DATA = 288,                    /* DATA  */
    FROM = 289,                    /* FROM  */
    OP = 290,                      /* OP  */
    CP = 291,                      /* CP  */
    ENABLE = 292,                  /* ENABLE  */
    DISABLE = 293,                 /* DISABLE  */
    HALT = 294,                    /* HALT  */
    ECM = 295,                     /* ECM  */
    BITMAP = 296,                  /* BITMAP  */
    SCREEN = 297,                  /* SCREEN  */
    ON = 298,                      /* ON  */
    OFF = 299,                     /* OFF  */
    ROWS = 300,                    /* ROWS  */
    VERTICAL = 301,                /* VERTICAL  */
    SCROLL = 302,                  /* SCROLL  */
    VAR = 303,                     /* VAR  */
    AS = 304,                      /* AS  */
    TEMPORARY = 305,               /* TEMPORARY  */
    XPEN = 306,                    /* XPEN  */
    YPEN = 307,                    /* YPEN  */
    PEEK = 308,                    /* PEEK  */
    GOTO = 309,                    /* GOTO  */
    HORIZONTAL = 310,              /* HORIZONTAL  */
    MCM = 311,                     /* MCM  */
    COMPRESS = 312,                /* COMPRESS  */
    EXPAND = 313,                  /* EXPAND  */
    LOOP = 314,                    /* LOOP  */
    REPEAT = 315,                  /* REPEAT  */
    WHILE = 316,                   /* WHILE  */
    TEXT = 317,                    /* TEXT  */
    TILES = 318,                   /* TILES  */
    COLORMAP = 319,                /* COLORMAP  */
    SELECT = 320,                  /* SELECT  */
    MONOCOLOR = 321,               /* MONOCOLOR  */
    MULTICOLOR = 322,              /* MULTICOLOR  */
    COLLISION = 323,               /* COLLISION  */
    IF = 324,                      /* IF  */
    THEN = 325,                    /* THEN  */
    HIT = 326,                     /* HIT  */
    BACKGROUND = 327,              /* BACKGROUND  */
    TO = 328,                      /* TO  */
    RANDOM = 329,                  /* RANDOM  */
    BYTE = 330,                    /* BYTE  */
    WORD = 331,                    /* WORD  */
    POSITION = 332,                /* POSITION  */
    CODE = 333,                    /* CODE  */
    VARIABLES = 334,               /* VARIABLES  */
    MS = 335,                      /* MS  */
    CYCLES = 336,                  /* CYCLES  */
    S = 337,                       /* S  */
    HASH = 338,                    /* HASH  */
    WIDTH = 339,                   /* WIDTH  */
    HEIGHT = 340,                  /* HEIGHT  */
    DWORD = 341,                   /* DWORD  */
    PEN = 342,                     /* PEN  */
    CLEAR = 343,                   /* CLEAR  */
    BEG = 344,                     /* BEG  */
    END = 345,                     /* END  */
    GAMELOOP = 346,                /* GAMELOOP  */
    ENDIF = 347,                   /* ENDIF  */
    UP = 348,                      /* UP  */
    DOWN = 349,                    /* DOWN  */
    LEFT = 350,                    /* LEFT  */
    RIGHT = 351,                   /* RIGHT  */
    DEBUG = 352,                   /* DEBUG  */
    AND = 353,                     /* AND  */
    RANDOMIZE = 354,               /* RANDOMIZE  */
    GRAPHIC = 355,                 /* GRAPHIC  */
    TEXTMAP = 356,                 /* TEXTMAP  */
    POINT = 357,                   /* POINT  */
    GOSUB = 358,                   /* GOSUB  */
    RETURN = 359,                  /* RETURN  */
    POP = 360,                     /* POP  */
    OR = 361,                      /* OR  */
    ELSE = 362,                    /* ELSE  */
    NOT = 363,                     /* NOT  */
    TRUE = 364,                    /* TRUE  */
    FALSE = 365,                   /* FALSE  */
    DO = 366,                      /* DO  */
    EXIT = 367,                    /* EXIT  */
    WEND = 368,                    /* WEND  */
    UNTIL = 369,                   /* UNTIL  */
    FOR = 370,                     /* FOR  */
    STEP = 371,                    /* STEP  */
    EVERY = 372,                   /* EVERY  */
    MID = 373,                     /* MID  */
    INSTR = 374,                   /* INSTR  */
    UPPER = 375,                   /* UPPER  */
    LOWER = 376,                   /* LOWER  */
    STR = 377,                     /* STR  */
    VAL = 378,                     /* VAL  */
    STRING = 379,                  /* STRING  */
    SPACE = 380,                   /* SPACE  */
    FLIP = 381,                    /* FLIP  */
    CHR = 382,                     /* CHR  */
    ASC = 383,                     /* ASC  */
    LEN = 384,                     /* LEN  */
    POW = 385,                     /* POW  */
    MOD = 386,                     /* MOD  */
    ADD = 387,                     /* ADD  */
    MIN = 388,                     /* MIN  */
    MAX = 389,                     /* MAX  */
    SGN = 390,                     /* SGN  */
    SIGNED = 391,                  /* SIGNED  */
    ABS = 392,                     /* ABS  */
    RND = 393,                     /* RND  */
    COLORS = 394,                  /* COLORS  */
    INK = 395,                     /* INK  */
    TIMER = 396,                   /* TIMER  */
    POWERING = 397,                /* POWERING  */
    DIM = 398,                     /* DIM  */
    ADDRESS = 399,                 /* ADDRESS  */
    PROC = 400,                    /* PROC  */
    PROCEDURE = 401,               /* PROCEDURE  */
    CALL = 402,                    /* CALL  */
    OSP = 403,                     /* OSP  */
    CSP = 404,                     /* CSP  */
    SHARED = 405,                  /* SHARED  */
    MILLISECOND = 406,             /* MILLISECOND  */
    MILLISECONDS = 407,            /* MILLISECONDS  */
    TICKS = 408,                   /* TICKS  */
    GLOBAL = 409,                  /* GLOBAL  */
    PARAM = 410,                   /* PARAM  */
    PRINT = 411,                   /* PRINT  */
    DEFAULT = 412,                 /* DEFAULT  */
    USE = 413,                     /* USE  */
    PAPER = 414,                   /* PAPER  */
    INVERSE = 415,                 /* INVERSE  */
    REPLACE = 416,                 /* REPLACE  */
    XOR = 417,                     /* XOR  */
    IGNORE = 418,                  /* IGNORE  */
    NORMAL = 419,                  /* NORMAL  */
    WRITING = 420,                 /* WRITING  */
    ONLY = 421,                    /* ONLY  */
    LOCATE = 422,                  /* LOCATE  */
    CLS = 423,                     /* CLS  */
    HOME = 424,                    /* HOME  */
    CMOVE = 425,                   /* CMOVE  */
    CENTER = 426,                  /* CENTER  */
    CENTRE = 427,                  /* CENTRE  */
    TAB = 428,                     /* TAB  */
    SET = 429,                     /* SET  */
    CUP = 430,                     /* CUP  */
    CDOWN = 431,                   /* CDOWN  */
    CLEFT = 432,                   /* CLEFT  */
    CRIGHT = 433,                  /* CRIGHT  */
    CLINE = 434,                   /* CLINE  */
    XCURS = 435,                   /* XCURS  */
    YCURS = 436,                   /* YCURS  */
    MEMORIZE = 437,                /* MEMORIZE  */
    REMEMBER = 438,                /* REMEMBER  */
    HSCROLL = 439,                 /* HSCROLL  */
    VSCROLL = 440,                 /* VSCROLL  */
    TEXTADDRESS = 441,             /* TEXTADDRESS  */
    BLACK = 442,                   /* BLACK  */
    WHITE = 443,                   /* WHITE  */
    RED = 444,                     /* RED  */
    CYAN = 445,                    /* CYAN  */
    VIOLET = 446,                  /* VIOLET  */
    GREEN = 447,                   /* GREEN  */
    BLUE = 448,                    /* BLUE  */
    YELLOW = 449,                  /* YELLOW  */
    ORANGE = 450,                  /* ORANGE  */
    BROWN = 451,                   /* BROWN  */
    LIGHT = 452,                   /* LIGHT  */
    DARK = 453,                    /* DARK  */
    GREY = 454,                    /* GREY  */
    GRAY = 455,                    /* GRAY  */
    MAGENTA = 456,                 /* MAGENTA  */
    PURPLE = 457,                  /* PURPLE  */
    LAVENDER = 458,                /* LAVENDER  */
    GOLD = 459,                    /* GOLD  */
    TURQUOISE = 460,               /* TURQUOISE  */
    TAN = 461,                     /* TAN  */
    PINK = 462,                    /* PINK  */
    PEACH = 463,                   /* PEACH  */
    OLIVE = 464,                   /* OLIVE  */
    Identifier = 465,              /* Identifier  */
    String = 466,                  /* String  */
    Integer = 467                  /* Integer  */
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

#line 281 "src-generated/ugbc.tab.h"

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
