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
    RASTER = 269,                  /* RASTER  */
    DONE = 270,                    /* DONE  */
    AT = 271,                      /* AT  */
    COLOR = 272,                   /* COLOR  */
    BORDER = 273,                  /* BORDER  */
    WAIT = 274,                    /* WAIT  */
    NEXT = 275,                    /* NEXT  */
    WITH = 276,                    /* WITH  */
    BANK = 277,                    /* BANK  */
    SPRITE = 278,                  /* SPRITE  */
    DATA = 279,                    /* DATA  */
    FROM = 280,                    /* FROM  */
    OP = 281,                      /* OP  */
    CP = 282,                      /* CP  */
    ENABLE = 283,                  /* ENABLE  */
    DISABLE = 284,                 /* DISABLE  */
    HALT = 285,                    /* HALT  */
    ECM = 286,                     /* ECM  */
    BITMAP = 287,                  /* BITMAP  */
    SCREEN = 288,                  /* SCREEN  */
    ON = 289,                      /* ON  */
    OFF = 290,                     /* OFF  */
    ROWS = 291,                    /* ROWS  */
    VERTICAL = 292,                /* VERTICAL  */
    SCROLL = 293,                  /* SCROLL  */
    VAR = 294,                     /* VAR  */
    AS = 295,                      /* AS  */
    TEMPORARY = 296,               /* TEMPORARY  */
    XPEN = 297,                    /* XPEN  */
    YPEN = 298,                    /* YPEN  */
    PEEK = 299,                    /* PEEK  */
    GOTO = 300,                    /* GOTO  */
    HORIZONTAL = 301,              /* HORIZONTAL  */
    MCM = 302,                     /* MCM  */
    COMPRESS = 303,                /* COMPRESS  */
    EXPAND = 304,                  /* EXPAND  */
    LOOP = 305,                    /* LOOP  */
    REPEAT = 306,                  /* REPEAT  */
    WHILE = 307,                   /* WHILE  */
    TEXT = 308,                    /* TEXT  */
    TILES = 309,                   /* TILES  */
    COLORMAP = 310,                /* COLORMAP  */
    SELECT = 311,                  /* SELECT  */
    MONOCOLOR = 312,               /* MONOCOLOR  */
    MULTICOLOR = 313,              /* MULTICOLOR  */
    COLLISION = 314,               /* COLLISION  */
    IF = 315,                      /* IF  */
    THEN = 316,                    /* THEN  */
    HIT = 317,                     /* HIT  */
    BACKGROUND = 318,              /* BACKGROUND  */
    TO = 319,                      /* TO  */
    RANDOM = 320,                  /* RANDOM  */
    BYTE = 321,                    /* BYTE  */
    WORD = 322,                    /* WORD  */
    POSITION = 323,                /* POSITION  */
    CODE = 324,                    /* CODE  */
    VARIABLES = 325,               /* VARIABLES  */
    MS = 326,                      /* MS  */
    CYCLES = 327,                  /* CYCLES  */
    S = 328,                       /* S  */
    HASH = 329,                    /* HASH  */
    WIDTH = 330,                   /* WIDTH  */
    HEIGHT = 331,                  /* HEIGHT  */
    DWORD = 332,                   /* DWORD  */
    PEN = 333,                     /* PEN  */
    CLEAR = 334,                   /* CLEAR  */
    BEG = 335,                     /* BEG  */
    END = 336,                     /* END  */
    GAMELOOP = 337,                /* GAMELOOP  */
    ENDIF = 338,                   /* ENDIF  */
    UP = 339,                      /* UP  */
    DOWN = 340,                    /* DOWN  */
    LEFT = 341,                    /* LEFT  */
    RIGHT = 342,                   /* RIGHT  */
    DEBUG = 343,                   /* DEBUG  */
    AND = 344,                     /* AND  */
    RANDOMIZE = 345,               /* RANDOMIZE  */
    GRAPHIC = 346,                 /* GRAPHIC  */
    TEXTMAP = 347,                 /* TEXTMAP  */
    POINT = 348,                   /* POINT  */
    BLACK = 349,                   /* BLACK  */
    WHITE = 350,                   /* WHITE  */
    RED = 351,                     /* RED  */
    CYAN = 352,                    /* CYAN  */
    VIOLET = 353,                  /* VIOLET  */
    GREEN = 354,                   /* GREEN  */
    BLUE = 355,                    /* BLUE  */
    YELLOW = 356,                  /* YELLOW  */
    ORANGE = 357,                  /* ORANGE  */
    BROWN = 358,                   /* BROWN  */
    LIGHT = 359,                   /* LIGHT  */
    DARK = 360,                    /* DARK  */
    GREY = 361,                    /* GREY  */
    GRAY = 362,                    /* GRAY  */
    MAGENTA = 363,                 /* MAGENTA  */
    PURPLE = 364,                  /* PURPLE  */
    LAVENDER = 365,                /* LAVENDER  */
    GOLD = 366,                    /* GOLD  */
    TURQUOISE = 367,               /* TURQUOISE  */
    TAN = 368,                     /* TAN  */
    PINK = 369,                    /* PINK  */
    PEACH = 370,                   /* PEACH  */
    OLIVE = 371,                   /* OLIVE  */
    Identifier = 372,              /* Identifier  */
    String = 373,                  /* String  */
    Integer = 374                  /* Integer  */
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

#line 188 "src-generated/ugbc.tab.h"

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
