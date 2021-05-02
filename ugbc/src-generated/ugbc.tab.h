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
    RASTER = 276,                  /* RASTER  */
    DONE = 277,                    /* DONE  */
    AT = 278,                      /* AT  */
    COLOR = 279,                   /* COLOR  */
    BORDER = 280,                  /* BORDER  */
    WAIT = 281,                    /* WAIT  */
    NEXT = 282,                    /* NEXT  */
    WITH = 283,                    /* WITH  */
    BANK = 284,                    /* BANK  */
    SPRITE = 285,                  /* SPRITE  */
    DATA = 286,                    /* DATA  */
    FROM = 287,                    /* FROM  */
    OP = 288,                      /* OP  */
    CP = 289,                      /* CP  */
    ENABLE = 290,                  /* ENABLE  */
    DISABLE = 291,                 /* DISABLE  */
    HALT = 292,                    /* HALT  */
    ECM = 293,                     /* ECM  */
    BITMAP = 294,                  /* BITMAP  */
    SCREEN = 295,                  /* SCREEN  */
    ON = 296,                      /* ON  */
    OFF = 297,                     /* OFF  */
    ROWS = 298,                    /* ROWS  */
    VERTICAL = 299,                /* VERTICAL  */
    SCROLL = 300,                  /* SCROLL  */
    VAR = 301,                     /* VAR  */
    AS = 302,                      /* AS  */
    TEMPORARY = 303,               /* TEMPORARY  */
    XPEN = 304,                    /* XPEN  */
    YPEN = 305,                    /* YPEN  */
    PEEK = 306,                    /* PEEK  */
    GOTO = 307,                    /* GOTO  */
    HORIZONTAL = 308,              /* HORIZONTAL  */
    MCM = 309,                     /* MCM  */
    COMPRESS = 310,                /* COMPRESS  */
    EXPAND = 311,                  /* EXPAND  */
    LOOP = 312,                    /* LOOP  */
    REPEAT = 313,                  /* REPEAT  */
    WHILE = 314,                   /* WHILE  */
    TEXT = 315,                    /* TEXT  */
    TILES = 316,                   /* TILES  */
    COLORMAP = 317,                /* COLORMAP  */
    SELECT = 318,                  /* SELECT  */
    MONOCOLOR = 319,               /* MONOCOLOR  */
    MULTICOLOR = 320,              /* MULTICOLOR  */
    COLLISION = 321,               /* COLLISION  */
    IF = 322,                      /* IF  */
    THEN = 323,                    /* THEN  */
    HIT = 324,                     /* HIT  */
    BACKGROUND = 325,              /* BACKGROUND  */
    TO = 326,                      /* TO  */
    RANDOM = 327,                  /* RANDOM  */
    BYTE = 328,                    /* BYTE  */
    WORD = 329,                    /* WORD  */
    POSITION = 330,                /* POSITION  */
    CODE = 331,                    /* CODE  */
    VARIABLES = 332,               /* VARIABLES  */
    MS = 333,                      /* MS  */
    CYCLES = 334,                  /* CYCLES  */
    S = 335,                       /* S  */
    HASH = 336,                    /* HASH  */
    WIDTH = 337,                   /* WIDTH  */
    HEIGHT = 338,                  /* HEIGHT  */
    DWORD = 339,                   /* DWORD  */
    PEN = 340,                     /* PEN  */
    CLEAR = 341,                   /* CLEAR  */
    BEG = 342,                     /* BEG  */
    END = 343,                     /* END  */
    GAMELOOP = 344,                /* GAMELOOP  */
    ENDIF = 345,                   /* ENDIF  */
    UP = 346,                      /* UP  */
    DOWN = 347,                    /* DOWN  */
    LEFT = 348,                    /* LEFT  */
    RIGHT = 349,                   /* RIGHT  */
    DEBUG = 350,                   /* DEBUG  */
    AND = 351,                     /* AND  */
    RANDOMIZE = 352,               /* RANDOMIZE  */
    GRAPHIC = 353,                 /* GRAPHIC  */
    TEXTMAP = 354,                 /* TEXTMAP  */
    POINT = 355,                   /* POINT  */
    GOSUB = 356,                   /* GOSUB  */
    RETURN = 357,                  /* RETURN  */
    POP = 358,                     /* POP  */
    OR = 359,                      /* OR  */
    ELSE = 360,                    /* ELSE  */
    NOT = 361,                     /* NOT  */
    TRUE = 362,                    /* TRUE  */
    FALSE = 363,                   /* FALSE  */
    DO = 364,                      /* DO  */
    EXIT = 365,                    /* EXIT  */
    WEND = 366,                    /* WEND  */
    UNTIL = 367,                   /* UNTIL  */
    FOR = 368,                     /* FOR  */
    STEP = 369,                    /* STEP  */
    EVERY = 370,                   /* EVERY  */
    MID = 371,                     /* MID  */
    INSTR = 372,                   /* INSTR  */
    UPPER = 373,                   /* UPPER  */
    LOWER = 374,                   /* LOWER  */
    STR = 375,                     /* STR  */
    VAL = 376,                     /* VAL  */
    STRING = 377,                  /* STRING  */
    SPACE = 378,                   /* SPACE  */
    FLIP = 379,                    /* FLIP  */
    CHR = 380,                     /* CHR  */
    MILLISECOND = 381,             /* MILLISECOND  */
    MILLISECONDS = 382,            /* MILLISECONDS  */
    TICKS = 383,                   /* TICKS  */
    BLACK = 384,                   /* BLACK  */
    WHITE = 385,                   /* WHITE  */
    RED = 386,                     /* RED  */
    CYAN = 387,                    /* CYAN  */
    VIOLET = 388,                  /* VIOLET  */
    GREEN = 389,                   /* GREEN  */
    BLUE = 390,                    /* BLUE  */
    YELLOW = 391,                  /* YELLOW  */
    ORANGE = 392,                  /* ORANGE  */
    BROWN = 393,                   /* BROWN  */
    LIGHT = 394,                   /* LIGHT  */
    DARK = 395,                    /* DARK  */
    GREY = 396,                    /* GREY  */
    GRAY = 397,                    /* GRAY  */
    MAGENTA = 398,                 /* MAGENTA  */
    PURPLE = 399,                  /* PURPLE  */
    LAVENDER = 400,                /* LAVENDER  */
    GOLD = 401,                    /* GOLD  */
    TURQUOISE = 402,               /* TURQUOISE  */
    TAN = 403,                     /* TAN  */
    PINK = 404,                    /* PINK  */
    PEACH = 405,                   /* PEACH  */
    OLIVE = 406,                   /* OLIVE  */
    Identifier = 407,              /* Identifier  */
    String = 408,                  /* String  */
    Integer = 409                  /* Integer  */
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

#line 223 "src-generated/ugbc.tab.h"

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
