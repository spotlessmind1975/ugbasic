%{

#include <string.h>
#include "ugbc.tab.h" /* The tokens */
%}

%option yylineno
      
%%

"#["[a-fA-F0-9]+"]" { yylval.string = strdup(yytext); return(BufferDefinition); }
"#["[a-fA-F0-9]+ { yylval.string = strdup(yytext); return(BufferDefinition); }

_[\n\r]+
[\n\r]+ { return(NewLine);}
";" { return(OP_SEMICOLON); }
":" { return(OP_COLON); }
"(" { return(OP); }
")" { return(CP); }
"," { return(OP_COMMA); }
"=" { return(OP_ASSIGN); }
"==" { return(OP_EQUAL); }
":=" { return(OP_ASSIGN_DIRECT); }
"+" { return(OP_PLUS); }
"-" { return(OP_MINUS); }
"++" { return(OP_INC); }
"--" { return(OP_DEC); }
"#" { return(OP_HASH); }
"<" { return(OP_LT); }
"<=" { return(OP_LTE); }
">" { return(OP_GT); }
">=" { return(OP_GTE); }
"<>" { return(OP_DISEQUAL); }
"*" { return(OP_MULTIPLICATION); }
"**" { return(OP_MULTIPLICATION2); }
"$" { return(OP_DOLLAR); }
"^" { return(OP_POW); }
"/" { return(OP_DIVISION); }
"\\" { return(OP_DIVISION2); }
"[" { return(OSP); }
"]" { return(CSP); }
"{" { return(OGP); }
"}" { return(CGP); }
"?" { return(QM); }

8BIT { return (BYTE); }
16BIT { return (WORD); }
32BIT { return (DWORD); }

