%{

#include "../src/ugbc.h"

int yylex();
int yyerror(Environment *, const char *);
int yydebug=0;
int errors=0;
extern int yylineno;

int yywrap() { return 1; }
 
extern char DATATYPE_AS_STRING[][16];

%}

%parse-param {void * _environment}

%locations

%define parse.error verbose

%start program

%union {
    int integer;
    char * string;
}

%token Remark
%token NewLine 
%token SEMICOLON COLON COMMA PLUS MINUS INC DEC EQUAL ASSIGN LT LTE GT GTE 
%token DISEQUAL MULTIPLICATION DOLLAR DIVISION QM HAS IS OF

%token RASTER DONE AT COLOR BORDER WAIT NEXT WITH BANK SPRITE DATA FROM OP CP 
%token ENABLE DISABLE HALT ECM BITMAP SCREEN ON OFF ROWS VERTICAL SCROLL VAR AS TEMPORARY 
%token XPEN YPEN PEEK GOTO HORIZONTAL MCM COMPRESS EXPAND LOOP REPEAT WHILE TEXT TILES
%token COLORMAP SELECT MONOCOLOR MULTICOLOR COLLISION IF THEN HIT BACKGROUND TO RANDOM
%token BYTE WORD POSITION CODE VARIABLES MS CYCLES S HASH WIDTH HEIGHT DWORD PEN CLEAR
%token BEG END GAMELOOP ENDIF UP DOWN LEFT RIGHT DEBUG AND RANDOMIZE GRAPHIC TEXTMAP
%token POINT GOSUB RETURN POP OR ELSE NOT TRUE FALSE DO EXIT WEND UNTIL FOR STEP EVERY
%token MID INSTR UPPER LOWER STR VAL STRING SPACE FLIP CHR ASC LEN POW MOD ADD MIN MAX SGN
%token SIGNED ABS RND COLORS INK TIMER POWERING DIM ADDRESS PROC PROCEDURE CALL OSP CSP
%token SHARED MILLISECOND MILLISECONDS TICKS GLOBAL PARAM PRINT DEFAULT USE
%token PAPER INVERSE REPLACE XOR IGNORE NORMAL WRITING ONLY LOCATE CLS HOME CMOVE
%token CENTER CENTRE TAB SET CUP CDOWN CLEFT CRIGHT CLINE XCURS YCURS MEMORIZE REMEMBER
%token HSCROLL VSCROLL TEXTADDRESS JOY BIN BIT COUNT JOYCOUNT FIRE JUP JDOWN JLEFT JRIGHT JFIRE
%token INKEY SCANCODE SCAN SHIFT SCANSHIFT BOTH SHIFTS

%token BLACK WHITE RED CYAN VIOLET GREEN BLUE YELLOW ORANGE
%token BROWN LIGHT DARK GREY GRAY MAGENTA PURPLE
%token LAVENDER GOLD TURQUOISE TAN PINK PEACH OLIVE

%token <string> Identifier
%token <string> String
%token <integer> Integer

%type <string> expr term modula factor exponential expr_math
%type <integer> direct_integer
%type <string> random_definition_simple random_definition
%type <string> color_enumeration
%type <string> writing_mode_definition writing_part_definition
%type <integer> datatype

%right Integer String CP 
%left DOLLAR
%left OP
%right THEN ELSE
%left POW
%left MULTIPLICATION DIVISION
%left MOD
%left PLUS MINUS
%left OF IS
%right HAS BIT
%left AND OR EQUAL DISEQUAL LT LTE GT GTE

%%

expr : 
      expr_math
    | expr_math AND expr_math {
        $$ = variable_and( _environment, $1, $3 )->name;
        outline3("; %s = %s AND %s", $$, $1, $3 );
    } 
    | expr_math OR expr_math {
        $$ = variable_or( _environment, $1, $3 )->name;
        outline3("; %s = %s OR %s", $$, $1, $3 );
    } 
    | expr_math EQUAL expr_math {
        $$ = variable_compare( _environment, $1, $3 )->name;
    }
    | expr_math DISEQUAL expr_math {
        $$ = variable_compare_not( _environment, $1, $3 )->name;
    }
    | expr_math LT expr_math {
        $$ = variable_less_than( _environment, $1, $3, 0 )->name;
    }
    | expr_math LTE expr_math {
        $$ = variable_less_than( _environment, $1, $3, 1 )->name;
    }
    | expr_math GT expr_math {
        $$ = variable_greater_than( _environment, $1, $3, 0 )->name;
    }
    | expr_math GTE expr_math {
        $$ = variable_greater_than( _environment, $1, $3, 0 )->name;
    }
    | NOT expr {
        $$ = variable_not( _environment, $2 )->name;
    }
    ;
    
expr_math: 
      term
    | expr_math PLUS term {
        $$ = variable_add( _environment, $1, $3 )->name;
    }
    | expr_math MINUS term {
        $$ = variable_sub( _environment, $1, $3 )->name;
        outline3("; %s = %s - %s", $$, $1, $3 );
    }
    ;

term:
      modula
    | term MOD modula
    ;

modula: 
      factor
    | modula MULTIPLICATION factor {
        $$ = variable_mul( _environment, $1, $3 )->name;
        outline3("; %s = %s * %s", $$, $1, $3 );
    } 
    | modula DIVISION factor {
        $$ = variable_div( _environment, $1, $3 )->name;
        outline3("; %s = %s / %s", $$, $1, $3 );
    } 
    ;

factor: 
        exponential
      | factor POW exponential {
        $$ = powering( _environment, $1, $3 )->name;
        outline3("; %s = %s ^ %s", $$, $1, $3 );
      }
      | POWERING OP factor COMMA exponential CP {
        $$ = powering( _environment, $3, $5 )->name;
        outline3("; %s = %s ^ %s", $$, $3, $5 );
      }
      | factor HAS BIT exponential {
        $$ = variable_bit( _environment, $1, $4 )->name;
      }
      | factor HAS NOT BIT exponential {
        $$ = variable_not( _environment, variable_bit( _environment, $1, $5 )->name )->name;
      }
      | factor IS exponential {
        $$ = variable_bit( _environment, $1, $3 )->name;
      }
      | factor IS NOT exponential {
        $$ = variable_not( _environment, variable_bit( _environment, $1, $4 )->name )->name;
      }
      | BIT exponential OF factor {
        $$ = variable_bit( _environment, $2, $4 )->name;
      }
      ;

direct_integer:
    HASH Integer {
        $$ = $2;
    };

random_definition_simple:
      BYTE {
        $$ = random_value( _environment, VT_BYTE )->name;
    }
    | WORD {
        $$ = random_value( _environment, VT_WORD )->name;
    }
    | DWORD {
        $$ = random_value( _environment, VT_DWORD )->name;
    }
    | POSITION {
        $$ = random_value( _environment, VT_POSITION )->name;
    }
    | COLOR {
        $$ = random_value( _environment, VT_COLOR )->name;
    }
    | WIDTH {
        $$ = random_width( _environment )->name;
    }
    | HEIGHT {
        $$ = random_height( _environment )->name;
    };

