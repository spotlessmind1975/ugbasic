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

IF { RETURN(IF,1); }
ELSE { RETURN(ELSE,1); }
ELSEIF { RETURN(ELSEIF,1); }
ENDIF { RETURN(ENDIF,1); }

[\n\r]+ { RETURN(NewLine,0);}
\$[a-fA-F0-9]+ { embedlval.integer = strtol(embedtext+1,0,16); RETURN(Integer,1); }
&[Hh][a-fA-F0-9]+ { embedlval.integer = strtol(embedtext+2,0,16); RETURN(Integer,1); }
0x[a-fA-F0-9]+ { embedlval.integer = strtol(embedtext+2,0,16); RETURN(Integer,1); }
[a-fA-F0-9]+[hH] { int c = strlen(embedtext); embedtext[c-1] = 0; embedlval.integer = strtol(embedtext,0,16); RETURN(Integer,1); }
%[0-1]+ { embedlval.integer = strtol(embedtext+1,0,2); RETURN(Integer,1); }
\s[-][0-9]+ { embedlval.integer = atoi(embedtext); RETURN(Integer,1);  }
[0-9]+ { embedlval.integer = atoi(embedtext); RETURN(Integer,1);  }

[ \t]+ { embedcolno = (embedcolno + embedleng); embedposno = (embedposno + embedleng); }

[a-z\_][A-Za-z0-9\_]* { embedlval.string = strdup(embedtext); RETURN(Identifier,1);  }

. { embedcolno++; embedposno++; return(embedtext[0]); }

%%
