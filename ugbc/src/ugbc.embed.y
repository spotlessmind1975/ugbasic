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

char *str_replace( char *orig, char *rep, char *with ) {
    char *result; // the return string
    char *ins;    // the next insert point
    char *tmp;    // varies
    int len_rep;  // length of rep (the string to remove)
    int len_with; // length of with (the string to replace rep with)
    int len_front; // distance between rep and end of last rep
    int count;    // number of replacements

    // sanity checks and initialization
    if (!orig || !rep)
        return NULL;
    len_rep = strlen(rep);
    if (len_rep == 0)
        return NULL; // empty rep causes infinite loop during count
    if (!with)
        with = "";
    len_with = strlen(with);

    // count the number of replacements needed
    ins = orig;
    for (count = 0; tmp = strstr(ins, rep); ++count) {
        ins = tmp + len_rep;
    }

    tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    // first time through the loop, all the variable are set correctly
    // from here on,
    //    tmp points to the end of the result string
    //    ins points to the next occurrence of rep in orig
    //    orig points to the remainder of orig after "end of rep"
    while (count--) {
        ins = strstr(orig, rep);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep; // move to next "end of rep"
    }
    strcpy(tmp, orig);
    return result;
}

%}

%parse-param {void * _environment}

%locations

%define parse.error verbose

%start embed

%union {
    int integer;
    char * string;
}

%token OP CP OP_AT OP_EQUAL OP_DISEQUAL OP_AND OP_OR OP_NOT OP_POINT OP_LT OP_LTE OP_GT OP_GTE OP_COMMA OP_TAB OP_PIPE
%token IF ELSE ELSEIF ENDIF EMIT AS NewLine
%token ATARI ATARIXL C128 C128Z C64 VIC20 ZX COLECO SC3000 SG1000 MSX MSX1 DRAGON DRAGON32 DRAGON64 PC128OP MO5 CPC COCO
%token MACRO ENDMACRO INLINE

