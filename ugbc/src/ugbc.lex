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
"[" { return(OSP); }
"]" { return(CSP); }
"?" { return(QM); }

8BIT { return (BYTE); }
16BIT { return (WORD); }
32BIT { return (DWORD); }

ABS { return (ABS); }
AS { return (AS); }
ASC { return (ASC); }
AT { return (AT); }
ADD { return (ADD); }
ADDRESS { return (ADDRESS); }
AND { return (AND); }
BACKGROUND { return (BACKGROUND); }
BANK { return (BANK); }
BEGIN { return (BEG); }
BIN\$ { return (BIN); }
BITMAP { return (BITMAP); }
BLACK { return (BLACK); }
BLUE { return (BLUE); }
BROWN { return(BROWN); }
BYTE { return (BYTE); }
BORDER { return (BORDER); }
CALL { return (CALL); }
CDOWN { return (CDOWN); }
CENTER { return (CENTER); }
CENTRE { return (CENTRE); }
CHR { return (CHR); }
CHR\$ { return (CHR); }
CLEAR { return (CLEAR); }
CLEFT { return (CLEFT); }
CLINE { return (CLINE); }
CLS { return (CLS); }
CMOVE { return (CMOVE); }
CODE { return (CODE); }
COLLISION { return (COLLISION); }
COLOR { return (COLOR); }
COLORS { return (COLORS); }
COLORMAP { return (COLORMAP); }
COMPRESS { return (COMPRESS); }
CRIGHT { return (CRIGHT); }
CUP { return (CUP); }
CYAN { return(CYAN); }
CYCLES { return (CYCLES); }
DARK { return(DARK); }
DATA { return (DATA); }
DEBUG { return (DEBUG); }
DEC { return (DEC); }
DEFAULT { return (DEFAULT); }
DIM { return (DIM); }
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
GLOBAL { return (GLOBAL); }
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
HOME { return (HOME); }
HORIZONTAL { return (HORIZONTAL); }
HSCROLL { return (HSCROLL); }
IF { return (IF); }
IGNORE { return (IGNORE); }
INC { return (INC); }
INK { return (INK); }
INVERSE { return (INVERSE); }
INSTR { return (INSTR); }
JOY { return (JOY); }
LAVENDER { return(LAVENDER); }
LEFT { return (LEFT); }
LEFT\$ { return (LEFT); }
LEN { return (LEN); }
LIGHT { return(LIGHT); }
LOCATE { return(LOCATE); }
LOOP { return (LOOP); }
LOWER { return (LOWER); }
LOWER\$ { return (LOWER); }
MAGENTA { return(MAGENTA); }
NEXT { return (NEXT); }
MAX { return(MAX); }
MCM { return(MCM); }
MEMORIZE { return(MEMORIZE); }
MID { return(MID); }
MIN { return(MIN); }
MID\$ { return(MID); }
MOD { return(MOD); }
MONOCOLOR { return(MONOCOLOR); }
MS { return (MILLISECOND); }
MILLISECOND { return (MILLISECOND); }
MILLISECONDS { return (MILLISECONDS); }
MULTICOLOR { return(MULTICOLOR); }
NORMAL { return(NORMAL); }
NOT { return(NOT); }
OLIVE { return(OLIVE); }
OFF { return (OFF); }
ON { return (ON); }
ONLY { return (ONLY); }
OR { return (OR); }
ORANGE { return(ORANGE); }
PAPER { return(PAPER); }
PARAM { return(PARAM); }
PEACH { return(PEACH); }
PEEK { return (PEEK); }
PEN { return (PEN); }
PINK { return(PINK); }
POINT { return (POINT); }
POP { return (POP); }
POSITION { return (POSITION); }
POW { return (POWERING); }
PRINT { return (PRINT); }
PROC { return (PROC); }
PROCEDURE { return (PROCEDURE); }
PURPLE { return(PURPLE); }
RANDOM { return (RANDOM); }
RANDOMIZE { return (RANDOMIZE); }
RASTER { return (RASTER); }
RED { return(RED); }
REMEMBER { return(REMEMBER); }
REPEAT { return (REPEAT); }
REPLACE { return (REPLACE); }
RETURN { return (RETURN); }
RIGHT { return (RIGHT); }
RIGHT\$ { return (RIGHT); }
RND { return (RND); }
ROWS { return (ROWS); }
S { return (S); }
SCREEN { return (SCREEN); }
SCROLL { return (SCROLL); }
SELECT { return (SELECT); }
SET { return (SET); }
SGN { return (SGN); }
SHARED { return (SHARED); }
SIGNED { return (SIGNED); }
SPACE { return (SPACE); }
SPRITE { return (SPRITE); }
STEP { return (STEP); }
STR { return (STR); }
STR\$ { return (STR); }
STRING { return (STRING); }
STRING\$ { return (STRING); }
TAB { return(TAB); }
TAN { return(TAN); }
TEMPORARY { return (TEMPORARY); }
TEXT { return (TEXT); }
TEXTMAP { return (TEXTMAP); }
TEXTADDRESS { return (TEXTADDRESS); }
THEN { return (THEN); }
TICKS { return (TICKS); }
TILES { return (TILES); }
TIMER { return (TIMER); }
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
VSCROLL { return (VSCROLL); }
WAIT { return (WAIT); }
WEND { return (WEND); }
WITH { return (WITH); }
WIDTH { return (WIDTH); }
WHILE { return (WHILE); }
WHITE { return(WHITE); }
WRITING { return(WRITING); }
WORD { return (WORD); }
XOR { return (XOR); }
XCURS { return (XCURS); }
XPEN { return (XPEN); }
YCURS { return (YCURS); }
YELLOW { return(YELLOW); }
YPEN { return (YPEN); }

"REM "[^\n\r]* { return(Remark);  }
"' "[^\n\r]* { return(Remark);  }

[A-Za-z][A-Za-z0-9\_]* { yylval.string = strdup(yytext); return(Identifier);  }
\"(\\.|[^"\\])*\" { yylval.string = strdup(yytext); memcpy(yylval.string,yylval.string+1,strlen(yylval.string)); yylval.string[strlen(yylval.string)-1]=0; return(String);  }
\\$[0-9A-fa-f]+ { yylval.integer = strtol(yytext+1,0,16); return(Integer); }
\s[-][0-9]+ { yylval.integer = atoi(yytext); return(Integer);  }
[0-9]+ { yylval.integer = atoi(yytext); return(Integer);  }

[ \t]+ 
. { return(yytext[0]); }

%%
