%{

#include <stdio.h>
#include <string.h>
#include "ugbc.tab.h" /* The tokens */

#define RETURN(b, c)    \
{\
    yycolno = (yycolno + yyleng) * c; \
    yyposno = (yyposno + yyleng); \
    return b; \
}

char * strcopy( char * _dest, char * _source );

extern int yycolno;
extern int yyposno;

extern char * filenamestacked[256];
extern int yylinenostacked[];
extern int yycolnostacked[];
extern int yyposnostacked[];
extern int stacked;
extern char * asmSnippet;
extern char * importPath;

#if defined(__atari__) 
    char targetName[] = "atari";
#elif defined(__atarixl__) 
    char targetName[] = "atarixl";
#elif defined(__c64__)
    char targetName[] = "c64";
#elif defined(__plus4__)
    char targetName[] = "plus4";
#elif defined(__zx__)
    char targetName[] = "zx";
#elif defined(__coco__)
    char targetName[] = "coco";
#elif defined(__coco3__)
    char targetName[] = "coco3";
#elif defined(__d32__)
    char targetName[] = "d32";
#elif defined(__d64__)
    char targetName[] = "d64";
#elif defined(__gb__)
    char targetName[] = "gb";
#elif defined(__pc128op__)
    char targetName[] = "pc128op";
#elif defined(__to8__)
    char targetName[] = "to8";
#elif defined(__mo5__)
    char targetName[] = "mo5";
#elif defined(__vic20__)
    char targetName[] = "vic20";
#elif defined(__msx1__)
    char targetName[] = "msx1";
#elif defined(__coleco__)
    char targetName[] = "coleco";
#elif defined(__sc3000__)
    char targetName[] = "sc3000";
#elif defined(__sg1000__)
    char targetName[] = "sg1000";
#elif defined(__cpc__)
    char targetName[] = "cpc";
#elif defined(__c128__)
    char targetName[] = "c128";
#elif defined(__c128z__)
    char targetName[] = "c128z";
#elif defined(__vg5000__)
    char targetName[] = "vg5000";
#elif defined(__c64reu__)
    char targetName[] = "c64reu";
#elif defined(__pc1403__)
    char targetName[] = "pc1403";
#elif defined(__vz200__)
    char targetName[] = "vz200";
#endif

int yyconcatlineno;

static char * translate_spaces( char * _original ) {

    char * translated = strdup( _original );

    char * p = translated;

    while ( *p ) {
        if ( *p == ' ' ) {
            *p = '_';
        }
        ++p;
    }

    return translated;

}

char * strreplace( const char * _orig, const char * _rep, const char * _with);

%}

%x incl
%x impt
%x asm


%%

"IMPORT DECLARES"        BEGIN(impt);
<impt>[ \t\n\r]*     { /* eat the white spaces */
    char * importDeclaresFilename = malloc(1024);
    if ( importPath ) {
        sprintf(importDeclaresFilename, "%s/%s.bas", importPath, targetName);
    } else {
        sprintf(importDeclaresFilename, "../../imports/%s.bas", targetName);
        if( access( importDeclaresFilename, F_OK ) != 0 ) {
            sprintf(importDeclaresFilename, "../imports/%s.bas", targetName);
        }        
        if( access( importDeclaresFilename, F_OK ) != 0 ) {
            sprintf(importDeclaresFilename, "imports/%s.bas", targetName);
        }
        if( access( importDeclaresFilename, F_OK ) != 0 ) {
            if ( stacked == 0 ) {
                fprintf(stderr,  "*** ERROR: Missing import file %s at %d column %d (%d)\n", importDeclaresFilename, yylineno, (yycolno+1), (yyposno+1));
            } else {
                fprintf(stderr,  "*** ERROR: Missing import file %s at %d column %d (%d, %s)\n", importDeclaresFilename, yylineno, (yycolno+1), (yyposno+1), filenamestacked[stacked]);
            }
            exit(EXIT_FAILURE);
        }
    }
    yyin = fopen( importDeclaresFilename, "rt" );
    if ( ! yyin ) {
        if ( stacked == 0 ) {
            fprintf(stderr,  "*** ERROR: Missing import file %s at %d column %d (%d)\n", importDeclaresFilename, yylineno, (yycolno+1), (yyposno+1));
        } else {
            fprintf(stderr,  "*** ERROR: Missing import file %s at %d column %d (%d, %s)\n", importDeclaresFilename, yylineno, (yycolno+1), (yyposno+1), filenamestacked[stacked]);
        }
        exit(EXIT_FAILURE);
    }
    yylinenostacked[stacked] = yylineno;
    yycolnostacked[stacked] = yycolno;
    yyposnostacked[stacked] = yyposno;
    ++stacked;
    if ( stacked == 256 ) {
        if ( stacked == 0 ) {
            fprintf(stderr,  "*** ERROR: Maximum number of stacked include files reached (256) at %d column %d (%d)\n", yylineno, (yycolno+1), (yyposno+1));
        } else {
            fprintf(stderr,  "*** ERROR: Maximum number of stacked include files reached (256) at %d column %d (%d, %s)\n", yylineno, (yycolno+1), (yyposno+1), filenamestacked[stacked]);
        }
        exit(EXIT_FAILURE);
    }
    filenamestacked[stacked] = strdup( yytext );
    yylineno = 1;
    yyconcatlineno = 0;
    yycolno = 0;
    yyposno = 0;
    yypush_buffer_state(yy_create_buffer( yyin, YY_BUF_SIZE ));
    BEGIN(INITIAL);
}
INCLUDE             BEGIN(incl);
<incl>[ \t]*        /* eat the whitespace */
<incl>[^ \t\n\r]+     { /* got the include file name */
    char * filename = strreplace(yytext, "\"", "");
    yyin = fopen( filename, "rt" );
    if ( ! yyin ) {
        if ( stacked == 0 ) {
            fprintf(stderr,  "*** ERROR: Missing include file %s at %d column %d (%d)\n", yytext, yylineno, (yycolno+1), (yyposno+1));
        } else {
            fprintf(stderr,  "*** ERROR: Missing include file %s at %d column %d (%d, %s)\n", yytext, yylineno, (yycolno+1), (yyposno+1), filenamestacked[stacked]);
        }
        exit(EXIT_FAILURE);
    }

    unsigned char utf8check = fgetc( yyin );
    if ( utf8check == 0xef ) {
        fseek(yyin, 3, SEEK_SET );
    } else {
        fseek(yyin, 0, SEEK_SET );
    }

    yylinenostacked[stacked] = yylineno;
    yycolnostacked[stacked] = yycolno;
    yyposnostacked[stacked] = yyposno;
    ++stacked;
    if ( stacked == 256 ) {
        if ( stacked == 0 ) {
            fprintf(stderr,  "*** ERROR: Maximum number of stacked include files reached (256) at %d column %d (%d)\n",  yylineno, (yycolno+1), (yyposno+1));
        } else {
            fprintf(stderr,  "*** ERROR: Maximum number of stacked include files reached (256) at %d column %d (%d, %s)\n", yylineno, (yycolno+1), (yyposno+1), filenamestacked[stacked]);
        }
        exit(EXIT_FAILURE);
    }
    filenamestacked[stacked] = strdup( yytext );
    yylineno = 1;
    yyconcatlineno = 0;
    yycolno = 0;
    yyposno = 0;
    yypush_buffer_state(yy_create_buffer( yyin, YY_BUF_SIZE ));
    BEGIN(INITIAL);
}
<<EOF>> {
    yypop_buffer_state();
    if ( stacked ) {
        --stacked;
        yylineno = yylinenostacked[stacked];
        yycolno = yycolnostacked[stacked];
        yyposno = yyposnostacked[stacked];
        yyconcatlineno = 0;
    }
    if ( !YY_CURRENT_BUFFER ) {
        yyterminate();
    }
}

[\t ]*"ASM"[^\n\r\x0a\x0d]+ { ++yylineno; yycolno = 0; int p = strstr( yytext, "ASM" ) - yytext; yylval.string = strdup( yytext + p + 3 ); RETURN(AsmSnippet,1); }
[\t ]*"BEGIN ASM" { BEGIN(asm); asmSnippet = strdup(""); }
<asm>[\t ]*"END ASM" { yycolno = 0; BEGIN(INITIAL); yylval.string = strdup( asmSnippet ); RETURN(AsmSnippet,1); }
<asm>[\n\r\x0a\x0d]{1,3} { for(int k=0; k<strlen(yytext); ++k ) { if(yytext[k]==10) ++yylineno; }; yycolno = 0; int sz = strlen(asmSnippet) + strlen(yytext) + 3; char * tmp = malloc( sz ); memset( tmp, 0, sz ); strcopy( tmp, asmSnippet ); strcat( tmp, yytext ); asmSnippet = tmp; } 
<asm>.{1,3} { yycolno += strlen(yytext); int sz = strlen(asmSnippet) + strlen(yytext) + 3; char * tmp = malloc( sz ); memset( tmp, 0, sz ); strcopy( tmp, asmSnippet ); strcat( tmp, yytext ); asmSnippet = tmp; } 

"#["[a-fA-F0-9]+"]" { yylval.string = strdup(yytext+2); yylval.string[strlen(yylval.string)-1] = 0; RETURN(BufferDefinitionHex,1); }
"#["[a-fA-F0-9]+ { yylval.string = strdup(yytext+2); RETURN(BufferDefinitionHex,1); }

[\x0d] { }
_[\x0a]|_[\x0d][\x0a] { yycolno = 0; ++yylineno; ++yyconcatlineno; }
[\x0a] { ++yylineno; RETURN(NewLine,0); }
"." { RETURN(OP_PERIOD,1); }
";" { RETURN(OP_SEMICOLON,1); }
":" { RETURN(OP_COLON,1); }
"(" { RETURN(OP,1); }
")" { RETURN(CP,1); }
"," { RETURN(OP_COMMA,1); }
"=" { RETURN(OP_ASSIGN,1); }
"==" { RETURN(OP_EQUAL,1); }
":=" { RETURN(OP_ASSIGN_DIRECT,1); }
"+" { RETURN(OP_PLUS,1); }
"-" { RETURN(OP_MINUS,1); }
"++" { RETURN(INC,1); }
"--" { RETURN(DEC,1); }
"#" { RETURN(OP_HASH,1); }
"<" { RETURN(OP_LT,1); }
"<=" { RETURN(OP_LTE,1); }
">" { RETURN(OP_GT,1); }
">=" { RETURN(OP_GTE,1); }
"<>" { RETURN(OP_DISEQUAL,1); }
"*" { RETURN(OP_MULTIPLICATION,1); }
"**" { RETURN(OP_MULTIPLICATION2,1); }
"$" { RETURN(OP_DOLLAR,1); }
"^" { RETURN(OP_POW,1); }
"/" { RETURN(OP_DIVISION,1); }
"\\" { RETURN(OP_DIVISION2,1); }
"[" { RETURN(OSP,1); }
"]" { RETURN(CSP,1); }
"{" { RETURN(OGP,1); }
"}" { RETURN(CGP,1); }
"?" { RETURN(QM,1); }
"$$" { RETURN(OP_DOLLAR2,1); }
"!" { RETURN(OP_EXCLAMATION,1); }

