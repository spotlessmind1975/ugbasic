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
%token IF ELSE ELSEIF ENDIF NewLine
%token ATARI ATARIXL C128 C64 VIC20 ZX COLECO SC3000 SG1000 MSX MSX1 DRAGON DRAGON32 DRAGON64 PC128OP MO5

%token <string> Identifier
%token <integer> Integer

%type <integer> const_expr const_factor target

%right Integer String CP 
%left OP
%right ELSE OP_NOT
%left OP_AND OP_OR

%%

target : 
    ATARI {
        #ifdef __atari__
            $$ = 1;
        #else
            $$ = 0;
        #endif
    }
    |
    ATARIXL {
        #ifdef __atarixl__
            $$ = 1;
        #else
            $$ = 0;
        #endif
    }
    |
    C128 {
        #ifdef __c128__
            $$ = 1;
        #else
            $$ = 0;
        #endif
    }
    |
    C64 {
        #ifdef __c64__
            $$ = 1;
        #else
            $$ = 0;
        #endif
    }
    |
    VIC20 {
        #ifdef __vic20__
            $$ = 1;
        #else
            $$ = 0;
        #endif
    }
    |
    ZX {
        #ifdef __zx__
            $$ = 1;
        #else
            $$ = 0;
        #endif
    }
    |
    COLECO {
        #ifdef __coleco__
            $$ = 1;
        #else
            $$ = 0;
        #endif
    }
    |
    SC3000 {
        #ifdef __sc3000__
            $$ = 1;
        #else
            $$ = 0;
        #endif
    }
    |
    SG1000 {
        #ifdef __sg1000__
            $$ = 1;
        #else
            $$ = 0;
        #endif
    }
    |
    MSX {
        #ifdef __msx1__
            $$ = 1;
        #else
            $$ = 0;
        #endif
    }
    |
    MSX1 {
        #ifdef __msx1__
            $$ = 1;
        #else
            $$ = 0;
        #endif
    }
    |
    DRAGON {
        #if defined(__d32__) || defined(__d64__)
            $$ = 1;
        #else
            $$ = 0;
        #endif
    }
    |
    DRAGON32 {
        #ifdef __d32__
            $$ = 1;
        #else
            $$ = 0;
        #endif
    }
    |
    DRAGON64 {
        #ifdef __d64__
            $$ = 1;
        #else
            $$ = 0;
        #endif
    }
    |
    PC128OP {
        #ifdef __pc128op__
            $$ = 1;
        #else
            $$ = 0;
        #endif
    }
    |
    MO5 {
        #ifdef __mo5__
            $$ = 1;
        #else
            $$ = 0;
        #endif
    }    
    ;

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
      | target {
        //   printf( "(%d)\n", $2 );
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

embed2:
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
  | {
      return 0;
  }
  ;

embed :
    embed2
    | embed2 NewLine;

%%

int embederror (Environment * _ignored, const char *s) /* Called by embedparse on error */
{
    printf( "*** LINE: %s\n", _ignored->embedResult.line );
    printf( "*** ERROR: %s at %d column %d (%d)\n", s, 0, (embedcolno+1), (yyposno+1));

    // fprintf(stdout, "*** error!\n" );
}