%token <string> Identifier
%token <string> Content
%token <string> Value
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
    C128Z {
        #ifdef __c128z__
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
    COCO {
        #if defined(__coco__)
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
    |
    CPC {
        #ifdef __cpc__
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
    | const_factor OP_LT const_factor {
        // printf( "%d != %d\n", $1, $3 );
        $$ = ( $1 < $3 );
    }
    | const_factor OP_LTE const_factor {
        // printf( "%d != %d\n", $1, $3 );
        $$ = ( $1 <= $3 );
    }
    | const_factor OP_GT const_factor {
        // printf( "%d != %d\n", $1, $3 );
        $$ = ( $1 > $3 );
    }
    | const_factor OP_GTE const_factor {
        // printf( "%d != %d\n", $1, $3 );
        $$ = ( $1 >= $3 );
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
            } else if ( strcmp( $3, "palettePreserve" ) == 0 ) {
                $$ = ((struct _Environment *)_environment)->vestigialConfig.palettePreserve;
            } else {
                $$ = 0;
            }
        } else if ( strcmp( $1, "fontConfig" ) == 0 ) {
            if ( strcmp( $3, "schema" ) == 0 ) {
                $$ = ((struct _Environment *)_environment)->fontConfig.schema;
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
        // printf( "%s == %d\n", $1, $$ );
      }
      ;

macro_parameter :
    Identifier {
        Macro * currentMacro = ((struct _Environment *)_environment)->embedResult.currentMacro;
        if ( currentMacro ) {
            currentMacro->parameters[currentMacro->parameterCount++] = strdup( $1 );
            if ( currentMacro->parameterCount == MAX_TEMPORARY_STORAGE ) {
                CRITICAL_MACRO_TOO_MUCH_PARAMETERS( currentMacro->name, $1 );
            }
        }
    };

macro_parameters : 
    | macro_parameter
    | macro_parameter OP_COMMA macro_parameters;

macro_value :
    Value {
        ((struct _Environment *)_environment)->embedResult.values[((struct _Environment *)_environment)->embedResult.valueCount++] = strdup( $1 );
        if ( ((struct _Environment *)_environment)->embedResult.valueCount == MAX_TEMPORARY_STORAGE ) {
            CRITICAL_MACRO_TOO_MUCH_VALUES( ((struct _Environment *)_environment)->embedResult.currentMacro->name, $1 );
        }
    };

macro_values : 
    | macro_value
    | macro_value OP_COMMA macro_values;

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
  | OP_AT EMIT Identifier AS Identifier {
        if ( strcmp( $3, "frameBufferStart" ) == 0 ) {
            outline2( "%s=$%4.4x", $5, ((struct _Environment *)_environment)->frameBufferStart );
        }
        ((struct _Environment *)_environment)->embedResult.conditional = 1;
  }
  | OP_AT MACRO Identifier 
  {

    int i; 
    for( i=0; i<((struct _Environment *)_environment)->embedResult.current; ++i ) {
        if ( ((struct _Environment *)_environment)->embedResult.excluded[i] )
        break;
    }
    if ( i>= ((struct _Environment *)_environment)->embedResult.current ) {
        // printf( "%d @MACRO %s\n", ((struct _Environment *)_environment)->embedResult.current, $3 );

        ((struct _Environment *)_environment)->embedResult.currentMacro = malloc( sizeof( Macro ) );
        memset( ((struct _Environment *)_environment)->embedResult.currentMacro, 0, sizeof( Macro ) );
        Macro * currentMacro = ((struct _Environment *)_environment)->embedResult.currentMacro;
        currentMacro->name = strdup( $3 );
    }
  } macro_parameters {
    ((struct _Environment *)_environment)->embedResult.conditional = 1;
  }
  | OP_AT ENDMACRO
  {
    // printf( "@ENDMACRO\n" );

    Macro * currentMacro = ((struct _Environment *)_environment)->embedResult.currentMacro;
    if ( currentMacro ) {
        Macro * macro = ((struct _Environment *)_environment)->embedResult.macro;
        currentMacro->next = macro;
        ((struct _Environment *)_environment)->embedResult.macro = currentMacro;
        ((struct _Environment *)_environment)->embedResult.currentMacro = NULL;
    }
    ((struct _Environment *)_environment)->embedResult.conditional = 1;
  }
  | Content {
    // printf( " MACRO CONTENT = %s\n", $1 );

    Macro * currentMacro = ((struct _Environment *)_environment)->embedResult.currentMacro;
    if ( currentMacro ) {
        currentMacro->lines[currentMacro->lineCount++] = strdup( $1 );
        if ( currentMacro->lineCount == MAX_TEMPORARY_STORAGE ) {
            CRITICAL_MACRO_TOO_MUCH_LINES( currentMacro->name );
        }  
    }
    ((struct _Environment *)_environment)->embedResult.conditional = 1;
  }
  | OP_AT INLINE Identifier {

    // printf( "@INLINE %s\n", $3 );

    Macro * macro = ((struct _Environment *)_environment)->embedResult.macro;
    if ( ! macro ) {
        CRITICAL_MACRO_UNDEFINED( $3 );
    }
    while( macro ) {
        if ( strcmp( macro->name, $3 ) == 0 ) {
            break;
        }
        macro = macro->next;
    }
    if ( ! macro ) {
        CRITICAL_MACRO_UNDEFINED( $3 );
    }
    ((struct _Environment *)_environment)->embedResult.currentMacro = macro;
    ((struct _Environment *)_environment)->embedResult.lineCount = 0;
    ((struct _Environment *)_environment)->embedResult.valueCount = 0;
  } macro_values {
    
    MAKE_LABEL

    Macro * currentMacro = ((struct _Environment *)_environment)->embedResult.currentMacro;
    if ( ((struct _Environment *)_environment)->embedResult.valueCount != currentMacro->parameterCount ) {
        CRITICAL_MACRO_MISMATCH_PARAMETER_VALUES( currentMacro->name );
    }

    int j=0;
    for( j=0; j<currentMacro->lineCount; ++j ) {
        char * line = currentMacro->lines[j];
        int k=0;
        for( k=0; k<currentMacro->parameterCount; ++k ) {
            char * nextLine = str_replace( line, currentMacro->parameters[k], ((struct _Environment *)_environment)->embedResult.values[k] );
            if ( nextLine ) {
                line = nextLine;
            }
        }
        char * nextLine = str_replace( line, "label", label );
        if ( nextLine ) {
            line = nextLine;
        }
        ((struct _Environment *)_environment)->embedResult.lines[((struct _Environment *)_environment)->embedResult.lineCount++] = line;
        ((Environment *)_environment)->producedAssemblyLines += assemblyLineIsAComment( line ) ? 0 : 1; \
    }
    ((struct _Environment *)_environment)->embedResult.currentMacro = NULL;
    // printf( " lineCount = %d\n", ((struct _Environment *)_environment)->embedResult.lineCount );
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
    printf( "*** LINE2: %s\n", _ignored->embedResult.line );
    printf( "*** ERROR2: %s at %d column %d (%d)\n", s, 0, (embedcolno+1), (yyposno+1));

    exit(0);
}