"@" { RETURN(OP_AT,1); }
"%" { RETURN(OP_PERC,1); }
"&" { RETURN(OP_AMPERSAND,1); }
"%%" { RETURN(OP_PERC2,1); }

8BIT { RETURN(BYTE,1); }
16BIT { RETURN(WORD,1); }
32BIT { RETURN(DWORD,1); }

REM { RETURN(Remark,1);  }
"REM "[^\x0a\x0d]* { RETURN(Remark,1);  }
"'"[^\x0a\x0d]* { RETURN(Remark,1);  }

%{ /********************************* KEYWORDS *********************************/ %}

%{ /* --------------------------------- A --------------------------------- */ %}

A { RETURN(A,1); }
AAHS { RETURN(AAHS,1); }
Aa { RETURN(AAHS,1); }
ABS { RETURN(ABS,1); }
Ab { RETURN(ABS,1); }
ACCORDION { RETURN(ACCORDION,1); }
Ac { RETURN(ACCORDION,1); }
ACOUSTIC { RETURN(ACOUSTIC,1); }
Ao { RETURN(ACOUSTIC,1); }
AFTER { RETURN(AFTER,1); }
Af { RETURN(AFTER,1); }
AGE { RETURN(AGE,1); }
Ag { RETURN(AGE,1); }
AGOGO { RETURN(AGOGO,1); }
Ago { RETURN(AGOGO,1); }
ALPHA { RETURN(ALPHA,1); }
ALL { RETURN(ALL,1); }
All { RETURN(ALL,1); }
ALLOW { RETURN(ALLOW,1); }
Alw { RETURN(ALLOW,1); }
ALT { RETURN(ALT,1); }
Al { RETURN(ALT,1); }
ALTO { RETURN(ALTO,1); }
Alt { RETURN(ALTO,1); }
ANIMATE { RETURN(ANIMATE,1); }
Anm { RETURN(ANIMATE,1); }
ANIMATING { RETURN(ANIMATING,1); }
Ang { RETURN(ANIMATING,1); }
ANIMATION { RETURN(ANIMATION,1); }
Ani { RETURN(ANIMATION,1); }
APPLAUSE { RETURN(APPLAUSE,1); }
Ap { RETURN(APPLAUSE,1); }
ARRAY { RETURN(ARRAY,1); }
Ar { RETURN(ARRAY,1); }
AS { RETURN(AS,1); }
As { RETURN(AS,1); }
ASC { RETURN(ASC,1); }
Ax { RETURN(ASC,1); }
ASCII { RETURN(ASCII,1); }
Ascii { RETURN(ASCII,1); }
ASCIICODE { RETURN(ASCIICODE,1); }
Ascx { RETURN(ASCII,1); }
ASM { RETURN(ASM,1); }
Asm { RETURN(ASM,1); }
ATLAS { RETURN(ATLAS,1); }
Atl# { RETURN(ATLAS,1); }
ATMOSPHERE { RETURN(ATMOSPHERE,1); }
Atm { RETURN(ATMOSPHERE,1); }
ASTERISK { RETURN(ASTERISK,1); }
Ak { RETURN(ASTERISK,1); }
AT { RETURN(AT,1); }
At { RETURN(AT,1); }
ATARI { RETURN(ATARI,1); }
Ata { RETURN(ATARI,1); }
ATARIXL { RETURN(ATARIXL,1); }
Axl { RETURN(ATARIXL,1); }
ADD { RETURN(ADD,1); }
Ad { RETURN(ADD,1); }
ADDC { RETURN(ADDC,1); }
A\$ { RETURN(ADDC,1); }
ADDRESS { RETURN(ADDRESS,1); }
A# { RETURN(ADDRESS,1); }
AND { RETURN(AND,1); }
An { RETURN(AND,1);  }
ARROW { RETURN(ARROW,1); }
Aw { RETURN(ARROW,1); }
ASYNC { RETURN(ASYNC,1); }
Asy { RETURN(ASYNC,1); }
AUDIO { RETURN(AUDIO,1); }
Aud { RETURN(AUDIO,1); }
AUTO { RETURN(AUTO,1); }
Au { RETURN(AUTO,1); }
AVAILABLE { RETURN(AVAILABLE,1); }
Av { RETURN(AVAILABLE,1); }
AY8910 { RETURN(AY8910,1); }
Ay { RETURN(AY8910,1); }

%{ /* --------------------------------- B --------------------------------- */ %}

B { RETURN(B,1); }
BACK { RETURN(BACK,1); }
Ba { RETURN(BACK,1); }
BACKGROUND { RETURN(BACKGROUND,1); }
Bg { RETURN(BACKGROUND,1); }
BAG { RETURN(BAG,1); }
BANJO { RETURN(BANJO,1); }
Ban { RETURN(BANJO,1); }
BANK { RETURN(BANK,1); }
Bk { RETURN(BANK,1); }
BANKED { RETURN(BANKED,1); }
B! { RETURN(BANKED,1); }
BAR { RETURN(BAR,1); }
Br { RETURN(BAR,1); }
BARITONE { RETURN(BARITONE,1); }
Bar { RETURN(BARITONE,1); }
BASS { RETURN(BASS,1); }
Bas { RETURN(BASS,1); }
BASIC { RETURN(BASIC,1); }
BAs { RETURN(BASIC,1); }
BASSOON { RETURN(BASSOON,1); }
Bss { RETURN(BASSOON,1); }
BEGIN { RETURN(BEG,1); }
Be { RETURN(BEG,1); }
BF { RETURN(BF,1); }
BECKER { RETURN(BECKER,1); }
BEc { RETURN(BECKER,1); }
BELL { RETURN(BELL,1); }
Bel { RETURN(BELL,1); }
BELLS { RETURN(BELLS,1); }
BELONG { RETURN(BELONG,1); }
BETA { RETURN(BETA,1); }
Bet { RETURN(BETA,1); }
Bn { RETURN(BELONG,1); }
BIG { RETURN(BIG,1); }
Big { RETURN(BIG,1); }
BIN { RETURN(BIN,1); }
BIN\$ { RETURN(BIN,1); }
Bi { RETURN(BIN,1); }
BINARY { RETURN(BINARY,1); }
Bin { RETURN(BINARY,1); }
BIT { RETURN(BIT,1); }
Bt { RETURN(BIT,1); }
BIRD { RETURN(BIRD,1); }
BITMAP { RETURN(BITMAP,1); }
Bm { RETURN(BITMAP,1); }
BITMAPS { RETURN(BITMAPS,1); }
Bms { RETURN(BITMAPS,1); }
BLACK { RETURN(BLACK,1); }
Bl { RETURN(BLACK,1); }
BLIT { RETURN(BLIT,1); }
Blt { RETURN(BLIT,1); }
BLOCK { RETURN(BLOCK,1); }
Blk { RETURN(BLOCK,1); }
BLOWN { RETURN(BLOWN,1); }
BLUE { RETURN(BLUE,1); }
Bu { RETURN(BLUE,1); }
BOTTLE { RETURN(BOTTLE,1); }
BOTTOM { RETURN(BOTTOM,1); }
Bot { RETURN(BOTTOM,1); }
BOWED { RETURN(BOWED,1); }
BOX { RETURN(BOX,1); }
Bx { RETURN(BOX,1); }
BRASS { RETURN(BRASS,1); }
BREATH { RETURN(BREATH,1); }
BRIGHT { RETURN(BRIGHT,1); }
BRIGHTNESS { RETURN(BRIGHTNESS,1); }
BROWN { RETURN(BROWN,1); }
Brn { RETURN(BROWN,1); }
BY { RETURN(BY,1); }
BYTE { RETURN(BYTE,1); }
By { RETURN(BYTE,1); }
BYTES { RETURN(BYTES,1); }
Bys { RETURN(BYTES,1); }
BOOM { RETURN(BOOM,1); }
Boo { RETURN(BOOM,1); }
BOOLEAN { RETURN(BOOLEAN,1); }
BOl { RETURN(BOOLEAN,1); }
BORDER { RETURN(BORDER,1); }
Bo { RETURN(BORDER,1); }
BOUNCE { RETURN(BOUNCE,1); }
Bou { RETURN(BOUNCE,1); }
BUFFER { RETURN(BUFFER,1); }
BUT { RETURN(BUT,1); }
But { RETURN(BUT,1); }
Bf { RETURN(BUFFER,1); }

%{ /* --------------------------------- C --------------------------------- */ %}