random_definition:
      random_definition_simple {
          $$ = $1;
      };

color_enumeration:
      BLACK {
          $$ = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, $$, COLOR_BLACK );
      }
      | WHITE {
          $$ = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, $$, COLOR_WHITE );
      }
      | RED {
          $$ = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, $$, COLOR_RED );
      }
      | CYAN {
          $$ = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, $$, COLOR_CYAN );
      }
      | VIOLET {
          $$ = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, $$, COLOR_VIOLET );
      }
      | GREEN {
          $$ = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, $$, COLOR_GREEN );
      }
      | BLUE {
          $$ = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, $$, COLOR_BLUE );
      }
      | YELLOW {
          $$ = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, $$, COLOR_YELLOW );
      }
      | ORANGE {
          $$ = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, $$, COLOR_ORANGE );
      }
      | BROWN {
          $$ = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, $$, COLOR_BROWN );
      }
      | LIGHT RED {
          $$ = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, $$, COLOR_LIGHT_RED );
      }
      | DARK GREY {
          $$ = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, $$, COLOR_DARK_GREY );
      }
      | GREY {
          $$ = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, $$, COLOR_GREY );
      }
      | LIGHT GREEN {
          $$ = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, $$, COLOR_LIGHT_GREEN );
      }
      | LIGHT BLUE {
          $$ = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, $$, COLOR_LIGHT_BLUE );
      }
      | LIGHT GREY {
          $$ = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, $$, COLOR_LIGHT_GREY );
      }
      | DARK BLUE {
          $$ = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, $$, COLOR_DARK_BLUE );
      }
      | MAGENTA {
          $$ = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, $$, COLOR_MAGENTA );
      }
      | PURPLE {
          $$ = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, $$, COLOR_PURPLE );
      }
      | LAVENDER {
          $$ = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, $$, COLOR_LAVENDER );
      }
      | GOLD {
          $$ = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, $$, COLOR_GOLD );
      }
      | TURQUOISE {
          $$ = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, $$, COLOR_TURQUOISE );
      }
      | TAN {
          $$ = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, $$, COLOR_TAN );
      }
      | YELLOW GREEN {
          $$ = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, $$, COLOR_YELLOW_GREEN );
      }
      | OLIVE GREEN {
          $$ = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, $$, COLOR_OLIVE_GREEN );
      }
      | PINK {
          $$ = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, $$, COLOR_PINK );
      }
      | PEACH {
          $$ = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, $$, COLOR_PEACH );
      };

