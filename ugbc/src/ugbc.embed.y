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
}

%token OP CP OP_EQUAL OP_DISEQUAL OP_AND OP_OR OP_NOT
%token IF ELSE ELSEIF ENDIF

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
      ;

embed:
  IF const_expr {
      ((struct _Environment *)_environment)->embedResult.conditional = 1;
    if ( $2 ) {
        ((struct _Environment *)_environment)->embedResult.excluded = 0;
    } else {
        ((struct _Environment *)_environment)->embedResult.excluded = 1;
    }
  }
  | ELSE {
    ((struct _Environment *)_environment)->embedResult.conditional = 1;
    if ( ((struct _Environment *)_environment)->embedResult.excluded ) {
        ((struct _Environment *)_environment)->embedResult.excluded = 0;
    } else {
        ((struct _Environment *)_environment)->embedResult.excluded = 1;
    }
  }
  | ELSE IF const_expr {
    ((struct _Environment *)_environment)->embedResult.conditional = 1;
    if ( ((struct _Environment *)_environment)->embedResult.excluded ) {
        if ( $3 ) {
            ((struct _Environment *)_environment)->embedResult.excluded = 0;
        } else {
            ((struct _Environment *)_environment)->embedResult.excluded = 1;
        }
    }
  }
  | ELSEIF const_expr {
    ((struct _Environment *)_environment)->embedResult.conditional = 1;
    if ( ((struct _Environment *)_environment)->embedResult.excluded ) {
        if ( $2 ) {
            ((struct _Environment *)_environment)->embedResult.excluded = 0;
        } else {
            ((struct _Environment *)_environment)->embedResult.excluded = 1;
        }
    }
  }
  | ENDIF {
    ((struct _Environment *)_environment)->embedResult.conditional = 1;
  }
  ;

%%

int embederror (Environment * _ignored, const char *s) /* Called by embedparse on error */
{
      fprintf(stderr,  "*** EMBED ERROR: %s  column %d (%d)\n", s, (embedcolno+1), (embedposno+1));
      exit(EXIT_FAILURE);
}