C { RETURN(C,1); }
C128 { RETURN(C128,1); }
C128Z { RETURN(C128Z,1); }
C64 { RETURN(C64,1); }
C64REU { RETURN(C64REU,1); }
CALL { RETURN(CALL,1); }
Ca { RETURN(CALL,1); }
CALLIOPE { RETURN(CALLIOPE,1); }
CAN { RETURN(CAN,1); }
Cn { RETURN(CAN,1); }
CAPS { RETURN(CAPS,1); }
Cp { RETURN(CAPS,1); }
CAPSLOCK { RETURN(CAPSLOCK,1); }
Cpl { RETURN(CAPS,1); }
CASE { RETURN(CASE,1); }
Cs { RETURN(CASE,1); }
CDOWN { RETURN(CDOWN,1); }
Cd { RETURN(CDOWN,1); }
CELESTA { RETURN(CELESTA,1); }
CELLO { RETURN(CELLO,1); }
CENTER { RETURN(CENTER,1); }
Ce { RETURN(CENTER,1); }
CENTRE { RETURN(CENTRE,1); }
CGOTO { RETURN(CGOTO,1); }
Cg { RETURN(CGOTO,1); }
CHANNEL { RETURN(CHANNEL,1); }
CHn { RETURN(CHANNEL,1); }
CHAR { RETURN(CHAR,1); }
CHARANG { RETURN(CHARANG,1); }
CHECK { RETURN(CHECK,1); }
Chk { RETURN(CHECK,1); }
CHIFF { RETURN(CHIFF,1); }
CHR { RETURN(CHR,1); }
CHR\$ { RETURN(CHR,1); }
Ch { RETURN(CHR,1); }
CHOIR { RETURN(CHOIR,1); }
CHURCH { RETURN(CHURCH,1); }
CIRCLE { RETURN(CIRCLE,1); }
Ci { RETURN(CIRCLE,1); }
CLAMP { RETURN(CLAMP,1); }
Cla { RETURN(CLAMP,1); }
CLARINET { RETURN(CLARINET,1); }
CLASS { RETURN(CLASS,1); }
Css { RETURN(CLASS,1); }
CLAVI { RETURN(CLAVI,1); }
CLEAN { RETURN(CLEAN,1); }
CLEAR { RETURN(CLEAR,1); }
Clr { RETURN(CLEAR,1); }
CLEFT { RETURN(CLEFT,1); }
Cle { RETURN(CLEFT,1); }
CLINE { RETURN(CLINE,1); }
Cln { RETURN(CLINE,1); }
CLIP { RETURN(CLIP,1); }
Cli { RETURN(CLIP,1); }
CLOSE { RETURN(CLOSE,1); }
Clo { RETURN(CLOSE,1); }
CLR { RETURN(CLR,1); }
CLS { RETURN(CLS,1); }
Cl { RETURN(CLS,1); }
CMOB { RETURN(CMOB,1); }
Cmo { RETURN(CMOB,1); }
CMOVE { RETURN(CMOVE,1); }
Cm { RETURN(CMOVE,1); }
COARSE { RETURN(COARSE,1); }
COCO { RETURN(COCO,1); }
Cc { RETURN(COCO,1); }
COCO1 { RETURN(COCO1,1); }
Cc1 { RETURN(COCO1,1); }
COCO2 { RETURN(COCO2,1); }
Cc2 { RETURN(COCO2,1); }
COCO3 { RETURN(COCO3,1); }
Cc3 { RETURN(COCO3,1); }
CODE { RETURN(CODE,1); }
Co { RETURN(CODE,1); }
COLLISION { RETURN(COLLISION,1); }
Col { RETURN(COLLISION,1); }
COLECO { RETURN(COLECO,1); }
COLON { RETURN(COLON,1); }
COLOR { RETURN(COLOR,1); }
Cr { RETURN(COLOR,1); }
COLOUR { RETURN(COLOUR,1); }
COLORS { RETURN(COLORS,1); }
COLOURS { RETURN(COLOURS,1); }
Crs { RETURN(COLORS,1); }
COLORMAP { RETURN(COLORMAP,1); }
COLOURMAP { RETURN(COLOURMAP,1); }
Com { RETURN(COLOURMAP,1); }
COLUMN { RETURN(COLUMN,1); }
Clm { RETURN(COLUMN,1); }
COLUMNS { RETURN(COLUMNS,1); }
Cms { RETURN(COLUMNS,1); }
COMBINE { RETURN(COMBINE,1); }
Cmb { RETURN(COMBINE,1); }
COMMA { RETURN(COMMA,1); }
COMMODORE { RETURN(COMMODORE,1); }
COMPLETE { RETURN(COMPLETE,1); }
CONNECTED { RETURN(CONNECTED,1); }
Con { RETURN(CONNECTED,1); }
COS { RETURN(COS,1); }
Cx { RETURN(COS,1); }
Cmp { RETURN(COMPLETE,1); }
C= { RETURN(COMMODORE,1); }
COMPRESS { RETURN(COMPRESS,1); }
Cpr { RETURN(COMPRESS,1); }
COMPRESSED { RETURN(COMPRESSED,1); }
COMPRESSION { RETURN(COMPRESSION,1); }
Cprs { RETURN(COMPRESSION,1); }
CONFIGURE { RETURN(CONFIGURE,1); }
Cfg { RETURN(CONFIGURE,1); }
CONTRABASS { RETURN(CONTRABASS,1); }
CONSOLE { RETURN(CONSOLE,1); }
Cns { RETURN(CONSOLE,1); }
CONST { RETURN(CONST,1); }
C# { RETURN(CONST,1); }
CONTROL { RETURN(CONTROL,1); }
Ctrl { RETURN(CONTROL,1); }
COPY { RETURN(COPY,1); }
Cpy { RETURN(COPY,1); }
COUNT { RETURN(COUNT,1); }
C% { RETURN(COUNT,1); }
CPC { RETURN(CPC,1); }
CPU6502 { RETURN(CPU6502,1); }
CPU6809 { RETURN(CPU6809,1); }
CPUSC61860 { RETURN(CPUSC61860,1); }
CPUSM83 { RETURN(CPUSM83,1); }
CPUZ80 { RETURN(CPUZ80,1); }
CREATE { RETURN(CREATE,1); }
Crt { RETURN(CREATE,1); }
CRIGHT { RETURN(CRIGHT,1); }
Crg { RETURN(CRIGHT,1); }
CRSR { RETURN(CRSR,1); }
CRYSTAL { RETURN(CRYSTAL,1); }
CSET { RETURN(CSET,1); }
Cxx { RETURN(CSET,1); }
CSPRITE { RETURN(CSPRITE,1); }
Csp { RETURN(CSPRITE,1); }
CSV { RETURN(CSV,1); }
CUP { RETURN(CUP,1); }
Cu { RETURN(CUP,1); }
CURSOR { RETURN(CURSOR,1); }
Curs { RETURN(CURSOR,1); }
CURS { RETURN(CURS,1); }
CYAN { RETURN(CYAN,1); }
Cy { RETURN(CURSOR,1); }
CYCLES { RETURN(CYCLES,1); }
Cyc { RETURN(CYCLES,1); }
CYMBAL { RETURN(CYMBAL,1); }

%{ /* --------------------------------- D --------------------------------- */ %}

D!PEEK { RETURN(PEEKW,1); }
D!p { RETURN(PEEKW,1); }
D!POKE { RETURN(POKEW,1); }
D!k { RETURN(POKEW,1); }
D { RETURN(D,1); }
DAC1 { RETURN(DAC1,1); }
D1 { RETURN(DAC1,1); }
DARK { RETURN(DARK,1); }
Dk { RETURN(DARK,1); }
DATA { RETURN(DATA,1); }
Da { RETURN(DATA,1); }
DEC { RETURN(DEC,1); }
Dc { RETURN(DEC,1); }
DECLARE { RETURN(DECLARE,1); }
Dec { RETURN(DECLARE,1); }
DEFAULT { RETURN(DEFAULT,1); }
Dft { RETURN(DEFAULT,1); }
DEFDGR { RETURN(DEFDGR,1); }
Dfg { RETURN(DEFDGR,1); }
DEFINE { RETURN(DEFINE,1); }
De { RETURN(DEFINE,1); }
DEGREE { RETURN(DEGREE,1); }
Deg { RETURN(DEGREE,1); }
DELAY { RETURN(DELAY,1); }
Dy { RETURN(DELAY,1); }
DELETE { RETURN(DELETE,1); }
Del { RETURN(DELETE,1); }
DESTINATION { RETURN(DESTINATION,1); }
Ds { RETURN(DESTINATION,1); }
DESTROY { RETURN(DESTROY,1); }
Des { RETURN(DESTROY,1); }
DETECTION { RETURN(DETECTION,1); }
Det { RETURN(DETECTION,1); }
DIM { RETURN(DIM,1); }
DEVICE { RETURN(DEVICE,1); }
DEv { RETURN(DEVICE,1); }
DIALECT { RETURN(DIALECT,1); }
Dial { RETURN(DIALECT,1); }
Di { RETURN(DIM,1); }
DIRECTION { RETURN(DIRECTION,1); }
Dir# { RETURN(DIRECTION,1); }
DISABLE { RETURN(DISABLE,1); }
Dx { RETURN(DISABLE,1); }
DISTANCE { RETURN(DISTANCE,1); }
DISTORTION { RETURN(DISTORTION,1); }
DLOAD { RETURN(DLOAD,1); }
Dl { RETURN(DLOAD,1); }
DOJO { RETURN(DOJO,1); }
Dj { RETURN(DOJO,1); }
DOJOKA { RETURN(DOJOKA,1); }
Djk { RETURN(DOJOKA,1); }
DRAWBAR { RETURN(DRAWBAR,1); }
DRUM { RETURN(DRUM,1); }
DRUMS { RETURN(DRUMS,1); }
Dst { RETURN(DISTANCE,1); }
DIV { RETURN(DIV,1); }
Dv { RETURN(DIV,1); }
DO { RETURN(DO,1); }
Do { RETURN(DO,1); }
DOUBLE { RETURN(DOUBLE,1); }
Db { RETURN(DOUBLE,1); }
DOWN { RETURN(DOWN,1); }
Dw { RETURN(DOWN,1); }
DOWNB { RETURN(DOWNB,1); }
DWb { RETURN(DOWNB,1); }
DOWNW { RETURN(DOWNW,1); }
DWw { RETURN(DOWNW,1); }
DRAW { RETURN(DRAW,1); }
Dr { RETURN(DRAW,1); }
DRAGON { RETURN(DRAGON,1); }
Dg { RETURN(DRAGON,1); }
DRAGON32 { RETURN(DRAGON32,1); }
Dg32 { RETURN(DRAGON32,1); }
DRAGON64 { RETURN(DRAGON64,1); }
Dg64 { RETURN(DRAGON64,1); }
DSAVE { RETURN(DSAVE,1); }
Dsa { RETURN(DSAVE,1); }
DTILE { RETURN(DTILE,1); }
Dt { RETURN(DTILE,1); }
DTILES { RETURN(DTILES,1); }
Dts { RETURN(DTILES,1); }
DULCIMER { RETURN(DULCIMER,1); }
DUP { RETURN(DUP,1); }
Du { RETURN(DUP,1); }
DWORD { RETURN(DWORD,1); }
Dwd { RETURN(DWORD,1); }
DYNAMIC { RETURN(DYNAMIC,1); }
Dyn { RETURN(DYNAMIC,1); }

%{ /* --------------------------------- E --------------------------------- */ %}