exponential:
    Identifier {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
      OP indexes CP {
        Variable * array = variable_retrieve_or_define( _environment, $1, VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( $1 );
        }
        $$ = variable_move_from_array( _environment, $1 )->name;
    }
    | Identifier DOLLAR {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     } 
      OP indexes CP {
        Variable * array = variable_retrieve_or_define( _environment, $1, VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( $1 );
        }
        $$ = variable_move_from_array( _environment, $1 )->name;
    }
    | Identifier {
        $$ = variable_retrieve_or_define( _environment, $1, VT_WORD, 0 )->name;
      }
    | Identifier DOLLAR { 
        $$ = variable_retrieve_or_define( _environment, $1, VT_STRING, 0 )->name;
      }
    | Integer { 
        if ( $1 < 0 ) {
            $$ = variable_temporary( _environment, VT_SWORD, "(signed integer value)" )->name;
            variable_store( _environment, $$, $1 );
        } else {
            $$ = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
            variable_store( _environment, $$, $1 );
        }
      }
    | MINUS Integer { 
        $$ = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, $$, -$2 );
      }
    | String { 
        outline1("; (expr string: \"%s\")", $1 );
        $$ = variable_temporary( _environment, VT_STRING, "(string value)" )->name;
        outline1("; %s", $$ );
        variable_store_string( _environment, $$, $1 );
        outline2("; variable stored: %s = %s", $$, $1 );
      }
    | OP BYTE CP Integer { 
        $$ = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, $$, $4 );
      }
    | OP SIGNED BYTE CP Integer { 
        $$ = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, $$, $5 );
      }
    | OP WORD CP Integer { 
        $$ = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, $$, $4 );
      }
    | OP SIGNED WORD CP Integer { 
        $$ = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, $$, $5 );
      }
    | OP DWORD CP Integer { 
        $$ = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, $$, $4 );
      }
    | OP SIGNED DWORD CP Integer { 
        $$ = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, $$, $5 );
      }
    | OP POSITION CP Integer { 
        $$ = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, $$, $4 );
      }
    | OP COLOR CP Integer { 
        $$ = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, $$, $4 );
      }
    | color_enumeration { 
        $$ = $1;
      }
    | PEEK OP expr CP {
        $$ = peek_var( _environment, $3 )->name;
      }
    | XPEN {
        $$ = xpen( _environment )->name;
      }
    | YPEN {
        $$ = ypen( _environment )->name;
      }
    | COLLISION OP direct_integer CP {
        $$ = collision_to( _environment, $3 )->name;
      }      
    | COLLISION OP expr CP {
        $$ = collision_to_vars( _environment, $3 )->name;
      }      
    | HIT OP direct_integer CP {
        $$ = collision_to( _environment, $3 )->name;
      }      
    | HIT OP expr CP {
        $$ = collision_to_vars( _environment, $3 )->name;
      }      
    | LEFT OP expr COMMA expr CP {
        $$ = variable_string_left( _environment, $3, $5 )->name;
    }
    | RIGHT OP expr COMMA expr CP {
        $$ = variable_string_right( _environment, $3, $5 )->name;
    }
    | MID OP expr COMMA expr CP {
        $$ = variable_string_mid( _environment, $3, $5, NULL )->name;
    }
    | MID OP expr COMMA expr COMMA expr CP {
        $$ = variable_string_mid( _environment, $3, $5, $7 )->name;
    }
    | INSTR OP expr COMMA expr CP {
        $$ = variable_string_instr( _environment, $3, $5, NULL )->name;
    }
    | INSTR OP expr COMMA expr COMMA expr CP {
        $$ = variable_string_instr( _environment, $3, $5, $7 )->name;
    }
    | UPPER OP expr CP {
        $$ = variable_string_upper( _environment, $3 )->name;
    }
    | LOWER OP expr CP {
        $$ = variable_string_lower( _environment, $3 )->name;
    }
    | STR OP expr CP {
        $$ = variable_string_str( _environment, $3 )->name;
    }
    | BIN OP expr CP {
        $$ = variable_bin( _environment, $3, NULL )->name;
    }
    | BIN OP expr COMMA expr CP {
        $$ = variable_bin( _environment, $3, $5 )->name;
    }
    | SPACE OP expr CP {
        $$ = variable_string_space( _environment, $3 )->name;
    }
    | FLIP OP expr CP {
        $$ = variable_string_flip( _environment, $3 )->name;
    }
    | CHR OP expr CP {
        $$ = variable_string_chr( _environment, $3 )->name;
    }
    | ASC OP expr CP {
        $$ = variable_string_asc( _environment, $3 )->name;
    }
    | LEN OP expr CP {
        $$ = variable_string_len( _environment, $3 )->name;
    }
    | STRING OP expr COMMA expr CP {
        $$ = variable_string_string( _environment, $3, $5 )->name;
    }
    | VAL OP expr CP {
        $$ = variable_string_val( _environment, $3 )->name;
    }
    | RANDOM random_definition {
        $$ = $2;
    }
    | RND OP expr CP {
        $$ = rnd( _environment, $3 )->name;
    }
    | OP expr CP {
        $$ = $2;
    }
    | MAX OP expr COMMA expr CP {
        $$ = maximum( _environment, $3, $5 )->name;
    }
    | MIN OP expr COMMA expr CP {
        $$ = minimum( _environment, $3, $5 )->name;
    }
    | PARAM OP Identifier CP {
        $$ = param_procedure( _environment, $3 )->name;
    }
    | PARAM DOLLAR OP Identifier CP {
        $$ = param_procedure( _environment, $4 )->name;
    }
    | Identifier OSP {
      ((struct _Environment *)_environment)->parameters = 0;
    } values CSP {
      call_procedure( _environment, $1 );
      $$ = param_procedure( _environment, $1 )->name;
    }
    | SGN OP expr CP {
        $$ = sign( _environment, $3 )->name;
    }
    | ABS OP expr CP {
        $$ = absolute( _environment, $3 )->name;
    }
    | TRUE {
        $$ = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, $$, 255 );
    }
    | FALSE {
        $$ = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, $$, 255 );
    }
    | COLORS {
        $$ = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, $$, 16 );
    }
    | PEN COLORS {
        $$ = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, $$, COLOR_COUNT );
    }
    | PEN DEFAULT {
        $$ = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, $$, COLOR_WHITE );
    }
    | DEFAULT PEN {
        $$ = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, $$, COLOR_WHITE );
    }
    | PAPER COLORS {
        $$ = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, $$, COLOR_COUNT );
    }
    | PAPER DEFAULT {
        $$ = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, $$, COLOR_BLACK );
    }
    | DEFAULT PAPER {
        $$ = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, $$, COLOR_BLACK );
    }
    | WIDTH {
        $$ = screen_get_width( _environment )->name;
    }
    | HEIGHT {
        $$ = screen_get_height( _environment )->name;
    }
    | TIMER {
        $$ = get_timer( _environment )->name;
    }
    | PEN DOLLAR OP expr CP {
        $$ = text_get_pen( _environment, $4 )->name;
    }
    | PAPER DOLLAR OP expr CP {
        $$ = text_get_paper( _environment, $4 )->name;
    }
    | CMOVE DOLLAR OP expr COMMA expr CP {
        $$ = text_get_cmove( _environment, $4, $6 )->name;
    }
    | CUP DOLLAR {
        $$ = text_get_cmove_direct( _environment, 0, -1 )->name;
    }
    | CDOWN DOLLAR {
        $$ = text_get_cmove_direct( _environment, 0, 1 )->name;
    }
    | CLEFT DOLLAR {
        $$ = text_get_cmove_direct( _environment, -1, 0 )->name;
    }
    | CRIGHT DOLLAR {
        $$ = text_get_cmove_direct( _environment, 1, 0 )->name;
    }
    | AT DOLLAR OP expr COMMA expr CP {
        $$ = text_get_at( _environment, $4, $6 )->name;
    }
    | LOCATE DOLLAR OP expr COMMA expr CP {
        $$ = text_get_at( _environment, $4, $6 )->name;
    }
    | TAB DOLLAR {
        $$ = text_get_tab( _environment )->name;
    }
    | XCURS {
        $$ = text_get_xcurs( _environment )->name;
    }
    | YCURS {
        $$ = text_get_ycurs( _environment )->name;
    }
    | TEXTADDRESS {
        $$ = strdup( "TEXTADDRESS" );
    }
    | JOY OP expr CP {
        $$ = joy( _environment, $3 )->name;
    }
    | JUP OP expr CP {
        $$ = joy_direction( _environment, $3, JOY_UP )->name;
    }
    | JDOWN OP expr CP {
        $$ = joy_direction( _environment, $3, JOY_DOWN )->name;
    }
    | JLEFT OP expr CP {
        $$ = joy_direction( _environment, $3, JOY_LEFT )->name;
    }
    | JRIGHT OP expr CP {
        $$ = joy_direction( _environment, $3, JOY_RIGHT )->name;
    }
    | JFIRE OP expr CP {
        $$ = joy_direction( _environment, $3, JOY_FIRE )->name;
    }
    | FIRE OP expr CP {
        $$ = joy_direction( _environment, $3, JOY_FIRE )->name;
    }
    | JOY COUNT {
        $$ = variable_temporary( _environment, VT_BYTE, "(JOYCOUNT)" )->name;
        variable_store( _environment, $$, JOY_COUNT );
    }
    | JOYCOUNT {
        $$ = variable_temporary( _environment, VT_BYTE, "(JOYCOUNT)" )->name;
        variable_store( _environment, $$, JOY_COUNT );
    }
    | BIT OP expr COMMA expr CP {
        $$ = variable_bit( _environment, $3, $5 )->name;
    }
    | UP {
        $$ = variable_temporary( _environment, VT_BYTE, "(UP)" )->name;
        variable_store( _environment, $$, JOY_UP );
    }
    | DOWN {
        $$ = variable_temporary( _environment, VT_BYTE, "(DOWN)" )->name;
        variable_store( _environment, $$, JOY_DOWN );
    }
    | LEFT {
        $$ = variable_temporary( _environment, VT_BYTE, "(LEFT)" )->name;
        variable_store( _environment, $$, JOY_LEFT );
    }
    | RIGHT {
        $$ = variable_temporary( _environment, VT_BYTE, "(RIGHT)" )->name;
        variable_store( _environment, $$, JOY_RIGHT );
    }
    | FIRE {
        $$ = variable_temporary( _environment, VT_BYTE, "(FIRE)" )->name;
        variable_store( _environment, $$, JOY_FIRE );
    }
    | INKEY {
        $$ = inkey( _environment )->name;
    }
    | SCANCODE {
        $$ = scancode( _environment )->name;
    }
    | SCAN CODE {
        $$ = scancode( _environment )->name;
    }
    | SCANSHIFT {
        $$ = scanshift( _environment )->name;
    }
    | SCAN SHIFT {
        $$ = scanshift( _environment )->name;
    }
    | LEFT SHIFT {
        $$ = variable_temporary( _environment, VT_BYTE, "(SHIFT LEFT)" )->name;
        variable_store( _environment, $$, SHIFT_LEFT );
    }
    | RIGHT SHIFT {
        $$ = variable_temporary( _environment, VT_BYTE, "(SHIFT RIGHT)" )->name;
        variable_store( _environment, $$, SHIFT_RIGHT );
    }
    ;

position:   POSITION | AT;

