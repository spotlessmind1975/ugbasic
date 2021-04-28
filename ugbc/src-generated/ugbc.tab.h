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
    RASTER = 275,                  /* RASTER  */
    DONE = 276,                    /* DONE  */
    AT = 277,                      /* AT  */
    COLOR = 278,                   /* COLOR  */
    BORDER = 279,                  /* BORDER  */
    WAIT = 280,                    /* WAIT  */
    NEXT = 281,                    /* NEXT  */
    WITH = 282,                    /* WITH  */
    BANK = 283,                    /* BANK  */
    SPRITE = 284,                  /* SPRITE  */
    DATA = 285,                    /* DATA  */
    FROM = 286,                    /* FROM  */
    OP = 287,                      /* OP  */
    CP = 288,                      /* CP  */
    ENABLE = 289,                  /* ENABLE  */
    DISABLE = 290,                 /* DISABLE  */
    HALT = 291,                    /* HALT  */
    ECM = 292,                     /* ECM  */
    BITMAP = 293,                  /* BITMAP  */
    SCREEN = 294,                  /* SCREEN  */
    ON = 295,                      /* ON  */
    OFF = 296,                     /* OFF  */
    ROWS = 297,                    /* ROWS  */
    VERTICAL = 298,                /* VERTICAL  */
    SCROLL = 299,                  /* SCROLL  */
    VAR = 300,                     /* VAR  */
    AS = 301,                      /* AS  */
    TEMPORARY = 302,               /* TEMPORARY  */
    XPEN = 303,                    /* XPEN  */
    YPEN = 304,                    /* YPEN  */
    PEEK = 305,                    /* PEEK  */
    GOTO = 306,                    /* GOTO  */
    HORIZONTAL = 307,              /* HORIZONTAL  */
    MCM = 308,                     /* MCM  */
    COMPRESS = 309,                /* COMPRESS  */
    EXPAND = 310,                  /* EXPAND  */
    LOOP = 311,                    /* LOOP  */
    REPEAT = 312,                  /* REPEAT  */
    WHILE = 313,                   /* WHILE  */
    TEXT = 314,                    /* TEXT  */
    TILES = 315,                   /* TILES  */
    COLORMAP = 316,                /* COLORMAP  */
    SELECT = 317,                  /* SELECT  */
    MONOCOLOR = 318,               /* MONOCOLOR  */
    MULTICOLOR = 319,              /* MULTICOLOR  */
    COLLISION = 320,               /* COLLISION  */
    IF = 321,                      /* IF  */
    THEN = 322,                    /* THEN  */
    HIT = 323,                     /* HIT  */
    BACKGROUND = 324,              /* BACKGROUND  */
    TO = 325,                      /* TO  */
    RANDOM = 326,                  /* RANDOM  */
    BYTE = 327,                    /* BYTE  */
    WORD = 328,                    /* WORD  */
    POSITION = 329,                /* POSITION  */
    CODE = 330,                    /* CODE  */
    VARIABLES = 331,               /* VARIABLES  */
    MS = 332,                      /* MS  */
    CYCLES = 333,                  /* CYCLES  */
    S = 334,                       /* S  */
    HASH = 335,                    /* HASH  */
    WIDTH = 336,                   /* WIDTH  */
    HEIGHT = 337,                  /* HEIGHT  */
    DWORD = 338,                   /* DWORD  */
    PEN = 339,                     /* PEN  */
    CLEAR = 340,                   /* CLEAR  */
    BEG = 341,                     /* BEG  */
    END = 342,                     /* END  */
    GAMELOOP = 343,                /* GAMELOOP  */
    ENDIF = 344,                   /* ENDIF  */
    UP = 345,                      /* UP  */
    DOWN = 346,                    /* DOWN  */
    LEFT = 347,                    /* LEFT  */
    RIGHT = 348,                   /* RIGHT  */
    DEBUG = 349,                   /* DEBUG  */
    AND = 350,                     /* AND  */
    RANDOMIZE = 351,               /* RANDOMIZE  */
    GRAPHIC = 352,                 /* GRAPHIC  */
    TEXTMAP = 353,                 /* TEXTMAP  */
    POINT = 354,                   /* POINT  */
    GOSUB = 355,                   /* GOSUB  */
    RETURN = 356,                  /* RETURN  */
    POP = 357,                     /* POP  */
    OR = 358,                      /* OR  */
    ELSE = 359,                    /* ELSE  */
    NOT = 360,                     /* NOT  */
    TRUE = 361,                    /* TRUE  */
    FALSE = 362,                   /* FALSE  */
    DO = 363,                      /* DO  */
    EXIT = 364,                    /* EXIT  */
    WEND = 365,                    /* WEND  */
    UNTIL = 366,                   /* UNTIL  */
    FOR = 367,                     /* FOR  */
    STEP = 368,                    /* STEP  */
    EVERY = 369,                   /* EVERY  */
    MILLISECOND = 370,             /* MILLISECOND  */
    MILLISECONDS = 371,            /* MILLISECONDS  */
    TICKS = 372,                   /* TICKS  */
    BLACK = 373,                   /* BLACK  */
    WHITE = 374,                   /* WHITE  */
    RED = 375,                     /* RED  */
    CYAN = 376,                    /* CYAN  */
    VIOLET = 377,                  /* VIOLET  */
    GREEN = 378,                   /* GREEN  */
    BLUE = 379,                    /* BLUE  */
    YELLOW = 380,                  /* YELLOW  */
    ORANGE = 381,                  /* ORANGE  */
    BROWN = 382,                   /* BROWN  */
    LIGHT = 383,                   /* LIGHT  */
    DARK = 384,                    /* DARK  */
    GREY = 385,                    /* GREY  */
    GRAY = 386,                    /* GRAY  */
    MAGENTA = 387,                 /* MAGENTA  */
    PURPLE = 388,                  /* PURPLE  */
    LAVENDER = 389,                /* LAVENDER  */
    GOLD = 390,                    /* GOLD  */
    TURQUOISE = 391,               /* TURQUOISE  */
    TAN = 392,                     /* TAN  */
    PINK = 393,                    /* PINK  */
    PEACH = 394,                   /* PEACH  */
    OLIVE = 395,                   /* OLIVE  */
    Identifier = 396,              /* Identifier  */
    String = 397,                  /* String  */
    Integer = 398                  /* Integer  */
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

#line 212 "src-generated/ugbc.tab.h"

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