E { RETURN(E,1); }
EASEIN { RETURN(EASEIN,1); }
Eai { RETURN(EASEIN,1); }
EASEOUT { RETURN(EASEOUT,1); }
Eao { RETURN(EASEOUT,1); }
ECHOES { RETURN(ECHOES,1); }
ELECTRIC { RETURN(ELECTRIC,1); }
ELLIPSE { RETURN(ELLIPSE,1); }
Ell { RETURN(ELLIPSE,1); }
ELSE { RETURN(ELSE,1); }
El { RETURN(ELSE,1); }
ELSEIF { RETURN(ELSEIF,1); }
Eif { RETURN(ELSEIF,1); }
EMBEDDED { RETURN(EMBEDDED,1); }
Emb { RETURN(EMBEDDED,1); }
EMPTY { RETURN(EMPTY,1); }
Em { RETURN(EMPTY,1); }
EMPTYTILE { RETURN(EMPTYTILE,1); }
Emt { RETURN(EMPTYTILE,1); }
EMULATION { RETURN(EMULATION,1); }
EMu { RETURN(EMULATION,1); } 
END { RETURN(END,1); }
Ee { RETURN(END,1); }
ENDIF { RETURN(ENDIF,1); }
ENGLISH { RETURN(ENGLISH,1); }
ENSEMBLE { RETURN(ENSEMBLE,1); }
Ei { RETURN(ENDIF,1); }
ENDIAN { RETURN(ENDIAN,1); } 
End { RETURN(ENDIAN,1); } 
ENDPROC { RETURN(ENDPROC,1); } 
E\$ { RETURN(ENDPROC,1); } 
ENDSELECT { RETURN(ENDSELECT,1); }
Es { RETURN(ENDSELECT,1); }
ENDSTORAGE { RETURN(ENDSTORAGE,1); }
Ens { RETURN(ENDSTORAGE,1); }
ENDTYPE { RETURN(ENDTYPE,1); }
Et { RETURN(ENDTYPE,1); }
ENABLE { RETURN(ENABLE,1); }
En { RETURN(ENABLE,1); }
ENVELOPE { RETURN(ENVELOPE,1); }
Env { RETURN(ENVELOPE,1); }
EQUAL { RETURN(EQUAL,1); }
Eq { RETURN(EQUAL,1); }
ERROR { RETURN(ERROR,1); }
Er { RETURN(ERROR,1); }
EXACT { RETURN(EXACT,1); }
E! { RETURN(EXACT,1); }
EXEC { RETURN(EXEC,1); }
E# { RETURN(EXEC,1); }
EXIT { RETURN(EXIT,1); }
Ex { RETURN(EXIT,1); }
EXITIF { RETURN(EXITIF,1); }
X\$ { RETURN(EXITIF,1); }
EXP { RETURN(EXP,1); }
EXPAND { RETURN(EXPAND,1); }
Exp { RETURN(EXPAND,1); }
EXPLICIT { RETURN(EXPLICIT,1); }
Ex1 { RETURN(EXPLICIT,1); }
EXPLOSION { RETURN(EXPLOSION,1); }
Exx { RETURN(EXPLOSION,1); }
EVERY { RETURN(EVERY,1); }
Ev { RETURN(EVERY,1); }

%{ /* --------------------------------- F --------------------------------- */ %}

FADE { RETURN(FADE,1); }
FAd { RETURN(FADE,1); }
FALSE { RETURN(FALSE,1); }
Fa { RETURN(FALSE,1); }
FAST { RETURN(FAST,1); } 
Fst { RETURN(FAST,1); } 
F { RETURN(F,1); }
F1 { RETURN(F1,1); }
F2 { RETURN(F2,1); }
F3 { RETURN(F3,1); }
F4 { RETURN(F4,1); }
F5 { RETURN(F5,1); }
F6 { RETURN(F6,1); }
F7 { RETURN(F7,1); }
F8 { RETURN(F8,1); }
FILE { RETURN(FILEX,1); }
FILL { RETURN(FILL,1); }
Fil { RETURN(FILL,1); }
FIRE { RETURN(FIRE,1); }
Fi { RETURN(FIRE,1); }
FI { RETURN(FI,1); }
FIDDLE { RETURN(FIDDLE,1); }
FIFTHS { RETURN(FIFTHS,1); }
FILESIZE { RETURN(FILESIZE,1); }
FSIZE { RETURN(FSIZE,1); }
Fs { RETURN(FILESIZE,1); }
FIND { RETURN(FIND,1); }
Fn { RETURN(FIND,1); }
FHEIGHT { RETURN(FHEIGHT,1); }
Fh { RETURN(FHEIGHT,1); }
FINAL { RETURN(FINAL,1); }
FIn { RETURN(FINAL,1); }
FINGER { RETURN(FINGER,1); }
FIRST { RETURN(FIRST,1); }
FST { RETURN(FIRST,1); }
FLIP { RETURN(FLIP,1); }
FLIP\$ { RETURN(FLIP,1); }
Fl { RETURN(FLIP,1); }
FLOAT { RETURN(FLOAT,1); }
Ft { RETURN(FLOAT,1); }
FLUTE { RETURN(FLUTE,1); }
FONT { RETURN(FONT,1); }
Fnt { RETURN(FONT,1); }
FOR { RETURN(FOR,1); }
Fo { RETURN(FOR,1); }
FORBID { RETURN(FORBID,1); }
Fd { RETURN(FORBID,1); }
FRAME { RETURN(FRAME,1); }
Fr { RETURN(FRAME,1); }
FRAMES { RETURN(FRAMES,1); }
Frs { RETURN(FRAMES,1); }
FREE { RETURN(FREE,1); }
Fre { RETURN(FREE,1); }
FREEZE { RETURN(FREEZE,1); }
Frz { RETURN(FREEZE,1); }
FRENCH { RETURN(FRENCH,1); }
FRET { RETURN(FRET,1); }
FRETLESS { RETURN(FRETLESS,1); }
FROM { RETURN(FROM,1); }
Fm { RETURN(FROM,1); }
FUJINET { RETURN(FUJINET,1); }
Fj { RETURN(FUJINET,1); }
FUNCTION { RETURN(FUNCTION,1); }
Fu { RETURN(FUNCTION,1); }
FWIDTH { RETURN(FWIDTH,1); }
Fw { RETURN(FWIDTH,1); }
FX { RETURN(FX,1); }

%{ /* --------------------------------- G --------------------------------- */ %}

G { RETURN(G,1); }
GAMELOOP { RETURN(GAMELOOP,1); }
GB { RETURN(GB,1); }
Gl { RETURN(GAMELOOP,1); }
GET { RETURN(GET,1); }
Ge { RETURN(GET,1); }
GLOBAL { RETURN(GLOBAL,1); }
Gb { RETURN(GLOBAL,1); }
GLOCKENSPIEL { RETURN(GLOCKENSPIEL,1); }
GMC { RETURN(GMC,1); }
GOBLINS { RETURN(GOBLINS,1); }
GOLD { RETURN(GOLD,1); }
Gd { RETURN(GOLD,1); }
GOTO { RETURN(GOTO,1); }
Go { RETURN(GOTO,1); }
GOSUB { RETURN(GOSUB,1); }
Gs { RETURN(GOSUB,1); }
GR { RETURN(GR,1); }
GRAND { RETURN(GRAND,1); }
GRAPHIC { RETURN(GRAPHIC,1); }
Gr { RETURN(GRAPHIC,1); }
GRAPHICS { RETURN(GRAPHICS,1); }
Grs { RETURN(GRAPHIC,1); }
GRAY { RETURN(GRAY,1); }
Gy { RETURN(GRAY,1); }
GREEN { RETURN(GREEN,1); }
Gre { RETURN(GREEN,1); }
GREY { RETURN(GREY,1); }
GUITAR { RETURN(GUITAR,1); }
GUNSHOT { RETURN(GUNSHOT,1); }

%{ /* --------------------------------- H --------------------------------- */ %}

H { RETURN(H,1); }
HALO { RETURN(HALO,1); }
HALT { RETURN(HALT,1); }
Ht { RETURN(HALT,1); }
HALTED { RETURN(HALTED,1); }
Htd { RETURN(HALTED,1); }
HARMONICA { RETURN(HARMONICA,1); }
HARMONICS { RETURN(HARMONICS,1); }
HARP { RETURN(HARP,1); }
HARPSICHORD { RETURN(HARPSICHORD,1); }
HAS { RETURN(HAS,1); }
HEIGHT { RETURN(HEIGHT,1); }
HDBDOS { RETURN(HDBDOS,1); }
HDb { RETURN(HDBDOS,1); }
Hg { RETURN(HEIGHT,1); }
HELICOPTER { RETURN(HELICOPTER,1); }
HEX { RETURN(HEX,1); }
HEX\$ { RETURN(HEX,1); }
Hx { RETURN(HEX,1); }
HIRES { RETURN(HIRES,1); }
Hi { RETURN(HIRES,1); }
HIT { RETURN(HIT,1); }
HOME { RETURN(HOME,1); }
Hm { RETURN(HOME,1); }
HONKY { RETURN(HONKY,1); }
HORIZONTAL { RETURN(HORIZONTAL,1); }
Hz { RETURN(HORIZONTAL,1); }
HORN { RETURN(HORN,1); }
HSCROLL { RETURN(HSCROLL,1); }
Hs { RETURN(HSCROLL,1); }
HTTP { RETURN(HTTP,1); }

%{ /* --------------------------------- I --------------------------------- */ %}

I { RETURN(I,1); }
IAF { RETURN(IAF,1); }
Ia { RETURN(IAF,1); }
ID { RETURN(ID,1); }
Id { RETURN(ID,1); }
IF { RETURN(IF,1); }
If { RETURN(IF,1); }
IGNORE { RETURN(IGNORE,1); }
Ig { RETURN(IGNORE,1); }
IMAGE { RETURN(IMAGE,1); }
Im { RETURN(IMAGE,1); }
IMAGEREF { RETURN(IMAGEREF,1); }
IMr { RETURN(IMAGEREF,1); }
IMAGES { RETURN(IMAGES,1); }
Ims { RETURN(IMAGES,1); }
IMPLICIT { RETURN(IMPLICIT,1); }
Imp { RETURN(IMPLICIT,1); }
IN { RETURN(IN,1); }
In { RETURN(IN,1); }
INC { RETURN(INC,1); }
INCREMENTAL { RETURN(INCREMENTAL,1); }
INc { RETURN(INCREMENTAL,1); }
INK { RETURN(INK,1); }
Ik { RETURN(INK,1); }
INKB { RETURN(INKB,1); }
I\$ { RETURN(INKB,1); }
INKEY { RETURN(INKEY,1); }
INDEX { RETURN(INDEX,1); }
Idx { RETURN(INDEX,1); }
INKEY\$ { RETURN(INKEY,1); }
Iky { RETURN(INKEY,1); }
INPUT { RETURN(INPUT,1); }
Ip { RETURN(INPUT,1); }
INSERT { RETURN(INSERT,1); }
Ins { RETURN(INSERT,1); }
INST { RETURN(INST,1); }
Inx { RETURN(INST,1); }
INSTRUMENT { RETURN(INSTRUMENT,1); }
Inst { RETURN(INSTRUMENT,1); }
INVERSE { RETURN(INVERSE,1); }
Inv { RETURN(INVERSE,1); }
INSTR { RETURN(INSTR,1); }
INT { RETURN(INT,1); }
INTEGER { RETURN(INT,1); }
Int { RETURN(INT,1); }
INTERRUPT { RETURN(INTERRUPT,1); }
Intr { RETURN(INTERRUPT,1); }
Ist { RETURN(INSTR,1); }
IS { RETURN(IS,1); }

%{ /* --------------------------------- J --------------------------------- */ %}