bank_definition_simple:
  AT direct_integer {
      bank_define( _environment, NULL, BT_DATA, $2, NULL );
  }
  | Identifier AT direct_integer {
      bank_define( _environment, $1, BT_DATA, $3, NULL );
  }
  | AT direct_integer AS DATA {
      bank_define( _environment, NULL, BT_DATA, $2, NULL );
  }
  | Identifier AT direct_integer AS DATA {
      bank_define( _environment, $1, BT_DATA, $3, NULL );
  }
  | DATA Identifier AT direct_integer {
      bank_define( _environment, $2, BT_DATA, $4, NULL );
  }
  | DATA AT direct_integer {
      bank_define( _environment, NULL, BT_DATA, $3, NULL );
  }

  | Identifier AT direct_integer AS CODE {
      bank_define( _environment, $1, BT_CODE, $3, NULL );
  }
  | AT direct_integer AS CODE {
      bank_define( _environment, NULL, BT_CODE, $2, NULL );
  }
  | CODE Identifier AT direct_integer {
      bank_define( _environment, $2, BT_CODE, $4, NULL );
  }
  | CODE AT direct_integer {
      bank_define( _environment, NULL, BT_CODE, $3, NULL );
  }

  | AT direct_integer AS VARIABLES {
      bank_define( _environment, NULL, BT_VARIABLES, $2, NULL );
  }
  | Identifier AT direct_integer AS VARIABLES {
      bank_define( _environment, $1, BT_VARIABLES, $3, NULL );
  }
  | VARIABLES Identifier AT direct_integer {
      bank_define( _environment, $2, BT_VARIABLES, $4, NULL );
  }
  | VARIABLES AT direct_integer {
      bank_define( _environment, NULL, BT_VARIABLES, $3, NULL );
  }

  | Identifier AT direct_integer AS TEMPORARY {
      bank_define( _environment, $1, BT_TEMPORARY, $3, NULL );
  }
  | AT direct_integer AS TEMPORARY {
      bank_define( _environment, NULL, BT_TEMPORARY, $2, NULL );
  }
  | TEMPORARY Identifier AT direct_integer {
      bank_define( _environment, $2, BT_TEMPORARY, $4, NULL );
  }
  | TEMPORARY AT direct_integer {
      bank_define( _environment, NULL, BT_TEMPORARY, $3, NULL );
  }  
  ;

bank_definition_with_payload:
  Identifier AT direct_integer WITH String {
      bank_define( _environment, $1, BT_DATA, $3, $5 );
  }
  | Identifier AT direct_integer AS DATA WITH String {
      bank_define( _environment, $1, BT_DATA, $3, $7 );
  }
  | DATA Identifier AT direct_integer WITH String {
      bank_define( _environment, $2, BT_DATA, $4, $6 );
  }
  | Identifier AT direct_integer AS CODE WITH String {
      bank_define( _environment, $1, BT_CODE, $3, $7 );
  }
  | CODE Identifier AT direct_integer WITH String {
      bank_define( _environment, $2, BT_CODE, $4, $6 );
  };

bank_definition: 
    bank_definition_simple
  | bank_definition_with_payload;

raster_definition_simple:
    Identifier AT direct_integer {
      raster_at( _environment, $1, $3 );
    }
  | AT direct_integer WITH Identifier {
      raster_at( _environment, $4, $2 );
    };

raster_definition_expression:
    Identifier AT expr {
      raster_at_var( _environment, $1, $3 );
    }
  | AT expr WITH Identifier {
      raster_at_var( _environment, $2, $4 );
    };

raster_definition:
    raster_definition_simple
  | raster_definition_expression;

next_raster_definition_simple:
    Identifier AT direct_integer {
      next_raster_at_with( _environment, $3, $1 );
    }
  | AT direct_integer WITH Identifier {
      next_raster_at_with( _environment, $2, $4 );
    };

next_raster_definition_expression:
    Identifier AT expr {
      next_raster_at_with_var( _environment, $3, $1 );
    }
  | AT expr WITH Identifier {
      next_raster_at_with_var( _environment, $2, $4 );
    };

next_raster_definition:
    next_raster_definition_simple
  | next_raster_definition_expression;

color_definition_simple:
    BORDER direct_integer {
      color_border( _environment, $2 );
  }
  | BACKGROUND direct_integer TO direct_integer {
      color_background( _environment, $2, $4 );
  }
  | SPRITE direct_integer TO direct_integer {
      color_sprite( _environment, $2, $4 );
  };

color_definition_expression:
    BORDER expr {
      color_border_var( _environment, $2 );
  }
  | BACKGROUND expr TO expr {
      color_background_vars( _environment, $2, $4 );
  }
  | SPRITE expr TO expr {
      color_sprite_vars( _environment, $2, $4 );
  };

color_definition:
    color_definition_simple
  | color_definition_expression;

milliseconds:
    MS
    | MILLISECOND
    | MILLISECONDS;

wait_definition_simple:
      direct_integer CYCLES {
      wait_cycles( _environment, $1 );
    }
    | direct_integer TICKS {
      wait_ticks( _environment, $1 );
    }
    | direct_integer milliseconds {
      wait_milliseconds( _environment, $1 );
    };

wait_definition_expression:
      expr CYCLES {
      wait_cycles_var( _environment, $1 );
    }
    | expr TICKS {
      wait_ticks_var( _environment, $1 );
    }
    | expr milliseconds {
      wait_milliseconds_var( _environment, $1 );
    }
    ;

wait_definition:
    wait_definition_simple
  | wait_definition_expression;

sprite_definition_simple:
    direct_integer DATA FROM direct_integer {
      sprite_data_from( _environment, $1, $4 );
  }
  | direct_integer MULTICOLOR {
      sprite_multicolor( _environment, $1 );
  }
  | direct_integer MONOCOLOR {
      sprite_monocolor( _environment, $1 );
  }
  | direct_integer COLOR direct_integer {
      sprite_color( _environment, $1, $3 );
  }
  | direct_integer position OP direct_integer COMMA direct_integer CP {
      sprite_position( _environment, $1, $4, $6 );
  }
  | direct_integer ENABLE {
      sprite_enable( _environment, $1 );
  }
  | direct_integer DISABLE {
      sprite_disable( _environment, $1 );
  }
  | direct_integer EXPAND VERTICAL {
      sprite_expand_vertical( _environment, $1 );
  }
  | direct_integer COMPRESS VERTICAL {
      sprite_compress_vertical( _environment, $1 );
  }
  | direct_integer VERTICAL EXPAND {
      sprite_expand_vertical( _environment, $1 );
  }
  | direct_integer VERTICAL COMPRESS {
      sprite_compress_vertical( _environment, $1 );
  }
  | direct_integer EXPAND HORIZONTAL {
      sprite_expand_horizontal( _environment, $1 );
  }
  | direct_integer COMPRESS HORIZONTAL {
      sprite_compress_horizontal( _environment, $1 );
  }
  | direct_integer HORIZONTAL EXPAND {
      sprite_expand_horizontal( _environment, $1 );
  }
  | direct_integer HORIZONTAL COMPRESS {
      sprite_compress_horizontal( _environment, $1 );
  };

