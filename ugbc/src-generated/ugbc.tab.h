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
    RASTER = 274,                  /* RASTER  */
    DONE = 275,                    /* DONE  */
    AT = 276,                      /* AT  */
    COLOR = 277,                   /* COLOR  */
    BORDER = 278,                  /* BORDER  */
    WAIT = 279,                    /* WAIT  */
    NEXT = 280,                    /* NEXT  */
    WITH = 281,                    /* WITH  */
    BANK = 282,                    /* BANK  */
    SPRITE = 283,                  /* SPRITE  */
    DATA = 284,                    /* DATA  */
    FROM = 285,                    /* FROM  */
    OP = 286,                      /* OP  */
    CP = 287,                      /* CP  */
    ENABLE = 288,                  /* ENABLE  */
    DISABLE = 289,                 /* DISABLE  */
    HALT = 290,                    /* HALT  */
    ECM = 291,                     /* ECM  */
    BITMAP = 292,                  /* BITMAP  */
    SCREEN = 293,                  /* SCREEN  */
    ON = 294,                      /* ON  */
    OFF = 295,                     /* OFF  */
    ROWS = 296,                    /* ROWS  */
    VERTICAL = 297,                /* VERTICAL  */
    SCROLL = 298,                  /* SCROLL  */
    VAR = 299,                     /* VAR  */
    AS = 300,                      /* AS  */
    TEMPORARY = 301,               /* TEMPORARY  */
    XPEN = 302,                    /* XPEN  */
    YPEN = 303,                    /* YPEN  */
    PEEK = 304,                    /* PEEK  */
    GOTO = 305,                    /* GOTO  */
    HORIZONTAL = 306,              /* HORIZONTAL  */
    MCM = 307,                     /* MCM  */
    COMPRESS = 308,                /* COMPRESS  */
    EXPAND = 309,                  /* EXPAND  */
    LOOP = 310,                    /* LOOP  */
    REPEAT = 311,                  /* REPEAT  */
    WHILE = 312,                   /* WHILE  */
    TEXT = 313,                    /* TEXT  */
    TILES = 314,                   /* TILES  */
    COLORMAP = 315,                /* COLORMAP  */
    SELECT = 316,                  /* SELECT  */
    MONOCOLOR = 317,               /* MONOCOLOR  */
    MULTICOLOR = 318,              /* MULTICOLOR  */
    COLLISION = 319,               /* COLLISION  */
    IF = 320,                      /* IF  */
    THEN = 321,                    /* THEN  */
    HIT = 322,                     /* HIT  */
    BACKGROUND = 323,              /* BACKGROUND  */
    TO = 324,                      /* TO  */
    RANDOM = 325,                  /* RANDOM  */
    BYTE = 326,                    /* BYTE  */
    WORD = 327,                    /* WORD  */
    POSITION = 328,                /* POSITION  */
    CODE = 329,                    /* CODE  */
    VARIABLES = 330,               /* VARIABLES  */
    MS = 331,                      /* MS  */
    CYCLES = 332,                  /* CYCLES  */
    S = 333,                       /* S  */
    HASH = 334,                    /* HASH  */
    WIDTH = 335,                   /* WIDTH  */
    HEIGHT = 336,                  /* HEIGHT  */
    DWORD = 337,                   /* DWORD  */
    PEN = 338,                     /* PEN  */
    CLEAR = 339,                   /* CLEAR  */
    BEG = 340,                     /* BEG  */
    END = 341,                     /* END  */
    GAMELOOP = 342,                /* GAMELOOP  */
    ENDIF = 343,                   /* ENDIF  */
    UP = 344,                      /* UP  */
    DOWN = 345,                    /* DOWN  */
    LEFT = 346,                    /* LEFT  */
    RIGHT = 347,                   /* RIGHT  */
    DEBUG = 348,                   /* DEBUG  */
    AND = 349,                     /* AND  */
    RANDOMIZE = 350,               /* RANDOMIZE  */
    GRAPHIC = 351,                 /* GRAPHIC  */
    TEXTMAP = 352,                 /* TEXTMAP  */
    POINT = 353,                   /* POINT  */
    GOSUB = 354,                   /* GOSUB  */
    RETURN = 355,                  /* RETURN  */
    POP = 356,                     /* POP  */
    OR = 357,                      /* OR  */
    ELSE = 358,                    /* ELSE  */
    NOT = 359,                     /* NOT  */
    TRUE = 360,                    /* TRUE  */
    FALSE = 361,                   /* FALSE  */
    DO = 362,                      /* DO  */
    EXIT = 363,                    /* EXIT  */
    WEND = 364,                    /* WEND  */
    UNTIL = 365,                   /* UNTIL  */
    FOR = 366,                     /* FOR  */
    STEP = 367,                    /* STEP  */
    EVERY = 368,                   /* EVERY  */
    MILLISECOND = 369,             /* MILLISECOND  */
    MILLISECONDS = 370,            /* MILLISECONDS  */
    TICKS = 371,                   /* TICKS  */
    BLACK = 372,                   /* BLACK  */
    WHITE = 373,                   /* WHITE  */
    RED = 374,                     /* RED  */
    CYAN = 375,                    /* CYAN  */
    VIOLET = 376,                  /* VIOLET  */
    GREEN = 377,                   /* GREEN  */
    BLUE = 378,                    /* BLUE  */
    YELLOW = 379,                  /* YELLOW  */
    ORANGE = 380,                  /* ORANGE  */
    BROWN = 381,                   /* BROWN  */
    LIGHT = 382,                   /* LIGHT  */
    DARK = 383,                    /* DARK  */
    GREY = 384,                    /* GREY  */
    GRAY = 385,                    /* GRAY  */
    MAGENTA = 386,                 /* MAGENTA  */
    PURPLE = 387,                  /* PURPLE  */
    LAVENDER = 388,                /* LAVENDER  */
    GOLD = 389,                    /* GOLD  */
    TURQUOISE = 390,               /* TURQUOISE  */
    TAN = 391,                     /* TAN  */
    PINK = 392,                    /* PINK  */
    PEACH = 393,                   /* PEACH  */
    OLIVE = 394,                   /* OLIVE  */
    Identifier = 395,              /* Identifier  */
    String = 396,                  /* String  */
    Integer = 397                  /* Integer  */
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

#line 211 "src-generated/ugbc.tab.h"

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
