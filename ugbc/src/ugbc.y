%{

#include "../src/ugbc.h"

int yylex();
int yyerror(Environment *, const char *);
int yydebug=0;
int errors=0;
extern int yylineno;

int yywrap() { return 1; }
 
extern char DATATYPE_AS_STRING[][16];
extern char OUTPUT_FILE_TYPE_AS_STRING[][16];

#include <math.h>

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
%token OP_SEMICOLON OP_COLON OP_COMMA OP_PLUS OP_MINUS OP_INC OP_DEC OP_EQUAL OP_ASSIGN OP_LT OP_LTE OP_GT OP_GTE 
%token OP_DISEQUAL OP_MULTIPLICATION OP_MULTIPLICATION2 OP_DOLLAR OP_DIVISION OP_DIVISION2 QM HAS IS OF OP_HASH OP_POW OP_ASSIGN_DIRECT

%token RASTER DONE AT COLOR BORDER WAIT NEXT WITH BANK SPRITE DATA FROM OP CP 
%token ENABLE DISABLE HALT ECM BITMAP SCREEN ON OFF ROWS VERTICAL SCROLL VAR AS TEMPORARY 
%token XPEN YPEN PEEK GOTO HORIZONTAL MCM COMPRESS EXPAND LOOP REPEAT WHILE TEXT TILES
%token COLORMAP SELECT MONOCOLOR MULTICOLOR COLLISION IF THEN HIT BACKGROUND TO RANDOM
%token BYTE WORD POSITION CODE VARIABLES MS CYCLES WIDTH HEIGHT DWORD PEN CLEAR
%token BEG END GAMELOOP ENDIF UP DOWN LEFT RIGHT AND RANDOMIZE GRAPHIC TEXTMAP
%token POINT GOSUB RETURN POP OR ELSE NOT TRUE FALSE DO EXIT WEND UNTIL FOR STEP EVERY
%token MID INSTR UPPER LOWER STR VAL STRING SPACE FLIP CHR ASC LEN MOD ADD MIN MAX SGN
%token SIGNED ABS RND COLORS INK TIMER POWERING DIM ADDRESS PROC PROCEDURE CALL OSP CSP
%token SHARED MILLISECOND MILLISECONDS TICKS GLOBAL PARAM PRINT DEFAULT USE
%token PAPER INVERSE REPLACE XOR IGNORE NORMAL WRITING ONLY LOCATE CLS HOME CMOVE
%token CENTER CENTRE TAB SET CUP CDOWN CLEFT CRIGHT CLINE XCURS YCURS MEMORIZE REMEMBER
%token HSCROLL VSCROLL TEXTADDRESS JOY BIN BIT COUNT JOYCOUNT FIRE JUP JDOWN JLEFT JRIGHT JFIRE
%token INKEY SCANCODE SCAN SHIFT SCANSHIFT BOTH SHIFTS NONE LETTER ASTERISK COLON COMMA 
%token COMMODORE CONTROL CRSR CURSOR DELETE EQUAL FUNCTION INSERT ARROW MINUS PERIOD PLUS 
%token POUND RUNSTOP RUN STOP SEMICOLON SLASH KEY STATE KEYSTATE KEYSHIFT CAPSLOCK CAPS LOCK ALT
%token INPUT FREE TILEMAP EMPTY TILE EMPTYTILE PLOT GR CIRCLE DRAW LINE BOX POLYLINE ELLIPSE CLIP
%token BACK DEBUG CAN ELSEIF BUFFER LOAD SIZE MOB IMAGE PUT VISIBLE HIDDEN HIDE SHOW RENDER
%token SQR TI CONST VBL POKE NOP FILL IN POSITIVE DEFINE ATARI ATARIXL C64 DRAGON DRAGON32 DRAGON64 PLUS4 ZX 
%token FONT VIC20 PARALLEL YIELD SPAWN THREAD TASK IMAGES FRAME FRAMES XY YX ROLL MASKED USING TRANSPARENCY
%token OVERLAYED CASE ENDSELECT OGP CGP ARRAY NEW GET DISTANCE TYPE

%token A B C D E F G H I J K L M N O P Q R S T U V X Y W Z
%token F1 F2 F3 F4 F5 F6 F7 F8

%token BLACK WHITE RED CYAN VIOLET GREEN BLUE YELLOW ORANGE
%token BROWN LIGHT DARK GREY GRAY MAGENTA PURPLE
%token LAVENDER GOLD TURQUOISE TAN PINK PEACH OLIVE

%token <string> Identifier
%token <string> String
%token <integer> Integer
%token <string> BufferDefinition

%type <string> expr term modula factor exponential expr_math
%type <integer> const_expr const_term const_modula const_factor const_expr_math
%type <string> const_expr_string
%type <integer> direct_integer
%type <string> random_definition_simple random_definition
%type <string> color_enumeration
%type <string> writing_mode_definition writing_part_definition
%type <string> key_scancode_definition key_scancode_alphadigit key_scancode_function_digit
%type <integer> datatype
%type <integer> optional_integer
%type <string> optional_expr optional_x optional_y
%type <integer> target targets
%type <integer> protothread_definition
%type <integer> on_targets
%type <integer> image_load_flags image_load_flags1 image_load_flag
%type <integer> images_load_flags images_load_flags1 images_load_flag
%type <integer> put_image_flags put_image_flags1 put_image_flag
%type <integer> const_color_enumeration
%type <integer> using_transparency
%type <integer> using_background

%right Integer String CP 
%left OP_DOLLAR
%left OP
%right THEN ELSE OP_ASSIGN_DIRECT
%left OP_POW
%left OP_MULTIPLICATION OP_MULTIPLICATION2 OP_DIVISION OP_DIVISION2
%left MOD
%left OP_PLUS OP_MINUS
%left OF IS
%right HAS BIT
%left AND OR OP_EQUAL OP_DISEQUAL OP_LT OP_LTE OP_GT OP_GTE

%%

const_expr_string :
    String {
        $$ = $1;
    }
    | IF OP const_expr OP_COMMA const_expr_string OP_COMMA const_expr_string CP {
        if ( $3 ) {
            $$ = $5;
        } else {
            $$ = $7;
        }
      };

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
    | const_expr_math OP_LT const_expr_math {
        $$ = ( $1 < $3 );
    }
    | const_expr_math OP_LTE const_expr_math {
        $$ = ( $1 <= $3 );
    }
    | const_expr_math OP_GT const_expr_math {
        $$ = ( $1 > $3 );
    }
    | const_expr_math OP_GTE const_expr_math {
        $$ = ( $1 >= $3 );
    }
    | NOT const_expr {
        $$ = ( ! $2 );
    }
    ;
    
const_expr_math: 
      const_term
    | const_expr_math OP_PLUS const_term {
        $$ = $1 + $3;
    }
    | const_expr_math OP_MINUS const_term {
        $$ = $1 - $3;
    }
    ;

const_term:
      const_modula
    | const_term MOD const_modula {
        $$ = ( $1 % $3 );
    }
    ;

const_modula: 
      const_factor
    | const_modula OP_MULTIPLICATION const_factor {
        $$ = $1 * $3;
    } 
    | const_modula OP_MULTIPLICATION2 direct_integer {
        if ( log2($3) != (int)log2($3) ) {
            CRITICAL_INVALID_MULTIPLICATOR2( $3 );
        }
        $$ = $1 << ((int)log2($3));
    } 
    | const_modula OP_DIVISION const_factor {
        $$ = $1 / $3;
    } 
    | const_modula OP_DIVISION2 direct_integer {
        if ( log2($3) != (int)log2($3) ) {
            CRITICAL_INVALID_DIVISOR2( $3 );
        }
        $$ = $1 >> ((int)log2($3));
    } 
    ;

const_color_enumeration:
      BLACK {
          $$ = COLOR_BLACK;
      }
      | WHITE {
          $$ = COLOR_WHITE;
      }
      | RED {
          $$ = COLOR_RED;
      }
      | CYAN {
          $$ = COLOR_CYAN;
      }
      | VIOLET {
          $$ = COLOR_VIOLET;
      }
      | GREEN {
          $$ = COLOR_GREEN;
      }
      | BLUE {
          $$ = COLOR_BLUE;
      }
      | YELLOW {
          $$ = COLOR_YELLOW;
      }
      | ORANGE {
          $$ = COLOR_ORANGE;
      }
      | BROWN {
          $$ = COLOR_BROWN;
      }
      | LIGHT RED {
          $$ = COLOR_LIGHT_RED;
      }
      | DARK GREY {
          $$ = COLOR_DARK_GREY;
      }
      | GREY {
          $$ = COLOR_GREY;
      }
      | LIGHT GREEN {
          $$ = COLOR_LIGHT_GREEN;
      }
      | LIGHT BLUE {
          $$ = COLOR_LIGHT_BLUE;
      }
      | LIGHT GREY {
          $$ = COLOR_LIGHT_GREY;
      }
      | DARK BLUE {
          $$ = COLOR_DARK_BLUE;
      }
      | MAGENTA {
          $$ = COLOR_MAGENTA;
      }
      | PURPLE {
          $$ = COLOR_PURPLE;
      }
      | LAVENDER {
          $$ = COLOR_LAVENDER;
      }
      | GOLD {
          $$ = COLOR_GOLD;
      }
      | TURQUOISE {
          $$ = COLOR_TURQUOISE;
      }
      | TAN {
          $$ = COLOR_TAN;
      }
      | YELLOW GREEN {
          $$ = COLOR_YELLOW_GREEN;
      }
      | OLIVE GREEN {
          $$ = COLOR_OLIVE_GREEN;
      }
      | PINK {
          $$ = COLOR_PINK;
      }
      | PEACH {
          $$ = COLOR_PEACH;
      };

const_factor: 
        Integer
      | IF OP const_expr OP_COMMA const_expr OP_COMMA const_expr CP {
          if ( $3 ) {
              $$ = $5;
          } else {
              $$ = $7;
          }
      }
      | OP_MINUS Integer {
          $$ = -$2;
      }
      | OP const_expr CP {
          $$ = $2;
      }
      | WIDTH {
          $$ = ((Environment *)_environment)->screenWidth;
      }
      | SCREEN WIDTH {
          $$ = ((Environment *)_environment)->screenWidth;
      }
      | SCREEN TILES WIDTH {
          $$ = ((Environment *)_environment)->screenTilesWidth;
      }
      | TILES WIDTH {
          $$ = ((Environment *)_environment)->screenTilesWidth;
      }
      | FONT WIDTH {
          $$ = ((Environment *)_environment)->fontWidth;
      }
      | IMAGE WIDTH OP expr CP {
          Variable * v = variable_retrieve( _environment, $4 );
          if ( v->type != VT_IMAGE && v->type != VT_IMAGES ) {
              CRITICAL_NOT_IMAGE( v->name );
          }
          if ( !v->valueBuffer ) {
              CRITICAL_NOT_ASSIGNED_IMAGE( v->name );
          }
          $$ = v->valueBuffer[0];
      }
      | FRAMES OP expr CP {
          $$ = frames( _environment, $3 );
      }
      | IMAGES COUNT OP expr CP {
          $$ = frames( _environment, $4 );
      }
      | FRAMES COUNT OP expr CP {
          $$ = frames( _environment, $4 );
      }
      | HEIGHT {
          $$ = ((Environment *)_environment)->screenHeight;
      }
      | SCREEN HEIGHT {
          $$ = ((Environment *)_environment)->screenHeight;
      }
      | SCREEN TILES HEIGHT {
          $$ = ((Environment *)_environment)->screenTilesHeight;
      }
      | FONT HEIGHT {
          $$ = ((Environment *)_environment)->fontHeight;
      }
      | IMAGE HEIGHT OP expr CP {
          Variable * v = variable_retrieve( _environment, $4 );
          if ( v->type != VT_IMAGE && v->type != VT_IMAGES ) {
              CRITICAL_NOT_IMAGE( v->name );
          }
          $$ = v->valueBuffer[1];
      }
      | LEN OP Identifier CP {
          Constant * c = constant_find( ((Environment *)_environment)->constants, $3 );
          if ( c == NULL ) {
              CRITICAL_UNDEFINED_CONSTANT( $3 );
          }
          if ( c->valueString == NULL ) {
              CRITICAL_TYPE_MISMATCH_CONSTANT_STRING( $3 );
          }
          $$ = strlen( c->valueString );
      }
      | LEN OP String CP {
          $$ = strlen( $3 );
      }
      | LEN OP IF OP const_expr_string CP {
          $$ = strlen( $5 );
      }      
      | Identifier {
          Constant * c = constant_find( ((Environment *)_environment)->constants, $1 );
          if ( c == NULL ) {
              CRITICAL_UNDEFINED_CONSTANT( $1 );
          }
          if ( c->valueString != NULL ) {
              CRITICAL_TYPE_MISMATCH_CONSTANT_NUMERIC( $1 );
          }
          $$ = c->value;
      }
      | const_color_enumeration
      ;

expr : 
      expr_math
    | expr_math AND expr {        
        $$ = variable_and( _environment, $1, $3 )->name;
    } 
    | expr_math OR expr {
        $$ = variable_or( _environment, $1, $3 )->name;
    } 
    | expr_math OP_EQUAL expr {
        $$ = variable_compare( _environment, $1, $3 )->name;
    }
    | expr_math OP_DISEQUAL expr {
        $$ = variable_compare_not( _environment, $1, $3 )->name;
    }
    | expr_math OP_LT expr {
        $$ = variable_less_than( _environment, $1, $3, 0 )->name;
    }
    | expr_math OP_LTE expr {
        $$ = variable_less_than( _environment, $1, $3, 1 )->name;
    }
    | expr_math OP_GT expr {
        $$ = variable_greater_than( _environment, $1, $3, 0 )->name;
    }
    | expr_math OP_GTE expr {
        $$ = variable_greater_than( _environment, $1, $3, 0 )->name;
    }
    | NOT expr {
        $$ = variable_not( _environment, $2 )->name;
    }
    ;
    
expr_math: 
      term
    | expr_math OP_PLUS term {
        $$ = variable_add( _environment, $1, $3 )->name;
    }
    | expr_math OP_MINUS term {
        $$ = variable_sub( _environment, $1, $3 )->name;
    }
    ;

term:
      modula
    | term MOD modula {
        $$ = variable_mod( _environment, $1, $3 )->name;
    }
    ;

modula: 
      factor
    | modula OP_MULTIPLICATION factor {
        $$ = variable_mul( _environment, $1, $3 )->name;
    } 
    | modula OP_MULTIPLICATION2 direct_integer {
        if ( log2($3) != (int)log2($3) ) {
            CRITICAL_INVALID_MULTIPLICATOR2( $3 );
        }
        $$ = variable_mul2_const( _environment, $1, $3 )->name;
    } 
    | modula OP_DIVISION factor {
        $$ = variable_div( _environment, $1, $3 )->name;
    } 
    | modula OP_DIVISION2 direct_integer {
        if ( log2($3) != (int)log2($3) ) {
            CRITICAL_INVALID_DIVISOR2( $3 );
        }
        $$ = variable_div2_const( _environment, $1, (int)log2($3) )->name;
    } 
    | modula OP_DIVISION2 Integer {
        if ( log2($3) != (int)log2($3) ) {
            CRITICAL_INVALID_DIVISOR2( $3 );
        }
        $$ = variable_div2_const( _environment, $1, (int)log2($3) )->name;
    } 
    ;

factor: 
        exponential
      | factor OP_POW exponential {
        $$ = powering( _environment, $1, $3 )->name;
      }
      | POWERING OP factor OP_COMMA exponential CP {
        $$ = powering( _environment, $3, $5 )->name;
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
        $$ = variable_bit( _environment, $4, $2 )->name;
      }
      ;

direct_integer:
    OP_HASH Integer {
        $$ = $2;
    }
    | OP_HASH Identifier {
        Constant * c = constant_find( ((struct _Environment *)_environment)->constants, $2 );
        if ( !c ) {
            CRITICAL_UNDEFINED_CONSTANT($2);
        }
        if ( c->valueString ) {
            CRITICAL_TYPE_MISMATCH_CONSTANT_NUMERIC($2);
        }
        $$ = c->value;
    };

image_load_flag :
    FLIP X {
        $$ = FLAG_FLIP_X;
    }
    | FLIP Y {
        $$ = FLAG_FLIP_Y;
    }
    | FLIP XY {
        $$ = FLAG_FLIP_X | FLAG_FLIP_Y;
    }
    | FLIP YX {
        $$ = FLAG_FLIP_X | FLAG_FLIP_Y;
    }
    | OVERLAYED {
        $$ = FLAG_OVERLAYED;
    };

put_image_flag :
    WITH TRANSPARENCY {
        $$ = FLAG_TRANSPARENCY;
    };

images_load_flag :
    FLIP X {
        $$ = FLAG_FLIP_X;
    }
    | FLIP Y {
        $$ = FLAG_FLIP_Y;
    }
    | FLIP XY {
        $$ = FLAG_FLIP_X | FLAG_FLIP_Y;
    }
    | FLIP YX {
        $$ = FLAG_FLIP_X | FLAG_FLIP_Y;
    }
    | ROLL X {
        $$ = FLAG_ROLL_X;
    }
    | OVERLAYED {
        $$ = FLAG_OVERLAYED;
    }
    ;

put_image_flags1 :
    put_image_flag {
        $$ = $1;
    }
    | put_image_flag put_image_flags1 {
        $$ = $1 | $2;
    };

image_load_flags1 :
    image_load_flag {
        $$ = $1;
    }
    | image_load_flag image_load_flags1 {
        $$ = $1 | $2;
    };

images_load_flags1 :
    images_load_flag {
        $$ = $1;
    }
    | images_load_flag images_load_flags1 {
        $$ = $1 | $2;
    };

using_transparency :
    {
        $$ = -1;    
    } 
    | TRANSPARENCY {
        $$ = COLOR_BLACK;
    }
    | TRANSPARENCY const_color_enumeration {
        $$ = $2;
    };

using_background :
    {
        $$ = -1;    
    } 
    | BACKGROUND const_color_enumeration {
        $$ = $2;
    };

image_load_flags :
    {
        $$ = 0;    
    } 
    | image_load_flags1 {
        $$ = $1;
    };

put_image_flags :
    {
        $$ = 0;    
    } 
    | put_image_flags1 {
        $$ = $1;
    };

images_load_flags :
    {
        $$ = 0;    
    } 
    | images_load_flags1 {
        $$ = $1;
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

key_scancode_alphadigit :
      "0" {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 0)")->name;
        variable_store( _environment, $$, KEY_0 );
    }
    | "1" {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 1)")->name;
        variable_store( _environment, $$, KEY_1 );
    }
    | "2" {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 2)")->name;
        variable_store( _environment, $$, KEY_2 );
    }
    | "3" {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 3)")->name;
        variable_store( _environment, $$, KEY_3 );
    }
    | "4" {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 4)")->name;
        variable_store( _environment, $$, KEY_4 );
    }
    | "5" {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 5)")->name;
        variable_store( _environment, $$, KEY_5 );
    }
    | "6" {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 6)")->name;
        variable_store( _environment, $$, KEY_6 );
    }
    | "7" {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 7)")->name;
        variable_store( _environment, $$, KEY_7 );
    }
    | "8" {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 8)")->name;
        variable_store( _environment, $$, KEY_8 );
    }
    | "9" {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 9)")->name;
        variable_store( _environment, $$, KEY_9 );
    }
    | A {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LETTER A)")->name;
        variable_store( _environment, $$, KEY_A );
    }
    | B {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LETTER B)")->name;
        variable_store( _environment, $$, KEY_B );
    }
    | C {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LETTER C)")->name;
        variable_store( _environment, $$, KEY_C );
    }
    | D {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LETTER D)")->name;
        variable_store( _environment, $$, KEY_D );
    }
    | E {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LETTER E)")->name;
        variable_store( _environment, $$, KEY_E );
    }
    | F {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LETTER F)")->name;
        variable_store( _environment, $$, KEY_F );
    }
    | G {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LETTER G)")->name;
        variable_store( _environment, $$, KEY_G );
    }
    | H {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LETTER H)")->name;
        variable_store( _environment, $$, KEY_H );
    }
    | I {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LETTER I)")->name;
        variable_store( _environment, $$, KEY_I );
    }
    | J {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LETTER J)")->name;
        variable_store( _environment, $$, KEY_J );
    }
    | K {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LETTER K)")->name;
        variable_store( _environment, $$, KEY_K );
    }
    | L {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LETTER L)")->name;
        variable_store( _environment, $$, KEY_L );
    }
    | M {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LETTER M)")->name;
        variable_store( _environment, $$, KEY_M );
    }
    | N {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LETTER N)")->name;
        variable_store( _environment, $$, KEY_N );
    }
    | O {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LETTER O)")->name;
        variable_store( _environment, $$, KEY_O );
    }
    | P {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LETTER P)")->name;
        variable_store( _environment, $$, KEY_P );
    }
    | Q {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LETTER Q)")->name;
        variable_store( _environment, $$, KEY_Q );
    }
    | R {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LETTER R)")->name;
        variable_store( _environment, $$, KEY_R );
    }
    | S {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LETTER S)")->name;
        variable_store( _environment, $$, KEY_S );
    }
    | T {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LETTER T)")->name;
        variable_store( _environment, $$, KEY_T );
    }
    | U {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LETTER U)")->name;
        variable_store( _environment, $$, KEY_U );
    }
    | V {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LETTER V)")->name;
        variable_store( _environment, $$, KEY_V );
    }
    | X {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LETTER X)")->name;
        variable_store( _environment, $$, KEY_X );
    }
    | Y {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LETTER Y)")->name;
        variable_store( _environment, $$, KEY_Y );
    }
    | W {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LETTER W)")->name;
        variable_store( _environment, $$, KEY_W );
    }
    | Z {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LETTER Z)")->name;
        variable_store( _environment, $$, KEY_Z );
    }
    ;

