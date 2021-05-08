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
"++" { return(INC); }
"--" { return(DEC); }
"#" { return(HASH); }
"<" { return(LT); }
"<=" { return(LTE); }
">" { return(GT); }
">=" { return(GTE); }
"<>" { return(DISEQUAL); }
"*" { return(MULTIPLICATION); }
"$" { return(DOLLAR); }
"^" { return(POW); }
"/" { return(DIVISION); }

8BIT { return (BYTE); }
16BIT { return (WORD); }
32BIT { return (DWORD); }

AS { return (AS); }
ASC { return (ASC); }
AT { return (AT); }
ADD { return (ADD); }
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
CHR { return (CHR); }
CHR\$ { return (CHR); }
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
DEC { return (DEC); }
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
EXIT { return (EXIT); }
EXPAND { return (EXPAND); }
EVERY { return (EVERY); }
FALSE { return(FALSE); }
FLIP { return(FLIP); }
FLIP\$ { return(FLIP); }
FOR { return(FOR); }
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
INC { return (INC); }
INSTR { return (INSTR); }
LAVENDER { return(LAVENDER); }
LEFT { return (LEFT); }
LEFT\$ { return (LEFT); }
LEN { return (LEN); }
LIGHT { return(LIGHT); }
LOOP { return (LOOP); }
LOWER { return (LOWER); }
LOWER\$ { return (LOWER); }
MAGENTA { return(MAGENTA); }
NEXT { return (NEXT); }
MAX { return(MAX); }
MCM { return(MCM); }
MID { return(MID); }
MIN { return(MIN); }
MID\$ { return(MID); }
MOD { return(MOD); }
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
RIGHT\$ { return (RIGHT); }
ROWS { return (ROWS); }
S { return (S); }
SCREEN { return (SCREEN); }
SCROLL { return (SCROLL); }
SELECT { return (SELECT); }
SGN { return (SGN); }
SIGNED { return (SIGNED); }
SPACE { return (SPACE); }
SPRITE { return (SPRITE); }
STEP { return (STEP); }
STR { return (STR); }
STR\$ { return (STR); }
STRING { return (STRING); }
STRING\$ { return (STRING); }
TAN { return(TAN); }
TEMPORARY { return (TEMPORARY); }
TEXT { return (TEXT); }
TEXTMAP { return (TEXTMAP); }
THEN { return (THEN); }
TICKS { return (TICKS); }
TILES { return (TILES); }
TO { return (TO); }
TURQUOISE { return(TURQUOISE); }
TRUE { return(TRUE); }
UNTIL { return (UNTIL); }
UP { return (UP); }
UPPER { return (UPPER); }
UPPER\$ { return (UPPER); }
VAL { return (VAL); }
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
\s[-][0-9]+ { yylval.integer = atoi(yytext); return(Integer);  }
[0-9]+ { yylval.integer = atoi(yytext); return(Integer);  }
REM\s*[^\n\r]+[\n\r] { return(Remark);  }
'\s*[^\n\r]+[\n\r] { return(Remark);  }

[ \t]+
. { return(yytext[0]); }

%%
