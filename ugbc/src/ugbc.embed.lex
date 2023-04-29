%{

#include <string.h>
#include "ugbc.embed.tab.h" /* The tokens */

#define RETURN(b, c)    \
{\
    embedcolno = (embedcolno + embedleng) * c; \
    embedposno = (embedposno + embedleng); \
    return b; \
}

extern int embedcolno;
extern int embedposno;

%}

%option prefix="embed"

%%

"(" { RETURN(OP,1); }
")" { RETURN(CP,1); }
"==" { RETURN(OP_EQUAL,1); }
"!=" { RETURN(OP_DISEQUAL,1); }
"||" { RETURN(OP_OR,1); }
"&&" { RETURN(OP_AND,1); }
"!" { RETURN(OP_NOT,1); }
"@" { RETURN(OP_AT,1); }
"." { RETURN(OP_POINT,1); }
"<" { RETURN(OP_LT,1); }
"<=" { RETURN(OP_LTE,1); }
">" { RETURN(OP_GT,1); }
">=" { RETURN(OP_GTE,1); }
"," { RETURN(OP_COMMA,1); }
"\t" { RETURN(OP_TAB,1); }
"|" { RETURN(OP_PIPE,1); }

IF { RETURN(IF,1); }
ELSE { RETURN(ELSE,1); }
ELSEIF { RETURN(ELSEIF,1); }
ENDIF { RETURN(ENDIF,1); }

AS { RETURN(AS,1); }
EMIT { RETURN(EMIT,1); }

ATARI  { RETURN(ATARI,1); }
ATARIXL  { RETURN(ATARIXL,1); }
C128  { RETURN(C128,1); }
C128Z  { RETURN(C128Z,1); }
C64  { RETURN(C64,1); }
VIC20  { RETURN(VIC20,1); }
ZX  { RETURN(ZX,1); }
COLECO  { RETURN(COLECO,1); }
SC3000 { RETURN(SC3000,1); }
SG1000  { RETURN(SG1000,1); }
MSX  { RETURN(MSX,1); }
MSX1  { RETURN(MSX1,1); }
COCO  { RETURN(COCO,1); }
DRAGON  { RETURN(DRAGON,1); }
DRAGON32  { RETURN(DRAGON32,1); }
DRAGON64 { RETURN(DRAGON64,1); }
PC128OP  { RETURN(PC128OP,1); }
MO5  { RETURN(MO5,1); }
CPC  { RETURN(CPC,1); }

MACRO { RETURN(MACRO,1); }
ENDMACRO { RETURN(ENDMACRO,1); }
INLINE { RETURN(INLINE,1); }

[\n\r]+ { RETURN(NewLine,0);}
\$[a-fA-F0-9]+ { embedlval.integer = strtol(embedtext+1,0,16); RETURN(Integer,1); }
&[Hh][a-fA-F0-9]+ { embedlval.integer = strtol(embedtext+2,0,16); RETURN(Integer,1); }
0x[a-fA-F0-9]+ { embedlval.integer = strtol(embedtext+2,0,16); RETURN(Integer,1); }
[a-fA-F0-9]+[hH] { int c = strlen(embedtext); embedtext[c-1] = 0; embedlval.integer = strtol(embedtext,0,16); RETURN(Integer,1); }
%[0-1]+ { embedlval.integer = strtol(embedtext+1,0,2); RETURN(Integer,1); }
\s[-][0-9]+ { embedlval.integer = atoi(embedtext); RETURN(Integer,1);  }
[0-9]+ { embedlval.integer = atoi(embedtext); RETURN(Integer,1);  }
[ \t]+ { embedcolno = (embedcolno + embedleng); embedposno = (embedposno + embedleng); }

[A-Za-z0-9\_]* { embedlval.string = strdup(embedtext); RETURN(Identifier,1);  }
@@[^\n]* { char * content = strdup(embedtext); embedlval.string = content+2; RETURN(Content,1);  }
\[[^\]]+\] { char * value = strdup(embedtext); embedlval.string = value+1; embedlval.string[strlen(embedlval.string)-1] = 0; RETURN(Value,1);  }

. { embedcolno++; embedposno++; return(embedtext[0]); }

%%
