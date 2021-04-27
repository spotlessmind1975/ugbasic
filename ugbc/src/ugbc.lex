%{

#include <string.h>
#include "ugbc.tab.h" /* The tokens */
%}

%option yylineno
      
%%

[\n\r]+ { return(NewLine);}
";" { return(SEMICOLON); }
":" { return(COLON); }
"(" { return(OP); }
")" { return(CP); }
"," { return(COMMA); }
"=" { return(ASSIGN); }
"==" { return(EQUAL); }
"+" { return(PLUS); }
"-" { return(MINUS); }
"++" { return(INCREMENT); }
"--" { return(DECREMENT); }
"#" { return(HASH); }
"<" { return(LT); }
"<=" { return(LTE); }
">" { return(GT); }
">=" { return(GTE); }
"<>" { return(DISEQUAL); }

8BIT { return (BYTE); }
16BIT { return (WORD); }
32BIT { return (DWORD); }

AS { return (AS); }
AT { return (AT); }
AND { return (AND); }
BACKGROUND { return (BACKGROUND); }
BANK { return (BANK); }
BEGIN { return (BEG); }
BITMAP { return (BITMAP); }
BLACK { return (BLACK); }
BLUE { return (BLUE); }
BROWN { return(BROWN); }
BYTE { return (BYTE); }
BORDER { return (BORDER); }
CLEAR { return (CLEAR); }
CODE { return (CODE); }
COLLISION { return (COLLISION); }
COLOR { return (COLOR); }
COLORMAP { return (COLORMAP); }
COMPRESS { return (COMPRESS); }
CYAN { return(CYAN); }
CYCLES { return (CYCLES); }
DARK { return(DARK); }
DATA { return (DATA); }
DEBUG { return (DEBUG); }
DISABLE { return (DISABLE); }
DONE { return (DONE); }
DO { return (DO); }
DOWN { return (DOWN); }
DWORD { return (DWORD); }
ECM { return(ECM); }
ELSE { return(ELSE); }
END { return (END); }
ENDIF { return (ENDIF); }
ENABLE { return (ENABLE); }
EXIT { return (EXPAND); }
EXPAND { return (EXPAND); }
FALSE { return(FALSE); }
FROM { return (FROM); }
GAMELOOP { return (GAMELOOP); }
GOLD { return(GOLD); }
GOTO { return (GOTO); }
GOSUB { return (GOSUB); }
GRAPHIC { return (GRAPHIC); }
GRAY { return(GRAY); }
GREEN { return(GREEN); }
GREY { return(GREY); }
HALT { return (HALT); }
HEIGHT { return (HEIGHT); }
HIT { return (HIT); }
HORIZONTAL { return (HORIZONTAL); }
IF { return (IF); }
LAVENDER { return(LAVENDER); }
LEFT { return (LEFT); }
LIGHT { return(LIGHT); }
LOOP { return (LOOP); }
MAGENTA { return(MAGENTA); }
NEXT { return (NEXT); }
MCM { return(MCM); }
MONOCOLOR { return(MONOCOLOR); }
MS { return (MILLISECOND); }
MILLISECOND { return (MILLISECOND); }
MILLISECONDS { return (MILLISECONDS); }
MULTICOLOR { return(MULTICOLOR); }
NOT { return(NOT); }
OLIVE { return(OLIVE); }
OFF { return (OFF); }
ON { return (ON); }
OR { return (OR); }
ORANGE { return(ORANGE); }
PEACH { return(PEACH); }
PEEK { return (PEEK); }
PEN { return (PEN); }
PINK { return(PINK); }
POINT { return (POINT); }
POP { return (POP); }
POSITION { return (POSITION); }
PURPLE { return(PURPLE); }
RANDOM { return (RANDOM); }
RANDOMIZE { return (RANDOMIZE); }
RASTER { return (RASTER); }
RED { return(RED); }
REPEAT { return (REPEAT); }
RETURN { return (RETURN); }
RIGHT { return (RIGHT); }
ROWS { return (ROWS); }
S { return (S); }
SCREEN { return (SCREEN); }
SCROLL { return (SCROLL); }
SELECT { return (SELECT); }
SPRITE { return (SPRITE); }
TAN { return(TAN); }
TEMPORARY { return (TEMPORARY); }
TEXT { return (TEXT); }
TEXTMAP { return (TEXTMAP); }
THEN { return (THEN); }
TICKS { return (TICKS); }
TILES { return (TILES); }
TURQUOISE { return(TURQUOISE); }
TRUE { return(TRUE); }
UP { return (UP); }
VAR { return (VAR); }
VARIABLES { return (VARIABLES); }
VERTICAL { return (VERTICAL); }
VIOLET { return(VIOLET); }
WAIT { return (WAIT); }
WEND { return (WEND); }
WITH { return (WITH); }
WIDTH { return (WIDTH); }
WHILE { return (WHILE); }
WHITE { return(WHITE); }
WORD { return (WORD); }
XPEN { return (XPEN); }
YELLOW { return(YELLOW); }
YPEN { return (YPEN); }

[A-Za-z][A-Za-z0-9\_]* { yylval.string = strdup(yytext); return(Identifier);  }
\"(\\.|[^"\\])*\" { yylval.string = strdup(yytext); memcpy(yylval.string,yylval.string+1,strlen(yylval.string)); yylval.string[strlen(yylval.string)-1]=0; return(String);  }
$[0-9A-fa-f]+ { yylval.integer = strtol(yytext+1,0,16); return(Integer); }
[0-9]+ { yylval.integer = atoi(yytext); return(Integer);  }
REM\s*[^\n\r]+[\n\r] { return(Remark);  }
'\s*[^\n\r]+[\n\r] { return(Remark);  }

[ \t]+
. { return(yytext[0]); }

%%