A { return (A); }
ABS { return (ABS); }
Ab { return (ABS); }
ALT { return (ALT); }
Al { return (ALT); }
ARRAY { return (ARRAY); }
Ar { return (ARRAY); }
AS { return (AS); }
ASC { return (ASC); }
As { return (ASC); }
ASTERISK { return (ASTERISK); }
Ak { return (ASTERISK); }
AT { return (AT); }
ATARI { return (ATARI); }
At { return (ATARI); }
ATARIXL { return (ATARIXL); }
Ax { return (ATARIXL); }
ADD { return (ADD); }
Ad { return (ADD); }
ADDRESS { return (ADDRESS); }
A# { return (ADDRESS); }
AND { return (AND); }
An { return (AND); }
ARROW { return (ARROW); }
Aw { return (ARROW); }
B { return (B); }
BACK { return (BACK); }
Ba { return (BACK); }
BACKGROUND { return (BACKGROUND); }
Bg { return (BACKGROUND); }
BANK { return (BANK); }
Bk { return (BANK); }
BAR { return (BAR); }
Br { return (BAR); }
BEGIN { return (BEG); }
Be { return (BEG); }
BIN\$ { return (BIN); }
Bi { return (BIN); }
BIT { return (BIT); }
Bt { return (BIT); }
BOTH { return (BOTH); }
Bh { return (BOTH); }
BOX { return (BOX); }
Bx { return (BOX); }
BITMAP { return (BITMAP); }
Bm { return (BITMAP); }
BLACK { return (BLACK); }
Bl { return (BLACK); }
BLUE { return (BLUE); }
Bu { return (BLUE); }
BROWN { return(BROWN); }
Brn { return(BROWN); }
BYTE { return (BYTE); }
By { return (BYTE); }
BORDER { return (BORDER); }
Bo { return (BORDER); }
BUFFER { return (BUFFER); }
Bf { return (BUFFER); }
C { return (C); }
C64 { return (C64); }
CALL { return (CALL); }
Ca { return (CALL); }
CAN { return (CAN); }
Cn { return (CAN); }
CAPS { return (CAPS); }
Cp { return (CAPS); }
CAPSLOCK { return (CAPSLOCK); }
Cpl { return (CAPS); }
CASE { return (CASE); }
Cs { return (CASE); }
CDOWN { return (CDOWN); }
Cd { return (CDOWN); }
CENTER { return (CENTER); }
Ce { return (CENTER); }
CENTRE { return (CENTRE); }
CHR { return (CHR); }
CHR\$ { return (CHR); }
Ch { return (CHR); }
CIRCLE { return (CIRCLE); }
Ci { return (CIRCLE); }
CLEAR { return (CLEAR); }
Clr { return (CLEAR); }
CLEFT { return (CLEFT); }
Cle { return (CLEFT); }
CLINE { return (CLINE); }
Cln { return (CLINE); }
CLIP { return (CLIP); }
Cli { return (CLIP); }
CLS { return (CLS); }
Cl { return (CLS); }
CMOVE { return (CMOVE); }
Cm { return (CMOVE); }
CODE { return (CODE); }
Co { return (CODE); }
COLLISION { return (COLLISION); }
Col { return (COLLISION); }
COLON { return (COLON); }
COLOR { return (COLOR); }
COLOUR { return (COLOUR); }
Cr { return (COLOR); }
COLORS { return (COLORS); }
COLOURS { return (COLOURS); }
Crs { return (COLORS); }
COLORMAP { return (COLORMAP); }
COLOURMAP { return (COLOURMAP); }
Com { return (COLOURMAP); }
COLUMNS { return (COLUMNS); }
Cms { return (COLUMNS); }
COMMA { return (COMMA); }
COMMODORE { return (COMMODORE); }
C= { return (COMMODORE); }
COMPRESS { return (COMPRESS); }
Cmp { return (COMPRESS); }
CONST { return (CONST); }
C# { return (CONST); }
CONTROL { return (CONTROL); }
Ctrl { return (CONTROL); }
COUNT { return (COUNT); }
C% { return (COUNT); }
CRIGHT { return (CRIGHT); }
Crg { return (CRIGHT); }
CRSR { return (CRSR); }
CUP { return (CUP); }
Cu { return (CUP); }
CURSOR { return (CURSOR); }
Curs { return (CURSOR); }
CYAN { return(CYAN); }
Cy { return (CURSOR); }
CYCLES { return (CYCLES); }
Cyc { return (CYCLES); }
D { return (D); }
DARK { return(DARK); }
Dk { return(DARK); }
DATA { return (DATA); }
Da { return (DATA); }
DEBUG { return (DEBUG); }
De { return (DEBUG); }
DEC { return (OP_DEC); }
Dc { return (OP_DEC); }
DEFAULT { return (DEFAULT); }
Dft { return (DEFAULT); }
DEFINE { return (DEFINE); }
Def { return (DEFINE); }
DELETE { return (DELETE); }
Del { return (DELETE); }
DIM { return (DIM); }
Di { return (DIM); }
DISABLE { return (DISABLE); }
Dx { return (DISABLE); }
DISTANCE { return (DISTANCE); }
Dst { return (DISTANCE); }
DIV { return (DIV); }
Dv { return (DIV); }
DONE { return (DONE); }
Do { return (DONE); }
DO { return (DO); }
DOWN { return (DOWN); }
Dw { return (DOWN); }
DRAW { return (DRAW); }
Dr { return (DRAW); }
DRAGON { return (DRAGON); }
Dg { return (DRAGON); }
DRAGON32 { return (DRAGON32); }
Dg32 { return (DRAGON32); }
DRAGON64 { return (DRAGON64); }
Dg64 { return (DRAGON64); }
DWORD { return (DWORD); }
Dwd { return (DWORD); }
E { return (E); }
ECM { return(ECM); }
ELLIPSE { return(ELLIPSE); }
Ell { return(ELLIPSE); }
ELSE { return(ELSE); }
El { return(ELSE); }
ELSEIF { return(ELSEIF); }
Eif { return(ELSEIF); }
EMPTY { return(EMPTY); }
Em { return(EMPTY); }
EMPTYTILE { return(EMPTYTILE); }
Emt { return(EMPTYTILE); }
END { return (END); }
ENDIF { return (ENDIF); }
Ei { return (ENDIF); }
ENDSELECT { return (ENDSELECT); }
Es { return (ENDSELECT); }
ENABLE { return (ENABLE); }
En { return (ENABLE); }
EQUAL { return (EQUAL); }
Eq { return (EQUAL); }
EXIT { return (EXIT); }
Ex { return (EXIT); }
EXPAND { return (EXPAND); }
Exp { return (EXPAND); }
EVERY { return (EVERY); }
Ev { return (EVERY); }
FALSE { return(FALSE); }
Fa { return(FALSE); }
F { return (F); }
F1 { return (F1); }
F2 { return (F2); }
F3 { return (F3); }
F4 { return (F4); }
F5 { return (F5); }
F6 { return (F6); }
F7 { return (F7); }
F8 { return (F8); }
FILL { return (FILL); }
Fil { return (FILL); }
FIRE { return(FIRE); }
Fi { return(FIRE); }
FLIP { return(FLIP); }
FLIP\$ { return(FLIP); }
Fl { return(FLIP); }
FONT { return(FONT); }
Fnt { return(FONT); }
FOR { return(FOR); }
Fo { return(FOR); }
FRAME { return (FRAME); }
Fr { return (FRAME); }
FRAMES { return (FRAMES); }
Frs { return (FRAMES); }
FREE { return (FREE); }
Fre { return (FREE); }
FROM { return (FROM); }
Fm { return (FROM); }
FUNCTION { return (FUNCTION); }
Fu { return (FUNCTION); }
G { return (G); }
GAMELOOP { return (GAMELOOP); }
Gl { return (GAMELOOP); }
GET { return (GET); }
Ge { return (GET); }
GLOBAL { return (GLOBAL); }
Gb { return (GLOBAL); }
GOLD { return(GOLD); }
Gd { return(GOLD); }
GOTO { return (GOTO); }
Gt { return (GOTO); }
GOSUB { return (GOSUB); }
Gs { return (GOSUB); }
GR { return (GR); }
GRAPHIC { return (GRAPHIC); }
Gr { return (GRAPHIC); }
GRAY { return(GRAY); }
Gy { return(GRAY); }
GREEN { return(GREEN); }
Gre { return(GREEN); }
GREY { return(GREY); }
H { return (H); }
HALT { return (HALT); }
Ht { return (HALT); }
HAS { return (HAS); }
HEIGHT { return (HEIGHT); }
Hg { return (HEIGHT); }
HEX\$ { return (HEX); }
Hx { return (HEX); }
HIDE { return (HIDE); }
Hd { return (HIDE); }
HIDDEN { return (HIDDEN); }
Hdn { return (HIDDEN); }
HIT { return (HIT); }
HOME { return (HOME); }
Hm { return (HOME); }
HORIZONTAL { return (HORIZONTAL); }
Hz { return (HORIZONTAL); }
HSCROLL { return (HSCROLL); }
Hs { return (HSCROLL); }
I { return (I); }
IF { return (IF); }
IGNORE { return (IGNORE); }
Ig { return (IGNORE); }
IMAGE { return (IMAGE); }
Im { return (IMAGE); }
IMAGES { return (IMAGES); }
Ims { return (IMAGES); }
IN { return (IN); }
INC { return (OP_INC); }
In { return (OP_INC); }
INK { return (INK); }
Ik { return (INK); }
INKEY { return (INKEY); }
INKEY\$ { return (INKEY); }
Iky { return (INKEY); }
INPUT { return (INPUT); }
Ip { return (INPUT); }
INSERT { return (INSERT); }
Ins { return (INSERT); }
INVERSE { return (INVERSE); }
Inv { return (INVERSE); }
INSTR { return (INSTR); }
Ist { return (INSTR); }
IS { return (IS); }
J { return (J); }
JDOWN { return (JDOWN); }
Jd { return (JDOWN); }
JFIRE { return (JFIRE); }
Jf { return (JFIRE); }
JLEFT { return (JLEFT); }
Jl { return (JLEFT); }
JRIGHT { return (JRIGHT); }
Jr { return (JRIGHT); }
JUP { return (JUP); }
Ju { return (JUP); }
JOY { return (JOY); }
Jy { return (JOY); }
JOYCOUNT { return (JOYCOUNT); }
Jyc { return (JOYCOUNT); }
K { return (K); }
KEY { return (KEY); }
Ky { return (KEY); }
KEYSHIFT { return (KEYSHIFT); }
Ks { return (KEYSHIFT); }
KEYSTATE { return (KEYSTATE); }
Kt { return (KEYSTATE); }
L { return (L); }
LAVENDER { return(LAVENDER); }
La { return(LAVENDER); }
LEFT { return (LEFT); }
Lf { return (LEFT); }
LEFT\$ { return (LEFT); }
LEN { return (LEN); }
LETTER { return (LETTER); }
Lt { return (LETTER); }
LIGHT { return(LIGHT); }
Li { return(LIGHT); }
LINE { return(LINE); }
Ln { return(LINE); }
LOAD { return(LOAD); }
Ld { return(LOAD); }
LOCATE { return(LOCATE); }
Lc { return(LOCATE); }
LOCK { return (LOCK); }
Lk { return (LOCK); }
LOOP { return (LOOP); }
Lp { return (LOOP); }
LOWER { return (LOWER); }
Lw { return (LOWER); }
LOWER\$ { return (LOWER); }
M { return (M); }
MAGENTA { return(MAGENTA); }
Mg { return(MAGENTA); }
MASKED { return(MASKED); }
Mk { return(MASKED); }
MAX { return(MAX); }
Mx { return(MAX); }
MCM { return(MCM); }
MEMORIZE { return(MEMORIZE); }
Me { return(MEMORIZE); }
MID { return(MID); }
Md { return(MID); }
MID\$ { return(MID); }
MIN { return(MIN); }
Mn { return(MIN); }
MINUS { return(MINUS); }
Min { return(MINUS); }
MOB { return(MOB); }
Mb { return(MOB); }
MOD { return(MOD); }
M% { return(MOD); }
MONOCOLOR { return(MONOCOLOR); }
MONOCOLOUR { return(MONOCOLOUR); }
Mc { return(MONOCOLOR); }
MS { return (MILLISECOND); }
MILLISECOND { return (MILLISECOND); }
MILLISECONDS { return (MILLISECONDS); }
MUL { return(MUL); }
Mu { return(MUL); }
MULTICOLOR { return(MULTICOLOR); }
Mcs { return(MULTICOLOR); }
MULTICOLOUR { return(MULTICOLOUR); }
N { return (N); }
NEXT { return (NEXT); }
Nx { return (NEXT); }
NEW { return (NEW); }
Nw { return (NEW); }
NORMAL { return(NORMAL); }
No { return(NORMAL); }
NONE { return(NONE); }
Nn { return(NONE); }
NOP { return(NOP); }
Np { return(NOP); }
NOT { return(NOT); }
Nt { return(NOT); }
O { return (O); }
OF { return (OF); }
OFF { return (OFF); }
Of { return (OFF); }
OLIVE { return(OLIVE); }
Ol { return(OLIVE); }
ON { return (ON); }
ONLY { return (ONLY); }
On { return (ONLY); }
OR { return (OR); }
ORANGE { return(ORANGE); }
Or { return(ORANGE); }
OVERLAYED { return(OVERLAYED); }
Ov { return(OVERLAYED); }
P { return (P); }
PALETTE { return(PALETTE); }
Pal { return(PALETTE); }
PAPER { return(PAPER); }
Pa { return(PAPER); }
PARALLEL { return(PARALLEL); }
Pr { return(PARALLEL); }
PARAM { return(PARAM); }
Pm { return(PARAM); }
PEACH { return(PEACH); }
Pc { return(PEACH); }
PEEK { return (PEEK); }
Pk { return (PEEK); }
PEN { return (PEN); }
Pn { return (PEN); }
PERIOD { return (PERIOD); }
Per { return (PERIOD); }
PINK { return(PINK); }
Pik { return(PINK); }
PLOT { return(PLOT); }
Pl { return(PLOT); }
PLUS { return(PLUS); }
Plu { return(PLUS); }
PLUS4 { return (PLUS4); }
P4 { return (PLUS4); }
POINT { return (POINT); }
Pt { return (POINT); }
POKE { return (POKE); }
Po { return (POKE); }
POLYLINE { return (POLYLINE); }
Ply { return (POLYLINE); }
POSITIVE { return (POSITIVE); }
Pst { return (POSITIVE); }
POUND { return (POUND); }
Pnd { return (POUND); }
POP { return (POP); }
Pp { return (POP); }
POSITION { return (POSITION); }
Pos { return (POSITION); }
POW { return (POWERING); }
Pw { return (POWERING); }
PRINT { return (PRINT); }
PROC { return (PROC); }
Prc { return (PROC); }
PROCEDURE { return (PROCEDURE); }
Prcd { return (PROCEDURE); }
PURPLE { return(PURPLE); }
Pur { return(PURPLE); }
PUT { return(PUT); }
Pu { return(PUT); }
Q { return (Q); }
R { return (R); }
RANDOM { return (RANDOM); }
Rd { return (RANDOM); }
RANDOMIZE { return (RANDOMIZE); }
Rdm { return (RANDOMIZE); }
RASTER { return (RASTER); }
Rst { return (RASTER); }
RED { return(RED); }
Re { return(RED); }
REMEMBER { return(REMEMBER); }
Rm { return(REMEMBER); }
RENDER { return(RENDER); }
Rend { return(RENDER); }
REPEAT { return (REPEAT); }
Rpt { return (REPEAT); }
REPLACE { return (REPLACE); }
Rep { return (REPLACE); }
RETURN { return (RETURN); }
Rt { return (RETURN); }
RGB { return (RGB); }
RIGHT { return (RIGHT); }
RIGHT\$ { return (RIGHT); }
Rg { return (RIGHT); }
RND { return (RND); }
ROLL { return (ROLL); }
Rl { return (ROLL); }
ROWS { return (ROWS); }
Rws { return (ROWS); }
RUNSTOP { return (RUNSTOP); }
RUN { return (RUN); }
S { return (S); }
SCAN { return (SCAN); }
Scn { return (SCAN); }
SCANCODE { return (SCANCODE); }
Scc { return (SCANCODE); }
SCANSHIFT { return (SCANSHIFT); }
Scs { return (SCANSHIFT); }
SCREEN { return (SCREEN); }
Sc { return (SCREEN); }
SCROLL { return (SCROLL); }
Scl { return (SCROLL); }
SELECT { return (SELECT); }
Se { return (SELECT); }
SEMICOLON { return (SEMICOLON); }
SET { return (SET); }
St { return (SET); }
SGN { return (SGN); }
Sg { return (SGN); }
SHADES { return (SHADES); }
Sh { return (SHADES); }
SHARED { return (SHARED); }
Sr { return (SHARED); }
SHIFT { return (SHIFT); }
SHIFTS { return (SHIFTS); }
SHOW { return (SHOW); }
Sw { return (SHOW); }
SIGNED { return (SIGNED); }
Sgnd { return (SIGNED); }
SIZE { return (SIZE); }
Sz { return (SIZE); }
SLASH { return (SLASH); }
SPACE { return (SPACE); }
Spc { return (SPACE); }
SPAWN { return (SPAWN); }
Sp { return (SPAWN); }
SPRITE { return (SPRITE); }
Spr { return (SPRITE); }
SQR { return (SQR); }
STATE { return (STATE); }
Stt { return (STATE); }
STEP { return (STEP); }
Stp { return (STEP); }
STOP { return (STOP); }
STR { return (STR); }
STR\$ { return (STR); }
STRING { return (STRING); }
STRING\$ { return (STRING); }
T { return (T); }
TAB { return(TAB); }
Tb { return(TAB); }
TAN { return(TAN); }
Tn { return(TAN); }
TASK { return(TASK); }
Ts { return(TASK); }
TEMPORARY { return (TEMPORARY); }
Tmp { return (TEMPORARY); }
TEXT { return (TEXT); }
Tx { return (TEXT); }
TEXTMAP { return (TEXTMAP); }
Txm { return (TEXTMAP); }
TEXTADDRESS { return (TEXTADDRESS); }
Txa { return (TEXTADDRESS); }
THEN { return (THEN); }
Th { return (THEN); }
THREAD { return (THREAD); }
Thr { return (THREAD); }
TICKS { return (TICKS); }
Tk { return (TICKS); }
TILEMAP { return (TILEMAP); }
Tm { return (TILEMAP); }
TILE { return (TILE); }
Tl { return (TILE); }
TILES { return (TILES); }
Tls { return (TILES); }
TI { return (TI); }
TIMER { return (TIMER); }
Tmr { return (TIMER); }
TO { return (TO); }
TURQUOISE { return(TURQUOISE); }
Tu { return(TURQUOISE); }
TRANSPARENCY { return(TRANSPARENCY); }
Trs { return(TRANSPARENCY); }
TRUE { return(TRUE); }
Tr { return(TRUE); }
TYPE { return(TYPE); }
Ty { return(TYPE); }
U { return (U); }
UNTIL { return (UNTIL); }
Un { return (UNTIL); }
UP { return (UP); }
UPPER { return (UPPER); }
UPPER\$ { return (UPPER); }
Up { return (UPPER); }
USING { return (USING); }
Us { return (USING); }
V { return (V); }
VAL { return (VAL); }
Va { return (VAL); }
VAR { return (VAR); }
Vr { return (VAR); }
VBL { return (VBL); }
Vb { return (VBL); }
VIC20 { return (VIC20); }
V20 { return (VIC20); }
VARIABLES { return (VARIABLES); }
Vas { return (VARIABLES); }
VERTICAL { return (VERTICAL); }
Ve { return (VERTICAL); }
VIOLET { return(VIOLET); }
Vi { return(VIOLET); }
VISIBLE { return(VISIBLE); }
Vs { return(VISIBLE); }
VSCROLL { return (VSCROLL); }
Vscl { return (VSCROLL); }
W { return (W); }
WAIT { return (WAIT); }
Wt { return (WAIT); }
WEND { return (WEND); }
We { return (WEND); }
WITH { return (WITH); }
Wi { return (WITH); }
WIDTH { return (WIDTH); }
Wd { return (WIDTH); }
WHILE { return (WHILE); }
Wh { return (WHILE); }
WHITE { return(WHITE); }
Wht { return(WHITE); }
WRITING { return(WRITING); }
Wrt { return(WRITING); }
WORD { return (WORD); }
Wo { return (WORD); }
X { return (X); }
XGRAPHIC { return (XGRAPHIC); }
Xg { return (XGRAPHIC); }
XY { return (XY); }
XOR { return (XOR); }
Xr { return (XOR); }
XCURS { return (XCURS); }
Xcs { return (XCURS); }
XTEXT { return (XTEXT); }
Xt { return (XTEXT); }
XPEN { return (XPEN); }
Xp { return (XPEN); }
Y { return (Y); }
YGRAPHIC { return (YGRAPHIC); }
Yg { return (YGRAPHIC); }
YX { return (YX); }
YCURS { return (YCURS); }
Ycs { return (YCURS); }
YELLOW { return(YELLOW); }
Ye { return(YELLOW); }
YIELD { return(YIELD); }
Yi { return(YIELD); }
YTEXT { return (YTEXT); }
Yt { return (YTEXT); }
YPEN { return (YPEN); }
Yp { return (YPEN); }
Z { return (Z); }
ZX { return (ZX); }

