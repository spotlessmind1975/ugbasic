%{

#include "../src/ugbc.h"

int yylex();
int yyerror(Environment *, const char *);
int yydebug=0;
int errors=0;
extern int yylineno;

int yywrap() { return 1; }
 
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
%token SEMICOLON COLON COMMA PLUS MINUS INC DEC EQUAL ASSIGN LT LTE GT GTE DISEQUAL MULTIPLICATION DOLLAR DIVISION

%token RASTER DONE AT COLOR BORDER WAIT NEXT WITH BANK SPRITE DATA FROM OP CP 
%token ENABLE DISABLE HALT ECM BITMAP SCREEN ON OFF ROWS VERTICAL SCROLL VAR AS TEMPORARY 
%token XPEN YPEN PEEK GOTO HORIZONTAL MCM COMPRESS EXPAND LOOP REPEAT WHILE TEXT TILES
%token COLORMAP SELECT MONOCOLOR MULTICOLOR COLLISION IF THEN HIT BACKGROUND TO RANDOM
%token BYTE WORD POSITION CODE VARIABLES MS CYCLES S HASH WIDTH HEIGHT DWORD PEN CLEAR
%token BEG END GAMELOOP ENDIF UP DOWN LEFT RIGHT DEBUG AND RANDOMIZE GRAPHIC TEXTMAP
%token POINT GOSUB RETURN POP OR ELSE NOT TRUE FALSE DO EXIT WEND UNTIL FOR STEP EVERY
%token MID INSTR UPPER LOWER STR VAL STRING SPACE FLIP CHR ASC LEN POW MOD ADD MIN MAX

%token MILLISECOND MILLISECONDS TICKS

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

%right Integer String CP
%left OP
%right THEN ELSE
%left POW
%left MULTIPLICATION DIVISION
%left MOD
%left PLUS MINUS
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
        $$ = variable_pow( _environment, $1, $3 )->name;
        outline3("; %s = %s ^ %s", $$, $1, $3 );
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
        $$ = $1;
      }
    | Identifier DOLLAR { 
        $$ = $1;
      }
    | Integer { 
        $$ = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
        variable_store( _environment, $$, $1 );
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
    | OP WORD CP Integer { 
        $$ = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, $$, $4 );
      }
    | OP DWORD CP Integer { 
        $$ = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, $$, $4 );
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
    | PEEK OP direct_integer CP {
        $$ = peek( _environment, $3 )->name;
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
    | OP expr CP {
        $$ = $2;
    }
    | MAX OP expr COMMA expr CP {
        $$ = variable_max( _environment, $3, $5 )->name;
    }
    | MIN OP expr COMMA expr CP {
        $$ = variable_min( _environment, $3, $5 )->name;
    }
    | TRUE {
        $$ = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, $$, 255 );
    }
    | FALSE {
        $$ = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, $$, 255 );
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

text_definition:
  text_definition_simple;

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
      variable_define( _environment, $1, VT_BYTE, 0 );
  }
  | Identifier DOLLAR ON Identifier {
      variable_define( _environment, $1, VT_STRING, 0 );
  }
  | Identifier ON Identifier ASSIGN direct_integer {
      variable_define( _environment, $1, VT_BYTE, $5 );
  }
  | Identifier ON Identifier ASSIGN expr {
      Variable * v = variable_retrieve( _environment, $5 );
      Variable * d = variable_define( _environment, $1, v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
  | Identifier DOLLAR ON Identifier ASSIGN expr {
      Variable * v = variable_retrieve( _environment, $6 );
      Variable * d = variable_define( _environment, $1, VT_STRING, 0 );
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

on_definition:
      expr GOTO {
          on_goto( _environment, $1 );
      } on_goto_definition
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
  | VAR var_definition
  | ADD add_definition
  | INC Identifier {
      variable_increment( _environment, $2 );
  }
  | DEC Identifier {
      variable_decrement( _environment, $2 );
  }
  | RANDOMIZE {
      randomize( _environment );
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
  | FOR Identifier ASSIGN expr TO expr STEP expr {
      begin_for_step( _environment, $2, $4, $6, $8 );  
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
  | ON on_definition
  | GOTO goto_definition
  | GOSUB gosub_definition
  | EVERY every_definition
  | RETURN {
      return_label( _environment );
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
  | Identifier COLON {
      outhead1("%s:", $1);
  }
  | Identifier ASSIGN expr {
        outline2("; %s = %s", $1, $3 );
        Variable * expr = variable_retrieve( _environment, $3 );
        outline1("; retrieved %s ", $3 );
        variable_define( _environment, $1, expr->type, 0 )->name;
        outline1("; defined %s ", $1 );
        variable_move( _environment, $3, $1 );
        outline2("; moved %s -> %s ", $3, $1 );
  }
  | Identifier DOLLAR ASSIGN expr {
        outline2("; %s = %s", $1, $4 );
        Variable * expr = variable_retrieve( _environment, $4 );
        outline1("; retrieved %s ", $4 );
        variable_define( _environment, $1, VT_STRING, 0 )->name;
        outline1("; defined %s ", $1 );
        variable_move( _environment, $4, $1 );
        outline2("; moved %s -> %s ", $4, $1 );
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
      statements_no_linenumbers
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
    exit(EXIT_FAILURE);
}

int main( int _argc, char *_argv[] ) {
    extern FILE *yyin;
    int flags, opt;
    int nsecs, tfnd;
    Environment * _environment = malloc(sizeof(Environment));

    while ((opt = getopt(_argc, _argv, "e:c:")) != -1) {
        switch (opt) {
                case 'c':
                    _environment->configurationFileName = strdup(optarg);
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

    bank_define( _environment, "VARIABLES", BT_VARIABLES, 0x4000, NULL );
    bank_define( _environment, "TEMPORARY", BT_TEMPORARY, 0x4100, NULL );

    if ( _environment->configurationFileName ) {
        _environment->configurationFile = fopen( _environment->configurationFileName, "wt");
        if ( ! _environment->configurationFile ) {
            fprintf(stderr, "Unable to open configuration file: %s\n", _environment->configurationFileName );
            exit(EXIT_FAILURE);
        }
        linker_setup( _environment );
        outhead0(".segment \"CODE\"");
        variable_define( _environment, "strings_address", VT_ADDRESS, 0x4200 );
        bank_define( _environment, "STRINGS", BT_STRINGS, 0x4200, NULL );
    } else {
        outhead0("org 32768");
        variable_define( _environment, "strings_address", VT_ADDRESS, 0xa000 );
    }


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