J { RETURN(J,1); }
JAZZ { RETURN(JAZZ,1); }
JDOWN { RETURN(JDOWN,1); }
Jd { RETURN(JDOWN,1); }
JFIRE { RETURN(JFIRE,1); }
Jf { RETURN(JFIRE,1); }
JLEFT { RETURN(JLEFT,1); }
Jl { RETURN(JLEFT,1); }
JMOVE { RETURN(JMOVE,1); }
Jm { RETURN(JMOVE,1); }
JRIGHT { RETURN(JRIGHT,1); }
Jr { RETURN(JRIGHT,1); }
JSON { RETURN(JSON,1); }
Js { RETURN(JSON,1); }
JUP { RETURN(JUP,1); }
Ju { RETURN(JUP,1); }
JOY { RETURN(JOY,1); }
Jy { RETURN(JOY,1); }
JOYX { RETURN(JOYX,1); }
Jyx { RETURN(JOYX,1); }
JOYY { RETURN(JOYY,1); }
Jyy { RETURN(JOYY,1); }
JOYSTICK { RETURN(JOYSTICK,1); }
Jyt { RETURN(JOYSTICK,1); }
JOYCOUNT { RETURN(JOYCOUNT,1); }
Jyc { RETURN(JOYCOUNT,1); }
JOYDIR { RETURN(JOYDIR,1); }
Jdy { RETURN(JOYDIR,1); }

%{ /* --------------------------------- K --------------------------------- */ %}

K { RETURN(K,1); }
KALIMBA { RETURN(KALIMBA,1); }
KEY { RETURN(KEY,1); }
Ky { RETURN(KEY,1); }
KEYGET { RETURN(KEYGET,1); }
Kyg { RETURN(KEYGET,1); }
KEYBOARD { RETURN(KEYBOARD,1); }
Kyb { RETURN(KEYBOARD,1); }
KEYSHIFT { RETURN(KEYSHIFT,1); }
Ks { RETURN(KEYSHIFT,1); }
KEYSTATE { RETURN(KEYSTATE,1); }
Kt { RETURN(KEYSTATE,1); }
KILL { RETURN(KILL,1); }
Ki { RETURN(KILL,1); }
KOTO { RETURN(KOTO,1); }

%{ /* --------------------------------- L --------------------------------- */ %}

L { RETURN(L,1); }
LATENCY { RETURN(LATENCY,1); }
Lay { RETURN(LATENCY,1); }
LAVENDER { RETURN(LAVENDER,1); }
La { RETURN(LAVENDER,1); }
LAYER { RETURN(LAYER,1); }
Ly { RETURN(LAYER,1); }
LBOTTOM { RETURN(LBOTTOM,1); }
L\$ { RETURN(LBOTTOM,1); }
LBOUND { RETURN(LBOUND,1); }
Lb { RETURN(LBOUND,1); }
LCASE { RETURN(LCASE,1); }
Lca { RETURN(LCASE,1); }
LEAD { RETURN(LEAD,1); }
LEFT { RETURN(LEFT,1); }
Lf { RETURN(LEFT,1); }
LEFT\$ { RETURN(LEFT,1); }
LEFTB { RETURN(LEFTB,1); }
LFb { RETURN(LEFTB,1); }
LEFTW { RETURN(LEFTW,1); }
LFw { RETURN(LEFTW,1); }
LEN { RETURN(LEN,1); }
LET { RETURN(LET,1); }
Le { RETURN(LET,1); }
LIGHT { RETURN(LIGHT,1); }
Li { RETURN(LIGHT,1); }
LINE { RETURN(LINE,1); }
LITTLE { RETURN(LITTLE,1); }
Lit { RETURN(LITTLE,1); }
Ln { RETURN(LINE,1); }
LOAD { RETURN(LOAD,1); }
Ld { RETURN(LOAD,1); }
LOCATE { RETURN(LOCATE,1); }
Lc { RETURN(LOCATE,1); }
LOCK { RETURN(LOCK,1); }
Lk { RETURN(LOCK,1); }
LOG { RETURN(LOG,1); }
Lg { RETURN(LOG,1); }
LOGIN { RETURN(LOGIN,1); }
Lgn { RETURN(LOGIN,1); }
LONG { RETURN(LONG,1); }
Lo { RETURN(LONG,1); }
LOOP { RETURN(LOOP,1); }
Lp { RETURN(LOOP,1); }
LOWER { RETURN(LOWER,1); }
Lw { RETURN(LOWER,1); }
LOWER\$ { RETURN(LOWER,1); }

%{ /* --------------------------------- M --------------------------------- */ %}

M { RETURN(M,1); }
MAGENTA { RETURN(MAGENTA,1); }
Mg { RETURN(MAGENTA,1); }
MARIMBA { RETURN(MARIMBA,1); }
MASKED { RETURN(MASKED,1); }
Mk { RETURN(MASKED,1); }
MAX { RETURN(MAX,1); }
Mx { RETURN(MAX,1); }
MELODIC { RETURN(MELODIC,1); }
MEMCONT { RETURN(MEMCONT,1); }
MEc { RETURN(MEMCONT,1); }
MEMCLR { RETURN(MEMCLR,1); }
MEl { RETURN(MEMCLR,1); }
MEMDEF { RETURN(MEMDEF,1); }
Md { RETURN(MEMDEF,1); }
MEMLEN { RETURN(MEMLEN,1); }
MLn { RETURN(MEMLEN,1); }
MEMORY { RETURN(MEMORY,1); }
Mm { RETURN(MEMORY,1); }
MEMPEEK { RETURN(MEMPEEK,1); }
Mp { RETURN(MEMPEEK,1); }
MEMLOAD { RETURN(MEMLOAD,1); }
Ml { RETURN(MEMLOAD,1); }
MEMOR { RETURN(MEMOR,1); }
Mo { RETURN(MEMOR,1); }
MEMPOS { RETURN(MEMPOS,1); }
Mep { RETURN(MEMPOS,1); }
MEMSAVE { RETURN(MEMSAVE,1); }
Ms { RETURN(MEMSAVE,1); }
MMo { RETURN(MMOB,1); }
METALLIC { RETURN(METALLIC,1); }
MEMORIZE { RETURN(MEMORIZE,1); }
Me { RETURN(MEMORIZE,1); }
MEMRESTORE { RETURN(MEMRESTORE,1); }
MEr { RETURN(MEMRESTORE,1); }
MESSAGE { RETURN(MESSAGE,1); }
Ma { RETURN(MESSAGE,1); }
MID { RETURN(MID,1); }
Mi { RETURN(MID,1); }
MID\$ { RETURN(MID,1); }
MIDI { RETURN(MIDI,1); }
Mid { RETURN(MIDI,1); }
MIN { RETURN(MIN,1); }
Mn { RETURN(MIN,1); }
MINUS { RETURN(MINUS,1); }
Min { RETURN(MINUS,1); }
MOB { RETURN(MOB,1); }
Mb { RETURN(MOB,1); }
MOD { RETURN(MOD,1); }
MODE { RETURN(MODE,1); }
M# { RETURN(MODE,1); }
M% { RETURN(MOD,1); }
MONOCOLOR { RETURN(MONOCOLOR,1); }
MONOCOLOUR { RETURN(MONOCOLOUR,1); }
MOVE { RETURN(MOVE,1); }
Mv { RETURN(MOVE,1); }
MOVEMENT { RETURN(MOVEMENT,1); }
Mvv { RETURN(MOVEMENT,1); }
MOVING { RETURN(MOVING,1); }
Mvi { RETURN(MOVING,1); }
MMOVE { RETURN(MMOVE,1); }
Mmv { RETURN(MMOVE,1); }
Mc { RETURN(MONOCOLOR,1); }
MS { RETURN(MILLISECOND,1); }
MSPRITE { RETURN(MSPRITE,1); }
Msp { RETURN(MSPRITE,1); }
MSX { RETURN(MSX,1); }
MSX1 { RETURN(MSX1,1); }
MILLISECOND { RETURN(MILLISECOND,1); }
MILLISECONDS { RETURN(MILLISECONDS,1); }
MUL { RETURN(MUL,1); }
Mu { RETURN(MUL,1); }
MULTICOLOR { RETURN(MULTICOLOR,1); }
Mcs { RETURN(MULTICOLOR,1); }
MULTI { RETURN(MULTI,1); }
Mlt { RETURN(MULTI,1); }
MO5 { RETURN(MO5,1); }
MULTICOLOUR { RETURN(MULTICOLOUR,1); }
MUSIC { RETURN(MUSIC,1); }
Mus { RETURN(MUSIC,1); }
MUTED { RETURN(MUTED,1); }

%{ /* --------------------------------- N --------------------------------- */ %}

NAME { RETURN(NAME,1); }
NAm { RETURN(NAME,1); }
NAMED { RETURN(NAMED,1); }
Na { RETURN(NAMED,1); }
NARROW { RETURN(NARROW,1); }
Naw { RETURN(NARROW,1); }
N { RETURN(N,1); }
NEXT { RETURN(NEXT,1); }
Ni { RETURN(NIBBLE,1); }
NEWLINE { RETURN(NEWLINE,1); }
Nl { RETURN(NEWLINE,1); }
NIBBLE { RETURN(NIBBLE,1); }
Nx { RETURN(NEXT,1); }
NEW { RETURN(NEW,1); }
Nw { RETURN(NEW,1); }
NOISE { RETURN(NOISE,1); }
NORMAL { RETURN(NORMAL,1); }
No { RETURN(NORMAL,1); }
NONE { RETURN(NONE,1); }
Nn { RETURN(NONE,1); }
NOP { RETURN(NOP,1); }
Np { RETURN(NOP,1); }
NOT { RETURN(NOT,1); }
Nt { RETURN(NOT,1); }
NOTE { RETURN(NOTE,1); }
Ne { RETURN(NOTE,1); }
NRM { RETURN(NRM,1); }
Nr { RETURN(NRM,1); }
NYLON { RETURN(NYLON,1); }
NTSC { RETURN(NTSC,1); }
Nts { RETURN(NTSC,1); }
NULL { RETURN(NULLkw,1); }
Nu { RETURN(NULLkw,1); }

%{ /* --------------------------------- O --------------------------------- */ %}