key_scancode_function_digit :
      F1 {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode F1)")->name;
        variable_store( _environment, $$, KEY_F1 );
    }
    | F2 {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode F2)")->name;
        variable_store( _environment, $$, KEY_F2 );
    }
    | F3 {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode F3)")->name;
        variable_store( _environment, $$, KEY_F3 );
    }
    | F4 {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode F4)")->name;
        variable_store( _environment, $$, KEY_F4 );
    }
    | F5 {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode F5)")->name;
        variable_store( _environment, $$, KEY_F5 );
    }
    | F6 {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode F6)")->name;
        variable_store( _environment, $$, KEY_F6 );
    }
    | F7 {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode F7)")->name;
        variable_store( _environment, $$, KEY_F7 );
    }
    | F8 {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode F8)")->name;
        variable_store( _environment, $$, KEY_F8 );
    };

key_scancode_definition : 
      NONE {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode NONE)")->name;
        variable_store( _environment, $$, KEY_NONE );
    }
    | key_scancode_alphadigit {
        $$ = $1;
    }
    | ASTERISK {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode ASTERISK)")->name;
        variable_store( _environment, $$, KEY_ASTERISK );
    }
    | AT {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode AT)")->name;
        variable_store( _environment, $$, KEY_AT );
    }
    | CLEAR {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode CLEAR)")->name;
        variable_store( _environment, $$, KEY_CLEAR );
    }
    | COLON {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode COLON)")->name;
        variable_store( _environment, $$, KEY_COLON );
    }
    | COMMA {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode COMMA)")->name;
        variable_store( _environment, $$, KEY_COMMA );
    }
    | COMMODORE {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode COMMODORE)")->name;
        variable_store( _environment, $$, KEY_COMMODORE );
    }
    | CONTROL {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode CONTROL)")->name;
        variable_store( _environment, $$, KEY_CONTROL );
    }
    | CRSR LEFT RIGHT {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode CRSR LEFT RIGHT)")->name;
        variable_store( _environment, $$, KEY_CRSR_LEFT_RIGHT );
    }
    | CRSR UP DOWN {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode CRSR UP DOWN)")->name;
        variable_store( _environment, $$, KEY_CRSR_UP_DOWN );
    }
    | DELETE {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode DELETE)")->name;
        variable_store( _environment, $$, KEY_DELETE );
    }
    | EQUAL {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode EQUAL)")->name;
        variable_store( _environment, $$, KEY_EQUAL );
    }
    | key_scancode_function_digit {
        $$ = $1;
    }
    | HOME {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode HOME)")->name;
        variable_store( _environment, $$, KEY_HOME );
    }
    | INSERT {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode INSERT)")->name;
        variable_store( _environment, $$, KEY_INSERT );
    }
    | ARROW LEFT {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode ARROW LEFT)")->name;
        variable_store( _environment, $$, KEY_LEFT_ARROW );
    }
    | LEFT ARROW {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode ARROW LEFT)")->name;
        variable_store( _environment, $$, KEY_LEFT_ARROW );
    }
    | ARROW UP {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode ARROW UP)")->name;
        variable_store( _environment, $$, KEY_UP_ARROW );
    }
    | UP ARROW {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode ARROW UP)")->name;
        variable_store( _environment, $$, KEY_UP_ARROW );
    }
    | MINUS {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode MINUS)")->name;
        variable_store( _environment, $$, KEY_MINUS );
    }
    | PERIOD {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode PERIOD)")->name;
        variable_store( _environment, $$, KEY_PERIOD );
    }
    | PLUS {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode PLUS)")->name;
        variable_store( _environment, $$, KEY_PLUS );
    }
    | POUND {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode POUND)")->name;
        variable_store( _environment, $$, KEY_POUND );
    }
    | RETURN {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode RETURN)")->name;
        variable_store( _environment, $$, KEY_RETURN );
    }
    | RUNSTOP {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode RUNSTOP)")->name;
        variable_store( _environment, $$, KEY_RUNSTOP );        
    }
    | RUN STOP {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode RUNSTOP)")->name;
        variable_store( _environment, $$, KEY_RUNSTOP );        
    }
    | SEMICOLON {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode SEMICOLON)")->name;
        variable_store( _environment, $$, KEY_SEMICOLON );
    }
    | SLASH {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode SLASH)")->name;
        variable_store( _environment, $$, KEY_SLASH );        
    }
    | SPACE {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode SPACE)")->name;
        variable_store( _environment, $$, KEY_SPACE );        
    };