"REM"[^\n\r]* { return(Remark);  }
"' "[^\n\r]* { return(Remark);  }

[A-Za-z][A-Za-z0-9\_]* { yylval.string = strdup(yytext); return(Identifier);  }
\"(\\.|[^"\\])*\" { yylval.string = strdup(yytext); memcpy(yylval.string,yylval.string+1,strlen(yylval.string)); yylval.string[strlen(yylval.string)-1]=0; return(String);  }
\$[a-fA-F0-9]+ { yylval.integer = strtol(yytext+1,0,16); return(Integer); }
&[Hh][a-fA-F0-9]+ { yylval.integer = strtol(yytext+2,0,16); return(Integer); }
0x[a-fA-F0-9]+ { yylval.integer = strtol(yytext+2,0,16); return(Integer); }
[a-fA-F0-9]+[hH] { int c = strlen(yytext); yytext[c-1] = 0; yylval.integer = strtol(yytext,0,16); return(Integer); }
%[0-1]+ { yylval.integer = strtol(yytext+1,0,2); return(Integer); }
\s[-][0-9]+ { yylval.integer = atoi(yytext); return(Integer);  }
[0-9]+ { yylval.integer = atoi(yytext); return(Integer);  }

[ \t]+ 
. { return(yytext[0]); }

%%