sprite_definition_expression:
    expr DATA FROM expr {
      sprite_data_from_vars( _environment, $1, $4 );
  }
  | expr MULTICOLOR {
      sprite_multicolor_var( _environment, $1 );
  }
  | expr MONOCOLOR {
      sprite_monocolor_var( _environment, $1 );
  }
  | expr COLOR expr {
      sprite_color_vars( _environment, $1, $3 );
  }
  | expr position OP expr COMMA expr CP {
      sprite_position_vars( _environment, $1, $4, $6 );
  }
  | expr ENABLE {
      sprite_enable_var( _environment, $1 );
  }
  | expr DISABLE {
      sprite_disable_var( _environment, $1 );
  }
  | expr EXPAND VERTICAL {
      sprite_expand_vertical_var( _environment, $1 );
  }
  | expr COMPRESS VERTICAL {
      sprite_compress_vertical_var( _environment, $1 );
  }
  | expr VERTICAL EXPAND {
      sprite_expand_vertical_var( _environment, $1 );
  }
  | expr VERTICAL COMPRESS {
      sprite_compress_vertical_var( _environment, $1 );
  }
  | expr EXPAND HORIZONTAL {
      sprite_expand_horizontal_var( _environment, $1 );
  }
  | expr COMPRESS HORIZONTAL {
      sprite_compress_horizontal_var( _environment, $1 );
  }
  | expr HORIZONTAL EXPAND {
      sprite_expand_horizontal_var( _environment, $1 );
  }
  | expr HORIZONTAL COMPRESS {
      sprite_compress_horizontal_var( _environment, $1 );
  };

sprite_definition:
    sprite_definition_simple
  | sprite_definition_expression;

bitmap_definition_simple:
    AT direct_integer {
      bitmap_at( _environment, $2 );
  } 
  | ENABLE {
      bitmap_enable( _environment );
  }
  | DISABLE {
      bitmap_disable( _environment );
  }
  | CLEAR {
      bitmap_clear( _environment );
  }
  | CLEAR WITH direct_integer {
      bitmap_clear_with( _environment, $3 );
  }
  ;

bitmap_definition_expression:
    AT expr {
      bitmap_at_var( _environment, $2 );
  }
  | CLEAR WITH expr {
      bitmap_clear_with_vars( _environment, $3 );
  }
  ;

bitmap_definition:
    bitmap_definition_simple
  | bitmap_definition_expression;

textmap_definition_simple:
    AT direct_integer {
      textmap_at( _environment, $2 );
  };

textmap_definition_expression:
    AT expr {
      textmap_at_var( _environment, $2 );
  };

textmap_definition:
    textmap_definition_simple
  | textmap_definition_expression;

text_definition_simple:
    ENABLE {
      text_enable( _environment );
  }
  | DISABLE {
      text_disable( _environment );
  };

text_definition_expression:
     AT expr COMMA expr COMMA expr {
       text_at( _environment, $2, $4, $6 );
   }
   | expr COMMA expr COMMA expr {
       text_at( _environment, $1, $3, $5 );
   };

text_definition:
    text_definition_simple
  | text_definition_expression;

tiles_definition_simple:
    AT direct_integer {
      tiles_at( _environment, $2 );
  };

tiles_definition_expression:
    AT expr {
      tiles_at_var( _environment, $2 );
  };

tiles_definition:
    tiles_definition_simple
  | tiles_definition_expression;

colormap_definition_simple:
    AT direct_integer {
      colormap_at( _environment, $2 );
  }
  | CLEAR {
      colormap_clear( _environment );
  }
  | CLEAR WITH direct_integer ON direct_integer {
      colormap_clear_with( _environment, $3, $5 );
  };

colormap_definition_expression:
    AT expr {
      colormap_at_var( _environment, $2 );
  }
  | CLEAR WITH expr ON expr {
      colormap_clear_with_vars( _environment, $3, $5 );
  };
  ;

colormap_definition:
    colormap_definition_simple
  | colormap_definition_expression;

screen_definition_simple:
    ON {   
      screen_on( _environment );
  }
  | OFF {
      screen_off( _environment );
  }
  | ROWS direct_integer {
      screen_rows( _environment, $2 );
  }
  | VERTICAL SCROLL direct_integer {
      screen_vertical_scroll( _environment, $3 );
  }
  | HORIZONTAL SCROLL direct_integer {
      screen_horizontal_scroll( _environment, $3 );
  };

screen_definition_expression:
    ROWS expr {
      screen_rows_var( _environment, $2 );
  }
  | VERTICAL SCROLL expr {
      screen_vertical_scroll_var( _environment, $3 );
  }
  | HORIZONTAL SCROLL expr {
      screen_horizontal_scroll_var( _environment, $3 );
  };

screen_definition:
    screen_definition_simple
  | screen_definition_expression;