exponential:
    Identifier {
        ++((struct _Environment *)_environment)->arrayNestedIndex;
        memset( ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex], 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex] = 0;
    }
      OP indexes CP {
        Variable * array = variable_retrieve_or_define( _environment, $1, VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( $1 );
        }
        $$ = variable_move_from_array( _environment, $1 )->name;
        --((struct _Environment *)_environment)->arrayNestedIndex;
    }
    | Identifier OP_DOLLAR {
        ++((struct _Environment *)_environment)->arrayNestedIndex;
        memset( ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex], 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex] = 0;
     } 
      OP indexes CP {
        Variable * array = variable_retrieve_or_define( _environment, $1, VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( $1 );
        }
        if ( array->arrayType != VT_STRING && array->arrayType != VT_DSTRING ) {
            CRITICAL_NOT_STRING_ARRAY( $1 );
        }        
        $$ = variable_move_from_array( _environment, $1 )->name;
        --((struct _Environment *)_environment)->arrayNestedIndex;
    }
    | OSP Identifier CSP {
        ++((struct _Environment *)_environment)->arrayNestedIndex;
        memset( ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex], 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex] = 0;
        ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex][((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex]] = strdup( "PROTOTHREADCT" );
        ++((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex];
        Variable * array = variable_retrieve_or_define( _environment, $2, VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( $2 );
        }
        $$ = variable_move_from_array( _environment, $2 )->name;
        --((struct _Environment *)_environment)->arrayNestedIndex;
    }
    | OSP Identifier OP_DOLLAR CSP {
        ++((struct _Environment *)_environment)->arrayNestedIndex;
        memset( ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex], 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex] = 0;
        ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex][((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex]] = strdup( "PROTOTHREADCT" );
        ++((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex];
        Variable * array = variable_retrieve_or_define( _environment, $2, VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( $2 );
        }
        if ( array->arrayType != VT_STRING && array->arrayType != VT_DSTRING ) {
            CRITICAL_NOT_STRING_ARRAY( $2 );
        }        
        $$ = variable_move_from_array( _environment, $2 )->name;
        --((struct _Environment *)_environment)->arrayNestedIndex;
    }
    | Identifier {
        Constant * c = constant_find( ((struct _Environment *)_environment)->constants, $1 );
        if ( c ) {
            if ( c->valueString ) {
                $$ = variable_temporary( _environment,  VT_STRING, "(constant)" )->name;
                variable_store_string( _environment, $$, c->valueString );
            } else {
                $$ = variable_temporary( _environment,  VT_WORD, "(constant)" )->name;
                variable_store( _environment, $$, c->value );
            }
        } else {
            $$ = variable_retrieve_or_define( _environment, $1, VT_WORD, 0 )->name;
        }
    }
    | Identifier OP_DOLLAR { 
        Constant * c = constant_find( ((struct _Environment *)_environment)->constants, $1 );
        if ( c ) {
            if ( !c->valueString ) {
                CRITICAL_TYPE_MISMATCH_CONSTANT_STRING( $1 );
            }
            $$ = variable_temporary( _environment,  VT_STRING, "(constant)" )->name;
            variable_store_string( _environment, $$, c->valueString );
        } else {
            $$ = variable_retrieve_or_define( _environment, $1, VT_DSTRING, 0 )->name;
        }
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
    | OP_MINUS Integer { 
        $$ = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, $$, -$2 );
      }
    | String { 
        $$ = variable_temporary( _environment, VT_STRING, "(string value)" )->name;
        variable_store_string( _environment, $$, $1 );
      }
    | OP BYTE CP Integer { 
        $$ = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, $$, $4 );
      }
    | OP BYTE CP direct_integer { 
        $$ = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, $$, $4 );
      }
    | OP BYTE CP OP expr CP { 
        $$ = variable_cast( _environment, $5, VT_BYTE )->name;
      }
    | OP SIGNED BYTE CP Integer { 
        $$ = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, $$, $5 );
      }
    | OP SIGNED BYTE CP direct_integer { 
        $$ = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, $$, $5 );
      }
    | OP SIGNED BYTE CP OP expr CP { 
        $$ = variable_cast( _environment, $6, VT_SBYTE )->name;
      }
    | OP WORD CP Integer { 
        $$ = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, $$, $4 );
      }
    | OP WORD CP direct_integer { 
        $$ = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, $$, $4 );
      }
    | OP WORD CP OP expr CP { 
        $$ = variable_cast( _environment, $5, VT_WORD )->name;
      }
    | OP SIGNED WORD CP Integer { 
        $$ = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, $$, $5 );
    }
    | OP SIGNED WORD CP direct_integer { 
        $$ = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, $$, $5 );
      }
    | OP SIGNED WORD CP OP expr CP { 
        $$ = variable_cast( _environment, $6, VT_SWORD )->name;
      }
    | OP DWORD CP Integer { 
        $$ = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, $$, $4 );
      }
    | OP DWORD CP direct_integer { 
        $$ = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, $$, $4 );
      }
    | OP DWORD CP OP expr CP { 
        $$ = variable_cast( _environment, $5, VT_DWORD )->name;
      }
    | OP SIGNED DWORD CP Integer { 
        $$ = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, $$, $5 );
      }
    | OP SIGNED DWORD CP direct_integer { 
        $$ = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, $$, $5 );
      }
    | OP SIGNED DWORD CP OP expr CP { 
        $$ = variable_cast( _environment, $6, VT_SDWORD )->name;
      }
    | OP POSITION CP Integer { 
        $$ = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, $$, $4 );
      }
    | OP POSITION CP direct_integer { 
        $$ = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, $$, $4 );
      }
    | OP POSITION CP OP expr CP { 
        $$ = variable_cast( _environment, $5, VT_POSITION )->name;
      }
    | OP COLOR CP Integer { 
        $$ = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, $$, $4 );
      }
    | OP COLOR CP direct_integer { 
        $$ = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, $$, $4 );
      }
    | OP COLOR CP OP expr CP { 
        $$ = variable_cast( _environment, $5, VT_COLOR )->name;
      }
    | OP STRING CP Identifier { 
        $$ = variable_cast( _environment, $4, VT_DSTRING )->name;        
      }
    | BufferDefinition { 
        $$ = parse_buffer_definition( _environment, $1, VT_BUFFER )->name;
      }
    | OP IMAGE CP BufferDefinition { 
        $$ = parse_buffer_definition( _environment, $4, VT_IMAGE )->name;
      }      
    | OP IMAGES CP BufferDefinition { 
        $$ = parse_buffer_definition( _environment, $4, VT_IMAGES )->name;
      }      
    | SQR OP factor CP {
        $$ = sqroot( _environment, $3 )->name;
      }
    | NEW IMAGE OP const_expr OP_COMMA const_expr CP {        
        $$ = new_image( _environment, $4, $6, ((struct _Environment *)_environment)->currentMode )->name;
      }
    | LOAD OP String CP {
        $$ = load( _environment, $3, NULL, 0 )->name;
      }
    | LOAD OP String AS String CP {
        $$ = load( _environment, $3, $5, 0 )->name;
      }
    | LOAD OP String OP_COMMA Integer CP {
        $$ = load( _environment, $3, NULL, $5 )->name;
      }
    | LOAD OP String AS String OP_COMMA Integer CP {
        $$ = load( _environment, $3, $5, $7 )->name;
      }
    | IMAGES LOAD OP String CP FRAME SIZE OP const_expr OP_COMMA const_expr CP images_load_flags  using_transparency using_background  {        
        $$ = images_load( _environment, $4, NULL, ((struct _Environment *)_environment)->currentMode, $9, $11, $13, $14, $15 )->name;
      }
    | IMAGES LOAD OP String AS String CP FRAME SIZE OP const_expr OP_COMMA const_expr CP images_load_flags  using_transparency using_background  {        
        $$ = images_load( _environment, $4, $6, ((struct _Environment *)_environment)->currentMode, $11, $13, $15, $16, $17 )->name;
      }
    | LOAD IMAGES OP String CP FRAME SIZE OP const_expr OP_COMMA const_expr CP images_load_flags  using_transparency using_background  {        
        $$ = images_load( _environment, $4, NULL, ((struct _Environment *)_environment)->currentMode, $9, $11, $13, $14, $15 )->name;
      }
    | LOAD IMAGES OP String AS String CP FRAME SIZE OP const_expr OP_COMMA const_expr CP images_load_flags  using_transparency using_background {
        $$ = images_load( _environment, $4, $6, ((struct _Environment *)_environment)->currentMode, $11, $13, $15, $16, $17 )->name;
      }
    | IMAGE LOAD OP String CP image_load_flags  using_transparency using_background  {
        $$ = image_load( _environment, $4, NULL, ((struct _Environment *)_environment)->currentMode, $6, $7, $8 )->name;
      }
    | IMAGE LOAD OP String AS String CP image_load_flags  using_transparency using_background  {
        $$ = image_load( _environment, $4, $6, ((struct _Environment *)_environment)->currentMode, $8, $9, $10 )->name;
      }
    | IMAGE LOAD OP String OP_COMMA Integer CP image_load_flags  using_transparency using_background  {
        $$ = image_load( _environment, $4, NULL, $6, $8, $9, $10 )->name;
      }
    | IMAGE LOAD OP String AS String OP_COMMA Integer CP image_load_flags  using_transparency using_background  {
        $$ = image_load( _environment, $4, $6, $8, $10, $11, $12 )->name;
      }
    | LOAD IMAGE OP String CP image_load_flags  using_transparency using_background  {
        $$ = image_load( _environment, $4, NULL, ((struct _Environment *)_environment)->currentMode, $6, $7, $8 )->name;
      }
    | LOAD IMAGE OP String AS String CP image_load_flags  using_transparency using_background  {
        $$ = image_load( _environment, $4, $6, ((struct _Environment *)_environment)->currentMode, $8, $9, $10 )->name;
      }
    | LOAD IMAGE OP String OP_COMMA Integer CP image_load_flags  using_transparency using_background  {
        $$ = image_load( _environment, $4, NULL, $6, $8, $9, $10 )->name;
      }
    | LOAD IMAGE OP String AS String OP_COMMA Integer CP image_load_flags  using_transparency using_background  {
        $$ = image_load( _environment, $4, $6, $8, $10, $11, $12 )->name;
      }
   | SIZE OP expr CP {
        Variable * v = variable_retrieve( _environment, $3 );
        switch( v->type ) {
            case VT_IMAGE:
            case VT_IMAGES:
            case VT_BUFFER:
            case VT_STRING: 
                break;
            default:
                CRITICAL_SIZE_UNSUPPORTED( $3, DATATYPE_AS_STRING[v->type] );
                break;
        }
        $$ = variable_temporary( _environment, VT_WORD, "(size)" )->name;
        variable_store( _environment, $$, v->size );
      }
    | color_enumeration { 
        $$ = $1;
      }
    | DISTANCE OP optional_x OP_COMMA optional_y TO optional_x OP_COMMA optional_y CP {
        $$ = distance( _environment, $3, $5, $7, $9 )->name;
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
    | LEFT OP expr OP_COMMA expr CP {
        $$ = variable_string_left( _environment, $3, $5 )->name;
    }
    | RIGHT OP expr OP_COMMA expr CP {
        $$ = variable_string_right( _environment, $3, $5 )->name;
    }
    | MID OP expr OP_COMMA expr CP {
        $$ = variable_string_mid( _environment, $3, $5, NULL )->name;
    }
    | MID OP expr OP_COMMA expr OP_COMMA expr CP {
        $$ = variable_string_mid( _environment, $3, $5, $7 )->name;
    }
    | INSTR OP expr OP_COMMA expr CP {
        $$ = variable_string_instr( _environment, $3, $5, NULL )->name;
    }
    | INSTR OP expr OP_COMMA expr OP_COMMA expr CP {
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
    | BIN OP expr OP_COMMA expr CP {
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
    | STRING OP expr OP_COMMA expr CP {
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
    | FREE {
        cpu_dsgc( _environment );
        $$ = variable_retrieve( _environment, "FREE_STRING" )->name;
    }
    | SCREEN {
        $$ = variable_temporary( _environment, VT_BYTE, "(SCREEN)" )->name;
        variable_store( _environment, $$, SCREEN_CAPABILITIES );
    }
    | CAN SCREEN direct_integer {
        $$ = screen_can( _environment, $3 )->name;
    }
    | TILEMAP {
        $$ = variable_temporary( _environment, VT_BYTE, "(TILEMAP)" )->name;
        variable_store( _environment, $$, TILEMAP_NATIVE );
    }
    | BITMAP {
        $$ = variable_temporary( _environment, VT_BYTE, "(BITMAP)" )->name;
        variable_store( _environment, $$, BITMAP_NATIVE );
    }
    | POINT OP optional_expr OP_COMMA optional_expr CP {
        $$ = point( _environment, $3, $5 )->name;
    }
    | MAX OP expr OP_COMMA expr CP {
        $$ = maximum( _environment, $3, $5 )->name;
    }
    | MIN OP expr OP_COMMA expr CP {
        $$ = minimum( _environment, $3, $5 )->name;
    }
    | PARAM OP Identifier CP {
        $$ = param_procedure( _environment, $3 )->name;
    }
    | PARAM OP_DOLLAR OP Identifier CP {
        $$ = param_procedure( _environment, $4 )->name;
    }
    | Identifier OSP {
      ((struct _Environment *)_environment)->parameters = 0;
    } values CSP {
      call_procedure( _environment, $1 );
      $$ = param_procedure( _environment, $1 )->name;
    }
    | Identifier OSP CSP {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, $1 );
      $$ = param_procedure( _environment, $1 )->name;
    }
    | SPAWN Identifier {
      ((struct _Environment *)_environment)->parameters = 0;
      $$ = spawn_procedure( _environment, $2 )->name;
    }
    | SPAWN Identifier OSP {
        ((struct _Environment *)_environment)->parameters = 0;
        } values CSP {
      $$ = spawn_procedure( _environment, $2 )->name;
    }
    | SPAWN Identifier OSP CSP {
        ((struct _Environment *)_environment)->parameters = 0;
      $$ = spawn_procedure( _environment, $2 )->name;
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
        variable_store( _environment, $$, 0 );
    }
    | COLORS {
        $$ = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, $$, COLOR_COUNT );
    }
    | COLORS COUNT {
        $$ = variable_temporary( _environment, VT_COLOR, "(COLORS COUNT)" )->name;
        variable_store( _environment, $$, COLOR_COUNT );
    }
    | COLOR COUNT {
        $$ = variable_temporary( _environment, VT_COLOR, "(COLORS COUNT)" )->name;
        variable_store( _environment, $$, COLOR_COUNT );
    }
    | THREAD {
        Variable * var = variable_temporary( _environment, VT_THREAD, "(THREAD)" );
        cpu_protothread_current( _environment, var->realName );
        $$ = var->name;
    }
    | TASK {
        Variable * var = variable_temporary( _environment, VT_THREAD, "(TASK)" );
        cpu_protothread_current( _environment, var->realName );
        $$ = var->name;
    }
    | SCREEN COLORS {
        $$ = variable_temporary( _environment, VT_COLOR, "(SCREEN COLORS)" )->name;
        variable_store( _environment, $$, COLOR_COUNT );
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
    | SCREEN WIDTH {
        $$ = screen_get_width( _environment )->name;
    }
    | SCREEN TILES WIDTH {
        $$ = screen_tiles_get_width( _environment )->name;
    }
    | TILES WIDTH {
        $$ = screen_tiles_get_width( _environment )->name;
    }
    | FONT WIDTH {
        $$ = variable_temporary( _environment, VT_POSITION, "(FONT WIDTH)" )->name;
        variable_store( _environment, $$, ((struct _Environment *)_environment)->fontWidth );
    }
    | IMAGES COUNT OP expr CP {
        $$ = variable_temporary( _environment, VT_BYTE, "(frame count)" )->name;
        variable_store( _environment, $$, frames( _environment, $4 ) );
    }
    | FRAME COUNT OP expr CP {
        $$ = variable_temporary( _environment, VT_BYTE, "(frame count)" )->name;
        variable_store( _environment, $$, frames( _environment, $4 ) );
    }
    | FRAMES OP expr CP {
        $$ = variable_temporary( _environment, VT_BYTE, "(frame count)" )->name;
        variable_store( _environment, $$, frames( _environment, $3 ) );
    }
    | IMAGE WIDTH OP expr CP {
        $$ = image_get_width( _environment, $4 )->name;
    }
    | HEIGHT {
        $$ = screen_get_height( _environment )->name;
    }
    | SCREEN HEIGHT {
        $$ = screen_get_height( _environment )->name;
    }
    | SCREEN TILES HEIGHT {
        $$ = screen_tiles_get_height( _environment )->name;
    }
    | FONT HEIGHT {
        $$ = variable_temporary( _environment, VT_POSITION, "(FONT HEIGHT)" )->name;
        variable_store( _environment, $$, ((struct _Environment *)_environment)->fontHeight );
    }
    | IMAGE HEIGHT OP expr CP {
        $$ = image_get_height( _environment, $4 )->name;
    }
    | MOB OP expr CP {
        $$ = mob_init( _environment, $3, NULL, NULL )->name;
    }
    | MOB OP expr OP_COMMA VISIBLE CP {
        $$ = mob_init( _environment, $3, NULL, NULL )->name;
        mob_show( _environment, $$ );
    }
    | MOB OP expr OP_COMMA HIDDEN CP {
        $$ = mob_init( _environment, $3, NULL, NULL )->name;
    }
    | TI {
        $$ = get_timer( _environment )->name;
    }
    | TIMER {
        $$ = get_timer( _environment )->name;
    }
    | PEN OP_DOLLAR OP expr CP {
        $$ = get_pen( _environment, $4 )->name;
    }
    | PAPER OP_DOLLAR OP expr CP {
        $$ = get_paper( _environment, $4 )->name;
    }
    | CMOVE OP_DOLLAR OP expr OP_COMMA expr CP {
        $$ = get_cmove( _environment, $4, $6 )->name;
    }
    | CUP OP_DOLLAR {
        $$ = get_cmove_direct( _environment, 0, -1 )->name;
    }
    | CDOWN OP_DOLLAR {
        $$ = get_cmove_direct( _environment, 0, 1 )->name;
    }
    | CLEFT OP_DOLLAR {
        $$ = get_cmove_direct( _environment, -1, 0 )->name;
    }
    | CRIGHT OP_DOLLAR {
        $$ = get_cmove_direct( _environment, 1, 0 )->name;
    }
    | AT OP_DOLLAR OP expr OP_COMMA expr CP {
        $$ = get_at( _environment, $4, $6 )->name;
    }
    | LOCATE OP_DOLLAR OP expr OP_COMMA expr CP {
        $$ = get_at( _environment, $4, $6 )->name;
    }
    | TAB OP_DOLLAR {
        $$ = get_tab( _environment )->name;
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
    | BIT OP expr OP_COMMA expr CP {
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
    | JOY UP {
        $$ = variable_temporary( _environment, VT_BYTE, "(UP)" )->name;
        variable_store( _environment, $$, 1 << JOY_UP );
    }
    | JOY DOWN {
        $$ = variable_temporary( _environment, VT_BYTE, "(DOWN)" )->name;
        variable_store( _environment, $$, 1 << JOY_DOWN );
    }
    | JOY LEFT {
        $$ = variable_temporary( _environment, VT_BYTE, "(LEFT)" )->name;
        variable_store( _environment, $$, 1 << JOY_LEFT );
    }
    | JOY RIGHT {
        $$ = variable_temporary( _environment, VT_BYTE, "(RIGHT)" )->name;
        variable_store( _environment, $$, 1 << JOY_RIGHT );
    }
    | JOY FIRE {
        $$ = variable_temporary( _environment, VT_BYTE, "(FIRE)" )->name;
        variable_store( _environment, $$, JOY_FIRE );
    }
    | INPUT OP_DOLLAR OP expr CP {
        $$ = input_string( _environment, $4 )->name;
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
    | KEY STATE OP expr CP {
        $$ = keystate( _environment, $4 )->name;
    }
    | KEYSTATE OP expr CP {
        $$ = keystate( _environment, $3 )->name;
    }
    | SCANSHIFT {
        $$ = scanshift( _environment )->name;
    }
    | SCAN SHIFT {
        $$ = scanshift( _environment )->name;
    }
    | KEYSHIFT {
        $$ = keyshift( _environment )->name;
    }
    | KEY SHIFT {
        $$ = keyshift( _environment )->name;
    }
    | LEFT SHIFT {
        $$ = variable_temporary( _environment, VT_BYTE, "(SHIFT LEFT)" )->name;
        variable_store( _environment, $$, SHIFT_LEFT );
    }
    | SHIFT LEFT {
        $$ = variable_temporary( _environment, VT_BYTE, "(SHIFT LEFT)" )->name;
        variable_store( _environment, $$, SHIFT_LEFT );
    }
    | RIGHT SHIFT {
        $$ = variable_temporary( _environment, VT_BYTE, "(SHIFT RIGHT)" )->name;
        variable_store( _environment, $$, SHIFT_RIGHT );
    }
    | SHIFT RIGHT {
        $$ = variable_temporary( _environment, VT_BYTE, "(SHIFT RIGHT)" )->name;
        variable_store( _environment, $$, SHIFT_RIGHT );
    }
    | CAPSLOCK {
        $$ = variable_temporary( _environment, VT_BYTE, "(SHIFT CAPSLOCK)" )->name;
        variable_store( _environment, $$, SHIFT_CAPSLOCK );
    }
    | CAPS LOCK {
        $$ = variable_temporary( _environment, VT_BYTE, "(SHIFT CAPSLOCK)" )->name;
        variable_store( _environment, $$, SHIFT_CAPSLOCK );
    }
    | CONTROL {
        $$ = variable_temporary( _environment, VT_BYTE, "(SHIFT CONTROL)" )->name;
        variable_store( _environment, $$, SHIFT_CONTROL );
    }
    | LEFT ALT {
        $$ = variable_temporary( _environment, VT_BYTE, "(SHIFT LEFT ALT)" )->name;
        variable_store( _environment, $$, SHIFT_LEFT_ALT );
    }
    | ALT LEFT {
        $$ = variable_temporary( _environment, VT_BYTE, "(SHIFT LEFT ALT)" )->name;
        variable_store( _environment, $$, SHIFT_LEFT_ALT );
    }
    | RIGHT ALT {
        $$ = variable_temporary( _environment, VT_BYTE, "(SHIFT RIGHT ALT)" )->name;
        variable_store( _environment, $$, SHIFT_RIGHT_ALT );
    }
    | ALT RIGHT {
        $$ = variable_temporary( _environment, VT_BYTE, "(SHIFT RIGHT ALT)" )->name;
        variable_store( _environment, $$, SHIFT_RIGHT_ALT );
    }
    | KEY key_scancode_definition {
        $$ = $2;
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
  | BACK expr {
      back( _environment, $2 );
  }
  | BACKGROUND expr {
      back( _environment, $2 );
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
    }
    | KEY {
      wait_key( _environment );
    }
    | VBL {
      wait_vbl( _environment );
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
    | UNTIL { 
        wait_until( _environment );  
    } expr {
        wait_until_condition( _environment, $3 );  
    }
    | WHILE { 
        wait_while( _environment );  
    } expr {
        wait_while_condition( _environment, $3 );  
    }
    | PARALLEL expr { 
        wait_parallel( _environment, $2 );  
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
  | direct_integer position OP direct_integer OP_COMMA direct_integer CP {
      sprite_at( _environment, $1, $4, $6 );
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
  | expr position OP expr OP_COMMA expr CP {
      sprite_at_vars( _environment, $1, $4, $6 );
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

optional_integer : 
    Integer {
        $$ = $1;
    } | {
        $$ = 0;
    };

bitmap_enable_resolution : 
      {
        bitmap_enable( _environment, 0, 0, 0 );
    }
    | OP optional_integer  CP {
        bitmap_enable( _environment, 0, 0, $2 );
    }
    | OP optional_integer OP_COMMA optional_integer CP {
        bitmap_enable( _environment, $2, $4, 0 );
    }
    | OP optional_integer OP_COMMA optional_integer OP_COMMA optional_integer CP {
        bitmap_enable( _environment, $2, $4, $6 );
    }

bitmap_definition_simple:
    AT direct_integer {
      bitmap_at( _environment, $2 );
  } 
  | ENABLE bitmap_enable_resolution {

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

text_definition_expression:
     AT expr OP_COMMA expr OP_COMMA expr {
       text_at( _environment, $2, $4, $6 );
   }
   | expr OP_COMMA expr OP_COMMA expr {
       text_at( _environment, $1, $3, $5 );
   };

text_definition:
    text_definition_expression;

tilemap_enable_resolution : 
      {
        tilemap_enable( _environment, 0, 0, 0 );
    }
    | OP optional_integer CP {
        tilemap_enable( _environment, 0, 0, $2 );
    }
    | OP optional_integer OP_COMMA optional_integer CP {
        tilemap_enable( _environment, $2, $4, 0 );
    }
    | OP optional_integer OP_COMMA optional_integer OP_COMMA optional_integer CP {
        tilemap_enable( _environment, $2, $4, $6 );
    }

tilemap_definition_simple:
    ENABLE tilemap_enable_resolution {

  }
  | DISABLE {
      tilemap_disable( _environment );
  };

tilemap_definition:
    tilemap_definition_simple;

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
    direct_integer {   
      screen_mode( _environment, $1 );
  }
  | ON {   
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
   Identifier {
      variable_retrieve_or_define( _environment, $1, ((struct _Environment *)_environment)->defaultVariableType, 0 );
  }
  | Identifier AS datatype {
      variable_retrieve_or_define( _environment, $1, $3, 0 );
  }
  | Identifier AS datatype OP_ASSIGN const_expr {
      variable_retrieve_or_define( _environment, $1, $3, $5 );
  }
  | Identifier ON Identifier {
      variable_retrieve_or_define( _environment, $1, VT_BYTE, 0 );
  }
  | Identifier OP_DOLLAR ON Identifier {
      variable_retrieve_or_define( _environment, $1, VT_DSTRING, 0 );
  }
  | Identifier ON Identifier OP_ASSIGN direct_integer {
      variable_retrieve_or_define( _environment, $1, VT_BYTE, $5 );
  }
  | Identifier ON Identifier OP_ASSIGN expr {
      Variable * v = variable_retrieve( _environment, $5 );
      Variable * d = variable_retrieve_or_define( _environment, $1, v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
  | Identifier OP_DOLLAR ON Identifier OP_ASSIGN expr {
      Variable * v = variable_retrieve( _environment, $6 );
      Variable * d = variable_retrieve_or_define( _environment, $1, VT_DSTRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
  ;

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
      AT OP direct_integer OP_COMMA direct_integer CP {
        point_at( _environment, $3, $5 );
    }
    ;

point_definition_expression:
      AT OP expr OP_COMMA expr CP {
        point_at_vars( _environment, $3, $5 );
    };

point_definition:
    point_definition_simple
  | point_definition_expression;

optional_x:
    expr {
        $$ = $1;
    }
    | {
        $$ = strdup( "XGR" );
    }
    ;

optional_y:
    expr {
        $$ = $1;
    }
    | {
        $$ = strdup( "YGR" );
    }
    ;

optional_expr:
    expr {
        $$ = $1;
    }
    | {
        $$ = NULL;
    }
    ;

plot_definition_expression:
      optional_x OP_COMMA optional_y OP_COMMA optional_expr {
        plot( _environment, $1, $3, $5 );
    }
    | optional_x OP_COMMA optional_y {
        plot( _environment, $1, $3, NULL );
    };

plot_definition:
    plot_definition_expression;

circle_definition_expression:
      optional_x OP_COMMA optional_y OP_COMMA expr OP_COMMA optional_expr {
        circle( _environment, $1, $3, $5, $7 );
        gr_locate( _environment, $1, $3 );
    }
    | optional_x OP_COMMA optional_y OP_COMMA expr {
        circle( _environment, $1, $3, $5, NULL );
        gr_locate( _environment, $1, $3 );
    };

circle_definition:
    circle_definition_expression;

ellipse_definition_expression:
      optional_x OP_COMMA optional_y OP_COMMA expr OP_COMMA expr OP_COMMA optional_expr {
        ellipse( _environment, $1, $3, $5, $7, $9 );
        gr_locate( _environment, $1, $3 );
    }
    | optional_x OP_COMMA optional_y OP_COMMA expr OP_COMMA expr {
        ellipse( _environment, $1, $3, $5, $7, NULL );
        gr_locate( _environment, $1, $3 );
    };

ellipse_definition:
    ellipse_definition_expression;

mob_definition_expression:
     SHOW expr {
        mob_show( _environment, $2 );
    }
    | HIDE expr {
        mob_hide( _environment, $2 );
    }
    | RENDER {
        mob_render( _environment, 0 );
    }
    | RENDER ON VBL {
        mob_render( _environment, 1 );
    }
    | Identifier OP_COMMA expr AT optional_x OP_COMMA optional_y VISIBLE {
        Variable * var = mob_init( _environment, $3, $5, $7 );
        variable_move_naked( _environment, $1, var->name );
        mob_show( _environment, $1 );
        gr_locate( _environment, $5, $7 );
    }
    | Identifier OP_COMMA expr AT optional_x OP_COMMA optional_y HIDDEN {
        Variable * var = mob_init( _environment, $3, $5, $7 );
        variable_move_naked( _environment, $1, var->name );
        mob_hide( _environment, $1 );
    }
    | Identifier OP_COMMA expr AT optional_x OP_COMMA optional_y {
        Variable * var = mob_init( _environment, $3, $5, $7 );
        variable_move_naked( _environment, $1, var->name );
        gr_locate( _environment, $5, $7 );
    }
    | Identifier OP_COMMA expr {
        Variable * var = mob_init( _environment, $3, NULL, NULL );
        variable_move_naked( _environment, $1, var->name );
    }
    | Identifier OP_COMMA expr VISIBLE {
        Variable * var = mob_init( _environment, $3, NULL, NULL );
        variable_move_naked( _environment, $1, var->name );
        mob_show( _environment, $1 );
    }
    | Identifier OP_COMMA expr HIDDEN {
        Variable * var = mob_init( _environment, $3, NULL, NULL );
        variable_move_naked( _environment, $1, var->name );
    }
    | Identifier AT optional_x OP_COMMA optional_y {
        mob_at( _environment, $1, $3, $5 );
        gr_locate( _environment, $3, $5 );
    }
    ;

mob_definition:
    mob_definition_expression;

put_definition_expression:
      IMAGE expr AT optional_x OP_COMMA optional_y put_image_flags {
        put_image( _environment, $2, $4, $6, NULL, $7 );
        gr_locate( _environment, $4, $6 );
    }
    |  IMAGE expr FRAME expr AT optional_x OP_COMMA optional_y put_image_flags {
        put_image( _environment, $2, $6, $8, $4, $9 );
        gr_locate( _environment, $6, $8 );
    }
    | IMAGE expr put_image_flags {
        put_image( _environment, $2, "XGR", "YGR", NULL, $3 );
    }
    | IMAGE expr FRAME expr put_image_flags {
        put_image( _environment, $2, "XGR", "YGR", $4, $5 );
    }
    ;

get_definition_expression:
      IMAGE Identifier FROM optional_x OP_COMMA optional_y  {
        get_image( _environment, $2, $4, $6 );
        gr_locate( _environment, $4, $6 );
    };

put_definition:
    put_definition_expression;

get_definition:
    get_definition_expression;

draw_definition_expression:
      optional_x OP_COMMA optional_y TO optional_x OP_COMMA optional_y OP_COMMA optional_expr {
        draw( _environment, $1, $3, $5, $7, $9 );
        gr_locate( _environment, $5, $7 );
    }
    | optional_x OP_COMMA optional_y TO optional_x OP_COMMA optional_y  {
        draw( _environment, $1, $3, $5, $7, NULL );
        gr_locate( _environment, $5, $7 );
    }
    | TO optional_x OP_COMMA optional_y OP_COMMA optional_expr {
        draw( _environment, "XGR", "YGR", $2, $4, $6 );
        gr_locate( _environment, $2, $4 );
    }
    | TO optional_x OP_COMMA optional_y  {
        draw( _environment, "XGR", "YGR", $2, $4, NULL );
        gr_locate( _environment, $2, $4 );
    };

draw_definition:
    draw_definition_expression;

box_definition_expression:
      optional_x OP_COMMA optional_y TO optional_x OP_COMMA optional_y OP_COMMA optional_expr {
        box( _environment, $1, $3, $5, $7, $9 );
        gr_locate( _environment, $5, $7 );
    }
    | optional_x OP_COMMA optional_y TO optional_x OP_COMMA optional_y  {
        box( _environment, $1, $3, $5, $7, NULL );
        gr_locate( _environment, $5, $7 );
    }
    | TO optional_x OP_COMMA optional_y OP_COMMA optional_expr {
        box( _environment, "XGR", "YGR", $2, $4, $6 );
        gr_locate( _environment, $2, $4 );
    }
    | TO optional_x OP_COMMA optional_y  {
        box( _environment, "XGR", "YGR", $2, $4, NULL );
        gr_locate( _environment, $2, $4 );
    };

box_definition:
    box_definition_expression;

clip_definition_expression:
      expr OP_COMMA expr TO expr OP_COMMA expr {
        clip( _environment, $1, $3, $5, $7 );
    }
    | {
        clip( _environment, NULL, NULL, NULL, NULL );
    };

clip_definition:
    clip_definition_expression;

polyline_definition_expression_continue:
      TO optional_x OP_COMMA optional_y OP_COMMA optional_expr {
        draw( _environment, "XGR", "YGR", $2, $4, $6 );
        gr_locate( _environment, $2, $4 );
    }
    | TO optional_x OP_COMMA optional_y  {
        draw( _environment, "XGR", "YGR", $2, $4, NULL );
        gr_locate( _environment, $2, $4 );
    } polyline_definition_expression_continue
    | TO optional_x OP_COMMA optional_y  {
        draw( _environment, "XGR", "YGR", $2, $4, NULL );
        gr_locate( _environment, $2, $4 );
    };

polyline_definition_expression:
      optional_x OP_COMMA optional_y TO optional_x OP_COMMA optional_y OP_COMMA optional_expr {
        draw( _environment, $1, $3, $5, $7, $9 );
        gr_locate( _environment, $5, $7 );
    }
    | optional_x OP_COMMA optional_y TO optional_x OP_COMMA optional_y  {
        draw( _environment, $1, $3, $5, $7, NULL );
        gr_locate( _environment, $5, $7 );
    }
    | optional_x OP_COMMA optional_y TO optional_x OP_COMMA optional_y  {
        draw( _environment, $1, $3, $5, $7, NULL );
        gr_locate( _environment, $5, $7 );
    } polyline_definition_expression_continue
    | TO optional_x OP_COMMA optional_y OP_COMMA optional_expr {
        draw( _environment, "XGR", "YGR", $2, $4, $6 );
        gr_locate( _environment, $2, $4 );
    }
    | TO optional_x OP_COMMA optional_y  {
        draw( _environment, "XGR", "YGR", $2, $4, NULL );
        gr_locate( _environment, $2, $4 );
    }
    | TO optional_x OP_COMMA optional_y  {
        draw( _environment, "XGR", "YGR", $2, $4, NULL );
        gr_locate( _environment, $2, $4 );
    } polyline_definition_expression_continue;

polyline_definition:
    polyline_definition_expression;

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
    } OP_COMMA on_goto_definition;

on_gosub_definition:
      Identifier {
          on_gosub_index( _environment, $1 );
          on_gosub_end( _environment );
      }
    | Identifier {
          on_gosub_index( _environment, $1 );
    } OP_COMMA on_gosub_definition;

on_proc_definition:
      Identifier {
          on_proc_index( _environment, $1 );
          on_proc_end( _environment );
      }
    | Identifier {
          on_proc_index( _environment, $1 );
    } OP_COMMA on_proc_definition;

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
    | expr TICKS CALL Identifier {
          every_ticks_call( _environment, $1, $4 );
    }
    | ON {
          every_on( _environment );
    }
    | OFF {
          every_off( _environment );
    };

add_definition :
    Identifier OP_COMMA expr {
        variable_move_naked( _environment, variable_add( _environment, $1, $3 )->name, $1 );
    }
    | Identifier OP_COMMA expr OP_COMMA expr TO expr {
        add_complex( _environment, $1, $3, $5, $7 );
    }
    ;

dimensions :
      const_expr {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = $1;
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
    | const_expr OP_COMMA dimensions {
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
        $$ = VT_DSTRING;
    }
    | IMAGE {
        $$ = VT_IMAGE;
    }
    | IMAGES {
        $$ = VT_IMAGE;
    }
    | BUFFER {
        $$ = VT_BUFFER;
    };

const_array_definition :
    const_expr {
        Variable *currentArray = ((struct _Environment *)_environment)->currentArray;
        Constant * first = currentArray->arrayInitialization;
        Constant * c = malloc( sizeof( Constant ) );
        memset( c, 0, sizeof( Constant ) );
        c->value = $1;
        if ( first ) {
            while( first->next ) {
                first = first->next;
            }
            first->next = c;
        } else {
            currentArray->arrayInitialization = c;
        }        
    };

const_array_definitions1:
    const_array_definition {

    }
    | const_array_definition OP_COMMA const_array_definitions1 {

    };

const_array_definitions : 
    {

    }
    | const_array_definitions1;

array_assign: {
        if ( ! ((struct _Environment *)_environment)->currentArray->memoryArea ) {
            memory_area_assign( ((struct _Environment *)_environment)->memoryAreas, ((struct _Environment *)_environment)->currentArray );
        }
        if ( ((struct _Environment *)_environment)->currentArray->memoryArea ) {
            variable_store( _environment, ((struct _Environment *)_environment)->currentArray->name, ((struct _Environment *)_environment)->currentArray->value );
        }
    }
    | OP_ASSIGN BufferDefinition {
        int size = ( strlen( $2 ) - 3 ) / 2;
        if ( size != ((struct _Environment *)_environment)->currentArray->size ) {
            CRITICAL_BUFFER_SIZE_MISMATCH_ARRAY_SIZE( ((struct _Environment *)_environment)->currentArray->name, ((struct _Environment *)_environment)->currentArray->size, size );
        }
        char * buffer = malloc( size );
        char hexdigits[3];
        int i = 0, c = 0, j = 0;
        for( i = 2, c = strlen( $2 ); i<(c-2); i += 2 ) {
            hexdigits[0] = $2[i];
            hexdigits[1] = $2[i+1];
            hexdigits[2] = 0;
            buffer[j] = strtol(hexdigits,0,16);
            ++j;
        }
        ((struct _Environment *)_environment)->currentArray->valueBuffer = buffer;
        ((struct _Environment *)_environment)->currentArray->memoryArea = NULL;
        ((struct _Environment *)_environment)->currentArray = NULL;
    }
    | OP_ASSIGN {
        Variable *currentArray = ((struct _Environment *)_environment)->currentArray;
        currentArray->arrayInitialization = NULL;
    } OP_HASH OGP const_array_definitions CGP {
        Variable *currentArray = ((struct _Environment *)_environment)->currentArray;
        char * buffer = malloc( currentArray->size ), * ptr = buffer;
        int i=0;
        Constant * initializationValues = currentArray->arrayInitialization;
        while(initializationValues) {
            switch( VT_BITWIDTH(currentArray->arrayType) ) {
                case 8:
                    *ptr = (initializationValues->value) & 0xff;
                    ++ptr;
                    break;
                case 16:
                    #ifdef CPU_BIG_ENDIAN
                        *ptr = ( initializationValues->value >> 8 ) & 0xff;
                        *(ptr+1) = ( initializationValues->value ) & 0xff;
                    #else
                        *(ptr+1) = ( initializationValues->value >> 8 ) & 0xff;
                        *ptr = ( initializationValues->value ) & 0xff;
                    #endif
                    ptr += 2;
                    break;
                case 32:
                    #ifdef CPU_BIG_ENDIAN
                        *ptr = ( initializationValues->value >> 24 ) & 0xff;
                        *(ptr+1) = ( initializationValues->value >> 16 ) & 0xff;
                        *(ptr+2) = ( initializationValues->value >> 8 ) & 0xff;
                        *(ptr+3) = ( initializationValues->value ) & 0xff;
                    #else
                        *(ptr+3) = ( initializationValues->value >> 24 ) & 0xff;
                        *(ptr+2) = ( initializationValues->value >> 16 ) & 0xff;
                        *(ptr+1) = ( initializationValues->value >> 8 ) & 0xff;
                        *ptr = ( initializationValues->value ) & 0xff;
                    #endif
                    ptr += 4;
                    break;
            }
            initializationValues = initializationValues->next;
        }
        if ( ( ptr - buffer ) != currentArray->size ) {
            CRITICAL_BUFFER_SIZE_MISMATCH_ARRAY_SIZE( currentArray->name, currentArray->size, (int)(ptr-buffer));
        }
        ((struct _Environment *)_environment)->currentArray->valueBuffer = buffer;
        ((struct _Environment *)_environment)->currentArray->memoryArea = NULL;
        ((struct _Environment *)_environment)->currentArray = NULL;
    };

array_reassign:
    BufferDefinition {
        int size = ( strlen( $1 ) - 3 ) / 2;
        if ( size != ((struct _Environment *)_environment)->currentArray->size ) {
            CRITICAL_BUFFER_SIZE_MISMATCH_ARRAY_SIZE( ((struct _Environment *)_environment)->currentArray->name, ((struct _Environment *)_environment)->currentArray->size, size );
        }
        char * buffer = malloc( size );
        char hexdigits[3];
        int i = 0, c = 0, j = 0;
        for( i = 2, c = strlen( $1 ); i<(c-2); i += 2 ) {
            hexdigits[0] = $1[i];
            hexdigits[1] = $1[i+1];
            hexdigits[2] = 0;
            buffer[j] = strtol(hexdigits,0,16);
            ++j;
        }
        Variable * var = variable_temporary( _environment, VT_BUFFER, "(array reassign)" );
        variable_store_buffer( _environment, var->name, buffer, size, 0 );
        cpu_mem_move_direct_size( _environment, var->realName, ((struct _Environment *)_environment)->currentArray->realName, size );
        ((struct _Environment *)_environment)->currentArray = NULL;
    }
    | {
        Variable *currentArray = ((struct _Environment *)_environment)->currentArray;
        currentArray->arrayInitialization = NULL;
    } OP_HASH OGP const_array_definitions CGP {
        Variable *currentArray = ((struct _Environment *)_environment)->currentArray;
        int size = currentArray->size;
        char * buffer = malloc( currentArray->size ), * ptr = buffer;
        int i=0;
        Constant * initializationValues = currentArray->arrayInitialization;
        while(initializationValues) {
            switch( VT_BITWIDTH(currentArray->arrayType) ) {
                case 8:
                    *ptr = (initializationValues->value) & 0xff;
                    ++ptr;
                    break;
                case 16:
                    #ifdef CPU_BIG_ENDIAN
                        *ptr = ( initializationValues->value >> 8 ) & 0xff;
                        *(ptr+1) = ( initializationValues->value ) & 0xff;
                    #else
                        *(ptr+1) = ( initializationValues->value >> 8 ) & 0xff;
                        *ptr = ( initializationValues->value ) & 0xff;
                    #endif
                    ptr += 2;
                    break;
                case 32:
                    #ifdef CPU_BIG_ENDIAN
                        *ptr = ( initializationValues->value >> 24 ) & 0xff;
                        *(ptr+1) = ( initializationValues->value >> 16 ) & 0xff;
                        *(ptr+2) = ( initializationValues->value >> 8 ) & 0xff;
                        *(ptr+3) = ( initializationValues->value ) & 0xff;
                    #else
                        *(ptr+3) = ( initializationValues->value >> 24 ) & 0xff;
                        *(ptr+2) = ( initializationValues->value >> 16 ) & 0xff;
                        *(ptr+1) = ( initializationValues->value >> 8 ) & 0xff;
                        *ptr = ( initializationValues->value ) & 0xff;
                    #endif
                    ptr += 4;
                    break;
            }
            initializationValues = initializationValues->next;
        }
        if ( ( ptr - buffer ) != currentArray->size ) {
            CRITICAL_BUFFER_SIZE_MISMATCH_ARRAY_SIZE( currentArray->name, currentArray->size, (int)(ptr-buffer));
        }
        Variable * var = variable_temporary( _environment, VT_BUFFER, "(array reassign)" );
        variable_store_buffer( _environment, var->name, buffer, size, 0 );
        cpu_mem_move_direct_size( _environment, var->realName, ((struct _Environment *)_environment)->currentArray->realName, size );
        ((struct _Environment *)_environment)->currentArray = NULL;
    };    

dim_definition :
      Identifier {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      } OP dimensions CP {
        ((struct _Environment *)_environment)->currentArray = variable_retrieve_or_define( _environment, $1, VT_ARRAY, 0 );
        variable_array_type( _environment, $1, VT_WORD );
    } array_assign;
    | Identifier WITH const_expr {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      } OP dimensions CP {
        ((struct _Environment *)_environment)->currentArray = variable_retrieve_or_define( _environment, $1, VT_ARRAY, 0 );
        ((struct _Environment *)_environment)->currentArray->value = $3;
        variable_array_type( _environment, $1, VT_WORD );
        if ( ! ((struct _Environment *)_environment)->currentArray->memoryArea ) {
            memory_area_assign( ((struct _Environment *)_environment)->memoryAreas, ((struct _Environment *)_environment)->currentArray );
        }
        if ( ((struct _Environment *)_environment)->currentArray->memoryArea ) {
            variable_store( _environment, ((struct _Environment *)_environment)->currentArray->name, ((struct _Environment *)_environment)->currentArray->value );
        }
    }
    | Identifier {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      } OP_DOLLAR OP dimensions CP {
        ((struct _Environment *)_environment)->currentArray = variable_retrieve_or_define( _environment, $1, VT_ARRAY, 0 );
        variable_array_type( _environment, $1, VT_DSTRING );
        if ( ! ((struct _Environment *)_environment)->currentArray->memoryArea ) {
            memory_area_assign( ((struct _Environment *)_environment)->memoryAreas, ((struct _Environment *)_environment)->currentArray );
        }
        if ( ((struct _Environment *)_environment)->currentArray->memoryArea ) {
            variable_store( _environment, ((struct _Environment *)_environment)->currentArray->name, ((struct _Environment *)_environment)->currentArray->value );
        }
    }
    | Identifier datatype {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      } OP dimensions CP {
        ((struct _Environment *)_environment)->currentArray = variable_retrieve_or_define( _environment, $1, VT_ARRAY, 0 );
        variable_array_type( _environment, $1, $2 );
    } array_assign;
    | Identifier datatype WITH const_expr {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      } OP dimensions CP {
        ((struct _Environment *)_environment)->currentArray = variable_retrieve_or_define( _environment, $1, VT_ARRAY, 0 );
        ((struct _Environment *)_environment)->currentArray->value = $4;
        variable_array_type( _environment, $1, $2 );
        if ( ! ((struct _Environment *)_environment)->currentArray->memoryArea ) {
            memory_area_assign( ((struct _Environment *)_environment)->memoryAreas, ((struct _Environment *)_environment)->currentArray );
        }
        if ( ((struct _Environment *)_environment)->currentArray->memoryArea ) {
            variable_store( _environment, ((struct _Environment *)_environment)->currentArray->name, ((struct _Environment *)_environment)->currentArray->value );
        }
      }
    | Identifier AS datatype {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      } OP dimensions CP {
        ((struct _Environment *)_environment)->currentArray = variable_retrieve_or_define( _environment, $1, VT_ARRAY, 0 );
        variable_array_type( _environment, $1, $3 );
    } array_assign;
    | Identifier AS datatype WITH const_expr {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      } OP dimensions CP {
        ((struct _Environment *)_environment)->currentArray = variable_retrieve_or_define( _environment, $1, VT_ARRAY, 0 );
        ((struct _Environment *)_environment)->currentArray->value = $5;
        variable_array_type( _environment, $1, $3 );
        if ( ! ((struct _Environment *)_environment)->currentArray->memoryArea ) {
            memory_area_assign( ((struct _Environment *)_environment)->memoryAreas, ((struct _Environment *)_environment)->currentArray );
        }
        if ( ((struct _Environment *)_environment)->currentArray->memoryArea ) {
            variable_store( _environment, ((struct _Environment *)_environment)->currentArray->name, ((struct _Environment *)_environment)->currentArray->value );
        }
    }
    ;

dim_definitions :
      dim_definition
    | dim_definition OP_COMMA dim_definitions
    ;

fill_definition :
      Identifier {
        variable_array_fill( _environment, $1, 0 );
    }
    | Identifier WITH const_expr {
        variable_array_fill( _environment, $1, $3 );
    }
    ;

fill_definitions :
      fill_definition
    | fill_definition OP_COMMA fill_definitions
    ;

indexes :
      expr {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex][((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex]] = strdup( $1 );
          ++((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex];
    }
    | expr OP_COMMA indexes {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex][((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex]] = strdup( $1 );
          ++((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex];
    }
    ;

parameters : 
      Identifier {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
    | Identifier OP_DOLLAR {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_DSTRING;
          ++((struct _Environment *)_environment)->parameters;
    }
    | Identifier AS datatype {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = $3;
          ++((struct _Environment *)_environment)->parameters;
    }
    | Identifier OP_COMMA parameters {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
    | Identifier OP_DOLLAR OP_COMMA parameters {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_DSTRING;
          ++((struct _Environment *)_environment)->parameters;
    }
    | Identifier AS datatype OP_COMMA parameters {
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
    | Identifier OP_DOLLAR {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_DSTRING;
          ++((struct _Environment *)_environment)->parameters;
    }
    | Identifier AS datatype {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = $3;
          ++((struct _Environment *)_environment)->parameters;
    }
    | Identifier OP_COMMA parameters_expr {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
    | Identifier OP_DOLLAR OP_COMMA parameters_expr {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_DSTRING;
          ++((struct _Environment *)_environment)->parameters;
    }
    | Identifier AS datatype OP_COMMA parameters_expr {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = $3;
          ++((struct _Environment *)_environment)->parameters;
    }
    | String {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ++((struct _Environment *)_environment)->parameters;
    }
    | String OP_COMMA parameters_expr {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ++((struct _Environment *)_environment)->parameters;
    }
    ;

values : 
      expr {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ++((struct _Environment *)_environment)->parameters;
    }
    | expr OP_COMMA values {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ++((struct _Environment *)_environment)->parameters;
    }
    ;

print_definition :
    expr {
        print( _environment, $1, 1 );
    }
  | expr OP_COMMA {
        print( _environment, $1, 0 );
        print_tab( _environment, 0 );
  }
  | expr OP_SEMICOLON {
        print( _environment, $1, 0 );
  }
  | expr OP_COMMA {
        print( _environment, $1, 0 );
        print_tab( _environment, 0 );
  }  print_definition
  | expr OP_SEMICOLON  {
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
    writing_mode_definition OP_COMMA writing_part_definition {
        writing( _environment, $1, $3 );
    }
    ;

locate_definition : 
     OP_COMMA expr {
        locate( _environment, NULL, $2 );
    }
    | expr OP_COMMA {
        locate( _environment, $1, NULL );
    } 
    | expr OP_COMMA expr {
        locate( _environment, $1, $3 );
    }
    ;

gr_locate_definition : 
     OP_COMMA expr {
        gr_locate( _environment, NULL, $2 );
    }
    | expr OP_COMMA {
        gr_locate( _environment, $1, NULL );
    } 
    | expr OP_COMMA expr {
        gr_locate( _environment, $1, $3 );
    }
    ;

cmove_definition : 
     OP_COMMA expr {
        cmove( _environment, NULL, $2 );
    }
    | expr OP_COMMA {
        cmove( _environment, $1, NULL );
    } 
    | expr OP_COMMA expr {
        cmove( _environment, $1, $3 );
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

input_definition2 :
      Identifier {
        input( _environment, $1 );
        print_newline( _environment );
      }
    | Identifier OP_SEMICOLON {
        input( _environment, $1 );
      }
    | Identifier {
        input( _environment, $1 );
      } OP_COMMA input_definition2
    ;

input_definition :
      String OP_SEMICOLON Identifier {
        Variable * string = variable_temporary( _environment, VT_STRING, "(string value)" );
        variable_store_string( _environment, string->name, $1 );
        print( _environment, string->name, 0 );
        input( _environment, $3 );
        print_newline( _environment );
    }
    | String OP_SEMICOLON Identifier OP_DOLLAR {
        Variable * string = variable_temporary( _environment, VT_STRING, "(string value)" );
        variable_store_string( _environment, string->name, $1 );
        print( _environment, string->name, 0 );
        Variable * var = variable_retrieve_or_define( _environment, $3, VT_DSTRING, 0 );
        input( _environment, var->name );
        print_newline( _environment );
    }
    | String OP_SEMICOLON Identifier OP_SEMICOLON {
        Variable * string = variable_temporary( _environment, VT_STRING, "(string value)" );
        variable_store_string( _environment, string->name, $1 );
        print( _environment, string->name, 0 );
        input( _environment, $3 );
    }
    | String OP_SEMICOLON Identifier OP_DOLLAR OP_SEMICOLON {
        Variable * string = variable_temporary( _environment, VT_STRING, "(string value)" );
        variable_store_string( _environment, string->name, $1 );
        print( _environment, string->name, 0 );
        Variable * var = variable_retrieve_or_define( _environment, $3, VT_DSTRING, 0 );
        input( _environment, var->name );
    }
    | String OP_SEMICOLON Identifier OP_SEMICOLON {
        Variable * string = variable_temporary( _environment, VT_STRING, "(string value)" );
        variable_store_string( _environment, string->name, $1 );
        print( _environment, string->name, 0 );
        input( _environment, $3 );
    }  input_definition2
    | String OP_SEMICOLON Identifier OP_DOLLAR OP_SEMICOLON {
        Variable * string = variable_temporary( _environment, VT_STRING, "(string value)" );
        variable_store_string( _environment, string->name, $1 );
        print( _environment, string->name, 0 );
        Variable * var = variable_retrieve_or_define( _environment, $3, VT_DSTRING, 0 );
        input( _environment, var->name );
    }  input_definition2
    | input_definition2
  ;

poke_definition : 
      expr OP_COMMA expr {
        poke_var( _environment, $1, $3 );
    };
  
define_definition :
      STRING COUNT const_expr {
        if ( $3 <= 0 ) {
            CRITICAL_INVALID_STRING_COUNT( $3 );
        }
        ((struct _Environment *)_environment)->dstring.count = $3;
    }
    | STRING SPACE const_expr {
        if ( $3 <= 0 ) {
            CRITICAL_INVALID_STRING_SPACE( $3 );
        }
        ((struct _Environment *)_environment)->dstring.space = $3;
    }
    | TASK COUNT const_expr {
        if ( $3 <= 0 ) {
            CRITICAL_INVALID_TASK_COUNT( $3 );
        }
        ((struct _Environment *)_environment)->protothreadConfig.count = $3;
    }
    | DEFAULT TYPE datatype {
        ((struct _Environment *)_environment)->defaultVariableType = $3;
    };

define_definitions :
      define_definition
    | define_definition OP_COMMA define_definitions;

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
    };

targets :
     target {
         $$ = $1;
     }
     | target OP_COMMA targets {
        $$ = $1 || $3;
     };

protothread_definition: 
    PARALLEL {
        $$ = 1;
    }
    | {
        $$ = 0;
    };

on_targets: 
      { $$ = 1; }
    | ON targets {
        $$ = $2;
    };

statement:
    BANK bank_definition
  | RASTER raster_definition
  | NEXT RASTER next_raster_definition
  | COLOR color_definition
  | WAIT wait_definition
  | SPRITE sprite_definition
  | BITMAP bitmap_definition
  | TEXTMAP textmap_definition
  | TILEMAP tilemap_definition
  | TEXT text_definition
  | TILES tiles_definition
  | COLORMAP colormap_definition
  | SCREEN screen_definition
  | POINT point_definition
  | PLOT plot_definition
  | CIRCLE circle_definition
  | ELLIPSE ellipse_definition
  | DRAW draw_definition
  | PUT put_definition
  | GET get_definition
  | MOB mob_definition
  | BOX box_definition
  | POLYLINE polyline_definition
  | CLIP clip_definition
  | SET LINE expr {
      variable_move( _environment, $3, "LINE" );
  }
  | INK ink_definition
  | VAR var_definition
  | TEXTADDRESS OP_ASSIGN expr {
      variable_move( _environment, $3, "ADDRESS" );
  }
  | EMPTY TILE OP_ASSIGN expr {
      variable_move( _environment, $4, "EMPTYTILE" );
  }
  | EMPTYTILE OP_ASSIGN expr {
      variable_move( _environment, $3, "EMPTYTILE" );
  }
  | ADD add_definition
  | POKE poke_definition
  | NOP {
      outline0( "NOP" );
  }
  | PRINT print_definition
  | PRINT {
      print_newline( _environment );
  }
  | DEBUG expr {
      print( _environment, $2, 0 );
  }
  | INPUT input_definition
  | QM print_definition
  | LOCATE locate_definition
  | GR LOCATE gr_locate_definition
  | MEMORIZE {
      memorize( _environment );
  }
  | REMEMBER {
      remember( _environment );
  }
  | HSCROLL hscroll_definition
  | VSCROLL vscroll_definition
  | CMOVE cmove_definition
  | CUP {
      cmove_direct( _environment, 0, -1 );
  }
  | CDOWN {
      cmove_direct( _environment, 0, 1 );
  }
  | CLEFT {
      cmove_direct( _environment, -1, 0 );
  }
  | CRIGHT {
      cmove_direct( _environment, 1, 0 );
  }
  | CLINE {
      cline( _environment, NULL );
  }
  | CLINE expr {
      cline( _environment, $2 );
  }
  | SET TAB expr {
      text_set_tab( _environment, $3 );
  }
  | CENTER expr {
      center( _environment, $2 );
  }
  | CENTRE expr {
      center( _environment, $2 );
  }
  | CLS {
      cls( _environment, NULL );
  }
  | CLS expr {
      cls( _environment, $2 );
  }
  | HOME {
      home( _environment );
  }
  | CLEAR KEY {
      clear_key( _environment );
  }
  | OP_INC Identifier {
      variable_increment( _environment, $2 );
  }
  | OP_DEC Identifier {
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
      else_if_then_label( _environment );  
      else_if_then( _environment, NULL );  
  }
  | ELSE IF {
      else_if_then_label( _environment );  
   }  expr THEN {
      else_if_then( _environment, $4 );  
  }
  | ELSEIF {
      else_if_then_label( _environment );  
   } expr THEN {
      else_if_then( _environment, $3 );  
  }
  | ENDIF {
      end_if_then( _environment );  
  }
  | SELECT CASE expr {
      select_case( _environment, $3 );  
  }
  | CASE {
      case_equals_label( _environment );  
  } expr {
      case_equals( _environment, $3 );  
  }
  | CASE ELSE {
      case_equals_label( _environment );  
      case_else( _environment );  
  }
  | ENDSELECT {
      end_select_case( _environment );  
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
  | EXIT PROC IF expr {
      exit_proc_if( _environment, $4, NULL );  
  }
  | EXIT PROCEDURE IF expr {
      exit_proc_if( _environment, $4, NULL );  
  }
  | EXIT PROC WITH expr IF expr {
      exit_proc_if( _environment, $6, $4 );  
  }
  | EXIT PROCEDURE WITH expr IF expr {
      exit_proc_if( _environment, $6, $4 );  
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
  | EXIT IF expr OP_COMMA Integer {
      exit_loop_if( _environment, $3, $5 );  
  }
  | EXIT IF expr OP_COMMA direct_integer {
      exit_loop_if( _environment, $3, $5 );  
  }
  | EXIT Integer IF expr {
      exit_loop_if( _environment, $4, $2 );  
  }
  | EXIT direct_integer IF expr  {
      exit_loop_if( _environment, $4, $2 );  
  }
  | FOR Identifier OP_ASSIGN expr TO expr {
      begin_for( _environment, $2, $4, $6 );  
  } 
  | NEXT {
      end_for( _environment );
  }
  | protothread_definition PROCEDURE Identifier on_targets {
        ((struct _Environment *)_environment)->parameters = 0;
      ((struct _Environment *)_environment)->protothread = $1;
        begin_procedure( _environment, $3 );
        ((struct _Environment *)_environment)->emptyProcedure = !$4;
  }
  | protothread_definition PROCEDURE Identifier {
      ((struct _Environment *)_environment)->parameters = 0;
      ((struct _Environment *)_environment)->protothread = $1;
    } OSP parameters CSP on_targets {
      begin_procedure( _environment, $3 );
      ((struct _Environment *)_environment)->emptyProcedure = !$8;
  }
  | SHARED parameters_expr {
      shared( _environment );
  }
  | GLOBAL parameters_expr {
      global( _environment );
  }
  | END PROC {
      ((struct _Environment *)_environment)->emptyProcedure = 0;
      end_procedure( _environment, NULL );
  }
  | END PROCEDURE {
      ((struct _Environment *)_environment)->emptyProcedure = 0;
      end_procedure( _environment, NULL );
  }
  | END PROC OSP expr CSP {
      ((struct _Environment *)_environment)->emptyProcedure = 0;
      end_procedure( _environment, $4 );
  }
  | FOR Identifier OP_ASSIGN expr TO expr STEP expr {
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
  | Identifier OSP CSP {
      ((struct _Environment *)_environment)->parameters = 0;
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
  | CALL Identifier OSP CSP {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, $2 );
  }
  | SPAWN Identifier {
      ((struct _Environment *)_environment)->parameters = 0;
      spawn_procedure( _environment, $2 );
  }
  | SPAWN Identifier OSP {
      ((struct _Environment *)_environment)->parameters = 0;
    } values CSP {
      spawn_procedure( _environment, $2 );
  }
  | SPAWN Identifier OSP CSP {
      ((struct _Environment *)_environment)->parameters = 0;
      spawn_procedure( _environment, $2 );
  }
  | YIELD {
      yield( _environment );
  }
  | PEN expr {
      pen( _environment, $2 );
  }
  | PAPER expr {
      paper( _environment, $2 );
  }
  | INVERSE ON {
      CRITICAL_NOT_SUPPORTED("INVERSE");
  }
  | INVERSE OFF {
      CRITICAL_NOT_SUPPORTED("INVERSE");
  }
  | WRITING writing_definition
  | Identifier OP_COLON {
      cpu_label( _environment, $1 );
  } 
  | LOAD String OP_COMMA Integer {
    load( _environment, $2, NULL, $4 );
  }
  | LOAD String AS String OP_COMMA Integer {
    load( _environment, $2, $4, $6 );
  }
  | RUN PARALLEL {
      run_parallel( _environment );
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
  | LEFT OP expr OP_COMMA expr CP OP_ASSIGN expr {
        variable_string_left_assign( _environment, $3, $5, $8 );
  }
  | RIGHT OP expr OP_COMMA expr CP OP_ASSIGN expr {
        variable_string_right_assign( _environment, $3, $5, $8 );
  }
  | MID OP expr OP_COMMA expr CP OP_ASSIGN expr {
        variable_string_mid_assign( _environment, $3, $5, NULL, $8 );
  }
  | MID OP expr OP_COMMA expr OP_COMMA expr CP OP_ASSIGN expr {
        variable_string_mid_assign( _environment, $3, $5, $7, $10 );
  }
  | DEFINE define_definitions
  | DIM dim_definitions
  | FILL fill_definitions
  | CONST Identifier OP_ASSIGN const_expr_string {
        const_define_string( _environment, $2, $4 );
  }
  | CONST Identifier OP_ASSIGN const_expr {
        const_define_numeric( _environment, $2, $4 );
  }
  | CONST POSITIVE Identifier OP_ASSIGN const_expr {
        if ( $5 < 0 ) {
            CRITICAL_NEGATIVE_CONSTANT( $3 );
        }
        const_define_numeric( _environment, $3, $5 );
  }
  | POSITIVE CONST Identifier OP_ASSIGN const_expr {
        if ( $5 < 0 ) {
            CRITICAL_NEGATIVE_CONSTANT( $3 );
        }
        const_define_numeric( _environment, $3, $5 );
  }
  | CONST Identifier IN OP const_expr OP_COMMA const_expr CP OP_ASSIGN const_expr  {
        if ( $10 < $5 ) {
            CRITICAL_TOO_LITTLE_CONSTANT( $2 );
        }
        if ( $10 > $7 ) {
            CRITICAL_TOO_BIG_CONSTANT( $2 );
        }
        const_define_numeric( _environment, $2, $10 );
  }
  | CONST Identifier IN OSP const_expr OP_COMMA const_expr CP OP_ASSIGN const_expr  {
        if ( $10 <= $5 ) {
            CRITICAL_TOO_LITTLE_CONSTANT( $2 );
        }
        if ( $10 > $7 ) {
            CRITICAL_TOO_BIG_CONSTANT( $2 );
        }
        const_define_numeric( _environment, $2, $10 );
  }
  | CONST Identifier IN OP const_expr OP_COMMA const_expr CSP OP_ASSIGN const_expr  {
        if ( $10 < $5 ) {
            CRITICAL_TOO_LITTLE_CONSTANT( $2 );
        }
        if ( $10 >= $7 ) {
            CRITICAL_TOO_BIG_CONSTANT( $2 );
        }
        const_define_numeric( _environment, $2, $10 );
  }
  | CONST Identifier IN OSP const_expr OP_COMMA const_expr CSP OP_ASSIGN const_expr {
        if ( $10 <= $5 ) {
            CRITICAL_TOO_LITTLE_CONSTANT( $2 );
        }
        if ( $10 >= $7 ) {
            CRITICAL_TOO_BIG_CONSTANT( $2 );
        }
        const_define_numeric( _environment, $2, $10 );
  }
  | TI OP_ASSIGN expr {
        set_timer( _environment, $3 );
  }
  | TIMER OP_ASSIGN expr {
        set_timer( _environment, $3 );
  }
  | Identifier OP_ASSIGN expr {
        Variable * expr = variable_retrieve( _environment, $3 );
        Variable * variable = variable_retrieve_or_define( _environment, $1, expr->type, 0 );
        if ( variable->type == VT_ARRAY ) {
            if ( expr->type != VT_BUFFER ) {
                CRITICAL_CANNOT_ASSIGN_TO_ARRAY( $1, DATATYPE_AS_STRING[expr->type] );
            }
            if ( expr->size != variable->size ) {
                CRITICAL_BUFFER_SIZE_MISMATCH_ARRAY_SIZE( $1, expr->size, variable->size );
            }
        }
        variable_move( _environment, $3, $1 );
  }
  | Identifier OP_ASSIGN OP_HASH const_expr {
        if ( !variable_exists( _environment, $1 ) ) {
            variable_retrieve_or_define( _environment, $1, VT_WORD, $4 );
        }
        variable_store( _environment, $1, $4 );
  }
  | Identifier OP_ASSIGN_DIRECT expr  {
        Variable * expr = variable_retrieve( _environment, $3 );
        Variable * var = variable_retrieve_or_define( _environment, $1, expr->type, 0 );
        var->value = expr->value;
        if ( expr->valueString ) {
            var->valueString = strdup( expr->valueString );
        }
        var->size = expr->size;
        if ( expr->valueBuffer ) {
            var->valueBuffer = malloc( expr->size );
            memcpy( var->valueBuffer, expr->valueBuffer, expr->size );
        }
        var->absoluteAddress = expr->absoluteAddress;
        var->bank = expr->bank;
        var->memoryArea = expr->memoryArea;
        var->arrayDimensions = expr->arrayDimensions;
        memcpy( var->arrayDimensionsEach, expr->arrayDimensionsEach, MAX_ARRAY_DIMENSIONS * sizeof( int ) );
        var->arrayType = expr->arrayType;
        var->frameSize = expr->frameSize;
        var->frameCount = expr->frameCount;
        expr->assigned = 1;
  }
  | ARRAY Identifier {
      
    } OP_ASSIGN {
      Variable * var = variable_retrieve( _environment, $2 );
      if ( var->type != VT_ARRAY ) {
          CRITICAL_NOT_ARRAY( $2 );
      }
      ((struct _Environment *)_environment)->currentArray = var;
  } array_reassign 
  | ARRAY Identifier {
      
    } OP_ASSIGN_DIRECT {
      Variable * var = variable_retrieve( _environment, $2 );
      if ( var->type != VT_ARRAY ) {
          CRITICAL_NOT_ARRAY( $2 );
      }
      ((struct _Environment *)_environment)->currentArray = var;
  } array_reassign
  | Identifier OP_DOLLAR OP_ASSIGN expr {
        Variable * expr = variable_retrieve( _environment, $4 );
        variable_retrieve_or_define( _environment, $1, VT_DSTRING, 0 )->name;
        variable_move( _environment, $4, $1 );
  }
  | Identifier {
        ++((struct _Environment *)_environment)->arrayNestedIndex;
        memset( ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex], 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex] = 0;
    }
      OP indexes CP OP_ASSIGN expr {
        Variable * expr = variable_retrieve( _environment, $7 );
        Variable * array = variable_retrieve( _environment, $1 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( $1 );
        }
        variable_move_array( _environment, $1, expr->name );
        --((struct _Environment *)_environment)->arrayNestedIndex;
  }
  | Identifier OP_DOLLAR {
        ++((struct _Environment *)_environment)->arrayNestedIndex;
        memset( ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex], 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex] = 0;
    } OP indexes CP OP_ASSIGN expr {
        Variable * x = variable_retrieve( _environment, $8 );
        Variable * a = variable_retrieve( _environment, $1 );
        if ( x->type != VT_STRING && x->type != VT_DSTRING ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[x->type], DATATYPE_AS_STRING[VT_DSTRING] );
        }
        if ( a->type != VT_ARRAY ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[a->type], DATATYPE_AS_STRING[VT_ARRAY] );
        }
        if ( a->arrayType != VT_DSTRING ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[a->arrayType], DATATYPE_AS_STRING[VT_DSTRING] );
        }
        variable_move_array_string( _environment, $1, x->name );
        --((struct _Environment *)_environment)->arrayNestedIndex;
  }
  | Identifier {
        ++((struct _Environment *)_environment)->arrayNestedIndex;
        memset( ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex], 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex] = 0;
    } datatype OP indexes CP OP_ASSIGN expr {
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
        --((struct _Environment *)_environment)->arrayNestedIndex;
  }
  | OSP Identifier CSP {
        ++((struct _Environment *)_environment)->arrayNestedIndex;
        memset( ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex], 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex] = 0;
    }
      OP_ASSIGN expr {
        ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex][((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex]] = strdup( "PROTOTHREADCT" );
        ++((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex];
        Variable * expr = variable_retrieve( _environment, $6 );
        Variable * array = variable_retrieve( _environment, $2 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( $2 );
        }
        variable_move_array( _environment, $2, expr->name );
        --((struct _Environment *)_environment)->arrayNestedIndex;
  }
  | OSP Identifier OP_DOLLAR CSP {
        ++((struct _Environment *)_environment)->arrayNestedIndex;
        memset( ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex], 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex] = 0;
    } OP_ASSIGN expr {
        ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex][((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex]] = strdup( "PROTOTHREADCT" );
        ++((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex];
        Variable * x = variable_retrieve( _environment, $7 );
        Variable * a = variable_retrieve( _environment, $2 );
        if ( x->type != VT_STRING && x->type != VT_DSTRING ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[x->type], DATATYPE_AS_STRING[VT_DSTRING] );
        }
        if ( a->type != VT_ARRAY ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[a->type], DATATYPE_AS_STRING[VT_ARRAY] );
        }
        if ( a->arrayType != VT_DSTRING ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[a->arrayType], DATATYPE_AS_STRING[VT_DSTRING] );
        }
        variable_move_array_string( _environment, $2, x->name );
        --((struct _Environment *)_environment)->arrayNestedIndex;
  }
  | OSP Identifier CSP {
        ++((struct _Environment *)_environment)->arrayNestedIndex;
        memset( ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex], 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex] = 0;
    } datatype OP_ASSIGN expr {
        ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex][((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex]] = strdup( "PROTOTHREADCT" );
        ++((struct _Environment *)_environment)->arrayIndexes[((struct _Environment *)_environment)->arrayNestedIndex];

        Variable * x = variable_retrieve( _environment, $7 );
        Variable * a = variable_retrieve( _environment, $2 );
        if ( x->type != $5 ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[x->type], DATATYPE_AS_STRING[$5] );
        }
        if ( a->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( $2 );
        }
        if ( a->arrayType != $5 ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[a->arrayType], DATATYPE_AS_STRING[$5] );
        }
        variable_move_array( _environment, $2, x->name );
        --((struct _Environment *)_environment)->arrayNestedIndex;
  }
  | Remark
  |
  ;

statements_no_linenumbers:
      statement { ((Environment *)_environment)->yylineno = yylineno; variable_reset( _environment ); }
    | statement OP_COLON { ((Environment *)_environment)->yylineno = yylineno; variable_reset( _environment );  } statements_no_linenumbers { }
    ;

statements_with_linenumbers:
      Integer {
        outhead1("; BEGIN LINE %d OF BASIC PROGRAM", $1);
        char lineNumber[MAX_TEMPORARY_STORAGE];
        sprintf(lineNumber, "_linenumber%d", $1 );
        cpu_label( _environment, lineNumber);
    } statements_no_linenumbers { 
        ((Environment *)_environment)->yylineno = yylineno;
    };

statements_complex:
    Identifier NewLine {
        if ( strcmp( $1, "REM" ) != 0 ) {
            call_procedure( _environment, $1 );
        }
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

    char version[MAX_TEMPORARY_STORAGE] = "v1.5";

#if defined(__atari__) 
    char target[MAX_TEMPORARY_STORAGE] = "ATARI 400/800";
#elif defined(__atarixl__) 
    char target[MAX_TEMPORARY_STORAGE] = "ATARI XL";
#elif __c64__
    char target[MAX_TEMPORARY_STORAGE] = "Commodore 64";
#elif __plus4__
    char target[MAX_TEMPORARY_STORAGE] = "Commodore PLUS/4";
#elif __zx__
    char target[MAX_TEMPORARY_STORAGE] = "ZX Spectrum 48K";
#elif __d32__
    char target[MAX_TEMPORARY_STORAGE] = "Dragon 32";
#elif __d64__
    char target[MAX_TEMPORARY_STORAGE] = "Dragon 64";
#elif __pc128op__
    char target[MAX_TEMPORARY_STORAGE] = "PC128 Olivetti Prodest / Thomson MO6";
#elif __mo5__
    char target[MAX_TEMPORARY_STORAGE] = "Thomson MO5";
#elif __vic20__
    char target[MAX_TEMPORARY_STORAGE] = "Commodore VIC-20";
#endif

    printf("--------------------------------------------------\n");
    printf("ugBASIC Compiler %s [target: %s]\n", version, target);
    printf("--------------------------------------------------\n");
    printf("Copyright 2021 Marco Spedaletti (asimov@mclink.it)\n\n");
    printf("Licensed under the Apache License, Version 2.0 (the \"License\");\n");
    printf("you may not use this program except in compliance with the License.\n\n");

    printf("usage: %s [options] <source>\n\n", _argv[0] );

    printf("Options and parameters:\n" );
    printf("\t<source>     Input filename with ugBASIC source code\n" );
    printf("\t<asm>        Output filename with ASM source code (optional if '-o' given)\n" );
    printf("\t-a           Show statistics on assembly listing generated\n" );
    printf("\t-I           Install needed chaintool for this target\n" );
    printf("\t-d           Enable debugging of IMAGE LOAD\n" );
    printf("\t-c <file>    Output filename with linker configuration\n" );
    printf("\t-o <exe>     Output filename with final executable file for target\n" );
    printf("\t-O <type>    Output file format for target:\n" );
#if __atari__ 
    printf("\t                xex - executable binary file\n" );
#elif __atarixl__ 
    printf("\t                xex - executable binary file\n" );
#elif __c64__
    printf("\t                prg - program binary file\n" );
#elif __plus4__
    printf("\t                prg - program binary file\n" );
#elif __zx__
    printf("\t                tap - tape file\n" );
#elif __d32__
    printf("\t                bin - dragon dos binary file\n" );
#elif __d64__
    printf("\t                bin - dragon dos binary file\n" );
#elif __pc128op__
    printf("\t                k7o - K7 format (original algorithm)\n" );
    printf("\t                k7 - K7 format\n" );
#elif __mo5__
    printf("\t                k7o - K7 format (original algorithm)\n" );
    printf("\t                k7 - K7 format\n" );
#elif __vic20__
    printf("\t                prg - program binary file\n" );
#endif
    printf("\t-l <name>    Output filename with list of variables defined\n" );
    printf("\t-e <modules> Embed specified modules instead of inline code\n" );
#if __zx__
    printf("\t-L <ignored> Output filename with assembly listing file\n" );
#else
    printf("\t-L <listing> Output filename with assembly listing file\n" );
#endif
    printf("\t-E           Show stats of embedded modules\n" );
    printf("\t-W           Enable warnings during compilation\n" );
    exit(EXIT_FAILURE);
}

int main( int _argc, char *_argv[] ) {
    extern FILE *yyin;
    int flags, opt;
    int nsecs, tfnd;
    Environment * _environment = malloc(sizeof(Environment));
    memset( _environment, 0, sizeof(Environment));

    setup_embedded( _environment );

    _environment->warningsEnabled = 0;

    _environment->defaultVariableType = VT_WORD;

#if defined(__atari__) 
    _environment->outputFileType = OUTPUT_FILE_TYPE_XEX;
#elif defined(__atarixl__) 
    _environment->outputFileType = OUTPUT_FILE_TYPE_XEX;
#elif __c64__
    _environment->outputFileType = OUTPUT_FILE_TYPE_PRG;
#elif __plus4__
    _environment->outputFileType = OUTPUT_FILE_TYPE_PRG;
#elif __zx__
    _environment->outputFileType = OUTPUT_FILE_TYPE_TAP;
#elif __d32__
    _environment->outputFileType = OUTPUT_FILE_TYPE_BIN;
#elif __d64__
    _environment->outputFileType = OUTPUT_FILE_TYPE_BIN;
#elif __pc128op__
    _environment->outputFileType = OUTPUT_FILE_TYPE_K7_NEW;
#elif __mo5__
    _environment->outputFileType = OUTPUT_FILE_TYPE_K7_NEW;
#elif __vic20__
    _environment->outputFileType = OUTPUT_FILE_TYPE_PRG;
#endif

    while ((opt = getopt(_argc, _argv, "ae:c:Wo:Ie:l:EO:dL:")) != -1) {
        switch (opt) {
                case 'a':
                    if ( ! _environment->listingFileName ) {
                        char listingFileName[MAX_TEMPORARY_STORAGE];
                        sprintf( listingFileName, "%s.lst", tmpnam(NULL) );
                        _environment->listingFileName = strdup(listingFileName);
                    }
                    _environment->analysis = 1;
                    break;
                case 'c':
                    _environment->configurationFileName = strdup(optarg);
                    break;
                case 'o':
                    _environment->exeFileName = strdup(optarg);
                    break;
                case 'd':
                    _environment->debugImageLoad = 1;
                    break;
                case 'O':
                    if ( strcmp( optarg, "bin") == 0 ) {
                        _environment->outputFileType = OUTPUT_FILE_TYPE_BIN;
                    } else if ( strcmp( optarg, "prg") == 0 ) {
                        _environment->outputFileType = OUTPUT_FILE_TYPE_PRG;
                    } else if ( strcmp( optarg, "xex") == 0 ) {
                        _environment->outputFileType = OUTPUT_FILE_TYPE_XEX;
                    } else if ( strcmp( optarg, "k7o") == 0 ) {
                        _environment->outputFileType = OUTPUT_FILE_TYPE_K7_ORIGINAL;
                    } else if ( strcmp( optarg, "k7") == 0 ) {
                        _environment->outputFileType = OUTPUT_FILE_TYPE_K7_NEW;
                    } else if ( strcmp( optarg, "tap") == 0 ) {
                        _environment->outputFileType = OUTPUT_FILE_TYPE_K7_NEW;
                    }
                    break;
                case 'W':
                    _environment->warningsEnabled = 1;
                    break;
                case 'I':
                    _environment->installChainTool = 1;
                    break;
                case 'l':
                    _environment->debuggerLabelsFileName = strdup(optarg);
                    break;
                case 'L':
                    _environment->listingFileName = strdup(optarg);
                    break;
                case 'E':
                    _environment->embeddedStatsEnabled = 1;
                    break;
                case 'e': {
                    char * p = strtok(optarg, ",");
                    while (p) {

                        parse_embedded( p, cpu_beq );
                        parse_embedded( p, cpu_bneq );
                        parse_embedded( p, cpu_busy_wait );
                        parse_embedded( p, cpu_bveq );
                        parse_embedded( p, cpu_bvneq );
                        parse_embedded( p, cpu_combine_nibbles );
                        parse_embedded( p, cpu_compare_16bit );
                        parse_embedded( p, cpu_compare_32bit );
                        parse_embedded( p, cpu_compare_8bit );
                        parse_embedded( p, cpu_di );
                        parse_embedded( p, cpu_ei );
                        parse_embedded( p, cpu_inc );
                        parse_embedded( p, cpu_inc_16bit );
                        parse_embedded( p, cpu_inc_32bit );
                        parse_embedded( p, cpu_dec );
                        parse_embedded( p, cpu_dec_16bit );
                        parse_embedded( p, cpu_less_than_16bit );
                        parse_embedded( p, cpu_less_than_32bit );
                        parse_embedded( p, cpu_less_than_8bit );
                        parse_embedded( p, cpu_greater_than_16bit );
                        parse_embedded( p, cpu_greater_than_32bit );
                        parse_embedded( p, cpu_greater_than_8bit );
                        parse_embedded( p, cpu_fill );
                        parse_embedded( p, cpu_fill_blocks );
                        parse_embedded( p, cpu_halt );
                        parse_embedded( p, cpu_end );
                        parse_embedded( p, cpu_jump );
                        parse_embedded( p, cpu_call );
                        parse_embedded( p, cpu_return );
                        parse_embedded( p, cpu_pop );
                        parse_embedded( p, cpu_label );
                        parse_embedded( p, cpu_limit_16bit );
                        parse_embedded( p, cpu_logical_not_8bit );
                        parse_embedded( p, cpu_logical_and_8bit );
                        parse_embedded( p, cpu_logical_or_8bit );
                        parse_embedded( p, cpu_not_8bit );
                        parse_embedded( p, cpu_and_8bit );
                        parse_embedded( p, cpu_or_8bit );
                        parse_embedded( p, cpu_not_16bit );
                        parse_embedded( p, cpu_and_16bit );
                        parse_embedded( p, cpu_or_16bit );
                        parse_embedded( p, cpu_not_16bit );
                        parse_embedded( p, cpu_and_16bit );
                        parse_embedded( p, cpu_or_16bit );
                        parse_embedded( p, cpu_not_32bit );
                        parse_embedded( p, cpu_and_32bit );
                        parse_embedded( p, cpu_or_32bit );
                        parse_embedded( p, cpu_math_add_16bit );
                        parse_embedded( p, cpu_math_add_16bit_with_16bit );
                        parse_embedded( p, cpu_math_add_16bit_with_8bit );
                        parse_embedded( p, cpu_math_add_32bit );
                        parse_embedded( p, cpu_math_add_8bit );
                        parse_embedded( p, cpu_math_and_const_16bit );
                        parse_embedded( p, cpu_math_and_const_32bit );
                        parse_embedded( p, cpu_math_and_const_8bit );
                        parse_embedded( p, cpu_math_complement_const_16bit );
                        parse_embedded( p, cpu_math_complement_const_32bit );
                        parse_embedded( p, cpu_math_complement_const_8bit );
                        parse_embedded( p, cpu_math_div2_8bit );
                        parse_embedded( p, cpu_math_div2_const_16bit );
                        parse_embedded( p, cpu_math_div2_const_32bit );
                        parse_embedded( p, cpu_math_div2_const_8bit );
                        parse_embedded( p, cpu_math_double_16bit );
                        parse_embedded( p, cpu_math_double_32bit );
                        parse_embedded( p, cpu_math_double_8bit );
                        parse_embedded( p, cpu_math_mul_16bit_to_32bit );
                        parse_embedded( p, cpu_math_mul_8bit_to_16bit );
                        parse_embedded( p, cpu_math_div_32bit_to_16bit );
                        parse_embedded( p, cpu_math_div_16bit_to_16bit );
                        parse_embedded( p, cpu_math_div_8bit_to_8bit );
                        parse_embedded( p, cpu_math_mul2_const_16bit );
                        parse_embedded( p, cpu_math_mul2_const_32bit );
                        parse_embedded( p, cpu_math_mul2_const_8bit );
                        parse_embedded( p, cpu_math_sub_16bit );
                        parse_embedded( p, cpu_math_sub_32bit );
                        parse_embedded( p, cpu_math_sub_8bit );
                        parse_embedded( p, cpu_math_sub_16bit_with_8bit );
                        parse_embedded( p, cpu_move_16bit );
                        parse_embedded( p, cpu_addressof_16bit );
                        parse_embedded( p, cpu_move_32bit );
                        parse_embedded( p, cpu_move_8bit );
                        parse_embedded( p, cpu_peek );
                        parse_embedded( p, cpu_poke );
                        parse_embedded( p, cpu_random );
                        parse_embedded( p, cpu_random_16bit );
                        parse_embedded( p, cpu_random_32bit );
                        parse_embedded( p, cpu_random_8bit );
                        parse_embedded( p, cpu_store_16bit );
                        parse_embedded( p, cpu_store_32bit );
                        parse_embedded( p, cpu_store_8bit );
                        parse_embedded( p, cpu_mem_move );
                        parse_embedded( p, cpu_mem_move_direct );
                        parse_embedded( p, cpu_mem_move_size );
                        parse_embedded( p, cpu_mem_move_direct_size );
                        parse_embedded( p, cpu_mem_move_direct_indirect_size );
                        parse_embedded( p, cpu_compare_memory );
                        parse_embedded( p, cpu_compare_memory_size );
                        parse_embedded( p, cpu_less_than_memory );
                        parse_embedded( p, cpu_less_than_memory_size );
                        parse_embedded( p, cpu_greater_than_memory );
                        parse_embedded( p, cpu_greater_than_memory_size );
                        parse_embedded( p, cpu_uppercase );
                        parse_embedded( p, cpu_lowercase );
                        parse_embedded( p, cpu_convert_string_into_16bit );
                        parse_embedded( p, cpu_fill_indirect );
                        parse_embedded( p, cpu_flip );
                        parse_embedded( p, cpu_move_8bit_indirect );
                        parse_embedded( p, cpu_move_8bit_indirect2 );
                        parse_embedded( p, cpu_move_16bit_indirect );
                        parse_embedded( p, cpu_move_16bit_indirect2 );
                        parse_embedded( p, cpu_move_32bit_indirect );
                        parse_embedded( p, cpu_move_32bit_indirect2 );
                        parse_embedded( p, cpu_bit_check );
                        parse_embedded( p, cpu_number_to_string );
                        parse_embedded( p, cpu_move_8bit_indirect_with_offset );
                        parse_embedded( p, cpu_bits_to_string );
                        parse_embedded( p, cpu_bit_check_extended );
                        parse_embedded( p, cpu_move_8bit_indirect_with_offset2 );
                        parse_embedded( p, cpu_dsdefine );
                        parse_embedded( p, cpu_dsalloc );
                        parse_embedded( p, cpu_dsfree );
                        parse_embedded( p, cpu_dswrite );
                        parse_embedded( p, cpu_dsresize );
                        parse_embedded( p, cpu_dsresize_size );
                        parse_embedded( p, cpu_dsgc );
                        parse_embedded( p, cpu_dsdescriptor );
                        parse_embedded( p, cpu_move_8bit_with_offset );
                        parse_embedded( p, cpu_move_8bit_with_offset2 );
                        parse_embedded( p, cpu_store_8bit_with_offset );
                        parse_embedded( p, cpu_dsalloc_size );
                        parse_embedded( p, cpu_complement2_8bit );
                        parse_embedded( p, cpu_complement2_16bit );
                        parse_embedded( p, cpu_complement2_32bit );
                        parse_embedded( p, cpu_mobinit );
                        parse_embedded( p, cpu_mobshow );
                        parse_embedded( p, cpu_mobhide );
                        parse_embedded( p, cpu_mobat );
                        parse_embedded( p, cpu_mobrender );
                        parse_embedded( p, cpu_sqroot );

                        p = strtok(NULL, ",");
                    }

                    }
                    break;
                default: /* '?' */
                    show_usage_and_exit( _argc, _argv );
                }
    }

    if ( _environment->installChainTool ) {
        target_install( _environment );
    }
    
    if ( ! _argv[optind] ) {
        show_usage_and_exit( _argc, _argv );
    }

    if ( ! _argv[optind+1] && !_environment->exeFileName ) {
        show_usage_and_exit( _argc, _argv );
    }

    _environment->sourceFileName = strdup(_argv[optind] );

    if ( _environment->exeFileName && !_argv[optind+1]) {
        char asmFileName[MAX_TEMPORARY_STORAGE];
        sprintf( asmFileName, "%s.asm", tmpnam(NULL) );
        _environment->asmFileName = strdup(asmFileName);
    } else {
        _environment->asmFileName = strdup(_argv[optind+1] );
    }
    
    yyin = fopen( _environment->sourceFileName, "r" );
    if ( ! yyin ) {
        fprintf(stderr, "Unable to open source file: %s\n", _environment->sourceFileName );
        exit(EXIT_FAILURE);
    }
    
    begin_compilation( _environment );

    yydebug = 1;
    errors = 0;
    yyparse (_environment);

    end_compilation( _environment );

    target_peephole_optimizer( _environment );

    if ( _environment->exeFileName ) {
        begin_build( _environment );
        end_build( _environment );
    }

    if ( _environment->embeddedStatsEnabled ) {
        printf( "Stats of embedded modules:\n");
        stats_embedded( cpu_beq );
        stats_embedded( cpu_bneq );
        stats_embedded( cpu_busy_wait );
        stats_embedded( cpu_bveq );
        stats_embedded( cpu_bvneq );
        stats_embedded( cpu_combine_nibbles );
        stats_embedded( cpu_compare_16bit );
        stats_embedded( cpu_compare_32bit );
        stats_embedded( cpu_compare_8bit );
        stats_embedded( cpu_di );
        stats_embedded( cpu_ei );
        stats_embedded( cpu_inc );
        stats_embedded( cpu_inc_16bit );
        stats_embedded( cpu_inc_32bit );
        stats_embedded( cpu_dec );
        stats_embedded( cpu_dec_16bit );
        stats_embedded( cpu_less_than_16bit );
        stats_embedded( cpu_less_than_32bit );
        stats_embedded( cpu_less_than_8bit );
        stats_embedded( cpu_greater_than_16bit );
        stats_embedded( cpu_greater_than_32bit );
        stats_embedded( cpu_greater_than_8bit );
        stats_embedded( cpu_fill );
        stats_embedded( cpu_fill_blocks );
        stats_embedded( cpu_halt );
        stats_embedded( cpu_end );
        stats_embedded( cpu_jump );
        stats_embedded( cpu_call );
        stats_embedded( cpu_return );
        stats_embedded( cpu_pop );
        stats_embedded( cpu_label );
        stats_embedded( cpu_limit_16bit );
        stats_embedded( cpu_logical_not_8bit );
        stats_embedded( cpu_logical_and_8bit );
        stats_embedded( cpu_logical_or_8bit );
        stats_embedded( cpu_not_8bit );
        stats_embedded( cpu_and_8bit );
        stats_embedded( cpu_or_8bit );
        stats_embedded( cpu_not_16bit );
        stats_embedded( cpu_and_16bit );
        stats_embedded( cpu_or_16bit );
        stats_embedded( cpu_not_32bit );
        stats_embedded( cpu_and_32bit );
        stats_embedded( cpu_or_32bit );
        stats_embedded( cpu_math_add_16bit );
        stats_embedded( cpu_math_add_16bit_with_16bit );
        stats_embedded( cpu_math_add_16bit_with_8bit );
        stats_embedded( cpu_math_add_32bit );
        stats_embedded( cpu_math_add_8bit );
        stats_embedded( cpu_math_and_const_16bit );
        stats_embedded( cpu_math_and_const_32bit );
        stats_embedded( cpu_math_and_const_8bit );
        stats_embedded( cpu_math_complement_const_16bit );
        stats_embedded( cpu_math_complement_const_32bit );
        stats_embedded( cpu_math_complement_const_8bit );
        stats_embedded( cpu_math_div2_8bit );
        stats_embedded( cpu_math_div2_const_16bit );
        stats_embedded( cpu_math_div2_const_32bit );
        stats_embedded( cpu_math_div2_const_8bit );
        stats_embedded( cpu_math_double_16bit );
        stats_embedded( cpu_math_double_32bit );
        stats_embedded( cpu_math_double_8bit );
        stats_embedded( cpu_math_mul_16bit_to_32bit );
        stats_embedded( cpu_math_mul_8bit_to_16bit );
        stats_embedded( cpu_math_div_32bit_to_16bit );
        stats_embedded( cpu_math_div_16bit_to_16bit );
        stats_embedded( cpu_math_div_8bit_to_8bit );
        stats_embedded( cpu_math_mul2_const_16bit );
        stats_embedded( cpu_math_mul2_const_32bit );
        stats_embedded( cpu_math_mul2_const_8bit );
        stats_embedded( cpu_math_sub_16bit );
        stats_embedded( cpu_math_sub_32bit );
        stats_embedded( cpu_math_sub_8bit );
        stats_embedded( cpu_math_sub_16bit_with_8bit );
        stats_embedded( cpu_move_16bit );
        stats_embedded( cpu_addressof_16bit );
        stats_embedded( cpu_move_32bit );
        stats_embedded( cpu_move_8bit );
        stats_embedded( cpu_peek );
        stats_embedded( cpu_poke );
        stats_embedded( cpu_random );
        stats_embedded( cpu_random_16bit );
        stats_embedded( cpu_random_32bit );
        stats_embedded( cpu_random_8bit );
        stats_embedded( cpu_store_16bit );
        stats_embedded( cpu_store_32bit );
        stats_embedded( cpu_store_8bit );
        stats_embedded( cpu_mem_move );
        stats_embedded( cpu_mem_move_direct );
        stats_embedded( cpu_mem_move_size );
        stats_embedded( cpu_mem_move_direct_size );
        stats_embedded( cpu_mem_move_direct_indirect_size );
        stats_embedded( cpu_compare_memory );
        stats_embedded( cpu_compare_memory_size );
        stats_embedded( cpu_less_than_memory );
        stats_embedded( cpu_less_than_memory_size );
        stats_embedded( cpu_greater_than_memory );
        stats_embedded( cpu_greater_than_memory_size );
        stats_embedded( cpu_uppercase );
        stats_embedded( cpu_lowercase );
        stats_embedded( cpu_convert_string_into_16bit );
        stats_embedded( cpu_fill_indirect );
        stats_embedded( cpu_flip );
        stats_embedded( cpu_move_8bit_indirect );
        stats_embedded( cpu_move_8bit_indirect2 );
        stats_embedded( cpu_move_16bit_indirect );
        stats_embedded( cpu_move_16bit_indirect2 );
        stats_embedded( cpu_move_32bit_indirect );
        stats_embedded( cpu_move_32bit_indirect2 );
        stats_embedded( cpu_bit_check );
        stats_embedded( cpu_number_to_string );
        stats_embedded( cpu_move_8bit_indirect_with_offset );
        stats_embedded( cpu_bits_to_string );
        stats_embedded( cpu_bit_check_extended );
        stats_embedded( cpu_move_8bit_indirect_with_offset2 );
        stats_embedded( cpu_dsdefine );
        stats_embedded( cpu_dsalloc );
        stats_embedded( cpu_dsfree );
        stats_embedded( cpu_dswrite );
        stats_embedded( cpu_dsresize );
        stats_embedded( cpu_dsresize_size );
        stats_embedded( cpu_dsgc );
        stats_embedded( cpu_dsdescriptor );
        stats_embedded( cpu_move_8bit_with_offset );
        stats_embedded( cpu_move_8bit_with_offset2 );
        stats_embedded( cpu_store_8bit_with_offset );
        stats_embedded( cpu_dsalloc_size );
        stats_embedded( cpu_complement2_8bit );
        stats_embedded( cpu_complement2_16bit );
        stats_embedded( cpu_complement2_32bit );
        stats_embedded( cpu_mobinit );
        stats_embedded( cpu_mobshow );
        stats_embedded( cpu_mobhide );
        stats_embedded( cpu_mobat );
        stats_embedded( cpu_mobrender );
        stats_embedded( cpu_sqroot );
    }

}

int yyerror (Environment * _ignored, const char *s) /* Called by yyparse on error */
{
        // TODO: better error message (like other compilers)
      printf( "*** ERROR: %s at %d\n", s, yylineno);
      exit(EXIT_FAILURE);
}

