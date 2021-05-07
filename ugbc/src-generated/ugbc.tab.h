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
    INCREMENT = 265,               /* INCREMENT  */
    DECREMENT = 266,               /* DECREMENT  */
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
    RASTER = 277,                  /* RASTER  */
    DONE = 278,                    /* DONE  */
    AT = 279,                      /* AT  */
    COLOR = 280,                   /* COLOR  */
    BORDER = 281,                  /* BORDER  */
    WAIT = 282,                    /* WAIT  */
    NEXT = 283,                    /* NEXT  */
    WITH = 284,                    /* WITH  */
    BANK = 285,                    /* BANK  */
    SPRITE = 286,                  /* SPRITE  */
    DATA = 287,                    /* DATA  */
    FROM = 288,                    /* FROM  */
    OP = 289,                      /* OP  */
    CP = 290,                      /* CP  */
    ENABLE = 291,                  /* ENABLE  */
    DISABLE = 292,                 /* DISABLE  */
    HALT = 293,                    /* HALT  */
    ECM = 294,                     /* ECM  */
    BITMAP = 295,                  /* BITMAP  */
    SCREEN = 296,                  /* SCREEN  */
    ON = 297,                      /* ON  */
    OFF = 298,                     /* OFF  */
    ROWS = 299,                    /* ROWS  */
    VERTICAL = 300,                /* VERTICAL  */
    SCROLL = 301,                  /* SCROLL  */
    VAR = 302,                     /* VAR  */
    AS = 303,                      /* AS  */
    TEMPORARY = 304,               /* TEMPORARY  */
    XPEN = 305,                    /* XPEN  */
    YPEN = 306,                    /* YPEN  */
    PEEK = 307,                    /* PEEK  */
    GOTO = 308,                    /* GOTO  */
    HORIZONTAL = 309,              /* HORIZONTAL  */
    MCM = 310,                     /* MCM  */
    COMPRESS = 311,                /* COMPRESS  */
    EXPAND = 312,                  /* EXPAND  */
    LOOP = 313,                    /* LOOP  */
    REPEAT = 314,                  /* REPEAT  */
    WHILE = 315,                   /* WHILE  */
    TEXT = 316,                    /* TEXT  */
    TILES = 317,                   /* TILES  */
    COLORMAP = 318,                /* COLORMAP  */
    SELECT = 319,                  /* SELECT  */
    MONOCOLOR = 320,               /* MONOCOLOR  */
    MULTICOLOR = 321,              /* MULTICOLOR  */
    COLLISION = 322,               /* COLLISION  */
    IF = 323,                      /* IF  */
    THEN = 324,                    /* THEN  */
    HIT = 325,                     /* HIT  */
    BACKGROUND = 326,              /* BACKGROUND  */
    TO = 327,                      /* TO  */
    RANDOM = 328,                  /* RANDOM  */
    BYTE = 329,                    /* BYTE  */
    WORD = 330,                    /* WORD  */
    POSITION = 331,                /* POSITION  */
    CODE = 332,                    /* CODE  */
    VARIABLES = 333,               /* VARIABLES  */
    MS = 334,                      /* MS  */
    CYCLES = 335,                  /* CYCLES  */
    S = 336,                       /* S  */
    HASH = 337,                    /* HASH  */
    WIDTH = 338,                   /* WIDTH  */
    HEIGHT = 339,                  /* HEIGHT  */
    DWORD = 340,                   /* DWORD  */
    PEN = 341,                     /* PEN  */
    CLEAR = 342,                   /* CLEAR  */
    BEG = 343,                     /* BEG  */
    END = 344,                     /* END  */
    GAMELOOP = 345,                /* GAMELOOP  */
    ENDIF = 346,                   /* ENDIF  */
    UP = 347,                      /* UP  */
    DOWN = 348,                    /* DOWN  */
    LEFT = 349,                    /* LEFT  */
    RIGHT = 350,                   /* RIGHT  */
    DEBUG = 351,                   /* DEBUG  */
    AND = 352,                     /* AND  */
    RANDOMIZE = 353,               /* RANDOMIZE  */
    GRAPHIC = 354,                 /* GRAPHIC  */
    TEXTMAP = 355,                 /* TEXTMAP  */
    POINT = 356,                   /* POINT  */
    GOSUB = 357,                   /* GOSUB  */
    RETURN = 358,                  /* RETURN  */
    POP = 359,                     /* POP  */
    OR = 360,                      /* OR  */
    ELSE = 361,                    /* ELSE  */
    NOT = 362,                     /* NOT  */
    TRUE = 363,                    /* TRUE  */
    FALSE = 364,                   /* FALSE  */
    DO = 365,                      /* DO  */
    EXIT = 366,                    /* EXIT  */
    WEND = 367,                    /* WEND  */
    UNTIL = 368,                   /* UNTIL  */
    FOR = 369,                     /* FOR  */
    STEP = 370,                    /* STEP  */
    EVERY = 371,                   /* EVERY  */
    MID = 372,                     /* MID  */
    INSTR = 373,                   /* INSTR  */
    UPPER = 374,                   /* UPPER  */
    LOWER = 375,                   /* LOWER  */
    STR = 376,                     /* STR  */
    VAL = 377,                     /* VAL  */
    STRING = 378,                  /* STRING  */
    SPACE = 379,                   /* SPACE  */
    FLIP = 380,                    /* FLIP  */
    CHR = 381,                     /* CHR  */
    ASC = 382,                     /* ASC  */
    LEN = 383,                     /* LEN  */
    POW = 384,                     /* POW  */
    MOD = 385,                     /* MOD  */
    MILLISECOND = 386,             /* MILLISECOND  */
    MILLISECONDS = 387,            /* MILLISECONDS  */
    TICKS = 388,                   /* TICKS  */
    BLACK = 389,                   /* BLACK  */
    WHITE = 390,                   /* WHITE  */
    RED = 391,                     /* RED  */
    CYAN = 392,                    /* CYAN  */
    VIOLET = 393,                  /* VIOLET  */
    GREEN = 394,                   /* GREEN  */
    BLUE = 395,                    /* BLUE  */
    YELLOW = 396,                  /* YELLOW  */
    ORANGE = 397,                  /* ORANGE  */
    BROWN = 398,                   /* BROWN  */
    LIGHT = 399,                   /* LIGHT  */
    DARK = 400,                    /* DARK  */
    GREY = 401,                    /* GREY  */
    GRAY = 402,                    /* GRAY  */
    MAGENTA = 403,                 /* MAGENTA  */
    PURPLE = 404,                  /* PURPLE  */
    LAVENDER = 405,                /* LAVENDER  */
    GOLD = 406,                    /* GOLD  */
    TURQUOISE = 407,               /* TURQUOISE  */
    TAN = 408,                     /* TAN  */
    PINK = 409,                    /* PINK  */
    PEACH = 410,                   /* PEACH  */
    OLIVE = 411,                   /* OLIVE  */
    Identifier = 412,              /* Identifier  */
    String = 413,                  /* String  */
    Integer = 414                  /* Integer  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "src/ugbc.y"

    int integer;
    char * string;

#line 228 "src-generated/ugbc.tab.h"

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