O { RETURN(O,1); }
OBOE { RETURN(OBOE,1); }
OCARINA { RETURN(OCARINA,1); }
OF { RETURN(OF,1); }
OFF { RETURN(OFF,1); }
Of { RETURN(OFF,1); }
OFFSET { RETURN(OFFSET,1); }
Ofs { RETURN(OFFSET,1); }
OOHS { RETURN(OOHS,1); }
OLIVE { RETURN(OLIVE,1); }
Ol { RETURN(OLIVE,1); }
ON { RETURN(ON,1); }
ONLY { RETURN(ONLY,1); }
On { RETURN(ONLY,1); }
OPACITY { RETURN(OPACITY, 1); }
Opc { RETURN(OPACITY, 1); }
OPTION { RETURN(OPTION,1); }
Op { RETURN(OPTION,1); }
OPEN { RETURN(OPEN,1); }
O\$ { RETURN(OPEN,1); }
OR { RETURN(OR,1); }
ORANGE { RETURN(ORANGE,1); }
Or { RETURN(ORANGE,1); }
ORCHESTRA { RETURN(ORCHESTRA,1); }
ORCHESTRAL { RETURN(ORCHESTRAL,1); }
ORGAN { RETURN(ORGAN,1); }
ORIGIN { RETURN(ORIGIN,1); }
Og { RETURN(ORIGIN,1); }
OUT { RETURN(OUT,1); }
Ou { RETURN(OUT,1); }
OVERDRIVEN { RETURN(OVERDRIVEN,1); }
OVERLAYED { RETURN(OVERLAYED,1); }
Ov { RETURN(OVERLAYED,1); }

%{ /* --------------------------------- P --------------------------------- */ %}

P { RETURN(P,1); }
PAD { RETURN(PAD,1); }
Pd { RETURN(PAD,1); }
PAGE { RETURN(PAGE,1); }
Pg { RETURN(PAGE,1); }
PAINT { RETURN(PAINT,1); } 
P# { RETURN(PAINT,1); } 
PAL { RETURN(PAL,1); }
Pal# { RETURN(PAL,1); }
PALETTE { RETURN(PALETTE,1); }
PAl { RETURN(PALETTE,1); }
Pal[0-9]+, { RETURN(PALETTE1,1); }
PAN { RETURN(PAN,1); }
PAPER { RETURN(PAPER,1); }
Pa { RETURN(PAPER,1); }
PARALLEL { RETURN(PARALLEL,1); }
PARSE { RETURN(PARSE,1); }
PAr { RETURN(PARSE,1); }
PASSWORD { RETURN(PASSWORD,1); }
PAs { RETURN(PASSWORD,1); }
PATH { RETURN(PATH,1); }
Pth { RETURN(PATH,1); }
Pr { RETURN(PARALLEL,1); }
PAUSE { RETURN(PAUSE,1); }
Pau { RETURN(PAUSE,1); }
PCLS { RETURN(PCLS,1); }
Pc { RETURN(PCLS,1); }
PC1403 { RETURN(PC1403,1); }
PARAM { RETURN(PARAM,1); }
Pm { RETURN(PARAM,1); }
PC128OP { RETURN(PC128OP,1); }
PEACH { RETURN(PEACH,1); }
Pch { RETURN(PEACH,1); }
PEEK { RETURN(PEEK,1); }
Pk { RETURN(PEEK,1); }
PEEKW { RETURN(PEEKW,1); }
Pkw { RETURN(PEEKW,1); }
PEEKD { RETURN(PEEKD,1); }
Pkd { RETURN(PEEKD,1); }
PEN { RETURN(PEN,1); }
Pn { RETURN(PEN,1); }
PERCUSSIVE { RETURN(PERCUSSIVE,1); }
PER { RETURN(PER,1); }
Pex { RETURN(PER,1); }
PERIOD { RETURN(PERIOD,1); }
Per { RETURN(PERIOD,1); }
PI { RETURN(PI,1); }
Pi { RETURN(PI,1); }
PIANO { RETURN(PIANO,1); }
PICCOLO { RETURN(PICCOLO,1); }
PICK { RETURN(PICK,1); }
PING { RETURN(PING,1); }
Pin { RETURN(PING,1); }
PINK { RETURN(PINK,1); }
Pik { RETURN(PINK,1); }
PIPE { RETURN(PIPE,1); }
PIZZICATO { RETURN(PIZZICATO,1); }
PLACE { RETURN(PLACE,1); }
Pla { RETURN(PLACE,1); }
PLAY { RETURN(PLAY,1); }
Py { RETURN(PLAY,1); }
PLOT { RETURN(PLOT,1); }
Pl { RETURN(PLOT,1); }
PLOTR { RETURN(PLOTR,1); }
P\$ { RETURN(PLOTR,1); }
PLUS { RETURN(PLUS,1); }
Plu { RETURN(PLUS,1); }
PLUS4 { RETURN(PLUS4,1); }
P4 { RETURN(PLUS4,1); }
PMODE { RETURN(PMODE,1); }
Pmd { RETURN(PMODE,1); }
POINT { RETURN(POINT,1); }
Pt { RETURN(POINT,1); }
POKE { RETURN(POKE,1); }
Po { RETURN(POKE,1); }
POKEY { RETURN(POKEY,1); }
POy { RETURN(POKEY,1); }
POKEW { RETURN(POKEW,1); }
Pow { RETURN(POKEW,1); }
POKED { RETURN(POKED,1); }
Pod { RETURN(POKED,1); }
POLYLINE { RETURN(POLYLINE,1); }
Ply { RETURN(POLYLINE,1); }
POLYSYNTH { RETURN(POLYSYNTH,1); }
PORT { RETURN(PORT,1); }
P^ { RETURN(PORT,1); }
POSITIVE { RETURN(POSITIVE,1); }
POST { RETURN(POST,1); }
PSG { RETURN(PSG,1); }
Psg { RETURN(PSG,1); }
Pst { RETURN(POSITIVE,1); }
POUND { RETURN(POUND,1); }
Pnd { RETURN(POUND,1); }
POP { RETURN(POP,1); }
Pp { RETURN(POP,1); }
POSITION { RETURN(POSITION,1); }
Ps { RETURN(POSITION,1); }
POW { RETURN(POWERING,1); }
Pw { RETURN(POWERING,1); }
PRECISE { RETURN(PRECISE,1); }
PRECISION { RETURN(PRECISION,1); }
Pre { RETURN(PRECISION,1); }
PRESET { RETURN(PRESET,1); }
Prs { RETURN(PRESET,1); }
PRESERVE { RETURN(PRESERVE,1); }
Pv { RETURN(PRESERVE,1); }
PRESS { RETURN(PRESS,1); }
PRx { RETURN(PRESS,1); }
PRESSED { RETURN(PRESSED,1); }
Px { RETURN(PRESSED,1); }
PRINT { RETURN(PRINT,1); }
PROBABILITY { RETURN(PROBABILITY,1); }
Prb { RETURN(PROC,1); }
PROC { RETURN(PROC,1); }
Prc { RETURN(PROC,1); }
PROCEDURE { RETURN(PROCEDURE,1); }
P1 { RETURN(PROCEDURE,1); }
Prcd { RETURN(PROCEDURE,1); }
PROGRAM { RETURN(PROGRAM,1); }
Prg { RETURN(PROGRAM,1); }
PSET { RETURN(PSET,1); }
P%t { RETURN(PSET,1); }
PURPLE { RETURN(PURPLE,1); }
Pur { RETURN(PURPLE,1); }
PUT { RETURN(PUT,1); }
Pu { RETURN(PUT,1); }

%{ /* --------------------------------- Q --------------------------------- */ %}

Q { RETURN(Q,1); }
QUERY { RETURN(QUERY,1); }
Qu { RETURN(QUERY,1); }

%{ /* --------------------------------- R --------------------------------- */ %}

R { RETURN(R,1); }
RADIAN { RETURN(RADIAN,1); }
Rdn { RETURN(RADIAN,1); }
RAIN { RETURN(RAIN,1); }
RANDOM { RETURN(RANDOM,1); }
Rd { RETURN(RANDOM,1); }
RANDOMIZE { RETURN(RANDOMIZE,1); }
RANGE { RETURN(RANGE,1); }
Rx { RETURN(RANGE,1); }
Rdm { RETURN(RANDOMIZE,1); }
RASTER { RETURN(RASTER,1); }
Rst { RETURN(RASTER,1); }
RATE { RETURN(RATE,1); }
Rte { RETURN(RATE,1); }
RATIO { RETURN(RATIO,1); }
Ra { RETURN(RATIO,1); }
RAW { RETURN(RAW,1); }
READ { RETURN(READ,1); }
R# { RETURN(READ,1); }
READONLY { RETURN(READONLY,1); }
Ron { RETURN(READONLY,1); }
READY { RETURN(READY,1); }
R#y { RETURN(READY,1); }
RECORDER { RETURN(RECORDER,1); }
REC { RETURN(REC,1); }
Rc { RETURN(REC,1); }
RECEIVE { RETURN(RECEIVE,1); }
Rcv { RETURN(RECEIVE,1); }
RED { RETURN(RED,1); }
Re { RETURN(RED,1); }
REED { RETURN(REED,1); }
REGISTER { RETURN(REGISTER,1); }
REg { RETURN(REGISTER,1); }
RELATIVE { RETURN(RELATIVE,1); }
Rel { RETURN(RELATIVE,1); }
RELEASE { RETURN(RELEASE,1); }
Rl { RETURN(RELEASE,1); }
RELOC { RETURN(RELOC,1); }
REl { RETURN(RELOC,1); }
REMEMBER { RETURN(REMEMBER,1); }
Rm { RETURN(REMEMBER,1); }
REPEAT { RETURN(REPEAT,1); }
Rpt { RETURN(REPEAT,1); }
REPLACE { RETURN(REPLACE,1); }
Rep { RETURN(REPLACE,1); }
RESPAWN { RETURN(RESPAWN,1); }
RLE { RETURN(RLE,1); }
Rn { RETURN(RESPAWN,1); }
RESIDENT { RETURN(RESIDENT,1); }
Rex { RETURN(RESIDENT,1); }
RESOLUTION { RETURN(RESOLUTION,1); }
Res { RETURN(RESOLUTION,1); }
RESTORE { RETURN(RESTORE,1); }
Rer { RETURN(RESTORE,1); }
RESUME { RETURN(RESUME,1); }
Rsm { RETURN(RESUME,1); }
RETRIES { RETURN(RETRIES,1); }
Rts { RETURN(RETRIES,1); }
RETURN { RETURN(RETURN,1); }
Rt { RETURN(RETURN,1); }
REVERSE { RETURN(REVERSE,1); }
RGB { RETURN(RGB,1); }
RIGHT { RETURN(RIGHT,1); }
RIGHT\$ { RETURN(RIGHT,1); }
Rg { RETURN(RIGHT,1); }
RIGHTB { RETURN(RIGHTB,1); }
RGb { RETURN(RIGHTB,1); }
RIGHTW { RETURN(RIGHTW,1); }
RGw { RETURN(RIGHTW,1); }
RING { RETURN(RING,1); }
RND { RETURN(RND,1); }
Rr { RETURN(RND,1); }
ROCK { RETURN(ROCK,1); }
ROLL { RETURN(ROLL,1); }
Ro { RETURN(ROLL,1); }
ROT { RETURN(ROT,1); }
Rot { RETURN(ROT,1); }
ROTATE { RETURN(ROTATE,1); }
ROt { RETURN(ROTATE,1); }
ROUNDS { RETURN(ROUNDS,1); }
ROu { RETURN(ROUNDS,1); }
ROW { RETURN(ROW,1); }
Rw { RETURN(ROW,1); }
ROWS { RETURN(ROWS,1); }
Rws { RETURN(ROWS,1); }
RUNSTOP { RETURN(RUNSTOP,1); }
RUN { RETURN(RUN,1); }
Ru { RETURN(RUN,1); }
RUNNING { RETURN(RUNNING,1); }
Run { RETURN(RUNNING,1); }

