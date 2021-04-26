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
DOWN { return (DOWN); }
DWORD { return (DWORD); }
ECM { return(ECM); }
END { return (END); }
ENDIF { return (ENDIF); }
ENABLE { return (ENABLE); }
EXPAND { return (EXPAND); }
FROM { return (FROM); }
GAMELOOP { return (GAMELOOP); }
GOLD { return(GOLD); }
GOTO { return (GOTO); }
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
MS { return(MS); }
MULTICOLOR { return(MULTICOLOR); }
OLIVE { return(OLIVE); }
OFF { return (OFF); }
ON { return (ON); }
ORANGE { return(ORANGE); }
PEACH { return(PEACH); }
PEEK { return (PEEK); }
PEN { return (PEN); }
PINK { return(PINK); }
POINT { return (POINT); }
POSITION { return (POSITION); }
PURPLE { return(PURPLE); }
RANDOM { return (RANDOM); }
RANDOMIZE { return (RANDOMIZE); }
RASTER { return (RASTER); }
RED { return(RED); }
REPEAT { return (REPEAT); }
RIGHT { return (RIGHT); }
ROWS { return (ROWS); }
S { return (S); }
SCREEN { return (SCREEN); }
SCROLL { return (SCROLL); }
MS { return (MILLISECOND); }
MILLISECOND { return (MILLISECOND); }
MILLISECONDS { return (MILLISECONDS); }
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
UP { return (UP); }
VAR { return (VAR); }
VARIABLES { return (VARIABLES); }
VERTICAL { return (VERTICAL); }
VIOLET { return(VIOLET); }
WAIT { return (WAIT); }
WITH { return (WITH); }
WIDTH { return (WIDTH); }
WHILE { return (WHILE); }
WHITE { return(WHITE); }
WORD { return (WORD); }
XPEN { return (XPEN); }
YELLOW { return(YELLOW); }
YPEN { return (YPEN); }

[A-Za-z][A-Za-z0-9]* { yylval.string = strdup(yytext); return(Identifier);  }
\"(\\.|[^"\\])*\" { yylval.string = strdup(yytext); memcpy(yylval.string,yylval.string+1,strlen(yylval.string)); yylval.string[strlen(yylval.string)-1]=0; return(String);  }
$[0-9A-fa-f]+ { yylval.integer = strtol(yytext+1,0,16); return(Integer); }
[0-9]+ { yylval.integer = atoi(yytext); return(Integer);  }
REM\s*[^\n\r]+[\n\r] { return(Remark);  }

[ \t]+
. { return(yytext[0]); }

%%