var_definition_simple:
  | Identifier ON Identifier {
      variable_retrieve_or_define( _environment, $1, VT_BYTE, 0 );
  }
  | Identifier DOLLAR ON Identifier {
      variable_retrieve_or_define( _environment, $1, VT_STRING, 0 );
  }
  | Identifier ON Identifier ASSIGN direct_integer {
      variable_retrieve_or_define( _environment, $1, VT_BYTE, $5 );
  }
  | Identifier ON Identifier ASSIGN expr {
      Variable * v = variable_retrieve( _environment, $5 );
      Variable * d = variable_retrieve_or_define( _environment, $1, v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
  | Identifier DOLLAR ON Identifier ASSIGN expr {
      Variable * v = variable_retrieve( _environment, $6 );
      Variable * d = variable_retrieve_or_define( _environment, $1, VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  };

goto_definition:
    Identifier {
      goto_label( _environment, $1 );
  }
  | Integer {
      goto_number( _environment, $1 );
  }
  ;

gosub_definition:
    Identifier {
      gosub_label( _environment, $1 );
  }
  | Integer {
      gosub_number( _environment, $1 );
  }
  ;

var_definition:
    var_definition_simple;

point_definition_simple:
      AT OP direct_integer COMMA direct_integer CP {
        point_at( _environment, $3, $5 );
    }
    ;

point_definition_expression:
      AT OP expr COMMA expr CP {
        point_at_vars( _environment, $3, $5 );
    };

point_definition:
    point_definition_simple
  | point_definition_expression;

ink_definition:
    expr {
        ink( _environment, $1 );
    }

on_goto_definition:
      Identifier {
          on_goto_index( _environment, $1 );
          on_goto_end( _environment );
      }
    | Identifier {
        on_goto_index( _environment, $1 );
    } COMMA on_goto_definition;

on_gosub_definition:
      Identifier {
          on_gosub_index( _environment, $1 );
          on_gosub_end( _environment );
      }
    | Identifier {
          on_gosub_index( _environment, $1 );
    } COMMA on_gosub_definition;

on_proc_definition:
      Identifier {
          on_proc_index( _environment, $1 );
          on_proc_end( _environment );
      }
    | Identifier {
          on_proc_index( _environment, $1 );
    } COMMA on_proc_definition;

on_definition:
      expr GOTO {
          on_goto( _environment, $1 );
      } on_goto_definition
    | expr PROC {
          on_proc( _environment, $1 );
      } on_proc_definition
    | expr GOSUB {
        on_gosub( _environment, $1 );  
    } on_gosub_definition;

every_definition :
      expr TICKS GOSUB Identifier {
          every_ticks_gosub( _environment, $1, $4 );
    }
    | ON {
          every_on( _environment );
    }
    | OFF {
          every_off( _environment );
    };

add_definition :
    Identifier COMMA expr {
        variable_move_naked( _environment, variable_add( _environment, $1, $3 )->name, $1 );
    }
    | Identifier COMMA expr COMMA expr TO expr {
        add_complex( _environment, $1, $3, $5, $7 );
    }
    ;

dimensions :
      Integer {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = $1;
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
    | Integer COMMA dimensions {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = $1;
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
    ;

datatype : 
    BYTE {
        $$ = VT_BYTE;
    }
    | SIGNED BYTE {
        $$ = VT_SBYTE;
    }
    | WORD {
        $$ = VT_WORD;
    }
    | SIGNED WORD {
        $$ = VT_SWORD;
    }
    | DWORD {
        $$ = VT_DWORD;
    }
    | SIGNED DWORD {
        $$ = VT_SDWORD;
    }
    | ADDRESS {
        $$ = VT_ADDRESS;
    }
    | POSITION {
        $$ = VT_POSITION;
    }
    | COLOR {
        $$ = VT_COLOR;
    }
    | STRING {
        $$ = VT_STRING;
    };
    
dim_definition :
      Identifier {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      } OP dimensions CP {
        variable_retrieve_or_define( _environment, $1, VT_ARRAY, 0 );
        variable_array_type( _environment, $1, VT_WORD );
        variable_reset( _environment );
    }
    | Identifier {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      } DOLLAR OP dimensions CP {
        variable_retrieve_or_define( _environment, $1, VT_ARRAY, 0 );
        variable_array_type( _environment, $1, VT_STRING );
        variable_reset( _environment );
    }
    | Identifier datatype {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      } OP dimensions CP {
        variable_retrieve_or_define( _environment, $1, VT_ARRAY, 0 );
        variable_array_type( _environment, $1, $2 );
        variable_reset( _environment );
    }
    ;

dim_definitions :
      dim_definition
    | dim_definition COMMA dim_definitions
    ;

indexes :
      expr {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( $1 );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
    | expr COMMA indexes {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( $1 );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
    ;

parameters : 
      Identifier {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
    | Identifier DOLLAR {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
    | Identifier AS datatype {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = $3;
          ++((struct _Environment *)_environment)->parameters;
    }
    | Identifier COMMA parameters {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
    | Identifier DOLLAR COMMA parameters {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
    | Identifier AS datatype COMMA parameters {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = $3;
          ++((struct _Environment *)_environment)->parameters;
    }
    ;

parameters_expr : 
      Identifier {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
    | Identifier DOLLAR {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
    | Identifier AS datatype {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = $3;
          ++((struct _Environment *)_environment)->parameters;
    }
    | Identifier COMMA parameters_expr {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
    | Identifier DOLLAR COMMA parameters_expr {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
    | Identifier AS datatype COMMA parameters_expr {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = $3;
          ++((struct _Environment *)_environment)->parameters;
    }
    | String {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ++((struct _Environment *)_environment)->parameters;
    }
    | String COMMA parameters_expr {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ++((struct _Environment *)_environment)->parameters;
    }
    ;

values : 
      expr {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ++((struct _Environment *)_environment)->parameters;
    }
    | expr COMMA values {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ++((struct _Environment *)_environment)->parameters;
    }
    ;

print_definition :
    expr {
        print( _environment, $1, 1 );
    }
  | expr COMMA {
        print( _environment, $1, 0 );
        print_tab( _environment, 0 );
  }
  | expr SEMICOLON {
        print( _environment, $1, 0 );
  }
  | expr COMMA {
        print( _environment, $1, 0 );
        print_tab( _environment, 0 );
  }  print_definition
  | expr SEMICOLON  {
        print( _environment, $1, 0 );
  } print_definition
  ;

writing_mode_definition : 
      REPLACE {
          $$ = variable_temporary( _environment, VT_BYTE, "(writing REPLACE)" )->name;
          variable_store( _environment, $$, WRITING_REPLACE );
    }
    | OR {
          $$ = variable_temporary( _environment, VT_BYTE, "(writing OR)" )->name;
          variable_store( _environment, $$, WRITING_OR );
    }
    | XOR {
          $$ = variable_temporary( _environment, VT_BYTE, "(writing XOR)" )->name;
          variable_store( _environment, $$, WRITING_XOR );
    }
    | AND {
          $$ = variable_temporary( _environment, VT_BYTE, "(writing AND)" )->name;
          variable_store( _environment, $$, WRITING_AND );
    }
    | IGNORE {
          $$ = variable_temporary( _environment, VT_BYTE, "(writing IGNORE)" )->name;
          variable_store( _environment, $$, WRITING_IGNORE );
    }
    ;

writing_part_definition :
      NORMAL {
          $$ = variable_temporary( _environment, VT_BYTE, "(writing NORMAL)" )->name;
          variable_store( _environment, $$, WRITING_NORMAL );
    }
    | PAPER {
          $$ = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, $$, WRITING_PAPER );
    }
    | PAPER ONLY {
          $$ = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, $$, WRITING_PAPER );
    }
    | PEN {
          $$ = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, $$, WRITING_PEN );
    }
    | PEN ONLY {
          $$ = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, $$, WRITING_PEN );
    }
    ;

writing_definition : 
    writing_mode_definition COMMA writing_part_definition {
        text_writing( _environment, $1, $3 );
    }
    ;

locate_definition : 
     COMMA expr {
        text_locate( _environment, NULL, $2 );
    }
    | expr COMMA {
        text_locate( _environment, $1, NULL );
    } 
    | expr COMMA expr {
        text_locate( _environment, $1, $3 );
    }
    ;

cmove_definition : 
     COMMA expr {
        text_cmove( _environment, NULL, $2 );
    }
    | expr COMMA {
        text_cmove( _environment, $1, NULL );
    } 
    | expr COMMA expr {
        text_cmove( _environment, $1, $3 );
    }
    ;

hscroll_definition : 
    LEFT {
        text_hscroll_line( _environment, -1 );
    }
    | SCREEN LEFT {
        text_hscroll_screen( _environment, -1 );
    }
    | RIGHT {
        text_hscroll_line( _environment, 1 );
    }
    | SCREEN RIGHT {
        text_hscroll_screen( _environment, 1 );
    }
    ;

vscroll_definition : 
      SCREEN UP {
        text_vscroll_screen( _environment, -1 );
    }
    | SCREEN DOWN {
        text_vscroll_screen( _environment, 1 );
    }
    ;

statement:
    BANK bank_definition
  | RASTER raster_definition
  | NEXT RASTER next_raster_definition
  | COLOR color_definition
  | WAIT wait_definition
  | SPRITE sprite_definition
  | BITMAP bitmap_definition
  | TEXTMAP textmap_definition
  | TEXT text_definition
  | TILES tiles_definition
  | COLORMAP colormap_definition
  | SCREEN screen_definition
  | POINT point_definition
  | INK ink_definition
  | VAR var_definition
  | TEXTADDRESS ASSIGN expr {
      variable_move( _environment, $3, "ADDRESS" );
  }
  | ADD add_definition
  | PRINT print_definition
  | QM print_definition
  | LOCATE locate_definition
  | MEMORIZE {
      text_memorize( _environment );
  }
  | REMEMBER {
      text_remember( _environment );
  }
  | HSCROLL hscroll_definition
  | VSCROLL vscroll_definition
  | CMOVE cmove_definition
  | CUP {
      text_cmove_direct( _environment, 0, -1 );
  }
  | CDOWN {
      text_cmove_direct( _environment, 0, 1 );
  }
  | CLEFT {
      text_cmove_direct( _environment, -1, 0 );
  }
  | CRIGHT {
      text_cmove_direct( _environment, 1, 0 );
  }
  | CLINE {
      text_cline( _environment, NULL );
  }
  | CLINE expr {
      text_cline( _environment, $2 );
  }
  | SET TAB expr {
      text_set_tab( _environment, $3 );
  }
  | CENTER expr {
      text_center( _environment, $2 );
  }
  | CENTRE expr {
      text_center( _environment, $2 );
  }
  | CLS {
      text_cls( _environment );
  }
  | HOME {
      text_home( _environment );
  }
  | INC Identifier {
      variable_increment( _environment, $2 );
  }
  | DEC Identifier {
      variable_decrement( _environment, $2 );
  }
  | RANDOMIZE {
      randomize( _environment, NULL );
  }
  | RANDOMIZE expr {
      randomize( _environment, $2 );
  }
  | IF expr THEN {
      if_then( _environment, $2 );  
  }
  | ELSE {
      else_if_then( _environment, NULL );  
  }
  | ELSE IF expr THEN {
      else_if_then( _environment, $3 );  
  }
  | ENDIF {
      end_if_then( _environment );  
  }
  | DO {
      begin_loop( _environment );  
  }
  | LOOP {
      end_loop( _environment );  
  }
  | WHILE { 
      begin_while( _environment );  
  } expr {
      begin_while_condition( _environment, $3 );  
  }
  | WEND {
      end_while( _environment );  
  }
  | REPEAT {
      begin_repeat( _environment );  
  }
  | UNTIL expr {
      end_repeat( _environment, $2 );  
  }
  | EXIT {
      exit_loop( _environment, 0 );  
  }
  | EXIT PROC {
      exit_procedure( _environment );
  }
  | POP PROC {
      exit_procedure( _environment );
  }
  | EXIT IF expr {
      exit_loop_if( _environment, $3, 0 );  
  }
  | EXIT Integer {
      exit_loop( _environment, $2 );  
  }
  | EXIT direct_integer {
      exit_loop( _environment, $2 );  
  }
  | EXIT IF expr COMMA Integer {
      exit_loop_if( _environment, $3, $5 );  
  }
  | EXIT IF expr COMMA direct_integer {
      exit_loop_if( _environment, $3, $5 );  
  }
  | FOR Identifier ASSIGN expr TO expr {
      begin_for( _environment, $2, $4, $6 );  
  }
  | NEXT {
      end_for( _environment );
  }
  | PROCEDURE Identifier {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, $2 );
  }
  | PROCEDURE Identifier {
      ((struct _Environment *)_environment)->parameters = 0;
    } OSP parameters CSP {
      begin_procedure( _environment, $2 );
  }
  | SHARED parameters_expr {
      shared( _environment );
  }
  | GLOBAL parameters_expr {
      global( _environment );
  }
  | END PROC {
      end_procedure( _environment, NULL );
  }
  | END PROC OSP expr CSP {
      end_procedure( _environment, $4 );
  }
  | FOR Identifier ASSIGN expr TO expr STEP expr {
      begin_for_step( _environment, $2, $4, $6, $8 );  
  }
  | Identifier " " {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, $1 );
  }
  | PROC Identifier {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, $2 );
  }
  | CALL Identifier {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, $2 );
  }
  | Identifier OSP {
      ((struct _Environment *)_environment)->parameters = 0;
    } values CSP {
      call_procedure( _environment, $1 );
  }
  | PROC Identifier OSP {
      ((struct _Environment *)_environment)->parameters = 0;
    } values CSP {
      call_procedure( _environment, $2 );
  }
  | CALL Identifier OSP {
      ((struct _Environment *)_environment)->parameters = 0;
    } values CSP {
      call_procedure( _environment, $2 );
  }
  | PEN expr {
      text_pen( _environment, $2 );
  }
  | PAPER expr {
      text_paper( _environment, $2 );
  }
  | INVERSE ON {
      CRITICAL_NOT_SUPPORTED("INVERSE");
  }
  | INVERSE OFF {
      CRITICAL_NOT_SUPPORTED("INVERSE");
  }
  | WRITING writing_definition
  | Identifier COLON {
      outhead1("%s:", $1);
  } 
  | BEG GAMELOOP {
      begin_gameloop( _environment );
  }
  | END GAMELOOP {
      end_gameloop( _environment );
  }
  | GRAPHIC {
      graphic( _environment );
  }
  | HALT {
      halt( _environment );
  }
  | END {
      end( _environment );
  }
  | ON on_definition
  | GOTO goto_definition
  | GOSUB gosub_definition
  | EVERY every_definition
  | RETURN {
      return_label( _environment );
  }
  | RETURN expr {
      return_procedure( _environment, $2 );
  }
  | POP {
      pop( _environment );
  }
  | DONE  {
      return 0;
  }
  | LEFT OP expr COMMA expr CP ASSIGN expr {
        variable_string_left_assign( _environment, $3, $5, $8 );
  }
  | RIGHT OP expr COMMA expr CP ASSIGN expr {
        variable_string_right_assign( _environment, $3, $5, $8 );
  }
  | MID OP expr COMMA expr CP ASSIGN expr {
        variable_string_mid_assign( _environment, $3, $5, NULL, $8 );
  }
  | MID OP expr COMMA expr COMMA expr CP ASSIGN expr {
        variable_string_mid_assign( _environment, $3, $5, $7, $10 );
  }
  | DIM dim_definitions
  | Identifier ASSIGN expr {
        outline2("; %s = %s", $1, $3 );
        Variable * expr = variable_retrieve( _environment, $3 );
        outline1("; retrieved %s ", $3 );
        variable_retrieve_or_define( _environment, $1, expr->type, 0 )->name;
        outline1("; defined %s ", $1 );
        variable_move( _environment, $3, $1 );
        outline2("; moved %s -> %s ", $3, $1 );
  }
  | Identifier DOLLAR ASSIGN expr {
        outline2("; %s = %s", $1, $4 );
        Variable * expr = variable_retrieve( _environment, $4 );
        outline1("; retrieved %s ", $4 );
        variable_retrieve_or_define( _environment, $1, VT_STRING, 0 )->name;
        outline1("; defined %s ", $1 );
        variable_move( _environment, $4, $1 );
        outline2("; moved %s -> %s ", $4, $1 );
  }
  | Identifier {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
      OP indexes CP ASSIGN expr {
        Variable * expr = variable_retrieve( _environment, $7 );
        Variable * array = variable_retrieve( _environment, $1 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( $1 );
        }
        variable_move_array( _environment, $1, expr->name );
  }
  | Identifier DOLLAR {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    } OP indexes CP ASSIGN expr {
        Variable * x = variable_retrieve( _environment, $8 );
        Variable * a = variable_retrieve( _environment, $1 );
        if ( x->type != VT_STRING ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[x->type], DATATYPE_AS_STRING[VT_STRING] );
        }
        if ( a->type != VT_ARRAY ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[a->type], DATATYPE_AS_STRING[VT_ARRAY] );
        }
        if ( a->arrayType != VT_STRING ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[a->arrayType], DATATYPE_AS_STRING[VT_STRING] );
        }
        variable_move_array_string( _environment, $1, x->name );
  }
  | Identifier {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    } datatype OP indexes CP ASSIGN expr {
        Variable * x = variable_retrieve( _environment, $8 );
        Variable * a = variable_retrieve( _environment, $1 );
        if ( x->type != $3 ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[x->type], DATATYPE_AS_STRING[$3] );
        }
        if ( a->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( $1 );
        }
        if ( a->arrayType != $3 ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[a->arrayType], DATATYPE_AS_STRING[$3] );
        }
        variable_move_array( _environment, $1, x->name );
  }
  | DEBUG expr {
      debug_var( _environment, $2 );
  }
  | Remark
  |
  ;

statements_no_linenumbers:
      statement { ((Environment *)_environment)->yylineno = yylineno; }
    | statement COLON { ((Environment *)_environment)->yylineno = yylineno; } statements_no_linenumbers
    ;

statements_with_linenumbers:
      Integer {
        outhead1("_linenumber%d:", $1);
    } statements_no_linenumbers { 
        ((Environment *)_environment)->yylineno = yylineno;
    };

statements_complex:
    Identifier NewLine {
        call_procedure( _environment, $1 );
    } statements_complex
    | statements_no_linenumbers
    | statements_no_linenumbers NewLine statements_complex
    | statements_with_linenumbers
    | statements_with_linenumbers NewLine statements_complex
    ;

program : 
  { ((Environment *)_environment)->yylineno = yylineno; } statements_complex;

%%

void show_usage_and_exit( int _argc, char *_argv[] ) {

    printf("ugBASIC Compiler v1.0\n");
    printf("---------------------\n");
    printf("Copyright 2021 Marco Spedaletti (asimov@mclink.it)\n\n");
    printf("Licensed under the Apache License, Version 2.0 (the \"License\");\n");
    printf("you may not use this program except in compliance with the License.\n\n");

    printf("usage: %s [-c <file>] <source> <asm>\n\n", _argv[0] );

    printf("Options and parameters:\n" );
    printf("\t<source>     Input filename with ugBASIC source code" );
    printf("\t<asm>        Output filename with ASM source code" );
    printf("\t-c <file>    Output filename with linker configuration" );
    printf("\t-W           Enable warnings during compilation" );
    exit(EXIT_FAILURE);
}

int main( int _argc, char *_argv[] ) {
    extern FILE *yyin;
    int flags, opt;
    int nsecs, tfnd;
    Environment * _environment = malloc(sizeof(Environment));
    memset( _environment, 0, sizeof(Environment));

    _environment->warningsEnabled = 0;

    while ((opt = getopt(_argc, _argv, "e:c:W")) != -1) {
        switch (opt) {
                case 'c':
                    _environment->configurationFileName = strdup(optarg);
                    break;
                case 'W':
                    _environment->warningsEnabled = 1;
                    break;
                default: /* '?' */
                    show_usage_and_exit( _argc, _argv );
                }
    }

    _environment->sourceFileName = strdup(_argv[optind] );
    _environment->asmFileName = strdup(_argv[optind+1] );
    
    yyin = fopen( _environment->sourceFileName, "r" );
    if ( ! yyin ) {
        fprintf(stderr, "Unable to open source file: %s\n", _environment->sourceFileName );
        exit(EXIT_FAILURE);
    }
    _environment->asmFile = fopen( _environment->asmFileName, "wt");
    if ( ! _environment->asmFile ) {
        fprintf(stderr, "Unable to open output file: %s\n", _environment->asmFileName );
        exit(EXIT_FAILURE);
    }

    bank_define( _environment, "VARIABLES", BT_VARIABLES, 0x5000, NULL );
    bank_define( _environment, "TEMPORARY", BT_TEMPORARY, 0x5100, NULL );

    if ( _environment->configurationFileName ) {
        _environment->configurationFile = fopen( _environment->configurationFileName, "wt");
        if ( ! _environment->configurationFile ) {
            fprintf(stderr, "Unable to open configuration file: %s\n", _environment->configurationFileName );
            exit(EXIT_FAILURE);
        }
        linker_setup( _environment );
        deploy( varsDeployed, "./ugbc/src/hw/c64/vars.asm");
        outhead0(".segment \"CODE\"");
        variable_define( _environment, "stringsAddress", VT_ADDRESS, 0x4200 );
        variable_global( _environment, "stringsAddress" );
        bank_define( _environment, "STRINGS", BT_STRINGS, 0x4200, NULL );
        variable_import( _environment, "TEXTADDRESS", VT_ADDRESS );
        variable_global( _environment, "TEXTADDRESS" );    
        variable_define( _environment, "colormapAddress", VT_ADDRESS, 0xD800 );
        variable_global( _environment, "colormapAddress" );
    } else {
        outhead0("org 32768");
        variable_define( _environment, "stringsAddress", VT_ADDRESS, 0xa000 );
        variable_global( _environment, "stringsAddress" );
        variable_define( _environment, "bitmap_enabled", VT_BYTE, 0 );
        variable_global( _environment, "bitmap_enabled" );
        variable_define( _environment, "bitmapAddress", VT_ADDRESS, 0x4000 );
        variable_global( _environment, "bitmapAddress" );
        variable_define( _environment, "colormapAddress", VT_ADDRESS, 0x5800 );
        variable_global( _environment, "colormapAddress" );
    }

    setup_text_variables( _environment );

    yydebug = 1;
    errors = 0;
    yyparse (_environment);

    gameloop_cleanup( _environment );
    bank_cleanup( _environment );
    variable_cleanup( _environment );

    if ( _environment->configurationFileName ) {
        linker_cleanup( _environment );
        fclose(_environment->configurationFile);
    }

    fclose(_environment->asmFile);

}

int yyerror (Environment * _ignored, const char *s) /* Called by yyparse on error */
{
        // TODO: better error message (like other compilers)
      printf( "*** ERROR: %s at %d\n", s, yylineno);
      exit(EXIT_FAILURE);
}