%{ /* --------------------------------- S --------------------------------- */ %}

S { RETURN(S,1); }
SAFE { RETURN(SAFE,1); }
Sa { RETURN(SAFE,1); }
SAVE { RETURN(SAVE,1); }
Sv { RETURN(SAVE,1); }
SAWTOOTH { RETURN(SAWTOOTH,1); }
SAX { RETURN(SAX,1); }
SBYTE { RETURN(SBYTE,1); }
Sb { RETURN(SBYTE,1); }
SC3000 { RETURN(SC3000,1); }
SCALE { RETURN(SCALE,1); }
S# { RETURN(SCALE,1); }
SCAN { RETURN(SCAN,1); }
Scn { RETURN(SCAN,1); }
SCANCODE { RETURN(SCANCODE,1); }
Scc { RETURN(SCANCODE,1); }
SCANSHIFT { RETURN(SCANSHIFT,1); }
Scs { RETURN(SCANSHIFT,1); }
SCI { RETURN(SCI,1); }
SCREEN { RETURN(SCREEN,1); }
Sc { RETURN(SCREEN,1); }
SCROLL { RETURN(SCROLL,1); }
Scl { RETURN(SCROLL,1); }
SEASHORE { RETURN(SEASHORE,1); }
SECOND { RETURN(SECOND,1); }
Sec { RETURN(SECOND,1); }
SECTION { RETURN(SECTION,1); }
SEEK { RETURN(SEEK,1); }
sk { RETURN(SEEK,1); }
SELECT { RETURN(SELECT,1); }
Sl { RETURN(SELECT,1); }
SEMICOLON { RETURN(SEMICOLON,1); }
SEMIGRAPHIC { RETURN(SEMIGRAPHIC,1); }
Sem { RETURN(SEMIGRAPHIC,1); }
SEND { RETURN(SEND,1); }
Sen { RETURN(SEND,1); }
SEPARATOR { RETURN(SEPARATOR,1); }
Sep { RETURN(SEPARATOR,1); }
SEQUENCE { RETURN(SEQUENCE,1); }
Seq { RETURN(SEQUENCE,1); }
SERIAL { RETURN(SERIAL,1); }
SEr { RETURN(SERIAL,1); }
SET { RETURN(SET,1); }
Se { RETURN(SET,1); }
SG1000 { RETURN(SG1000,1); }
SGN { RETURN(SGN,1); }
Sg { RETURN(SGN,1); }
SHADES { RETURN(SHADES,1); }
Shs { RETURN(SHADES,1); }
SHAKUHACHI { RETURN(SHAKUHACHI,1); }
SHAMISEN { RETURN(SHAMISEN,1); }
SHANAI { RETURN(SHANAI,1); }
SHARED { RETURN(SHARED,1); }
SIO { RETURN(SIO,1); }
Sr { RETURN(SHARED,1); }
SHIFT { RETURN(SHIFT,1); }
SHOOT { RETURN(SHOOT,1); }
Sho { RETURN(SHOOT,1); }
SID { RETURN(SID,1); }
SHUFFLE { RETURN(SHUFFLE,1); }
Sh { RETURN(SHUFFLE,1); }
Sd { RETURN(SID,1); }
SIGNED { RETURN(SIGNED,1); }
Sgnd { RETURN(SIGNED,1); }
SIMPLE { RETURN(SIMPLE,1); }
Sim { RETURN(SIMPLE,1); }
SJ2 { RETURN(SJ2,1); }
Sj2 { RETURN(SJ2,1); }
SIN { RETURN(SIN,1); }
Sn { RETURN(SIN,1); }
SINGLE { RETURN(SINGLE,1); }
Sng { RETURN(SINGLE,1); }
SITAR { RETURN(SITAR,1); }
SIZE { RETURN(SIZE,1); }
Sz { RETURN(SIZE,1); }
SLAP { RETURN(SLAP,1); }
SLASH { RETURN(SLASH,1); }
SLEEP { RETURN(SLEEP,1); }
SLe { RETURN(SLEEP,1); }
SLICE { RETURN(SLICE,1); }
SLOT { RETURN(SLOT,1); }
SLc { RETURN(SLICE,1); }
SN76489 { RETURN(SN76489,1); }
SOPRANO { RETURN(SOPRANO,1); }
SOUND { RETURN(SOUND,1); }
So { RETURN(SOUND,1); }
SOUNDTRACK { RETURN(SOUNDTRACK,1); }
SOURCE { RETURN(SOURCE,1); }
Src { RETURN(SOURCE,1); }
SPACE { RETURN(SPACE,1); }
Sp { RETURN(SPACE,1); }
SPAWN { RETURN(SPAWN,1); }
Sw { RETURN(SPAWN,1); }
SPC { RETURN(SPC,1); }
Ss { RETURN(SPC,1); }
SPEED { RETURN(SPEED,1); }
Spe { RETURN(SPEED,1); }
SPEN { RETURN(SPEN,1); }
SPe { RETURN(SPEN,1); }
SPRITE { RETURN(SPRITE,1); }
Spr { RETURN(SPRITE,1); }
SQUARE { RETURN(SQUARE,1); }
SQR { RETURN(SQR,1); }
STACK { RETURN(STACK,1); }
Stk { RETURN(STACK,1); }
STANDARD { RETURN(STANDARD,1); }
Std { RETURN(STANDARD,1); }
START { RETURN(START,1); }
Sta { RETURN(START,1); }
STATE { RETURN(STATE,1); }
Stt { RETURN(STATE,1); }
STATIC { RETURN(STATIC,1); }
Stc { RETURN(STATIC,1); }
STATUS { RETURN(STATUS,1); }
STa { RETURN(STATUS,1); }
STEADY { RETURN(STEADY,1); }
Ste { RETURN(STEADY,1); }
STEEL { RETURN(STEEL,1); }
STEP { RETURN(STEP,1); }
Stp { RETURN(STEP,1); }
STOP { RETURN(STOP,1); }
St { RETURN(STOP,1); }
STORAGE { RETURN(STORAGE,1); }
Str { RETURN(STORAGE,1); }
STR { RETURN(STR,1); }
STR\$ { RETURN(STR,1); }
S\$ { RETURN(STR,1); }
STRING { RETURN(STRING,1); }
S1 { RETURN(STRING,1); }
STRING\$ { RETURN(STRING,1); }
STRINGS { RETURN(STRINGS,1); }
STRIP { RETURN(STRIP,1); }
Sti { RETURN(STRIP,1); }
STRPTR { RETURN(STRPTR,1); }
Spt { RETURN(STRPTR,1); }
SUBSTRING { RETURN(SUBSTRING,1); }
Sbs { RETURN(SUBSTRING,1); }
SUM { RETURN(SUM,1); }
Sm { RETURN(SUM,1); }
SUCCESS { RETURN(SUCCESS,1); }
Su { RETURN(SUCCESS,1); }
SUSPEND { RETURN(SUSPEND,1); }
SS { RETURN(SUSPEND,1); }
SWAP { RETURN(SWAP,1); }
Swp { RETURN(SWAP,1); }
SWEEP { RETURN(SWEEP,1); }
SYNC { RETURN(SYNC,1); }
Syn { RETURN(SYNC,1); }
SYNTH { RETURN(SYNTH,1); }
SYNTHBRASS { RETURN(SYNTHBRASS,1); }
SYNTHSTRINGS { RETURN(SYNTHSTRINGS,1); }
SYS { RETURN(SYS,1); }
Sy { RETURN(SYS,1); }
SYSTEM { RETURN(SYSTEM,1); }
Sys { RETURN(SYSTEM,1); }

%{ /* --------------------------------- T --------------------------------- */ %}

T { RETURN(T,1); }
TAB { RETURN(TAB,1); }
Tb { RETURN(TAB,1); }
TAIKO { RETURN(TAIKO,1); }
TAN { RETURN(TAN,1); }
Tn { RETURN(TAN,1); }
TARGET { RETURN(TARGET,1); }
Tar { RETURN(TARGET,1); }
TANGO { RETURN(TANGO,1); }
TASK { RETURN(TASK,1); }
Ts { RETURN(TASK,1); }
TED { RETURN(TED,1); }
TELEPHONE { RETURN(TELEPHONE,1); }
TEMPORARY { RETURN(TEMPORARY,1); }
Tmp { RETURN(TEMPORARY,1); }
TENOR { RETURN(TENOR,1); }
TEXT { RETURN(TEXT,1); }
Tx { RETURN(TEXT,1); }
TEXTMAP { RETURN(TEXTMAP,1); }
Txm { RETURN(TEXTMAP,1); }
TEXTADDRESS { RETURN(TEXTADDRESS,1); }
Txa { RETURN(TEXTADDRESS,1); }
THEN { RETURN(THEN,1); }
Th { RETURN(THEN,1); }
THREAD { RETURN(THREAD,1); }
Thr { RETURN(THREAD,1); }
THRESHOLD { RETURN(THRESHOLD,1); }
Th2 { RETURN(THRESHOLD,1); }
TICK { RETURN(TICK,1); }
Tk { RETURN(TICK,1); }
TICKS { RETURN(TICKS,1); }
Tks { RETURN(TICKS,1); }
TPS { RETURN(TPS,1); }
Tp { RETURN(TPS,1); }
TIMPANI { RETURN(TIMPANI,1); }
TINKLE { RETURN(TINKLE,1); }
TILEMAP { RETURN(TILEMAP,1); }
Tm { RETURN(TILEMAP,1); }
TILE { RETURN(TILE,1); }
Tl { RETURN(TILE,1); }
TILES { RETURN(TILES,1); }
Tls { RETURN(TILES,1); }
TILESET { RETURN(TILESET,1); }
Tse { RETURN(TILESET,1); }
TIME { RETURN(TI,1); }
TI { RETURN(TI,1); }
TIMER { RETURN(TIMER,1); }
Tmr { RETURN(TIMER,1); }
TO { RETURN(TO,1); }
To { RETURN(TO,1); }
TO8 { RETURN(TO8,1); }
TOM { RETURN(TOM,1); }
TONK { RETURN(TONK,1); }
TRAVEL { RETURN(TRAVEL,1); }
Trv { RETURN(TRAVEL,1); }
TREMOLO { RETURN(TREMOLO,1); }
TROMBONE { RETURN(TROMBONE,1); }
TRUMPET { RETURN(TRUMPET,1); }
TUBA { RETURN(TUBA,1); }
TUBULAR { RETURN(TUBULAR,1); }
TURQUOISE { RETURN(TURQUOISE,1); }
Tu { RETURN(TURQUOISE,1); }
TRANSPARENCY { RETURN(TRANSPARENCY,1); }
Trs { RETURN(TRANSPARENCY,1); }
TRANSPARENT { RETURN(TRANSPARENT,1); }
Tra { RETURN(TRANSPARENT,1); }
TRUE { RETURN(TRUE,1); }
Tr { RETURN(TRUE,1); }
TSB { RETURN(TSB,1); }
TWEET { RETURN(TWEET,1); }
TYPE { RETURN(TYPE,1); }
Ty { RETURN(TYPE,1); }

