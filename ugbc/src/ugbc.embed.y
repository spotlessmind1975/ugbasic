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

%type <integer> const_expr const_factor

%right Integer String CP 
%left OP
%right ELSE OP_NOT
%left OP_AND OP_OR

%%

const_expr : 
      const_factor {
        // printf( "%d\n", $1 );
      }
    | const_factor OP_AND const_expr {        
        // printf( "%d AND %d\n", $1, $3 );
        $$ = ( $1 && $3 );
    } 
    | const_factor OP_OR const_expr {
        // printf( "%d OR %d\n", $1, $3 );
        $$ = ( $1 || $3 );
    } 
    | const_factor OP_EQUAL const_factor {
        // printf( "%d == %d\n", $1, $3 );
        $$ = ( $1 == $3 );
    }
    | const_factor OP_DISEQUAL const_factor {
        // printf( "%d != %d\n", $1, $3 );
        $$ = ( $1 != $3 );
    }
    ;
    
const_factor: 
        Integer {
        //   printf( "# %d\n", $1 );
          $$ = $1;
      }
      | OP const_expr CP {
        //   printf( "(%d)\n", $2 );
          $$ = $2;
      }
      | OP_NOT const_factor {
        // printf( "NOT %d\n", $2 );
          $$ = ( ! $2 );
      }
      | Identifier OP_POINT Identifier {
        if ( strcmp( $1, "vestigialConfig" ) == 0 ) {
            if ( strcmp( $3, "screenModeUnique" ) == 0 ) {
                $$ = ((struct _Environment *)_environment)->vestigialConfig.screenModeUnique;
            } else if ( strcmp( $3, "doubleBufferSelected" ) == 0 ) {
                $$ = ((struct _Environment *)_environment)->vestigialConfig.doubleBufferSelected;
            } else if ( strcmp( $3, "doubleBuffer" ) == 0 ) {
                $$ = ((struct _Environment *)_environment)->vestigialConfig.doubleBuffer;
            } else {
                $$ = 0;
            }
        } else {
            $$ = 0;
        }
        // printf( "%s.%s == %d\n", $1, $3, $$ );
      }
      | Identifier {
        if ( strcmp( $1, "currentMode" ) == 0 ) {
            $$ = ((struct _Environment *)_environment)->currentMode;
        } else {
            $$ = 0;
        }
        //   printf( "%s == %d\n", $1, $$ );
      }
      ;

embed:
    OP_AT IF const_expr {
    //    printf( "--- IF ---\n" );

      ((struct _Environment *)_environment)->embedResult.conditional = 1;
    if ( $3 ) {
        ((struct _Environment *)_environment)->embedResult.excluded[((struct _Environment *)_environment)->embedResult.current] = 0;
    } else {
        ((struct _Environment *)_environment)->embedResult.excluded[((struct _Environment *)_environment)->embedResult.current] = 1;
    }
    ++((struct _Environment *)_environment)->embedResult.current;
  }
  | OP_AT ELSE {
    ((struct _Environment *)_environment)->embedResult.conditional = 1;
    if ( ((struct _Environment *)_environment)->embedResult.excluded[((struct _Environment *)_environment)->embedResult.current-1] ) {
        ((struct _Environment *)_environment)->embedResult.excluded[((struct _Environment *)_environment)->embedResult.current-1] = 0;
    } else {
        ((struct _Environment *)_environment)->embedResult.excluded[((struct _Environment *)_environment)->embedResult.current-1] = 1;
    }
  }
  | OP_AT ELSE IF const_expr {
    ((struct _Environment *)_environment)->embedResult.conditional = 1;
    if ( ((struct _Environment *)_environment)->embedResult.excluded[((struct _Environment *)_environment)->embedResult.current-1] ) {
        if ( $4 ) {
            ((struct _Environment *)_environment)->embedResult.excluded[((struct _Environment *)_environment)->embedResult.current-1] = 0;
        } else {
            ((struct _Environment *)_environment)->embedResult.excluded[((struct _Environment *)_environment)->embedResult.current-1] = 1;
        }
    }
  }
  | OP_AT ELSEIF const_expr {
    ((struct _Environment *)_environment)->embedResult.conditional = 1;
    if ( ((struct _Environment *)_environment)->embedResult.excluded[((struct _Environment *)_environment)->embedResult.current-1] ) {
        if ( $3 ) {
            ((struct _Environment *)_environment)->embedResult.excluded[((struct _Environment *)_environment)->embedResult.current-1] = 0;
        } else {
            ((struct _Environment *)_environment)->embedResult.excluded[((struct _Environment *)_environment)->embedResult.current-1] = 1;
        }
    }
  }
  | OP_AT ENDIF {
    ((struct _Environment *)_environment)->embedResult.conditional = 1;
    ((struct _Environment *)_environment)->embedResult.excluded[((struct _Environment *)_environment)->embedResult.current-1] = 0;
    --((struct _Environment *)_environment)->embedResult.current;
  }
  | %empty {
      return 0;
  }
  ;

%%

int embederror (Environment * _ignored, const char *s) /* Called by embedparse on error */
{
    fprintf(stderr, "*** LINE: %s\n", _ignored->embedResult.line );
    fprintf(stderr,  "*** ERROR: %s at %d column %d (%d)\n", s, 0, (embedcolno+1), (yyposno+1));

    // fprintf(stdout, "*** error!\n" );
}

