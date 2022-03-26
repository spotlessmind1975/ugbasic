%{

#include "../src/ugbc.h"

int embedlex();
int embederror(Environment *, const char *);
int embeddebug=0;
int embederrors=0;

int embedcolno;
int embedposno;

int embedwrap() { return 1; }

#include <math.h>

%}

%parse-param {void * _environment}

%locations

%define parse.error verbose

%start embed

%union {
    int integer;
    char * string;
}

%token OP CP OP_AT OP_EQUAL OP_DISEQUAL OP_AND OP_OR OP_NOT OP_POINT
%token IF ELSE ELSEIF ENDIF

%token <string> Identifier
%token <integer> Integer

%type <integer> const_expr const_term const_modula const_factor const_expr_math

%right Integer String CP 
%left OP
%right ELSE
%left AND OR

%%

const_expr : 
      const_expr_math
    | const_expr_math AND const_expr_math {        
        $$ = ( $1 && $3 );
    } 
    | const_expr_math OR const_expr_math {
        $$ = ( $1 || $3 );
    } 
    | const_expr_math OP_EQUAL const_expr_math {
        $$ = ( $1 == $3 );
    }
    | const_expr_math OP_DISEQUAL const_expr_math {
        $$ = ( $1 != $3 );
    }
    | OP_NOT const_expr {
        $$ = ( ! $2 );
    }
    ;
    
const_expr_math: 
      const_term
    ;

const_term:
      const_modula
    ;

const_modula: 
      const_factor
    ;

const_factor: 
        Integer {
          $$ = $1;
      }
      | OP const_expr CP {
          $$ = $2;
      }
      | Identifier OP_POINT Identifier {
        if ( strcmp( $1, "vestigialConfig" ) == 0 ) {
            if ( strcmp( $3, "screenModeUnique" ) == 0 ) {
                $$ = ((struct _Environment *)_environment)->vestigialConfig.screenModeUnique;
            } else {
                $$ = 0;
            }
        } else {
            $$ = 0;
        }
      }
      | Identifier {
        if ( strcmp( $1, "currentMode" ) == 0 ) {
            $$ = ((struct _Environment *)_environment)->currentMode;
        } else {
            $$ = 0;
        }
      }
      ;

embed:
    OP_AT IF const_expr {
        printf("@IF %d\n", $3);
      ((struct _Environment *)_environment)->embedResult.conditional = 1;
    if ( $3 ) {
        ((struct _Environment *)_environment)->embedResult.excluded = 0;
    } else {
        ((struct _Environment *)_environment)->embedResult.excluded = 1;
    }
  }
  | OP_AT ELSE {
    ((struct _Environment *)_environment)->embedResult.conditional = 1;
    if ( ((struct _Environment *)_environment)->embedResult.excluded ) {
        ((struct _Environment *)_environment)->embedResult.excluded = 0;
    } else {
        ((struct _Environment *)_environment)->embedResult.excluded = 1;
    }
  }
  | OP_AT ELSE IF const_expr {
    ((struct _Environment *)_environment)->embedResult.conditional = 1;
    if ( ((struct _Environment *)_environment)->embedResult.excluded ) {
        if ( $4 ) {
            ((struct _Environment *)_environment)->embedResult.excluded = 0;
        } else {
            ((struct _Environment *)_environment)->embedResult.excluded = 1;
        }
    }
  }
  | OP_AT ELSEIF const_expr {
    ((struct _Environment *)_environment)->embedResult.conditional = 1;
    if ( ((struct _Environment *)_environment)->embedResult.excluded ) {
        if ( $3 ) {
            ((struct _Environment *)_environment)->embedResult.excluded = 0;
        } else {
            ((struct _Environment *)_environment)->embedResult.excluded = 1;
        }
    }
  }
  | OP_AT ENDIF {
    ((struct _Environment *)_environment)->embedResult.conditional = 1;
    ((struct _Environment *)_environment)->embedResult.excluded = 0;
  }
  ;

%%

int embederror (Environment * _ignored, const char *s) /* Called by embedparse on error */
{

}