%{ /* --------------------------------- U --------------------------------- */ %}

U { RETURN(U,1); }
UBOUND { RETURN(UBOUND,1); }
UCASE { RETURN(UCASE,1); }
Uca { RETURN(UCASE,1); }
UGBASIC { RETURN(UGBASIC,1); }
Ug { RETURN(UGBASIC,1); }
Ub { RETURN(UBOUND,1); }
UNBANKED { RETURN(UNBANKED,1); }
UNb { RETURN(UNBANKED,1); }
UNIQUE { RETURN(UNIQUE,1); }
Uq { RETURN(UNIQUE,1); }
UNFREEZE { RETURN(UNFREEZE,1); }
Unf { RETURN(UNFREEZE,1); }
UNSIGNED { RETURN(UNSIGNED,1); }
Uns { RETURN(UNSIGNED,1); }
UNTIL { RETURN(UNTIL,1); }
Un { RETURN(UNTIL,1); }
UP { RETURN(UP,1); }
UPB { RETURN(UPB,1); }
UPDATE { RETURN(UPDATE,1); }
Upd { RETURN(UPDATE,1); }
UPPER { RETURN(UPPER,1); }
UPPER\$ { RETURN(UPPER,1); }
Up { RETURN(UPPER,1); }
UPW { RETURN(UPW,1); }
USE { RETURN(USE,1); }
Ux { RETURN(USE,1); }
USING { RETURN(USING,1); }
Uxi { RETURN(USING,1); }

%{ /* --------------------------------- V --------------------------------- */ %}

V { RETURN(V,1); }
VAL { RETURN(VAL,1); }
Va { RETURN(VAL,1); }
VALUE { RETURN(VALUE,1); }
Vu { RETURN(VALUE,1); }
VALUES { RETURN(VALUES,1); }
Vus { RETURN(VALUES,1); }
VAR { RETURN(VAR,1); }
Vr { RETURN(VAR,1); }
VARBANK { RETURN(VARBANK,1); }
Vbk { RETURN(VARBANK,1); }
VARBANKPTR { RETURN(VARBANKPTR,1); }
Vbp { RETURN(VARBANKPTR,1); }
VARPTR { RETURN(VARPTR,1); }
Vp { RETURN(VARPTR,1); }
VBL { RETURN(VBL,1); }
Vb { RETURN(VBL,1); }
VCENTER { RETURN(VCENTER,1); }
VCENTRE { RETURN(VCENTRE,1); }
Vc { RETURN(VCENTER,1); }
VIC { RETURN(VIC,1); }
VIC20 { RETURN(VIC20,1); }
V20 { RETURN(VIC20,1); }
VARIABLES { RETURN(VARIABLES,1); }
Vas { RETURN(VARIABLES,1); }
VERTICAL { RETURN(VERTICAL,1); }
Ve { RETURN(VERTICAL,1); }
VECTOR { RETURN(VECTOR,1); }
Vec { RETURN(VECTOR,1); }
VG5000 { RETURN(VG5000,1); }
Vg5 { RETURN(VG5000,1); }
VHCENTER { RETURN(VHCENTER,1); }
VHCENTRE { RETURN(VHCENTRE,1); }
Vh { RETURN(VHCENTER,1); }
VIBRAPHONE { RETURN(VIBRAPHONE,1); }
VIDEO { RETURN(VIDEO,1); }
Vd { RETURN(VIDEO,1); }
VIOLA { RETURN(VIOLA,1); }
VIOLIN { RETURN(VIOLIN,1); }
VIOLET { RETURN(VIOLET,1); }
Vi { RETURN(VIOLET,1); }
VIRTUALIZED { RETURN(VIRTUALIZED,1); }
Viz { RETURN(VIRTUALIZED,1); }
VISIBLE { RETURN(VISIBLE,1); }
Vs { RETURN(VISIBLE,1); }
VOICE { RETURN(VOICE,1); }
VOLUME { RETURN(VOLUME,1); }
Vo { RETURN(VOLUME,1); }
VSCROLL { RETURN(VSCROLL,1); }
Vscl { RETURN(VSCROLL,1); }
VZ200 { RETURN(VZ200,1); }

%{ /* --------------------------------- W --------------------------------- */ %}

W { RETURN(W,1); }
WAIT { RETURN(WAIT,1); }
Wt { RETURN(WAIT,1); }
Wa { RETURN(WAIT,1); }
WARM { RETURN(WARM,1); }
WAVE { RETURN(WAVE,1); }
Wv { RETURN(WAVE,1); }
WEND { RETURN(WEND,1); }
We { RETURN(WEND,1); }
WHISTLE { RETURN(WHISTLE,1); }
WITH { RETURN(WITH,1); }
Wi { RETURN(WITH,1); }
WITHOUT { RETURN(WITHOUT,1); }
Wio { RETURN(WITHOUT,1); }
WIDE { RETURN(WIDE,1); }
Wid { RETURN(WIDE,1); }
WIDTH { RETURN(WIDTH,1); }
Wd { RETURN(WIDTH,1); }
WHILE { RETURN(WHILE,1); }
Wh { RETURN(WHILE,1); }
WHITE { RETURN(WHITE,1); }
Wht { RETURN(WHITE,1); }
WRITE { RETURN(WRITE,1); }
W# { RETURN(WRITE,1); }
WRITING { RETURN(WRITING,1); }
Wrt { RETURN(WRITING,1); }
WOODBLOCK { RETURN(WOODBLOCK,1); }
WORD { RETURN(WORD,1); }
Wo { RETURN(WORD,1); }

%{ /* --------------------------------- X --------------------------------- */ %}

X { RETURN(X,1); }
XGR { RETURN(XGR,1); }
XGRAPHIC { RETURN(XGRAPHIC,1); }
Xg { RETURN(XGRAPHIC,1); }
XY { RETURN(XY,1); }
XYLOPHONE { RETURN(XYLOPHONE,1); }
XOR { RETURN(XOR,1); }
Xr { RETURN(XOR,1); }
XCURS { RETURN(XCURS,1); }
Xcs { RETURN(XCURS,1); }
XTEXT { RETURN(XTEXT,1); }
Xt { RETURN(XTEXT,1); }
XPEN { RETURN(XPEN,1); }
Xp { RETURN(XPEN,1); }

%{ /* --------------------------------- Y --------------------------------- */ %}

Y { RETURN(Y,1); }
YGR { RETURN(YGR,1); }
YGRAPHIC { RETURN(YGRAPHIC,1); }
Yg { RETURN(YGRAPHIC,1); }
YX { RETURN(YX,1); }
YCURS { RETURN(YCURS,1); }
Ycs { RETURN(YCURS,1); }
YELLOW { RETURN(YELLOW,1); }
Ye { RETURN(YELLOW,1); }
YIELD { RETURN(YIELD,1); }
Yi { RETURN(YIELD,1); }
YTEXT { RETURN(YTEXT,1); }
Yt { RETURN(YTEXT,1); }
YPEN { RETURN(YPEN,1); }
Yp { RETURN(YPEN,1); }

%{ /* --------------------------------- Z --------------------------------- */ %}

Z { RETURN(Z,1); }
ZX { RETURN(ZX,1); }

\"(\\.|[^"\\])*\" { yylval.string = strdup(yytext); memcpy(yylval.string,yylval.string+1,strlen(yylval.string)); yylval.string[strlen(yylval.string)-1]=0; RETURN(String,1);  }
#\"(\\.|[^"\\])*\" { yylval.string = strdup(yytext); memcpy(yylval.string,yylval.string+2,strlen(yylval.string)-2); yylval.string[strlen(yylval.string)-3]=0; RETURN(RawString,1);  }
#'.' { yylval.integer = (unsigned char)yytext[2]; RETURN(Integer,1);  }
\$[a-fA-F0-9]+ { yylval.integer = strtol(yytext+1,0,16); RETURN(Integer,1); }
&[Hh][a-fA-F0-9]+ { yylval.integer = strtol(yytext+2,0,16); RETURN(Integer,1); }
0x[a-fA-F0-9]+ { yylval.integer = strtol(yytext+2,0,16); RETURN(Integer,1); }
[0-9][a-fA-F0-9]+[hH] { int c = strlen(yytext); yytext[c-1] = 0; yylval.integer = strtol(yytext,0,16); RETURN(Integer,1); }
%[0-1]+ { yylval.integer = strtol(yytext+1,0,2); RETURN(Integer,1); }
[0-9]+ { yylval.integer = atoi(yytext); RETURN(Integer,1);  }
-[0-9]*\.[0-9]+ { yylval.floating = atof(yytext); RETURN(Float,1);  }
[0-9]*\.[0-9]+ { yylval.floating = atof(yytext); RETURN(Float,1);  }
[0-9]*\.[0-9]+E[0-9]+ { yylval.floating = atof(yytext); RETURN(Float,1);  }
[0-9]*\.[0-9]+E-[0-9]+ { yylval.floating = atof(yytext); RETURN(Float,1);  }

[ \t]+ { yycolno = (yycolno + yyleng); yyposno = (yyposno + yyleng); }

[a-z\_][A-Za-z0-9\_]* { yylval.string = strdup(yytext); RETURN(Identifier,1);  }
[a-z\_][a-z0-9\_ ]+[ ][a-z0-9]+\n { yylval.string = translate_spaces(yytext); RETURN(IdentifierSpaced,1);  }

REG\([A-Z][A-Z]*\) { yylval.string = strdup(yytext+4); yylval.string[strlen(yylval.string)-1] = 0; RETURN(Register,1);  }
REG\([0-9]+\) { yylval.string = strdup(yytext+4); yylval.string[strlen(yylval.string)-1] = 0; RETURN(Register,1);  }
REG\([0-9]+,[0-9]+\) { yylval.string = strdup(yytext+4); yylval.string[strlen(yylval.string)-1] = 0; RETURN(Register,1);  }

. { yycolno++; yyposno++; return(yytext[0]); }


%%
