%{

/*****************************************************************************
 * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
 *****************************************************************************
 * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *----------------------------------------------------------------------------
 * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
 * (la "Licenza"); è proibito usare questo file se non in conformità alla
 * Licenza. Una copia della Licenza è disponibile all'indirizzo:
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Se non richiesto dalla legislazione vigente o concordato per iscritto,
 * il software distribuito nei termini della Licenza è distribuito
 * "COSÌ COM'È", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
 * implicite. Consultare la Licenza per il testo specifico che regola le
 * autorizzazioni e le limitazioni previste dalla medesima.
 ****************************************************************************/

#include "../src/ugbc.h"
#include <math.h>
#include <errno.h>

/*****************************************************************************
 ************ BISON CONFIGURATION (PARSER GENERATOR)
 *****************************************************************************/

/*!
   This variable keeps track of the current byte position when reading the input file.
 */
int yyposno;

/*!
   This variable keeps track of the concatenated line number when reading the 
   input file. In BASIC, logical lines, with commands, parameters, and so on, 
   can be written across multiple physical lines if the last character is an 
   underscore. This variable keeps track of the line number within the set of 
   linked lines. Therefore, this number resets to zero whenever a new line 
   begins, unless the previous line ends with an underscore.
 */
extern int yyconcatlineno;

/*!
  In Bison, the yydebug variable is the primary tool for runtime debugging 
  of the generated parser. When enabled, it allows you to see exactly what's 
  happening "under the hood" as the parser parses the input.

  Normally, a Bison parser operates silently: it reads tokens and reduces the 
  rules. If there's an error, you only receive a generic "syntax error".
  When yydebug is enabled (1), the parser prints a detailed log to standard 
  error (stderr), including when a token is read and pushed onto the stack 
  (shifts), when a sequence of symbols is transformed into a non-terminal 
  according to a grammatical rule (reductions) and the evolution of parser 
  states (stack state).

  This variable is a global integer variable (of type int). To enable 
  logging, you must set it to a non-zero value (usually 1). This value is 
  driven by "-y" command line parameter (-y0 or -y1) Inside the Bison definition, 
  we defined the %debug macro to include the code needed for tracing support.
  */
int yydebug = 0;

/*!
  This variable contains the level of nested INCLUDED files, i.e. the
  last empty position on the stacked files.
  */
int stacked = 0;

/*!
  This variable contains the list of file names of files included recursively.
  When a file is included with the `INCLUDE` command, its name is inserted 
  into this stack, from top to bottom. Conversely, when the file is finished 
  reading, its name is popped from the stack, which empties.
  */
char * filenamestacked[256];

/*!
   This variable keeps track of the current byte position when reading the input file
   of files included recursively. When a file is included with the `INCLUDE` command, 
   its actual line number is inserted into this stack, from top to bottom.
   Conversely, when the file is finished reading, its name is popped from the stack, 
   which empties.
 */
int yyposnostacked[256];

/*!
  This function is the scanner. Its job is to read a stream of input characters 
  and group them into meaningful units called "tokens". Imagine reading a sentence: 
  yylex() is the one that recognizes that "int" is a keyword, "x" is a variable, 
  and "=" is an operator. It populates some key global variables: `yytext`,
  a string (character array) containing the actual text just recognized (e.g., 
  if it recognizes a number, `yytext` will contain `"123"`); `yyleng`: the 
  length of the string contained in `yytext`; finally, `yylval` used to pass 
  the token's "value" to the parser (e.g., the actual numeric value of a string).
  */
int yylex();

/*!
  `yyerror()` is a syntactic error handling function. The parser (`yyparse()`) 
  automatically calls `yyerror()` whenever it encounters a token that doesn't 
  meet the defined grammatical rules. Information about where the error occurred 
  is added.
  */
int yyerror(Environment *, const char *);

/*!
  This function called by the scanner (the automaton generated by Flex) when it 
  reaches the end of the file (EOF) it's reading. Its name stands for "wrap up" 
  (to wrap up): its purpose is to decide whether the scanner's job is finished (1) or 
  whether it should continue reading from another file (0).
  */
int yywrap() { return 1; }

/*****************************************************************************
 ************ AUXILIARY VARIABLES
 *****************************************************************************/

/*!
   This variable holds the name of the folder containing the set of definitions 
   to be used with the IMPORT DECLARES command. Executing this statement loads the 
   relevant ugBASIC file for the target in question from this location. If NULL,
   the import path will be search against the following paths: ../../imports,
   ../imports and, finally, ./imports.
 */
char * importPath;

/*!
   This variable will store an assembly code snippet within a program.
   This means that we're essentially treating the source code as a "data string".
   This technique is common in compiler development, emulator development, or 
   when using inline assembly. 
  */
char * asmSnippet = NULL;

/*!
    This variable defines as an array of constant pointers. Each element of 
    the array represents the "human" name of a ugBASIC's data type. The main 
    reason is to map an IDto a readable string. If ugBASIC encounters an error, 
    you don't want it to print "Error in type 2," but rather "Error in type 
    FLOAT.". Note that it's vital that the order of strings in the array 
    exactly reflects the order of the IDs in your `enum`. If you move an 
    element to one, you must also move it to the other, otherwise the mapping 
    will be staggered. Often, a final `NULL` or `UNKNOWN` string is added to 
    handle error cases or to allow you to loop through the array without knowing 
    its size beforehand.
  */
extern char DATATYPE_AS_STRING[][32];

/*!
   In technical terms, it's an array (or list) of constant strings. Each string 
   represents the description of the generated format. This variable has three 
   main purposes in the compiler workflow: the compiler uses this array to rename 
   output files based on the source filename; òets the compiler know which output 
   "stages" the user has requested; finally, before writing a file, the system 
   checks whether the desired extension is one of the "managed" or supported types 
   on the target architecture.
  */
extern char OUTPUT_FILE_TYPE_AS_STRING[][16];

%}

/*****************************************************************************
 ************ BISON SYNTAX
 *****************************************************************************/

/*============================================================================
 ============ PRELIMINARY CONFIGURATIONS
 ============================================================================*/

/* Enable code generator to print out debugging info, if needed. */
%debug

/* Enable additional parameter on all calls (yyerror, too).
    Typization is not important. */
%parse-param { void * _environment }

/* Enable `YYLTYPE` structure with the `%locations` in Bison. */
%locations

/* Ask BISON to be more verbose when it meets a syntax error. */
%define parse.error verbose

/* So, "program" is the root of the BNF. */
%start program

/* This is the payload for each matched element: */
%union {

    /* Integer values (8, 16 and 32 bit).*/
    int integer;

    /* Literal values (strings and dynamic symbols).*/
    char * string;

    /* Floating point values (bitwide varying).*/
    double floating;
}

/*============================================================================
 ============ TOKENS
 ============================================================================*/

/* Special and/or not printable symbols. */
%token NewLine Remark

/* Operators, symbols and special characters. */
%token CP CSP CGP OP OSP OGP
%token OP_AMPERSAND OP_ASSIGN OP_AT OP_ASSIGN_DIRECT OP_COLON OP_COMMA 
%token OP_DISEQUAL OP_DIVISION OP_DIVISION2 OP_DOLLAR OP_DOLLAR2 OP_EQUAL 
%token OP_EXCLAMATION OP_GT OP_GTE OP_HASH OP_LT OP_LTE OP_MINUS 
%token OP_MULTIPLICATION OP_MULTIPLICATION2 OP_PERC OP_PERC2 OP_PERIOD 
%token OP_PLUS OP_POW OP_SEMICOLON QM 

/* Keywords (instructions and functions). */
%token A AAHS ABS ACCORDION ACOUSTIC ADD ADDC ADDRESS AFTER AGE AGOGO ALL ALLOW
%token ALPHA ALT ALTO AND ANIMATE ANIMATING ANIMATION APPLAUSE ARRAY ARROW AS
%token ASC ASCII ASCIICODE ASM ASTERISK ASYNC AT ATARI ATARIXL ATLAS ATMOSPHERE
%token AUDIO AUTO AVAILABLE AY8910 B BACK BACKGROUND BAG BANJO BANK BANKED BAR
%token BARITONE BASIC BASS BASSOON BECKER BEG BELL BELLS BELONG BETA BF BIG BIN
%token BINARY BIRD BIT BITMAP BITMAPADDRESS BITMAPS BLACK BLIT BLOCK BLOWN BLUE
%token BOOLEAN BOOM BORDER BOTTLE BOTTOM BOUNCE BOWED BOX BRASS BREATH BRIGHT
%token BRIGHTNESS BROWN BUFFER BUT BY BYTE BYTES C C128Z C16 C64 C64REU CALL
%token CALLIOPE CAN CAPS CAPSLOCK CASE CDOWN CELESTA CELLO CENTER CENTRE CGOTO
%token CHAIN CHANNEL CHAR CHARANG CHECK CHIFF CHOIR CHR CHURCH CIRCLE CLAMP
%token CLARINET CLASS CLAVI CLEAN CLEAR CLEFT CLINE CLIP CLOSE CLR CLS CMOB
%token CMOVE COARSE COCO COCO1 COCO2 COCO3 CODE COLECO COLLISION COLON COLOR
%token COLORMAP COLORS COLOUR COLOURMAP COLOURS COLUMN COLUMNS COMBINE COMMA
%token COMMODORE COMPILE COMPILED COMPLETE COMPRESS COMPRESSED COMPRESSION CONFIGURE
%token CONNECTED CONSOLE CONST CONTRABASS CONTROL COPPER COPY COS COUNT CPC
%token CPU6309 CPU6502 CPU6510 CPU6809 CPU7501 CPU8086 CPU8501 CPU8502
%token CPUSC61860 CPUSM83 CPUSPEED CPUZ80 CREATE CRIGHT CRSR CRYSTAL CSET
%token CSPRITE CSV CUP CURS CURSOR CYAN CYCLES CYMBAL D DAC1 DARK DATA DEC
%token DECLARE DECRYPT DEFAULT DEFDGR DEFINE DEGREE DELAY DELETE DESERIALIZE
%token DESTINATION DESTROY DETECTION DEVICE DIALECT DIGITS DIM DIRECTION
%token DISABLE DISTANCE DISTORTION DIV DLOAD DO DOJO DOJOKA DOUBLE DOWN DOWNB
%token DOWNW DRAGON DRAGON32 DRAGON64 DRAW DRAWBAR DRUM DRUMS DSAVE DTILE
%token DTILES DULCIMER DUP DWORD DYNAMIC E EASEIN EASEOUT ECHOES ELECTRIC
%token ELLIPSE ELSE ELSEIF EMBEDDED EMPTY EMPTYTILE EMULATION ENABLE ENCRYPT
%token END ENDCOPPER ENDIAN ENDIF ENDPROC ENDSELECT ENDSTORAGE ENDTYPE ENGLISH
%token ENSEMBLE ENVELOPE EQUAL ERROR EVERY EXACT EXEC EXIT EXITIF EXP EXPAND
%token EXPLICIT EXPLOSION F F1 F2 F3 F4 F5 F6 F7 F8 FADE FALSE FAST FCIRCLE
%token FELLIPSE FHEIGHT FI FIDDLE FIFTHS FILESIZE FILEX FILL FINAL FIND FINGER
%token FIRE FIRST FLASH FLIP FLOAT FLUTE FONT FOR FORBID FRAME FRAMES FREE
%token FREEZE FRENCH FRET FRETLESS FROM FSIZE FUJINET FUNCTION FWIDTH FX G
%token GAMELOOP GB GET GLOBAL GLOCKENSPIEL GMC GOBLINS GOLD GOSUB GOTO GPRINT
%token GR GRAND GRAPHIC GRAPHICS GRAY GREEN GREY GUITAR GUNSHOT H HALO HALT
%token HALTED HARMONICA HARMONICS HARP HARPSICHORD HAS HDBDOS HEIGHT HELICOPTER
%token HEX HEX2BIN HIRES HIT HOME HONKY HORIZONTAL HORN HSCROLL HTTP I IAF ID
%token IF IGNORE IMAGE IMAGEREF IMAGES IMPLICIT IN INC INCREMENTAL INDEX INK
%token INKB INKEY INLINE INPUT INSERT INST INSTR INSTRUMENT INT INTEGER
%token INTERRUPT INVERSE IS J JAZZ JDOWN JFIRE JLEFT JMOVE JOY JOYCOUNT JOYDIR
%token JOYSTICK JOYX JOYY JRIGHT JSON JUP K KALIMBA KEY KEYBOARD KEYGET
%token KEYSHIFT KEYSTATE KILL KOTO L LATENCY LAVENDER LAYER LBOTTOM LBOUND
%token LCASE LEAD LEFT LEFTB LEFTW LEN LET LIGHT LINE LITTLE LOAD LOCATE LOCK
%token LOG LOGIN LONG LOOP LOWER M MAGENTA MARIMBA MASKED MAX MELODIC MEMCLR
%token MEMCONT MEMDEF MEMLEN MEMLOAD MEMOR MEMORIZE MEMORY MEMPEEK MEMPOS
%token MEMRESTORE MEMSAVE MESSAGE METALLIC MID MIDI MILLISECOND MILLISECONDS
%token MIN MINUS MMOB MMOVE MO5 MOB MOD MODE UNIQUE C128 MONOCOLOR MONOCOLOUR
%token MOVE MOVEMENT MOVIE MOVING MS MSPRITE MSX MSX1 MUL MULTI MULTICOLOR
%token MULTICOLOUR MUSIC MUTED N NAME NAMED NARROW NEW NEWLINE NEXT NIBBLE
%token NOISE NONE NOP NORMAL NOT NOTE NRM NTSC NULLkw NUMBER NYLON O OBOE
%token OCARINA OF OFF OFFSET OLIVE ON ONLY OOHS OPACITY OPEN OPTIMIZED OPTION
%token OR ORANGE ORCHESTRA ORCHESTRAL ORGAN ORIGIN OUT OVERDRIVEN OVERLAYED P
%token PAD PAGE PAINT PAL PALETTE PALETTE1 PAN PAPER PARALLEL PARAM PARSE
%token PASSWORD PATH PAUSE PC128OP PC1403 PCCGA PCLS PEACH PEEK PEEKD PEEKW PEN
%token PER PERCUSSIVE PERIOD PI PIANO PICCOLO PICK PING PINK PIPE PIZZICATO
%token PLACE PLAY PLOT PLOTR PLUS PLUS4 PMODE POINT POKE POKED POKEW POKEY
%token POLYLINE POLYSYNTH POP PORT POSITION POSITIVE POST POUND POWERING
%token PRECISE PRECISION PRESERVE PRESET PRESS PRESSED PRINT PROBABILITY PROC
%token PROCEDURE PROGRAM PSET PSG PURPLE PUT Q QUERY R RADIAN RAIN RANDOM
%token RANDOMIZE RANGE RASTER RATE RATIO RAW READ READONLY READY REC RECEIVE
%token RECORDER RECT RED REED REGISTER RELATIVE RELEASE RELOC REMEMBER REPEAT
%token REPLACE RESET RESIDENT RESOLUTION RESPAWN RESTORE RESUME RETRIES RETURN
%token REVERSE RGB RIGHT RIGHTB RIGHTW RING RLE RND ROCK ROLL ROT ROTATE ROUNDS
%token ROW ROWS RUN RUNNING RUNSTOP S SAFE SAMPLES SAVE SAWTOOTH SAX SBYTE SC3000 SCALE
%token SCAN SCANCODE SCANSHIFT SCI SCREEN SCROLL SEASHORE SECOND SECTION SEEK
%token SELECT SEMICOLON SEMIGRAPHIC SEND SEPARATOR SEQUENCE SERIAL SERIALIZE
%token SET SG1000 SGN SHADES SHAKUHACHI SHAMISEN SHANAI SHARED SHIFT SHOOT
%token SHUFFLE SID SIGNED SIMPLE SIN SINGLE SIO SITAR SIZE SJ2 SLAP SLASH SLEEP
%token SLICE SLOT SLOW SN76489 SOPRANO SOUND SOUNDTRACK SOURCE SPACE SPAWN SPC
%token SPEED SPEN SPRITE SQR SQUARE STACK STANDARD START STATE STATIC STATUS
%token STEADY STEEL STEP STOP STORAGE STORE STR STRIG STRING STRINGS STRIP
%token STRPTR SUBSTRING SUCCESS SUM SUSPEND SWAP SWEEP SYNC SYNTH SYNTHBRASS
%token SYNTHSTRINGS SYS SYSTEM T TAB TAIKO TAN TANGO TARGET TASK TED TELEPHONE
%token TEMPORARY TENOR TEXT TEXTADDRESS TEXTMAP THEN THREAD THRESHOLD TI TICK
%token TICKS TILE TILEMAP TILES TILESET TIMER TIMPANI TINKLE TO TO8 TOM TONK
%token TPS TRANSPARENCY TRANSPARENT TRAVEL TREMOLO TRIANGLE TROMBONE TRUE
%token TRUMPET TSB TUBA TUBULAR TURQUOISE TWEET TYPE U UBOUND UCASE UGBASIC
%token UNBANKED UNFREEZE UNSIGNED UNTIL UP UPB UPDATE UPPER UPW USE USING V VAL
%token VALUE VALUES VAR VARBANK VARBANKPTR VARIABLES VARPTR VBL VCENTER VCENTRE
%token VECTOR VERTICAL VG5000 VHCENTER VHCENTRE VIBRAPHONE VIC VIC20 VIDEO
%token VIOLA VIOLET VIOLIN VIRTUALIZED VISIBLE VOICE VOLUME VSCROLL VZ200 W
%token WAIT WARM WAVE WEND WHILE WHISTLE WHITE WIDE WIDTH WITH WITHOUT
%token WOODBLOCK WORD WRITE WRITING X XCURS XGR XGRAPHIC XOR XPEN XTEXT XY
%token XYLOPHONE Y YCURS YELLOW YGR YGRAPHIC YIELD YPEN YTEXT YX Z ZX 

/* Integer numbers (8, 16, 32 bit). */
%token <integer> Integer

/* Floating point numbers. */
%token <floating> Float

/* Strings between double quotes. */
%token <string> String

/* Strings between double quotes, prefixed by "#". */
%token <string> RawString

/* Explicit buffer definition using #[ operator. */
%token <string> BufferDefinitionHex

/* Literal identifier (without spaces). */
%token <string> Identifier

/* Literal identifier (with spaces). */
%token <string> IdentifierSpaced

/* CPU registers (CPU dependent). */
%token <string> Register

/* ASM code snippet. */
%token <string> AsmSnippet

/*============================================================================
 ============ TERMS
 ============================================================================*/

/* Integer terms (numeric/flags). */
%type <integer> as_datatype 
%type <integer> as_datatype_mandatory 
%type <integer> as_datatype_suffix 
%type <integer> as_datatype_suffix_optional
%type <integer> asmio
%type <integer> audio_source
%type <integer> blit_binary_op 
%type <integer> blit_compounded
%type <integer> blit_expression 
%type <integer> blit_image_flags 
%type <integer> blit_operand
%type <integer> blit_unary_op 
%type <integer> box_mode 
%type <integer> clamp_optional
%type <integer> configure_name
%type <integer> const_color_enumeration
%type <integer> const_expr 
%type <integer> const_expr_math 
%type <integer> const_expr_math2
%type <integer> const_factor 
%type <integer> const_instrument
%type <integer> const_key_scancode_alphadigit 
%type <integer> const_key_scancode_definition 
%type <integer> const_key_scancode_function_digit
%type <integer> const_modula 
%type <integer> const_note
%type <integer> const_note_single
%type <integer> const_octave 
%type <integer> const_term 
%type <integer> datatype 
%type <integer> direct_integer
%type <integer> fill_base_optional 
%type <integer> fill_count_optional
%type <integer> fill_max_optional 
%type <integer> fill_min_optional 
%type <integer> flip_image_flags
%type <integer> font_schema
%type <integer> image_load_flag
%type <integer> image_load_flags 
%type <integer> image_load_flags1 
%type <integer> images_load_flag
%type <integer> images_load_flags 
%type <integer> images_load_flags1 
%type <integer> line_mode 
%type <integer> load_flag
%type <integer> load_flags 
%type <integer> load_flags1 
%type <integer> load_image
%type <integer> load_images
%type <integer> load_movie
%type <integer> load_sequence
%type <integer> memory_video_optional
%type <integer> music_type
%type <integer> on_bank_explicit
%type <integer> on_bank_implicit 
%type <integer> on_targets
%type <integer> op_comma_or_semicolon
%type <integer> on_off_optional 
%type <integer> option_name
%type <integer> safe_fast_optional
%type <integer> endianess_optional
%type <integer> integer_optional
%type <integer> loop_optional
%type <integer> origin_direction_optional 
%type <integer> PALETTE1
%type <integer> parallel_optional
%type <integer> precision 
%type <integer> put_action
%type <integer> put_image_flag
%type <integer> put_image_flags 
%type <integer> put_image_flags1 
%type <integer> raw_optional
%type <integer> readonly_optional
%type <integer> relative_optional 
%type <integer> release_optional
%type <integer> left_or_right 
%type <integer> up_or_down
%type <integer> sequence_load_flag
%type <integer> sequence_load_flags 
%type <integer> sequence_load_flags1 
%type <integer> shuffle_definition_optional_rounds
%type <integer> sprite_flag 
%type <integer> sprite_flags 
%type <integer> sprite_flags1
%type <integer> strip_definition_id_optional
%type <integer> system_optional
%type <integer> target targets
%type <integer> tile_load_flag%type <integer> tile_load_flags 
%type <integer> tile_load_flags1 
%type <integer> using_background
%type <integer> using_opacity
%type <integer> using_transparency

/* String terms. */
%type <string> casting
%type <string> color_enumeration
%type <string> const_expr_string 
%type <string> const_expr_string_const
%type <string> dload_from_offset 
%type <string> dload_size_size 
%type <string> dload_to_address 
%type <string> dload_to_bank
%type <string> dojo_functions
%type <string> dsave_from_address 
%type <string> dsave_size_size
%type <string> dsave_to_offset 
%type <string> exponential 
%type <string> exponential_less 
%type <string> expr 
%type <string> expr_math expr_math2
%type <string> factor 
%type <string> fujinet_functions
%type <string> key_scancode_alphadigit 
%type <string> key_scancode_definition 
%type <string> key_scancode_function_digit
%type <string> mandatory_x 
%type <string> mandatory_y
%type <string> modula 
%type <string> on_flash_address
%type <string> optional_by
%type <string> optional_clamp
%type <string> optional_expr 
%type <string> field_optional
%type <string> next_animation_optional
%type <string> period_optional
%type <string> step_optional
%type <string> optional_x 
%type <string> optional_x_or_string
%type <string> optional_y 
%type <string> pad_optional
%type <string> random_definition
%type <string> random_definition_simple 
%type <string> serial_function
%type <string> term 
%type <string> timer_number 
%type <string> timer_number_comma
%type <string> to_identifier_optional
%type <string> travel_function
%type <string> writing_mode_definition 
%type <string> writing_part_definition

/* Floating point terms. */
%type <floating> const_expr_floating

/*============================================================================
 ============ PRECEDENCE MANAGEMENT
 ============================================================================*/

/* In Bison, priority increases as you move down the file. Directives written 
   on lower lines have a higher priority than those written above. In addition 
   to "vertical" priority, %left, %right and %nonassoc define associativity
   (i.e., what happens between operators with the same priority).
   When the parser encounters a conflict (comparison between an operator 
   already on the stack and an incoming one), it follows these steps.

   If the two operators have different priorities, it chooses the one with 
   the higher priority (the one defined lower in the `.y` file). If the two 
   operators have the same priority (they are on the same line), it looks 
   for associativity: if `%left`, it reduces (performs the operation on the 
   left); if `%right`, shift (waits for the operation to the right).

   Sometimes an operator has a different priority depending on the context. 
   The classic example is the unary minus (e.g., $-5 * 3$). In this case, 
   the `-` must have a higher priority than multiplication, even though 
   addition/subtraction is usually lower. It is solved using `%prec`.
*/

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
%left OSP

%%

/*****************************************************************************
 ************ LANGUAGE RULES
 *****************************************************************************/

/*============================================================================
 ============ KEYWORDS ALIAS
 ============================================================================*/

bitmap_or_bitmaps: BITMAP | BITMAPS;
const_instruction: CONST | SHARED CONST | CONST SHARED | GLOBAL CONST | CONST GLOBAL;
filesize: FILEX SIZE | FILESIZE | FSIZE;
float_or_single: FLOAT | SINGLE;
frame: FRAME | TILE;
image_or_images:  IMAGE | IMAGES | ATLAS;
images_or_atlas: IMAGES | ATLAS;
load_image :    LOAD IMAGE {
                    $$ = 0; 
                } | 
                IMAGE LOAD {
                    $$ = 0; 
                } | 
                LOAD COMPILED IMAGE {
                    $$ = 1; 
                } | 
                COMPILED IMAGE LOAD {
                    $$ = 1; 
                };
load_images:    LOAD IMAGES {
                    $$ = 0; 
                } | 
                LOAD ATLAS {
                    $$ = 0; 
                } | 
                IMAGES LOAD {
                    $$ = 0; 
                } | 
                ATLAS LOAD {
                    $$ = 0; 
                } |
                LOAD COMPILED IMAGES {
                    $$ = 1; 
                } | 
                LOAD COMPILED ATLAS {
                    $$ = 1; 
                } | 
                COMPILED IMAGES LOAD {
                    $$ = 1; 
                } | 
                COMPILED ATLAS LOAD {
                    $$ = 1; 
                };
load_movie :    LOAD MOVIE {
                    $$ = 0; 
                } | 
                MOVIE LOAD {
                    $$ = 0; 
                };
load_sequence:  LOAD SEQUENCE {
                    $$ = 0; 
                } | 
                SEQUENCE LOAD {
                    $$ = 0; 
                } | 
                LOAD STRIP {
                    $$ = 0; 
                } | 
                STRIP LOAD {
                    $$ = 0; 
                } |
                LOAD COMPILED SEQUENCE {
                    $$ = 1; 
                } | 
                COMPILED SEQUENCE LOAD {
                    $$ = 1; 
                } | 
                LOAD COMPILED STRIP {
                    $$ = 1; 
                } | 
                COMPILED STRIP LOAD {
                    $$ = 1; 
                } ;
load_tilemap : LOAD TILEMAP | TILEMAP LOAD;
load_tileset : LOAD TILESET | TILESET LOAD;
milliseconds: MS | MILLISECOND | MILLISECONDS;
op_assign:  OP_ASSIGN  | OP_ASSIGN_DIRECT;
position: POSITION | AT;
procedure: PROCEDURE | PROC;
sequence_or_strip:  SEQUENCE | STRIP;
text_or_csv: TEXT | CSV;
ticks: TICK | TICKS;

/*============================================================================
 ============ CONSTANT VALUES / SYMBOLS
 ============================================================================*/

/*
    Constant float value.
*/

const_expr_floating:
    Float { $$ = $1; } | 
    IF OP const_expr OP_COMMA const_expr_floating OP_COMMA const_expr_floating CP { $$ = ( $3 ) ? $5 : $7; }

/*
    Constant string value.
 */

const_expr_string:
    String { $$ = $1; } | 
    RawString { $$ = $1; } | 
    IF OP const_expr OP_COMMA const_expr_string OP_COMMA const_expr_string CP { $$ = ( $3 ) ? $5 : $7; };

const_expr_string_const:
    Z OP const_expr CP {
        Constant * c = constant_create( _environment, NULL );
        c->valueString = static_string_create_filled( _environment, $3, 0 );
        c->type = CT_STRING;
        $$ = c->name;
    } | 
    String {
        int size;
        char * buffer = parse_buffer( _environment, $1, &size, 0 );
        Constant * c = constant_create( _environment, NULL );
        c->valueString = static_string_create( _environment, buffer, size );
        c->type = CT_STRING;
        $$ = c->name;
    } | 
    Identifier {
        Constant * c1 = constant_find( _environment, $1 );
        if ( c1 == NULL ) {
            CRITICAL_UNDEFINED_CONSTANT( $1 );
        }
        if ( c1->type != CT_STRING ) {
            CRITICAL_TYPE_MISMATCH_CONSTANT_STRING( $1 );
        }
        Constant * c = constant_create( _environment, NULL );
        c->valueString = static_string_create( _environment, c1->valueString->value, c1->valueString->size );
        c->type = CT_STRING;
        $$ = c->name;
    } | 
    Identifier OP_PLUS const_expr_string_const {
        Constant * c1 = constant_find( _environment, $1 );
        Constant * c2 = constant_find( _environment, $3 );
        if ( c1 == NULL ) {
            CRITICAL_UNDEFINED_CONSTANT( $1 );
        }
        if ( c1->type != CT_STRING ) {
            CRITICAL_TYPE_MISMATCH_CONSTANT_STRING( $1 );
        }
        int sumSize = c1->valueString->size + c2->valueString->size;
        char * sumString = malloc( sumSize );
        memset( sumString, 0, sumSize );
        memcpy( sumString, c1->valueString->value, c1->valueString->size );
        memcpy( sumString + c1->valueString->size, c2->valueString->value, c2->valueString->size );
        Constant * c = constant_create( _environment, NULL );
        c->valueString = static_string_create( _environment, sumString, sumSize );
        c->type = CT_STRING;
        $$ = c->name;
    } | 
    String OP_PLUS const_expr_string_const {
        int size;
        char * buffer = parse_buffer( _environment, $1, &size, 0 );
        Constant * c2 = constant_find( _environment, $3 );
        int sumSize = size + c2->valueString->size;
        char * sumString = malloc( sumSize );
        memset( sumString, 0, sumSize );
        memcpy( sumString, buffer, size );
        memcpy( sumString + size, c2->valueString->value, c2->valueString->size );        
        Constant * c = constant_create( _environment, NULL );
        c->valueString = static_string_create( _environment, sumString, sumSize );
        c->type = CT_STRING;
        $$ = c->name;
    } | 
    Z OP const_expr CP OP_PLUS const_expr_string_const {
        Constant * c1 = constant_create( _environment, NULL );
        c1->valueString = static_string_create_filled( _environment, $3, 0 );
        c1->type = CT_STRING;
        Constant * c2 = constant_find( _environment, $6 );
        int sumSize = c1->valueString->size + c2->valueString->size;
        char * sumString = malloc( sumSize );
        memset( sumString, 0, sumSize );
        memcpy( sumString, c1->valueString->value, c1->valueString->size );
        memcpy( sumString + c1->valueString->size, c2->valueString->value, c2->valueString->size );        
        Constant * c = constant_create( _environment, NULL );
        c->valueString = static_string_create( _environment, sumString, sumSize );
        c->type = CT_STRING;
        $$ = c->name;
    };

/*
    Array of constants.
*/

const_array_definition:
    const_expr {
        Variable * currentArray = ((struct _Environment *)_environment)->currentArray;
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
    } | 
    const_expr_floating {
        Variable * currentArray = ((struct _Environment *)_environment)->currentArray;
        Constant * first = currentArray->arrayInitialization;
        Constant * c = malloc( sizeof( Constant ) );
        memset( c, 0, sizeof( Constant ) );
        c->valueFloating = $1;
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
    const_array_definition | 
    const_array_definition OP_COMMA const_array_definitions1;

const_array_definitions: 
    | 
    const_array_definitions1;

/*
    Musical notation in international standard, used in modern music, jazz, 
    and computer music (such as the MIDI protocol). This system uses the first 
    seven letters of the alphabet. To distinguish, for example, a very low "C" 
    from a very high one, a number is added immediately after the letter. This 
    system is called "Scientific Notation". The number indicates the octave it 
    belongs to. In the IMF/MIDI protocol each "Letter + Number" combination 
    corresponds to a fixed numeric value (the MIDI Note Number).
*/

const_note_single: 
    A { $$ = 9; } |
    B { $$ = 11; } |
    C { $$ = 0; } |
    D { $$ = 2; } |
    E { $$ = 4; } |
    F { $$ = 5; } |
    G { $$ = 7; };

const_octave:
    Integer { $$ = $1; };

const_note:
    const_note_single { $$ = $1 + ( 4 * 12 ); } |
    const_note_single const_octave { $$ = $1 + ( $2 * 12 ); } |
    F1 { $$ = 5 + ( 1 * 12 ); } |
    F2 { $$ = 5 + ( 2 * 12 ); } |
    F3 { $$ = 5 + ( 3 * 12 ); } |
    F4 { $$ = 5 + ( 4 * 12 ); } |
    F5 { $$ = 5 + ( 5 * 12 ); } |
    F6 { $$ = 5 + ( 6 * 12 ); } |
    F7 { $$ = 5 + ( 7 * 12 ); } |
    F8 { $$ = 5 + ( 8 * 12 ); } |
    const_note_single OP_HASH const_octave { $$ = ( $1 + 1 ) + ( $3 * 12 ); } |
    CONST const_octave { $$ = ( 0 + 1 ) + ( $2 * 12 ); };

/* 
    This is the list of instruments supported by IMF. This list is the same
    as MIDI (Musical Instrument Digital Interface) protocol. Those symbols
    are associated with instruments, and they are essential for telling
    ugBASIC which "timbre" to use to play the notes. These constants are 
    defined by the General MIDI (GM) standard, which assigns a unique number 
    to 128 different instruments, grouped into 16 families.
*/

const_instrument:
    ACCORDION { $$ = IMF_INSTRUMENT_ACCORDION; } |
    ACOUSTIC BASS { $$ = IMF_INSTRUMENT_ACOUSTIC_BASS; } |
    ACOUSTIC GRAND PIANO { $$ = IMF_INSTRUMENT_ACOUSTIC_GRAND_PIANO; } |
    ACOUSTIC GUITAR NYLON { $$ = IMF_INSTRUMENT_ACOUSTIC_GUITAR_NYLON; } |
    ACOUSTIC GUITAR STEEL { $$ = IMF_INSTRUMENT_ACOUSTIC_GUITAR_STEEL; } |
    AGOGO { $$ = IMF_INSTRUMENT_AGOGO; } |
    ALTO SAX { $$ = IMF_INSTRUMENT_ALTO_SAX; } |
    APPLAUSE { $$ = IMF_INSTRUMENT_APPLAUSE; } |
    BAG PIPE { $$ = IMF_INSTRUMENT_BAG_PIPE; } |
    BANJO { $$ = IMF_INSTRUMENT_BANJO; } |
    BARITONE SAX { $$ = IMF_INSTRUMENT_BARITONE_SAX; } |
    BASSOON { $$ = IMF_INSTRUMENT_BASSOON; } |
    BIRD TWEET { $$ = IMF_INSTRUMENT_BIRD_TWEET; } |
    BLOWN BOTTLE { $$ = IMF_INSTRUMENT_BLOWN_BOTTLE; } |
    BRASS SECTION { $$ = IMF_INSTRUMENT_BRASS_SECTION; } |
    BREATH NOISE { $$ = IMF_INSTRUMENT_BREATH_NOISE; } |
    BRIGHT ACOUSTIC PIANO { $$ = IMF_INSTRUMENT_BRIGHT_ACOUSTIC_PIANO; } |
    CELESTA { $$ = IMF_INSTRUMENT_CELESTA; } |
    CELLO { $$ = IMF_INSTRUMENT_CELLO; } |
    CHOIR AAHS { $$ = IMF_INSTRUMENT_CHOIR_AAHS; } |
    CHURCH ORGAN { $$ = IMF_INSTRUMENT_CHURCH_ORGAN; } |
    CLARINET { $$ = IMF_INSTRUMENT_CLARINET; } |
    CLAVI { $$ = IMF_INSTRUMENT_CLAVI; } |
    CONTRABASS { $$ = IMF_INSTRUMENT_CONTRABASS; } |
    DISTORTION GUITAR { $$ = IMF_INSTRUMENT_DISTORTION_GUITAR; } |
    DRAWBAR ORGAN { $$ = IMF_INSTRUMENT_DRAWBAR_ORGAN; } |
    DULCIMER { $$ = IMF_INSTRUMENT_DULCIMER; } |
    ELECTRIC BASS FINGER { $$ = IMF_INSTRUMENT_ELECTRIC_BASS_FINGER; } |
    ELECTRIC BASS PICK { $$ = IMF_INSTRUMENT_ELECTRIC_BASS_PICK; } |
    ELECTRIC GRAND PIANO { $$ = IMF_INSTRUMENT_ELECTRIC_GRAND_PIANO; } |
    ELECTRIC GUITAR CLEAN { $$ = IMF_INSTRUMENT_ELECTRIC_GUITAR_CLEAN; } |
    ELECTRIC GUITAR JAZZ { $$ = IMF_INSTRUMENT_ELECTRIC_GUITAR_JAZZ; } |
    ELECTRIC GUITAR MUTED { $$ = IMF_INSTRUMENT_ELECTRIC_GUITAR_MUTED; } |
    ELECTRIC PIANO "1" { $$ = IMF_INSTRUMENT_ELECTRIC_PIANO1; } |
    ELECTRIC PIANO "2" { $$ = IMF_INSTRUMENT_ELECTRIC_PIANO2; } |
    ENGLISH HORN { $$ = IMF_INSTRUMENT_ENGLISH_HORN; } |
    EXPLOSION { $$ = IMF_INSTRUMENT_EXPLOSION; } |
    FIDDLE { $$ = IMF_INSTRUMENT_FIDDLE; } |
    FLUTE { $$ = IMF_INSTRUMENT_FLUTE; } |
    FRENCH HORN { $$ = IMF_INSTRUMENT_FRENCH_HORN; } |
    FRETLESS BASS { $$ = IMF_INSTRUMENT_FRETLESS_BASS; } |
    FX "1" RAIN { $$ = IMF_INSTRUMENT_FX_1_RAIN; } |
    FX "2" SOUNDTRACK { $$ = IMF_INSTRUMENT_FX_2_SOUNDTRACK; } |
    FX "3" CRYSTAL { $$ = IMF_INSTRUMENT_FX_3_CRYSTAL; } |
    FX "4" ATMOSPHERE { $$ = IMF_INSTRUMENT_FX_4_ATMOSPHERE; } |
    FX "5" BRIGHTNESS { $$ = IMF_INSTRUMENT_FX_5_BRIGHTNESS; } |
    FX "6" GOBLINS { $$ = IMF_INSTRUMENT_FX_6_GOBLINS; } |
    FX "7" ECHOES { $$ = IMF_INSTRUMENT_FX_7_ECHOES; } |
    FX "8" SCI FI { $$ = IMF_INSTRUMENT_FX_8_SCI_FI; } |
    GLOCKENSPIEL { $$ = IMF_INSTRUMENT_GLOCKENSPIEL; } |
    GUITAR FRET NOISE { $$ = IMF_INSTRUMENT_GUITAR_FRET_NOISE; } |
    GUITAR HARMONICS { $$ = IMF_INSTRUMENT_GUITAR_HARMONICS; } |
    GUNSHOT { $$ = IMF_INSTRUMENT_GUNSHOT; } |
    HARMONICA { $$ = IMF_INSTRUMENT_HARMONICA; } |
    HARPSICHORD { $$ = IMF_INSTRUMENT_HARPSICHORD; } |
    HELICOPTER { $$ = IMF_INSTRUMENT_HELICOPTER; } |
    HONKY TONK PIANO { $$ = IMF_INSTRUMENT_HONKY_TONK_PIANO; } |
    KALIMBA { $$ = IMF_INSTRUMENT_KALIMBA; } |
    KOTO { $$ = IMF_INSTRUMENT_KOTO; } |
    LEAD "1" SQUARE { $$ = IMF_INSTRUMENT_LEAD_1_SQUARE; } |
    LEAD "2" SAWTOOTH { $$ = IMF_INSTRUMENT_LEAD_2_SAWTOOTH; } |
    LEAD "3" CALLIOPE { $$ = IMF_INSTRUMENT_LEAD_3_CALLIOPE; } |
    LEAD "4" CHIFF { $$ = IMF_INSTRUMENT_LEAD_4_CHIFF; } |
    LEAD "5" CHARANG { $$ = IMF_INSTRUMENT_LEAD_5_CHARANG; } |
    LEAD "6" VOICE { $$ = IMF_INSTRUMENT_LEAD_6_VOICE; } |
    LEAD "7" FIFTHS { $$ = IMF_INSTRUMENT_LEAD_7_FIFTHS; } |
    LEAD "8" BASS LEAD { $$ = IMF_INSTRUMENT_LEAD_8_BASS_LEAD; } |
    MARIMBA { $$ = IMF_INSTRUMENT_MARIMBA; } |
    MELODIC TOM { $$ = IMF_INSTRUMENT_MELODIC_TOM; } |
    MUSIC BOX { $$ = IMF_INSTRUMENT_MUSIC_BOX; } |
    MUTED TRUMPET { $$ = IMF_INSTRUMENT_MUTED_TRUMPET; } |
    OBOE { $$ = IMF_INSTRUMENT_OBOE; } |
    OCARINA { $$ = IMF_INSTRUMENT_OCARINA; } |
    ORCHESTRA HIT { $$ = IMF_INSTRUMENT_ORCHESTRA_HIT; } |
    ORCHESTRAL HARP { $$ = IMF_INSTRUMENT_ORCHESTRAL_HARP; } |
    OVERDRIVEN GUITAR { $$ = IMF_INSTRUMENT_OVERDRIVEN_GUITAR; } |
    PAD "1" NEW AGE { $$ = IMF_INSTRUMENT_PAD_1_NEW_AGE; } |
    PAD "2" WARM { $$ = IMF_INSTRUMENT_PAD_2_WARM; } |
    PAD "3" POLYSYNTH { $$ = IMF_INSTRUMENT_PAD_3_POLYSYNTH; } |
    PAD "4" CHOIR { $$ = IMF_INSTRUMENT_PAD_4_CHOIR; } |
    PAD "5" BOWED { $$ = IMF_INSTRUMENT_PAD_5_BOWED; } |
    PAD "6" METALLIC { $$ = IMF_INSTRUMENT_PAD_6_METALLIC; } |
    PAD "7" HALO { $$ = IMF_INSTRUMENT_PAD_7_HALO; } |
    PAD "8" SWEEP { $$ = IMF_INSTRUMENT_PAD_8_SWEEP; } |
    PAN FLUTE { $$ = IMF_INSTRUMENT_PAN_FLUTE; } |
    PERCUSSIVE ORGAN { $$ = IMF_INSTRUMENT_PERCUSSIVE_ORGAN; } |
    PICCOLO { $$ = IMF_INSTRUMENT_PICCOLO; } |
    PIZZICATO STRINGS { $$ = IMF_INSTRUMENT_PIZZICATO_STRINGS; } |
    RECORDER { $$ = IMF_INSTRUMENT_RECORDER; } |
    REED ORGAN { $$ = IMF_INSTRUMENT_REED_ORGAN; } |
    REVERSE CYMBAL { $$ = IMF_INSTRUMENT_REVERSE_CYMBAL; } |
    ROCK ORGAN { $$ = IMF_INSTRUMENT_ROCK_ORGAN; } |
    SEASHORE { $$ = IMF_INSTRUMENT_SEASHORE; } |
    SHAKUHACHI { $$ = IMF_INSTRUMENT_SHAKUHACHI; } |
    SHAMISEN { $$ = IMF_INSTRUMENT_SHAMISEN; } |
    SHANAI { $$ = IMF_INSTRUMENT_SHANAI; } |
    SITAR { $$ = IMF_INSTRUMENT_SITAR; } |
    SLAP BASS "1" { $$ = IMF_INSTRUMENT_SLAP_BASS_1; } |
    SLAP BASS "2" { $$ = IMF_INSTRUMENT_SLAP_BASS_2; } |
    SOPRANO SAX { $$ = IMF_INSTRUMENT_SOPRANO_SAX; } |
    STEEL DRUMS { $$ = IMF_INSTRUMENT_STEEL_DRUMS; } |
    STRING ENSEMBLE "1" { $$ = IMF_INSTRUMENT_STRING_ENSEMBLE_1; } |
    STRING ENSEMBLE "2" { $$ = IMF_INSTRUMENT_STRING_ENSEMBLE_2; } |
    SYNTH BASS "1" { $$ = IMF_INSTRUMENT_SYNTH_BASS_1; } |
    SYNTH BASS "2" { $$ = IMF_INSTRUMENT_SYNTH_BASS_2; } |
    SYNTH DRUM { $$ = IMF_INSTRUMENT_SYNTH_DRUM; } |
    SYNTH VOICE { $$ = IMF_INSTRUMENT_SYNTH_VOICE; } |
    SYNTHBRASS "1" { $$ = IMF_INSTRUMENT_SYNTHBRASS_1; } |
    SYNTHBRASS "2" { $$ = IMF_INSTRUMENT_SYNTHBRASS_2; } |
    SYNTHSTRINGS "1" { $$ = IMF_INSTRUMENT_SYNTHSTRINGS_1; } |
    SYNTHSTRINGS "2" { $$ = IMF_INSTRUMENT_SYNTHSTRINGS_2; } |
    TAIKO DRUM { $$ = IMF_INSTRUMENT_TAIKO_DRUM; } |
    TANGO ACCORDION { $$ = IMF_INSTRUMENT_TANGO_ACCORDION; } |
    TELEPHONE RING { $$ = IMF_INSTRUMENT_TELEPHONE_RING; } |
    TENOR SAX { $$ = IMF_INSTRUMENT_TENOR_SAX; } |
    TIMPANI { $$ = IMF_INSTRUMENT_TIMPANI; } |
    TINKLE BELL { $$ = IMF_INSTRUMENT_TINKLE_BELL; } |
    TREMOLO STRINGS { $$ = IMF_INSTRUMENT_TREMOLO_STRINGS; } |
    TROMBONE { $$ = IMF_INSTRUMENT_TROMBONE; } |
    TRUMPET { $$ = IMF_INSTRUMENT_TRUMPET; } |
    TUBA { $$ = IMF_INSTRUMENT_TUBA; } |
    TUBULAR BELLS { $$ = IMF_INSTRUMENT_TUBULAR_BELLS; } |
    VIBRAPHONE { $$ = IMF_INSTRUMENT_VIBRAPHONE; } |
    VIOLA { $$ = IMF_INSTRUMENT_VIOLA; } |
    VIOLIN { $$ = IMF_INSTRUMENT_VIOLIN; } |
    VOICE OOHS { $$ = IMF_INSTRUMENT_VOICE_OOHS; } |
    WHISTLE { $$ = IMF_INSTRUMENT_WHISTLE; } |
    WOODBLOCK { $$ = IMF_INSTRUMENT_WOODBLOCK; } |
    XYLOPHONE { $$ = IMF_INSTRUMENT_XYLOPHONE; };

/* 
    This is the list of colors supported.
*/

const_color_enumeration:
    BLACK { $$ = COLOR_BLACK; } | 
    BLUE { $$ = COLOR_BLUE; } | 
    BROWN { $$ = COLOR_BROWN; } | 
    CYAN { $$ = COLOR_CYAN; } | 
    DARK BLUE { $$ = COLOR_DARK_BLUE; } | 
    DARK GRAY { $$ = COLOR_DARK_GREY; } | 
    DARK GREEN { $$ = COLOR_DARK_GREEN; } | 
    DARK GREY { $$ = COLOR_DARK_GREY; } | 
    DARK RED { $$ = COLOR_DARK_RED; } | 
    DARK WHITE { $$ = COLOR_DARK_WHITE; } | 
    GOLD { $$ = COLOR_GOLD; } | 
    GRAY { $$ = COLOR_GREY; } | 
    GREEN { $$ = COLOR_GREEN; } | 
    GREY { $$ = COLOR_GREY; } | 
    LAVENDER { $$ = COLOR_LAVENDER; } | 
    LIGHT BLUE { $$ = COLOR_LIGHT_BLUE; } | 
    LIGHT GRAY { $$ = COLOR_LIGHT_GREY; } | 
    LIGHT GREEN { $$ = COLOR_LIGHT_GREEN; } | 
    LIGHT GREY { $$ = COLOR_LIGHT_GREY; } | 
    LIGHT RED { $$ = COLOR_LIGHT_RED; } | 
    LIGHT WHITE { $$ = COLOR_LIGHT_WHITE; } | 
    MAGENTA { $$ = COLOR_MAGENTA; } | 
    OLIVE GREEN { $$ = COLOR_OLIVE_GREEN; } | 
    ORANGE { $$ = COLOR_ORANGE; } | 
    PEACH { $$ = COLOR_PEACH; } |
    PINK { $$ = COLOR_PINK; } | 
    PURPLE { $$ = COLOR_PURPLE; } | 
    RED { $$ = COLOR_RED; } | 
    TAN { $$ = COLOR_TAN; } | 
    TURQUOISE { $$ = COLOR_TURQUOISE; } | 
    VIOLET { $$ = COLOR_VIOLET; } | 
    WHITE { $$ = COLOR_WHITE; } |
    YELLOW { $$ = COLOR_YELLOW; } | 
    YELLOW GREEN { $$ = COLOR_YELLOW_GREEN; };

/* 
    This is the list of keystrokes.
*/

const_key_scancode_alphadigit:
    "0" { $$ = key_constant( _environment, KEY_0 ); } | 
    "1" { $$ = key_constant( _environment, KEY_1 ); } | 
    "2" { $$ = key_constant( _environment, KEY_2 ); } | 
    "3" { $$ = key_constant( _environment, KEY_3 ); } | 
    "4" { $$ = key_constant( _environment, KEY_4 ); } | 
    "5" { $$ = key_constant( _environment, KEY_5 ); } | 
    "6" { $$ = key_constant( _environment, KEY_6 ); } | 
    "7" { $$ = key_constant( _environment, KEY_7 ); } | 
    "8" { $$ = key_constant( _environment, KEY_8 ); } | 
    "9" { $$ = key_constant( _environment, KEY_9 ); } | 
    A { $$ = key_constant( _environment, KEY_A ); } | 
    B { $$ = key_constant( _environment, KEY_B ); } | 
    C { $$ = key_constant( _environment, KEY_C ); } |
    D { $$ = key_constant( _environment, KEY_D ); } | 
    E { $$ = key_constant( _environment, KEY_E ); } | 
    F { $$ = key_constant( _environment, KEY_F ); } | 
    G { $$ = key_constant( _environment, KEY_G ); } | 
    H { $$ = key_constant( _environment, KEY_H ); } | 
    I { $$ = key_constant( _environment, KEY_I ); } | 
    J { $$ = key_constant( _environment, KEY_J ); } | 
    K { $$ = key_constant( _environment, KEY_K ); } |
    L { $$ = key_constant( _environment, KEY_L ); } | 
    M { $$ = key_constant( _environment, KEY_M ); } | 
    N { $$ = key_constant( _environment, KEY_N ); } | 
    O { $$ = key_constant( _environment, KEY_O ); } | 
    P { $$ = key_constant( _environment, KEY_P ); } | 
    Q { $$ = key_constant( _environment, KEY_Q ); } | 
    R { $$ = key_constant( _environment, KEY_R ); } | 
    S { $$ = key_constant( _environment, KEY_S ); } | 
    T { $$ = key_constant( _environment, KEY_T ); } | 
    U { $$ = key_constant( _environment, KEY_U ); } | 
    V { $$ = key_constant( _environment, KEY_V ); } | 
    W { $$ = key_constant( _environment, KEY_W ); } | 
    X { $$ = key_constant( _environment, KEY_X ); } |
    Y { $$ = key_constant( _environment, KEY_Y ); } | 
    Z { $$ = key_constant( _environment, KEY_Z ); };

const_key_scancode_function_digit:
    F1 { $$ = key_constant( _environment, KEY_F1 ); } | 
    F2 { $$ = key_constant( _environment, KEY_F2 ); } | 
    F3 { $$ = key_constant( _environment, KEY_F3 ); } | 
    F4 { $$ = key_constant( _environment, KEY_F4 ); } | 
    F5 { $$ = key_constant( _environment, KEY_F5 ); } | 
    F6 { $$ = key_constant( _environment, KEY_F6 ); } | 
    F7 { $$ = key_constant( _environment, KEY_F7 ); } | 
    F8 { $$ = key_constant( _environment, KEY_F8 ); };

const_key_scancode_definition: 
    ARROW LEFT { $$ = key_constant( _environment, KEY_LEFT_ARROW ); } | 
    ARROW UP { $$ = key_constant( _environment, KEY_UP_ARROW ); } | 
    ASTERISK { $$ = key_constant( _environment, KEY_ASTERISK ); } | 
    AT { $$ = key_constant( _environment, KEY_AT ); } | 
    CLEAR { $$ = key_constant( _environment, KEY_CLEAR ); } | 
    COLON { $$ = key_constant( _environment, KEY_COLON ); } | 
    COMMA { $$ = key_constant( _environment, KEY_COMMA ); } | 
    COMMODORE { $$ = key_constant( _environment, KEY_COMMODORE ); } | 
    const_key_scancode_alphadigit { $$ = $1; } | 
    const_key_scancode_function_digit { $$ = $1; } | 
    CONTROL { $$ = key_constant( _environment, KEY_CONTROL ); } | 
    CRSR LEFT RIGHT { $$ = key_constant( _environment, KEY_CRSR_LEFT_RIGHT ); } | 
    CRSR UP DOWN { $$ = key_constant( _environment, KEY_CRSR_UP_DOWN ); } | 
    DELETE { $$ = key_constant( _environment, KEY_DELETE ); } | 
    DOWN { $$ = key_constant( _environment, KEY_DOWN ); } | 
    EQUAL { $$ = key_constant( _environment, KEY_EQUAL ); } | 
    HOME { $$ = key_constant( _environment, KEY_HOME ); } | 
    INSERT { $$ = key_constant( _environment, KEY_INSERT ); } |
    LEFT { $$ = key_constant( _environment, KEY_LEFT ); } | 
    LEFT ARROW { $$ = key_constant( _environment, KEY_LEFT_ARROW ); } | 
    MINUS { $$ = key_constant( _environment, KEY_MINUS ); } | 
    NONE { $$ = key_constant( _environment, KEY_NONE ); } | 
    PERIOD { $$ = key_constant( _environment, KEY_PERIOD ); } | 
    PLUS { $$ = key_constant( _environment, KEY_PLUS ); } | 
    POUND { $$ = key_constant( _environment, KEY_POUND ); } | 
    RETURN { $$ = key_constant( _environment, KEY_RETURN ); } | 
    RIGHT { $$ = key_constant( _environment, KEY_RIGHT ); } | 
    RUN STOP { $$ = key_constant( _environment, KEY_RUNSTOP ); } | 
    RUNSTOP { $$ = key_constant( _environment, KEY_RUNSTOP ); } | 
    SEMICOLON { $$ = key_constant( _environment, KEY_SEMICOLON ); } | 
    SLASH { $$ = key_constant( _environment, KEY_SLASH ); } | 
    SPACE { $$ = key_constant( _environment, KEY_SPACE ); } |
    TAB { $$ = key_constant( _environment, KEY_TAB ); } | 
    UP { $$ = key_constant( _environment, KEY_UP ); } | 
    UP ARROW { $$ = key_constant( _environment, KEY_UP_ARROW ); };

/* 
    Various flags.
*/

image_load_flag:
    COMPRESSED { $$ = FLAG_COMPRESSED; } | 
    EXACT { $$ = FLAG_EXACT; } |
    FLIP X { $$ = FLAG_FLIP_X; } | 
    FLIP XY { $$ = FLAG_FLIP_X | FLAG_FLIP_Y; } | 
    FLIP Y { $$ = FLAG_FLIP_Y; } | 
    FLIP YX { $$ = FLAG_FLIP_X | FLAG_FLIP_Y; } | 
    OVERLAYED { $$ = FLAG_OVERLAYED; };

tile_load_flag:
    FLIP X { $$ = FLAG_FLIP_X; } | 
    FLIP XY { $$ = FLAG_FLIP_X | FLAG_FLIP_Y; } | 
    FLIP Y { $$ = FLAG_FLIP_Y; } | 
    FLIP YX { $$ = FLAG_FLIP_X | FLAG_FLIP_Y; } | 
    ROLL X { $$ = FLAG_ROLL_X; } | 
    ROLL XY { $$ = FLAG_ROLL_Y | FLAG_ROLL_X; } | 
    ROLL Y { $$ = FLAG_ROLL_Y; } | 
    ROLL YX { $$ = FLAG_ROLL_Y | FLAG_ROLL_X; } | 
    TRANSPARENT { $$ = FLAG_TRANSPARENCY; };

put_image_flag:
    WITH TRANSPARENCY { $$ = FLAG_TRANSPARENCY; };

load_flag:
    COMPRESSED { $$ = FLAG_COMPRESSED; };

images_load_flag:
    COMPRESSED { $$ = FLAG_COMPRESSED; } | 
    EXACT { $$ = FLAG_EXACT; } | 
    FLIP X { $$ = FLAG_FLIP_X; } | 
    FLIP XY { $$ = FLAG_FLIP_X | FLAG_FLIP_Y; } | 
    FLIP Y { $$ = FLAG_FLIP_Y; } | 
    FLIP YX { $$ = FLAG_FLIP_X | FLAG_FLIP_Y; } | 
    OVERLAYED { $$ = FLAG_OVERLAYED; } | 
    ROLL X { $$ = FLAG_ROLL_X; } | 
    ROLL XY { $$ = FLAG_ROLL_Y | FLAG_ROLL_X; } | 
    ROLL Y { $$ = FLAG_ROLL_Y; } | 
    ROLL YX { $$ = FLAG_ROLL_Y | FLAG_ROLL_X; };

sequence_load_flag:
    COMPRESSED { $$ = FLAG_COMPRESSED; } | 
    EXACT { $$ = FLAG_EXACT; } |
    FLIP X { $$ = FLAG_FLIP_X; } | 
    FLIP XY { $$ = FLAG_FLIP_X | FLAG_FLIP_Y; } | 
    FLIP Y { $$ = FLAG_FLIP_Y; } | 
    FLIP YX { $$ = FLAG_FLIP_X | FLAG_FLIP_Y; } | 
    OVERLAYED { $$ = FLAG_OVERLAYED; };

put_image_flags1:
    put_image_flag { $$ = $1; } | 
    put_image_flag put_image_flags1 { $$ = $1 | $2; };

image_load_flags1:
    image_load_flag { $$ = $1; } | 
    image_load_flag image_load_flags1 { $$ = $1 | $2; };

load_flags1:
    load_flag { $$ = $1; } | 
    load_flag load_flags1 { $$ = $1 | $2; };

tile_load_flags1:
    tile_load_flag { $$ = $1; } | 
    tile_load_flag tile_load_flags1 { $$ = $1 | $2; };

images_load_flags1:
    images_load_flag { $$ = $1; } | 
    images_load_flag images_load_flags1 { $$ = $1 | $2; };

sequence_load_flags1:
    sequence_load_flag { $$ = $1; } | 
    sequence_load_flag sequence_load_flags1 { $$ = $1 | $2; };

using_transparency: 
    { $$ = 0x00; }  | 
    TRANSPARENCY { $$ = 0x0f0000 | COLOR_BLACK; } | 
    TRANSPARENCY const_color_enumeration { $$ = 0x0f0000 | $2; };

using_opacity: 
    { $$ = 0x00; }  | 
    OPACITY { $$ = 0xf00000 | ( COLOR_BLACK << 8 ); } | 
    OPACITY const_color_enumeration { $$ = 0xf00000 | ( $2 << 8 ); };

using_background:
    { $$ = -1; } | 
    BACKGROUND const_color_enumeration { $$ = $2; };

tile_load_flags:
    { $$ = 0; } | 
    tile_load_flags1 { $$ = $1; };

image_load_flags:
    { $$ = 0; } | 
    image_load_flags1 { $$ = $1; };

put_image_flags:
    { $$ = 0; } | 
    put_image_flags1 { $$ = $1; };

blit_image_flags:
    { $$ = 0; };

load_flags:
    { $$ = 0; } | 
    load_flags1 { $$ = $1; };

images_load_flags:
    { $$ = 0; } | 
    images_load_flags1 { $$ = $1; };

release_optional:
    { $$ = 0; } | 
    RELEASE { $$ = 1; };

integer_optional: 
    { $$ = 0; } |
    Integer { $$ = $1; };

readonly_optional: 
    { $$ = READONLY_DEFAULT; } | 
    NOT READ ONLY { $$ = 0; } |
    NOT READONLY { $$ = 0; } |
    READ ONLY { $$ = 1; } |
    READONLY { $$ = 1; };

clamp_optional: 
    { $$ = 0; } | 
    CLAMP { $$ = 1; };

period_optional: 
    { $$ = NULL; } | 
    PERIOD Identifier { $$ = $2; };

sequence_load_flags:
    { $$ = 0; } | 
    sequence_load_flags1 { $$ = $1; };

field_optional:  
    { $$ = NULL; } | 
    OP_PERIOD Identifier { $$ = $2; };

sprite_flag:
    COMPRESS HORIZONTAL { $$ = SPRITE_FLAG_COMPRESS_HORIZONTAL; } | 
    COMPRESS VERTICAL { $$ = SPRITE_FLAG_COMPRESS_VERTICAL; } | 
    EXPAND HORIZONTAL { $$ = SPRITE_FLAG_EXPAND_HORIZONTAL; } | 
    EXPAND VERTICAL { $$ = SPRITE_FLAG_EXPAND_VERTICAL; } | 
    IGNORE COLOR const_expr { $$ = SPRITE_FLAG_TRANSPARENCY_COLOR | ( $3 & 0x000f ); } |
    MONOCOLOR { $$ = SPRITE_FLAG_MONOCOLOR; } | 
    MULTICOLOR { $$ = SPRITE_FLAG_MULTICOLOR; };

sprite_flags1:
    sprite_flag { $$ = $1; } | 
    sprite_flag sprite_flags1 { $$ = $1 | $2; };

sprite_flags:
    { $$ = 0; }  | 
    sprite_flags1 { $$ = $1; };

pad_optional:
    { $$ = NULL; } | 
    PAD expr { $$ = $2;};

flip_image_flags:
    X { $$ = FLAG_FLIP_X; } | 
    Y { $$ = FLAG_FLIP_Y; } | 
    XY { $$ = FLAG_FLIP_X | FLAG_FLIP_Y; } | 
    YX { $$ = FLAG_FLIP_X | FLAG_FLIP_Y; };

on_bank_explicit:
    { $$ = 0; } | 
    BANKED { $$ = 1; } | 
    BANKED OP const_expr CP { $$ = $3; } | 
    FOR BANK READ { $$ = -1; } | 
    FOR BANK WRITE { $$ = -1; } | 
    FOR READ BANK { $$ = -1; } | 
    FOR WRITE BANK { $$ = -1; } |
    UNBANKED { $$ = 0; };

on_bank_implicit:
    { $$ = ((struct _Environment *)_environment)->bankedLoadDefault; } | 
    BANKED { $$ = 1; } | 
    BANKED OP const_expr CP { $$ = $3; } |
    UNBANKED { $$ = 0; };

as_datatype_mandatory: 
    AS datatype { $$ = $2; };

as_datatype: 
    { $$ = ((struct _Environment *)_environment)->defaultVariableType; } | 
    as_datatype_mandatory;

as_datatype_suffix:
    OP_AMPERSAND { $$ = VT_SDWORD; } | 
    OP_AMPERSAND OP_AMPERSAND { $$ = VT_NUMBER; } | 
    OP_AT { $$ = VT_SBYTE; } | 
    OP_DOLLAR { $$ = VT_DSTRING; } | 
    OP_DOLLAR2 { $$ = VT_DOJOKA; } |
    OP_EXCLAMATION { $$ = VT_FLOAT; } | 
    OP_HASH { $$ = VT_BYTE; } | 
    OP_PERC { $$ = VT_SWORD; };

as_datatype_suffix_optional: 
    { $$ = 0; } | 
    as_datatype_suffix { $$ = $1; };

datatype: 
    BIT { $$ = VT_BIT; } | 
    BYTE { $$ = VT_BYTE; } | 
    SIGNED BYTE { $$ = VT_SBYTE; } | 
    SBYTE { $$ = VT_SBYTE; } | 
    WORD { $$ = VT_WORD; } | 
    INT { $$ = VT_SWORD; } | 
    INTEGER { $$ = VT_SWORD; } | 
    SIGNED WORD { $$ = VT_SWORD; } | 
    DWORD { $$ = VT_DWORD; } | 
    SIGNED DWORD { $$ = VT_SDWORD; } | 
    LONG { $$ = VT_SDWORD; } | 
    float_or_single { $$ = VT_FLOAT; } | 
    NUMBER { $$ = VT_NUMBER; } | 
    ADDRESS { $$ = VT_ADDRESS; } | 
    POSITION { $$ = VT_POSITION; } | 
    COLOR { $$ = VT_COLOR; } | 
    VECTOR { $$ = VT_VECTOR2; } | 
    COLOUR { $$ = VT_COLOR; } | 
    STRING { $$ = VT_DSTRING; } | 
    COMPILED IMAGE { $$ = VT_COMPILED_IMAGE; } | 
    IMAGE { $$ = VT_IMAGE; } | 
    COMPILED IMAGES { $$ = VT_COMPILED_IMAGES; } | 
    IMAGES { $$ = VT_IMAGES; } | 
    COMPILED ATLAS { $$ = VT_COMPILED_IMAGES; } | 
    ATLAS { $$ = VT_IMAGES; } | 
    COMPILED SEQUENCE { $$ = VT_COMPILED_SEQUENCE; } | 
    SEQUENCE { $$ = VT_SEQUENCE; } | 
    MOVIE { $$ = VT_MOVIE; } | 
    IMAGEREF { $$ = VT_IMAGEREF; } | 
    PATH { $$ = VT_PATH; } | 
    MUSIC { $$ = VT_MUSIC; } | 
    SAMPLES { $$ = VT_SAMPLES; } | 
    BLIT { $$ = VT_BLIT; } | 
    SPRITE { $$ = VT_SPRITE; } | 
    MSPRITE { $$ = VT_MSPRITE; } | 
    TILE { $$ = VT_TILE; } | 
    TILES { $$ = VT_TILES; } | 
    TILESET { $$ = VT_TILESET; } | 
    TILEMAP { $$ = VT_TILEMAP; } | 
    BUFFER { $$ = VT_BUFFER; } | 
    DOJOKA { $$ = VT_DOJOKA; } | 
    TASK { $$ = VT_THREAD; } | 
    THREAD { $$ = VT_THREAD; } | 
    Identifier {
        $$ = VT_TYPE;
        Type * type = type_find( ((struct _Environment *)_environment)->types, $1 );
        if ( ! type ) {
            CRITICAL_UNKNOWN_TYPE( $1 );
        }
        ((struct _Environment *)_environment)->currentType = type;
    };

relative_optional:
    { $$ = 0; } | 
    RELATIVE { $$ = 1; };

perc:
    |
    OP_PERC;

font_schema: 
    ALPHA { $$ = FONT_SCHEMA_ALPHA; } | 
    COMPLETE { $$ = FONT_SCHEMA_COMPLETE; } |
    EMBEDDED { $$ = FONT_SCHEMA_EMBEDDED; } | 
    SEMIGRAPHIC { $$ = FONT_SCHEMA_SEMIGRAPHIC; }  | 
    STANDARD { $$ = FONT_SCHEMA_STANDARD; };

precision: 
    FAST { $$ = FT_FAST; } | 
    SINGLE { $$ = FT_SINGLE; };

audio_source:
    SN76489 { $$ = ADN_SN76489; } | 
    POKEY { $$ = ADN_POKEY; } | 
    SID { $$ = ADN_SID; } | 
    DAC1 { $$ = ADN_DAC1; } | 
    AY8910 { $$ = ADN_AY8910; } | 
    TED { $$ = ADN_TED; } | 
    VIC { $$ = ADN_VIC1; };

/*============================================================================
 ============ CONSTANT FACTORS
 ============================================================================*/

const_factor: 
    Integer {
        $$ = $1;
    }
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
    | FALSE {
        $$ = 0x0;
    }
    | TRUE {
        $$ = 0xff;
    }
    | RGB OP const_expr OP_COMMA const_expr OP_COMMA const_expr CP {
        if ( ((Environment *)_environment)->currentRgbConverterFunction ) {
        $$ = ((Environment *)_environment)->currentRgbConverterFunction( $3, $5, $7 );
        } else {
        $$ = 0;
        }
    }
    | COLORS {
        $$ = ((Environment *)_environment)->screenColors;
    }
    | COLOURS {
        $$ = ((Environment *)_environment)->screenColors;
    }
    | MIN OP const_expr OP_COMMA const_expr CP {
        if ( $3 < $5 ) {
        $$ = $3;
        } else {
        $$ = $5;
        }
    }
    | MAX OP const_expr OP_COMMA const_expr CP {
        if ( $3 > $5 ) {
        $$ = $3;
        } else {
        $$ = $5;
        }
    }
    | SCREEN COLORS {
        $$ = ((Environment *)_environment)->screenColors;
    }
    | SCREEN COLOURS {
        $$ = ((Environment *)_environment)->screenColors;
    }
    | SHADES {
        $$ = ((Environment *)_environment)->screenShades;
    }
    | SCREEN SHADES {
        $$ = ((Environment *)_environment)->screenShades;
    }
    | XTEXT OP const_expr CP {
        $$ = $3 / ((Environment *)_environment)->fontWidth;
    }
    | X TEXT OP const_expr CP {
        $$ = $4 / ((Environment *)_environment)->fontWidth;
    }
    | YTEXT OP const_expr CP {
        $$ = $3 / ((Environment *)_environment)->fontHeight;
    }
    | Y TEXT OP const_expr CP {
        $$ = $4 / ((Environment *)_environment)->fontHeight;
    }
    | XGRAPHIC OP const_expr CP {
        $$ = $3 * ((Environment *)_environment)->fontWidth;
    }
    | X GRAPHIC OP const_expr CP {
        $$ = $4 * ((Environment *)_environment)->fontWidth;
    }
    | YGRAPHIC OP const_expr CP {
        $$ = $3 * ((Environment *)_environment)->fontHeight;
    }
    | Y GRAPHIC OP const_expr CP {
        $$ = $4 * ((Environment *)_environment)->fontHeight;
    }
    | WIDTH {
        $$ = ((Environment *)_environment)->screenWidth;
    }
    | TILES {
        $$ = ((Environment *)_environment)->screenTiles;
    }
    | FIND WIDTH OP const_expr CP {
        int widthModulus = ( ((Environment *)_environment)->screenWidth ) / $4;
        int width = ( widthModulus / 8 ) * 8;
        $$ = width;
    }
    | FIND WIDTH OP const_expr OP_COMMA const_expr CP {
        int widthModulus = ( ((Environment *)_environment)->screenWidth - $6 ) / $4;
        int width = ( widthModulus / 8 ) * 8;
        $$ = width;
    }
    | FWIDTH OP const_expr CP {
        int widthModulus = ( ((Environment *)_environment)->screenWidth ) / $3;
        int width = ( widthModulus / 8 ) * 8;
        $$ = width;
    }
    | FWIDTH OP const_expr OP_COMMA const_expr CP {
        int widthModulus = ( ((Environment *)_environment)->screenWidth - $5 ) / $3;
        int width = ( widthModulus / 8 ) * 8;
        $$ = width;
    }
    | SCREEN WIDTH {
        $$ = ((Environment *)_environment)->screenWidth;
    }
    | PAGE Integer {
        if ( ($2 != 0) && ($2 != 1) ) {
            CRITICAL_PAGE01();
        }
        $$ = $2;
    }
    | PAGE "A" {
        $$ = DOUBLE_BUFFER_PAGE_0;
    }
    | PAGE "B" {
        $$ = DOUBLE_BUFFER_PAGE_1;
    }
    | SCREEN TILES WIDTH {
        $$ = ((Environment *)_environment)->screenTilesWidth;
    }
    | TILES WIDTH {
        $$ = ((Environment *)_environment)->consoleTilesWidth;
    }
    | TILEMAP WIDTH OP expr CP {
        Variable * v = variable_retrieve( _environment, $4 );
        if ( v->type == VT_TILEMAP ) {
            $$ = v->mapWidth;
        } else {
            CRITICAL_TILEMAP_WIDTH_NO_TILEMAP( $4 );
        }
    }
    | TILE WIDTH OP expr CP {
        if ( ! ((Environment *)_environment)->emptyProcedure ) {
        Variable * v = variable_retrieve( _environment, $4 );
        if ( v->type == VT_IMAGES && v->originalTileset != NULL ) {
            $$ = v->frameWidth;
        } else {
            CRITICAL_TILE_WIDTH_NO_TILESET( $4 );
        }
        } else {
        $$ = 0;
        }
    }
    | SCREEN COLUMNS {
        $$ = ((Environment *)_environment)->screenTilesWidth;
    }
    | COLUMNS {
        $$ = ((Environment *)_environment)->consoleTilesWidth;
    }
    | FONT WIDTH {
        $$ = ((Environment *)_environment)->fontWidth;
    
    }
    | BETA {
#ifdef __BETA__
        $$ = 1;
#else
        $$ = 0;
#endif
    }
    | IMAGE WIDTH OP expr CP {
        if ( !((Environment *)_environment)->emptyProcedure ) {
        Variable * v = variable_retrieve( _environment, $4 );
        if ( v->type != VT_IMAGE && v->type != VT_IMAGES && v->type != VT_SEQUENCE && v->type != VT_MOVIE ) {
            CRITICAL_NOT_IMAGE( v->name );
        }
        int overallOffset = 0;
        if ( v->type == VT_IMAGES || v->type == VT_SEQUENCE || v->type == VT_MOVIE ) {
            overallOffset = 3;
        }
        if ( !v->valueBuffer ) {
            CRITICAL_NOT_ASSIGNED_IMAGE( v->name );
        }
        switch( v->type ) {
            case VT_IMAGE:
                $$ = v->originalWidth;
                break;
            case VT_IMAGES:
            case VT_SEQUENCE:
            case VT_MOVIE:
                $$ = v->frameWidth;
                break;
        }
        } else {
        $$ = 0;
        }
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
    | SPRITE COUNT {
        $$ = SPRITE_COUNT;
    }
    | VOLUME MIN {
        $$ = 0;
    }
    | VOLUME MAX {
        $$ = 255;
    }
    | SCREEN SPRITE RATIO X {
        $$ = SCREEN_SPRITE_RATIO_X;
    }
    | SCREEN SPRITE RATIO Y {
        $$ = SCREEN_SPRITE_RATIO_Y;
    }
    | SPRITE HEIGHT {
        if ( SPRITE_HEIGHT < 0 ) {
            CRITICAL_CANNOT_CALCULATE_SPRITE_HEIGHT( );
        }
        $$ = SPRITE_HEIGHT;
    }
    | SCREEN BORDER X {
        $$ = SCREEN_BORDER_X;
    }
    | SCREEN BORDER Y {
        $$ = SCREEN_BORDER_Y;
    }
    | SPRITE WIDTH {
        if ( SPRITE_WIDTH < 0 ) {
            CRITICAL_CANNOT_CALCULATE_SPRITE_WIDTH( );
        }
        $$ = SPRITE_WIDTH;
    }
    | SPRITE X MIN {
        $$ = SPRITE_X_MIN;
    }
    | SPRITE MIN X {
        $$ = SPRITE_X_MIN;
    }
    | SPRITE MIN Y {
        $$ = SPRITE_Y_MIN;
    }
    | SPRITE Y MIN {
        $$ = SPRITE_Y_MIN;
    }
    | SPRITE X MAX {
        $$ = SPRITE_X_MAX;
    }
    | SPRITE MAX X {
        $$ = SPRITE_X_MAX;
    }
    | SPRITE MAX Y {
        $$ = SPRITE_Y_MAX;
    }
    | SPRITE Y MAX {
        $$ = SPRITE_Y_MAX;
    }
    | LITTLE ENDIAN {
    #if defined(__c128z__) || defined(__vg5000__) || defined(__zx__) || \
        defined(__coleco__) || defined(__cpc__) || defined(__sc3000__) || \
        defined(__sc3000__) || defined(__sg1000__) ||  defined(__msx1__) || \
        defined(__atari__) || defined(__atarixl__) || defined(__c64__) || \
        defined(__c128__) || defined(__plus4__) || defined(__vic20__) || \
        defined( __c64reu__) || defined(__pc1403__) ||  defined(__gb__) || \
        defined(__pccga__) || defined( __vz200__) 
        $$ = 1;
    #else
        $$ = 0;
    #endif
    }
    | BIG ENDIAN {
    #if defined(__coco__) || defined(__d32__) || defined(__d64__) || \
        defined(__pc128op__) || defined(__mo5__) || defined(__coco3__) || \
        defined(__to8__) || defined(__d32b__) || defined(__d64b__) || defined(__cocob__)
        $$ = 1;
    #else
        $$ = 0;
    #endif
    }
    | filesize OP const_expr_string CP {
        $$ = file_size( _environment, $3 );
    }
    | HEIGHT {
        $$ = ((Environment *)_environment)->screenHeight;
    }
    | FIND HEIGHT OP const_expr CP {
        int heightModulus = ( ((Environment *)_environment)->screenHeight ) / $4;
        int height = ( heightModulus / 8 ) * 8;
        $$ = height;
    }
    | FIND HEIGHT OP const_expr OP_COMMA const_expr CP {
        int heightModulus = ( ((Environment *)_environment)->screenHeight - $6 ) / $4;
        int height = ( heightModulus / 8 ) * 8;
        $$ = height;
    }
    | FHEIGHT OP const_expr CP {
        int heightModulus = ( ((Environment *)_environment)->screenHeight ) / $3;
        int height = ( heightModulus / 8 ) * 8;
        $$ = height;
    }
    | FHEIGHT OP const_expr OP_COMMA const_expr CP {
        int heightModulus = ( ((Environment *)_environment)->screenHeight - $5 ) / $3;
        int height = ( heightModulus / 8 ) * 8;
        $$ = height;
    }
    | SCREEN HEIGHT {
        $$ = ((Environment *)_environment)->screenHeight;
    }
    | SCREEN TILES HEIGHT {
        $$ = ((Environment *)_environment)->screenTilesHeight;
    }
    | TILES HEIGHT {
        $$ = ((Environment *)_environment)->consoleTilesHeight;
    }
    | TILEMAP HEIGHT OP expr CP {
        Variable * v = variable_retrieve( _environment, $4 );
        if ( v->type == VT_TILEMAP ) {
            $$ = v->mapHeight;
        } else {
            CRITICAL_TILEMAP_HEIGHT_NO_TILEMAP( $4 );
        }
    }
    | TILE HEIGHT OP expr CP {
        if ( ! ((Environment *)_environment)->emptyProcedure ) {
        Variable * v = variable_retrieve( _environment, $4 );
        if ( v->type == VT_IMAGES && v->originalTileset != NULL ) {
            $$ = v->frameHeight;
        } else {
            CRITICAL_TILE_HEIGHT_NO_TILESET( $4 );
        }
        } else {
        $$ = 0;
        }
    }
    | SCREEN ROWS {
        $$ = ((Environment *)_environment)->screenTilesHeight;
    }
    | ROWS {
        $$ = ((Environment *)_environment)->consoleTilesHeight;
    }
    | FONT HEIGHT {
        $$ = ((Environment *)_environment)->fontHeight;
    }
    | IMAGE HEIGHT OP expr CP {
        if ( ! ((Environment *)_environment)->emptyProcedure ) {
        Variable * v = variable_retrieve( _environment, $4 );
        if ( v->type != VT_IMAGE && v->type != VT_IMAGES && v->type != VT_SEQUENCE && v->type != VT_MOVIE ) {
            CRITICAL_NOT_IMAGE( v->name );
        }
        int overallOffset = 0;
        if ( v->type == VT_IMAGES || v->type == VT_SEQUENCE || v->type == VT_MOVIE ) {
            overallOffset = 3;
        }
        if ( !v->valueBuffer ) {
            CRITICAL_NOT_ASSIGNED_IMAGE( v->name );
        }        
        switch( v->type ) {
            case VT_IMAGE:
                $$ = v->originalHeight;
                break;
            case VT_IMAGES:
            case VT_SEQUENCE:
            case VT_MOVIE:
                $$ = v->frameHeight;
                break;
        }
        } else {
        $$ = 0;
        }
    }
    | UBOUND OP Identifier CP {
        Variable * array = variable_retrieve( _environment, $3 );
        if ( array->type != VT_TARRAY ) {
        CRITICAL_NOT_ARRAY( $3 );
        }
        $$ = array->arrayDimensionsEach[array->arrayDimensions-1]-1;
    }
    | UBOUND OP Identifier OP_COMMA const_expr CP {
    Variable * array = variable_retrieve( _environment, $3 );
    if ( array->type != VT_TARRAY ) {
        CRITICAL_NOT_ARRAY( $3 );
    }
    if ( ( array->arrayDimensions == 1 ) && ( $5 > 1 ) ) {
        CRITICAL_ARRAY_MONODIMENSIONAL( $3 );
    }
    if ( ( array->arrayDimensions > 1 ) && ( $5 > array->arrayDimensions ) ) {
        CRITICAL_ARRAY_INVALID_DIMENSION( $3 );
    }
    $$ = array->arrayDimensionsEach[array->arrayDimensions-$5-1]-1;
    }
    | LBOUND OP Identifier CP {
        Variable * array = variable_retrieve( _environment, $3 );
        if ( array->type != VT_TARRAY ) {
        CRITICAL_NOT_ARRAY( $3 );
        }
        $$ = 0;
    }
    | LBOUND OP Identifier OP_COMMA const_expr CP {
    Variable * array = variable_retrieve( _environment, $3 );
    if ( array->type != VT_TARRAY ) {
        CRITICAL_NOT_ARRAY( $3 );
    }
    if ( ( array->arrayDimensions == 1 ) && ( $5 > 1 ) ) {
        CRITICAL_ARRAY_MONODIMENSIONAL( $3 );
    }
    if ( ( array->arrayDimensions > 1 ) && ( $5 > array->arrayDimensions ) ) {
        CRITICAL_ARRAY_INVALID_DIMENSION( $3 );
    }
    $$ = 0;
    }
    | JOY COUNT {
        $$ = JOY_COUNT;
    }
    | JOYCOUNT {
        $$ = JOY_COUNT;
    }
    | LEN OP Identifier CP {
        Constant * c = constant_find( _environment, $3 );
        if ( c == NULL ) {
            CRITICAL_UNDEFINED_CONSTANT( $3 );
        }
        if ( c->type != CT_STRING ) {
            CRITICAL_TYPE_MISMATCH_CONSTANT_STRING( $3 );
        }
        $$ = strlen( c->valueString->value );
    }
    | LEN OP String CP {
        $$ = strlen( $3 );
    }
    | LEN OP IF OP const_expr_string CP {
        $$ = strlen( $5 );
    }      
    | Identifier {
        Constant * c = constant_find( _environment, $1 );
        if ( c == NULL ) {
            CRITICAL_UNDEFINED_CONSTANT( $1 );
        }
        if ( c->type == CT_STRING ) {
            CRITICAL_TYPE_MISMATCH_CONSTANT_NUMERIC( $1 );
        }
        if ( c->type == CT_FLOAT ) {
            $$ = (int)(c->valueFloating);
        } else {
            $$ = c->value;
        }
    }
    | OP_HASH Identifier {
        Constant * c = constant_find( _environment, $2 );
        if ( c == NULL ) {
            CRITICAL_UNDEFINED_CONSTANT( $2 );
        }
        if ( c->type == CT_STRING ) {
            CRITICAL_TYPE_MISMATCH_CONSTANT_NUMERIC( $2 );
        }
        if ( c->type == CT_FLOAT ) {
            $$ = (int)(c->valueFloating);
        } else {
            $$ = c->value;
        }
    }
    | TILE ID OP expr OP_COMMA Identifier CP {
    $$ = tile_id( _environment, $4, $6 );
    }
    | const_color_enumeration
    | KEY const_key_scancode_definition {
    $$ = $2;
    }
    | const_key_scancode_definition {
    $$ = $1;
    }
    ;

/*============================================================================
 ============ CONSTANT EXPRESSIONS
 ============================================================================*/

const_modula: 
    const_factor | 
    const_modula OP_DIVISION const_factor { CHECK_NOTZERO_DIVISION_BY_ZERO($3); $$ = $1 / $3; } |
    const_modula OP_DIVISION2 direct_integer { CHECK_POWEROF2_INVALID_MULTIPLACTOR2( $3 ); $$ = $1 >> ((int)log2($3)); } |
    const_modula OP_MULTIPLICATION const_factor { $$ = $1 * $3; }  | 
    const_modula OP_MULTIPLICATION2 direct_integer { CHECK_POWEROF2_INVALID_MULTIPLACTOR2( $3 ); $$ = $1 << ((int)log2($3)); };

const_term:
    const_modula | 
    const_term MOD const_modula { $$ = ( $1 % $3 ); };

const_expr_math2: 
    const_term | 
    const_expr_math2 OP_MINUS const_term { $$ = $1 - $3; } |
    const_expr_math2 OP_PLUS const_term { $$ = $1 + $3; };

const_expr_math: 
    const_expr_math2 | 
    const_expr_math2 OP_ASSIGN const_expr_math2 { $$ = ( $1 == $3 ); } | 
    const_expr_math2 OP_DISEQUAL const_expr_math2 { $$ = ( $1 != $3 ); } | 
    const_expr_math2 OP_EQUAL const_expr_math2 { $$ = ( $1 == $3 ); } | 
    const_expr_math2 OP_GT const_expr_math2 { $$ = ( $1 > $3 ); } | 
    const_expr_math2 OP_GTE const_expr_math2 { $$ = ( $1 >= $3 ); } |
    const_expr_math2 OP_LT const_expr_math2 { $$ = ( $1 < $3 ); } | 
    const_expr_math2 OP_LTE const_expr_math2 { $$ = ( $1 <= $3 ); };

const_expr: 
    const_expr_math | 
    const_expr_math AND const_expr_math { $$ = ( $1 && $3 ); } | 
    const_expr_math OR const_expr_math { $$ = ( $1 || $3 ); } | 
    const_expr_math XOR const_expr_math { $$ = $1 ? !$3 : $3; } | 
    NOT const_expr { $$ = ( ! $2 ); } ;

/*============================================================================
 ============ ENUMERATIONS (CONSTANTS USING VARIABLES)
 ============================================================================*/

color_enumeration:
    BLACK { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_BLACK)->name; } | 
    BLUE { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_BLUE )->name; } | 
    BROWN { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_BROWN )->name; } |
    CYAN { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_CYAN )->name; } | 
    DARK BLUE { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_DARK_BLUE )->name; } | 
    DARK GRAY { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_DARK_GREY )->name; } | 
    DARK GREEN { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_DARK_GREEN )->name; } | 
    DARK GREY { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_DARK_GREY )->name; } | 
    DARK RED { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_DARK_RED )->name; } | 
    DARK WHITE { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_DARK_WHITE )->name; } | 
    GOLD { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_GOLD )->name; } | 
    GRAY { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_GREY )->name; } |
    GREEN { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_GREEN )->name; } | 
    GREY { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_GREY )->name; } | 
    LAVENDER { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_LAVENDER )->name; } | 
    LIGHT BLUE { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_LIGHT_BLUE )->name; } | 
    LIGHT GRAY { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_LIGHT_GREY )->name; } | 
    LIGHT GREEN { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_LIGHT_GREEN )->name; } | 
    LIGHT GREY { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_LIGHT_GREY )->name; } | 
    LIGHT RED { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_LIGHT_RED )->name; } | 
    LIGHT WHITE { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_LIGHT_WHITE )->name; } | 
    MAGENTA { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_MAGENTA )->name; } | 
    OLIVE GREEN { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_OLIVE_GREEN )->name; } | 
    ORANGE { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_ORANGE )->name; } | 
    PEACH { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_PEACH )->name; } |
    PINK { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_PINK )->name; } | 
    PURPLE { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_PURPLE )->name; } | 
    RED { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_RED )->name; } | 
    TAN { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_TAN )->name; } | 
    TURQUOISE { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_TURQUOISE )->name; } | 
    VIOLET { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_VIOLET )->name; } | 
    WHITE { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_WHITE )->name; } | 
    YELLOW { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_YELLOW )->name; } | 
    YELLOW GREEN { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_YELLOW_GREEN )->name; };

key_scancode_alphadigit:
    Integer {
        switch( $1 ) {
            case 0:
                $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_0 ) )->name;
                break;
            case 1:
                $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_1 ) )->name;
                break;
            case 2:
                $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_2 ) )->name;
                break;
            case 3:
                $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_3 ) )->name;
                break;
            case 4:
                $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_4 ) )->name;
                break;
            case 5:
                $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_5 ) )->name;
                break;
            case 6:
                $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_6 ) )->name;
                break;
            case 7:
                $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_7 ) )->name;
                break;
            case 8:
                $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_8 ) )->name;
                break;
            case 9:
                $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_9 ) )->name;
                break;
        }
    } | 
    A { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_A ) )->name; } | 
    B { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_B ) )->name; } | 
    C { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_C ) )->name; } | 
    D { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_D ) )->name; } | 
    E { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_E ) )->name; } | 
    F { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_F ) )->name; } | 
    G { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_G ) )->name; } | 
    H { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_H ) )->name; } |
    I { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_I ) )->name; } | 
    J { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_J ) )->name; } | 
    K { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_K ) )->name; } | 
    L { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_L ) )->name; } | 
    M { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_M ) )->name; } | 
    N { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_N ) )->name; } |
    O { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_O ) )->name; } | 
    P { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_P ) )->name; } | 
    Q { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_Q ) )->name; } | 
    R { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_R ) )->name; } | 
    S { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_S ) )->name; } | 
    T { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_T ) )->name; } | 
    U { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_U ) )->name; } | 
    V { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_V ) )->name; } | 
    W { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_W ) )->name; } | 
    X { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_X ) )->name; } | 
    Y { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_Y ) )->name; } | 
    Z { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_Z ) )->name; };

key_scancode_function_digit:
    F1 { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_F1 ) )->name; } | 
    F2 { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_F2 ) )->name; } | 
    F3 { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_F3 ) )->name; } | 
    F4 { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_F4 ) )->name; } | 
    F5 { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_F5 ) )->name; } | 
    F6 { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_F6 ) )->name; } |
    F7 { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_F7 ) )->name; } | 
    F8 { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_F8 ) )->name; };

key_scancode_definition: 
    ARROW LEFT { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_LEFT_ARROW ) )->name; } |
    ARROW UP { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_UP_ARROW ) )->name; } |
    ASTERISK { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_ASTERISK ) )->name; } | 
    AT { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_AT ) )->name; } | 
    CLEAR { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_CLEAR ) )->name; } |
    COLON { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_COLON ) )->name; } |
    COMMA { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_COMMA ) )->name; } | 
    COMMODORE { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_COMMODORE ) )->name; } |
    CONTROL { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_CONTROL ) )->name; } | 
    CRSR LEFT RIGHT { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_CRSR_LEFT_RIGHT ) )->name; } |
    CRSR UP DOWN { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_CRSR_UP_DOWN ) )->name; } |
    DELETE { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_DELETE ) )->name; } | 
    DOWN { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_DOWN ) )->name; } |
    EQUAL { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_EQUAL ) )->name; } | 
    INSERT { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_INSERT ) )->name; } |
    key_scancode_alphadigit { $$ = $1; } | 
    key_scancode_function_digit { $$ = $1; } | HOME { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_HOME ) )->name; } |
    LEFT { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_LEFT ) )->name; } |
    LEFT ARROW { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_LEFT_ARROW ) )->name; } |
    MINUS { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_MINUS ) )->name; } |
    NONE { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_NONE ) )->name; } |
    PERIOD { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_PERIOD ) )->name; } |
    PLUS { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_PLUS ) )->name; } |
    POUND { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_POUND ) )->name; } |
    RETURN { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_RETURN ) )->name; } |
    RIGHT { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_RIGHT ) )->name; } |
    RUN STOP { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_RUNSTOP ) )->name; } |
    RUNSTOP { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_RUNSTOP ) )->name; } |
    SEMICOLON { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_SEMICOLON ) )->name; } |
    SLASH { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_SLASH ) )->name; } |
    SPACE { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_SPACE ) )->name; } |
    TAB { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_TAB ) )->name; } | 
    UP { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_UP ) )->name; } | 
    UP ARROW { $$ = variable_by_constant( _environment, VT_BYTE, key_constant( _environment, KEY_UP_ARROW ) )->name; };

animation_type:
      SIMPLE { ((struct _Environment *)_environment)->animationType = AT_SIMPLE; } | 
      BOUNCE { ((struct _Environment *)_environment)->animationType = AT_BOUNCE; } | 
      LOOP { ((struct _Environment *)_environment)->animationType = AT_LOOP; };

endianess_optional:
    { $$ = 0; } | 
    LITTLE ENDIAN { $$ = 0; } | 
    BIG ENDIAN { $$ = 1; };

/*============================================================================
 ============ EXTENDED SYNTAXES
 ============================================================================*/

target: 
    CPUZ80 {
            #if defined(__c128z__) || defined(__vg5000__) || defined(__zx__) || \
                defined(__coleco__) || defined(__cpc__) || defined(__sc3000__) || \
                defined(__sc3000__) || defined(__sg1000__) ||  defined(__msx1__) || \
                defined(__vz200__)
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } | 
    CPUSM83 {
            #if defined(__gb__)
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } | 
    CPU6809 {
            #if defined(__coco__) || defined(__d32__) || defined(__d64__) || \
                defined(__pc128op__) || defined(__mo5__) || defined(__coco3__) || \
                defined(__to8__) || defined(__d32b__) || defined(__d64b__) || defined(__cocob__)
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } | 
    CPU6309 {
            #if defined(__d32b__) || defined(__d64b__) || defined(__cocob__) || defined(__coco3b__)
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } | 
    CPUSC61860 {
            #if defined(__pc1403__)
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } | 
    CPU6502 {
            #if defined(__atari__) || defined(__atarixl__) || \
                defined(__c128__) || defined(__vic20__)
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } | 
    CPU6510 {
            #if defined(__c64__) || defined( __c64reu__)
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } | 
    CPU7501 {
            #if defined(__c16__) || defined( __plus4__)
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } | 
    CPU8501 {
            #if defined(__c16__) || defined( __plus4__)
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } | 
    CPU8502 {
            #if defined(__c128__)
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } | 
    CPU8086 {
            #if defined(__pccga__)
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } | 
    ATARI {
            #ifdef __atari__
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } | 
    ATARIXL {
            #ifdef __atarixl__
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    C128 {
            #ifdef __c128__
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    C128Z {
            #ifdef __c128z__
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    C64 {
            #ifdef __c64__
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    C64REU {
            #ifdef __c64reu__
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    VIC20 {
            #ifdef __vic20__
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    VG5000 {
            #ifdef __vg5000__
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    ZX {
            #ifdef __zx__
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    COLECO {
            #ifdef __coleco__
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    PCCGA {
            #ifdef __pccga__
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    CPC {
            #ifdef __cpc__
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    VZ200 {
            #ifdef __vz200__
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    GB {
            #ifdef __gb__
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    PLUS4 {
            #ifdef __plus4__
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    C16 {
            #ifdef __c16__
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    SC3000 {
            #ifdef __sc3000__
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    SG1000 {
            #ifdef __sg1000__
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    PC1403 {
            #ifdef __pc1403__
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    MSX {
            #ifdef __msx1__
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    MSX1 {
            #ifdef __msx1__
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    COCO {
            #if defined(__coco__) || defined(__cocob__)
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    COCO1 {
            #if defined(__coco__) || defined(__cocob__)
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    COCO2 {
            #if defined(__coco__) || defined(__cocob__)
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    COCO3 {
            #if defined(__coco3__) || defined(__coco3b__)
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    DRAGON {
            #if defined(__d32__) || defined(__d64__) || defined(__d32b__) || defined(__d64b__)
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    DRAGON32 {
            #if defined(__d32__) || defined(__d32b__)
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    DRAGON64 {
            #if defined(__d64__) || defined(__d64b__)
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    PC128OP {
            #ifdef __pc128op__
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    TO8 {
            #ifdef __to8__
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    MO5 {
            #ifdef __mo5__
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    JOYSTICK AVAILABLE {
            #if JOY_COUNT > 0
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    JOY AVAILABLE {
            #if JOY_COUNT > 0
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    JOYSTICK NOT AVAILABLE {
            #if JOY_COUNT > 0
                $$ = 0;
            #else
                $$ = 1;
            #endif
        } |
    JOY NOT AVAILABLE {
            #if JOY_COUNT > 0
                $$ = 0;
            #else
                $$ = 1;
            #endif
        } |
    SPRITE AVAILABLE {
            #if defined(__c64__) || defined(__c64reu__) || defined(__c128__) \
                || defined(__msx1__) || defined(__coleco__) \
                || defined(__sc3000__) || defined(__sg1000__)
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    SPRITE NOT AVAILABLE {
            #if defined(__c64__) || defined(__c64reu__) || defined(__c128__) \
                || defined(__msx1__) || defined(__coleco__) \
                || defined(__sc3000__) || defined(__sg1000__) \
                || defined(__gb__)
                $$ = 0;
            #else
                $$ = 1;
            #endif
        } |
    POKEY {
            #if defined(__atari__) || defined(__atarixl__) 
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    TED {
            #if defined(__c16__) || defined(__plus4__) 
                $$ = 1;
            #else
                $$ = 0;
            #endif
        } |
    SID {
            #if defined(__c64__) || defined(__c64reu__) || defined(__c128__)  || defined(__c128z__) 
                $$ = 1;
            #else
                $$ = 0;
            #endif
        };

left_or_right:
    LEFT { $$ = -1; } |
    RIGHT { $$ = 1; };

up_or_down:
    UP { $$ = -1; } |
    DOWN { $$ = 1; };

targets:
     target { $$ = $1; } | 
     target OP_COMMA targets { $$ = $1 || $3; };

on_targets: 
    { $$ = 1; } | 
    ON targets { $$ = $2; } | 
    ON ALL BUT targets { $$ = ( $4 ) ? 0: 1; };

parallel_optional: 
    { $$ = 0; } |
    PARALLEL { $$ = 1; };

safe_fast_optional:
    { $$ = ((struct _Environment *)_environment)->optionReadSafe; } |
    SAFE { $$ = 1; } | 
    FAST { $$ = 0; };

op_comma_or_semicolon: 
    OP_COMMA { $$ = 0; } | 
    OP_SEMICOLON { $$ = 1; };

milliseconds_optional:
    |
    milliseconds
    ;

step_optional:
    { $$ = NULL; } | 
    STEP expr { $$ = $2; };

system_optional: 
    { $$ = 0; } | 
    SYSTEM { $$ = 1; };

raw_optional: 
    { $$ = ((struct _Environment *)_environment)->printRaw; }
    | RAW { $$ = 1; };

static_optional:
    |
    STATIC;

optional_by:
    { $$ = NULL; } | 
    BY expr { $$ = $2; };

memory_video_optional:
    { $$ = 0; } | 
    MEMORY { $$ = 0; } | 
    VIDEO { $$ = 1; };

loop_optional:
    { $$ = 0; } | 
    LOOP { $$ = 1; };

on_off_optional: 
    { $$ = 1; } | 
    ON { $$ = 1; } | 
    OFF { $$ = 0; };

origin_direction_optional:
    { $$ = 1; } | 
    DOWN { $$ = 1; } | 
    UP { $$ = -1; };

to_identifier_optional: 
    { $$ = NULL; } | 
    TO Identifier { $$ = $2; };

array_assignment:
    OP_ASSIGN expr {
            ((struct _Environment *)_environment)->currentFieldName = NULL;
            ((struct _Environment *)_environment)->currentExpression = $2;
        } | 
    OP_PERIOD Identifier OP_ASSIGN expr {
            ((struct _Environment *)_environment)->currentFieldName = $2;
            ((struct _Environment *)_environment)->currentExpression = $4;
        };

thread_identifiers:
    expr {
            Variable * array = variable_retrieve( _environment, $1 );
            if ( array->type != VT_TARRAY || array->arrayType != VT_THREAD ) {
                ((struct _Environment *)_environment)->threadIdentifier[((struct _Environment *)_environment)->lastThreadIdentifierUsed] = strdup( $1 );
                ++((struct _Environment *)_environment)->lastThreadIdentifierUsed;
            } else {
                for( int i=0; i<array->size; ++i ) {
                    parser_array_init( _environment );
                    parser_array_index_numeric( _environment, i );
                    ((struct _Environment *)_environment)->threadIdentifier[((struct _Environment *)_environment)->lastThreadIdentifierUsed] = strdup( variable_move_from_array( _environment, array->name )->name );
                    ++((struct _Environment *)_environment)->lastThreadIdentifierUsed;
                }
            }
        } | 
    expr OP_COMMA thread_identifiers {
            Variable * array = variable_retrieve( _environment, $1 );
            if ( array->type != VT_TARRAY || array->arrayType != VT_THREAD ) {
                ((struct _Environment *)_environment)->threadIdentifier[((struct _Environment *)_environment)->lastThreadIdentifierUsed] = strdup( $1 );
                ++((struct _Environment *)_environment)->lastThreadIdentifierUsed;
            } else {
                for( int i=0; i<array->size; ++i ) {
                    parser_array_init( _environment );
                    parser_array_index_numeric( _environment, i );
                    ((struct _Environment *)_environment)->threadIdentifier[((struct _Environment *)_environment)->lastThreadIdentifierUsed] = strdup( variable_move_from_array( _environment, array->name )->name );
                    ++((struct _Environment *)_environment)->lastThreadIdentifierUsed;
                }
            }
        };

dimensions:
    {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = -1;
          ++((struct _Environment *)_environment)->arrayDimensions;
    } | 
    const_expr {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = $1;
          ++((struct _Environment *)_environment)->arrayDimensions;
    } | 
    const_expr OP_COMMA dimensions {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = $1;
          ++((struct _Environment *)_environment)->arrayDimensions;
    };

indexes:
    expr {
        Variable * expr = variable_retrieve( _environment, $1 );
        if ( expr->initializedByConstant ) {
            parser_array_index_numeric( _environment, expr->value );
        } else {
            parser_array_index_symbolic( _environment, $1 );
        }
    } | 
    expr OP_COMMA indexes {
        Variable * expr = variable_retrieve( _environment, $1 );
        if ( expr->initializedByConstant ) {
            parser_array_index_numeric( _environment, expr->value );
        } else {
            parser_array_index_symbolic( _environment, $1 );
        }
    } | 
    OP_HASH const_expr { parser_array_index_numeric( _environment, $2 ); } | 
    OP_HASH const_expr OP_COMMA indexes { parser_array_index_numeric( _environment, $2 ); };

parameters: 
    Identifier as_datatype_mandatory {
        ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
        ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = $2;
        ++((struct _Environment *)_environment)->parameters;
    } | 
    Identifier as_datatype_suffix_optional {
        VariableType vt = $2;
        if ( vt == 0 ) {
            vt = ((struct _Environment *)_environment)->defaultVariableType;
        }
        ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
        ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = vt;
        ++((struct _Environment *)_environment)->parameters;
    } | 
    Identifier as_datatype_mandatory OP_COMMA parameters {
        ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
        ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = $2;
        ++((struct _Environment *)_environment)->parameters;
    } | 
    Identifier as_datatype_suffix_optional OP_COMMA parameters {
        VariableType vt = $2;
        if ( vt == 0 ) {
            vt = ((struct _Environment *)_environment)->defaultVariableType;
        }
        ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
        ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = vt;
        ++((struct _Environment *)_environment)->parameters;
    }
    ;

parameters_expr: 
    |
    Identifier OP_DOLLAR {
        ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
        ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_DSTRING;
        ++((struct _Environment *)_environment)->parameters;
    } | 
    Identifier as_datatype {
        ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
        ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = $2;
        ++((struct _Environment *)_environment)->parameters;
    } | 
    Identifier OP_DOLLAR OP_COMMA parameters_expr {
        ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
        ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_DSTRING;
        ++((struct _Environment *)_environment)->parameters;
    } | 
    Identifier as_datatype OP_COMMA parameters_expr {
        ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
        ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = $2;
        ++((struct _Environment *)_environment)->parameters;
    } | 
    String {
        ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
        ++((struct _Environment *)_environment)->parameters;
    } | 
    RawString {
        ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
        ++((struct _Environment *)_environment)->parameters;
    } | 
    String OP_COMMA parameters_expr {
        ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
        ++((struct _Environment *)_environment)->parameters;
    } | 
    RawString OP_COMMA parameters_expr {
        ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
        ++((struct _Environment *)_environment)->parameters;
    };

values: 
    expr {
        Variable * v = variable_retrieve( _environment, $1 );
        if ( v->initializedByConstant && VT_BITWIDTH( v->type ) > 0 ) {
            ((struct _Environment *)_environment)->parametersValueEach[((struct _Environment *)_environment)->parameters] = v->value;
            ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = NULL;
        } else {
            ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
        }
        ++((struct _Environment *)_environment)->parameters;
    } | 
    expr OP_COMMA values {
        Variable * v = variable_retrieve( _environment, $1 );
        if ( v->initializedByConstant && VT_BITWIDTH( v->type ) > 0 ) {
            ((struct _Environment *)_environment)->parametersValueEach[((struct _Environment *)_environment)->parameters] = v->value;
            ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = NULL;
        } else {
            ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
        }
        ++((struct _Environment *)_environment)->parameters;
    };

asmio: 
    Register { $$ = cpu_register_decode( _environment, $1 ); } | 
    STACK OP BYTE CP { $$ = (int)STACK_BYTE; } | 
    STACK OP WORD CP { $$ = (int)STACK_WORD; } | 
    STACK OP DWORD CP { $$ = (int)STACK_DWORD; };

values_asmios:
    asmio OP_ASSIGN expr {
        ((struct _Environment *)_environment)->parametersAsmioEach[((struct _Environment *)_environment)->parameters] = $1;
        ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $3 );
        ++((struct _Environment *)_environment)->parameters;
    } | 
    asmio OP_ASSIGN expr OP_COMMA values_asmios {
        ((struct _Environment *)_environment)->parametersAsmioEach[((struct _Environment *)_environment)->parameters] = $1;
        ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $3 );
        ++((struct _Environment *)_environment)->parameters;
    } | 
    asmio OP_ASSIGN OP_HASH const_expr {
        ((struct _Environment *)_environment)->parametersAsmioEach[((struct _Environment *)_environment)->parameters] = $1;
        ((struct _Environment *)_environment)->parametersValueEach[((struct _Environment *)_environment)->parameters] = $4;
        ++((struct _Environment *)_environment)->parameters;
    } | 
    asmio OP_ASSIGN OP_HASH const_expr OP_COMMA values_asmios {
        ((struct _Environment *)_environment)->parametersAsmioEach[((struct _Environment *)_environment)->parameters] = $1;
        ((struct _Environment *)_environment)->parametersValueEach[((struct _Environment *)_environment)->parameters] = $4;
        ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = NULL;
        ++((struct _Environment *)_environment)->parameters;
    };

parameters_asmios:
    Identifier as_datatype ON asmio {
        ((struct _Environment *)_environment)->parametersAsmioEach[((struct _Environment *)_environment)->parameters] = $4;
        ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = $2;
        ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
        ++((struct _Environment *)_environment)->parameters;
    } | 
    Identifier as_datatype ON asmio {
        ((struct _Environment *)_environment)->parametersAsmioEach[((struct _Environment *)_environment)->parameters] = $4;
        ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = $2;
        ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
        ++((struct _Environment *)_environment)->parameters;
    } OP_COMMA parameters_asmios | 
    OP_HASH const_expr ON asmio {
        ((struct _Environment *)_environment)->parametersAsmioEach[((struct _Environment *)_environment)->parameters] = $4;
        ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = -1;
        ((struct _Environment *)_environment)->parametersValueEach[((struct _Environment *)_environment)->parameters] = $2;
        ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = NULL;
        ++((struct _Environment *)_environment)->parameters;
    } | 
    OP_HASH const_expr ON asmio  {
        ((struct _Environment *)_environment)->parametersAsmioEach[((struct _Environment *)_environment)->parameters] = $4;
        ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = -1;
        ((struct _Environment *)_environment)->parametersValueEach[((struct _Environment *)_environment)->parameters] = $2;
        ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = NULL;
        ++((struct _Environment *)_environment)->parameters;
    } OP_COMMA parameters_asmios | 
    OUT Identifier as_datatype ON asmio {
        ((struct _Environment *)_environment)->returnsAsmioEach[((struct _Environment *)_environment)->returns] = $5;
        ((struct _Environment *)_environment)->returnsTypeEach[((struct _Environment *)_environment)->returns] = $3;
        ((struct _Environment *)_environment)->returnsEach[((struct _Environment *)_environment)->returns] = strdup( $2 );
        ++((struct _Environment *)_environment)->returns;
    } | 
    OUT Identifier as_datatype ON asmio {
        ((struct _Environment *)_environment)->returnsAsmioEach[((struct _Environment *)_environment)->returns] = $5;
        ((struct _Environment *)_environment)->returnsTypeEach[((struct _Environment *)_environment)->returns] = $3;
        ((struct _Environment *)_environment)->returnsEach[((struct _Environment *)_environment)->returns] = strdup( $2 );
        ++((struct _Environment *)_environment)->returns;
    } OP_COMMA parameters_asmios;

return_parameter_asmios2: 
    asmio as_datatype {
        ((struct _Environment *)_environment)->returnsAsmioEach[((struct _Environment *)_environment)->returns] = $1;
        ((struct _Environment *)_environment)->returnsTypeEach[((struct _Environment *)_environment)->returns] = $2;
        ((struct _Environment *)_environment)->returnsEach[((struct _Environment *)_environment)->returns] = NULL;
        ++((struct _Environment *)_environment)->returns;
    };

return_parameter_asmios: 
    | 
    RETURN return_parameter_asmios2;
    ;

return_values_asmios2: 
    Identifier OP_ASSIGN asmio {
        ((struct _Environment *)_environment)->returnsAsmioEach[((struct _Environment *)_environment)->returns] = $3;
        ((struct _Environment *)_environment)->returnsEach[((struct _Environment *)_environment)->returns] = strdup( $1 );
        ++((struct _Environment *)_environment)->returns;
    } | 
    Identifier OP_ASSIGN asmio OP_COMMA return_values_asmios2 {
        ((struct _Environment *)_environment)->returnsAsmioEach[((struct _Environment *)_environment)->returns] = $3;
        ((struct _Environment *)_environment)->returnsEach[((struct _Environment *)_environment)->returns] = strdup( $1 );
        ++((struct _Environment *)_environment)->returns;
    };

return_values_asmios: 
    | 
    RETURN return_values_asmios2;

// Fix
optional_x_or_string:
    RELATIVE expr { $$ = origin_resolution_relative_transform_x( _environment, $2, 1 )->name; } |
    expr {
        Variable * t = variable_retrieve( _environment, $1 );
        if ( ( t->type == VT_STRING ) || ( t->type == VT_DSTRING ) ) {
            $$ = $1;
        } else {
            $$ = origin_resolution_relative_transform_x( _environment, $1, 0 )->name;
        }
    } |
    { $$ = origin_resolution_relative_transform_x( _environment, NULL, 0 )->name; };

mandatory_x:
    relative_optional expr { $$ = origin_resolution_relative_transform_x( _environment, $2, $1 )->name; };

mandatory_y:
    relative_optional expr { $$ = origin_resolution_relative_transform_y( _environment, $2, $1 )->name; };

optional_x:
    { $$ = origin_resolution_relative_transform_x( _environment, NULL, 0 )->name; } |
    relative_optional expr { $$ = origin_resolution_relative_transform_x( _environment, $2, $1 )->name; };

optional_y:
    { $$ = origin_resolution_relative_transform_y( _environment, NULL, 0 )->name; } |
    relative_optional expr { $$ = origin_resolution_relative_transform_y( _environment, $2, $1 )->name; };

optional_expr:
    { $$ = NULL; } |
    expr { $$ = $1; };

/* Buffer definition syntax, with suffixes and prefixes. Note that prefix can
   be omitted, while the suffix could not. */

buffer_definition_prefix: | OSP | OP_HASH OSP;
buffer_definition_suffix: CSP;
buffer_definition_suffix_optional: | buffer_definition_suffix;

/* Explicit integer constants. */

direct_integer:
    OP_HASH Integer { $$ = $2; } |
    OP_HASH OP_MINUS Integer { $$ = -$3; } | 
    OP_HASH Identifier {
        Constant * c = constant_find( _environment, $2 );
        if ( !c ) {
            CRITICAL_UNDEFINED_CONSTANT($2);
        }
        if ( c->type == CT_STRING ) {
            CRITICAL_TYPE_MISMATCH_CONSTANT_NUMERIC($2);
        }
        if ( c->type == CT_FLOAT ) {
            $$ = (int)(c->valueFloating);
        } else {
            $$ = c->value;
        }
    };

/*============================================================================
 ============ CASTING
 ============================================================================*/

casting:
    OP BIT CP exponential_less { $$ = variable_cast( _environment, $4, VT_BIT )->name; } |
    OP BYTE CP exponential_less { $$ = variable_cast( _environment, $4, VT_BYTE )->name; } |
    OP COLOR CP exponential_less { $$ = variable_cast( _environment, $4, VT_COLOR )->name; } | 
    OP COLOUR CP exponential_less { $$ = variable_cast( _environment, $4, VT_COLOR )->name; } |
    OP DWORD CP exponential_less { $$ = variable_cast( _environment, $4, VT_DWORD )->name; } | 
    OP float_or_single CP exponential_less { $$ = variable_cast( _environment, $4, VT_FLOAT )->name; } |
    OP NUMBER CP exponential_less { $$ = variable_cast( _environment, $4, VT_NUMBER )->name; } | 
    OP POSITION CP exponential_less { $$ = variable_cast( _environment, $4, VT_POSITION )->name; } | 
    OP SBYTE OP exponential_less { $$ = variable_cast( _environment, $4, VT_SBYTE )->name; } | 
    OP SIGNED BYTE OP exponential_less { $$ = variable_cast( _environment, $5, VT_SBYTE )->name; }| 
    OP SIGNED DWORD CP exponential_less { $$ = variable_cast( _environment, $5, VT_SDWORD )->name; } | 
    OP SIGNED WORD CP exponential_less { $$ = variable_cast( _environment, $5, VT_SWORD )->name; } | 
    OP WORD CP exponential_less { $$ = variable_cast( _environment, $4, VT_WORD )->name; };

/*============================================================================
 ============ EXPRESSIONS
 ============================================================================*/

exponential:
    exponential_less
    | OP expr CP {
        $$ = $2;
    }
    ;

factor: 
    exponential | 
    factor OP_POW exponential { $$ = powering( _environment, $1, $3 )->name; } | 
    POWERING OP factor OP_COMMA exponential CP { $$ = powering( _environment, $3, $5 )->name; } | 
    factor HAS BIT exponential { $$ = variable_bit( _environment, $1, $4 )->name; } | 
    factor HAS NOT BIT exponential { $$ = variable_not( _environment, variable_bit( _environment, $1, $5 )->name )->name; } |
    factor IS exponential { $$ = variable_bit( _environment, $1, $3 )->name; } | 
    factor IS NOT exponential { $$ = variable_not( _environment, variable_bit( _environment, $1, $4 )->name )->name; } |
    BIT exponential OF factor { $$ = variable_bit( _environment, $4, $2 )->name; } | 
    OP_MINUS factor {
        Variable * expr = variable_retrieve( _environment, $2 );
        if ( expr->type == VT_FLOAT ) {
            Variable * zero = variable_temporary( _environment, VT_FLOAT, "(zero)" );
            variable_store_float( _environment, zero->name, 0 );
            $$ = variable_sub( _environment, zero->name, expr->name )->name;
        } else {
            if ( expr->initializedByConstant ) {
                Variable * zero = variable_temporary( _environment, VT_SIGN( expr->type ), "(zero)" );
                variable_store( _environment, zero->name, -expr->value );
                $$ = zero->name;
                zero->initializedByConstant = 1;
            } else {
                Variable * zero = variable_temporary( _environment, VT_SIGN( expr->type ), "(zero)" );
                variable_store( _environment, zero->name, 0 );
                $$ = variable_sub( _environment, zero->name, expr->name )->name;
            }
        }
      };

modula: 
    factor | 
    modula OP_MULTIPLICATION factor {
        Variable * modula = variable_retrieve( _environment, $1 );
        Variable * factor = variable_retrieve( _environment, $3 );
        if ( ( modula->type != VT_FLOAT && factor->type != VT_FLOAT && modula->type != VT_NUMBER && factor->type != VT_NUMBER ) && factor->initializedByConstant ) {
            if ( modula->initializedByConstant ) {
                Variable * number = variable_temporary( _environment, VT_MAX_BITWIDTH_TYPE( factor->type, modula->type ), "(constant)" );
                $$ = number->name;
                variable_store( _environment, $$, factor->value * modula->value );
                number->initializedByConstant = 1;
            } else {
                $$ = variable_mul( _environment, $1, $3 )->name;
            }
        } else {
            $$ = variable_mul( _environment, $1, $3 )->name;
        }
    } | 
    modula OP_MULTIPLICATION2 direct_integer {
        if ( log2($3) != (int)log2($3) ) {
            CRITICAL_INVALID_MULTIPLICATOR2( $3 );
        }
        $$ = variable_mul2_const( _environment, $1, $3 )->name;
    } | 
    modula OP_MULTIPLICATION2 Integer {
        if ( log2($3) != (int)log2($3) ) {
            CRITICAL_INVALID_MULTIPLICATOR2( $3 );
        }
        $$ = variable_mul2_const( _environment, $1, $3 )->name;
    } | 
    modula OP_DIVISION factor {
        $$ = variable_div( _environment, $1, $3, NULL )->name;
    } | 
    modula OP_DIVISION2 direct_integer {
        if ( log2($3) != (int)log2($3) ) {
            CRITICAL_INVALID_DIVISOR2( $3 );
        }
        $$ = variable_div2_const( _environment, $1, $3, NULL )->name;
    } | 
    modula OP_DIVISION2 Integer {
        if ( log2($3) != (int)log2($3) ) {
            CRITICAL_INVALID_DIVISOR2( $3 );
        }
        $$ = variable_div2_const( _environment, $1, $3, NULL )->name;
    };

term:
    modula | 
    term MOD modula { $$ = variable_mod( _environment, $1, $3 )->name; };

expr_math2: 
    term | 
    expr_math2 OP_PLUS term {
        Variable * v = variable_retrieve( _environment, $1 );
        Variable * expr = variable_retrieve( _environment, $3 );
        if ( expr->initializedByConstant && VT_BITWIDTH(v->type)>1 ) {
            $$ = variable_add_const( _environment, $1, expr->value )->name;
        } else {
            $$ = variable_add( _environment, $1, $3 )->name;
        }
    } | 
    expr_math2 OP_MINUS term {
        Variable * v = variable_retrieve( _environment, $1 );
        Variable * expr = variable_retrieve( _environment, $3 );
        if ( expr->initializedByConstant && VT_BITWIDTH(v->type)>1 ) {
            $$ = variable_sub_const( _environment, $1, expr->value )->name;
        } else {
            $$ = variable_sub( _environment, $1, $3 )->name;
        }
    };

expr_math: 
      expr_math2 | 
      expr_math2 OP_EQUAL OP_HASH const_expr_math2 { $$ = variable_compare_const( _environment, $1, $4 )->name; } | 
      expr_math2 OP_EQUAL expr_math {
        Variable * expr = variable_retrieve( _environment, $3 );
        if ( expr->initializedByConstant ) {
            $$ = variable_compare_const( _environment, $1, expr->value )->name;
        } else {
            $$ = variable_compare( _environment, $1, $3 )->name;
        }
    } | 
    expr_math2 OP_ASSIGN OP_HASH const_expr_math2 { $$ = variable_compare_const( _environment, $1, $4 )->name; } | 
    expr_math2 OP_ASSIGN expr_math {
        Variable * expr = variable_retrieve( _environment, $3 );
        if ( expr->initializedByConstant ) {
            $$ = variable_compare_const( _environment, $1, expr->value )->name;
        } else {
            $$ = variable_compare( _environment, $1, $3 )->name;
        }
    } | 
    expr_math2 OP_DISEQUAL direct_integer { $$ = variable_compare_not_const( _environment, $1, $3 )->name; } | 
    expr_math2 OP_DISEQUAL expr_math {
        Variable * expr = variable_retrieve( _environment, $3 );
        if ( expr->initializedByConstant ) {
            $$ = variable_compare_not_const( _environment, $1, expr->value )->name;
        } else {
            $$ = variable_compare_not( _environment, $1, $3 )->name;
        }
    } | 
    expr_math2 OP_LT expr_math {
        Variable * expr = variable_retrieve( _environment, $3 );
        if ( expr->initializedByConstant ) {
            $$ = variable_less_than_const( _environment, $1, expr->value, 0 )->name;
        } else {
            $$ = variable_less_than( _environment, $1, $3, 0 )->name;
        }
    } | 
    expr_math2 OP_LTE expr_math {
        Variable * expr = variable_retrieve( _environment, $3 );
        if ( expr->initializedByConstant ) {
            $$ = variable_less_than_const( _environment, $1, expr->value, 1 )->name;
        } else {
            $$ = variable_less_than( _environment, $1, $3, 1 )->name;
        }
    } | 
    expr_math2 OP_LT OP_HASH const_expr_math2 { $$ = variable_less_than_const( _environment, $1, $4, 0 )->name; } | 
    expr_math2 OP_LTE OP_HASH const_expr_math2 { $$ = variable_less_than_const( _environment, $1, $4, 1 )->name; } | 
    expr_math2 OP_GT expr_math {
        Variable * expr = variable_retrieve( _environment, $3 );
        if ( expr->initializedByConstant ) {
            $$ = variable_greater_than_const( _environment, $1, expr->value, 0 )->name;
        } else {
            $$ = variable_greater_than( _environment, $1, $3, 0 )->name;
        }
    } | 
    expr_math2 OP_GTE expr_math {
        Variable * expr = variable_retrieve( _environment, $3 );
        if ( expr->initializedByConstant ) {
            $$ = variable_greater_than_const( _environment, $1, expr->value, 1 )->name;
        } else {
            $$ = variable_greater_than( _environment, $1, $3, 1 )->name;
        }
    } | 
    expr_math2 OP_GT OP_HASH const_expr_math2 { $$ = variable_greater_than_const( _environment, $1, $4, 0 )->name; } | 
    expr_math2 OP_GTE OP_HASH const_expr_math2 { $$ = variable_greater_than_const( _environment, $1, $4, 1 )->name; };

expr: 
    expr_math | 
    expr_math AND expr { $$ = variable_and( _environment, $1, $3 )->name; } | 
    expr_math OR expr { $$ = variable_or( _environment, $1, $3 )->name; } | 
    expr_math XOR expr { $$ = variable_xor( _environment, $1, $3 )->name; }  | 
    NOT expr { $$ = variable_not( _environment, $2 )->name; };

/*============================================================================
 ============ INSTRUCTIONS DEFINITIONS
 ============================================================================*/

/*-----------------------------------------------------------------------------
 ------------ RANDOM
 ----------------------------------------------------------------------------*/

/* RANDOM */
random_definition_simple:
    BIT { $$ = random_value( _environment, VT_BIT )->name; } | 
    BYTE { $$ = random_value( _environment, VT_BYTE )->name; } | 
    COLOR { $$ = random_value( _environment, VT_COLOR )->name; } | 
    COLOUR { $$ = random_value( _environment, VT_COLOR )->name; } | 
    DWORD { $$ = random_value( _environment, VT_DWORD )->name; } | 
    float_or_single { $$ = random_value( _environment, VT_FLOAT )->name; } | 
    HEIGHT { $$ = rnd( _environment, screen_get_height( _environment )->name )->name; } |
    INT { $$ = random_value( _environment, VT_SWORD )->name; } | 
    INTEGER { $$ = random_value( _environment, VT_SWORD )->name; } | 
    LONG { $$ = random_value( _environment, VT_SDWORD )->name; } | 
    NUMBER { $$ = random_value( _environment, VT_NUMBER )->name; } | 
    POSITION { $$ = random_value( _environment, VT_POSITION )->name; } | 
    WIDTH { $$ = rnd( _environment, screen_get_width( _environment )->name )->name; } | 
    WORD { $$ = random_value( _environment, VT_WORD )->name; };

random_definition:
    random_definition_simple { $$ = $1; };

/*-----------------------------------------------------------------------------
 ------------ FRAMING
 ----------------------------------------------------------------------------*/

frame_offset: 
    {
        ((struct _Environment *)_environment)->frameOffsetX = 0;
        ((struct _Environment *)_environment)->frameOffsetY = 0;
    } |
    OFFSET OP const_expr OP_COMMA const_expr CP {
        ((struct _Environment *)_environment)->frameOffsetX = $3;
        ((struct _Environment *)_environment)->frameOffsetY = $5;
    };

frame_origin: 
    {
        ((struct _Environment *)_environment)->frameOriginX = 0;
        ((struct _Environment *)_environment)->frameOriginY = 0;
    } |
    ORIGIN OP const_expr OP_COMMA const_expr CP {
        ((struct _Environment *)_environment)->frameOriginX = $3;
        ((struct _Environment *)_environment)->frameOriginY = $5;
    }
    ;

frame_size_explicit:
    FRAME SIZE OP const_expr OP_COMMA const_expr CP frame_offset frame_origin {
        ((struct _Environment *)_environment)->frameWidth = $4;
        ((struct _Environment *)_environment)->frameHeight = $6;
    };

frame_size_auto: 
    FRAME SIZE AUTO {
        ((struct _Environment *)_environment)->frameWidth = -1;
        ((struct _Environment *)_environment)->frameHeight = -1;
    };

frame_size_definition:
    frame_size_auto | 
    frame_size_explicit;

frame_size: 
    {
        ((struct _Environment *)_environment)->frameOffsetX = 0;
        ((struct _Environment *)_environment)->frameOffsetY = 0;
        ((struct _Environment *)_environment)->frameOriginX = 0;
        ((struct _Environment *)_environment)->frameOriginY = 0;
    } frame_size_definition;

frame_definition:
    const_expr {
        ((struct _Environment *)_environment)->currentStrip->frames[((struct _Environment *)_environment)->currentStrip->count++] = $1;
    } | 
    const_expr {
        ((struct _Environment *)_environment)->currentStrip->frames[((struct _Environment *)_environment)->currentStrip->count++] = $1;
    } OP_COMMA frame_definition
    ;

/*-----------------------------------------------------------------------------
 ------------ STRIPS
 ----------------------------------------------------------------------------*/

strip_definition_id_optional: 
    {
        $$ = -1;
    } | 
    ID const_expr {
        $$ = $2;
    };

strip_definition:
    STRIP strip_definition_id_optional {
        Strip * s = malloc( sizeof( Strip ) );
        memset(s, 0, sizeof( Strip ) );
        s->next = ((struct _Environment *)_environment)->currentStrip;
        if ( $2 == -1 ) {
            s->id = ((struct _Environment *)_environment)->currentStripMaxId++;
        } else {
            s->id = $2;
            if ( $2 > ((struct _Environment *)_environment)->currentStripMaxId ) {
                ((struct _Environment *)_environment)->currentStripMaxId = $2+1;
            }
        }
        ((struct _Environment *)_environment)->currentStrip = s;
    } OP frame_definition CP;

strips_definition:
    strip_definition | 
    strip_definition OP_COMMA strips_definition;

strips_definition_optional:
    | 
    OSP strips_definition CSP {

        Strip * final = NULL;
        
        Strip * actual = ((struct _Environment *)_environment)->currentStrip;

        while(actual) {
            Strip * element = malloc( sizeof( Strip ) );
            memcpy( element, actual, sizeof( Strip ) );
            element->next = final;
            final = element;
            actual = actual->next;
        }

        ((struct _Environment *)_environment)->currentStrip = final;

    };

/*-----------------------------------------------------------------------------
 ------------ DOJO SUPPORT
 ----------------------------------------------------------------------------*/

dojo_functions: 
    CREATE PORT OP CP { $$ = dojo_create_port( _environment )->name; } | 
    ERROR { $$ = dojo_error( _environment )->name; } | 
    GET MESSAGE OP expr CP { $$ = dojo_get_message( _environment, $4, NULL )->name; } | 
    GET MESSAGE OP expr OP_COMMA expr CP { $$ = dojo_get_message( _environment, $4, $6 )->name; } |
    GET OP expr CP { $$ = dojo_get_message( _environment, $3, NULL )->name; } |
    GET OP expr OP_COMMA expr CP { $$ = dojo_get_message( _environment, $3, $5 )->name; } |
    OPEN PORT OP expr CP { $$ = dojo_open_port( _environment, $4 )->name; } | 
    PEEK MESSAGE OP expr CP { $$ = dojo_peek_message( _environment, $4, NULL )->name; } |
    PEEK MESSAGE OP expr OP_COMMA expr CP { $$ = dojo_peek_message( _environment, $4, $6 )->name; } |
    PEEK OP expr OP_COMMA expr CP { $$ = dojo_peek_message( _environment, $3, $5 )->name; } |
    PING { $$ = dojo_ping( _environment, NULL, NULL )->name; } | 
    PING OP expr CP { $$ = dojo_ping( _environment, $3, NULL )->name; } | 
    PING OP expr OP_COMMA expr CP { $$ = dojo_ping( _environment, $3, $5 )->name; } |
    PORT OP expr CP { $$ = dojo_open_port( _environment, $3 )->name; } | 
    PUT MESSAGE OP expr OP_COMMA expr CP { $$ = dojo_put_message( _environment, $4, NULL, $6 )->name; } |
    PUT MESSAGE OP expr OP_COMMA expr OP_COMMA expr CP { $$ = dojo_put_message( _environment, $4, $6, $8 )->name; } | 
    PUT OP expr OP_COMMA expr CP { $$ = dojo_put_message( _environment, $3, NULL, $5 )->name; } | 
    PUT OP expr OP_COMMA expr OP_COMMA expr CP { $$ = dojo_put_message( _environment, $3, $5, $7 )->name; };

/*-----------------------------------------------------------------------------
 ------------ FUJINET SUPPORT
 ----------------------------------------------------------------------------*/

fujinet_functions: 
    BYTES { $$ = fujinet_get_bytes_waiting( _environment )->name; } | 
    CONNECTED { $$ = fujinet_is_connected( _environment )->name; } | 
    ERROR { $$ = fujinet_get_error( _environment )->name; } | 
    HTTP POST BIN OP expr as_datatype_mandatory CP  { $$ = fujinet_http_post_bin_type( _environment, $5, $6 )->name; } | 
    HTTP POST BIN OP expr CP { $$ = fujinet_http_post_bin( _environment, $5 )->name; } | 
    OPEN OP expr OP_COMMA expr OP_COMMA expr CP { $$ = fujinet_open( _environment, $3, $5, $7 )->name; } | 
    PARSE JSON { $$ = fujinet_parse_json( _environment )->name; } | 
    READ OP CP as_datatype_mandatory { $$ = fujinet_read_type( _environment, $4 )->name; } | 
    READ OP expr CP { $$ = fujinet_read( _environment, $3 )->name; } | 
    READ OP expr as_datatype_mandatory CP  {
        Variable * value = fujinet_read( _environment, $3 );
        if ( $4 == VT_DSTRING || $4 == VT_STRING ) {
            Variable * s = variable_temporary( _environment, VT_BYTE, "(size)" );
            cpu_dsdescriptor( _environment, value->realName, NULL, s->realName );
            cpu_dec( _environment, s->realName );
            cpu_dsresize( _environment, value->realName, s->realName );
            $$ = value->name;
        } else {
            Variable * revalue = variable_temporary( _environment, $4, "(revalue)" );
            variable_string_val( _environment, revalue->name );
            $$ = revalue->name;
        }
    } | 
    READY { $$ = fujinet_is_ready( _environment )->name; } | 
    SET CHANNEL MODE OP expr CP { $$ = fujinet_set_channel_mode_var( _environment, $5 )->name; } | 
    WRITE OP expr as_datatype_mandatory CP { $$ = fujinet_write_type( _environment, $3, $4 )->name; } |
    WRITE OP expr CP { $$ = fujinet_write( _environment, $3 )->name; };

/*-----------------------------------------------------------------------------
 ------------ OVERALL FUNCTIONS
 ----------------------------------------------------------------------------*/

exponential_less:
    Identifier as_datatype_suffix_optional {
        parser_array_init( _environment );
      }
      OP indexes CP field_optional {
        if ( $7 ) {
            Variable * array;
            array = variable_retrieve( _environment, $1 );
            if ( array->type != VT_TARRAY ) {
                CRITICAL_NOT_ARRAY( $1 );
            }
            if ( array->arrayDimensions == 1 && ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex][0] ) {
                $$ = variable_move_from_array1_type( _environment, $1, ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayNestedIndex][0], $7 )->name;
            } else {
                $$ = variable_move_from_array_type( _environment, $1, $7 )->name;
            }
        } else {
            define_implicit_array_if_needed( _environment, $1 );
            VariableType vt = $2;
            if ( vt == 0 ) {
                vt = ((struct _Environment *)_environment)->defaultVariableType;
            }
            Variable * array;
            if ( ! variable_exists( _environment, $1 ) ) {
                if ( ((struct _Environment *)_environment)->optionExplicit ) {
                    CRITICAL_VARIABLE_UNDEFINED( $1 );
                } else {
                    array = variable_define( _environment, $1, VT_TARRAY, 0 );
                    array->arrayType = vt;
                    array->arrayPrecision = ((struct _Environment *)_environment)->floatType.precision;
                }
            }        
            array = variable_retrieve( _environment, $1 );
            if ( array->type != VT_TARRAY ) {
                CRITICAL_NOT_ARRAY( $1 );
            }
            $$ = variable_move_from_array( _environment, $1 )->name;
        }
        parser_array_cleanup( _environment );
    } | 
    Identifier {
        Constant * c = constant_find( _environment, $1 );
        if ( c ) {
            if ( c->type == CT_STRING ) {
                $$ = variable_temporary( _environment,  VT_STRING, "(constant)" )->name;
                variable_store_string( _environment, $$, c->valueString->value );
            } else {
                if ( c->type == CT_FLOAT ) {
                    $$ = variable_temporary( _environment, VT_FLOAT, "(constant)" )->name;
                    variable_store_float( _environment, $$, c->valueFloating );
                } else {
                    Variable * number = variable_temporary( _environment, variable_type_from_numeric_value( _environment, c->value ), "(constant)" );
                    $$ = number->name;
                    variable_store( _environment, $$, c->value );
                    number->initializedByConstant = 1;
                }
            }
        } else {
            if ( !variable_exists( _environment, $1 ) ) {
                char * label = $1;
                if (strcmp($1, "q" ) == 0 && ((Environment *)_environment)->vestigialConfig.rchack_ostra_1172) {
                    label = malloc(MAX_TEMPORARY_STORAGE);
                    sprintf(label, "lbl%s", $1 );
                }
                if ( label_exists_named( _environment, label ) ) {
                    $$ = label;
                } else {
                    if ( ((struct _Environment *)_environment)->optionExplicit ) {
                        CRITICAL_VARIABLE_UNDEFINED( $1 );
                    } else {
                        $$ = variable_retrieve_or_define( _environment, $1, ((struct _Environment *)_environment)->defaultVariableType, 0 )->name;
                    }
                }
            } else {
                $$ = variable_retrieve( _environment, $1 )->name;
            }
        }
    } | 
    Identifier as_datatype_suffix {
        Constant * c = constant_find( _environment, $1 );
        if ( c ) {
            if ( c->type == CT_STRING ) {
                CRITICAL_TYPE_MISMATCH_CONSTANT_NUMERIC( $1 );
            } else {
                if ( c->type == CT_FLOAT ) {
                    if ( $2 == VT_FLOAT ) {
                        $$ = variable_temporary( _environment, $2, "(constant)" )->name;
                        variable_store_float( _environment, $$, c->valueFloating );
                    } else {
                        $$ = variable_temporary( _environment, $2, "(constant)" )->name;
                        variable_store( _environment, $$, (int)c->valueFloating );
                    }
                } else {
                    Variable * number = variable_temporary( _environment, $2, "(constant)" );
                    $$ = number->name;
                    variable_store( _environment, $$, c->value );
                    number->initializedByConstant = 1;
                }
            }
        } else {
            if ( !variable_exists( _environment, $1 ) ) {
                if ( ((struct _Environment *)_environment)->optionExplicit ) {
                    CRITICAL_VARIABLE_UNDEFINED( $1 );
                } else {
                    $$ = variable_retrieve_or_define( _environment, $1, $2, 0 )->name;
                }
            } else {
                $$ = variable_retrieve( _environment, $1 )->name;
            }
        }
    } | 
    Integer { 
        $$ = parser_adapted_numeric( _environment, $1 )->name;
      } | 
    Float { 
        $$ = variable_temporary( _environment, VT_FLOAT, "(float))" )->name;
        variable_store_float( _environment, $$, $1 );
    } | 
    String { 
        $$ = variable_temporary( _environment, VT_STRING, "(string value)" )->name;
        variable_store_string( _environment, $$, $1 );
      } | 
    RawString { 
        Variable * variable = variable_temporary( _environment, VT_STRING, "(string value)" );
        variable_store_string( _environment, variable->name, $1 );
        variable->printable = 1;
        $$ = variable->name;
      } | 
    OP BYTE CP direct_integer { $$ = parser_casted_numeric( _environment, VT_BYTE, $4 )->name; } | 
    OP BYTE CP OP expr CP { $$ = variable_cast( _environment, $5, VT_BYTE )->name; } |
    OP SIGNED BYTE CP direct_integer { $$ = parser_casted_numeric( _environment, VT_SBYTE, $5 )->name; } |
    OP SBYTE CP direct_integer { $$ = parser_casted_numeric( _environment, VT_SBYTE, $4 )->name; } | 
    OP SIGNED BYTE CP OP expr CP { $$ = variable_cast( _environment, $6, VT_SBYTE )->name; } |
    OP SBYTE CP OP expr CP { $$ = variable_cast( _environment, $5, VT_SBYTE )->name; } |
    OP WORD CP direct_integer { $$ = parser_casted_numeric( _environment, VT_WORD, $4 )->name; } |
    OP WORD CP OP expr CP { $$ = variable_cast( _environment, $5, VT_WORD )->name; } |
    OP SIGNED WORD CP direct_integer { $$ = parser_casted_numeric( _environment, VT_SWORD, $5 )->name; } |
    OP SIGNED WORD CP OP expr CP { $$ = variable_cast( _environment, $6, VT_SWORD )->name; } |
    OP float_or_single CP OP expr CP { $$ = variable_cast( _environment, $5, VT_FLOAT )->name; } |
    OP NUMBER CP direct_integer { $$ = parser_casted_numeric( _environment, VT_NUMBER, $4 )->name; } |
    OP DWORD CP direct_integer { $$ = parser_casted_numeric( _environment, VT_DWORD, $4 )->name; } |
    OP DWORD CP OP expr CP { $$ = variable_cast( _environment, $5, VT_DWORD )->name; } | 
    OP SIGNED DWORD CP direct_integer { $$ = parser_casted_numeric( _environment, VT_SDWORD, $5 )->name; } |
    OP SIGNED DWORD CP OP expr CP { $$ = variable_cast( _environment, $6, VT_SDWORD )->name; } |
    OP COLOR CP direct_integer { $$ = parser_casted_numeric( _environment, VT_COLOR, $4 )->name; } |
    OP COLOR CP OP expr CP { $$ = variable_cast( _environment, $5, VT_COLOR )->name; } |
    OP COLOUR CP direct_integer { $$ = parser_casted_numeric( _environment, VT_COLOR, $4 )->name; } |
    OP COLOUR CP OP expr CP { $$ = variable_cast( _environment, $5, VT_COLOR )->name; } |
    OP STRING CP Identifier { $$ = variable_cast( _environment, $4, VT_DSTRING )->name; } |
    OSP BufferDefinitionHex {  $$ = parse_buffer_definition( _environment, $2, VT_BUFFER, 1 )->name; } |
    OP IMAGE CP buffer_definition_prefix BufferDefinitionHex { 
        int size;
        char * buffer = parse_buffer( _environment, $5, &size, 1 );
        $$ = image_load_from_buffer( _environment, buffer, size )->name;
      }  |
    OP IMAGE CP RawString { 
        int size;
        char * buffer = parse_buffer( _environment, $4, &size, 0 );
        $$ = image_load_from_buffer( _environment, buffer, size )->name;
      } | 
    OP IMAGE CP Identifier { 
        Constant * c = constant_find( _environment, $4 );
        if ( c == NULL ) {
            CRITICAL_UNDEFINED_CONSTANT( $4 );
        }
        if ( c->type != CT_STRING ) {
            CRITICAL_TYPE_MISMATCH_CONSTANT_STRING( $4 );
        }
        $$ = image_load_from_buffer( _environment, c->valueString->value, c->valueString->size )->name;
      } | 
    OP images_or_atlas CP buffer_definition_prefix BufferDefinitionHex buffer_definition_suffix { 
        int size;
        char * buffer = parse_buffer( _environment, $5, &size, 1 );
        $$ = images_load_from_buffer( _environment, buffer, size )->name;
      } | 
    OP images_or_atlas CP RawString { 
        int size;
        char * buffer = parse_buffer( _environment, $4, &size, 0 );
        $$ = images_load_from_buffer( _environment, buffer, size )->name;
      } | 
    OP images_or_atlas CP Identifier { 
        Constant * c = constant_find( _environment, $4 );
        if ( c == NULL ) {
            CRITICAL_UNDEFINED_CONSTANT( $4 );
        }
        if ( c->type != CT_STRING ) {
            CRITICAL_TYPE_MISMATCH_CONSTANT_STRING( $4 );
        }
        $$ = images_load_from_buffer( _environment, c->valueString->value, c->valueString->size )->name;
      } | 
    BETA {
        $$ = variable_by_constant( _environment, VT_BYTE, BETAVALUE )->name;
    } | 
    PI {
        Variable * pi = variable_temporary( _environment, VT_FLOAT, "(float)" );
        #if defined(__c128z__) || defined(__vg5000__) || defined(__zx__) || \
            defined(__coleco__) || defined(__cpc__) || defined(__sc3000__) || \
            defined(__sc3000__) || defined(__sg1000__) ||  defined(__msx1__) ||  defined(__gb__) || \
            defined(__vz200__)
                variable_store_float( _environment, pi->name, M_PI );
        #else
                cpu_move_32bit( _environment, "PI", pi->realName );
        #endif
        $$ = pi->name;
      } | 
    PI OP CP {
        Variable * pi = variable_temporary( _environment, VT_FLOAT, "(float)" );
        #if defined(__c128z__) || defined(__vg5000__) || defined(__zx__) || \
            defined(__coleco__) || defined(__cpc__) || defined(__sc3000__) || \
            defined(__sc3000__) || defined(__sg1000__) ||  defined(__msx1__) ||  defined(__gb__) || \
            defined(__vz200__)
                variable_store_float( _environment, pi->name, M_PI );
        #else
                cpu_move_32bit( _environment, "PI", pi->realName );
        #endif
        $$ = pi->name;
      } | 
    SQR OP expr CP { $$ = sqroot( _environment, $3 )->name; } | 
    LOG OP expr CP { $$ = fp_log( _environment, $3 )->name; } | 
    EXP OP expr CP { $$ = fp_exp( _environment, $3 )->name; } | 
    SIN OP expr CP { $$ = fp_sin( _environment, $3 )->name; } | 
    COS OP expr CP { $$ = fp_cos( _environment, $3 )->name; } | 
    TAN OP expr CP { $$ = fp_tan( _environment, $3 )->name; } | 
    COMBINE NIBBLE OP expr OP_COMMA expr CP { $$ = combine_nibble_vars( _environment, $4, $6 )->name; } | 
    NEW TILESET {
        Variable * index = variable_temporary( _environment, VT_TILESET, "(tileset)");
        cpu_store_8bit( _environment, index->realName, ((struct _Environment *)_environment )->tilesetCount );
        ((struct _Environment *)_environment )->tilesets[((struct _Environment *)_environment )->tilesetCount] = malloc( sizeof( TileDescriptors ) );
        TileDescriptors * descriptors = ((struct _Environment *)_environment )->tilesets[((struct _Environment *)_environment )->tilesetCount];
        memset( descriptors, 0, sizeof( TileDescriptors ) );
        descriptors->count = 0;
        descriptors->first = 1;
        descriptors->firstFree = descriptors->first;
        descriptors->lastFree = 128;
        index->value = ++((struct _Environment *)_environment )->tilesetCount;
        $$ = index->name;
      } | 
    NEW OP const_expr OP_COMMA const_expr CP { $$ = new_image( _environment, $3, $5, ((struct _Environment *)_environment)->currentMode )->name; } | 
    NEW IMAGE OP const_expr OP_COMMA const_expr CP { $$ = new_image( _environment, $4, $6, ((struct _Environment *)_environment)->currentMode )->name; } | 
    NEW images_or_atlas OP const_expr OP_COMMA const_expr OP_COMMA const_expr CP { $$ = new_images( _environment, $4, $6, $8, ((struct _Environment *)_environment)->currentMode )->name;} | 
    NEW SEQUENCE OP const_expr OP_COMMA const_expr OP_COMMA const_expr OP_COMMA const_expr CP { $$ = new_sequence( _environment, $4, $6, $8, $10, ((struct _Environment *)_environment)->currentMode )->name; } | 
    NEW MUSIC OP const_expr CP { $$ = new_music( _environment, $4 )->name; } | 
    LOAD OP String CP on_bank_explicit load_flags { $$ = load( _environment, $3, NULL, 0, abs($5), $6 )->name; } | 
    LOAD OP String AS String CP on_bank_explicit load_flags { $$ = load( _environment, $3, $5, 0, abs($7), $8 )->name; } | 
    LOAD OP String OP_COMMA Integer CP on_bank_explicit load_flags { $$ = load( _environment, $3, NULL, $5, abs($7), $8 )->name; } | 
    LOAD OP String AS String OP_COMMA Integer CP on_bank_explicit load_flags { $$ = load( _environment, $3, $5, $7, abs($9), $10 )->name; } | 
    LOAD MUSIC OP String CP on_bank_explicit { $$ = music_load( _environment, $4, NULL, abs($6) )->name; } | 
    LOAD MUSIC OP String AS String CP on_bank_explicit { $$ = music_load( _environment, $4, $6, abs($8) )->name; } | 
    LOAD SAMPLES OP String CP on_bank_explicit { $$ = samples_load( _environment, $4, NULL, abs($6) )->name; } | 
    LOAD SAMPLES OP String AS String CP on_bank_explicit { $$ = samples_load( _environment, $4, $6, abs($8) )->name; } | 
    load_sequence OP String AS String CP frame SIZE OP const_expr OP_COMMA const_expr CP sequence_load_flags  using_transparency using_opacity using_background on_bank_implicit readonly_optional {

        ParamsSequenceLoad params;

        params.filename = $3;
        params.alias = $5;
        params.mode = ((struct _Environment *)_environment)->currentMode;
        params.frame_width = $10;
        params.frame_height = $12;
        params.flags = $14;
        params.transparent_color = $15+$16;
        params.background_color = $17;
        params.bank_expansion = $18;
        params.origin_x = ((struct _Environment *)_environment)->frameOriginX;
        params.origin_y = ((struct _Environment *)_environment)->frameOriginY;
        params.offset_x = ((struct _Environment *)_environment)->frameOffsetX;
        params.offset_y = ((struct _Environment *)_environment)->frameOffsetY;
        params.compiled = $1;

        Variable * sequence = sequence_load(  _environment, params );
        if ( $19 != -1 ) {
            sequence->readonly = ($19 || $1) ? 0 : 1;
        }
        $$ = sequence->name;
      } | 
    load_sequence OP String CP frame SIZE OP const_expr OP_COMMA const_expr CP sequence_load_flags  using_transparency using_opacity using_background on_bank_implicit readonly_optional {        

        ParamsSequenceLoad params;

        params.filename = $3;
        params.alias = NULL;
        params.mode = ((struct _Environment *)_environment)->currentMode;
        params.frame_width = $8;
        params.frame_height = $10;
        params.flags = $12;
        params.transparent_color = $13+$14;
        params.background_color = $15;
        params.bank_expansion = $16;
        params.origin_x = ((struct _Environment *)_environment)->frameOriginX;
        params.origin_y = ((struct _Environment *)_environment)->frameOriginY;
        params.offset_x = ((struct _Environment *)_environment)->frameOffsetX;
        params.offset_y = ((struct _Environment *)_environment)->frameOffsetY;
        params.compiled = $1;

        Variable * sequence = sequence_load(  _environment, params );
        if ( $17 != -1 ) {
            sequence->readonly = ($17 || $1) ? 0 : 1;
        }
        $$ = sequence->name;
      } | 
    load_images OP String CP frame_size images_load_flags  using_transparency using_opacity using_background on_bank_implicit readonly_optional strips_definition_optional {

        ParamsImagesLoad params;

        params.filename = $3;
        params.alias = NULL;
        params.mode = ((struct _Environment *)_environment)->currentMode;
        params.frame_width = ((struct _Environment *)_environment)->frameWidth;
        params.frame_height = ((struct _Environment *)_environment)->frameHeight;
        params.flags = $6;
        params.transparent_color = $7+$8;
        params.background_color = $9;
        params.bank_expansion = $10;
        params.origin_x = ((struct _Environment *)_environment)->frameOriginX;
        params.origin_y = ((struct _Environment *)_environment)->frameOriginY;
        params.offset_x = ((struct _Environment *)_environment)->frameOffsetX;
        params.offset_y = ((struct _Environment *)_environment)->frameOffsetY;
        params.compiled = $1;
            
        Variable * images = images_load( _environment, params );
        if ( $11 != -1 ) {
            images->readonly = ($11 || $1) ? 0 : 1;
        }
        images->strips = ((struct _Environment *)_environment)->currentStrip;
        $$ = images->name;
      } | 
    load_images OP String AS String CP frame_size images_load_flags  using_transparency using_opacity using_background on_bank_implicit readonly_optional {

        ParamsImagesLoad params;

        params.filename = $3;
        params.alias = $5;
        params.mode = ((struct _Environment *)_environment)->currentMode;
        params.frame_width = ((struct _Environment *)_environment)->frameWidth;
        params.frame_height = ((struct _Environment *)_environment)->frameHeight;
        params.flags = $8;
        params.transparent_color = $9+$10;
        params.background_color = $11;
        params.bank_expansion = $12;
        params.origin_x = ((struct _Environment *)_environment)->frameOriginX;
        params.origin_y = ((struct _Environment *)_environment)->frameOriginY;
        params.offset_x = ((struct _Environment *)_environment)->frameOffsetX;
        params.offset_y = ((struct _Environment *)_environment)->frameOffsetY;
        params.compiled = $1;

        Variable * images = images_load( _environment, params );
        if ( $11 != -1 ) {
            images->readonly = ($11 || $1) ? 0 : 1;
        }
        $$ = images->name;
      } | 
    load_tileset OP String CP images_load_flags using_transparency using_opacity using_background on_bank_implicit {
        $$ = tileset_load( _environment, $3, NULL, ((struct _Environment *)_environment)->currentMode, $5, $6+$7, $8, $9 )->name;
      } | 
    load_tileset OP String AS String CP images_load_flags  using_transparency using_opacity using_background on_bank_implicit {
        $$ = tileset_load( _environment, $3, $5, ((struct _Environment *)_environment)->currentMode, $7, $8+$9, $10, $11 )->name;
      } | 
    load_tilemap OP String CP images_load_flags using_transparency using_opacity using_background on_bank_implicit {
        $$ = tilemap_load( _environment, $3, NULL, ((struct _Environment *)_environment)->currentMode, $5, $6+$7, $8, $9 )->name;
      } | 
    load_image OP String CP image_load_flags  using_transparency using_opacity using_background on_bank_implicit readonly_optional {
        
        ParamsImageLoad params;
        
        params.filename = $3;
        params.alias = NULL;
        params.mode = ((struct _Environment *)_environment)->currentMode;
        params.flags = $5;
        params.transparent_color = $6+$7;
        params.background_color = $8;
        params.bank_expansion = $9;
        params.compiled = $1;

        Variable * image = image_load( _environment, params );
        if ( $10 != -1 ) {
            image->readonly = ($10 || $1) ? 0 : 1;
        }
        $$ = image->name;
      } | 
    load_image OP String AS String CP image_load_flags  using_transparency using_opacity using_background on_bank_implicit readonly_optional {

        ParamsImageLoad params;
        
        params.filename = $3;
        params.alias = $5;
        params.mode = ((struct _Environment *)_environment)->currentMode;
        params.flags = $7;
        params.transparent_color = $8+$9;
        params.background_color = $10;
        params.bank_expansion = $11;
        params.compiled = $1;

        Variable * image = image_load( _environment, params );
        if ( $12 != -1 ) {
            image->readonly = ($12 || $1) ? 0 : 1;
        }
        $$ = image->name;
      } | 
    load_image OP String OP_COMMA Integer CP image_load_flags  using_transparency using_opacity using_background on_bank_implicit readonly_optional {

        ParamsImageLoad params;
        
        params.filename = $3;
        params.alias = NULL;
        params.mode = $5;
        params.flags = $7;
        params.transparent_color = $8+$9;
        params.background_color = $10;
        params.bank_expansion = $11;
        params.compiled = $1;

        Variable * image = image_load( _environment, params );
        if ( $12 != -1 ) {
            image->readonly = $12;
        }
        $$ = image->name;
      } | 
    load_image OP String AS String OP_COMMA Integer CP image_load_flags  using_transparency using_opacity using_background on_bank_implicit readonly_optional {

        ParamsImageLoad params;

        params.filename = $3;
        params.alias = $5;
        params.mode = $7;
        params.flags = $9;
        params.transparent_color = $10+$11;
        params.background_color = $12;
        params.bank_expansion = $13;
        params.compiled = $1;

        Variable * image = image_load( _environment, params );
        if ( $14 != -1 ) {
            image->readonly = $14;
        }
        $$ = image->name;
      } | 
    load_movie { ((Environment *)_environment)->movieFilenamesCount = 0; } OP load_movie_params CP on_bank_implicit {

        ParamsMovieLoad params;

        int j=0;
        for( int i=((Environment *)_environment)->movieFilenamesCount-1; i>0; --i ) {
            params.filenames[j] = strdup(((Environment *)_environment)->movieFilenames[i]);
        }
        params.filenamesCount;

        params.mode = ((struct _Environment *)_environment)->currentMode;
        params.bank_expansion = $6;

        Variable * movie = movie_load( _environment, params );
        $$ = movie->name;
      } | 
    LOAD TILE OP String CP tile_load_flags {
        $$ = tile_load( _environment, $4, $6, NULL, -1 )->name;
      } | 
    LOAD TILE OP String OP_COMMA expr CP tile_load_flags {
        $$ = tile_load( _environment, $4, $8, $6, -1 )->name;
      } | 
    LOAD TILES OP String CP tile_load_flags {
        $$ = tiles_load( _environment, $4, $6, NULL, -1 )->name;
      } | 
    LOAD TILES OP String OP_COMMA expr CP tile_load_flags {
        $$ = tiles_load( _environment, $4, $8, $6, -1 )->name;
      } | 
    SIZE OP expr CP {
        Variable * v = variable_retrieve( _environment, $3 );
        switch( v->type ) {
            case VT_IMAGE:
            case VT_IMAGES:
            case VT_SEQUENCE:
            case VT_MOVIE:
            case VT_BUFFER:
            case VT_TYPE:
            case VT_STRING: 
                break;
            default:
                CRITICAL_SIZE_UNSUPPORTED( $3, DATATYPE_AS_STRING[v->type] );
                break;
        }
        $$ = variable_temporary( _environment, ((struct _Environment *)_environment)->defaultVariableType, "(size)" )->name;
        variable_store( _environment, $$, v->size );
      } | 
    color_enumeration {  $$ = $1; } | 
    RGB OP const_expr OP_COMMA const_expr OP_COMMA const_expr CP {
        Variable * rgb = variable_temporary( _environment, VT_COLOR, "(color)" );
        if ( ((Environment *)_environment)->currentRgbConverterFunction ) {
            variable_store( _environment, rgb->name, ((Environment *)_environment)->currentRgbConverterFunction( $3, $5, $7 ) );
        } else {
            variable_store( _environment, rgb->name, 0 );
        }
        rgb->initializedByConstant = 1;
        $$ = rgb->name;
    } | 
    DISTANCE OP optional_x OP_COMMA optional_y TO optional_x OP_COMMA optional_y CP { $$ = distance( _environment, $3, $5, $7, $9 )->name; } | 
    READ END { $$ = read_end( _environment )->name; } | 
    TRAVEL travel_function { $$ = $2; } | 
    DOJO dojo_functions { $$ = $2; } | 
    dojo_functions { $$ = $1; } | 
    FUJINET fujinet_functions { $$ = $2; } | 
    MEMPEEK OP expr CP { $$ = peek_var( _environment, $3 )->name; } | 
    PEEK OP expr CP {
        Variable * id = variable_retrieve( _environment, $3 );
        if ( id->type == VT_DOJOKA ) {
            $$ = dojo_peek_message( _environment, $3, NULL )->name;
        } else {
            $$ = peek_var( _environment, $3 )->name;
        }
      } | 
    PEEKW OP expr CP { $$ = peekw_var( _environment, $3 )->name; } | 
    PEEKD OP expr CP { $$ = peekd_var( _environment, $3 )->name; } | 
    SCREEN OP expr OP_COMMA expr CP { $$ = screen_var( _environment, $3, $5, 0 )->name; } |
    SCREEN OP_DOLLAR OP expr OP_COMMA expr CP { $$ = screen_var( _environment, $4, $6, 1 )->name; } |
    XPEN { $$ = xpen( _environment )->name; } | 
    YPEN { $$ = ypen( _environment )->name; } | 
    SPEN { $$ = spen( _environment )->name; } | 
    XGR { $$ = "XGR"; } | 
    YGR { $$ = "YGR"; } | 
    INT OP expr CP { $$ = variable_int( _environment, $3 )->name; } | 
    IN OP expr CP { $$ = in_var( _environment, $3 )->name; } | 
    COLLISION OP direct_integer CP { $$ = collision_to( _environment, $3 )->name; } | 
    COLLISION OP expr CP { $$ = collision_to_vars( _environment, $3 )->name; } | 
    HIT OP direct_integer CP { $$ = collision_to( _environment, $3 )->name; } | 
    HIT OP expr CP { $$ = collision_to_vars( _environment, $3 )->name; } | 
    TILESET OP expr CP { $$ = tileset_of_vars( _environment, $3 )->name; } | 
    TILEMAP INDEX OP expr OP_COMMA expr OP_COMMA expr CP { $$ = tilemap_index_vars( _environment, $4, $6, $8, NULL )->name; } |
    TILEMAP INDEX OP expr OP_COMMA expr OP_COMMA expr OP_COMMA expr CP { $$ = tilemap_index_vars( _environment, $4, $6, $8, $10 )->name; } |
    HEX2BIN OP expr TO expr CP { $$ = variable_hex2bin( _environment, $3, $5 )->name; } |
    ENCRYPT OP expr OP_COMMA expr CP { $$ = encrypt( _environment, $3, $5 )->name; } |
    DECRYPT OP expr OP_COMMA expr TO Identifier CP { $$ = decrypt( _environment, $3, $5, $7 )->name; } |
    LEFT OP expr OP_COMMA expr CP { $$ = variable_string_left( _environment, $3, $5 )->name; } | 
    RIGHT OP expr OP_COMMA expr CP { $$ = variable_string_right( _environment, $3, $5 )->name; } |
    BANK COUNT { $$ = bank_get_count( _environment )->name; } | 
    STRPTR OP expr CP { $$ = strptr( _environment, $3 )->name; } | 
    VARPTR OP Identifier CP { $$ = varptr( _environment, $3 )->name; } | 
    IMAGEREF OP Identifier CP { $$ = image_ref( _environment, $3 )->name; } | 
    CREATE PATH OP optional_x OP_COMMA optional_y TO expr OP_COMMA expr CP { $$ = create_path( _environment, $4, $6, $8, $10  )->name; } | 
    CREATE PATH OP optional_x OP_COMMA optional_y OP_COMMA expr OP_COMMA expr CP { $$ = create_path( _environment, $4, $6, $8, $10  )->name; } |
    CREATE VECTOR OP expr OP_COMMA expr CP { $$ = create_vector( _environment, $4, $6 )->name; } | 
    VARBANK OP Identifier CP {
        Variable * variable = variable_retrieve( _environment, $3 );
        Variable * bank = variable_temporary( _environment, VT_BYTE, "(bank)");
        variable_store( _environment, bank->name, variable->bankAssigned );
        $$ = bank->name;
    } | 
    VARBANKPTR OP Identifier CP {
        Variable * variable = variable_retrieve( _environment, $3 );
        Variable * ptr = variable_temporary( _environment, VT_ADDRESS, "(ptr)");
        variable_store( _environment, ptr->name, variable->absoluteAddress );
        $$ = ptr->name;
    } | 
    BANK OP CP { $$ = bank_get( _environment )->name; } | 
    BANK ADDRESS OP OP_HASH const_expr CP { $$ = bank_get_address( _environment, $5 )->name; } | 
    BANK ADDRESS OP expr CP { $$ = bank_get_address_var( _environment, $4 )->name; } |
    BANK SIZE OP OP_HASH const_expr CP { $$ = bank_get_size( _environment, $5 )->name; } |
    BANK SIZE OP expr CP { $$ = bank_get_size_var( _environment, $4 )->name; } |
    INST OP expr OP_COMMA expr OP_COMMA expr CP { $$ = variable_string_inst( _environment, $3, $5, $7 )->name; } |
    INSERT OP expr OP_COMMA expr OP_COMMA expr CP { $$ = variable_string_insert( _environment, $3, $5, $7 )->name; } |
    MID OP expr OP_COMMA expr CP { $$ = variable_string_mid( _environment, $3, $5, NULL )->name; } |
    MID OP expr OP_COMMA expr OP_COMMA expr CP { $$ = variable_string_mid( _environment, $3, $5, $7 )->name; } |
    SUBSTRING OP expr OP_COMMA expr CP { $$ = variable_string_substring( _environment, $3, $5, NULL )->name; } |
    SUBSTRING OP expr OP_COMMA expr OP_COMMA expr CP { $$ = variable_string_substring( _environment, $3, $5, $7 )->name; } |
    PLACE OP expr OP_COMMA expr CP { $$ = variable_string_instr( _environment, $3, $5, NULL )->name; } |
    PLACE OP expr OP_COMMA expr OP_COMMA expr CP { $$ = variable_string_instr( _environment, $3, $5, $7 )->name; } | 
    INSTR OP expr OP_COMMA expr CP { $$ = variable_string_instr( _environment, $3, $5, NULL )->name; } |
    INSTR OP expr OP_COMMA expr OP_COMMA expr CP { $$ = variable_string_instr( _environment, $3, $5, $7 )->name; } |
    UCASE OP expr CP { $$ = variable_string_upper( _environment, $3 )->name; } | 
    UPPER OP expr CP { $$ = variable_string_upper( _environment, $3 )->name; } | 
    LCASE OP expr CP { $$ = variable_string_lower( _environment, $3 )->name; } |
    LOWER OP expr CP { $$ = variable_string_lower( _environment, $3 )->name; } | 
    HEX OP expr CP { $$ = variable_hex( _environment, $3, 0 )->name; } | 
    SERIALIZE OP expr CP { $$ = serialize( _environment, $3, NULL )->name; } | 
    SERIALIZE OP expr OP_COMMA expr CP { $$ = serialize( _environment, $3, $5 )->name; } |
    DESERIALIZE OP expr TO Identifier CP { $$ = deserialize( _environment, $3, NULL, $5 )->name; } |
    DESERIALIZE OP expr OP_COMMA expr TO Identifier CP { $$ = deserialize( _environment, $3, $5, $7 )->name; } |
    OP_DOLLAR2 OP expr CP { $$ = variable_hex( _environment, $3, 0 )->name; } |
    STR OP expr CP { $$ = variable_string_str( _environment, $3 )->name; } |
    OP_PERC2 OP expr CP { $$ = variable_bin( _environment, $3, NULL, NULL, NULL )->name; } |
    BIN OP expr CP { $$ = variable_bin( _environment, $3, NULL, NULL, NULL )->name; } |
    BIN OP expr OP_COMMA expr CP { $$ = variable_bin( _environment, $3, $5, NULL, NULL )->name; } |
    BIN OP expr OP_COMMA expr OP_COMMA expr CP { $$ = variable_bin( _environment, $3, NULL, $5, $7 )->name; } |
    BIN OP expr OP_COMMA expr OP_COMMA expr OP_COMMA expr CP { $$ = variable_bin( _environment, $3, $5, $7, $9 )->name; } |
    SPACE OP expr CP { $$ = variable_string_space( _environment, $3 )->name; } |
    FLIP OP expr CP { $$ = variable_flip( _environment, $3 )->name; } |
    CHR OP expr CP { $$ = variable_string_chr( _environment, $3 )->name; } |
    PICK OP expr OP_COMMA const_expr CP { $$ = variable_string_pick( _environment, $3, $5 )->name; } |
    ASC OP expr CP { $$ = variable_string_asc( _environment, $3 )->name; } |
    UBOUND OP expr CP {
        Variable * array = variable_retrieve( _environment, $3 );
        if ( array->type != VT_TARRAY ) {
            CRITICAL_NOT_ARRAY( $3 );
        }
        Variable * value = variable_temporary( _environment, VT_WORD, "(ubound)" );
        variable_store( _environment, value->name, array->arrayDimensionsEach[array->arrayDimensions-1]-1 );
        $$ = value->name;
    } | 
    UBOUND OP expr OP_COMMA const_expr CP {
        Variable * array = variable_retrieve( _environment, $3 );
        if ( array->type != VT_TARRAY ) {
            CRITICAL_NOT_ARRAY( $3 );
        }
        if ( ( array->arrayDimensions == 1 ) && ( $5 > 1 ) ) {
          CRITICAL_ARRAY_MONODIMENSIONAL( $3 );
        }
        if ( ( array->arrayDimensions > 1 ) && ( $5 > array->arrayDimensions ) ) {
          CRITICAL_ARRAY_INVALID_DIMENSION( $3 );
        }
        Variable * value = variable_temporary( _environment, VT_WORD, "(ubound)" );
        variable_store( _environment, value->name, array->arrayDimensionsEach[array->arrayDimensions-$5-1]-1 );
        $$ = value->name;
    } | 
    LBOUND OP expr CP {
        Variable * array = variable_retrieve( _environment, $3 );
        if ( array->type != VT_TARRAY ) {
            CRITICAL_NOT_ARRAY( $3 );
        }
        Variable * value = variable_temporary( _environment, VT_WORD, "(lbound)" );
        variable_store( _environment, value->name, 0 );
        $$ = value->name;
    } | 
    LBOUND OP expr OP_COMMA const_expr CP {
        Variable * array = variable_retrieve( _environment, $3 );
        if ( array->type != VT_TARRAY ) {
            CRITICAL_NOT_ARRAY( $3 );
        }
        if ( ( array->arrayDimensions == 1 ) && ( $5 > 1 ) ) {
          CRITICAL_ARRAY_MONODIMENSIONAL( $3 );
        }
        if ( ( array->arrayDimensions > 1 ) && ( $5 > array->arrayDimensions ) ) {
          CRITICAL_ARRAY_INVALID_DIMENSION( $3 );
        }
        Variable * value = variable_temporary( _environment, VT_WORD, "(lbound)" );
        variable_store( _environment, value->name, 0 );
        $$ = value->name;
    } | 
    ARRAY COUNT OP expr OP_COMMA expr CP { $$ = variable_array_count_vars( _environment, $4, $6 )->name; } | 
    COUNT OP expr OP_COMMA expr CP { $$ = variable_array_count_vars( _environment, $3, $5 )->name; } | 
    ARRAY SUM OP expr CP { $$ = variable_array_sum_vars( _environment, $4 )->name; } | 
    SUM OP expr CP { $$ = variable_array_sum_vars( _environment, $3 )->name; } | 
    ARRAY MAX OP expr CP { $$ = variable_array_max_vars( _environment, $4 )->name; } | 
    MAX OP expr CP { $$ = variable_array_max_vars( _environment, $3 )->name; } | 
    ARRAY MIN OP expr CP { $$ = variable_array_min_vars( _environment, $4 )->name; } |
    MIN OP expr CP { $$ = variable_array_min_vars( _environment, $3 )->name; } |
    LEN OP expr CP { $$ = variable_string_len( _environment, $3 )->name; } |
    DUP OP expr OP_COMMA expr CP { $$ = variable_string_dup( _environment, $3, $5 )->name; } |
    STRING OP expr OP_COMMA expr CP { $$ = variable_string_string( _environment, $3, $5 )->name; } |
    VAL OP expr CP { $$ = variable_string_val( _environment, $3 )->name; } |
    RANDOM random_definition { $$ = $2; } | 
    RND OP expr CP {
        Variable * expr = variable_retrieve( _environment, $3 );
        if ( expr->initializedByConstant ) {
            switch( expr->value ) {
                case 0:
                    $$ = rnd0( _environment )->name;
                    break;
                case 1:
                    $$ = rnd1( _environment )->name;
                    break;
                default:
                    $$ = rnd( _environment, $3 )->name;
                    break;
            }
        } else {
            $$ = rnd( _environment, $3 )->name;
        }
    } | 
    RANGE OP expr OP_COMMA expr OP_COMMA expr CP { $$ = range( _environment, $3, $5, $7 )->name; } |
    casting { $$ = $1; } | 
    FREE {
        cpu_dsgc( _environment );
        Variable * var = variable_temporary( _environment, VT_WORD, "(free)" );
        cpu_move_16bit( _environment, "FREE_STRING", var->realName );
        $$ = var->name;
    } | 
    SCREEN { $$ = variable_by_constant( _environment, VT_BYTE, SCREEN_CAPABILITIES)->name; } | 
    CAN SCREEN direct_integer { $$ = screen_can( _environment, $3 )->name; } | 
    TILEMAP { $$ = variable_by_constant( _environment, VT_BYTE, TILEMAP_NATIVE)->name; } | 
    BITMAP { $$ = variable_by_constant( _environment, VT_BYTE, BITMAP_NATIVE)->name; } | 
    POINT OP optional_x OP_COMMA optional_y CP { $$ = point( _environment, $3, $5 )->name; } |
    MAX OP expr OP_COMMA expr CP { $$ = maximum( _environment, $3, $5 )->name; } |
    MIN OP expr OP_COMMA expr CP { $$ = minimum( _environment, $3, $5 )->name; } |
    PARAM OP Identifier on_targets CP  {
        if ( $4 ) {
            $$ = param_procedure( _environment, $3 )->name;
        } else {
            Variable * var = variable_temporary( _environment, VT_WORD, "(temp)" );
            $$ = var->name;
        }
    } | 
    PARAM OP_DOLLAR OP Identifier on_targets CP  {
        if ( $5 ) {
            $$ = param_procedure( _environment, $4 )->name;
        } else {
            Variable * var = variable_temporary( _environment, VT_WORD, "(temp)" );
            $$ = var->name;
        }
    } | 
    Identifier OSP {
      ((struct _Environment *)_environment)->parameters = 0;
    } values CSP {
      call_procedure( _environment, $1 );
      $$ = param_procedure( _environment, $1 )->name;
    } | 
    Identifier OSP CSP {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, $1 );
      $$ = param_procedure( _environment, $1 )->name;
    } | 
    RUNNING OP Identifier CP { $$ = running( _environment, $3, NULL )->name; } | 
    RUNNING OP Identifier OP_COMMA Identifier CP { $$ = running( _environment, $3, $5 )->name; } | 
    ANIMATING OP Identifier CP { $$ = animating( _environment, $3, NULL )->name; } |
    ANIMATING OP Identifier OP_COMMA Identifier CP { $$ = animating( _environment, $3, $5 )->name; } |
    MOVING OP Identifier CP { $$ = moving( _environment, $3, NULL )->name; } |
    MOVING OP Identifier OP_COMMA Identifier CP { $$ = moving( _environment, $3, $5 )->name; } |
    SPAWN Identifier {
      ((struct _Environment *)_environment)->parameters = 0;
      $$ = spawn_procedure( _environment, $2, 0 )->name;
    } | 
    SPAWN Identifier OSP {
        ((struct _Environment *)_environment)->parameters = 0;
        } values CSP {
      $$ = spawn_procedure( _environment, $2, 0 )->name;
    } | 
    SPAWN Identifier OSP CSP {
        ((struct _Environment *)_environment)->parameters = 0;
      $$ = spawn_procedure( _environment, $2, 0 )->name;
    } | 
    HALTED SPAWN Identifier {
      ((struct _Environment *)_environment)->parameters = 0;
      $$ = spawn_procedure( _environment, $3, 1 )->name;
    } | 
    HALTED SPAWN Identifier OSP {
        ((struct _Environment *)_environment)->parameters = 0;
        } values CSP {
      $$ = spawn_procedure( _environment, $3, 1 )->name;
    } | 
    HALTED SPAWN Identifier OSP CSP {
        ((struct _Environment *)_environment)->parameters = 0;
      $$ = spawn_procedure( _environment, $3, 1 )->name;
    } | 
    RESPAWN Identifier {
      ((struct _Environment *)_environment)->parameters = 0;
      $$ = respawn_procedure( _environment, $2 )->name;
    } | 
    SGN OP expr CP { $$ = sign( _environment, $3 )->name; } | 
    ABS OP expr CP { $$ = absolute( _environment, $3 )->name; } | 
    SERIAL serial_function { $$ = $2; } | 
    TRUE { $$ = variable_by_constant( _environment, VT_SBYTE, 255)->name; } | 
    FALSE { $$ = variable_by_constant( _environment, VT_SBYTE, 0)->name; } | 
    COLORS { $$ = variable_by_constant( _environment, VT_COLOR, ((Environment *)_environment)->screenColors)->name; } | 
    COLORS COUNT { $$ = variable_by_constant( _environment, VT_COLOR, ((Environment *)_environment)->screenColors)->name; } | 
    COLOR COUNT { $$ = variable_by_constant( _environment, VT_COLOR, ((Environment *)_environment)->screenColors)->name; } | 
    COLOURS { $$ = variable_by_constant( _environment, VT_COLOR, ((Environment *)_environment)->screenColors)->name; } | 
    COLOURS COUNT { $$ = variable_by_constant( _environment, VT_COLOR, ((Environment *)_environment)->screenColors)->name; } | 
    COLOUR COUNT { $$ = variable_by_constant( _environment, VT_COLOR, ((Environment *)_environment)->screenColors)->name; } | 
    THREAD {
        Variable * var = variable_temporary( _environment, VT_THREAD, "(THREAD)" );
        cpu_protothread_current( _environment, var->realName );
        $$ = var->name;
    } | 
    TASK {
        Variable * var = variable_temporary( _environment, VT_THREAD, "(TASK)" );
        cpu_protothread_current( _environment, var->realName );
        $$ = var->name;
    } | 
    SCREEN SHADES { $$ = variable_by_constant( _environment, VT_COLOR, ((Environment *)_environment)->screenShades)->name; } | 
    SHADES { $$ = variable_by_constant( _environment, VT_COLOR, ((Environment *)_environment)->screenShades)->name; } | 
    SCREEN COLORS { $$ = variable_by_constant( _environment, VT_COLOR, ((Environment *)_environment)->screenColors)->name; } | 
    PEN COLORS { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_COUNT)->name; } | 
    SCREEN COLOURS { $$ = variable_by_constant( _environment, VT_COLOR, ((Environment *)_environment)->screenColors)->name; } | 
    PEN COLOURS { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_COUNT)->name; } | 
    PEN DEFAULT { $$ = variable_by_constant( _environment, VT_COLOR, DEFAULT_PEN_COLOR)->name; } | 
    DEFAULT PEN { $$ = variable_by_constant( _environment, VT_COLOR, DEFAULT_PEN_COLOR)->name; } | 
    PAPER COLORS { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_COUNT)->name; } | 
    PAPER COLOURS { $$ = variable_by_constant( _environment, VT_COLOR, COLOR_COUNT)->name; } | 
    PAPER DEFAULT { $$ = variable_by_constant( _environment, VT_COLOR, DEFAULT_PAPER_COLOR)->name; } | 
    DEFAULT PAPER { $$ = variable_by_constant( _environment, VT_COLOR, DEFAULT_PAPER_COLOR)->name; } | 
    XTEXT OP expr CP { $$ = x_text_get( _environment, $3 )->name; } | 
    X TEXT OP expr CP { $$ = x_text_get( _environment, $4 )->name; } | 
    YTEXT OP expr CP { $$ = y_text_get( _environment, $3 )->name; } | 
    Y TEXT OP expr CP { $$ = y_text_get( _environment, $4 )->name; } | 
    XGRAPHIC OP expr CP { $$ = x_graphic_get( _environment, $3 )->name; } | 
    X GRAPHIC OP expr CP { $$ = x_graphic_get( _environment, $4 )->name; } | 
    YGRAPHIC OP expr CP { $$ = y_graphic_get( _environment, $3 )->name; } | 
    Y GRAPHIC OP expr CP { $$ = y_graphic_get( _environment, $4 )->name; } | 
    ROTATE VECTOR OP expr OP_COMMA expr CP { $$ = rotate_vector( _environment, $4, $6 )->name; } | 
    X OP expr CP { $$ = vector_get_x( _environment, $3 )->name; } | 
    Y OP expr CP { $$ = vector_get_y( _environment, $3 )->name; } | 
    WIDTH { $$ = screen_get_width( _environment )->name; } | 
    COLOR OP expr CP { $$ = color_get_vars( _environment, $3 )->name; } | 
    SCREEN WIDTH { $$ = screen_get_width( _environment )->name; } | 
    SCREEN TILES WIDTH { $$ = screen_tiles_get_width( _environment )->name; } | 
    TILES WIDTH { $$ = console_tiles_get_width( _environment )->name; } | 
    TILES COUNT { $$ = screen_tiles_get( _environment )->name; } | 
    SCREEN COLUMNS { $$ = screen_tiles_get_width( _environment )->name; } | 
    COLUMNS { $$ = console_tiles_get_width( _environment )->name; } | 
    FONT WIDTH { $$ = variable_by_constant( _environment, VT_BYTE, ((struct _Environment *)_environment)->fontWidth )->name; } | 
    IMAGES COUNT OP expr CP { $$ = variable_by_constant( _environment, VT_BYTE, frames( _environment, $4 ) )->name; } |
    FRAME COUNT OP expr CP { $$ = variable_by_constant( _environment, VT_BYTE, frames( _environment, $4 ) )->name; } |
    TILE COUNT OP expr CP { $$ = variable_by_constant( _environment, VT_BYTE, frames( _environment, $4 ) )->name; } |
    FRAMES OP expr CP { $$ = variable_by_constant( _environment, VT_BYTE, frames( _environment, $3 ) )->name; } |
    TILE CLASS OP expr OP_COMMA const_expr CP { $$ = tile_class( _environment, $4, $6 )->name; } | 
    TILE PROBABILITY OP expr OP_COMMA const_expr CP { $$ = tile_probability( _environment, $4, $6 )->name; } | 
    TILE BELONG OP expr OP_COMMA expr CP { $$ = tile_belong( _environment, $4, $6 )->name; } |
    TILE AT OP expr OP_COMMA expr CP { $$ = tile_at( _environment, $4, $6 )->name; } |
    TILES FIRST OP expr CP { $$ = tile_get_first( _environment, $4 )->name; } |
    TILEMAP WIDTH OP expr CP { $$ = tilemap_get_width( _environment, $4 )->name; } |
    TILE WIDTH OP expr CP {
          if ( ! ((Environment *)_environment)->emptyProcedure ) {
            Variable * v = variable_retrieve( _environment, $4 );
            if ( v->type == VT_IMAGES && v->originalTileset != NULL ) {
                $$ = tileset_tile_get_width( _environment, $4 )->name;
            } else {
                $$ = tile_get_width( _environment, $4 )->name;
            }
          } else {
            $$ = variable_temporary( _environment, VT_BYTE, "(zero)" )->name;
            variable_store( _environment, $$, 0 );
          }
    } | 
    DLOAD ERROR {
        $$ = variable_temporary( _environment, VT_BYTE, "(DLOAD ERROR)" )->name;
        variable_move( _environment, "DLOADERROR", $$ );
    } | 
    DSAVE ERROR {
        $$ = variable_temporary( _environment, VT_BYTE, "(DSAVE ERROR)" )->name;
        variable_move( _environment, "DSAVEERROR", $$ );
    } | 
    PAL {
        Variable * pal = variable_temporary( _environment, VT_SBYTE, "PAL" );
        cpu_compare_8bit_const( _environment, "TICKSPERSECOND", 50, pal->realName, 1 );
        $$ = pal->name;
    } | 
    NTSC {
        Variable * ntsc = variable_temporary( _environment, VT_SBYTE, "NTSC" );
        cpu_compare_8bit_const( _environment, "TICKSPERSECOND", 60, ntsc->realName, 1 );
        $$ = ntsc->name;
    } | 
    LITTLE ENDIAN { $$ = variable_by_constant( _environment, VT_SBYTE, (ENDIANESSVALUE == 1) ? 255 : 0)->name; } |
    BIG ENDIAN { $$ = variable_by_constant( _environment, VT_SBYTE, (ENDIANESSVALUE == 0) ? 255 : 0)->name; } |
    IMAGE WIDTH OP expr CP { $$ = image_get_width( _environment, $4 )->name; } |
    HEIGHT { $$ = screen_get_height( _environment )->name; } |
    SCREEN HEIGHT { $$ = screen_get_height( _environment )->name; } |
    SCREEN TILES HEIGHT { $$ = screen_tiles_get_height( _environment )->name; } |
    TILES HEIGHT { $$ = screen_tiles_get_height( _environment )->name; } |
    SCREEN ROWS { $$ = screen_tiles_get_height( _environment )->name; } |
    ROWS { $$ = console_tiles_get_height( _environment )->name; } |
    FONT HEIGHT { $$ = variable_by_constant( _environment, VT_BYTE, ((struct _Environment *)_environment)->fontHeight )->name; } |
    TILEMAP HEIGHT OP expr CP { $$ = tilemap_get_height( _environment, $4 )->name; } |
    TILE HEIGHT OP expr CP {
        if ( ! ((Environment *)_environment)->emptyProcedure ) {
            Variable * v = variable_retrieve( _environment, $4 );
            if ( v->type == VT_IMAGES && v->originalTileset != NULL ) {
                $$ = tileset_tile_get_height( _environment, $4 )->name;
            } else {
                $$ = tile_get_height( _environment, $4 )->name;
            }
        } else {
            $$ = variable_temporary( _environment, VT_BYTE, "(zero)" )->name;
            variable_store( _environment, $$, 0 );
        }
    } |
    IMAGE HEIGHT OP expr CP { $$ = image_get_height( _environment, $4 )->name; } |
    TILEMAP Identifier AT OP expr OP_COMMA expr CP { $$ = tilemap_at( _environment, $2, $5, $7, NULL )->name; } |
    TILEMAP Identifier LAYER expr AT OP expr OP_COMMA expr CP { $$ = tilemap_at( _environment, $2, $7, $9, $4 )->name; } |
    SCREEN PAGE { $$ = screen_page( _environment )->name; } | 
    VOLUME MIN { $$ = variable_by_constant( _environment, VT_BYTE, 0 )->name; } | 
    VOLUME MAX { $$ = variable_by_constant( _environment, VT_BYTE, 255 )->name; } | 
    SPRITE COUNT { $$ = variable_by_constant( _environment, VT_BYTE, SPRITE_COUNT )->name; } | 
    SPRITE HEIGHT {
        if ( SPRITE_HEIGHT < 0 ) {
            $$ = screen_get_height( _environment )->name;
        } else {
            $$ = variable_temporary( _environment, VT_WORD, "(SPRITE HEIGHT)" )->name;
            variable_store( _environment, $$, SPRITE_HEIGHT );
        }
    } | 
    SPRITE WIDTH {
        if ( SPRITE_HEIGHT < 0 ) {
            $$ = screen_get_width( _environment )->name;
        } else {
            $$ = variable_temporary( _environment, VT_WORD, "(SPRITE WIDTH)" )->name;
            variable_store( _environment, $$, SPRITE_WIDTH );
        }
    } | 
    SCREEN SPRITE RATIO X { $$ = variable_by_constant( _environment, VT_POSITION, SCREEN_SPRITE_RATIO_X )->name; } |
    SCREEN SPRITE RATIO Y { $$ = variable_by_constant( _environment, VT_POSITION, SCREEN_SPRITE_RATIO_Y )->name; } |
    SCREEN BORDER X { $$ = variable_by_constant( _environment, VT_POSITION, SCREEN_BORDER_X )->name; } | 
    SCREEN BORDER Y { $$ = variable_by_constant( _environment, VT_POSITION, SCREEN_BORDER_Y )->name; } |
    TICK PER SECOND { $$ = get_ticks_per_second( _environment )->name; } | 
    TICKS PER SECOND { $$ = get_ticks_per_second( _environment )->name; } | 
    TPS { $$ = get_ticks_per_second( _environment )->name; } | 
    SPRITE X MIN { $$ = variable_by_constant( _environment, VT_POSITION, SPRITE_X_MIN )->name; } | 
    SPRITE MIN X { $$ = variable_by_constant( _environment, VT_POSITION, SPRITE_X_MIN )->name; } | 
    SPRITE MIN Y { $$ = variable_by_constant( _environment, VT_POSITION, SPRITE_Y_MIN )->name; } | 
    SPRITE Y MIN { $$ = variable_by_constant( _environment, VT_POSITION, SPRITE_Y_MIN )->name; } | 
    SPRITE X MAX { $$ = variable_by_constant( _environment, VT_POSITION, SPRITE_X_MAX )->name; } | 
    SPRITE MAX X { $$ = variable_by_constant( _environment, VT_POSITION, SPRITE_X_MAX )->name; } | 
    SPRITE MAX Y { $$ = variable_by_constant( _environment, VT_POSITION, SPRITE_Y_MAX )->name; } | 
    SPRITE Y MAX { $$ = variable_by_constant( _environment, VT_POSITION, SPRITE_Y_MAX )->name; } | 
    SPRITE OP expr sprite_flags CP { $$ = sprite_init( _environment, $3, NULL, $4 )->name; } | 
    SPRITE OP expr OP_COMMA expr sprite_flags CP  { $$ = sprite_init( _environment, $3, $5, $6 )->name; } | 
    CSPRITE OP expr sprite_flags CP { $$ = csprite_init( _environment, $3, NULL, $4 )->name; } | 
    CSPRITE OP expr OP_COMMA expr sprite_flags CP { $$ = csprite_init( _environment, $3, $5, $6 )->name; } | 
    MSPRITE OP expr sprite_flags CP {
        Variable * original = variable_retrieve( _environment, $3 );
        if ( original->type == VT_MSPRITE ) {
            $$ = msprite_duplicate( _environment, $3 )->name;
        } else {
            $$ = msprite_init( _environment, $3, NULL, $4 )->name;
        }
    } | 
    MSPRITE OP expr OP_COMMA expr sprite_flags CP { $$ = msprite_init( _environment, $3, $5, $6 )->name; } | 
    PAGE Integer {
        if ( ( $2 != 0 ) && ( $2 != 1 ) ) {
            CRITICAL_PAGE01();
        }
        $$ = variable_temporary( _environment, VT_BYTE, "(PAGE)" )->name;
        variable_store( _environment, $$, $2 );
    } | 
    PAGE A { $$ = variable_by_constant( _environment, VT_BYTE, DOUBLE_BUFFER_PAGE_0 )->name; } | 
    PAGE B { $$ = variable_by_constant( _environment, VT_BYTE, DOUBLE_BUFFER_PAGE_1 )->name;  } | 
    IMAGE OP expr frame const_expr CP { $$ = image_extract( _environment, $3, $5, NULL )->name; } | 
    IMAGE OP expr sequence_or_strip const_expr frame const_expr CP {
        int sequence = $5;
        $$ = image_extract( _environment, $3, $7, &sequence )->name;
    } | 
    IMAGE OP expr frame NAMED Identifier CP {
        Variable * images = variable_retrieve( _environment, $3 );
        int calculatedFrame = find_frame_by_type( _environment, images->originalTileset, $3, $6 );
        $$ = image_extract( _environment, $3, calculatedFrame, NULL )->name;
    } | 
    RASTER LINE { $$ = get_raster_line( _environment )->name; } | 
    TI { $$ = get_timer( _environment )->name; } | 
    EMPTYTILE { $$ = "EMPTYTILE"; } | 
    EMPTY TILE { $$ = "EMPTYTILE"; } | 
    TIMER { $$ = get_timer( _environment )->name; } | 
    PEN {
        Variable * pen = variable_temporary( _environment, VT_COLOR, "(pen)" );
        cpu_move_8bit( _environment, "_PEN", pen->realName );
        $$ = pen->name;
    } | 
    PEN OP expr CP { $$ = get_pen( _environment, $3 )->name; } | 
    PEN OP_DOLLAR OP expr CP { $$ = get_pen( _environment, $4 )->name; } | 
    PAPER OP expr CP { $$ = get_paper( _environment, $3 )->name; } | 
    PAPER OP_DOLLAR OP expr CP { $$ = get_paper( _environment, $4 )->name; } | 
    CMOVE OP expr OP_COMMA expr CP { $$ = get_cmove( _environment, $3, $5 )->name; } | 
    CMOVE OP_DOLLAR OP expr OP_COMMA expr CP { $$ = get_cmove( _environment, $4, $6 )->name; } | 
    CUP { $$ = get_cmove_direct( _environment, 0, -1 )->name; } | 
    CUP OP_DOLLAR { $$ = get_cmove_direct( _environment, 0, -1 )->name; } | 
    CDOWN { $$ = get_cmove_direct( _environment, 0, 1 )->name; } | 
    CDOWN OP_DOLLAR { $$ = get_cmove_direct( _environment, 0, 1 )->name; } | 
    CLEFT { $$ = get_cmove_direct( _environment, -1, 0 )->name; } | 
    CLEFT OP_DOLLAR { $$ = get_cmove_direct( _environment, -1, 0 )->name; } | 
    CRIGHT { $$ = get_cmove_direct( _environment, 1, 0 )->name; } | 
    CRIGHT OP_DOLLAR { $$ = get_cmove_direct( _environment, 1, 0 )->name; } | 
    AT OP expr OP_COMMA expr CP { $$ = get_at( _environment, $3, $5 )->name; } | 
    AT OP_DOLLAR OP expr OP_COMMA expr CP { $$ = get_at( _environment, $4, $6 )->name; } | 
    LOCATE OP expr OP_COMMA expr CP { $$ = get_at( _environment, $3, $5 )->name; } | 
    LOCATE OP_DOLLAR OP expr OP_COMMA expr CP { $$ = get_at( _environment, $4, $6 )->name; } | 
    TAB { $$ = get_tab( _environment )->name; } | 
    TAB OP_DOLLAR { $$ = get_tab( _environment )->name; } | 
    XCURS { $$ = text_get_xcurs( _environment )->name; } | 
    X CURS { $$ = text_get_xcurs( _environment )->name; } | 
    YCURS { $$ = text_get_ycurs( _environment )->name; } | 
    Y CURS { $$ = text_get_ycurs( _environment )->name; } | 
    TEXTADDRESS { $$ = strdup( "TEXTADDRESS" ); } | 
    BITMAPADDRESS { $$ = strdup( "BITMAPADDRESS" ); } | 
    JOY OP OP_HASH const_expr CP { $$ = joy( _environment, $4 )->name; } | 
    JOY OP expr CP { $$ = joy_vars( _environment, $3 )->name; } | 
    JOYX { $$ = joyx( _environment, 0 )->name; } | 
    JOYX OP OP_HASH const_expr CP { $$ = joyx( _environment, $4 )->name; } | 
    JOYX OP expr CP { $$ = joyx_vars( _environment, $3 )->name; } | 
    JOY X  { $$ = joyx( _environment, 0 )->name; } | 
    JOY X OP OP_HASH const_expr CP { $$ = joyx( _environment, $5 )->name; } | 
    JOY X OP expr CP { $$ = joyx_vars( _environment, $4 )->name; } | 
    JOYY { $$ = joyy( _environment, 0 )->name; } | 
    JOYY OP OP_HASH const_expr CP { $$ = joyy( _environment, $4 )->name; } | 
    JOYY OP expr CP { $$ = joyy_vars( _environment, $3 )->name; } | 
    JOY Y { $$ = joyy( _environment, 0 )->name; } | 
    JOY Y OP OP_HASH const_expr CP { $$ = joyy( _environment, $5 )->name; } | 
    JOY Y OP expr CP { $$ = joyy_vars( _environment, $4 )->name; } | 
    JOYDIR { $$ = joydir( _environment, 0 )->name; } | 
    JOYDIR OP expr CP { $$ = joydir_semivars( _environment, $3 )->name; } | 
    JOYDIR OP OP_HASH const_expr CP { $$ = joydir( _environment, $4 )->name; } | 
    JUP OP expr CP { $$ = joy_direction_semivars( _environment, $3, JOY_UP )->name; } | 
    JUP { $$ = joy_direction( _environment, 0, JOY_UP )->name; } | 
    JUP OP OP_HASH const_expr CP { $$ = joy_direction( _environment, $4, JOY_UP )->name; } | 
    JDOWN OP expr CP { $$ = joy_direction_semivars( _environment, $3, JOY_DOWN )->name; } | 
    JDOWN { $$ = joy_direction( _environment, 0, JOY_DOWN )->name; } | 
    JDOWN OP OP_HASH const_expr CP { $$ = joy_direction( _environment, $4, JOY_DOWN )->name; } | 
    JLEFT OP expr CP { $$ = joy_direction_semivars( _environment, $3, JOY_LEFT )->name; } | 
    JLEFT { $$ = joy_direction( _environment, 0, JOY_LEFT )->name; } | 
    JLEFT OP OP_HASH const_expr CP { $$ = joy_direction( _environment, $4, JOY_LEFT )->name; } | 
    JRIGHT { $$ = joy_direction( _environment, 0, JOY_RIGHT )->name; } | 
    JRIGHT OP expr CP { $$ = joy_direction_semivars( _environment, $3, JOY_RIGHT )->name; } | 
    JRIGHT OP OP_HASH const_expr CP { $$ = joy_direction( _environment, $4, JOY_RIGHT )->name; } | 
    JFIRE { $$ = jfire( _environment, 0 )->name; } | 
    JFIRE OP expr CP { $$ = jfire_vars( _environment, $3 )->name; } | 
    JFIRE OP OP_HASH const_expr CP { $$ = jfire( _environment, $4 )->name; } | 
    FIRE OP expr CP { $$ = jfire_vars( _environment, $3 )->name; } | 
    FIRE OP OP_HASH const_expr CP { $$ = jfire( _environment, $4 )->name; } | 
    STRIG { $$ = strig( _environment, 0 )->name; } | 
    STRIG OP expr CP { $$ = strig_vars( _environment, $3 )->name; } | 
    STRIG OP OP_HASH const_expr CP { $$ = strig( _environment, $4 )->name; } | 
    JOY COUNT { $$ = variable_by_constant( _environment, VT_BYTE, JOY_COUNT )->name; } | 
    JOYCOUNT { $$ = variable_by_constant( _environment, VT_BYTE, JOY_COUNT )->name; } | 
    BIT OP expr OP_COMMA expr CP { $$ = variable_bit( _environment, $3, $5 )->name; } | 
    UP { $$ = variable_by_constant( _environment, VT_BYTE, JOY_UP )->name; } | 
    DOWN { $$ = variable_by_constant( _environment, VT_BYTE, JOY_DOWN )->name; } | 
    LEFT { $$ = variable_by_constant( _environment, VT_BYTE, JOY_LEFT )->name; } | 
    RIGHT { $$ = variable_by_constant( _environment, VT_BYTE, JOY_RIGHT )->name; } | 
    FIRE { $$ = variable_by_constant( _environment, VT_BYTE, JOY_FIRE )->name; } | 
    JOY UP { $$ = variable_by_constant( _environment, VT_BYTE, 1 << JOY_UP )->name; } | 
    JOY DOWN { $$ = variable_by_constant( _environment, VT_BYTE, 1 << JOY_DOWN )->name; } | 
    JOY LEFT { $$ = variable_by_constant( _environment, VT_BYTE, 1 << JOY_LEFT )->name; }  | 
    JOY RIGHT { $$ = variable_by_constant( _environment, VT_BYTE, 1 << JOY_RIGHT )->name; } | 
    JOY FIRE { $$ = variable_by_constant( _environment, VT_BYTE, 1 << JOY_FIRE )->name; } | 
    INPUT OP expr CP { $$ = input_string( _environment, $3 )->name; } | 
    INPUT OP_DOLLAR OP expr CP { $$ = input_string( _environment, $4 )->name; } |
    INKEY { $$ = inkey( _environment )->name; } | 
    SCANCODE { $$ = scancode( _environment )->name; } | 
    SCAN CODE { $$ = scancode( _environment )->name; } |
    ASCIICODE { $$ = asciicode( _environment )->name; } |
    ASCII CODE { $$ = asciicode( _environment )->name; } |
    KEY PRESSED OP OP_HASH const_expr CP {
        if ( ((Environment *)_environment)->keyPressDutyCycle ) {
            $$ = key_pressed( _environment, $5 )->name;
        } else {
            $$ = key_state( _environment, $5 )->name;
        }
    } | 
    KEY PRESSED OP expr CP {
        if ( ((Environment *)_environment)->keyPressDutyCycle ) {
            $$ = key_pressed_var( _environment, $4 )->name;
        } else {
            $$ = key_state_var( _environment, $4 )->name;
        }
    } | 
    KEY STATE OP OP_HASH const_expr CP { $$ = key_state( _environment, $5 )->name; } | 
    KEY STATE OP expr CP { $$ = key_state_var( _environment, $4 )->name; } | 
    KEYSTATE OP expr CP { $$ = key_state_var( _environment, $3 )->name; } | 
    SCANSHIFT { $$ = scanshift( _environment )->name; } | 
    SCAN SHIFT { $$ = scanshift( _environment )->name; } | 
    KEYSHIFT { $$ = keyshift( _environment )->name; } | 
    KEY SHIFT { $$ = keyshift( _environment )->name; } | 
    LEFT SHIFT { $$ = variable_by_constant( _environment, VT_BYTE, SHIFT_LEFT )->name; } | 
    SHIFT LEFT { $$ = variable_by_constant( _environment, VT_BYTE, SHIFT_LEFT )->name; } | 
    RIGHT SHIFT { $$ = variable_by_constant( _environment, VT_BYTE, SHIFT_RIGHT )->name; } | 
    SHIFT RIGHT { $$ = variable_by_constant( _environment, VT_BYTE, SHIFT_RIGHT )->name; } | 
    CAPSLOCK { $$ = variable_by_constant( _environment, VT_BYTE, SHIFT_CAPSLOCK )->name; } | 
    CAPS LOCK { $$ = variable_by_constant( _environment, VT_BYTE, SHIFT_CAPSLOCK )->name; } | 
    CONTROL { $$ = variable_by_constant( _environment, VT_BYTE, SHIFT_CONTROL )->name; } | 
    LEFT ALT { $$ = variable_by_constant( _environment, VT_BYTE, SHIFT_LEFT_ALT )->name; } | 
    ALT LEFT { $$ = variable_by_constant( _environment, VT_BYTE, SHIFT_LEFT_ALT )->name; } | 
    RIGHT ALT { $$ = variable_by_constant( _environment, VT_BYTE, SHIFT_RIGHT_ALT )->name; } | 
    ALT RIGHT { $$ = variable_by_constant( _environment, VT_BYTE, SHIFT_RIGHT_ALT )->name; } | 
    KEY key_scancode_definition { $$ = $2; } | 
    NOTE const_note { $$ = variable_by_constant( _environment, VT_BYTE, $2 )->name; } | 
    filesize OP const_expr_string CP { $$ = variable_by_constant( _environment, VT_BYTE, file_size( _environment, $3 ) )->name; } | 
    IF OP const_expr OP_COMMA const_expr OP_COMMA const_expr CP { $$ = variable_by_constant( _environment, ((struct _Environment *)_environment)->defaultVariableType, ($3) ? $5 : $7 )->name; } | 
    IF OP const_expr OP_COMMA const_expr_floating OP_COMMA const_expr_floating CP {
        $$ = variable_temporary( _environment, VT_FLOAT, "(iff)" )->name;
        if ( $3 ) {
          variable_store_float( _environment, $$, $5 );
        } else {
          variable_store_float( _environment, $$, $7 );
        }
      }
    | IF OP const_expr OP_COMMA const_expr_string OP_COMMA const_expr_string CP {
        $$ = variable_temporary( _environment, VT_STRING, "(ifs)" )->name;
        if ( $3 ) {
          variable_store_string( _environment, $$, $5 );
        } else {
          variable_store_string( _environment, $$, $7 );
        }
    }
    | Identifier OP_PERIOD Identifier { $$ = variable_move_from_type( _environment, $1, $3 )->name; }
    | OSP Identifier as_datatype_suffix_optional CSP field_optional {
        if ( !((struct _Environment *)_environment)->procedureName ) {
            CRITICAL_CANNOT_USE_MULTITASKED_ARRAY($2);
        }
        parser_array_init( _environment );
        define_implicit_array_if_needed( _environment, $2 );
        parser_array_index_symbolic( _environment, "PROTOTHREADCT" );
        Variable * array;
        if ( ! variable_exists( _environment, $2 ) ) {
            VariableType vt = $3;
            if ( vt == 0 ) {
                vt = ((struct _Environment *)_environment)->defaultVariableType;
            }
            if ( ((struct _Environment *)_environment)->optionExplicit ) {
                CRITICAL_VARIABLE_UNDEFINED( $2 );
            } else {
                array = variable_define( _environment, $2, VT_TARRAY, 0 );
                array->arrayType = vt;
                array->arrayPrecision = ((struct _Environment *)_environment)->floatType.precision;
            }
        }        
        array = variable_retrieve( _environment, $2 );        
        if ( array->type != VT_TARRAY ) {
            CRITICAL_NOT_ARRAY( $2 );
        }
        VariableType vt = $3;
        if ( vt != 0 ) {
            if ( array->arrayType != vt ) {
                CRITICAL_ARRAY_DATATYPE_WRONG( $2 );
            }
        }
        if ( $5 ) {
            $$ = variable_move_from_array_type( _environment, $2, $5 )->name;
        } else {
            $$ = variable_move_from_array( _environment, $2 )->name;
        }
        parser_array_cleanup( _environment );
    }
    ;

/*-----------------------------------------------------------------------------
 ------------ BANK DEFINITION
 ----------------------------------------------------------------------------*/

bank_definition_simple:
  AT direct_integer { bank_define( _environment, NULL, BT_DATA, $2, NULL ); } | 
  AT direct_integer AS CODE { bank_define( _environment, NULL, BT_CODE, $2, NULL ); } | 
  AT direct_integer AS DATA { bank_define( _environment, NULL, BT_DATA, $2, NULL ); } | 
  AT direct_integer AS TEMPORARY { bank_define( _environment, NULL, BT_TEMPORARY, $2, NULL ); } | 
  AT direct_integer AS VARIABLES { bank_define( _environment, NULL, BT_VARIABLES, $2, NULL ); } | 
  CODE AT direct_integer { bank_define( _environment, NULL, BT_CODE, $3, NULL ); } | 
  CODE Identifier AT direct_integer { bank_define( _environment, $2, BT_CODE, $4, NULL ); } | 
  DATA AT direct_integer { bank_define( _environment, NULL, BT_DATA, $3, NULL ); } | 
  DATA Identifier AT direct_integer { bank_define( _environment, $2, BT_DATA, $4, NULL ); } | 
  Identifier AT direct_integer { bank_define( _environment, $1, BT_DATA, $3, NULL ); } | 
  Identifier AT direct_integer AS CODE { bank_define( _environment, $1, BT_CODE, $3, NULL ); } | 
  Identifier AT direct_integer AS DATA { bank_define( _environment, $1, BT_DATA, $3, NULL ); } | 
  Identifier AT direct_integer AS TEMPORARY { bank_define( _environment, $1, BT_TEMPORARY, $3, NULL ); } |
  Identifier AT direct_integer AS VARIABLES { bank_define( _environment, $1, BT_VARIABLES, $3, NULL ); } | 
  TEMPORARY AT direct_integer { bank_define( _environment, NULL, BT_TEMPORARY, $3, NULL ); } |
  TEMPORARY Identifier AT direct_integer { bank_define( _environment, $2, BT_TEMPORARY, $4, NULL ); } |
  VARIABLES AT direct_integer { bank_define( _environment, NULL, BT_VARIABLES, $3, NULL ); } | 
  VARIABLES Identifier AT direct_integer { bank_define( _environment, $2, BT_VARIABLES, $4, NULL ); };

bank_definition_with_payload:
  CODE Identifier AT direct_integer WITH String { bank_define( _environment, $2, BT_CODE, $4, $6 ); } |
  DATA Identifier AT direct_integer WITH String { bank_define( _environment, $2, BT_DATA, $4, $6 ); } |
  Identifier AT direct_integer AS CODE WITH String { bank_define( _environment, $1, BT_CODE, $3, $7 ); } |
  Identifier AT direct_integer AS DATA WITH String { bank_define( _environment, $1, BT_DATA, $3, $7 ); } | 
  Identifier AT direct_integer WITH String { bank_define( _environment, $1, BT_DATA, $3, $5 ); };

/*-----------------------------------------------------------------------------
 ------------ EXPANSION BANK DEFINITION
 ----------------------------------------------------------------------------*/

bank_expansion_definition_simple:
    OP_HASH const_expr { bank_set( _environment, $2 ); };

bank_expansion_definition_expression:
    expr { bank_set_var( _environment, $1 ); } | 
    READ expr FROM expr TO expr SIZE expr { bank_read_vars( _environment, $2, $4, $6, $8 ); } | 
    WRITE expr FROM expr TO expr SIZE expr { bank_write_vars( _environment, $4, $2, $6, $8 ); };

/*-----------------------------------------------------------------------------
 ------------ (EXPANSION) BANK DEFINITION
 ----------------------------------------------------------------------------*/

bank_definition: 
    bank_definition_simple | 
    bank_definition_with_payload | 
    bank_expansion_definition_expression |
    bank_expansion_definition_simple;

/*-----------------------------------------------------------------------------
 ------------ RASTER DEFINITION
 ----------------------------------------------------------------------------*/

raster_definition_simple:
    AT direct_integer WITH Identifier { raster_at( _environment, $4, $2 ); } |
    Identifier AT direct_integer { raster_at( _environment, $1, $3 ); }; 

raster_definition_expression:
    AT expr WITH Identifier { raster_at_var( _environment, $2, $4 ); } |
    Identifier AT expr { raster_at_var( _environment, $1, $3 ); };

next_raster_definition_simple:
    AT direct_integer WITH Identifier { next_raster_at_with( _environment, $2, $4 ); } |
    Identifier AT direct_integer { next_raster_at_with( _environment, $3, $1 ); };

next_raster_definition_expression:
    AT expr WITH Identifier { next_raster_at_with_var( _environment, $2, $4 ); } |
    Identifier AT expr { next_raster_at_with_var( _environment, $3, $1 ); }; 

raster_definition:
    raster_definition_expression |
    raster_definition_simple;

next_raster_definition:
    next_raster_definition_expression |
    next_raster_definition_simple;

/*-----------------------------------------------------------------------------
 ------------ COLOR DEFINITION
 ----------------------------------------------------------------------------*/

color_definition_simple:
    BACKGROUND direct_integer TO direct_integer { color_background( _environment, $2, $4 ); } | 
    BORDER direct_integer { color_border( _environment, $2 ); } | 
    OP_HASH const_expr OP_COMMA expr { color_semivars( _environment, $2, $4 ); } | 
    OP_HASH const_expr OP_COMMA OP_HASH const_expr { color( _environment, $2, $5 ); } | 
    SPRITE direct_integer TO direct_integer { color_sprite( _environment, $2, $4 ); };

color_definition_expression:
  expr OP_COMMA expr OP_COMMA expr { color_tsb( _environment, $1, $3, $5 ); } | 
  expr OP_COMMA expr {
      if ( !((struct _Environment *)_environment)->insideCopperList ) {
        if ( ((Environment *)_environment)->dialect == DI_TSB ) {
            color_tsb( _environment, $1, $3, NULL );
        } else {
            Variable * index = variable_retrieve( _environment, $1 );
            Variable * value = variable_retrieve( _environment, $3 );
            if ( !index->initializedByConstant || !value->initializedByConstant) {
                color_vars( _environment, $1, $3 );
            } else {
                color( _environment, index->value, value->value );
            }
        }
      } else {
        Variable * index = variable_retrieve( _environment, $1 );
        if ( !index->initializedByConstant ) {
            CRITICAL_COLOR_WITH_NOT_CONST_NOT_ALLOWED( $1 );
        }
        Variable * color = variable_retrieve( _environment, $3 );
        if ( !color->initializedByConstant ) {
            CRITICAL_COLOR_WITH_NOT_CONST_NOT_ALLOWED( $3 );
        }
        copper_color( _environment, index->value, color->value );
      }
  } |
  OP_COMMA expr { color_tsb( _environment, NULL, NULL, $2 ); } |
  expr { color_tsb( _environment, $1, NULL, NULL ); } | 
  BORDER expr {
      if ( !((struct _Environment *)_environment)->insideCopperList ) {
          color_border_var( _environment, $2 );
      } else {
        Variable * color = variable_retrieve( _environment, $2 );
        if ( !color->initializedByConstant ) {
            CRITICAL_COLOR_WITH_NOT_CONST_NOT_ALLOWED( $2 );
        }
        copper_color_border( _environment, color->value );
      }
  } | 
  BACK expr { back( _environment, $2 ); } | 
  BACKGROUND expr {
      if ( !((struct _Environment *)_environment)->insideCopperList ) {
          back( _environment, $2 );
      } else {
        Variable * color = variable_retrieve( _environment, $2 );
        if ( !color->initializedByConstant ) {
            CRITICAL_COLOR_WITH_NOT_CONST_NOT_ALLOWED( $2 );
        }
        copper_color_background( _environment, color->value );
      }
  } | 
  BACKGROUND expr TO expr { color_background_vars( _environment, $2, $4 ); };

color_definition:
    color_definition_simple
  | color_definition_expression;

/*-----------------------------------------------------------------------------
 ------------ WAIT DEFINITION
 ----------------------------------------------------------------------------*/

wait_definition_simple:
    direct_integer CYCLES parallel_optional { wait_cycles( _environment, $1, $3 ); } | 
    direct_integer milliseconds { wait_milliseconds( _environment, $1 ); } | 
    direct_integer parallel_optional {
      if ( !((struct _Environment *)_environment)->insideCopperList ) {
        wait_cycles( _environment, $1, $2 );
      } else if ( $2 ) {
        CRITICAL_WAIT_PARALLEL_CANNOT_BE_CALLED_OUTSIDE_PROCEDURE( );
      } else {
        copper_wait( _environment, $1 );
      }
    } | 
    direct_integer ticks { wait_ticks( _environment, $1 ); } | 
    FIRE OP OP_HASH const_expr CP release_optional { wait_fire( _environment, $4, $6 ); } | 
    FIRE release_optional { wait_fire( _environment, -1, $2 ); } | 
    KEY OR FIRE OP OP_HASH const_expr CP release_optional { wait_key_or_fire( _environment, $6, $8 ); } |
    KEY OR FIRE release_optional { wait_key_or_fire( _environment, -1, $4 ); } | 
    KEY release_optional { wait_key( _environment, $2 ); } | 
    LINE const_expr { copper_wait( _environment, $2 ); } | 
    VBL { wait_vbl( _environment, NULL ); } | 
    VBL expr { wait_vbl( _environment, $2 ); };

wait_definition_expression:
    expr CYCLES parallel_optional {
        Variable * expr = variable_retrieve( _environment, $1 );
        if ( expr->initializedByConstant ) {
            wait_cycles( _environment, expr->value, $3 );
        } else {
            wait_cycles_var( _environment, $1, $3 );
        }
    } | 
    expr ticks {
        Variable * expr = variable_retrieve( _environment, $1 );
        if ( expr->initializedByConstant ) {
            wait_ticks( _environment, expr->value );
        } else {
            wait_ticks_var( _environment, $1 );
        }
    } | 
    expr milliseconds {
        Variable * expr = variable_retrieve( _environment, $1 );
        if ( expr->initializedByConstant ) {
            wait_milliseconds( _environment, expr->value );
        } else {
            wait_milliseconds_var( _environment, $1 );
        }
    } | 
    FIRE OP expr CP release_optional { wait_fire_semivar( _environment, $3, $5 ); } | 
    KEY OR FIRE OP expr CP release_optional { wait_key_or_fire_semivar( _environment, $5, $7 ); } | 
    UNTIL { 
        wait_until( _environment );  
    } expr {
        wait_until_condition( _environment, $3 );  
    } | 
    WHILE { 
        wait_while( _environment );  
    } expr {
        wait_while_condition( _environment, $3 );  
    } | 
    PARALLEL expr { 
        wait_parallel( _environment, $2 );  
    };

wait_definition:
    wait_definition_simple | 
    wait_definition_expression;

/*-----------------------------------------------------------------------------
 ------------ SLEEP DEFINITION
 ----------------------------------------------------------------------------*/

sleep_definition_simple:
    OP_HASH const_expr {
      wait_milliseconds( _environment, $2 * 1000 );
    };

sleep_definition_expression:
    expr {
        Variable * seconds = variable_retrieve_or_define( _environment, $1, VT_WORD, 0 );
        wait_milliseconds_var( _environment, variable_mul2_const( _environment, seconds->name, 1024 )->name );
    };

sleep_definition:
    sleep_definition_expression |
    sleep_definition_simple;

/*-----------------------------------------------------------------------------
 ------------ FADE DEFINITION
 ----------------------------------------------------------------------------*/

fade_in_palette:
    expr { fade_in_color_semivars( _environment, ((struct _Environment *)_environment)->paletteIndex++, $1 ); } | 
    OP_HASH const_expr { fade_in_color( _environment, ((struct _Environment *)_environment)->paletteIndex++, $2 ); } | 
    expr { fade_in_color_semivars( _environment, ((struct _Environment *)_environment)->paletteIndex++, $1 ); } OP_COMMA fade_in_palette |
    OP_HASH const_expr { fade_in_color( _environment, ((struct _Environment *)_environment)->paletteIndex++, $2 ); } OP_COMMA fade_in_palette;

fade_definition:
    IN { fade_in( _environment, NULL ); } | 
    IN {
      ((struct _Environment *)_environment)->paletteIndex = 0;
    } fade_in_palette period_optional {
      fade_in( _environment, $4 );
    } | 
    IN PERIOD expr { fade_in( _environment, $3 ); } |
    OUT { fade_out( _environment, NULL ); } | 
    OUT PERIOD expr { fade_out( _environment, $3 ); };

/*-----------------------------------------------------------------------------
 ------------ SPRITE DEFINITION
 ----------------------------------------------------------------------------*/

sprite_definition_action_simple:
    COLOR direct_integer { sprite_color( _environment, ((Environment *)_environment)->currentSpriteNumber, $2 ); } | 
    COLOUR direct_integer { sprite_color( _environment, ((Environment *)_environment)->currentSpriteNumber, $2 ); } |
    COMPRESS HORIZONTAL { sprite_compress_horizontal( _environment, ((Environment *)_environment)->currentSpriteNumber ); } |
    COMPRESS VERTICAL { sprite_compress_vertical( _environment, ((Environment *)_environment)->currentSpriteNumber ); } | 
    DISABLE { sprite_disable( _environment, ((Environment *)_environment)->currentSpriteNumber ); } | 
    ENABLE { sprite_enable( _environment, ((Environment *)_environment)->currentSpriteNumber ); } |
    EXPAND HORIZONTAL { sprite_expand_horizontal( _environment, ((Environment *)_environment)->currentSpriteNumber ); } |
    EXPAND VERTICAL { sprite_expand_vertical( _environment, ((Environment *)_environment)->currentSpriteNumber ); } |
    HORIZONTAL COMPRESS { sprite_compress_horizontal( _environment, ((Environment *)_environment)->currentSpriteNumber ); } |
    HORIZONTAL EXPAND { sprite_expand_horizontal( _environment, ((Environment *)_environment)->currentSpriteNumber ); } |
    MONOCOLOR { sprite_monocolor( _environment, ((Environment *)_environment)->currentSpriteNumber ); } |
    MONOCOLOUR { sprite_monocolor( _environment, ((Environment *)_environment)->currentSpriteNumber ); } | 
    MULTICOLOR { sprite_multicolor( _environment, ((Environment *)_environment)->currentSpriteNumber ); } | 
    MULTICOLOUR { sprite_multicolor( _environment, ((Environment *)_environment)->currentSpriteNumber ); } |
    OFF { sprite_disable( _environment, ((Environment *)_environment)->currentSpriteNumber ); } | 
    ON { sprite_enable( _environment, ((Environment *)_environment)->currentSpriteNumber ); } | 
    position direct_integer OP_COMMA direct_integer { sprite_at( _environment, ((Environment *)_environment)->currentSpriteNumber, $2, $4 ); } |
    VERTICAL COMPRESS { sprite_compress_vertical( _environment, ((Environment *)_environment)->currentSpriteNumber ); } |
    VERTICAL EXPAND { sprite_expand_vertical( _environment, ((Environment *)_environment)->currentSpriteNumber ); };

sprite_definition_simple:
    sprite_definition_action_simple | 
    sprite_definition_action_simple sprite_definition_simple;

sprite_definition_all_action_simple:
    | 
    ENABLE {
        for( int i=0; i<(SPRITE_COUNT-1); ++i ) {
            sprite_enable( _environment, i );
        }
    } | 
    ON {
        for( int i=0; i<(SPRITE_COUNT-1); ++i ) {
            sprite_enable( _environment, i );
        }
    } | 
    DISABLE {
        for( int i=0; i<(SPRITE_COUNT-1); ++i ) {
            sprite_disable( _environment, i );
        }
    } | 
    OFF {
        for( int i=0; i<(SPRITE_COUNT-1); ++i ) {
            sprite_disable( _environment, i );
        }
    } | 
    MULTICOLOR {
        for( int i=0; i<(SPRITE_COUNT-1); ++i ) {
            sprite_multicolor( _environment, i );
        }
    } | 
    MULTICOLOUR {
        for( int i=0; i<(SPRITE_COUNT-1); ++i ) {
            sprite_multicolor( _environment, i );
        }
    } | 
    MONOCOLOR {
        for( int i=0; i<(SPRITE_COUNT-1); ++i ) {
            sprite_monocolor( _environment, i );
        }
    } | 
    MONOCOLOUR {
        for( int i=0; i<(SPRITE_COUNT-1); ++i ) {
            sprite_monocolor( _environment, i );
        }
    } | 
    COLOR direct_integer {
        for( int i=0; i<(SPRITE_COUNT-1); ++i ) {
            sprite_color( _environment, i, $2 );
        }
    } | 
    COLOUR direct_integer {
        for( int i=0; i<(SPRITE_COUNT-1); ++i ) {
            sprite_color( _environment, i, $2 );
        }
    } | 
    position direct_integer OP_COMMA direct_integer {
        for( int i=0; i<(SPRITE_COUNT-1); ++i ) {
            sprite_at( _environment, i, $2, $4 );
        }
    } | 
    EXPAND VERTICAL {
        for( int i=0; i<(SPRITE_COUNT-1); ++i ) {
            sprite_expand_vertical( _environment, i );
        }
    } | 
    COMPRESS VERTICAL {
        for( int i=0; i<(SPRITE_COUNT-1); ++i ) {
            sprite_compress_vertical( _environment, i );
        }
    } | 
    VERTICAL EXPAND {
        for( int i=0; i<(SPRITE_COUNT-1); ++i ) {
            sprite_expand_vertical( _environment, i );
        }
    } | 
    VERTICAL COMPRESS {
        for( int i=0; i<(SPRITE_COUNT-1); ++i ) {
            sprite_compress_vertical( _environment, i );
        }
    } | 
    EXPAND HORIZONTAL {
        for( int i=0; i<(SPRITE_COUNT-1); ++i ) {
            sprite_expand_horizontal( _environment, i );
        }
    } | 
    COMPRESS HORIZONTAL {
        for( int i=0; i<(SPRITE_COUNT-1); ++i ) {
            sprite_compress_horizontal( _environment, i );
        }
    } | 
    HORIZONTAL EXPAND {
        for( int i=0; i<(SPRITE_COUNT-1); ++i ) {
            sprite_expand_horizontal( _environment, i );
        }
    } | HORIZONTAL COMPRESS {
        for( int i=0; i<(SPRITE_COUNT-1); ++i ) {
            sprite_compress_horizontal( _environment, i );
        }
    };

sprite_definition_all_simple:
    sprite_definition_all_action_simple;

sprite_definition_action_expression:
    COLOR expr { sprite_color_vars( _environment, ((Environment *)_environment)->currentSprite, $2 ); } |
    COLOUR expr { sprite_color_vars( _environment, ((Environment *)_environment)->currentSprite, $2 ); } | 
    COMPRESS HORIZONTAL { sprite_compress_horizontal_var( _environment, ((Environment *)_environment)->currentSprite ); } |
    COMPRESS VERTICAL { sprite_compress_vertical_var( _environment, ((Environment *)_environment)->currentSprite ); } |
    DISABLE { sprite_disable_var( _environment, ((Environment *)_environment)->currentSprite ); } |
    ENABLE { sprite_enable_var( _environment, ((Environment *)_environment)->currentSprite ); } |
    EXPAND HORIZONTAL { sprite_expand_horizontal_var( _environment, ((Environment *)_environment)->currentSprite ); } | 
    EXPAND VERTICAL { sprite_expand_vertical_var( _environment, ((Environment *)_environment)->currentSprite ); } | 
    HORIZONTAL COMPRESS { sprite_compress_horizontal_var( _environment, ((Environment *)_environment)->currentSprite ); } |
    HORIZONTAL EXPAND { sprite_expand_horizontal_var( _environment, ((Environment *)_environment)->currentSprite ); } |
    MONOCOLOR { sprite_monocolor_var( _environment, ((Environment *)_environment)->currentSprite ); } |
    MONOCOLOUR { sprite_monocolor_var( _environment, ((Environment *)_environment)->currentSprite ); } | 
    MULTICOLOR { sprite_multicolor_var( _environment, ((Environment *)_environment)->currentSprite ); } | 
    MULTICOLOUR { sprite_multicolor_var( _environment, ((Environment *)_environment)->currentSprite ); } | 
    OFF { sprite_disable_var( _environment, ((Environment *)_environment)->currentSprite ); } | 
    ON { sprite_enable_var( _environment, ((Environment *)_environment)->currentSprite ); } |
    position expr OP_COMMA expr { sprite_at_vars( _environment, ((Environment *)_environment)->currentSprite, $2, $4 ); } |
    REPLACE Identifier { sprite_init( _environment, $2, ((Environment *)_environment)->currentSprite, 0 )->name; } | 
    REPLACE Identifier OP sprite_flags CP { sprite_init( _environment, $2, ((Environment *)_environment)->currentSprite, $4 )->name;} |
    VERTICAL COMPRESS { sprite_compress_vertical_var( _environment, ((Environment *)_environment)->currentSprite ); } |
    VERTICAL EXPAND { sprite_expand_vertical_var( _environment, ((Environment *)_environment)->currentSprite ); };

sprite_definition_expression:
    sprite_definition_action_expression | 
    sprite_definition_action_expression sprite_definition_expression;

sprite_definition:
    direct_integer { ((Environment *)_environment)->currentSpriteNumber = $1; } sprite_definition_simple |
    expr { ((Environment *)_environment)->currentSprite = strdup($1); } sprite_definition_expression | 
    sprite_definition_all_simple;

/*-----------------------------------------------------------------------------
 ------------ BITMAP DEFINITION
 ----------------------------------------------------------------------------*/

bitmap_enable_resolution: 
    { bitmap_enable( _environment, 0, 0, 0 ); } | 
    HEIGHT const_expr { bitmap_enable( _environment, 0, -$2, $2 ); } | 
    OP integer_optional CP { bitmap_enable( _environment, 0, 0, $2 ); } | 
    OP integer_optional OP_COMMA integer_optional CP { bitmap_enable( _environment, $2, $4, 0 ); } | 
    OP integer_optional OP_COMMA integer_optional OP_COMMA integer_optional CP { bitmap_enable( _environment, $2, $4, $6 ); } |
    WIDTH const_expr { bitmap_enable( _environment, -$2, 0, $2 ); } ;

bitmap_definition_simple:
    AT direct_integer { bitmap_at( _environment, $2 ); }  | 
    bitmap_enable_resolution { } | 
    ENABLE bitmap_enable_resolution { } | 
    DISABLE { bitmap_disable( _environment ); } | 
    CLEAR { cls( _environment, NULL ); } | 
    CLEAR WITH direct_integer {
        Variable * parameter = variable_temporary( _environment, VT_COLOR, "()" );
        variable_store( _environment, parameter->name, $3 );
        cls( _environment, parameter->name );
    };

bitmap_definition_expression:
    AT expr { bitmap_at_var( _environment, $2 ); } | 
    CLEAR WITH expr { cls( _environment, $3 ); };

bitmap_definition:
    bitmap_definition_expression |
    bitmap_definition_simple;

/*-----------------------------------------------------------------------------
 ------------ TEXTNAP ENABLE DEFINITION
 ----------------------------------------------------------------------------*/

textmap_definition_simple:
    AT direct_integer {
        if ( $2 < 0 ) {
            CRITICAL_TEXTMAP_ADDRESS_NOT_VALID( $2 );
        }
        if ( $2 > 0xffff ) {
            CRITICAL_TEXTMAP_ADDRESS_NOT_VALID( $2 );
        }
        textmap_at( _environment, $2 );
    };

textmap_definition_expression:
    AT expr { textmap_at_var( _environment, $2 ); };

textmap_definition:
    textmap_definition_simple
  | textmap_definition_expression;

/*-----------------------------------------------------------------------------
 ------------ TEXT DEFINITION
 ----------------------------------------------------------------------------*/

text_definition_expression:
    AT expr OP_COMMA expr OP_COMMA expr { text_at( _environment, $2, $4, $6 ); } | 
    expr OP_COMMA expr OP_COMMA expr { text_at( _environment, $1, $3, $5 ); };

text_definition:
    text_definition_expression;

/*-----------------------------------------------------------------------------
 ------------ TILEMAP ENABLE DEFINITION
 ----------------------------------------------------------------------------*/

tilemap_enable_resolution: 
    { tilemap_enable( _environment, 0, 0, 0, 0, 0 ); } | 
    OP integer_optional CP { tilemap_enable( _environment, 0, 0, $2, 0, 0 ); } | 
    OP integer_optional OP_COMMA integer_optional CP { tilemap_enable( _environment, $2, $4, 0, 0, 0 ); } |
    OP integer_optional OP_COMMA integer_optional OP_COMMA integer_optional CP { tilemap_enable( _environment, $2, $4, $6, 0, 0 ); } |
    OP integer_optional OP_COMMA integer_optional OP_COMMA integer_optional OP_COMMA integer_optional OP_COMMA integer_optional CP { tilemap_enable( _environment, $2, $4, $6, $8, $10 ); };

tilemap_definition_simple:
    DISABLE { tilemap_disable( _environment ); } |
    ENABLE tilemap_enable_resolution { };

tilemap_definition:
    tilemap_definition_simple;

/*-----------------------------------------------------------------------------
 ------------ TILES DEFINITION
 ----------------------------------------------------------------------------*/

tiles_definition_simple:
    AT direct_integer { tiles_at( _environment, $2 ); } | 
    LOAD String tile_load_flags { tiles_load( _environment, $2, $3, NULL, -1 ); }; | 
    LOAD String TO Integer tile_load_flags { tiles_load( _environment, $2, $5, NULL, $4 ); };

tiles_definition_expression:
    AT expr { tiles_at_var( _environment, $2 ); };

tiles_definition:
    tiles_definition_expression |
    tiles_definition_simple;

/*-----------------------------------------------------------------------------
 ------------ FONT DEFINITION
 ----------------------------------------------------------------------------*/

font_definition_simple:
    LOAD String tile_load_flags { tiles_load( _environment, $2, $3 | FLAG_EXACT, NULL, -1 ); }; | 
    LOAD String TO Integer tile_load_flags { tiles_load( _environment, $2, $5 | FLAG_EXACT, NULL, $4 ); };

font_definition:
    font_definition_simple;

/*-----------------------------------------------------------------------------
 ------------ COLORMAP DEFINITION
 ----------------------------------------------------------------------------*/

colormap_definition_simple:
    AT direct_integer { colormap_at( _environment, $2 ); } | 
    CLEAR { colormap_clear( _environment ); } | 
    CLEAR WITH direct_integer ON direct_integer { colormap_clear_with( _environment, $3, $5 ); };

colormap_definition_expression:
    AT expr { colormap_at_var( _environment, $2 ); } | 
    CLEAR WITH expr ON expr { colormap_clear_with_vars( _environment, $3, $5 ); };

colormap_definition:
    colormap_definition_expression |
    colormap_definition_simple;

/*-----------------------------------------------------------------------------
 ------------ SCREEN DEFINITION
 ----------------------------------------------------------------------------*/

screen_definition_simple:
    COLUMNS direct_integer { screen_columns( _environment, $2 ); } |
    direct_integer { screen_mode( _environment, $1 ); } | 
    HORIZONTAL SCROLL direct_integer { screen_horizontal_scroll( _environment, $3 ); } |
    Integer { screen_mode( _environment, $1 ); } |  
    OFF { screen_off( _environment ); } | 
    ON { screen_on( _environment ); } | 
    OP_HASH const_expr OP_COMMA OP_HASH const_expr { screen_type_color_set( _environment, $2, $5 ); } | 
    ROWS direct_integer { screen_rows( _environment, $2 ); } | 
    VERTICAL SCROLL direct_integer { screen_vertical_scroll( _environment, $3 ); };

screen_definition_expression:
    COLUMNS expr { screen_columns_var( _environment, $2 ); } | 
    HORIZONTAL SCROLL expr { screen_horizontal_scroll_var( _environment, $3 ); } |
    ROWS expr { screen_rows_var( _environment, $2 ); } | 
    VERTICAL SCROLL expr { screen_vertical_scroll_var( _environment, $3 ); };

screen_definition:
    screen_definition_expression |
    screen_definition_simple;

/*-----------------------------------------------------------------------------
 ------------ GRAPHICS DEFINITION
 ----------------------------------------------------------------------------*/

graphics_definition_simple:
    const_expr { screen_mode( _environment, $1 ); }  | 
    OP_HASH Integer { screen_mode( _environment, $2 ); };

graphics_definition:
    graphics_definition_simple;

/*-----------------------------------------------------------------------------
 ------------ VARIABLE DEFINITION
 ----------------------------------------------------------------------------*/

var_definition_simple:
  Identifier as_datatype {
      variable_define( _environment, $1, $2, 0 );
      if ( $2 == VT_TYPE ) {
        variable_set_type( _environment, $1, ((struct _Environment *)_environment)->currentType->name );
      }
  } |
  Identifier as_datatype_suffix { variable_define( _environment, $1, $2, 0 ); } | 
  Identifier as_datatype OP_ASSIGN const_expr {
      variable_define( _environment, $1, $2, $4 );
      variable_store( _environment, $1, $4 );
  } | 
  Identifier ON Identifier { variable_define( _environment, $1, VT_BYTE, 0 ); } | 
  Identifier as_datatype_suffix ON Identifier {
      if ( $2 != 0 ) {
          variable_define( _environment, $1, $2, 0 );        
      } else {
          variable_define( _environment, $1, ((struct _Environment *)_environment)->defaultVariableType, 0 );
      }
  } | 
  Identifier ON Identifier OP_ASSIGN direct_integer {
      variable_define( _environment, $1, VT_BYTE, $5 );
      variable_store( _environment, $1, $5 );
  } | 
  Identifier ON Identifier OP_ASSIGN expr {
      Variable * v = variable_retrieve( _environment, $5 );
      Variable * d = variable_define( _environment, $1, v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  } | 
  Identifier as_datatype_suffix ON Identifier OP_ASSIGN expr {
      VariableType vt = $2;
      if ( vt == 0 ) {
        vt = ((struct _Environment *)_environment)->defaultVariableType;
      }
      Variable * v = variable_retrieve( _environment, $6 );
      Variable * d = variable_define( _environment, $1, vt, 0 );
      variable_move( _environment, v->name, d->name );
  };

var_definition_complex:
    var_definition_simple | 
    var_definition_simple OP_COMMA var_definition_complex;

var_definition:
    var_definition_complex;

/*-----------------------------------------------------------------------------
 ------------ RESTORE DEFINITION
 ----------------------------------------------------------------------------*/

restore_definition:
    { restore_label( _environment, NULL ); } |
    expr { restore_label( _environment, $1 ); };

/*-----------------------------------------------------------------------------
 ------------ (C)GOTO DEFINITION
 ----------------------------------------------------------------------------*/

cgoto_definition:
    expr { cgoto( _environment, $1 ); };

goto_definition:
    Identifier { goto_label( _environment, $1 ); } | 
    Integer { goto_number( _environment, $1 ); };

/*-----------------------------------------------------------------------------
 ------------ GOSUB DEFINITION
 ----------------------------------------------------------------------------*/

gosub_definition:
    Identifier { gosub_label( _environment, $1 ); } | 
    Integer { gosub_number( _environment, $1 ); };

/*-----------------------------------------------------------------------------
 ------------ POINT DEFINITION
 ----------------------------------------------------------------------------*/

point_definition_simple:
    AT OP direct_integer OP_COMMA direct_integer CP { point_at( _environment, $3, $5 ); };

point_definition_expression:
    AT OP optional_x OP_COMMA optional_y CP { point_at_vars( _environment, $3, $5 ); };

point_definition:
    point_definition_expression |
    point_definition_simple;

/*-----------------------------------------------------------------------------
 ------------ PLOT DEFINITION
 ----------------------------------------------------------------------------*/

plot_definition_expression:
    optional_x OP_COMMA optional_y OP_COMMA optional_expr {
        plot( _environment, $1, $3, resolve_color( _environment, $5 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $1, $3 );
    } | 
    optional_x OP_COMMA optional_y {
        plot( _environment, $1, $3, NULL, 0 );
        gr_locate( _environment, $1, $3 );
    };

plot_definition:
    plot_definition_expression;

plotr_definition_expression:
      expr OP_COMMA expr OP_COMMA optional_expr {
        Variable * x = origin_resolution_relative_transform_x( _environment, $1, 1 );
        Variable * y = origin_resolution_relative_transform_y( _environment, $3, 1 );
        plot( _environment, x->name, y->name, resolve_color( _environment, $5 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, x->name, y->name );
    } | 
    expr OP_COMMA expr {
        Variable * x = origin_resolution_relative_transform_x( _environment, $1, 1 );
        Variable * y = origin_resolution_relative_transform_y( _environment, $3, 1 );
        plot( _environment, x->name, y->name, NULL, 0 );
        gr_locate( _environment, x->name, y->name );
    };

plotr_definition:
    plotr_definition_expression;

/*-----------------------------------------------------------------------------
 ------------ FCIRCLE DEFINITION
 ----------------------------------------------------------------------------*/

fcircle_definition_expression:
    optional_x OP_COMMA optional_y OP_COMMA expr OP_COMMA expr OP_COMMA optional_expr {
        fellipse( _environment, $1, $3, $5, $7, resolve_color( _environment, $9 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $1, $3 );
    } | 
    optional_x OP_COMMA optional_y OP_COMMA expr OP_COMMA optional_expr {
        fcircle( _environment, $1, $3, $5, resolve_color( _environment, $7 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $1, $3 );
    } | 
    optional_x OP_COMMA optional_y OP_COMMA expr {
        fcircle( _environment, $1, $3, $5, NULL, 0 );
        gr_locate( _environment, $1, $3 );
    };

fcircle_definition:
    fcircle_definition_expression;

/*-----------------------------------------------------------------------------
 ------------ CIRCLE DEFINITION
 ----------------------------------------------------------------------------*/

circle_definition_expression:
    optional_x OP_COMMA optional_y OP_COMMA expr OP_COMMA expr OP_COMMA optional_expr {
        ellipse( _environment, $1, $3, $5, $7, resolve_color( _environment, $9 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $1, $3 );
    } | 
    optional_x OP_COMMA optional_y OP_COMMA expr OP_COMMA optional_expr {
        circle( _environment, $1, $3, $5, resolve_color( _environment, $7 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $1, $3 );
    } | 
    optional_x OP_COMMA optional_y OP_COMMA expr {
        circle( _environment, $1, $3, $5, NULL, 0 );
        gr_locate( _environment, $1, $3 );
    } | 
    FILL fcircle_definition_expression;

circle_definition:
    circle_definition_expression;

/*-----------------------------------------------------------------------------
 ------------ ELLIPSE DEFINITION
 ----------------------------------------------------------------------------*/

ellipse_definition_expression:
    optional_x OP_COMMA optional_y OP_COMMA expr OP_COMMA expr OP_COMMA optional_expr {
        ellipse( _environment, $1, $3, $5, $7, resolve_color( _environment, $9 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $1, $3 );
    } | 
    optional_x OP_COMMA optional_y OP_COMMA expr OP_COMMA expr {
        ellipse( _environment, $1, $3, $5, $7, NULL, 0 );
        gr_locate( _environment, $1, $3 );
    } | 
    FILL fellipse_definition_expression;

ellipse_definition:
    ellipse_definition_expression;

fellipse_definition_expression:
    optional_x OP_COMMA optional_y OP_COMMA expr OP_COMMA expr OP_COMMA optional_expr {
        fellipse( _environment, $1, $3, $5, $7, resolve_color( _environment, $9 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $1, $3 );
    } | 
    optional_x OP_COMMA optional_y OP_COMMA expr OP_COMMA expr {
        fellipse( _environment, $1, $3, $5, $7, NULL, 0 );
        gr_locate( _environment, $1, $3 );
    };

fellipse_definition:
    fellipse_definition_expression;

/*-----------------------------------------------------------------------------
 ------------ GET DEFINITION
 ----------------------------------------------------------------------------*/

get_message_definition_params: 
    {
        ((struct _Environment *)_environment)->dojoChannelName = NULL;
        ((struct _Environment *)_environment)->dojoObjectName = NULL;
    } | 
    OP_COMMA expr  {
        ((struct _Environment *)_environment)->dojoChannelName = NULL;
        ((struct _Environment *)_environment)->dojoObjectName = strdup( $2 );
    } | 
    OP_COMMA expr OP_COMMA expr {
        ((struct _Environment *)_environment)->dojoChannelName = strdup( $2 );
        ((struct _Environment *)_environment)->dojoObjectName = strdup( $4 );
    };

get_definition_expression:
    Identifier as_datatype_suffix_optional get_message_definition_params {
        if ( $2 != 0 ) {
            if ( $2 != VT_STRING && $2 != VT_DSTRING ) {
                CRITICAL_GET_NEED_STRING( $2 );
            }
        }
        Variable * variable = NULL;
        if ( variable_exists( _environment, $1 ) ) {
            variable = variable_retrieve( _environment, $1 );
        }
        if ( variable && variable->type == VT_IMAGE ) {
            Variable * zero = variable_temporary( _environment, VT_POSITION, "(zero)" );
            get_image( _environment, $1, zero->name, zero->name, NULL, NULL, NULL, NULL, 1 );
        } else if ( variable && variable->type == VT_DOJOKA ) {
            if ( !((struct _Environment *)_environment)->dojoObjectName ) {
                DOJO_GET_MESSAGE_MISSING_VARIABLE( );
            }
            dojo_get_message_inplace( _environment, $1, ((struct _Environment *)_environment)->dojoChannelName, ((struct _Environment *)_environment)->dojoObjectName );
        } else {
            variable = variable_retrieve_or_define( _environment, $1, VT_DSTRING, 0 );
            wait_key( _environment, 0 );
            Variable * p = variable_retrieve_or_define( _environment, $1, VT_DSTRING, 0 );
            Variable * k = inkey( _environment );
            variable_move( _environment, k->name, p->name );
        }
    } | 
    OP optional_x OP_COMMA optional_y CP OP_COMMA expr {
        get_image( _environment, $7, $2, $4, NULL, NULL, NULL, NULL, 0 );
        gr_locate( _environment, $2, $4 );
    } | 
    OP optional_x OP_COMMA optional_y CP OP_MINUS OP expr OP_COMMA expr CP OP_COMMA expr {
        get_image( _environment, $13, $2, $4, $8, $10, NULL, NULL, 0 );
        gr_locate( _environment, $2, $4 );
    } | 
    OP optional_x OP_COMMA optional_y CP OP_MINUS OP expr OP_COMMA expr CP OP_COMMA expr OP_COMMA G {
        get_image( _environment, $13, $2, $4, $8, $10, NULL, NULL, 1 );
        gr_locate( _environment, $2, $4 );
    } | 
    IMAGE expr FROM optional_x OP_COMMA optional_y  {
        get_image( _environment, $2, $4, $6, NULL, NULL, NULL, NULL, 1 );
        gr_locate( _environment, $4, $6 );
    } | 
    IMAGE expr frame expr FROM optional_x OP_COMMA optional_y  {
        get_image( _environment, $2, $6, $8, NULL, NULL, $4, NULL, 1 );
        gr_locate( _environment, $6, $8 );
    } | 
    IMAGE expr sequence_or_strip expr frame expr FROM optional_x OP_COMMA optional_y  {
        get_image( _environment, $2, $8, $10, NULL, NULL, $6, $4, 1 );
        gr_locate( _environment, $8, $10 );
    } | 
    BITMAP expr FROM optional_x OP_COMMA optional_y  {
        get_image( _environment, $2, $4, $6, NULL, NULL, NULL, NULL, 0 );
        gr_locate( _environment, $4, $6 );
    } | 
    BITMAP expr frame expr FROM optional_x OP_COMMA optional_y  {
        get_image( _environment, $2, $6, $8, NULL, NULL, $4, NULL, 0 );
        gr_locate( _environment, $6, $8 );
    } | 
    BITMAP expr sequence_or_strip expr frame expr FROM optional_x OP_COMMA optional_y  {
        get_image( _environment, $2, $8, $10, NULL, NULL, $6, $4, 1 );
        gr_locate( _environment, $8, $10 );
    };

get_definition:
    get_definition_expression;

/*-----------------------------------------------------------------------------
 ------------ SLICE DEFINITION
 ----------------------------------------------------------------------------*/

slice_source_optional: 
    {
        ((struct _Environment *)_environment)->sliceImageX = NULL;
        ((struct _Environment *)_environment)->sliceImageY = NULL;
    } |
    FROM expr OP_COMMA expr {
        ((struct _Environment *)_environment)->sliceImageX = $2;
        ((struct _Environment *)_environment)->sliceImageY = $4;
    };

slice_definition_expression:
    IMAGE expr frame expr slice_source_optional TO Identifier { slice_image( _environment, $2, $4, NULL, $7 ); } |
    IMAGE expr frame OP_HASH Identifier slice_source_optional TO Identifier {
        Variable * images = variable_retrieve( _environment, $2 );
        Variable * calculatedFrame = calculate_frame_by_type( _environment, images->originalTileset, $2, $5 );
        slice_image( _environment, $2, calculatedFrame->name, NULL, $8 );
    } | 
    IMAGE expr sequence_or_strip expr frame expr slice_source_optional TO Identifier { slice_image( _environment, $2, $6, $6, $9 ); } |
    IMAGE expr slice_source_optional TO Identifier { slice_image( _environment, $2, NULL, NULL, $5 ); };

slice_definition:
    slice_definition_expression;

/*-----------------------------------------------------------------------------
 ------------ PUT DEFINITION
 ----------------------------------------------------------------------------*/

put_action: 
    PSET { $$ = 0;} |
    PRESET { $$ = 1; } | 
    AND { $$ = 2; } | 
    OR { $$ = 3; } | 
    NOT { $$ = 4; };

put_definition_expression:
    OP optional_x OP_COMMA optional_y CP OP_COMMA expr {
        put_image( _environment, $7, $2, $4, NULL, NULL, NULL, NULL, FLAG_WITH_PALETTE );
        gr_locate( _environment, $2, $4 );
    } | 
    OP optional_x OP_COMMA optional_y CP OP_MINUS OP expr OP_COMMA expr CP OP_COMMA expr {
        put_image( _environment, $13, $2, $4, $8, $10, NULL, NULL, FLAG_WITH_PALETTE );
        gr_locate( _environment, $2, $4 );
    } | 
    OP optional_x OP_COMMA optional_y CP OP_MINUS OP expr OP_COMMA expr CP OP_COMMA expr OP_COMMA put_action {
        switch ( $15 )  {
            case 0: // PSET
                put_image( _environment, $13, $2, $4, $8, $10, NULL, NULL, FLAG_WITH_PALETTE );
                break;
            case 1: // PRESET
                put_image( _environment, $13, $2, $4, $8, $10, NULL, NULL, 0 );
                break;
            case 2: // AND
                if ( ! (((struct _Environment *)_environment)->blitAND ) ) {
                    ((struct _Environment *)_environment)->blitAND = strdup( "BLITAND" );
                    blit_define_begin_compound( _environment, "BLITAND" );  
                    int operand1 = cpu_blit_alloc_register( _environment );
                    blit_define_compound_operand_to_register( _environment, operand1, 0 );
                    int operand2 = cpu_blit_alloc_register( _environment );
                    blit_define_compound_operand_to_register( _environment, operand2, 1 );
                    int result = cpu_blit_alloc_register( _environment );
                    blit_define_compound_binary( _environment, 0, operand1, operand2, result );
                    cpu_blit_free_register( _environment, operand1 );
                    cpu_blit_free_register( _environment, operand2 );
                    blit_define_end_compound( _environment, result );
                }
                ((struct _Environment *)_environment)->blit.sourceCount = 1;
                ((struct _Environment *)_environment)->blit.sources[0] = strdup( $13 );
                blit_image( _environment, ((struct _Environment *)_environment)->blitAND, $2, $4, NULL, NULL, 0 );
                break;
            case 3: // OR
                if ( ! (((struct _Environment *)_environment)->blitOR ) ) {
                    ((struct _Environment *)_environment)->blitOR = strdup( "BLITOR" );
                    blit_define_begin_compound( _environment, "BLITOR" );  
                    int operand1 = cpu_blit_alloc_register( _environment );
                    blit_define_compound_operand_to_register( _environment, operand1, 0 );
                    int operand2 = cpu_blit_alloc_register( _environment );
                    blit_define_compound_operand_to_register( _environment, operand2, 1 );
                    int result = cpu_blit_alloc_register( _environment );
                    blit_define_compound_binary( _environment, 1, operand1, operand2, result );
                    cpu_blit_free_register( _environment, operand1 );
                    cpu_blit_free_register( _environment, operand2 );
                    blit_define_end_compound( _environment, result );
                }
                ((struct _Environment *)_environment)->blit.sourceCount = 1;
                ((struct _Environment *)_environment)->blit.sources[0] = strdup( $13 );
                blit_image( _environment, ((struct _Environment *)_environment)->blitOR, $2, $4, NULL, NULL, 0 );
                break;
            case 4: // NOT
                CRITICAL_PUT_NOT_NOT_SUPPORTED( $13 );
                break;
        }
        gr_locate( _environment, $2, $4 );
    } | 
    IMAGE expr AT optional_x OP_COMMA optional_y put_image_flags {
        $7 = $7 | FLAG_WITH_PALETTE;
        put_image( _environment, $2, $4, $6, NULL, NULL, NULL, NULL, $7 );
        gr_locate( _environment, $4, $6 );
    } | 
    IMAGE expr frame expr AT optional_x OP_COMMA optional_y put_image_flags {
        $9 = $9 | FLAG_WITH_PALETTE;
        put_image( _environment, $2, $6, $8, NULL, NULL, $4, NULL, $9 );
        gr_locate( _environment, $6, $8 );
    } | 
    IMAGE expr frame OP_HASH Identifier AT optional_x OP_COMMA optional_y put_image_flags {
        $10 = $10 | FLAG_WITH_PALETTE;
        Variable * images = variable_retrieve( _environment, $2 );
        Variable * calculatedFrame = calculate_frame_by_type( _environment, images->originalTileset, $2, $5 );
        put_image( _environment, $2, $7, $9, NULL, NULL, calculatedFrame->name, NULL, $10 );
        gr_locate( _environment, $7, $9 );
    } |
    IMAGE expr sequence_or_strip expr frame expr AT optional_x OP_COMMA optional_y put_image_flags {
        $11 = $11 | FLAG_WITH_PALETTE;
        put_image( _environment, $2, $8, $10, NULL, NULL, $6, $4, $11 );
        gr_locate( _environment, $8, $10 );
    } | 
    IMAGE expr put_image_flags {
        $3 = $3 | FLAG_WITH_PALETTE;
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        put_image( _environment, $2, implicitX->name, implicitY->name, NULL, NULL, NULL, NULL, $3 );
    } | 
    IMAGE expr frame expr put_image_flags {
        $5 = $5 | FLAG_WITH_PALETTE;
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        put_image( _environment, $2, implicitX->name, implicitY->name, NULL, NULL, $4, NULL, $5 );
    } | 
    IMAGE expr frame OP_HASH Identifier put_image_flags {
        $6 = $6 | FLAG_WITH_PALETTE;
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        Variable * images = variable_retrieve( _environment, $2 );
        Variable * calculatedFrame = calculate_frame_by_type( _environment, images->originalTileset, $2, $5 );
        put_image( _environment, $2, implicitX->name, implicitY->name, NULL, NULL, calculatedFrame->name, NULL, $6 );
    } | 
    IMAGE expr sequence_or_strip expr frame expr put_image_flags {
        $7 = $7 | FLAG_WITH_PALETTE;
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        put_image( _environment, $2, implicitX->name, implicitY->name, NULL, NULL, $6, $4, $7 );
    } |
    BITMAP expr AT optional_x OP_COMMA optional_y put_image_flags {
        put_image( _environment, $2, $4, $6, NULL, NULL, NULL, NULL, $7 );
        gr_locate( _environment, $4, $6 );
    } | 
    BITMAP expr frame expr AT optional_x OP_COMMA optional_y put_image_flags {
        put_image( _environment, $2, $6, $8, NULL, NULL, $4, NULL, $9 );
        gr_locate( _environment, $6, $8 );
    } | 
    BITMAP expr frame OP_HASH Identifier AT optional_x OP_COMMA optional_y put_image_flags {
        Variable * images = variable_retrieve( _environment, $2 );
        Variable * calculatedFrame = calculate_frame_by_type( _environment, images->originalTileset, $2, $5 );
        put_image( _environment, $2, $7, $9, NULL, NULL, calculatedFrame->name, NULL, $10 );
        gr_locate( _environment, $7, $9 );
    } | 
    BITMAP expr sequence_or_strip expr frame expr AT optional_x OP_COMMA optional_y put_image_flags {
        put_image( _environment, $2, $8, $10, NULL, NULL, $6, $4, $11 );
        gr_locate( _environment, $8, $10 );
    } | 
    BITMAP expr put_image_flags {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        put_image( _environment, $2, implicitX->name, implicitY->name, NULL, NULL, NULL, NULL, $3 );
    } | 
    BITMAP expr frame expr put_image_flags {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        put_image( _environment, $2, implicitX->name, implicitY->name, NULL, NULL, $4, NULL, $5 );
    } | 
    BITMAP expr frame OP_HASH Identifier put_image_flags {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        Variable * images = variable_retrieve( _environment, $2 );
        Variable * calculatedFrame = calculate_frame_by_type( _environment, images->originalTileset, $2, $5 );
        put_image( _environment, $2, implicitX->name, implicitY->name, NULL, NULL, calculatedFrame->name, NULL, $6 );
    } | 
    BITMAP expr sequence_or_strip expr frame expr put_image_flags {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        put_image( _environment, $2, implicitX->name, implicitY->name, NULL, NULL, $6, $4, $7 );
    } | 
    MOVIE expr {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        
        ParamsPutMovie params;
        params.movie = strdup( $2 );
        params.x1 = implicitX->name;
        params.y1 = implicitY->name;
        
        put_movie( _environment, &params );
    } | 
    MOVIE expr AT optional_x OP_COMMA optional_y {
        ParamsPutMovie params;
        params.movie = strdup( $2 );
        params.x1 = $4;
        params.y1 = $6;
        put_movie( _environment, &params );
        gr_locate( _environment, $4, $6 );
    } | 
    TILE expr AT optional_x OP_COMMA optional_y { put_tile( _environment, $2, $4, $6, NULL, NULL ); } |
    TILEMAP Identifier pad_optional put_image_flags { put_tilemap_vars( _environment, $2, $4 | FLAG_WITH_PALETTE, NULL, NULL, NULL, $3 ); } | 
    TILEMAP Identifier pad_optional LAYER expr put_image_flags { put_tilemap_vars( _environment, $2, $6 | FLAG_WITH_PALETTE, NULL, NULL, $5, $3 ); } | 
    TILEMAP Identifier pad_optional FROM expr OP_COMMA expr put_image_flags { put_tilemap_vars( _environment, $2, $8 | FLAG_WITH_PALETTE, $5, $7, NULL, $3 ); } | 
    TILEMAP Identifier pad_optional LAYER expr FROM expr OP_COMMA expr put_image_flags { put_tilemap_vars( _environment, $2, $10 | FLAG_WITH_PALETTE, $7, $9, $5, $3 ); };

put_definition:
    put_definition_expression;

/*-----------------------------------------------------------------------------
 ------------ BLIT
 ----------------------------------------------------------------------------*/

blit_unary_op:
    COPY { $$ = 1 << ((struct _Environment *)_environment)->currentModeBW; } | 
    IGNORE { $$ = ( 1 << ((struct _Environment *)_environment)->currentModeBW ) + 2; } | 
    INVERSE { $$ = ( 1 << ((struct _Environment *)_environment)->currentModeBW ) + 1; } | 
    THRESHOLD { $$ = ( 1 << ((struct _Environment *)_environment)->currentModeBW ) + 3; } |
    VALUE const_expr { $$ = $2 & ( ( 1 << ((struct _Environment *)_environment)->currentModeBW ) - 1 ); };

blit_binary_op:
    A { $$ = 3; } | 
    AND { $$ = 0; } | 
    B { $$ = 4; } | 
    COPY A { $$ = 3; } | 
    COPY B { $$ = 4; } | 
    MASKED { $$ = 5; } |
    OR { $$ = 1; } | 
    XOR { $$ = 2; };

blit_operand:
    DESTINATION { $$ = 0 ; } |
    SOURCE { $$ = 1; } | 
    SOURCE Integer { $$ = $2; };

blit_sources:
    Identifier { ((struct _Environment *)_environment)->blit.sources[((struct _Environment *)_environment)->blit.sourceCount++] = strdup( $1 ); } | 
    Identifier { ((struct _Environment *)_environment)->blit.sources[((struct _Environment *)_environment)->blit.sourceCount++] = strdup( $1 ); } OP_COMMA blit_sources;

blit_expression:
    OP blit_operand CP {
        // Take a free register for operand
        int operand = cpu_blit_alloc_register( _environment );
        blit_define_compound_operand_to_register( _environment, operand, $2 );
        // Take a free register for result
        int result = cpu_blit_alloc_register( _environment );
        // U ( operand ) -> result
        blit_define_compound_unary( _environment, 1 << ((struct _Environment *)_environment)->currentModeBW /* COPY */, operand, result );
        // Free operand
        cpu_blit_free_register( _environment, operand );
        // outline3( "; ( O%2.2x (R%2.2X) ) -> R%2.2x", $2, operand, result );
        $$ = result;

    } | 
    OP blit_unary_op blit_operand CP {
        // Take a free register for operand
        int operand = cpu_blit_alloc_register( _environment );
        blit_define_compound_operand_to_register( _environment, operand, $3 );
        // Take a free register for result
        int result = cpu_blit_alloc_register( _environment );
        // U ( operand ) -> result
        blit_define_compound_unary( _environment, $2, operand, result );
        // Free operand
        cpu_blit_free_register( _environment, operand );
        // outline4( "; ( [%2.2x] O%2.2x (R%2.2x) ) -> R%2.2x", $2, $3, operand, result );
        $$ = result;
    } | 
    OP blit_operand blit_binary_op blit_operand CP {
        // Take a free register for operand1
        int operand1 = cpu_blit_alloc_register( _environment );
        blit_define_compound_operand_to_register( _environment, operand1, $2 );
        // Take a free register for operand2
        int operand2 = cpu_blit_alloc_register( _environment );
        blit_define_compound_operand_to_register( _environment, operand2, $4 );
        // Take a free register for result
        int result = cpu_blit_alloc_register( _environment );
        // B ( operand1, operand2 ) -> result
        blit_define_compound_binary( _environment, $3, operand1, operand2, result );
        // Free operand1
        cpu_blit_free_register( _environment, operand1 );
        // Free operand2
        cpu_blit_free_register( _environment, operand2 );
        // outline6( "; ( O%2.2x R%2.2x [%2.2x] O%2.2x R%2.2x ) -> R%2.2x", $2, operand1, $3, $4, operand2, result );
        $$ = result;
    };

blit_compounded:
    blit_expression {
        // outline2( "; R%2.2x -> R%2.2x", $1, $1 );
        // Pass result register
        $$ = $1;
    } | 
    OP blit_compounded CP {
        // outline2( "; (R%2.2x) -> R%2.2x", $2, $2 );
        // Pass result register
        $$ = $2;
    } | 
    OP blit_unary_op blit_compounded CP {
        // Take a free register for result
        int result = cpu_blit_alloc_register( _environment );
        // B ( result1, result2 ) -> result
        blit_define_compound_unary( _environment, $2, $3, result );
        // Pass result register
        // outline3( "; ( [%2.2x] R%2.2x) -> R%2.2x", $2, $3, result );
        // Free operand
        cpu_blit_free_register( _environment, $3 );
        $$ = result;
    } | 
    OP blit_compounded blit_binary_op blit_compounded CP {
        // Take a free register for result
        int result = cpu_blit_alloc_register( _environment );
        // B ( result1, result2 ) -> result
        blit_define_compound_binary( _environment, $3, $2, $4, result );
        // Pass result register
        // outline4( "; ( R%2.2x [%2.2x] R%2.2x) -> R%2.2x", $2, $3, $4, result );
        // Free operands
        cpu_blit_free_register( _environment, $2 );
        // Free operands
        cpu_blit_free_register( _environment, $4 );
        $$ = result;
    };

blit_definition_define_expression: 
    Identifier AS {
        //printf( "\n\n%s\n", $1 );
        blit_define_begin_compound( _environment, $1 );  
    } blit_compounded {
        //printf( "R%2.2x -> final\n\n", $4 );
        blit_define_end_compound( _environment, $4 );
      } | 
    Identifier op_assign blit_unary_op OP_COMMA blit_unary_op OP_COMMA blit_binary_op OP_COMMA blit_unary_op OP_COMMA blit_unary_op OP_COMMA blit_binary_op OP_COMMA blit_unary_op {
        blit_define( _environment, $1, $3, $5, $7, $9, $11, $13, $15 );
      };

blit_definition_expression:
    blit_definition_define_expression
    |  image_or_images blit_sources AT optional_x OP_COMMA optional_y WITH Identifier blit_image_flags {
        $9 = $9 | FLAG_WITH_PALETTE;
        blit_image( _environment, $8, $4, $6, NULL, NULL, $9 );
        gr_locate( _environment, $4, $6 );
    }
    |  image_or_images blit_sources frame expr AT optional_x OP_COMMA optional_y WITH Identifier blit_image_flags {
        $11 = $11 | FLAG_WITH_PALETTE;
        blit_image( _environment, $10, $6, $8, $4, NULL, $11 );
        gr_locate( _environment, $6, $8 );
    }
    |  image_or_images blit_sources SEQUENCE expr frame expr AT optional_x OP_COMMA optional_y WITH Identifier blit_image_flags {
        $13 = $13 | FLAG_WITH_PALETTE;
        blit_image( _environment, $12, $8, $10, $6, $4, $13 );
        gr_locate( _environment, $8, $10 );
    }
    | image_or_images blit_sources WITH Identifier blit_image_flags {
        $5 = $5 | FLAG_WITH_PALETTE;
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        blit_image( _environment, $4, implicitX->name, implicitY->name, NULL, NULL, $5 );
    }
    | image_or_images blit_sources frame expr WITH Identifier blit_image_flags {
        $7 = $7 | FLAG_WITH_PALETTE;
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        blit_image( _environment, $6, implicitX->name, implicitY->name, $4, NULL, $7 );
    }
    | image_or_images blit_sources SEQUENCE expr frame expr WITH Identifier blit_image_flags {
        $9 = $9 | FLAG_WITH_PALETTE;
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        blit_image( _environment, $8, implicitX->name, implicitY->name, $6, $4, $9 );
    }
    |
      bitmap_or_bitmaps blit_sources AT optional_x OP_COMMA optional_y WITH Identifier blit_image_flags {
        blit_image( _environment, $8, $4, $6, NULL, NULL, $9 );
        gr_locate( _environment, $4, $6 );
    }
    | bitmap_or_bitmaps blit_sources frame expr AT optional_x OP_COMMA optional_y WITH Identifier blit_image_flags {
        blit_image( _environment, $10, $6, $8, $4, NULL, $11 );
        gr_locate( _environment, $6, $8 );
    }
    | bitmap_or_bitmaps blit_sources SEQUENCE expr frame expr AT optional_x OP_COMMA optional_y WITH Identifier blit_image_flags {
        blit_image( _environment, $12, $8, $10, $6, $4, $13 );
        gr_locate( _environment, $8, $10 );
    }
    | bitmap_or_bitmaps blit_sources WITH Identifier blit_image_flags {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        blit_image( _environment, $4, implicitX->name, implicitY->name, NULL, NULL, $5 );
    }
    | bitmap_or_bitmaps blit_sources frame expr WITH Identifier blit_image_flags {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        blit_image( _environment, $6, implicitX->name, implicitY->name, $4, NULL, $7 );
    }
    | bitmap_or_bitmaps blit_sources SEQUENCE expr frame expr WITH Identifier blit_image_flags {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        blit_image( _environment, $8, implicitX->name, implicitY->name, $6, $4, $9 );
    }
    ;

blit_definition:
    blit_definition_expression;

/*-----------------------------------------------------------------------------
 ------------ MOVE DEFINITION
 ----------------------------------------------------------------------------*/

move_definition_expression:
    TILE expr AT optional_x OP_COMMA optional_y { move_tile( _environment, $2, $4, $6 ); } | 
    Identifier WITH Identifier { move( _environment, $1, $3, NULL, NULL, NULL ); } | 
    Identifier WITH Identifier SYNC Identifier { move( _environment, $1, $3, NULL, NULL, $5 ); } | 
    Identifier TO expr OP_COMMA expr WITH Identifier { move( _environment, $1, $7, $3, $5, NULL ); } | 
    Identifier TO expr OP_COMMA expr WITH Identifier SYNC Identifier { move( _environment, $1, $7, $3, $5, $9 ); } | 
    const_expr OP_COMMA const_expr as_datatype {
        if ( !((struct _Environment *)_environment)->insideCopperList ) {
            CRITICAL_COPPER_LIST_NOT_OPENED( );
        }
        copper_move( _environment, $1, $3, $4 );
    };

move_definition:
    move_definition_expression;

/*-----------------------------------------------------------------------------
 ------------ LINE DEFINITION
 ----------------------------------------------------------------------------*/

line_mode: 
    { $$ = 0; } | 
    PSET { $$ = 0; } | 
    PRESET {$$ = 1; };

box_mode: 
    { $$ = 0; } | 
    B { $$ = 1; } | 
    BF { $$ = 2; };

line_definition_expression:
    OP expr OP_COMMA expr CP OP_MINUS OP expr OP_COMMA expr CP {
        draw( _environment, $2, $4, $8, $10, NULL, 0 );
        gr_locate( _environment, $8, $10 );
    }
    | OP expr OP_COMMA expr CP OP_MINUS OP expr OP_COMMA expr CP OP_COMMA expr {
        Variable * zero = variable_temporary( _environment, VT_BYTE, "(zero)" );
        variable_store( _environment, zero->name, 0 );
        draw( _environment, $2, $4, $8, $10, resolve_color( _environment, $13 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $8, $10 );
    }
    | OP_MINUS OP expr OP_COMMA expr CP {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        Variable * zero = variable_temporary( _environment, VT_BYTE, "(zero)" );
        variable_store( _environment, zero->name, 0 );
        draw( _environment, implicitX->name, implicitY->name, $3, $5, NULL, 0 );
        gr_locate( _environment, $3, $5 );
    }
    | OP_MINUS OP expr OP_COMMA expr CP OP_COMMA expr {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        Variable * zero = variable_temporary( _environment, VT_BYTE, "(zero)" );
        variable_store( _environment, zero->name, 0 );
        draw( _environment, implicitX->name, implicitY->name, $3, $5, resolve_color( _environment, $8 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $3, $5 );
    }
    | OP expr OP_COMMA expr CP OP_MINUS OP expr OP_COMMA expr CP OP_COMMA line_mode OP_COMMA box_mode {
        Variable * zero = variable_temporary( _environment, VT_BYTE, "(zero)" );
        variable_store( _environment, zero->name, 0 );
        switch( $15 ) {
            case 0:
                draw( _environment, $2, $4, $8, $10, $13 == 0 ? NULL : color_get_vars( _environment, zero->name )->name, 0 );
                break;
            case 1:
                box( _environment, $2, $4, $8, $10, $13 == 0 ? NULL : color_get_vars( _environment, zero->name )->name, 0 );
                break;
            case 2:
                bar( _environment, $2, $4, $8, $10, $13 == 0 ? NULL : color_get_vars( _environment, zero->name )->name, 0 );
                break;
        }
        gr_locate( _environment, $8, $10 );
    }
    | OP_MINUS OP expr OP_COMMA expr CP OP_COMMA line_mode OP_COMMA box_mode {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        Variable * zero = variable_temporary( _environment, VT_BYTE, "(zero)" );
        variable_store( _environment, zero->name, 0 );
        switch( $10 ) {
            case 0:
                draw( _environment, implicitX->name, implicitY->name, $3, $5, $8 == 0 ? NULL : color_get_vars( _environment, zero->name )->name, 0 );
                break;
            case 1:
                box( _environment, implicitX->name, implicitY->name, $3, $5, $8 == 0 ? NULL : color_get_vars( _environment, zero->name )->name, 0 );
                break;
            case 2:
                bar( _environment, implicitX->name, implicitY->name, $3, $5, $8 == 0 ? NULL : color_get_vars( _environment, zero->name )->name, 0 );
                break;
        }
        gr_locate( _environment, $3, $5 );
    }
    | optional_x_or_string OP_COMMA optional_y TO optional_x OP_COMMA optional_y OP_COMMA optional_expr {
        draw( _environment, $1, $3, $5, $7, resolve_color( _environment, $9 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $5, $7 );
    }
    | optional_x_or_string OP_COMMA optional_y TO optional_x OP_COMMA optional_y  {
        draw( _environment, $1, $3, $5, $7, NULL, 0 );
        gr_locate( _environment, $5, $7 );
    }
    | TO optional_x OP_COMMA optional_y OP_COMMA optional_expr {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        draw( _environment, implicitX->name, implicitY->name, $2, $4, resolve_color( _environment, $6 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $2, $4 );
    }
    | TO optional_x OP_COMMA optional_y  {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        draw( _environment, implicitX->name, implicitY->name, $2, $4, NULL, 0 );
        gr_locate( _environment, $2, $4 );
    }
    | INPUT {
        ((Environment *)_environment)->lineInput = 1;
    } input_definition
    ;

line_definition:
    line_definition_expression;

/*-----------------------------------------------------------------------------
 ------------ DRAW DEFINITION
 ----------------------------------------------------------------------------*/

draw_optional_string2:
    OP_COMMA expr OP_COMMA expr { draw_tsb_string( _environment, ((Environment *)_environment)->optionalX, ((Environment *)_environment)->optionalY, $2, resolve_color( _environment, $4 ), ((Environment *)_environment)->colorImplicit ); } | 
    TO optional_x OP_COMMA optional_y OP_COMMA optional_expr {
        draw( _environment, ((Environment *)_environment)->optionalX, ((Environment *)_environment)->optionalY, $2, $4, resolve_color( _environment, $6 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $2, $4 );
    } | 
    TO optional_x OP_COMMA optional_y  {
        draw( _environment, ((Environment *)_environment)->optionalX, ((Environment *)_environment)->optionalY, $2, $4, NULL, 0 );
        gr_locate( _environment, $2, $4 );
    };

draw_optional_string:
    {
        draw_string( _environment, ((Environment *)_environment)->optionalX );
    } | 
    OP_COMMA optional_y {
         ((Environment *)_environment)->optionalY = $2;
    } draw_optional_string2;

draw_definition_expression:
    OP expr OP_COMMA expr CP OP_MINUS OP expr OP_COMMA expr CP {
        draw( _environment, $2, $4, $8, $10, NULL, 0 );
        gr_locate( _environment, $8, $10 );
    } | 
    OP expr OP_COMMA expr CP OP_MINUS OP expr OP_COMMA expr CP OP_COMMA line_mode {
        Variable * zero = variable_temporary( _environment, VT_BYTE, "(zero)" );
        variable_store( _environment, zero->name, 0 );
        draw( _environment, $2, $4, $8, $10, $13 == 0 ? NULL : color_get_vars( _environment, zero->name )->name, 0 );
        gr_locate( _environment, $8, $10 );
    } | 
    OP expr OP_COMMA expr CP OP_MINUS OP expr OP_COMMA expr CP OP_COMMA expr {
        Variable * zero = variable_temporary( _environment, VT_BYTE, "(zero)" );
        variable_store( _environment, zero->name, 0 );
        draw( _environment, $2, $4, $8, $10, resolve_color( _environment, $13 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $8, $10 );
    } | 
    OP expr OP_COMMA expr CP OP_MINUS OP expr OP_COMMA expr CP OP_COMMA line_mode OP_COMMA box_mode {
        Variable * zero = variable_temporary( _environment, VT_BYTE, "(zero)" );
        variable_store( _environment, zero->name, 0 );
        switch( $15 ) {
            case 0:
                draw( _environment, $2, $4, $8, $10, $13 == 0 ? NULL : color_get_vars( _environment, zero->name )->name, 0 );
                break;
            case 1:
                box( _environment, $2, $4, $8, $10, $13 == 0 ? NULL : color_get_vars( _environment, zero->name )->name, 0 );
                break;
            case 2:
                bar( _environment, $2, $4, $8, $10, $13 == 0 ? NULL : color_get_vars( _environment, zero->name )->name, 0 );
                break;
        }
        gr_locate( _environment, $8, $10 );
    } | 
    optional_x_or_string {
        ((Environment *)_environment)->optionalX = $1;
    } draw_optional_string | 
    TO optional_x OP_COMMA optional_y OP_COMMA optional_expr {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        draw( _environment, implicitX->name, implicitY->name, $2, $4, resolve_color( _environment, $6 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $2, $4 );
    } | 
    TO optional_x OP_COMMA optional_y  {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        draw( _environment, implicitX->name, implicitY->name, $2, $4, NULL, 0 );
        gr_locate( _environment, $2, $4 );
    };

draw_tile_definition_expression:
    expr COLUMN expr OP_COMMA expr TO expr  { draw_tile_column( _environment, $1, $3, $5, $7, NULL ); } |
    expr COLUMN expr OP_COMMA expr TO expr OP_COMMA optional_expr { draw_tile_column( _environment, $1, $3, $5, $7, $9 ); } |
    expr ROW expr OP_COMMA expr TO expr  { draw_tile_row( _environment, $1, $3, $5, $7, NULL ); } | 
    expr ROW expr OP_COMMA expr TO expr OP_COMMA optional_expr { draw_tile_row( _environment, $1, $3, $5, $7, $9 ); };

draw_definition:
    draw_definition_expression;

draw_tile_definition: 
    draw_tile_definition_expression;

/*-----------------------------------------------------------------------------
 ------------ BOX DEFINITION
 ----------------------------------------------------------------------------*/

box_definition_expression:
    optional_x OP_COMMA optional_y TO optional_x OP_COMMA optional_y  {
        box( _environment, $1, $3, $5, $7, NULL, 0 );
        gr_locate( _environment, $5, $7 );
    } | 
    optional_x OP_COMMA optional_y TO optional_x OP_COMMA optional_y OP_COMMA optional_expr {
        box( _environment, $1, $3, $5, $7, resolve_color( _environment, $9 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $5, $7 );
    } | 
    TO optional_x OP_COMMA optional_y  {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        box( _environment, implicitX->name, implicitY->name, $2, $4, NULL, 0 );
        gr_locate( _environment, $2, $4 );
    } |
    TO optional_x OP_COMMA optional_y OP_COMMA optional_expr {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        box( _environment, implicitX->name, implicitY->name, $2, $4, resolve_color( _environment, $6 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $2, $4 );
    };

box_definition:
    box_definition_expression;

/*-----------------------------------------------------------------------------
 ------------ REC DEFINITION
 ----------------------------------------------------------------------------*/

rec_definition_expression:
    mandatory_x OP_COMMA mandatory_y TO expr OP_COMMA expr  {
        Variable * x2 = variable_add( _environment, $1, variable_retrieve_or_define( _environment, $5, VT_POSITION, 0 )->name );
        Variable * x2p = variable_temporary( _environment, VT_POSITION, "(x)" );
        variable_move( _environment, x2->name, x2p->name );
        variable_decrement( _environment, x2p->name );        
        Variable * y2 = variable_add( _environment, $3, variable_retrieve_or_define( _environment, $7, VT_POSITION, 0 )->name );
        Variable * y2p = variable_temporary( _environment, VT_POSITION, "(y)" );
        variable_move( _environment, y2->name, y2p->name );
        variable_decrement( _environment, y2p->name );
        box( _environment, $1, $3, x2->name, y2p->name, resolve_color( _environment, NULL ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, x2->name, y2p->name );
    } | 
    mandatory_x OP_COMMA mandatory_y TO expr OP_COMMA expr OP_COMMA expr  {
        Variable * x2 = variable_add( _environment, $1, variable_retrieve_or_define( _environment, $5, VT_POSITION, 0 )->name );
        Variable * x2p = variable_temporary( _environment, VT_POSITION, "(x)" );
        variable_move( _environment, x2->name, x2p->name );
        variable_decrement( _environment, x2p->name );        
        Variable * y2 = variable_add( _environment, $3, variable_retrieve_or_define( _environment, $7, VT_POSITION, 0 )->name );
        Variable * y2p = variable_temporary( _environment, VT_POSITION, "(y)" );
        variable_move( _environment, y2->name, y2p->name );
        variable_decrement( _environment, y2p->name );
        box( _environment, $1, $3, x2->name, y2p->name, resolve_color( _environment, $9 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, x2->name, y2p->name );
    } |
    mandatory_x OP_COMMA mandatory_y OP_COMMA expr OP_COMMA expr OP_COMMA expr  {
        Variable * x2 = variable_add( _environment, $1, variable_retrieve_or_define( _environment, $5, VT_POSITION, 0 )->name );
        Variable * x2p = variable_temporary( _environment, VT_POSITION, "(x)" );
        variable_move( _environment, x2->name, x2p->name );
        variable_decrement( _environment, x2p->name );        
        Variable * y2 = variable_add( _environment, $3, variable_retrieve_or_define( _environment, $7, VT_POSITION, 0 )->name );
        Variable * y2p = variable_temporary( _environment, VT_POSITION, "(y)" );
        variable_move( _environment, y2->name, y2p->name );
        variable_decrement( _environment, y2p->name );
        box( _environment, $1, $3, x2->name, y2p->name, resolve_color( _environment, $9 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, x2->name, y2p->name );
    };

rec_definition:
    rec_definition_expression;

/*-----------------------------------------------------------------------------
 ------------ CONSOLE DEFINITION
 ----------------------------------------------------------------------------*/

console_definition_simple:
    OFF { console( _environment, 0, 0, ((struct _Environment *)_environment)->screenTilesWidth-1, ((struct _Environment *)_environment)->screenTilesHeight-1 ); } | 
    OP_HASH const_expr OP_COMMA OP_HASH const_expr OP_COMMA OP_HASH const_expr OP_COMMA OP_HASH const_expr { console( _environment, $2, $5, $8, $11 ); } |
    OP_HASH const_expr OP_COMMA OP_HASH const_expr TO OP_HASH const_expr OP_COMMA OP_HASH const_expr { console( _environment, $2, $5, $8, $11 ); } |
    RESTORE OP_HASH const_expr { console_restore( _environment, $3 ); } |
    SAVE OP_HASH const_expr { console_save( _environment, $3 ); } |
    USE OP_HASH const_expr { console_restore( _environment, $3 ); };

console_definition_expression:
    expr OP_COMMA expr OP_COMMA expr OP_COMMA expr { console_vars( _environment, $1, $3, $5, $7 ); } |
    expr OP_COMMA expr TO expr OP_COMMA expr { console_vars( _environment, $1, $3, $5, $7 ); } | 
    RESTORE expr { console_restore_vars( _environment, $2 ); } |
    SAVE expr { console_save_vars( _environment, $2 ); } |
    USE expr { console_restore_vars( _environment, $2 ); };

console_definition:
    console_definition_expression |
    console_definition_simple;

/*-----------------------------------------------------------------------------
 ------------ BAR DEFINITION
 ----------------------------------------------------------------------------*/

bar_definition_expression:
    optional_x OP_COMMA optional_y OP_COMMA optional_x OP_COMMA optional_y OP_COMMA optional_expr {
        bar( _environment, $1, $3, $5, $7, resolve_color( _environment, $9 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $5, $7 );
    } | 
    optional_x OP_COMMA optional_y TO optional_x OP_COMMA optional_y OP_COMMA optional_expr {
        bar( _environment, $1, $3, $5, $7, resolve_color( _environment, $9 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $5, $7 );
    } | 
    optional_x OP_COMMA optional_y TO optional_x OP_COMMA optional_y  {
        bar( _environment, $1, $3, $5, $7, NULL, 0 );
        gr_locate( _environment, $5, $7 );
    } | 
    TO optional_x OP_COMMA optional_y OP_COMMA optional_expr {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        bar( _environment, implicitX->name, implicitY->name, $2, $4, resolve_color( _environment, $6 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $2, $4 );
    } | 
    TO optional_x OP_COMMA optional_y  {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        bar( _environment, implicitX->name, implicitY->name, $2, $4, NULL, 0 );
        gr_locate( _environment, $2, $4 );
    };

bar_definition:
    bar_definition_expression;

/*-----------------------------------------------------------------------------
 ------------ BLOCK DEFINITION
 ----------------------------------------------------------------------------*/

block_definition_expression:
    mandatory_x OP_COMMA mandatory_y OP_COMMA mandatory_x OP_COMMA mandatory_y OP_COMMA expr  {
        bar( _environment, $1, $3, $5, $7, resolve_color( _environment, $9 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $5, $7 );
    };

block_definition:
    block_definition_expression;

/*-----------------------------------------------------------------------------
 ------------ CLIP DEFINITION
 ----------------------------------------------------------------------------*/

clip_definition_expression:
    { clip( _environment, NULL, NULL, NULL, NULL ); } |
    expr OP_COMMA expr TO expr OP_COMMA expr { clip( _environment, $1, $3, $5, $7 ); };

clip_definition:
    clip_definition_expression;

/*-----------------------------------------------------------------------------
 ------------ POLYLINE DEFINITION
 ----------------------------------------------------------------------------*/

polyline_definition_expression_continue:
    TO optional_x OP_COMMA optional_y OP_COMMA optional_expr {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        draw( _environment, implicitX->name, implicitY->name, $2, $4, resolve_color( _environment, $6 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $2, $4 );
    } | 
    TO optional_x OP_COMMA optional_y  {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        draw( _environment, implicitX->name, implicitY->name, $2, $4, NULL, 0 );
        gr_locate( _environment, $2, $4 );
    } polyline_definition_expression_continue | 
    TO optional_x OP_COMMA optional_y  {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        draw( _environment, implicitX->name, implicitY->name, $2, $4, NULL, 0 );
        gr_locate( _environment, $2, $4 );
    };

polyline_definition_expression:
    optional_x OP_COMMA optional_y TO optional_x OP_COMMA optional_y OP_COMMA optional_expr {
        draw( _environment, $1, $3, $5, $7, resolve_color( _environment, $9 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $5, $7 );
    } | 
    optional_x OP_COMMA optional_y TO optional_x OP_COMMA optional_y  {
        draw( _environment, $1, $3, $5, $7, NULL, 0 );
        gr_locate( _environment, $5, $7 );
    } | 
    optional_x OP_COMMA optional_y TO optional_x OP_COMMA optional_y  {
        draw( _environment, $1, $3, $5, $7, NULL, 0 );
        gr_locate( _environment, $5, $7 );
    } polyline_definition_expression_continue | 
    TO optional_x OP_COMMA optional_y OP_COMMA optional_expr {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        draw( _environment, implicitX->name, implicitY->name, $2, $4, resolve_color( _environment, $6 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $2, $4 );
    } | 
    TO optional_x OP_COMMA optional_y  {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        draw( _environment, implicitX->name, implicitY->name, $2, $4, NULL, 0 );
        gr_locate( _environment, $2, $4 );
    } | 
    TO optional_x OP_COMMA optional_y  {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        draw( _environment, implicitX->name, implicitY->name, $2, $4, NULL, 0 );
        gr_locate( _environment, $2, $4 );
    } polyline_definition_expression_continue;

polyline_definition:
    polyline_definition_expression;

/*-----------------------------------------------------------------------------
 ------------ TRIANGLE DEFINITION
 ----------------------------------------------------------------------------*/

triangle_definition:
    optional_x OP_COMMA optional_y TO mandatory_x OP_COMMA mandatory_y TO mandatory_x OP_COMMA mandatory_y {
        draw( _environment, $1, $3, $5, $7, NULL, 0 );
        draw( _environment, $5, $7, $9, $11, NULL, 0 );
        draw( _environment, $9, $11, $1, $3, NULL, 0 );
        gr_locate( _environment, $1, $3 );
    } | 
    optional_x OP_COMMA optional_y TO mandatory_x OP_COMMA mandatory_y TO mandatory_x OP_COMMA mandatory_y OP_COMMA expr {
        draw( _environment, $1, $3, $5, $7, resolve_color( _environment, $13), 0 );
        draw( _environment, $5, $7, $9, $11, resolve_color( _environment, $13), 0 );
        draw( _environment, $9, $11, $1, $3, resolve_color( _environment, $13), 0 );
        gr_locate( _environment, $1, $3 );
    };

/*-----------------------------------------------------------------------------
 ------------ INK DEFINITION
 ----------------------------------------------------------------------------*/

ink_definition:
    expr { ink( _environment, $1 ); };

inkb_definition:
    expr OP_COMMA expr OP_COMMA { inkb( _environment, $1, $3, NULL ); } | 
    expr OP_COMMA expr OP_COMMA expr { inkb( _environment, $1, $3, $5 ); } | 
    expr OP_COMMA OP_COMMA { inkb( _environment, $1, NULL, NULL ); } |
    expr OP_COMMA OP_COMMA expr { inkb( _environment, $1, NULL, $4 ); };

/*-----------------------------------------------------------------------------
 ------------ ON GOTO DEFINITION
 ----------------------------------------------------------------------------*/

on_goto_definition:
    Identifier { on_goto_index( _environment, $1 ); } OP_COMMA on_goto_definition | 
    Identifier { on_goto_index( _environment, $1 ); on_goto_end( _environment ); } |
    Integer { on_goto_number( _environment, $1 ); } OP_COMMA on_goto_definition |
    Integer { on_goto_number( _environment, $1 ); on_goto_end( _environment ); };

/*-----------------------------------------------------------------------------
 ------------ ON GOSUB DEFINITION
 ----------------------------------------------------------------------------*/

on_gosub_definition:
    Identifier { on_gosub_index( _environment, $1 ); } OP_COMMA on_gosub_definition | 
    Identifier { on_gosub_index( _environment, $1 ); on_gosub_end( _environment ); } | 
    Integer { on_gosub_number( _environment, $1 ); } OP_COMMA on_gosub_definition |
    Integer { on_gosub_number( _environment, $1 ); on_gosub_end( _environment ); };

on_proc_definition:
    Identifier { on_proc_index( _environment, $1 ); } OP_COMMA on_proc_definition |
    Identifier { on_proc_index( _environment, $1 ); on_proc_end( _environment ); };

/*-----------------------------------------------------------------------------
 ------------ ON DEFINITION
 ----------------------------------------------------------------------------*/

on_definition:
    expr GOSUB { on_gosub( _environment, $1 );   } on_gosub_definition |
    expr GOTO { on_goto( _environment, $1 ); } on_goto_definition | 
    expr PROC { on_proc( _environment, $1 ); } on_proc_definition | 
    SCROLL DOWN ROW CALL Identifier { scroll( _environment, 0, 0 ); on_scroll_call( _environment, 0, 1, $5 ); } |
    SCROLL DOWN ROW GOSUB Identifier { scroll( _environment, 0, 0 ); on_scroll_gosub( _environment, 0, 1, $5 ); } | 
    SCROLL LEFT COLUMN CALL Identifier { scroll( _environment, 0, 0 ); on_scroll_call( _environment, -1, 0, $5 ); } | 
    SCROLL LEFT COLUMN GOSUB Identifier { scroll( _environment, 0, 0 ); on_scroll_gosub( _environment, -1, 0, $5 ); } | 
    SCROLL RIGHT COLUMN CALL Identifier { scroll( _environment, 0, 0 ); on_scroll_call( _environment, 1, 0, $5 ); } | 
    SCROLL RIGHT COLUMN GOSUB Identifier { scroll( _environment, 0, 0 ); on_scroll_gosub( _environment, 1, 0, $5 ); } | 
    SCROLL UP ROW CALL Identifier { scroll( _environment, 0, 0 ); on_scroll_call( _environment, 0, -1, $5 ); } | 
    SCROLL UP ROW GOSUB Identifier { scroll( _environment, 0, 0 ); on_scroll_gosub( _environment, 0, -1, $5 ); };

/*-----------------------------------------------------------------------------
 ------------ EVERY DEFINITION
 ----------------------------------------------------------------------------*/

timer_number_comma:
    { $$ = NULL; } | 
    OP_COMMA expr { $$ = $2; };

timer_number:
    { $$ = NULL; } | 
    expr { $$ = $1; };

every_definition:
    expr ticks timer_number_comma GOSUB Identifier on_targets {
        if ( $6 ) {
          every_ticks_gosub( _environment, $1, $5, $3 );
        }
    } | 
    expr ticks timer_number_comma CALL Identifier on_targets {
        if ( $6 ) {
          every_ticks_call( _environment, $1, $5, $3 );
        }
    } | 
    ON timer_number on_targets {
        if ( $3 ) {
          every_on( _environment, $2 );
        }
    } | 
    OFF timer_number on_targets {
        if ( $3 ) {
          every_off( _environment, $2 );
        }
    };

/*-----------------------------------------------------------------------------
 ------------ AFTER DEFINITION
 ----------------------------------------------------------------------------*/

after_definition:
    expr ticks timer_number_comma GOSUB Identifier on_targets {
        if ( $6 ) {
          every_ticks_gosub( _environment, $1, $5, $3 );
          every_on( _environment, $3 );
        }
    } | 
    expr ticks timer_number_comma CALL Identifier on_targets {
        if ( $6 ) {
          every_ticks_call( _environment, $1, $5, $3 );
          every_on( _environment, $3 );
        }
    };

/*-----------------------------------------------------------------------------
 ------------ ADD(C) DEFINITION
 ----------------------------------------------------------------------------*/

limits_optional: 
    {
        ((struct _Environment *)_environment)->upperLimit = NULL;
        ((struct _Environment *)_environment)->lowerLimit = NULL;
        ((struct _Environment *)_environment)->clamp = 0;
    } | 
    OP_COMMA expr TO expr clamp_optional {
        ((struct _Environment *)_environment)->lowerLimit = $2;
        ((struct _Environment *)_environment)->upperLimit = $4;
        ((struct _Environment *)_environment)->clamp = $5;
    };

add_definition:
    Identifier field_optional OP_COMMA expr {
        Variable * expr = variable_retrieve( _environment, $4 );
        if ( expr->initializedByConstant ) {
            if ( $2 ) {
                variable_add_inplace_type( _environment, $1, $2, expr->value );
            } else {
                variable_add_inplace( _environment, $1, expr->value );
            }
        } else {            
            if ( $2 ) {
                variable_add_inplace_type_vars( _environment, $1, $2, $4 );
            } else {
                variable_add_inplace_vars( _environment, $1, $4 );
            }
        }
    } | 
    Identifier field_optional OP_COMMA OP_HASH const_expr {
        if ( $2 ) {
            variable_add_inplace_type( _environment, $1, $2, $5 );
        } else {
            variable_add_inplace( _environment, $1, $5 );
        }
    } | 
    Identifier field_optional OP_COMMA expr OP_COMMA expr TO expr clamp_optional {
        if ( $2 ) {
            add_complex_type_vars( _environment, $1, $2, $4, $6, $8, $9 );
        } else {
            add_complex_vars( _environment, $1, $4, $6, $8, $9 );
        }
    } | 
    Identifier field_optional OP_COMMA expr OP_COMMA expr OP_COMMA expr clamp_optional {
        if ( $2 ) {
            add_complex_type_vars( _environment, $1, $2, $4, $6, $8, $9 );
        } else {
            add_complex_vars( _environment, $1, $4, $6, $8, $9 );
        }
    } | 
    Identifier field_optional OP_COMMA OP_HASH const_expr OP_COMMA OP_HASH const_expr TO OP_HASH const_expr clamp_optional {
        if ( $2 ) {
            add_complex_type( _environment, $1, $2, $5, $8, $11, $12 );
        } else {
            add_complex( _environment, $1, $5, $8, $11, $12 );
        }
    } | 
    OSP Identifier CSP OP_COMMA expr { variable_add_inplace_mt( _environment, $2, $5 ); } | 
    OSP Identifier CSP OP_COMMA expr OP_COMMA expr TO expr clamp_optional { add_complex_mt( _environment, $2, $5, $7, $9, $10 ); } |
    Identifier OP {
        parser_array_init( _environment );        
    } indexes CP field_optional OP_COMMA expr limits_optional {
        if ( $6 ) {
            add_complex_array_type( _environment, $1, $6, $8, ((struct _Environment *)_environment)->lowerLimit, ((struct _Environment *)_environment)->upperLimit, ((struct _Environment *)_environment)->clamp );
        } else {
            define_implicit_array_if_needed( _environment, $1 );
            add_complex_array( _environment, $1, $8, ((struct _Environment *)_environment)->lowerLimit, ((struct _Environment *)_environment)->upperLimit, ((struct _Environment *)_environment)->clamp );
        }
        parser_array_cleanup( _environment );
    };

addc_definition:
    Identifier field_optional OP_COMMA expr OP_COMMA expr TO expr  {
        if ( $2 ) {
            add_complex_type_vars( _environment, $1, $2, $4, $6, $8, 1 );
        } else {
            add_complex_vars( _environment, $1, $4, $6, $8, 1 );
        }
    } | 
    Identifier field_optional OP_COMMA expr OP_COMMA expr OP_COMMA expr  {
        if ( $2 ) {
            add_complex_type_vars( _environment, $1, $2, $4, $6, $8, 1 );
        } else {
            add_complex_vars( _environment, $1, $4, $6, $8, 1 );
        }
    } | 
    Identifier field_optional OP_COMMA OP_HASH const_expr OP_COMMA OP_HASH const_expr TO OP_HASH const_expr {
        if ( $2 ) {
            add_complex_type( _environment, $1, $2, $5, $8, $11, 1 );
        } else {
            add_complex( _environment, $1, $5, $8, $11, 1 );
        }
    } | 
    OSP Identifier CSP OP_COMMA expr OP_COMMA expr TO expr clamp_optional { add_complex_mt( _environment, $2, $5, $7, $9, 1 ); } |
    Identifier OP {
        parser_array_init( _environment );        
    } indexes CP field_optional OP_COMMA expr limits_optional {
        if ( $6 ) {
            add_complex_array_type( _environment, $1, $6, $8, ((struct _Environment *)_environment)->lowerLimit, ((struct _Environment *)_environment)->upperLimit, 1 );
        } else {
            define_implicit_array_if_needed( _environment, $1 );
            add_complex_array( _environment, $1, $8, ((struct _Environment *)_environment)->lowerLimit, ((struct _Environment *)_environment)->upperLimit, 1 );
        }
        parser_array_cleanup( _environment );
    };

/*-----------------------------------------------------------------------------
 ------------ XOR DEFINITION
 ----------------------------------------------------------------------------*/

xor_definition:
    Identifier OP_COMMA expr { variable_xor_inplace_vars( _environment, $1, $3 ); } | 
    Identifier OP_COMMA OP_HASH const_expr { variable_xor_inplace( _environment, $1, $4 ); } |
    OSP Identifier CSP OP_COMMA expr { variable_xor_inplace_mt( _environment, $2, $5 ); };

/*-----------------------------------------------------------------------------
 ------------ SWAP DEFINITION
 ----------------------------------------------------------------------------*/

swap_definition:
    Identifier as_datatype_suffix_optional OP_COMMA Identifier as_datatype_suffix_optional {
        if ( $2 != $5 ) {
            CRITICAL_CANNOT_SWAP_DIFFERENT_DATATYPES( $1, $4 );
        }
        variable_swap( _environment, $1, $4 );
    };

/*-----------------------------------------------------------------------------
 ------------ MUL DEFINITION
 ----------------------------------------------------------------------------*/

mul_definition:
    Identifier perc OP_COMMA expr { variable_move( _environment, variable_mul( _environment, $1, $4 )->name, $1 ); };

/*-----------------------------------------------------------------------------
 ------------ DIV DEFINITION
 ----------------------------------------------------------------------------*/

div_definition:
    Identifier perc OP_COMMA expr { variable_move( _environment, variable_div( _environment, $1, $4, NULL )->name, $1 ); } |
    Identifier perc OP_COMMA OP_HASH const_expr {
        if ( log2($5) != (int)log2($5) ) {
            Variable * v = variable_retrieve( _environment, $1 );
            Variable * temporary = variable_temporary( _environment, v->type, "(temp)" );
            variable_store( _environment, v->name, $5 );
            variable_move( _environment, variable_div( _environment, $1, temporary->name, NULL )->name, $1 );
        } else {
            variable_move( _environment, variable_div2_const( _environment, $1, $5, NULL )->name, $1 );
        }
    } |
    Identifier perc OP_COMMA expr OP_COMMA Identifier perc {
        variable_retrieve_or_define( _environment, $6, ((struct _Environment *)_environment)->defaultVariableType, 0);
        variable_move( _environment, variable_div( _environment, $1, $4, $6 )->name, $1 );
    };

/*-----------------------------------------------------------------------------
 ------------ ASSIGNMENT OF ARRAY DEFINITION
 ----------------------------------------------------------------------------*/

array_assign_buffer:
    buffer_definition_prefix BufferDefinitionHex {
        if ( !((struct _Environment *)_environment)->emptyProcedure ) {
            int size = ( strlen( $2 ) ) / 2;
            if ( ((struct _Environment *)_environment)->currentArray->arrayDimensions > 1 ) {
                if ( size != ((struct _Environment *)_environment)->currentArray->size ) {
                    CRITICAL_BUFFER_SIZE_MISMATCH_ARRAY_SIZE( ((struct _Environment *)_environment)->currentArray->name, ((struct _Environment *)_environment)->currentArray->size, size );
                }
            } else {
                if ( ((struct _Environment *)_environment)->currentArray->arrayDimensionsEach[0] >= 0 ) {
                    if ( size != ((struct _Environment *)_environment)->currentArray->size ) {
                        CRITICAL_BUFFER_SIZE_MISMATCH_ARRAY_SIZE( ((struct _Environment *)_environment)->currentArray->name, ((struct _Environment *)_environment)->currentArray->size, size );
                    }
                } else {
                    ((struct _Environment *)_environment)->currentArray->arrayDimensionsEach[0] = size / ( VT_BITWIDTH( ((struct _Environment *)_environment)->currentArray->arrayType ) / 8 );
                    ((struct _Environment *)_environment)->currentArray->size = size;
                }
            }

            char * buffer = malloc( size );
            char hexdigits[3];
            int i = 0, c = 0, j = 0;
            for( i = 0, c = strlen( $2 ); i<c; i += 2 ) {
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
    } buffer_definition_suffix_optional | 
    OP_HASH OGP const_array_definitions CGP {
        if ( !((struct _Environment *)_environment)->emptyProcedure ) {
            Variable *currentArray = ((struct _Environment *)_environment)->currentArray;
            if ( currentArray->size < 0 ) {
                int size = 0;
                Constant * first = currentArray->arrayInitialization;
                while( first ) {
                    first = first->next;
                    ++size;
                }
                if ( currentArray->arrayType == VT_FLOAT ) {
                    currentArray->size = ( size * ( VT_FLOAT_BITWIDTH( currentArray->arrayPrecision ) / 8 ) );
                } else {
                    currentArray->size = ( size * ( VT_BITWIDTH( currentArray->arrayType ) / 8 ) );
                }
                currentArray->arrayDimensionsEach[0] = size;
            }
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
                    default: {
                        int result[16];
                        if ( currentArray->arrayType == VT_FLOAT ) {
                            switch( currentArray->arrayPrecision ) {
                                case FT_FAST:
                                    cpu_float_fast_from_double_to_int_array( _environment, initializationValues->valueFloating, result );
                                    break;
                                case FT_SINGLE:
                                    cpu_float_single_from_double_to_int_array( _environment, initializationValues->valueFloating, result );
                                    break;
                            }

                            memcpy( ptr, &result, VT_FLOAT_BITWIDTH( currentArray->arrayPrecision ) / 8 );
                        }
                        ptr += ( VT_FLOAT_BITWIDTH( currentArray->arrayPrecision ) / 8 );
                        break;
                    }
                }
                initializationValues = initializationValues->next;
            }
            if ( ( ptr - buffer ) != currentArray->size ) {
                CRITICAL_BUFFER_SIZE_MISMATCH_ARRAY_SIZE( currentArray->name, currentArray->size, (int)(ptr-buffer));
            }
            ((struct _Environment *)_environment)->currentArray->valueBuffer = buffer;
            ((struct _Environment *)_environment)->currentArray->memoryArea = NULL;
            ((struct _Environment *)_environment)->currentArray = NULL;
        }
    };

array_assign:
    {
        if ( !((struct _Environment *)_environment)->emptyProcedure ) {
            if ( ! ((struct _Environment *)_environment)->currentArray->memoryArea ) {
                memory_area_assign( ((struct _Environment *)_environment)->memoryAreas, ((struct _Environment *)_environment)->currentArray );
            }
            if ( ((struct _Environment *)_environment)->currentArray->memoryArea ) {
                variable_store( _environment, ((struct _Environment *)_environment)->currentArray->name, ((struct _Environment *)_environment)->currentArray->value );
            }
            int i=0;
            for( i=0; i<((struct _Environment *)_environment)->arrayDimensions; ++i ) {
                if ( ((struct _Environment *)_environment)->arrayDimensionsEach[i] <= 0 ) {
                    CRITICAL_ARRAY_MISSING_SIZE( ((struct _Environment *)_environment)->currentArray->name );
                }
            }
        }
    } | 
    WITH const_expr {
        if ( !((struct _Environment *)_environment)->emptyProcedure ) {
            ((struct _Environment *)_environment)->currentArray->value = $2;
            if ( ! ((struct _Environment *)_environment)->currentArray->memoryArea ) {
                memory_area_assign( ((struct _Environment *)_environment)->memoryAreas, ((struct _Environment *)_environment)->currentArray );
            }
            if ( ((struct _Environment *)_environment)->currentArray->memoryArea ) {
                variable_store( _environment, ((struct _Environment *)_environment)->currentArray->name, ((struct _Environment *)_environment)->currentArray->value );
            }
        }
    } | 
    OP_ASSIGN {
        if ( !((struct _Environment *)_environment)->emptyProcedure ) {
            Variable *currentArray = ((struct _Environment *)_environment)->currentArray;
            currentArray->arrayInitialization = NULL;
            if ( VT_BITWIDTH( currentArray->arrayType ) == 0 && currentArray->arrayType != VT_FLOAT ) {
                CRITICAL_ARRAY_ASSIGN_DATATYPE_NOT_SUPPORTED( currentArray->name );
            }
        }
    } array_assign_buffer | 
    OP_ASSIGN LOAD String AS text_or_csv {

        if ( !((struct _Environment *)_environment)->emptyProcedure ) {

            Variable *currentArray = ((struct _Environment *)_environment)->currentArray;
            
            int size, count;
            char * valueBuffer = file_read_csv( _environment, $3, currentArray->arrayType, &size, &count );

            if ( currentArray->arrayDimensions == 1 ) {
                if ( currentArray->arrayDimensionsEach[0] < 0 ) {
                    currentArray->size = size;
                    currentArray->arrayDimensionsEach[0] = count;
                } else {
                    if ( size != ((struct _Environment *)_environment)->currentArray->size ) {
                        CRITICAL_BUFFER_SIZE_MISMATCH_ARRAY_SIZE( ((struct _Environment *)_environment)->currentArray->name, ((struct _Environment *)_environment)->currentArray->size, size );
                    }
                }
            } else {
                if ( size != ((struct _Environment *)_environment)->currentArray->size ) {
                    CRITICAL_BUFFER_SIZE_MISMATCH_ARRAY_SIZE( ((struct _Environment *)_environment)->currentArray->name, ((struct _Environment *)_environment)->currentArray->size, size );
                }
            }

            ((struct _Environment *)_environment)->currentArray->valueBuffer = valueBuffer;
            ((struct _Environment *)_environment)->currentArray->memoryArea = NULL;
            ((struct _Environment *)_environment)->currentArray = NULL;

        }

    } | 
    OP_ASSIGN LOAD String AS BINARY {
        if ( !((struct _Environment *)_environment)->emptyProcedure ) {
            Variable *currentArray = ((struct _Environment *)_environment)->currentArray;
            
            currentArray->arrayInitialization = NULL;

            FILE * handle = fopen( $3, "rt" );
            if ( ! handle ) {
                CRITICAL_ARRAY_DEFINITION_FILE_NOT_FOUND( $3 );
            }

            currentArray->arrayInitialization = malloc( sizeof( Constant ) );
            memset( currentArray->arrayInitialization, 0, sizeof( Constant ) );

            Constant * current = currentArray->arrayInitialization;

            while( !feof( handle ) ) {

                switch( VT_BITWIDTH( currentArray->arrayType ) ) {
                    case 8: {
                        unsigned char value = 0;
                        (void)!fread( &value, 1, 1, handle );
                        current->value = value;
                        break;
                    }
                    case 16: {
                        int value = 0;
                        (void)!fread( &value, 1, 2, handle );
                        current->value = value;
                        break;
                    }
                    case 32: {
                        long value = 0;
                        (void)!fread( &value, 1, 4, handle );
                        current->value = value;
                        break;
                    }
                    default:
                        CRITICAL_ARRAY_DATATYPE_NOT_SUPPORTED( $3 );
                }

                current->next = malloc( sizeof( Constant ) );
                memset( current->next, 0, sizeof( Constant ) );
                current = current->next;

            }

            fclose( handle );

            int size = 0;
            Constant * first = currentArray->arrayInitialization;
            while( first->next ) {
                first = first->next;
                ++size;
            }

            if ( currentArray->arrayDimensions == 1 ) {
                if ( currentArray->size < 0 ) {
                    currentArray->size = ( size * ( VT_BITWIDTH( currentArray->arrayType ) / 8 ) );
                    currentArray->arrayDimensionsEach[0] = size;
                } else {
                    if ( size != ((struct _Environment *)_environment)->currentArray->size ) {
                        CRITICAL_BUFFER_SIZE_MISMATCH_ARRAY_SIZE( ((struct _Environment *)_environment)->currentArray->name, ((struct _Environment *)_environment)->currentArray->size, size );
                    }
                }
            } else {
                if ( size != ((struct _Environment *)_environment)->currentArray->size ) {
                    CRITICAL_BUFFER_SIZE_MISMATCH_ARRAY_SIZE( ((struct _Environment *)_environment)->currentArray->name, ((struct _Environment *)_environment)->currentArray->size, size );
                }
            }

            char * buffer = malloc( currentArray->size ), * ptr = buffer;
            int i=0;
            Constant * initializationValues = currentArray->arrayInitialization;
            while(initializationValues->next) {
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
        }
    };

array_reassign:
    buffer_definition_prefix BufferDefinitionHex {
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
        Variable * var = variable_temporary( _environment, VT_BUFFER, "(array reassign)" );
        variable_store_buffer( _environment, var->name, buffer, size, 0 );
        cpu_mem_move_direct_size( _environment, var->realName, ((struct _Environment *)_environment)->currentArray->realName, size );
        ((struct _Environment *)_environment)->currentArray = NULL;
    } buffer_definition_suffix_optional | 
    OP_HASH OGP const_array_definitions CGP {
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

/*-----------------------------------------------------------------------------
 ------------ DIM/VAR DEFINITION
 ----------------------------------------------------------------------------*/

dim_definition:
    Identifier datatype {
            if ( !((struct _Environment *)_environment)->emptyProcedure ) {
            memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
            ((struct _Environment *)_environment)->arrayDimensions = 0;
            }
        } OP dimensions CP {
            if ( !((struct _Environment *)_environment)->emptyProcedure ) {
                ((struct _Environment *)_environment)->currentArray = variable_define( _environment, $1, VT_TARRAY, 0 );
                if ( $2 == VT_TYPE ) {
                    variable_set_type( _environment, $1, ((struct _Environment *)_environment)->currentType->name );
                }
                variable_array_type( _environment, $1, $2 );
            }
        } array_assign readonly_optional on_bank_explicit {
            if ( !((struct _Environment *)_environment)->emptyProcedure ) {
                Variable * array = variable_retrieve( _environment, $1 );
                if ( $9 != -1 ) {
                    array->readonly = $9;
                }
                if ( $10 > 0 ) {
                    if ( ! banks_store( _environment, array, $10 ) ) {
                        CRITICAL_STORAGE_BANKED_OUT_OF_MEMORY( array->name );
                    };
                } else if ( $10 < 0 ) {
                    array->bankReadOrWrite = 1;
                }
            }
        }
        as_datatype_suffix |
    Identifier as_datatype_suffix_optional {
            if ( !((struct _Environment *)_environment)->emptyProcedure ) {
            memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
            ((struct _Environment *)_environment)->arrayDimensions = 0;
            }
        } OP dimensions CP {
            if ( !((struct _Environment *)_environment)->emptyProcedure ) {
                ((struct _Environment *)_environment)->currentArray = variable_define( _environment, $1, VT_TARRAY, 0 );
            }
        } as_datatype {
            if ( !((struct _Environment *)_environment)->emptyProcedure ) {
                int followRchackCocon1163 = 0;

                /* retrocompatible hacks */

                // If we are compiling "Cocon" game with a recent
                // version of the compiler, arrays "til", "sts", 
                // "bkg", "win" and "ugb" will be defined as BYTE, 
                // to reduce to half the memory occupation.        
                if ( ((struct _Environment *)_environment)->vestigialConfig.rchack_cocon_1163 ) {
                    if ( 
                        strcmp( $1, "til" ) == 0 || 
                        strcmp( $1, "sts" ) == 0 || 
                        strcmp( $1, "bkg" ) == 0 ||
                        strcmp( $1, "win" ) == 0 ||
                        strcmp( $1, "ugb" ) == 0
                        ) {
                        followRchackCocon1163 = 1;
                    }
                }

                if ( followRchackCocon1163 ) {
                    variable_array_type( _environment, $1, VT_BYTE );
                } else {
                    if ( $2 ) {
                        if ( $2 == VT_TYPE ) {
                            variable_set_type( _environment, $1, ((struct _Environment *)_environment)->currentType->name );
                        }
                        variable_array_type( _environment, $1, $2 );
                    } else {
                        if ( $8 == VT_TYPE ) {
                            variable_set_type( _environment, $1, ((struct _Environment *)_environment)->currentType->name );
                        }
                        variable_array_type( _environment, $1, $8 );
                    }
                }
            }

        } array_assign readonly_optional on_bank_explicit {
            if ( !((struct _Environment *)_environment)->emptyProcedure ) {
                Variable * array = variable_retrieve( _environment, $1 );
                if ( $11 != -1 ) {
                    array->readonly = $11;
                }
                if ( $12 > 0 ) {
                    if ( ! banks_store( _environment, array, $12 ) ) {
                        CRITICAL_STORAGE_BANKED_OUT_OF_MEMORY( array->name );
                    };
                } else if ( $12 < 0 ) {
                    array->bankReadOrWrite = 1;
                }
            }
        } | 
    Identifier WITH const_expr {
            if ( !((struct _Environment *)_environment)->emptyProcedure ) {
                memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
                ((struct _Environment *)_environment)->arrayDimensions = 0;
            }
        } OP dimensions CP {
            if ( !((struct _Environment *)_environment)->emptyProcedure ) {
                ((struct _Environment *)_environment)->currentArray = variable_define( _environment,  $1, VT_TARRAY, 0 );
                ((struct _Environment *)_environment)->currentArray->value = $3;
                variable_array_type( _environment, $1, ((struct _Environment *)_environment)->defaultVariableType );
                if ( ! ((struct _Environment *)_environment)->currentArray->memoryArea ) {
                    memory_area_assign( ((struct _Environment *)_environment)->memoryAreas, ((struct _Environment *)_environment)->currentArray );
                }
                if ( ((struct _Environment *)_environment)->currentArray->memoryArea ) {
                    variable_store( _environment, ((struct _Environment *)_environment)->currentArray->name, ((struct _Environment *)_environment)->currentArray->value );
                }
            }
        } readonly_optional on_bank_explicit {
            if ( !((struct _Environment *)_environment)->emptyProcedure ) {
                Variable * array = variable_retrieve( _environment, $1 );
                if ( $9 != -1 ) {
                    array->readonly = $9;
                }
                if ( $10 > 0 ) {
                    if ( ! banks_store( _environment, array, $10 ) ) {
                        CRITICAL_STORAGE_BANKED_OUT_OF_MEMORY( array->name );
                    };
                } else if ( $10 < 0 ) {
                    array->bankReadOrWrite = 1;
                }
            }
        } | 
    Identifier datatype WITH const_expr {
            if ( !((struct _Environment *)_environment)->emptyProcedure ) {
            memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
            ((struct _Environment *)_environment)->arrayDimensions = 0;
            }
        } OP dimensions CP {
            if ( !((struct _Environment *)_environment)->emptyProcedure ) {
                ((struct _Environment *)_environment)->currentArray = variable_define( _environment, $1, VT_TARRAY, 0 );
                ((struct _Environment *)_environment)->currentArray->value = $4;
                variable_array_type( _environment, $1, $2 );
                if ( ! ((struct _Environment *)_environment)->currentArray->memoryArea ) {
                    memory_area_assign( ((struct _Environment *)_environment)->memoryAreas, ((struct _Environment *)_environment)->currentArray );
                }
                if ( ((struct _Environment *)_environment)->currentArray->memoryArea ) {
                    variable_store( _environment, ((struct _Environment *)_environment)->currentArray->name, ((struct _Environment *)_environment)->currentArray->value );
                }
            }
        } readonly_optional on_bank_explicit {
            if ( !((struct _Environment *)_environment)->emptyProcedure ) {
                Variable * array = variable_retrieve( _environment, $1 );
                if ( $10 != -1 ) {
                    array->readonly = $10;
                }
                if ( $11 > 0 ) {
                    if ( ! banks_store( _environment, array, $11 ) ) {
                        CRITICAL_STORAGE_BANKED_OUT_OF_MEMORY( array->name );
                    };
                } else if ( $11 < 0 ) {
                    array->bankReadOrWrite = 1;
                }
            }
        } | 
    Identifier as_datatype_mandatory {
            if ( !((struct _Environment *)_environment)->emptyProcedure ) {
            memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
            ((struct _Environment *)_environment)->arrayDimensions = 0;
            }
        } OP dimensions CP as_datatype {
            if ( !((struct _Environment *)_environment)->emptyProcedure ) {
                ((struct _Environment *)_environment)->currentArray = variable_define( _environment, $1, VT_TARRAY, 0 );
                
                /* retrocompatible hacks */

                // If we are compiling "Cocon" game with a recent
                // version of the compiler, arrays "til", "sts", 
                // "bkg", "win" and "ugb" will be defined as BYTE, 
                // to reduce to half the memory occupation.        
                if ( ((struct _Environment *)_environment)->vestigialConfig.rchack_cocon_1163 ) {
                    if ( 
                        strcmp( $1, "til" ) == 0 || 
                        strcmp( $1, "sts" ) == 0 || 
                        strcmp( $1, "bkg" ) == 0 ||
                        strcmp( $1, "win" ) == 0 ||
                        strcmp( $1, "ugb" ) == 0
                        ) {
                        variable_array_type( _environment, $1, VT_BYTE );
                    } else {
                        int realType = ( $7 == ((struct _Environment *)_environment)->defaultVariableType ) ? $2 : $7;
                        if ( realType == VT_TYPE ) {
                            variable_set_type( _environment, $1, ((struct _Environment *)_environment)->currentType->name );
                        }
                        variable_array_type( _environment, $1, realType );
                    }
                } else {
                    int realType = ( $7 == ((struct _Environment *)_environment)->defaultVariableType ) ? $2 : $7;
                    if ( realType == VT_TYPE ) {
                        variable_set_type( _environment, $1, ((struct _Environment *)_environment)->currentType->name );
                    }
                    variable_array_type( _environment, $1, realType );
                }
            }
        } array_assign readonly_optional on_bank_explicit {
            if ( !((struct _Environment *)_environment)->emptyProcedure ) {
                Variable * array = variable_retrieve( _environment, $1 );
                if ( $10 != -1 ) {
                    array->readonly = $10;
                }
                if ( $11 > 0 ) {
                    if ( ! banks_store( _environment, array, $11 ) ) {
                        CRITICAL_STORAGE_BANKED_OUT_OF_MEMORY( array->name );
                    };
                } else if ( $11 < 0 ) {
                    array->bankReadOrWrite = 1;
                }
            }
        } | 
    Identifier as_datatype_mandatory WITH const_expr {
            if ( !((struct _Environment *)_environment)->emptyProcedure ) {
                memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
                ((struct _Environment *)_environment)->arrayDimensions = 0;
            }
        } OP dimensions CP {
            if ( !((struct _Environment *)_environment)->emptyProcedure ) {
                ((struct _Environment *)_environment)->currentArray = variable_define( _environment, $1, VT_TARRAY, 0 );
                ((struct _Environment *)_environment)->currentArray->value = $4;
                variable_array_type( _environment, $1, $2 );
                if ( ! ((struct _Environment *)_environment)->currentArray->memoryArea ) {
                    memory_area_assign( ((struct _Environment *)_environment)->memoryAreas, ((struct _Environment *)_environment)->currentArray );
                }
                if ( ((struct _Environment *)_environment)->currentArray->memoryArea ) {
                    variable_store( _environment, ((struct _Environment *)_environment)->currentArray->name, ((struct _Environment *)_environment)->currentArray->value );
                }
            }
        } readonly_optional on_bank_explicit {
            if ( !((struct _Environment *)_environment)->emptyProcedure ) {
                Variable * array = variable_retrieve( _environment, $1 );
                if ( $10 != -1 ) {
                    array->readonly = $10;
                }
                if ( $11 > 0 ) {
                    if ( ! banks_store( _environment, array, $11 ) ) {
                        CRITICAL_STORAGE_BANKED_OUT_OF_MEMORY( array->name );
                    };
                } else if ( $11 < 0 ) {
                    array->bankReadOrWrite = 1;
                }
            }
        };

dim_definitions:
    dim_definition |
    dim_definition OP_COMMA dim_definitions |
    var_definition;

/*-----------------------------------------------------------------------------
 ------------ FILL DEFINITION
 ----------------------------------------------------------------------------*/

fill_base_optional:
    { $$ = 0; } | 
    const_expr { $$ = $1; };

fill_min_optional:
    { $$ = 0; } | 
    MIN const_expr { $$ = $2; };

fill_max_optional:
    { $$ = 0; } | 
    MAX const_expr { $$ = $2; };

fill_count_optional:
    { $$ = 0; } | 
    COUNT const_expr { $$ = $2; };

fill_definition_array:
    Identifier {
        define_implicit_array_if_needed( _environment, $1 );
        variable_array_fill( _environment, $1, 0 );
    }
    | Identifier WITH const_expr {
        define_implicit_array_if_needed( _environment, $1 );
        variable_array_fill( _environment, $1, $3 );
    }
    | Identifier RANDOM fill_min_optional fill_max_optional fill_count_optional {
        if ( !((struct _Environment *)_environment)->randomizeTimerCalled ) {
            randomize( _environment, get_timer( _environment )->name );
            ((struct _Environment *)_environment)->randomizeTimerCalled = 1;
        }
        define_implicit_array_if_needed( _environment, $1 );
        variable_array_fill_random( _environment, $1, 0, $3, $4, $5, 0 );
    }
    | Identifier WITH fill_base_optional RANDOM fill_min_optional fill_max_optional fill_count_optional {
        if ( !((struct _Environment *)_environment)->randomizeTimerCalled ) {
            randomize( _environment, get_timer( _environment )->name );
            ((struct _Environment *)_environment)->randomizeTimerCalled = 1;
        }
        define_implicit_array_if_needed( _environment, $1 );
        variable_array_fill_random( _environment, $1, $3, $5, $6, $7, 0 );
    }
    | Identifier WITH fill_base_optional RANDOM BOOLEAN fill_count_optional {
        if ( !((struct _Environment *)_environment)->randomizeTimerCalled ) {
            randomize( _environment, get_timer( _environment )->name );
            ((struct _Environment *)_environment)->randomizeTimerCalled = 1;
        }
        define_implicit_array_if_needed( _environment, $1 );
        variable_array_fill_random( _environment, $1, $3, 0, 0, $6, 1 );
    }
    | Identifier WITH INCREMENTAL fill_min_optional fill_count_optional {
        define_implicit_array_if_needed( _environment, $1 );
        variable_array_fill_incremental( _environment, $1, $4, $5 );
    }
    | Identifier INCREMENTAL fill_min_optional fill_count_optional {
        define_implicit_array_if_needed( _environment, $1 );
        variable_array_fill_incremental( _environment, $1, $3, $4 );
    }
    | Identifier WITH INC fill_min_optional fill_count_optional {
        define_implicit_array_if_needed( _environment, $1 );
        variable_array_fill_incremental( _environment, $1, $4, $5 );
    }
    | Identifier INC fill_min_optional fill_count_optional {
        define_implicit_array_if_needed( _environment, $1 );
        variable_array_fill_incremental( _environment, $1, $3, $4 );
    }
    ;

fill_definitions_array:
    fill_definition_array | 
    fill_definition_array OP_COMMA fill_definitions_array;
    
fill_definitions:
    fill_definitions_array;

/*-----------------------------------------------------------------------------
 ------------ FILL SCREEN DEFINITION
 ----------------------------------------------------------------------------*/

fill_screen_definition: 
    expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr { fill( _environment, $1, $3, $5, $7, $9, $11 ); };

/*-----------------------------------------------------------------------------
 ------------ SHUFFLE DEFINITION
 ----------------------------------------------------------------------------*/

shuffle_definition_optional_rounds: 
    { $$ = 128; } | 
    ROUNDS const_expr { $$ = $2; };

shuffle_definition_array:
    Identifier shuffle_definition_optional_rounds { variable_array_shuffle( _environment, $1, $2 ); };

shuffle_definition:
      shuffle_definition_array
    | shuffle_definition_array OP_COMMA shuffle_definition;

/*-----------------------------------------------------------------------------
 ------------ PRINT BUFFER DEFINITION
 ----------------------------------------------------------------------------*/

print_buffer_definition:
    OP_AT expr {
        Variable * p = variable_retrieve_or_define( _environment, $2, VT_WORD, 0 );
        Variable * x = variable_temporary( _environment, VT_BYTE, "(x)" );
        Variable * y = variable_div( _environment, p->name, screen_tiles_get_width( _environment )->name, x->name );
        locate( _environment, x->name, y->name );
    } | 
    OP_AT expr {
        Variable * p = variable_retrieve_or_define( _environment, $2, VT_WORD, 0 );
        Variable * x = variable_temporary( _environment, VT_BYTE, "(x)" );
        Variable * y = variable_div( _environment, p->name, screen_tiles_get_width( _environment )->name, x->name );
        locate( _environment, x->name, y->name );
    } OP_COMMA print_buffer_raw_definition | 
    expr { print_buffer( _environment, $1, 1, 1 ); } | 
    expr OP_COMMA {
        print_buffer( _environment, $1, 0, 1 );
        print_tab( _environment, 0 );
    } | 
    expr OP_SEMICOLON { print_buffer( _environment, $1, 0, 1 ); } | 
    expr OP_COMMA {
        print_buffer( _environment, $1, 0, 1 );
        print_tab( _environment, 0 );
    } print_buffer_definition | 
    expr OP_SEMICOLON  { print_buffer( _environment, $1, 0, 0 ); } print_buffer_definition;

print_buffer_raw_definition:
    OP_AT expr {
        Variable * p = variable_retrieve_or_define( _environment, $2, VT_WORD, 0 );
        Variable * x = variable_temporary( _environment, VT_BYTE, "(x)" );
        Variable * y = variable_div( _environment, p->name, screen_tiles_get_width( _environment )->name, x->name );
        locate( _environment, x->name, y->name );
    } | 
    OP_AT expr {
        Variable * p = variable_retrieve_or_define( _environment, $2, VT_WORD, 0 );
        Variable * x = variable_temporary( _environment, VT_BYTE, "(x)" );
        Variable * y = variable_div( _environment, p->name, screen_tiles_get_width( _environment )->name, x->name );
        locate( _environment, x->name, y->name );
    } OP_COMMA print_buffer_raw_definition | 
    expr { print_buffer( _environment, $1, 1, 0 ); } | 
    expr OP_COMMA {
        print_buffer( _environment, $1, 0, 0 );
        print_tab( _environment, 0 );
    } | 
    expr OP_SEMICOLON { print_buffer( _environment, $1, 0, 0 ); } | 
    expr OP_COMMA {
        print_buffer( _environment, $1, 0, 0 );
        print_tab( _environment, 0 );
    } print_buffer_raw_definition | 
    expr OP_SEMICOLON  { print_buffer( _environment, $1, 0, 0 ); } print_buffer_raw_definition;

/*-----------------------------------------------------------------------------
 ------------ PRINT DEFINITION
 ----------------------------------------------------------------------------*/

print_definition:
    SPC OP expr CP { spc( _environment, $3 ); } | 
    SPC OP expr CP { spc( _environment, $3 ); } print_definition | 
    SPC OP expr CP { spc( _environment, $3 ); } OP_COMMA print_definition | 
    SPC OP expr CP { spc( _environment, $3 ); } OP_SEMICOLON print_definition | 
    OP_AT expr {
        Variable * p = variable_retrieve_or_define( _environment, $2, VT_WORD, 0 );
        Variable * x = variable_temporary( _environment, VT_BYTE, "(x)" );
        Variable * y = variable_div( _environment, p->name, screen_tiles_get_width( _environment )->name, x->name );
        locate( _environment, x->name, y->name );
    } | 
    OP_AT expr {
        Variable * p = variable_retrieve_or_define( _environment, $2, VT_WORD, 0 );
        Variable * x = variable_temporary( _environment, VT_BYTE, "(x)" );
        Variable * y = variable_div( _environment, p->name, screen_tiles_get_width( _environment )->name, x->name );
        locate( _environment, x->name, y->name );
    } OP_COMMA print_definition | 
    raw_optional expr { print( _environment, $2, 1, $1 ); } | 
    raw_optional expr OP_COMMA {
        print( _environment, $2, 0, $1 );
        print_tab( _environment, 0 );
    } | 
    raw_optional expr OP_SEMICOLON { print( _environment, $2, 0, $1 ); } | 
    raw_optional expr OP_COMMA {
        print( _environment, $2, 0, $1 );
        print_tab( _environment, 0 );
    }  print_definition | 
    raw_optional expr OP_SEMICOLON  { print( _environment, $2, 0, $1 ); } print_definition;

/*-----------------------------------------------------------------------------
 ------------ GPRINT DEFINITION
 ----------------------------------------------------------------------------*/

gprint_definition:
    expr WITH expr { gprint( _environment, $3, $1, "XGR", "YGR" ); } | 
    expr AT expr OP_COMMA expr WITH expr { gprint( _environment, $7, $1, $3, $5 ); };

/*-----------------------------------------------------------------------------
 ------------ WRITING DEFINITION
 ----------------------------------------------------------------------------*/

writing_mode_definition: 
    AND { $$ = variable_by_constant( _environment, VT_BYTE, WRITING_AND )->name; } | 
    IGNORE {$$ = variable_by_constant( _environment, VT_BYTE, WRITING_IGNORE )->name; } |
    OR { $$ = variable_by_constant( _environment, VT_BYTE, WRITING_OR )->name; } | 
    XOR {$$ = variable_by_constant( _environment, VT_BYTE, WRITING_XOR )->name; } |
    REPLACE { $$ = variable_by_constant( _environment, VT_BYTE, WRITING_REPLACE )->name; };

writing_part_definition:
    NORMAL { $$ = variable_by_constant( _environment, VT_BYTE, WRITING_NORMAL )->name; } | 
    PAPER { $$ = variable_by_constant( _environment, VT_BYTE, WRITING_PAPER )->name; } | 
    PAPER ONLY {$$ = variable_by_constant( _environment, VT_BYTE, WRITING_PAPER )->name; } | 
    PEN { $$ = variable_by_constant( _environment, VT_BYTE, WRITING_PEN )->name; } | 
    PEN ONLY { $$ = variable_by_constant( _environment, VT_BYTE, WRITING_PEN )->name; };

writing_definition: 
    writing_mode_definition OP_COMMA writing_part_definition { writing( _environment, $1, $3 ); };

/*-----------------------------------------------------------------------------
 ------------ SOUND DEFINITION
 ----------------------------------------------------------------------------*/

sound_definition_argument:
    OP_HASH const_expr milliseconds_optional {
        ((struct _Environment *)_environment)->soundNoteValue[((struct _Environment *)_environment)->lastSoundNoteDuration] = $2;
        ++((struct _Environment *)_environment)->lastSoundNoteDuration;
    } | 
    OP_HASH const_expr OP_COMMA OP_HASH const_expr milliseconds_optional {
        ((struct _Environment *)_environment)->soundNoteValue[((struct _Environment *)_environment)->lastSoundNoteDuration] = $2;
        ((struct _Environment *)_environment)->soundDurationValue[((struct _Environment *)_environment)->lastSoundNoteDuration] = $5;
        ++((struct _Environment *)_environment)->lastSoundNoteDuration;
    } | 
    expr milliseconds_optional {
        ((struct _Environment *)_environment)->soundNote[((struct _Environment *)_environment)->lastSoundNoteDuration] = strdup( $1 );
        ++((struct _Environment *)_environment)->lastSoundNoteDuration;
    } | 
    expr OP_COMMA expr milliseconds_optional {
        ((struct _Environment *)_environment)->soundNote[((struct _Environment *)_environment)->lastSoundNoteDuration] = strdup( $1 );
        ((struct _Environment *)_environment)->soundDuration[((struct _Environment *)_environment)->lastSoundNoteDuration] = strdup( $3 );
        ++((struct _Environment *)_environment)->lastSoundNoteDuration;
    };

sound_definition_arguments:
    sound_definition_argument | 
    sound_definition_argument OP_SEMICOLON sound_definition_arguments;

sound_definition: 
    sound_definition_arguments ON OP_HASH const_expr {
        Variable * channel;
        if ( ((struct _Environment *)_environment)->atLeastOneSoundNoteDurationSymbolic ) {
            channel = variable_temporary( _environment, VT_BYTE, "(channel)" );
            variable_store( _environment, channel->name, $4 );
        }
        for( int i=0; i<((struct _Environment *)_environment)->lastSoundNoteDuration; ++i ) {
            if ( ((struct _Environment *)_environment)->soundNote[i] ) {
                if ( ((struct _Environment *)_environment)->soundDuration[i] ) {
                    sound_vars( _environment, ((struct _Environment *)_environment)->soundNote[i], ((struct _Environment *)_environment)->soundDuration[i], channel->name );
                } else {
                    Variable * duration = variable_temporary( _environment, VT_BYTE, "(duration)" );
                    variable_store( _environment, duration->name, ((struct _Environment *)_environment)->soundDurationValue[i] );
                    sound_vars( _environment, ((struct _Environment *)_environment)->soundNote[i], duration->name, channel->name );
                }
            } else if ( ((struct _Environment *)_environment)->soundDuration[i] ) {
                Variable * note = variable_temporary( _environment, VT_BYTE, "(note)" );
                variable_store( _environment, note->name, ((struct _Environment *)_environment)->soundNoteValue[i] );
                sound_vars( _environment, note->name, ((struct _Environment *)_environment)->soundDuration[i], channel->name );
            } else {
                sound( _environment, ((struct _Environment *)_environment)->soundNoteValue[i], ((struct _Environment *)_environment)->soundDurationValue[i], $4 );
            }
        }
    } | 
    sound_definition_arguments ON expr {
        for( int i=0; i<((struct _Environment *)_environment)->lastSoundNoteDuration; ++i ) {
            if ( ((struct _Environment *)_environment)->soundNote[i] ) {
                if ( ((struct _Environment *)_environment)->soundDuration[i] ) {
                    sound_vars( _environment, ((struct _Environment *)_environment)->soundNote[i], ((struct _Environment *)_environment)->soundDuration[i], $3 );
                } else {
                    Variable * duration = variable_temporary( _environment, VT_BYTE, "(duration)" );
                    variable_store( _environment, duration->name, ((struct _Environment *)_environment)->soundDurationValue[i] );
                    sound_vars( _environment, ((struct _Environment *)_environment)->soundNote[i], duration->name, $3 );
                }
            } else if ( ((struct _Environment *)_environment)->soundDuration[i] ) {
                Variable * note = variable_temporary( _environment, VT_BYTE, "(note)" );
                variable_store( _environment, note->name, ((struct _Environment *)_environment)->soundNoteValue[i] );
                sound_vars( _environment, note->name, ((struct _Environment *)_environment)->soundDuration[i], $3 );
            } else {
                Variable * duration = variable_temporary( _environment, VT_BYTE, "(duration)" );
                variable_store( _environment, duration->name, ((struct _Environment *)_environment)->soundDurationValue[i] );
                Variable * note = variable_temporary( _environment, VT_BYTE, "(note)" );
                variable_store( _environment, note->name, ((struct _Environment *)_environment)->soundNoteValue[i] );
                sound_vars( _environment, note->name, ((struct _Environment *)_environment)->soundDuration[i], $3 );
                sound_vars( _environment, note->name, duration->name, $3 );
            }
        }
    } | 
    sound_definition_arguments {
        for( int i=0; i<((struct _Environment *)_environment)->lastSoundNoteDuration; ++i ) {
            if ( ((struct _Environment *)_environment)->soundNote[i] ) {
                if ( ((struct _Environment *)_environment)->soundDuration[i] ) {
                    sound_vars( _environment, ((struct _Environment *)_environment)->soundNote[i], ((struct _Environment *)_environment)->soundDuration[i], NULL );
                } else {
                    Variable * duration = variable_temporary( _environment, VT_BYTE, "(duration)" );
                    variable_store( _environment, duration->name, ((struct _Environment *)_environment)->soundDurationValue[i] );
                    sound_vars( _environment, ((struct _Environment *)_environment)->soundNote[i], duration->name, NULL );
                }
            } else if ( ((struct _Environment *)_environment)->soundDuration[i] ) {
                Variable * note = variable_temporary( _environment, VT_BYTE, "(note)" );
                variable_store( _environment, note->name, ((struct _Environment *)_environment)->soundNoteValue[i] );
                sound_vars( _environment, note->name, ((struct _Environment *)_environment)->soundDuration[i], NULL );
            } else {
                sound( _environment, ((struct _Environment *)_environment)->soundNoteValue[i], ((struct _Environment *)_environment)->soundDurationValue[i], 0xff );
            }
        }
    } | 
    OFF  { sound_off( _environment, 0xffff ); } | 
    OFF ON OP_HASH const_expr { sound_off( _environment, $4 ); } | 
    OFF ON expr { sound_off_var( _environment, $3 ); };

/*-----------------------------------------------------------------------------
 ------------ INSTRUMENT DEFINITION
 ----------------------------------------------------------------------------*/

instrument_definition_simple:
    const_instrument ON OP_HASH const_expr { instrument( _environment, $1, $4 ); } |
    OP_HASH const_expr ON OP_HASH const_expr { instrument( _environment, $2, $5 ); };

instrument_definition_expression:
    const_instrument ON expr { instrument_semi_var( _environment, $1, $3 ); } |
    OP_HASH const_expr ON expr { instrument_semi_var( _environment, $2, $4 ); };

instrument_definition: 
    instrument_definition_expression |
    instrument_definition_simple;

/*-----------------------------------------------------------------------------
 ------------ MUSIC DEFINITION
 ----------------------------------------------------------------------------*/

music_type:
    { $$ = MUSIC_TYPE_AUTO; } | 
    IAF { $$ = MUSIC_TYPE_IAF; } | 
    MID { $$ = MUSIC_TYPE_MID; } | 
    PSG { $$ = MUSIC_TYPE_PSG; } | 
    SJ2 { $$ = MUSIC_TYPE_SJ2; };

music_definition_expression:
    expr music_type loop_optional { music_var( _environment, $1, $3, $2 ); } | 
    LOOP expr music_type { music_var( _environment, $2, 1, $3 ); } | 
    PAUSE { music_pause( _environment ); } | 
    RESUME { music_resume( _environment ); } | 
    SEEK expr { music_seek_var( _environment, $2 ); } |
    STOP { music_stop( _environment ); };

music_definition:
    music_definition_expression;

/*-----------------------------------------------------------------------------
 ------------ PLAY DEFINITION
 ----------------------------------------------------------------------------*/

play_definition_simple: 
    OFF { play_off( _environment, 0xffff ); } | 
    OFF ON OP_HASH const_expr { play_off( _environment, $4 ); } |
    OP_HASH const_expr { play( _environment, $2, 0, 0xffff ); } | 
    OP_HASH const_expr ON OP_HASH const_expr { play( _environment, $2, 0, $5 ); } | 
    OP_HASH const_expr OP_COMMA OP_HASH const_expr { play( _environment, $2, $5, 0xffff ); } | 
    OP_HASH const_expr OP_COMMA OP_HASH const_expr ON OP_HASH const_expr { play( _environment, $2, $5, $8 ); } | 
    OP_HASH const_expr OP_COMMA OP_HASH const_expr OP_COMMA OP_HASH const_expr { play( _environment, $5, $8, $2 ); };

play_definition_expression: 
    expr {
        Variable * var = variable_retrieve_or_define( _environment, $1, VT_DWORD, 0 );
        if ( var->type == VT_STRING || var->type == VT_DSTRING ) {
            play_string( _environment, $1 );
        } else {
            play_vars( _environment, $1, NULL, NULL );
        }
    } | 
    expr OP_COMMA expr { play_vars( _environment, $1, $3, NULL ); } | 
    expr OP_COMMA expr ON expr { play_vars( _environment, $1, $3, $5 ); } | 
    expr OP_COMMA expr OP_COMMA expr { play_vars( _environment, $3, $5, $1 ); } | 
    expr ON expr { play_vars( _environment, $1, NULL, $3 ); } | 
    OFF ON expr { play_off_var( _environment, $3 ); };

play_definition: 
    play_definition_expression |
    play_definition_simple;

/*-----------------------------------------------------------------------------
 ------------ VOLUME DEFINITION
 ----------------------------------------------------------------------------*/

volume_definition_simple: 
    OFF { volume_off( _environment, 0xffff ); } | 
    OFF ON OP_HASH const_expr { volume_off( _environment, $4 ); } |
    OP_HASH const_expr { volume( _environment, $2, 0xffff ); } | 
    OP_HASH const_expr ON OP_HASH const_expr { volume( _environment, $2, $5 ); };

volume_definition_expression: 
    expr { volume_vars( _environment, $1, NULL ); } | 
    expr ON expr { volume_vars( _environment, $1, $3 ); } | 
    OFF ON expr { volume_off_var( _environment, $3 ); };

volume_definition: 
    volume_definition_expression |
    volume_definition_simple;

/*-----------------------------------------------------------------------------
 ------------ BELL DEFINITION
 ----------------------------------------------------------------------------*/

bell_definition_simple: 
    { bell( _environment, 400, 1500, 0xffff ); }  | 
    OP_HASH const_expr { bell( _environment, $2, 1500, 0xffff ); } | 
    OP_HASH const_expr ON OP_HASH const_expr { bell( _environment, $2, 1500, $5 ); } | 
    OP_HASH const_expr OP_COMMA OP_HASH const_expr { bell( _environment, $2, $5, 0xffff ); } | 
    OP_HASH const_expr OP_COMMA OP_HASH const_expr ON OP_HASH const_expr { bell( _environment, $2, $5, $8 ); };

bell_definition_expression: 
    expr { bell_vars( _environment, $1, NULL, NULL, 0 ); } | 
    expr ON expr { bell_vars( _environment, $1, NULL, $3, 0 ); } | 
    expr OP_COMMA expr { bell_vars( _environment, $1, $3, NULL, 0 ); } | 
    expr OP_COMMA expr ON expr { bell_vars( _environment, $1, $3, $5, 0 ); };

bell_definition: 
    bell_definition_expression |
    bell_definition_simple;

/*-----------------------------------------------------------------------------
 ------------ BOOM DEFINITION
 ----------------------------------------------------------------------------*/

boom_definition_simple: 
    { boom( _environment, 1500, 0xffff ); } | 
    ON OP_HASH const_expr { boom( _environment, 1500, $3 ); } | 
    OP_HASH const_expr { boom( _environment, $2, 0xffff ); } | 
    OP_HASH const_expr milliseconds { boom( _environment, $2, 0xffff ); } | 
    OP_HASH const_expr OP_COMMA ON OP_HASH const_expr { boom( _environment, $2, $6 ); } | 
    OP_HASH milliseconds const_expr OP_COMMA ON OP_HASH const_expr { boom( _environment, $3, $7 ); };

boom_definition_expression: 
    expr { boom_var( _environment, $1, NULL ); } | 
    expr milliseconds { boom_var( _environment, $1, NULL ); } | 
    expr milliseconds ON expr { boom_var( _environment, $1, $4 ); } |
    expr ON expr { boom_var( _environment, $1, $3 ); } | 
    ON expr { boom_var( _environment, NULL, $2 ); };

boom_definition: 
    boom_definition_expression |
    boom_definition_simple;

/*-----------------------------------------------------------------------------
 ------------ SHOOT DEFINITION
 ----------------------------------------------------------------------------*/

shoot_definition_simple: 
    { shoot( _environment, 0xffff ); } | 
    OP_HASH const_expr { shoot( _environment, $2 ); };

shoot_definition: 
    shoot_definition_simple
    ;

/*-----------------------------------------------------------------------------
 ------------ LOCATE DEFINITION
 ----------------------------------------------------------------------------*/

locate_definition: 
    OP_COMMA expr { locate( _environment, NULL, $2 ); } | 
    expr OP_COMMA { locate( _environment, $1, NULL ); }  | 
    expr OP_COMMA expr { locate( _environment, $1, $3 ); };

/*-----------------------------------------------------------------------------
 ------------ GR LOCATE DEFINITION
 ----------------------------------------------------------------------------*/

gr_locate_definition: 
    optional_x OP_COMMA optional_y { gr_locate( _environment, $1, $3 ); };

/*-----------------------------------------------------------------------------
 ------------ CMOVE DEFINITION
 ----------------------------------------------------------------------------*/

cmove_definition: 
    OP_COMMA expr { cmove( _environment, NULL, $2 ); } | 
    expr OP_COMMA { cmove( _environment, $1, NULL ); }  | 
    expr OP_COMMA expr { cmove( _environment, $1, $3 ); };

/*-----------------------------------------------------------------------------
 ------------ HSCROLL DEFINITION
 ----------------------------------------------------------------------------*/

hscroll_definition: 
    LEFT { text_hscroll_line( _environment, -1, 0 ); } | 
    SCREEN LEFT { text_hscroll_screen( _environment, -1, 0 ); } | 
    RIGHT { text_hscroll_line( _environment, 1, 0 ); } | 
    SCREEN RIGHT { text_hscroll_screen( _environment, 1, 0 ); };

/*-----------------------------------------------------------------------------
 ------------ VSCROLL DEFINITION
 ----------------------------------------------------------------------------*/

vscroll_definition: 
    SCREEN UP { text_vscroll_screen( _environment, -1, 0 ); } | 
    SCREEN DOWN { text_vscroll_screen( _environment, 1, 0 ); };
    
/*-----------------------------------------------------------------------------
 ------------ INPUT DEFINITION
 ----------------------------------------------------------------------------*/

input_definition2:
    Identifier as_datatype_suffix_optional {
        VariableType vt = $2;
        if ( vt == 0 ) {
            vt = ((struct _Environment *)_environment)->defaultVariableType;
        }
        input( _environment, $1, vt );
        print_newline( _environment );
      } | 
    Identifier as_datatype_suffix_optional OP_SEMICOLON {
        VariableType vt = $2;
        if ( vt == 0 ) {
            vt = ((struct _Environment *)_environment)->defaultVariableType;
        }
        input( _environment, $1, vt );
      } | 
    Identifier as_datatype_suffix_optional {
        VariableType vt = $2;
        if ( vt == 0 ) {
            vt = ((struct _Environment *)_environment)->defaultVariableType;
        }
        input( _environment, $1, vt );
      } OP_COMMA input_definition2;

input_definition:
    String op_comma_or_semicolon Identifier as_datatype_suffix_optional {
        VariableType vt = $4;
        if ( vt == 0 ) {
            vt = ((struct _Environment *)_environment)->defaultVariableType;
        }
        Variable * string = variable_temporary( _environment, VT_STRING, "(string value)" );
        variable_store_string( _environment, string->name, $1 );
        print( _environment, string->name, 0, ((struct _Environment *)_environment)->printRaw );
        if ( $2 == 1 ) {
            Variable * qm = variable_temporary( _environment, VT_STRING, "(string value)" );
            variable_store_string( _environment, qm->name, "?" );
            print( _environment, qm->name, 0, ((struct _Environment *)_environment)->printRaw );
        }
        Variable * var = variable_retrieve_or_define( _environment, $3, vt, 0 );
        input( _environment, var->name, VT_DSTRING );
        print_newline( _environment );
    } | 
    String op_comma_or_semicolon Identifier as_datatype_suffix_optional OP_SEMICOLON {
        VariableType vt = $4;
        if ( vt == 0 ) {
            vt = ((struct _Environment *)_environment)->defaultVariableType;
        }
        Variable * string = variable_temporary( _environment, VT_STRING, "(string value)" );
        variable_store_string( _environment, string->name, $1 );
        print( _environment, string->name, 0, ((struct _Environment *)_environment)->printRaw );
        if ( $2 == 1 ) {
            Variable * qm = variable_temporary( _environment, VT_STRING, "(string value)" );
            variable_store_string( _environment, qm->name, "?" );
            print( _environment, qm->name, 0, ((struct _Environment *)_environment)->printRaw );
        }
        input( _environment, $3, vt );
    } | 
    String op_comma_or_semicolon Identifier as_datatype_suffix_optional OP_COMMA {
        VariableType vt = $4;
        if ( vt == 0 ) {
            vt = ((struct _Environment *)_environment)->defaultVariableType;
        }
        Variable * string = variable_temporary( _environment, VT_STRING, "(string value)" );
        variable_store_string( _environment, string->name, $1 );
        print( _environment, string->name, 0, ((struct _Environment *)_environment)->printRaw );
        if ( $2 == 1 ) {
            Variable * qm = variable_temporary( _environment, VT_STRING, "(string value)" );
            variable_store_string( _environment, qm->name, "?" );
            print( _environment, qm->name, 0, ((struct _Environment *)_environment)->printRaw );
        }
        input( _environment, $3, vt );
    }  input_definition2 | 
    input_definition2 | 
    RawString op_comma_or_semicolon Identifier as_datatype_suffix_optional {
        VariableType vt = ((struct _Environment *)_environment)->defaultVariableType;
        Variable * string = variable_temporary( _environment, VT_STRING, "(string value)" );
        variable_store_string( _environment, string->name, $1 );
        string->printable = 1;
        print( _environment, string->name, 0, ((struct _Environment *)_environment)->printRaw );
        if ( $2 == 1 ) {
            Variable * qm = variable_temporary( _environment, VT_STRING, "(string value)" );
            variable_store_string( _environment, qm->name, "?" );
            print( _environment, qm->name, 0, ((struct _Environment *)_environment)->printRaw );
        }
        input( _environment, $3, vt );
        print_newline( _environment );
    } | 
    RawString op_comma_or_semicolon Identifier as_datatype_suffix_optional OP_SEMICOLON {
        VariableType vt = $4;
        if ( vt == 0 ) {
            vt = ((struct _Environment *)_environment)->defaultVariableType;
        }
        Variable * string = variable_temporary( _environment, VT_STRING, "(string value)" );
        variable_store_string( _environment, string->name, $1 );
        string->printable = 1;
        print( _environment, string->name, 0, ((struct _Environment *)_environment)->printRaw );
        if ( $2 == 1 ) {
            Variable * qm = variable_temporary( _environment, VT_STRING, "(string value)" );
            variable_store_string( _environment, qm->name, "?" );
            print( _environment, qm->name, 0, ((struct _Environment *)_environment)->printRaw );
        }
        input( _environment, $3, vt );
    } | 
    RawString op_comma_or_semicolon Identifier as_datatype_suffix_optional OP_COMMA {
        VariableType vt = $4;
        if ( vt == 0 ) {
            vt = ((struct _Environment *)_environment)->defaultVariableType;
        }
        Variable * string = variable_temporary( _environment, VT_STRING, "(string value)" );
        variable_store_string( _environment, string->name, $1 );
        string->printable = 1;
        print( _environment, string->name, 0, ((struct _Environment *)_environment)->printRaw );
        if ( $2 == 1 ) {
            Variable * qm = variable_temporary( _environment, VT_STRING, "(string value)" );
            variable_store_string( _environment, qm->name, "?" );
            print( _environment, qm->name, 0, ((struct _Environment *)_environment)->printRaw );
        }
        input( _environment, $3, vt );
    } input_definition2;

/*-----------------------------------------------------------------------------
 ------------ READ DEFINITION
 ----------------------------------------------------------------------------*/

read_definition_single:
     safe_fast_optional Identifier as_datatype_suffix_optional {
        if ( $3 ) {
            if ( !variable_exists( _environment, $2 ) ) {
                variable_define( _environment, $2, $3, 0 );
            }
        }
        read_data( _environment, $2, $1 );
    } | 
    safe_fast_optional Identifier {
            parser_array_init( _environment );
            if ( variable_exists( _environment, $2 ) ) {
                Variable * v = variable_retrieve( _environment, $2 );
                if ( v->arrayType == VT_TYPE ) {
                    ((struct _Environment *)_environment)->currentType = v->typeType;
                } else {
                    ((struct _Environment *)_environment)->currentType = NULL;
                }
            }
        } OP indexes CP field_optional {
            if ( !((struct _Environment *)_environment)->currentType ) {
                define_implicit_array_if_needed( _environment, $2 );
            }
            Variable * a = variable_retrieve( _environment, $2 );
            if ( a->type != VT_TARRAY ) {
                CRITICAL_NOT_ARRAY( $2 );
            }
            Variable * read;
            if ( ! ((struct _Environment *)_environment)->currentType ) {
                read = variable_temporary( _environment, a->arrayType, "(temp for array)" );
            } else {
                if ( ! a->typeType ) {
                    CRITICAL_VARIABLE_TYPE_NEEDED( $2 );
                }
                ((struct _Environment *)_environment)->currentField = field_find( a->typeType, $7 );
                if ( ! ((struct _Environment *)_environment)->currentField ) {
                    CRITICAL_UNKNOWN_FIELD_ON_TYPE( $7 );
                }
                read = variable_temporary( _environment, ((struct _Environment *)_environment)->currentField->type, "(temp for array)" );
            }
            read_data( _environment, read->name, $1 );
            if ( ! ((struct _Environment *)_environment)->currentType ) {
                if ( a->arrayType == VT_DSTRING ) {
                    variable_move_array_string( _environment, $2, read->name );
                } else {
                    variable_move_array( _environment, $2, read->name );
                }
            } else {
                variable_move_array_type( _environment, $2, ((struct _Environment *)_environment)->currentField->name, read->name );
            }
            parser_array_cleanup( _environment );
        } | 
    safe_fast_optional Identifier OP_DOLLAR {
            parser_array_init( _environment );
        } OP indexes CP {
            define_implicit_array_if_needed( _environment, $2 );
            Variable * a = variable_retrieve( _environment, $2 );
            if ( a->type != VT_TARRAY ) {
                CRITICAL_NOT_ARRAY( $2 );
            }
            if ( a->arrayType != VT_DSTRING ) {
                CRITICAL_DATATYPE_MISMATCH( a->name, $2 );
            }
            Variable * read = variable_temporary( _environment, VT_DSTRING, "(temp for array)" );
            read_data( _environment, read->name, $1 );
            variable_move_array_string( _environment, $2, read->name );
            parser_array_cleanup( _environment );
        };

read_definition:
    read_definition_single | 
    read_definition_single OP_COMMA read_definition;

/*-----------------------------------------------------------------------------
 ------------ POKE DEFINITION
 ----------------------------------------------------------------------------*/

poke_definition: 
    expr OP_COMMA expr {
        if ( ((struct _Environment *)_environment)->insideCopperList ) {
            Variable * address = variable_retrieve( _environment, $1 );
            if ( !address->initializedByConstant ) {
                CRITICAL_STORE_WITH_NOT_CONST_NOT_ALLOWED( $1 );
            }
            Variable * value = variable_retrieve( _environment, $3 );
            if ( !value->initializedByConstant ) {
                CRITICAL_STORE_WITH_NOT_CONST_NOT_ALLOWED( $3 );
            }
            copper_store( _environment, address->value, value->value, VT_BYTE );
        } else {
            poke_var( _environment, $1, $3 );
        }
    };

/*-----------------------------------------------------------------------------
 ------------ POKEW DEFINITION
 ----------------------------------------------------------------------------*/

pokew_definition: 
    expr OP_COMMA expr {
      if ( ((struct _Environment *)_environment)->insideCopperList ) {
        Variable * address = variable_retrieve( _environment, $1 );
        if ( !address->initializedByConstant ) {
            CRITICAL_STORE_WITH_NOT_CONST_NOT_ALLOWED( $1 );
        }
        Variable * value = variable_retrieve( _environment, $3 );
        if ( !value->initializedByConstant ) {
            CRITICAL_STORE_WITH_NOT_CONST_NOT_ALLOWED( $3 );
        }
        copper_store( _environment, address->value, value->value, VT_WORD );
      } else {
        pokew_var( _environment, $1, $3 );
      }
    };

/*-----------------------------------------------------------------------------
 ------------ POKED DEFINITION
 ----------------------------------------------------------------------------*/

poked_definition: 
    expr OP_COMMA expr {
      if ( ((struct _Environment *)_environment)->insideCopperList ) {
        Variable * address = variable_retrieve( _environment, $1 );
        if ( !address->initializedByConstant ) {
            CRITICAL_STORE_WITH_NOT_CONST_NOT_ALLOWED( $1 );
        }
        Variable * value = variable_retrieve( _environment, $3 );
        if ( !value->initializedByConstant ) {
            CRITICAL_STORE_WITH_NOT_CONST_NOT_ALLOWED( $3 );
        }
        copper_store( _environment, address->value, value->value, VT_DWORD );
      } else {
        poked_var( _environment, $1, $3 );
      }
    };

/*-----------------------------------------------------------------------------
 ------------ DEFINE DEFINITION
 ----------------------------------------------------------------------------*/

define_definition:
    HORIZONTAL SCROLL ON { ((struct _Environment *)_environment)->horizontalScrollOff = 0; } | 
    HORIZONTAL SCROLL OFF { ((struct _Environment *)_environment)->horizontalScrollOff = 1; } | 
    STACK const_expr { ((struct _Environment *)_environment)->stackSize = $2; } | 
    STACK SIZE const_expr { ((struct _Environment *)_environment)->stackSize = $3; } | 
    STACK START const_expr { ((struct _Environment *)_environment)->stackStartAddress = $3; } | 
    CHAIN { ((struct _Environment *)_environment)->chainUsed = 1; } | 
    SET LINE { ((struct _Environment *)_environment)->lineNeeded = 1; } | 
    CLIP on_off_optional { ((struct _Environment *)_environment)->optionClip = $2; } | 
    PUT IMAGE FAST { ((struct _Environment *)_environment)->putImageSafe = 0; } | 
    PUT IMAGE SAFE { ((struct _Environment *)_environment)->putImageSafe = 1; } | 
    GET IMAGE FAST { ((struct _Environment *)_environment)->getImageSafe = 0; } | 
    GET IMAGE SAFE { ((struct _Environment *)_environment)->getImageSafe = 1; } | 
    PRINT RAW { ((struct _Environment *)_environment)->printRaw = 1; } | 
    PRINT NORMAL { ((struct _Environment *)_environment)->printRaw = 0; } | 
    GPRINT INLINE { ((struct _Environment *)_environment)->gprintInline = 1; } | 
    GPRINT EMBEDDED { ((struct _Environment *)_environment)->gprintInline = 0; } | 
    PRINT FAST { ((struct _Environment *)_environment)->printSafe = 0; } | 
    PRINT SAFE { ((struct _Environment *)_environment)->printSafe = 1; } | 
    IMAGEREF FAST { ((struct _Environment *)_environment)->putImageRefUnsafe = 1; } | 
    IMAGEREF SAFE { ((struct _Environment *)_environment)->putImageRefUnsafe = 0; } | 
    TRANSPARENCY COARSE  {
        ((struct _Environment *)_environment)->transparencyCoarse = 1;        
        ((struct _Environment *)_environment)->transparencyUsed = 1;
    } | 
    TRANSPARENCY PRECISE  {
        ((struct _Environment *)_environment)->transparencyCoarse = 0;        
        ((struct _Environment *)_environment)->transparencyUsed = 1;
    } | 
    DOJO FUJINET  { ((struct _Environment *)_environment)->dojoOnFujiNet = 1; } | 
    DOJO VIRTUALIZED FUJINET  { ((struct _Environment *)_environment)->dojoOnVirtualizedFujiNet = 1; } | 
    DOJO ON FUJINET  { ((struct _Environment *)_environment)->dojoOnFujiNet = 1; } | 
    DOJO ON VIRTUALIZED FUJINET  { ((struct _Environment *)_environment)->dojoOnVirtualizedFujiNet = 1; } |
    DOJO SERIAL { ((struct _Environment *)_environment)->dojoOnFujiNet = 0; } | 
    DOJO ON SERIAL { ((struct _Environment *)_environment)->dojoOnFujiNet = 0; } | 
    FUJINET HDBDOS  { fujinet_define( _environment, FN_HDBDOS ); } | 
    FUJINET BECKER { fujinet_define( _environment, FN_BECKER ); } | 
    FUJINET BECKER PORT { fujinet_define( _environment, FN_BECKER ); } | 
    FUJINET SERIAL { fujinet_define( _environment, FN_SERIAL ); } | 
    FUJINET SIO { fujinet_define( _environment, FN_SIO ); } | 
    FUJINET ON SIO { fujinet_define( _environment, FN_SIO ); } | 
    SERIAL HDBDOS  { fujinet_define( _environment, FN_HDBDOS ); } | 
    SERIAL BECKER { fujinet_define( _environment, FN_BECKER ); } | 
    SERIAL BECKER PORT { fujinet_define( _environment, FN_BECKER ); } | 
    SID RELOC const_expr { ((struct _Environment *)_environment)->sidRelocAddress = $3; } | 
    IMAGE FREE HEIGHT { ((struct _Environment *)_environment)->freeImageHeight = 1; } | 
    IMAGE FREE WIDTH { ((struct _Environment *)_environment)->freeImageWidth = 1; } | 
    COLOR IMPLICIT { ((struct _Environment *)_environment)->colorImplicit = 1; } | 
    COLOR EXPLICIT { ((struct _Environment *)_environment)->colorImplicit = 0; } | 
    COMPRESSION OFF { ((struct _Environment *)_environment)->compressionForbidden = 1; } | 
    COMPRESSION ON { ((struct _Environment *)_environment)->compressionForbidden = 0; } | 
    COMPRESSION RLE ON { ((struct _Environment *)_environment)->enableRle = 1; } | 
    COMPRESSION RLE OFF { ((struct _Environment *)_environment)->enableRle = 0; } | 
    RESIDENT DETECTION ON { ((struct _Environment *)_environment)->residentDetectionEnabled = 1; } | 
    RESIDENT DETECTION OFF { ((struct _Environment *)_environment)->residentDetectionEnabled = 0; } | 
    CENTER WITH NEWLINE { ((struct _Environment *)_environment)->centerWithoutNewLine = 0; } | 
    CENTER WITHOUT NEWLINE { ((struct _Environment *)_environment)->centerWithoutNewLine = 1; } | 
    CLS IMPLICIT { ((struct _Environment *)_environment)->vestigialConfig.clsImplicit = 1; } |
    CLS EXPLICIT { ((struct _Environment *)_environment)->vestigialConfig.clsImplicit = 0; } | 
    CLS FAST { ((struct _Environment *)_environment)->clsSlow = 0; } | 
    CLS SLOW { ((struct _Environment *)_environment)->clsSlow = 1; } | 
    JOYSTICK SYNC { ((struct _Environment *)_environment)->joystickConfig.sync = 1; } | 
    JOYSTICK ASYNC { ((struct _Environment *)_environment)->joystickConfig.sync = 0; } | 
    KEYBOARD SYNC { ((struct _Environment *)_environment)->keyboardConfig.sync = 1; } | 
    KEYBOARD ASYNC { ((struct _Environment *)_environment)->keyboardConfig.sync = 0; } | 
    AUDIO SYNC { ((struct _Environment *)_environment)->audioConfig.async = 0; } | 
    AUDIO ASYNC { ((struct _Environment *)_environment)->audioConfig.async = 1; } | 
    MSPRITE SYNC { ((struct _Environment *)_environment)->multiplexingSpriteConfig.async = 0; } | 
    MSPRITE ASYNC { ((struct _Environment *)_environment)->multiplexingSpriteConfig.async = 1; } | 
    LOAD BANKED ON { ((struct _Environment *)_environment)->bankedLoadDefault = 1; } | 
    LOAD BANKED OFF { ((struct _Environment *)_environment)->bankedLoadDefault = 0; } | 
    KEY PRESSED SYNC { ((Environment *)_environment)->keyPressDutyCycle = 1; } | 
    KEY PRESSED ASYNC { ((Environment *)_environment)->keyPressDutyCycle = 0; } | 
    KEY PRESS SYNC { ((Environment *)_environment)->keyPressDutyCycle = 1; } | 
    KEY PRESS ASYNC { ((Environment *)_environment)->keyPressDutyCycle = 0; } | 
    AUDIO TARGET audio_source {
        if ( ! define_audio_target_check( _environment, $3 ) ) {
            CRITICAL_AUDIO_TARGET_UNAVAILABLE( );
        }
        ((struct _Environment *)_environment)->audioConfig.target = $3;
    } | 
    FONT font_schema {
        ((struct _Environment *)_environment)->fontConfig.schema = $2;
        font_descriptors_init( _environment, 0 );
    } | 
    FONT OPTIMIZED { ((struct _Environment *)_environment)->fontConfig.optimized = 1; } | 
    JOYSTICK VALUES DEFAULT { ((struct _Environment *)_environment)->joystickConfig.values = 0; } | 
    JOYSTICK VALUES TSB { ((struct _Environment *)_environment)->joystickConfig.values = 1; } | 
    JOYSTICK EMULATION ON { ((struct _Environment *)_environment)->joystickConfig.notEmulated = 0; } | 
    JOYSTICK EMULATION OFF { ((struct _Environment *)_environment)->joystickConfig.notEmulated = 1; } | 
    JOYSTICK RETRIES const_expr {
        if ( $3 < 0 ) {
            CRITICAL_INVALID_JOYSTICK_RETRIES( $3 );
        }
        if ( $3 > 255 ) {
            CRITICAL_INVALID_JOYSTICK_RETRIES( $3 );
        }
        ((struct _Environment *)_environment)->joystickConfig.retries = $3;
    } | 
    PROGRAM START const_expr {
        if ( $3 < 0 ) {
            CRITICAL_INVALID_PROGRAM_START( $3 );
        }
        if ( $3 > 0xffff ) {
            CRITICAL_INVALID_PROGRAM_START( $3 );
        }
        ((struct _Environment *)_environment)->program.startingAddress = $3;
    } | 
    PROGRAM NAME const_expr_string {
        ((struct _Environment *)_environment)->program.name = strdup( $3 );
    } | 
    NUMBER BYTES const_expr {
        if ( $3 <= 4 || ( $3 & 0x01 ) ) {
            CRITICAL_INVALID_NUMBER_BYTES( $3 );
        }
        ((struct _Environment *)_environment)->numberConfig.maxBytes = $3;
    } | 
    NUMBER DIGITS const_expr {
        if ( $3 <= 10 || ( $3 & 0x01 ) ) {
            CRITICAL_INVALID_NUMBER_DIGITS( $3 );
        }
        ((struct _Environment *)_environment)->numberConfig.maxDigits = $3;
    } | 
    STRING COUNT const_expr {
        if ( $3 <= 0 || $3 > 255 ) {
            CRITICAL_INVALID_STRING_COUNT( $3 );
        }
        ((struct _Environment *)_environment)->dstring.count = $3;
    } | 
    STRING SPACE const_expr {
        if ( $3 <= 0 || $3 > 32767 ) {
            CRITICAL_INVALID_STRING_SPACE( $3 );
        }
        ((struct _Environment *)_environment)->dstring.space = $3;
    } | 
    FLOAT PRECISION precision {
        ((struct _Environment *)_environment)->floatType.precision = $3;
    } | 
    TASK COUNT const_expr {
        if ( $3 <= 0 ) {
            CRITICAL_INVALID_TASK_COUNT( $3 );
        }
        ((struct _Environment *)_environment)->protothreadConfig.count = $3;
        variable_import( _environment, "PROTOTHREADCOUNT", VT_BYTE, $3 );
    } | 
    DEFAULT TYPE datatype {
        ((struct _Environment *)_environment)->defaultVariableType = $3;
    } | 
    INPUT SIZE const_expr {
        if ( $3 <= 0 ) {
            CRITICAL_INVALID_INPUT_SIZE( $3 );
        }
        ((struct _Environment *)_environment)->keyboardConfig.size = $3;
    } | 
    INPUT SEPARATOR const_expr {
        if ( $3 <= 0 ) {
            CRITICAL_INVALID_INPUT_SEPARATOR( $3 );
        }
        ((struct _Environment *)_environment)->keyboardConfig.separator = $3;
    } | 
    INPUT CURSOR const_expr {
        if ( $3 <= 0 ) {
            CRITICAL_INVALID_INPUT_CURSOR( $3 );
        }
        ((struct _Environment *)_environment)->keyboardConfig.cursor = $3;
    } | 
    INPUT LATENCY const_expr  {
        if ( $3 <= 0 || $3 >= 256 ) {
            CRITICAL_INVALID_INPUT_LATENCY( $3 );
        }
        ((struct _Environment *)_environment)->keyboardConfig.latency = $3;
    } | 
    INPUT LATENCY const_expr milliseconds {
        int latency = $3 / 20;
        if ( latency <= 0 || latency >= 256 ) {
            CRITICAL_INVALID_INPUT_LATENCY_MS( $3 );
        }
        ((struct _Environment *)_environment)->keyboardConfig.latency = latency;
    } | 
    INPUT RATE const_expr {
        if ( $3 <= 0 ) {
            CRITICAL_INVALID_INPUT_RATE( $3 );
        }
        ((struct _Environment *)_environment)->keyboardConfig.delay = 255 - $3;
    } | 
    INPUT DELAY const_expr {
        if ( $3 <= 0 || $3 >= 256 ) {
            CRITICAL_INVALID_INPUT_DELAY( $3 );
        }
        ((struct _Environment *)_environment)->keyboardConfig.delay = $3;
    } | 
    INPUT DELAY const_expr milliseconds {
        int delay = $3 / 20;
        if ( delay <= 0 || delay >= 256 ) {
            CRITICAL_INVALID_INPUT_DELAY_MS( $3 );
        }
        ((struct _Environment *)_environment)->keyboardConfig.delay = delay;
    } | 
    INPUT RELEASE const_expr {
        if ( $3 <= 0 || $3 >= 256 ) {
            CRITICAL_INVALID_INPUT_RELEASE( $3 );
        }
        ((struct _Environment *)_environment)->keyboardConfig.release = $3;
    } | 
    INPUT RELEASE const_expr milliseconds {
        int release = $3 / 20;
        if ( release <= 0 || release >= 256 ) {
            CRITICAL_INVALID_INPUT_RELEASE_MS( $3 );
        }
        ((struct _Environment *)_environment)->keyboardConfig.release = release;
    } | 
    SCREEN MODE UNIQUE OFF {
        ((struct _Environment *)_environment)->vestigialConfig.screenModeUnique = 0;
    } | 
    SCREEN MODE UNIQUE {
        ((struct _Environment *)_environment)->vestigialConfig.screenModeUnique = 1;
    } | 
    SCREEN MODE UNIQUE ON {
        ((struct _Environment *)_environment)->vestigialConfig.screenModeUnique = 1;
    } | 
    DOUBLE BUFFER ON {
        ((struct _Environment *)_environment)->vestigialConfig.doubleBufferSelected = 1;
        ((struct _Environment *)_environment)->vestigialConfig.doubleBuffer = 1;
    } | 
    DOUBLE BUFFER OFF {
        ((struct _Environment *)_environment)->vestigialConfig.doubleBufferSelected = 1;
        ((struct _Environment *)_environment)->vestigialConfig.doubleBuffer = 0;
    } | 
    PALETTE PRESERVE {
        ((struct _Environment *)_environment)->vestigialConfig.palettePreserve = 1;
    } | 
    PALETTE NOT PRESERVE {
        ((struct _Environment *)_environment)->vestigialConfig.palettePreserve = 0;
    } | 
    ANIMATION animation_definition | 
    MOVEMENT movement_definition | 
    BLIT blit_definition_define_expression | 
    KEYBOARD RATE const_expr {
        if ( $3 <= 0 ) {
            CRITICAL_INVALID_INPUT_RATE( $3 );
        }
        ((struct _Environment *)_environment)->keyboardConfig.delay = 255 - $3;
    } | 
    KEYBOARD DELAY const_expr {
        if ( $3 <= 0 ) {
            CRITICAL_INVALID_INPUT_DELAY( $3 );
        }
        ((struct _Environment *)_environment)->keyboardConfig.delay = $3;
    } | 
    KEYBOARD DELAY const_expr milliseconds {
        int delay = $3 / 20;
        if ( delay <= 0 ) {
            CRITICAL_INVALID_INPUT_DELAY( $3 );
        }
        ((struct _Environment *)_environment)->keyboardConfig.delay = delay;
    } | 
    PAINT BUFFER const_expr {
        if ( $3 <= 0 ) {
            CRITICAL_INVALID_PAINT_BUFFER( $3 );
        }
        ((struct _Environment *)_environment)->paintBucketSize = $3;
    };

define_definitions:
    define_definition |
    define_definition OP_COMMA define_definitions;

/*-----------------------------------------------------------------------------
 ------------ CONFIGURE DEFINITION
 ----------------------------------------------------------------------------*/

configure_name:
    GMC { $$ = HN_GMC; } | 
    SN76489 { $$ = HN_SN76489; };

option_name:
    ADDRESS { $$ = HPN_ADDRESS; } |
    SLOT { $$ = HPN_SLOT; };

configure_set_static_option:
    option_name OP_ASSIGN const_expr {
        OptionParameterValue * actual = malloc( sizeof( OptionParameterValue ) );
        memset( actual, 0, sizeof( OptionParameterValue ) );
        actual->parameter = $1;
        actual->value = $3;
        actual->next = ((struct _Environment *)_environment)->optionParameters;
        ((struct _Environment *)_environment)->optionParameters = actual;
    };

configure_set_static_options:
    configure_set_static_option | 
    configure_set_static_option OP_COMMA configure_set_static_options;

configure_static_definitions:
    static_optional configure_name {
            ((struct _Environment *)_environment)->optionParameters = NULL;
        } SET configure_set_static_options {
            OptionParameterValue * actual = ((struct _Environment *)_environment)->optionParameters;
            while( actual ) {
                configure_set_value( _environment, $2, actual->parameter, actual->value );
                actual = actual->next;
            }
        };

configure_set_dynamic_option:
    option_name OP_ASSIGN expr {
        OptionParameterValue * actual = malloc( sizeof( OptionParameterValue ) );
        memset( actual, 0, sizeof( OptionParameterValue ) );
        actual->parameter = $1;
        actual->valueName = strdup( $3 );
        actual->next = ((struct _Environment *)_environment)->optionParameters;
        ((struct _Environment *)_environment)->optionParameters = actual;
    };

configure_set_dynamic_options:
    configure_set_dynamic_option
    | configure_set_dynamic_option OP_COMMA configure_set_dynamic_options;

configure_dynamic_definitions:
    DYNAMIC configure_name {
        ((struct _Environment *)_environment)->optionParameters = NULL;
    } SET configure_set_dynamic_options {
        OptionParameterValue * actual = ((struct _Environment *)_environment)->optionParameters;
        while( actual ) {
            configure_set_value_var( _environment, $2, actual->parameter, actual->valueName );
            actual = actual->next;
        }
    };

configure_definitions:
    configure_dynamic_definitions |
    configure_static_definitions;

/*-----------------------------------------------------------------------------
 ------------ DECLARE DEFINITION
 ----------------------------------------------------------------------------*/

declare_definition:
    system_optional procedure Identifier AT const_expr on_targets {
            ((struct _Environment *)_environment)->parameters = 0;
            ((struct _Environment *)_environment)->returns = 0;
            if ( $6 ) {
                declare_procedure( _environment, $3, $5, $1 );
            }
        } | 
    system_optional procedure Identifier AT const_expr {
            ((struct _Environment *)_environment)->parameters = 0;
            ((struct _Environment *)_environment)->returns = 0;
            } OP parameters_asmios CP on_targets {
            if ( $10 ) {
                declare_procedure( _environment, $3, $5, $1 );
            }
        } | 
    system_optional FUNCTION Identifier AT const_expr {
            ((struct _Environment *)_environment)->parameters = 0;
            ((struct _Environment *)_environment)->returns = 0;
        } return_parameter_asmios on_targets {
            if ( $8 ) {
                declare_procedure( _environment, $3, $5, $1 );
            }
        } | 
    system_optional FUNCTION Identifier AT const_expr {
            ((struct _Environment *)_environment)->parameters = 0;
            ((struct _Environment *)_environment)->returns = 0;
        } OP parameters_asmios CP return_parameter_asmios on_targets {
            if ( $11 ) {
                declare_procedure( _environment, $3, $5, $1 );
            }
        };

/*-----------------------------------------------------------------------------
 ------------ SCROLL DEFINITION
 ----------------------------------------------------------------------------*/

scroll_definition: 
    left_or_right { scroll( _environment, $1, 0 ); } |
    left_or_right up_or_down { scroll( _environment, $1, $2 ); } |
    up_or_down { scroll( _environment, 0, $1 ); };

/*-----------------------------------------------------------------------------
 ------------ PALETTE DEFINITION
 ----------------------------------------------------------------------------*/

palette_definition:
    expr { color_semivars( _environment, ((struct _Environment *)_environment)->paletteIndex++, $1 ); } | 
    expr { color_semivars( _environment, ((struct _Environment *)_environment)->paletteIndex++, $1 ); } OP_COMMA palette_definition |
    OP_HASH const_expr { color( _environment, ((struct _Environment *)_environment)->paletteIndex++, $2 ); } | 
    OP_HASH const_expr { color( _environment, ((struct _Environment *)_environment)->paletteIndex++, $2 ); } OP_COMMA palette_definition;

/*-----------------------------------------------------------------------------
 ------------ USE DEFINITION
 ----------------------------------------------------------------------------*/

use_definition:
    TILESET expr { use_tileset( _environment, $2 ); };

/*-----------------------------------------------------------------------------
 ------------ OPTION DEFINITION
 ----------------------------------------------------------------------------*/

option_definitions:
    ARRAY CHECK { ((struct _Environment *)_environment)->checkBoundary = 1; } | 
    ARRAY SIZE const_expr { ((struct _Environment *)_environment)->defaultArraySize = $3; } | 
    CALL AS GOSUB { ((struct _Environment *)_environment)->optionCallAsGoto = 0; } | 
    CALL AS GOTO { ((struct _Environment *)_environment)->optionCallAsGoto = 1; } | 
    CLIP on_off_optional { ((struct _Environment *)_environment)->optionClip = $2; } |
    COMPILE on_targets {
        if ( ! $2 ) {
            printf("OPTION COMPILE does not allow to compile this source code on this target.\n");
            end_compilation( _environment );
            exit(EXIT_SUCCESS);
        }
    } | 
    DEFAULT TYPE datatype { ((struct _Environment *)_environment)->defaultVariableType = $3; } | 
    DIALECT ATARI { option_dialect( _environment, DI_ATARI_BASIC ); } | 
    DIALECT ATARI BASIC { option_dialect( _environment, DI_ATARI_BASIC ); } | 
    DIALECT TSB { option_dialect( _environment, DI_TSB ); } | 
    DIALECT UGBASIC { option_dialect( _environment, DI_UGBASIC ); } | 
    EXEC AS GOSUB { ((struct _Environment *)_environment)->optionExecAsGosub = 1; } | 
    EXEC AS GOTO { ((struct _Environment *)_environment)->optionExecAsGosub = 0; } | 
    EXPLICIT on_off_optional { ((struct _Environment *)_environment)->optionExplicit = $2; } | 
    FINAL HALT { ((struct _Environment *)_environment)->finalReturn = 0; } | 
    FINAL RETURN { ((struct _Environment *)_environment)->finalReturn = 1; } | 
    LEFT INSERT { ((struct _Environment *)_environment)->leftReplace = 0; } | 
    LEFT REPLACE { ((struct _Environment *)_environment)->leftReplace = 1; } | 
    MID INSERT { ((struct _Environment *)_environment)->midReplace = 0; } | 
    MID REPLACE { ((struct _Environment *)_environment)->midReplace = 1; } | 
    READ safe_fast_optional { ((struct _Environment *)_environment)->optionReadSafe = $2; } | 
    TYPE NARROW { ((struct _Environment *)_environment)->defaultNarrowType = 1; } | 
    TYPE SIGNED { ((struct _Environment *)_environment)->defaultUnsignedType = 0; } | 
    TYPE UNSIGNED { ((struct _Environment *)_environment)->defaultUnsignedType = 1; } | 
    TYPE WIDE { ((struct _Environment *)_environment)->defaultNarrowType = 0; };

/*-----------------------------------------------------------------------------
 ------------ ORIGIN DEFINITION
 ----------------------------------------------------------------------------*/

origin_definitions:
    expr OP_COMMA expr origin_direction_optional {
            ((struct _Environment *)_environment)->originUsed = 1;
            variable_move( ((struct _Environment *)_environment), $1, "ORIGINX" );
            variable_move( ((struct _Environment *)_environment), $3, "ORIGINY" );
            ((struct _Environment *)_environment)->originYDirection = $4;
        };

/*-----------------------------------------------------------------------------
 ------------ RESOLUTION DEFINITION
 ----------------------------------------------------------------------------*/

resolution_definitions:
    expr OP_COMMA expr {
            ((struct _Environment *)_environment)->resolutionUsed = 1;
            variable_move( ((struct _Environment *)_environment), $1, "RESOLUTIONX" );
            variable_move( ((struct _Environment *)_environment), $3, "RESOLUTIONY" );
        };

/*-----------------------------------------------------------------------------
 ------------ OUT DEFINITION
 ----------------------------------------------------------------------------*/

out_definition: 
    expr OP_COMMA expr { out_var( _environment, $1, $3 ); };

/*-----------------------------------------------------------------------------
 ------------ LOAD TILE DEFINITION
 ----------------------------------------------------------------------------*/

tile_definition: 
    LOAD String TO Integer tile_load_flags { tile_load( _environment, $2, $5, NULL, $4 ); };

/*-----------------------------------------------------------------------------
 ------------ SYS/EXEC DEFINITION
 ----------------------------------------------------------------------------*/

sys_definition:
    expr on_targets {
            if ( $2 ) {
                sys_var( _environment, $1 );
            }
        } | 
    OP_HASH const_expr on_targets {
            if ( $3 ) {
                sys( _environment, $2 );
            }
        } | 
    expr WITH {
        ((struct _Environment *)_environment)->parameters = 0;
        ((struct _Environment *)_environment)->returns = 0;
        } values_asmios return_values_asmios on_targets {
            if ( $6 ) {
                sys_var( _environment, $1 );
            }
        } | 
    OP_HASH const_expr WITH {
        ((struct _Environment *)_environment)->parameters = 0;
        ((struct _Environment *)_environment)->returns = 0;
        } values_asmios return_values_asmios on_targets {
            if ( $7 ) {
                sys( _environment, $2 );
            }
        };

exec_definition:
    sys_definition | 
    IdentifierSpaced {
            if (  ((struct _Environment *)_environment)->optionExecAsGosub ) {
                call_procedure( _environment, $1 );
            } else {
                goto_label( _environment, $1 );
            }
        };

/*-----------------------------------------------------------------------------
 ------------ DATA DEFINITION
 ----------------------------------------------------------------------------*/

data_definition_single:
    const_expr {
        if ( ((struct _Environment *)_environment)->currentType ) {
            Constant * c = malloc( sizeof( Constant ) );
            memset( c, 0, sizeof( Constant ) );

            c->value = $1;
            
            if ( ((struct _Environment *)_environment)->currentFieldsValues ) {
                Constant * last = ((struct _Environment *)_environment)->currentFieldsValues;
                while( last->next ) {
                    last = last->next;
                }
                last->next = c;
            } else {
                ((struct _Environment *)_environment)->currentFieldsValues = c;
            }

            ((struct _Environment *)_environment)->currentField = ((struct _Environment *)_environment)->currentField->next;
            if ( ! ((struct _Environment *)_environment)->currentField ) {
                data_type( _environment );
                ((struct _Environment *)_environment)->currentField = ((struct _Environment *)_environment)->currentType->first;
                ((struct _Environment *)_environment)->currentFieldsValues = NULL;
            }
        } else {
            data_numeric( _environment, $1 );
        }
    } | 
    const_expr_floating { data_floating( _environment, $1 ); } | 
    const_expr_string { data_string( _environment, $1 ); } | 
    OSP const_expr_string_const CSP { data_string( _environment, $2 ); };

data_definition_data:
    data_definition_single {
            if ( ((struct _Environment *)_environment)->currentType ) {
                if ( ((struct _Environment *)_environment)->currentField != ((struct _Environment *)_environment)->currentType->first ) {
                    CRITICAL_DATA_NOT_ENOUGH_FOR_TYPE( ((struct _Environment *)_environment)->currentType->name );
                }
            }
        } | 
    data_definition_single OP_COMMA data_definition_data | 
    LOAD String AS TEXT {
            FILE * handle = fopen( $2, "rt" );
            if ( ! handle ) {
                CRITICAL_DATA_LOAD_TEXT_NOT_FOUND( $2 );
            }
            while( !feof( handle ) ) {
                char valueString[MAX_TEMPORARY_STORAGE];
                memset( valueString, 0, MAX_TEMPORARY_STORAGE );
                int p=0, j=0;
                while( !feof( handle ) ) {
                    char c = fgetc(handle);
                    if ( j == 0 ) {
                        if ( (c < '0') || (c > '9') ) {
                            continue;
                        }
                        j = 1;
                    } else {
                        if ( (c < '0') || (c > '9') ) {
                            break;
                        }
                    }
                    valueString[p] = c;
                    ++p;
                }
                data_numeric( _environment, atoi( valueString ) );
            }
            fclose( handle );
        };

data_definition:
    {
        ((struct _Environment *)_environment)->currentType = NULL;
        ((struct _Environment *)_environment)->currentField = NULL;
        ((struct _Environment *)_environment)->dataDataType = 0;
    } data_definition_data | 
    as_datatype_mandatory {
        ((struct _Environment *)_environment)->currentType = NULL;
        ((struct _Environment *)_environment)->currentField = NULL;
        ((struct _Environment *)_environment)->dataDataType = $1;
        if ( ((struct _Environment *)_environment)->dataDataType == VT_TYPE ) {
            ((struct _Environment *)_environment)->currentField = ((struct _Environment *)_environment)->currentType->first;
        }
    } data_definition_data;

/*-----------------------------------------------------------------------------
 ------------ CLEAR DEFINITION
 ----------------------------------------------------------------------------*/

clear_definition: 
    const_expr {
        if ( $1 <= 0 ) {
            CRITICAL_INVALID_STRING_SPACE( $1 );
        }
        ((struct _Environment *)_environment)->dstring.space = $1;
        clear( _environment );
        cpu_dsinit( _environment );
    };

/*-----------------------------------------------------------------------------
 ------------ PMODE DEFINITION
 ----------------------------------------------------------------------------*/

pmode_definition:
    expr OP_COMMA expr {
            Variable * expr1 = variable_retrieve( _environment, $1 );
            if ( ! expr1->initializedByConstant ) {
                CRITICAL_PMODE_NEEDS_CONSTANTS( );
            }
            Variable * expr2 = variable_retrieve( _environment, $3 );
            if ( ! expr2->initializedByConstant ) {
                CRITICAL_PMODE_NEEDS_CONSTANTS( );
            }
            pmode( _environment, expr1->value, expr2->value );
        } | 
    OP_HASH const_expr OP_COMMA OP_HASH const_expr { pmode( _environment, $2, $5 ); };

/*-----------------------------------------------------------------------------
 ------------ PAINT DEFINITION
 ----------------------------------------------------------------------------*/

paint_definition:
    expr OP_COMMA expr OP_COMMA expr  {
        Variable * color = sbpen_get( _environment, $5 );
        paint_vars( _environment, $1, $3, color->name, NULL );
    } | 
    OP expr OP_COMMA expr CP { paint_vars( _environment, $2, $4, NULL, NULL ); } | 
    OP expr OP_COMMA expr CP OP_COMMA expr { paint_vars( _environment, $2, $4, $7, NULL ); } | 
    OP expr OP_COMMA expr CP OP_COMMA OP_COMMA expr { paint_vars( _environment, $2, $4, NULL, $8 ); } |
    OP expr OP_COMMA expr CP OP_COMMA expr OP_COMMA expr { paint_vars( _environment, $2, $4, $7, $9 ); }     ;

/*-----------------------------------------------------------------------------
 ------------ BORDER DEFINITION
 ----------------------------------------------------------------------------*/

border_definition:
    expr { color_border_var( _environment, $1 ); };

/*-----------------------------------------------------------------------------
 ------------ DSAVE DEFINITION
 ----------------------------------------------------------------------------*/

dsave_to_offset:
    { $$ = NULL; } |
    TO expr { $$ = $2; };

dsave_from_address:
    { $$ = NULL; } |
    FROM expr { $$ = $2; };

dsave_size_size:
    { $$ = NULL; } |
    SIZE expr { $$ = $2; };

dsave_definition:
    expr dsave_to_offset dsave_from_address dsave_size_size { dsave( _environment, $1, $2, $3, $4 ); };

/*-----------------------------------------------------------------------------
 ------------ DLOAD DEFINITION
 ----------------------------------------------------------------------------*/

dload_to_bank:
    { $$ = NULL; } |
    BANK expr { $$ = $2; };

dload_from_offset:
    { $$ = NULL; } |
    FROM expr { $$ = $2; };

dload_to_address:
    { $$ = NULL; } |
    TO expr { $$ = $2; };

dload_size_size:
    { $$ = NULL; } |
    SIZE expr { $$ = $2; };

dload_definition:
    expr dload_from_offset dload_to_address dload_to_bank dload_size_size { dload( _environment, $1, $2, $3, $4, $5 ); };

/*-----------------------------------------------------------------------------
 ------------ CHAIN DEFINITION
 ----------------------------------------------------------------------------*/

chain_definition:
    expr { chain( _environment, $1 ); };

/*-----------------------------------------------------------------------------
 ------------ DEFDGR DEFINITION
 ----------------------------------------------------------------------------*/

defdgr_definition:
    OP_DOLLAR OP expr CP OP_ASSIGN expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr { defdgr_vars( _environment, $3, $6, $8, $10, $12, $14, $16, $18, $20 ); } | 
    OP expr CP OP_ASSIGN expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr { defdgr_vars( _environment, $2, $5, $7, $9, $11, $13, $15, $17, $19 ); };

/*-----------------------------------------------------------------------------
 ------------ FLIP DEFINITION
 ----------------------------------------------------------------------------*/

flip_definition:
    IMAGE expr flip_image_flags { flip_image_vars_direction( _environment, $2, NULL, NULL, $3 ); } | 
    IMAGE expr frame OP_HASH Identifier flip_image_flags {
        Variable * images = variable_retrieve( _environment, $2 );
        Variable * calculatedFrame = calculate_frame_by_type( _environment, images->originalTileset, $2, $5 );
        flip_image_vars_direction( _environment, $2, calculatedFrame->name, NULL, $6 );
    } | 
    IMAGE expr sequence_or_strip expr frame expr flip_image_flags { flip_image_vars_direction( _environment, $2, $6, $4, $7 ); } | 
    IMAGE expr frame expr flip_image_flags { flip_image_vars_direction( _environment, $2, $4, NULL, $5 ); } | 
    flip_image_flags IMAGE expr { flip_image_vars_direction( _environment, $3, NULL, NULL, $1 ); } | 
    flip_image_flags IMAGE expr frame OP_HASH Identifier {
        Variable * images = variable_retrieve( _environment, $3 );
        Variable * calculatedFrame = calculate_frame_by_type( _environment, images->originalTileset, $3, $6 );
        flip_image_vars_direction( _environment, $3, calculatedFrame->name, NULL, $1 );
    } | 
    flip_image_flags IMAGE expr sequence_or_strip expr frame expr { flip_image_vars_direction( _environment, $3, $7, $5, $1 ); } | 
    flip_image_flags IMAGE expr frame expr { flip_image_vars_direction( _environment, $3, $5, NULL, $1 ); } | 
    IMAGE expr DIRECTION expr { flip_image_vars_indirection( _environment, $2, NULL, NULL, $4 ); } | 
    IMAGE expr frame OP_HASH Identifier DIRECTION expr {
        Variable * images = variable_retrieve( _environment, $2 );
        Variable * calculatedFrame = calculate_frame_by_type( _environment, images->originalTileset, $2, $5 );
        flip_image_vars_indirection( _environment, $2, calculatedFrame->name, NULL, $7 );
    } | 
    IMAGE expr sequence_or_strip expr frame expr DIRECTION expr { flip_image_vars_indirection( _environment, $2, $6, $4, $8 ); } | 
    IMAGE expr frame expr DIRECTION expr { flip_image_vars_indirection( _environment, $2, $4, NULL, $6 ); } |
    DIRECTION expr IMAGE expr { flip_image_vars_indirection( _environment, $4, NULL, NULL, $2 ); } | 
    DIRECTION expr IMAGE expr frame OP_HASH Identifier {
        Variable * images = variable_retrieve( _environment, $4 );
        Variable * calculatedFrame = calculate_frame_by_type( _environment, images->originalTileset, $4, $7 );
        flip_image_vars_indirection( _environment, $4, calculatedFrame->name, NULL, $2 );
    } | 
    DIRECTION expr IMAGE expr sequence_or_strip expr frame expr { flip_image_vars_indirection( _environment, $4, $8, $6, $2 ); } | 
    DIRECTION expr IMAGE expr frame expr { flip_image_vars_indirection( _environment, $4, $6, NULL, $2 ); };

/*-----------------------------------------------------------------------------
 ------------ KILL DEFINITION
 ----------------------------------------------------------------------------*/

kill_definition: 
    {
        ((struct _Environment *)_environment)->lastThreadIdentifierUsed = 0;
        memset( ((struct _Environment *)_environment)->threadIdentifier, 0, MAX_TEMPORARY_STORAGE * sizeof( char * ) );
    } thread_identifiers on_targets {
        if ( $3 ) {
            for( int i=0; i<((struct _Environment *)_environment)->lastThreadIdentifierUsed; ++i ) {
                kill_procedure( _environment, ((struct _Environment *)_environment)->threadIdentifier[i] );
            }
        }
    };

/*-----------------------------------------------------------------------------
 ------------ STOP DEFINITION
 ----------------------------------------------------------------------------*/

stop_definition: 
    Identifier { stop_animation( _environment, $1 ); } | 
    ANIMATION Identifier { stop_animation( _environment, $2 ); } | 
    MOVEMENT Identifier { stop_movement( _environment, $2 ); };

/*-----------------------------------------------------------------------------
 ------------ SPAWN DEFINITION
 ----------------------------------------------------------------------------*/

spawn_definition:
    Identifier on_targets {
            if ( $2 ) {
                ((struct _Environment *)_environment)->parameters = 0;
                spawn_procedure( _environment, $1, 0 );
            }
        } | 
    Identifier OSP {
            ((struct _Environment *)_environment)->parameters = 0;
            } values CSP on_targets {
            if ( $6 ) {
                spawn_procedure( _environment, $1, 0 );
            }
        } | 
    Identifier OSP CSP on_targets {
            ((struct _Environment *)_environment)->parameters = 0;
            if ( $4 ) {
                spawn_procedure( _environment, $1, 0 );
            }
        } | 
    Identifier OP_COMMA Identifier on_targets {
            if ( $4 ) {
                Variable * variable = variable_retrieve( _environment, $1 );
                if ( variable->type != VT_TARRAY || variable->arrayType != VT_THREAD ) {
                    ((struct _Environment *)_environment)->parameters = 0;
                    variable_move( _environment, spawn_procedure( _environment, $3, 0 )->name, variable->name );
                } else {
                    for( int i=0; i<variable->size; ++i ) {
                        parser_array_init( _environment );
                        parser_array_index_numeric( _environment, i );
                        ((struct _Environment *)_environment)->parameters = 0;
                        variable_move_array( _environment, variable->name, spawn_procedure( _environment, $3, 0 )->name );
                    }
                }
            }
        } | 
    Identifier OP_COMMA Identifier OSP {
            ((struct _Environment *)_environment)->parameters = 0;
            } values CSP on_targets {
            if ( $8 ) {
                    Variable * variable = variable_retrieve( _environment, $1 );
                    if ( variable->type != VT_TARRAY || variable->arrayType != VT_THREAD ) {
                        ((struct _Environment *)_environment)->parameters = 0;
                        variable_move( _environment, spawn_procedure( _environment, $3, 0 )->name, variable->name );
                    } else {
                        for( int i=0; i<variable->size; ++i ) {
                            parser_array_init( _environment );
                            parser_array_index_numeric( _environment, i );
                            ((struct _Environment *)_environment)->parameters = 0;
                            variable_move_array( _environment, variable->name, spawn_procedure( _environment, $3, 0 )->name );
                        }
                    }
            }
        } | 
    Identifier OP_COMMA Identifier OSP CSP on_targets {
            ((struct _Environment *)_environment)->parameters = 0;
            if ( $6 ) {
                    Variable * variable = variable_retrieve( _environment, $1 );
                    if ( variable->type != VT_TARRAY || variable->arrayType != VT_THREAD ) {
                        ((struct _Environment *)_environment)->parameters = 0;
                        variable_move( _environment, spawn_procedure( _environment, $3, 0 )->name, variable->name );
                    } else {
                        for( int i=0; i<variable->size; ++i ) {
                            parser_array_init( _environment );
                            parser_array_index_numeric( _environment, i );
                            ((struct _Environment *)_environment)->parameters = 0;
                            variable_move_array( _environment, variable->name, spawn_procedure( _environment, $3, 0 )->name );
                        }
                    }
            }
        };

/*-----------------------------------------------------------------------------
 ------------ HIRES DEFINITION
 ----------------------------------------------------------------------------*/

hires_definition_expression:
    expr OP_COMMA expr { hires( _environment, $1, $3 ); };

hires_definition: 
    hires_definition_expression;

/*-----------------------------------------------------------------------------
 ------------ MULTI DEFINITION
 ----------------------------------------------------------------------------*/

multi_definition_expression:
    expr OP_COMMA expr OP_COMMA expr {
        bitmap_enable( _environment, 0, 0, 32 );
        sbpen_set( _environment, 1, $1 );
        sbpen_set( _environment, 2, $3 );
        sbpen_set( _environment, 3, $5 );
    } |
    ON { bitmap_enable( _environment, 0, 0, 32 ); };

multi_definition: 
    multi_definition_expression;

/*-----------------------------------------------------------------------------
 ------------ MOD DEFINITION
 ----------------------------------------------------------------------------*/

mod_definition_expression:
    expr OP_COMMA expr {
        sbpen_set( _environment, 1, $1 );
        sbpen_set( _environment, 0, $3 );
        paper( _environment, $3 );
    };

mod_definition: 
    mod_definition_expression;

/*-----------------------------------------------------------------------------
 ------------ KEY GET DEFINITION
 ----------------------------------------------------------------------------*/

keyget_definition:
    Identifier as_datatype_suffix_optional {
        if ( $2 != 0 ) {
            if ( $2 != VT_STRING && $2 != VT_DSTRING ) {
                CRITICAL_GET_NEED_STRING( $2 );
            }
        }
        wait_key( _environment, 0 );
        Variable * p = variable_retrieve_or_define( _environment, $1, VT_DSTRING, 0 );
        Variable * k = inkey( _environment );
        variable_move( _environment, k->name, p->name );
    };

/*-----------------------------------------------------------------------------
 ------------ AT DEFINITION
 ----------------------------------------------------------------------------*/

at_definition:
    OP Identifier as_datatype_suffix_optional OP_COMMA Identifier as_datatype_suffix_optional CP {
            if ( ($3 != 0) && ($6 != 0) && ($3 != $6) ) {
                CRITICAL_CANNOT_SWAP_DIFFERENT_DATATYPES( DATATYPE_AS_STRING[$3], DATATYPE_AS_STRING[$6] );
            }
            if ( $3 != VT_DSTRING ) {
                Variable * v1 = variable_retrieve( _environment, $2 );
                if ( v1->type != VT_DSTRING ) {
                    CRITICAL_AT_UNSUPPORTED( v1->name, DATATYPE_AS_STRING[v1->type]);
                }
            }
            if ( $6 != VT_DSTRING ) {
                Variable * v2 = variable_retrieve( _environment, $5 );
                if ( v2->type != VT_DSTRING ) {
                    CRITICAL_AT_UNSUPPORTED( v2->name, DATATYPE_AS_STRING[v2->type]);
                }
            }
            variable_swap( _environment, $2, $5 );
        } | 
    Identifier as_datatype_suffix_optional OP_COMMA Identifier as_datatype_suffix_optional {
            if ( ($2 != 0) && ($5 != 0) && ($2 != $5) ) {
                CRITICAL_CANNOT_SWAP_DIFFERENT_DATATYPES( DATATYPE_AS_STRING[$2], DATATYPE_AS_STRING[$5] );
            }
            if ( $2 != VT_DSTRING ) {
                Variable * v1 = variable_retrieve( _environment, $1 );
                if ( v1->type != VT_DSTRING ) {
                    CRITICAL_AT_UNSUPPORTED( v1->name, DATATYPE_AS_STRING[v1->type]);
                }
            }
            if ( $5 != VT_DSTRING ) {
                Variable * v2 = variable_retrieve( _environment, $4 );
                if ( v2->type != VT_DSTRING ) {
                    CRITICAL_AT_UNSUPPORTED( v2->name, DATATYPE_AS_STRING[v2->type]);
                }
            }
            variable_swap( _environment, $1, $4 );
        };

/*-----------------------------------------------------------------------------
 ------------ NRM DEFINITION
 ----------------------------------------------------------------------------*/

nrm_definition:
    {
        tilemap_enable( _environment, 0, 0, 0, 0, 0 );
        cls( _environment, NULL );
    };

/*-----------------------------------------------------------------------------
 ------------ CHAR DEFINITION
 ----------------------------------------------------------------------------*/

char_definition:
    mandatory_x OP_COMMA mandatory_y OP_COMMA expr OP_COMMA expr OP_COMMA expr { char_at( _environment, $1, $3, $5, $7, $9 ); };

/*-----------------------------------------------------------------------------
 ------------ CENTER DEFINITION
 ----------------------------------------------------------------------------*/

center_definition: 
  expr OP_SEMICOLON { center( _environment, $1, 0, NULL); } | 
  expr { center( _environment, $1, 1, NULL ); } | 
  expr OP_COMMA expr { center( _environment, $1, 1, $3 ); } | 
  AT OP expr OP_COMMA expr CP expr OP_COMMA expr {
      locate( _environment, $3, $5 );
      center( _environment, $7, 0, $9 );
  }
  ;

/*-----------------------------------------------------------------------------
 ------------ VCENTER DEFINITION
 ----------------------------------------------------------------------------*/

vcenter_definition: 
  expr OP_SEMICOLON { vcenter( _environment, $1, 0 ); } | 
  expr { vcenter( _environment, $1, 1 ); } | 
  expr OP_COMMA expr { vcenter( _environment, $1, 1 ); };

/*-----------------------------------------------------------------------------
 ------------ VHCENTER DEFINITION
 ----------------------------------------------------------------------------*/

vhcenter_definition: 
  expr OP_SEMICOLON { vhcenter( _environment, $1, 0, NULL); } | 
  expr { vhcenter( _environment, $1, 1, NULL ); } | 
  expr OP_COMMA expr { vhcenter( _environment, $1, 1, $3 ); };

/*-----------------------------------------------------------------------------
 ------------ INSERT DEFINITION
 ----------------------------------------------------------------------------*/

insert_definition: 
    expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr { insert( _environment, $1, $3, $5, $7, $9, $11 ); };

/*-----------------------------------------------------------------------------
 ------------ ENVELOPE DEFINITION
 ----------------------------------------------------------------------------*/

envelope_definition:
    expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr { envelope( _environment, $1, $3, $5, $7, $9 ); };

/*-----------------------------------------------------------------------------
 ------------ PAUSE DEFINITION
 ----------------------------------------------------------------------------*/

pause_definition:
    expr { pause_seconds( _environment, NULL, $1 ); } | 
    expr OP_COMMA expr { pause_seconds( _environment, $1, $3 ); };

/*-----------------------------------------------------------------------------
 ------------ SUSPEND DEFINITION
 ----------------------------------------------------------------------------*/

suspend_definition:
    expr { suspend_vars( _environment, $1 ); };

/*-----------------------------------------------------------------------------
 ------------ FREEZE DEFINITION
 ----------------------------------------------------------------------------*/

freeze_definition:
    Identifier { freeze_vars( _environment, $1 ); };

/*-----------------------------------------------------------------------------
 ------------ RESUME DEFINITION
 ----------------------------------------------------------------------------*/

resume_definition:
    expr { resume_vars( _environment, $1 ); };

/*-----------------------------------------------------------------------------
 ------------ UNFREEZE DEFINITION
 ----------------------------------------------------------------------------*/

unfreeze_definition:
    Identifier { unfreeze_vars( _environment, $1 ); };

/*-----------------------------------------------------------------------------
 ------------ WAVE DEFINITION
 ----------------------------------------------------------------------------*/

wave_definition:
    expr OP_COMMA expr { wave( _environment, $1, $3, NULL ); } | 
    expr OP_COMMA expr OP_COMMA expr { wave( _environment, $1, $3, $5 ); }

/*-----------------------------------------------------------------------------
 ------------ CSET DEFINITION
 ----------------------------------------------------------------------------*/

cset_definition: 
    expr { cset( _environment, $1 ); };

/*-----------------------------------------------------------------------------
 ------------ ROT DEFINITION
 ----------------------------------------------------------------------------*/

rot_definition:
    expr { rot( _environment, $1, NULL ); } | 
    expr OP_COMMA expr { rot( _environment, $1, $3 ); };

/*-----------------------------------------------------------------------------
 ------------ KEY DEFINITION
 ----------------------------------------------------------------------------*/

key_definition:
    SPEED const_expr milliseconds OP_COMMA const_expr milliseconds OP_COMMA const_expr milliseconds {
            int latency = $2 / 20;
            if ( latency <= 0 || latency >= 256 ) {
                CRITICAL_INVALID_INPUT_LATENCY_MS( $2 );
            }
            ((struct _Environment *)_environment)->keyboardConfig.latency = latency;
            int delay = $5 / 20;
            if ( delay <= 0 || delay >= 256 ) {
                CRITICAL_INVALID_INPUT_DELAY_MS( $5 );
            }
            ((struct _Environment *)_environment)->keyboardConfig.delay = delay;
            int release = $8 / 20;
            if ( release <= 0 || release >= 256 ) {
                CRITICAL_INVALID_INPUT_RELEASE_MS( $8 );
            }
            ((struct _Environment *)_environment)->keyboardConfig.release = release;
        } | 
    SPEED const_expr OP_COMMA const_expr OP_COMMA const_expr {
            int latency = $2;
            if ( latency <= 0 || latency >= 256 ) {
                CRITICAL_INVALID_INPUT_LATENCY_MS( $2 );
            }
            ((struct _Environment *)_environment)->keyboardConfig.latency = latency;
            int delay = $4;
            if ( delay <= 0 || delay >= 256 ) {
                CRITICAL_INVALID_INPUT_DELAY_MS( $4 );
            }
            ((struct _Environment *)_environment)->keyboardConfig.delay = delay;
            int release = $6;
            if ( release <= 0 || release >= 256 ) {
                CRITICAL_INVALID_INPUT_RELEASE_MS( $6 );
            }
            ((struct _Environment *)_environment)->keyboardConfig.release = release;
        };

/*-----------------------------------------------------------------------------
 ------------ CHECK DEFINITION
 ----------------------------------------------------------------------------*/

check_definition:
    Identifier { } | 
    IdentifierSpaced { };

/*-----------------------------------------------------------------------------
 ------------ MOB DEFINITION
 ----------------------------------------------------------------------------*/

mob_definition:
    ON {
            for( int i=0; i<(SPRITE_COUNT-1); ++i ) {
                sprite_enable( _environment, i );
            }
        } | 
    ON expr { sprite_enable_var( _environment, $2 ); } | 
    OFF {
            for( int i=0; i<(SPRITE_COUNT-1); ++i ) {
                sprite_disable( _environment, i );
            }
        } | 
    OFF expr { sprite_disable_var( _environment, $2 ); };

/*-----------------------------------------------------------------------------
 ------------ CMOB DEFINITION
 ----------------------------------------------------------------------------*/

cmob_definition:
    expr OP_COMMA expr {
        color_sprite_semi_vars( _environment, 0, $1 );
        color_sprite_semi_vars( _environment, 1, $3 );
    };

/*-----------------------------------------------------------------------------
 ------------ DOJO DEFINITION
 ----------------------------------------------------------------------------*/

dojo_definition:
    PUT Identifier OP_COMMA expr OP_COMMA expr {
            Variable * id = variable_retrieve( _environment, $2 );
            if ( id->type != VT_DOJOKA ) {
                DOJO_PUT_MESSAGE_MISSING_VARIABLE( );
            }
            dojo_put_message( _environment, $2, $4, $6 );
        } | 
    PUT MESSAGE expr OP_COMMA expr OP_COMMA expr { dojo_put_message( _environment, $3, $5, $7 ); } |
    PUT Identifier OP_COMMA expr {
            Variable * id = variable_retrieve( _environment, $2 );
            if ( id->type != VT_DOJOKA ) {
                DOJO_PUT_MESSAGE_MISSING_VARIABLE( );
            }
            dojo_put_message( _environment, $2, NULL, $4 );
        } | 
    PUT MESSAGE expr OP_COMMA expr { dojo_put_message( _environment, $3, NULL, $5 ); } | 
    GET MESSAGE expr OP_COMMA expr { dojo_get_message_inplace( _environment, $3, NULL, $5 ); } | 
    GET MESSAGE expr OP_COMMA expr OP_COMMA expr { dojo_get_message_inplace( _environment, $3, $5, $7 ); } |
    PING { dojo_ping( _environment, NULL, NULL ); } | 
    PING expr { dojo_ping( _environment, $2, NULL ); } | 
    PING expr OP_COMMA expr { dojo_ping( _environment, $2, $4 ); };

/*-----------------------------------------------------------------------------
 ------------ FUJINET DEFINITION
 ----------------------------------------------------------------------------*/

fujinet_definition:
    DEVICE expr {
            Variable * expr = variable_retrieve( _environment, $2 );
            if ( expr->initializedByConstant ) {
                fujinet_set_device( _environment, expr->value );        
            } else {
                fujinet_set_device_var( _environment, $2 );        
            }
        } | 
    SET CHANNEL MODE expr { fujinet_set_channel_mode_var( _environment, $4 ); } | 
    CLOSE { fujinet_close( _environment ); } | 
    OPEN expr OP_COMMA expr OP_COMMA expr { fujinet_open( _environment, $2, $4, $6 ); } | 
    PARSE JSON { fujinet_parse_json( _environment ); } | 
    SET JSON QUERY expr { fujinet_json_query( _environment, $4 ); } | 
    STATUS { fujinet_get_status( _environment ); } | 
    LOGIN expr { fujinet_login( _environment, $2 ); } | 
    PASSWORD expr { fujinet_password( _environment, $2 ); } | 
    WRITE expr { fujinet_write( _environment, $2 ); } | 
    WRITE expr as_datatype_mandatory { fujinet_write_type( _environment, $2, $3 ); };

/*-----------------------------------------------------------------------------
 ------------ TRAVEL DEFINITION
 ----------------------------------------------------------------------------*/

optional_clamp: 
    {
        $$ = NULL;
    }
    | CLAMP {
        Variable * trueValue = variable_temporary( _environment, VT_SBYTE, "(true)");
        variable_store( _environment, trueValue->name, 0xff );
        $$ = trueValue->name;
    };

travel_definition_array_first:
    Identifier field_optional {
            if ( $2 ) {
                ((struct _Environment *)_environment)->travelX = $1;
                ((struct _Environment *)_environment)->travelXF = $2;
                ((struct _Environment *)_environment)->travelXAR = NULL;
            } else {
                ((struct _Environment *)_environment)->travelX = $1;
                ((struct _Environment *)_environment)->travelXF = NULL;
                ((struct _Environment *)_environment)->travelXAR = NULL;
            }
        } | 
    Identifier OP {
            parser_array_init( _environment );
            define_implicit_array_if_needed( _environment, $1 );        
        } indexes CP field_optional {
            ((struct _Environment *)_environment)->travelX = $1;
            ((struct _Environment *)_environment)->travelXF = $6;
            ((struct _Environment *)_environment)->travelXAR = parser_array_retrieve( _environment );
            parser_array_cleanup( _environment );        
        };

travel_definition_array_second:
    Identifier field_optional {
            ((struct _Environment *)_environment)->travelY = $1;
            ((struct _Environment *)_environment)->travelYF = $2;
            ((struct _Environment *)_environment)->travelYAR = NULL;
    } | 
    Identifier OP {
            parser_array_init( _environment );
            define_implicit_array_if_needed( _environment, $1 );        
        } indexes CP field_optional {
            ((struct _Environment *)_environment)->travelY = $1;
            ((struct _Environment *)_environment)->travelYF = $6;
            ((struct _Environment *)_environment)->travelYAR = parser_array_retrieve( _environment );
            parser_array_cleanup( _environment );        
        };

travel_definition_array: 
    travel_definition_array_first OP_COMMA travel_definition_array_second;

travel_definition:
    Identifier TO travel_definition_array optional_by optional_clamp {
            char * x;
            if ( ((struct _Environment *)_environment)->travelXAR ) {
                Variable * ax = variable_retrieve( _environment, ((struct _Environment *)_environment)->travelX );
                if ( ((struct _Environment *)_environment)->travelXF ) {
                    if ( ! ax->typeType ) {
                        CRITICAL_VARIABLE_TYPE_NEEDED( ax->name );
                    }
                    Field * field = field_find( ax->typeType, ((struct _Environment *)_environment)->travelXF );
                    if ( ! field ) {
                        CRITICAL_UNKNOWN_FIELD_ON_TYPE( ((struct _Environment *)_environment)->travelXF );
                    }
                    x = variable_temporary( _environment, field->type, "(x)" )->name;
                } else {
                    x = variable_temporary( _environment, ax->arrayType, "(x)" )->name;
                }
            } else {
                x = ((struct _Environment *)_environment)->travelX;
            }
            char * y;
            if ( ((struct _Environment *)_environment)->travelYAR ) {
                Variable * ay = variable_retrieve( _environment, ((struct _Environment *)_environment)->travelY );
                if ( ((struct _Environment *)_environment)->travelYF ) {
                    if ( ! ay->typeType ) {
                        CRITICAL_VARIABLE_TYPE_NEEDED( ay->name );
                    }
                    Field * field = field_find( ay->typeType, ((struct _Environment *)_environment)->travelYF );
                    if ( ! field ) {
                        CRITICAL_UNKNOWN_FIELD_ON_TYPE( ((struct _Environment *)_environment)->travelYF );
                    }
                    y = variable_temporary( _environment, field->type, "(y)" )->name;
                } else {
                    y = variable_temporary( _environment, ay->arrayType, "(y)" )->name;
                }
            } else {
                y = ((struct _Environment *)_environment)->travelY;
            }
            travel_path( _environment, $1, x, y, $4, $5 );
            if ( ((struct _Environment *)_environment)->travelXAR ) {
                parser_array_init_by( _environment, ((struct _Environment *)_environment)->travelXAR );
                if ( ((struct _Environment *)_environment)->travelXF ) {
                    variable_move_array_type( _environment, ((struct _Environment *)_environment)->travelX, ((struct _Environment *)_environment)->travelXF, x );
                } else {
                    variable_move_array( _environment, ((struct _Environment *)_environment)->travelX, x );
                }
            }
            if ( ((struct _Environment *)_environment)->travelYAR ) {
                parser_array_init_by( _environment, ((struct _Environment *)_environment)->travelYAR );
                if ( ((struct _Environment *)_environment)->travelYF ) {
                    variable_move_array_type( _environment, ((struct _Environment *)_environment)->travelY, ((struct _Environment *)_environment)->travelYF, y );
                } else {
                    variable_move_array( _environment, ((struct _Environment *)_environment)->travelY, y );
                }
            }
        } | 
    Identifier OP {
            parser_array_init( _environment );
            define_implicit_array_if_needed( _environment, $1 );
        } indexes CP TO travel_definition_array optional_by optional_clamp {
            Variable * path = variable_move_from_array( _environment, $1 );
            char * x;
            if ( ((struct _Environment *)_environment)->travelXAR ) {
                Variable * ax = variable_retrieve( _environment, ((struct _Environment *)_environment)->travelX );
                if ( ((struct _Environment *)_environment)->travelXF ) {
                    if ( ! ax->typeType ) {
                        CRITICAL_VARIABLE_TYPE_NEEDED( ax->name );
                    }
                    Field * field = field_find( ax->typeType, ((struct _Environment *)_environment)->travelXF );
                    if ( ! field ) {
                        CRITICAL_UNKNOWN_FIELD_ON_TYPE( ((struct _Environment *)_environment)->travelXF );
                    }
                    x = variable_temporary( _environment, field->type, "(x)" )->name;
                } else {
                    x = variable_temporary( _environment, ax->arrayType, "(x)" )->name;
                }
            } else {
                x = ((struct _Environment *)_environment)->travelX;
            }
            char * y;
            if ( ((struct _Environment *)_environment)->travelYAR ) {
                Variable * ay = variable_retrieve( _environment, ((struct _Environment *)_environment)->travelY );
                if ( ((struct _Environment *)_environment)->travelYF ) {
                    if ( ! ay->typeType ) {
                        CRITICAL_VARIABLE_TYPE_NEEDED( ay->name );
                    }
                    Field * field = field_find( ay->typeType, ((struct _Environment *)_environment)->travelYF );
                    if ( ! field ) {
                        CRITICAL_UNKNOWN_FIELD_ON_TYPE( ((struct _Environment *)_environment)->travelYF );
                    }
                    y = variable_temporary( _environment, field->type, "(y)" )->name;
                } else {
                    y = variable_temporary( _environment, ay->arrayType, "(y)" )->name;
                }
            } else {
                y = ((struct _Environment *)_environment)->travelY;
            }
            travel_path( _environment, path->name, x, y, $8, $9 );
            if ( ((struct _Environment *)_environment)->travelXAR ) {
                parser_array_init_by( _environment, ((struct _Environment *)_environment)->travelXAR );
                if ( ((struct _Environment *)_environment)->travelXF ) {
                    variable_move_array_type( _environment, ((struct _Environment *)_environment)->travelX, ((struct _Environment *)_environment)->travelXF, x );
                } else {
                    variable_move_array( _environment, ((struct _Environment *)_environment)->travelX, x );
                }
                parser_array_cleanup( _environment );        
            }
            if ( ((struct _Environment *)_environment)->travelYAR ) {
                parser_array_init_by( _environment, ((struct _Environment *)_environment)->travelYAR );
                if ( ((struct _Environment *)_environment)->travelYF ) {
                    variable_move_array_type( _environment, ((struct _Environment *)_environment)->travelY, ((struct _Environment *)_environment)->travelYF, y );
                } else {
                    variable_move_array( _environment, ((struct _Environment *)_environment)->travelY, y );
                }
                parser_array_cleanup( _environment );        
            }        
            variable_move_array( _environment, $1, path->name );
            parser_array_cleanup( _environment );
        };

travel_function:
    OP Identifier TO travel_definition_array optional_by optional_clamp CP {
            char * x;
            if ( ((struct _Environment *)_environment)->travelXAR ) {
                Variable * ax = variable_retrieve( _environment, ((struct _Environment *)_environment)->travelX );
                if ( ((struct _Environment *)_environment)->travelXF ) {
                    if ( ! ax->typeType ) {
                        CRITICAL_VARIABLE_TYPE_NEEDED( ax->name );
                    }
                    Field * field = field_find( ax->typeType, ((struct _Environment *)_environment)->travelXF );
                    if ( ! field ) {
                        CRITICAL_UNKNOWN_FIELD_ON_TYPE( ((struct _Environment *)_environment)->travelXF );
                    }
                    x = variable_temporary( _environment, field->type, "(x)" )->name;
                } else {
                    x = variable_temporary( _environment, ax->arrayType, "(x)" )->name;
                }
            } else {
                x = ((struct _Environment *)_environment)->travelX;
            }
            char * y;
            if ( ((struct _Environment *)_environment)->travelYAR ) {
                Variable * ay = variable_retrieve( _environment, ((struct _Environment *)_environment)->travelY );
                if ( ((struct _Environment *)_environment)->travelYF ) {
                    if ( ! ay->typeType ) {
                        CRITICAL_VARIABLE_TYPE_NEEDED( ay->name );
                    }
                    Field * field = field_find( ay->typeType, ((struct _Environment *)_environment)->travelYF );
                    if ( ! field ) {
                        CRITICAL_UNKNOWN_FIELD_ON_TYPE( ((struct _Environment *)_environment)->travelYF );
                    }
                    y = variable_temporary( _environment, field->type, "(y)" )->name;
                } else {
                    y = variable_temporary( _environment, ay->arrayType, "(y)" )->name;
                }
            } else {
                y = ((struct _Environment *)_environment)->travelY;
            }
            $$ = travel_path( _environment, $2, x, y, $5, $6 )->name;
            if ( ((struct _Environment *)_environment)->travelXAR ) {
                parser_array_init_by( _environment, ((struct _Environment *)_environment)->travelXAR );
                if ( ((struct _Environment *)_environment)->travelXF ) {
                    variable_move_array_type( _environment, ((struct _Environment *)_environment)->travelX, ((struct _Environment *)_environment)->travelXF, x );
                } else {
                    variable_move_array( _environment, ((struct _Environment *)_environment)->travelX, x );
                }
                parser_array_cleanup( _environment );        
            }
            if ( ((struct _Environment *)_environment)->travelYAR ) {
                parser_array_init_by( _environment, ((struct _Environment *)_environment)->travelYAR );
                if ( ((struct _Environment *)_environment)->travelYF ) {
                    variable_move_array_type( _environment, ((struct _Environment *)_environment)->travelY, ((struct _Environment *)_environment)->travelYF, y );
                } else {
                    variable_move_array( _environment, ((struct _Environment *)_environment)->travelY, y );
                }
                parser_array_cleanup( _environment );
            }
        } | 
    OP Identifier OP {
            parser_array_init( _environment );
            define_implicit_array_if_needed( _environment, $2 );
        } indexes CP TO travel_definition_array optional_by optional_clamp CP {
            Variable * path = variable_move_from_array( _environment, $2 );
            char * x;
            if ( ((struct _Environment *)_environment)->travelXAR ) {
                Variable * ax = variable_retrieve( _environment, ((struct _Environment *)_environment)->travelX );
                if ( ((struct _Environment *)_environment)->travelXF ) {
                    if ( ! ax->typeType ) {
                        CRITICAL_VARIABLE_TYPE_NEEDED( ax->name );
                    }
                    Field * field = field_find( ax->typeType, ((struct _Environment *)_environment)->travelXF );
                    if ( ! field ) {
                        CRITICAL_UNKNOWN_FIELD_ON_TYPE( ((struct _Environment *)_environment)->travelXF );
                    }
                    x = variable_temporary( _environment, field->type, "(x)" )->name;
                } else {
                    x = variable_temporary( _environment, ax->arrayType, "(x)" )->name;
                }
            } else {
                x = ((struct _Environment *)_environment)->travelX;
            }
            char * y;
            if ( ((struct _Environment *)_environment)->travelYAR ) {
                Variable * ay = variable_retrieve( _environment, ((struct _Environment *)_environment)->travelY );
                if ( ((struct _Environment *)_environment)->travelYF ) {
                    if ( ! ay->typeType ) {
                        CRITICAL_VARIABLE_TYPE_NEEDED( ay->name );
                    }
                    Field * field = field_find( ay->typeType, ((struct _Environment *)_environment)->travelYF );
                    if ( ! field ) {
                        CRITICAL_UNKNOWN_FIELD_ON_TYPE( ((struct _Environment *)_environment)->travelYF );
                    }
                    y = variable_temporary( _environment, field->type, "(y)" )->name;
                } else {
                    y = variable_temporary( _environment, ay->arrayType, "(y)" )->name;
                }
            } else {
                y = ((struct _Environment *)_environment)->travelY;
            }
            $$ = travel_path( _environment, path->name, x, y, $9, $10 )->name;
            if ( ((struct _Environment *)_environment)->travelXAR ) {
                parser_array_init_by( _environment, ((struct _Environment *)_environment)->travelXAR );
                if ( ((struct _Environment *)_environment)->travelXF ) {
                    variable_move_array_type( _environment, ((struct _Environment *)_environment)->travelX, ((struct _Environment *)_environment)->travelXF, x );
                } else {
                    variable_move_array( _environment, ((struct _Environment *)_environment)->travelX, x );
                }
                parser_array_cleanup( _environment );        
            }
            if ( ((struct _Environment *)_environment)->travelYAR ) {
                parser_array_init_by( _environment, ((struct _Environment *)_environment)->travelYAR );
                if ( ((struct _Environment *)_environment)->travelYF ) {
                    variable_move_array_type( _environment, ((struct _Environment *)_environment)->travelY, ((struct _Environment *)_environment)->travelYF, y );
                } else {
                    variable_move_array( _environment, ((struct _Environment *)_environment)->travelY, y );
                }
                parser_array_cleanup( _environment );        
            }        
            variable_move_array( _environment, $2, path->name );
            parser_array_cleanup( _environment );
        };

/*-----------------------------------------------------------------------------
 ------------ ANIMATION DEFINITION
 ----------------------------------------------------------------------------*/

delay_optional: 
    { ((struct _Environment *)_environment)->animationDelay = 20; } | 
    DELAY const_expr { ((struct _Environment *)_environment)->animationDelay = $2; };

ease_in_delay_optional: 
    { ((struct _Environment *)_environment)->animationEaseInDelay = 20; } |
    DELAY const_expr { ((struct _Environment *)_environment)->animationEaseInDelay = $2; };

ease_in_optional: 
    {
            ((struct _Environment *)_environment)->animationEaseInFrames = 0;
            ((struct _Environment *)_environment)->animationEaseInDelay = 0;
        } |
    EASEIN const_expr ease_in_delay_optional {
        ((struct _Environment *)_environment)->animationEaseInFrames = $2;
    };

ease_out_delay_optional: 
    { ((struct _Environment *)_environment)->animationEaseOutDelay = 20; } |
    DELAY const_expr { ((struct _Environment *)_environment)->animationEaseOutDelay = $2; };

ease_out_optional: 
    {
            ((struct _Environment *)_environment)->animationEaseOutFrames = 0;
            ((struct _Environment *)_environment)->animationEaseOutDelay = 0;
        } |
    EASEOUT const_expr ease_out_delay_optional { ((struct _Environment *)_environment)->animationEaseOutFrames = $2; };

next_animation_optional:
    { $$ = NULL; ((struct _Environment *)_environment)->animationNextWithEaseIn = 0; } |
    NEXT Identifier { $$ = $2; ((struct _Environment *)_environment)->animationNextWithEaseIn = 0; } |
    NEXT WITH EASEIN Identifier { $$ = $4; ((struct _Environment *)_environment)->animationNextWithEaseIn = 1; };

wait_vbl_optional:
    { ((struct _Environment *)_environment)->animationWaitVbl = 0; } |
    WAIT VBL { ((struct _Environment *)_environment)->animationWaitVbl = 1; };

preserve_background_optional:
    { ((struct _Environment *)_environment)->animationPreserveBackground = 0; } |
    PRESERVE BACKGROUND { ((struct _Environment *)_environment)->animationPreserveBackground = 1; };

reverse_optional: 
    { ((struct _Environment *)_environment)->animationReverse = 0; } |
    REVERSE { ((struct _Environment *)_environment)->animationReverse = 1; };

next_animation_definition: 
    Identifier { next_animation( _environment, $1 ); };

animation_definition:
    reverse_optional animation_type Identifier WITH expr delay_optional ease_in_optional ease_out_optional USING Identifier next_animation_optional wait_vbl_optional preserve_background_optional { animation( _environment, $3, $5, $10, $11 ); };

animate_definition:
    Identifier WITH Identifier { animate_semivars( _environment, $1, $3, NULL, NULL ); } |
    Identifier WITH Identifier AT optional_x OP_COMMA optional_y { animate_semivars( _environment, $1, $3, $5, $7 ); };

/*-----------------------------------------------------------------------------
 ------------ MOVEMENT DEFINITION
 ----------------------------------------------------------------------------*/

movement_direction:
    LEFT {
            ((struct _Environment *)_environment)->movementDeltaX = -1;
            ((struct _Environment *)_environment)->movementDeltaY = 0;
        } | 
    RIGHT {
            ((struct _Environment *)_environment)->movementDeltaX = 1;
            ((struct _Environment *)_environment)->movementDeltaY = 0;
        } | 
    UP {
            ((struct _Environment *)_environment)->movementDeltaX = 0;
            ((struct _Environment *)_environment)->movementDeltaY = -1;
        } | 
    DOWN {
            ((struct _Environment *)_environment)->movementDeltaX = 0;
            ((struct _Environment *)_environment)->movementDeltaY = 1;
        } | 
    TO POSITION {
            ((struct _Environment *)_environment)->movementDeltaX = 0;
            ((struct _Environment *)_environment)->movementDeltaY = 0;
        } | 
    STEADY {
            ((struct _Environment *)_environment)->movementDeltaX = 2;
            ((struct _Environment *)_environment)->movementDeltaY = 2;
    };

movement_delay_optional:
    { ((struct _Environment *)_environment)->movementDelay = 20; } |
    DELAY const_expr { ((struct _Environment *)_environment)->movementDelay = $2; };

movement_definition:
    Identifier movement_direction WITH expr movement_delay_optional USING Identifier { movement( _environment, $1, $4, $7 ); } | 
    Identifier movement_direction movement_delay_optional USING Identifier { movement( _environment, $1, NULL, $5 ); };

/*-----------------------------------------------------------------------------
 ------------ MMOB DEFINITION
 ----------------------------------------------------------------------------*/

mmob_definition: 
    expr OP_COMMA expr OP_COMMA expr { mmob( _environment, $1, $3, $5, NULL, NULL, NULL, NULL ); } | 
    expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr { mmob( _environment, $1, $3, $5, $7, $9, NULL, NULL ); } |
    expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr { mmob( _environment, $1, $3, $5, $7, $9, $11, NULL ); } |
    expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr { mmob( _environment, $1, $3, $5, $7, $9, $11, $13 ); };

/*-----------------------------------------------------------------------------
 ------------ UPW/UPB DEFINITION
 ----------------------------------------------------------------------------*/

upw_definition:
    expr OP_COMMA expr OP_COMMA expr OP_COMMA expr { upw( _environment, $1, $3, $5, $7 ); };

upb_definition:
    expr OP_COMMA expr OP_COMMA expr OP_COMMA expr { upb( _environment, $1, $3, $5, $7 ); };

/*-----------------------------------------------------------------------------
 ------------ DOWNW/DOWNB DEFINITION
 ----------------------------------------------------------------------------*/

downw_definition:
    expr OP_COMMA expr OP_COMMA expr OP_COMMA expr { downw( _environment, $1, $3, $5, $7 ); };

downb_definition:
    expr OP_COMMA expr OP_COMMA expr OP_COMMA expr { downb( _environment, $1, $3, $5, $7 ); };

/*-----------------------------------------------------------------------------
 ------------ LEFTW/LEFTB DEFINITION
 ----------------------------------------------------------------------------*/

leftw_definition:
    expr OP_COMMA expr OP_COMMA expr OP_COMMA expr { leftw( _environment, $1, $3, $5, $7 ); };

leftb_definition:
    expr OP_COMMA expr OP_COMMA expr OP_COMMA expr { leftb( _environment, $1, $3, $5, $7 ); };

/*-----------------------------------------------------------------------------
 ------------ RIGHTW/RIGHTB DEFINITION
 ----------------------------------------------------------------------------*/

rightw_definition:
    expr OP_COMMA expr OP_COMMA expr OP_COMMA expr { rightw( _environment, $1, $3, $5, $7 ); };

rightb_definition:
    expr OP_COMMA expr OP_COMMA expr OP_COMMA expr { rightb( _environment, $1, $3, $5, $7 ); };

/*-----------------------------------------------------------------------------
 ------------ MEMLOAD DEFINITION
 ----------------------------------------------------------------------------*/

memload_definition:
    { memload( _environment ); };

/*-----------------------------------------------------------------------------
 ------------ MEMSAVE DEFINITION
 ----------------------------------------------------------------------------*/

memsave_definition:
    { memsave( _environment ); };

/*-----------------------------------------------------------------------------
 ------------ MEMPOS DEFINITION
 ----------------------------------------------------------------------------*/

mempos_definition:
    expr OP_COMMA expr { mempos( _environment, $1, $3 ); };

/*-----------------------------------------------------------------------------
 ------------ MEMOR DEFINITION
 ----------------------------------------------------------------------------*/

memor_definition:
    expr { memor( _environment, $1, NULL, NULL ); } | 
    expr OP_COMMA expr OP_COMMA expr { memor( _environment, $1, $3, $5 ); };

/*-----------------------------------------------------------------------------
 ------------ MEMDEF DEFINITION
 ----------------------------------------------------------------------------*/

memdef_definition:
    expr  { memdef( _environment, $1, NULL, NULL, NULL ); } | 
    expr OP_COMMA expr { memdef( _environment, $1, $3, NULL, NULL ); }  | 
    expr OP_COMMA expr OP_COMMA expr OP_COMMA expr { memdef( _environment, $1, $3, $5, $7 ); } |
    expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr { memdef( _environment, $1, $3, $5, $7 ); } |
    expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr { memdef( _environment, $1, $3, $5, $7 ); };

/*-----------------------------------------------------------------------------
 ------------ MEMLEN DEFINITION
 ----------------------------------------------------------------------------*/

memlen_definition:
    expr { memlen( _environment, $1 ); };

/*-----------------------------------------------------------------------------
 ------------ MEMRESTORE DEFINITION
 ----------------------------------------------------------------------------*/

memrestore_definition:
    expr { memrestore( _environment, $1 ); };

/*-----------------------------------------------------------------------------
 ------------ MEMCONT DEFINITION
 ----------------------------------------------------------------------------*/

memcont_definition:
    expr { memcont( _environment, $1 ); };

/*-----------------------------------------------------------------------------
 ------------ MEMCLR DEFINITION
 ----------------------------------------------------------------------------*/

memclr_definition:
    expr OP_COMMA expr { memclr( _environment, $1, $3, NULL ); } | 
    expr OP_COMMA expr OP_COMMA expr { memclr( _environment, $1, $3, $5 ); };

/*-----------------------------------------------------------------------------
 ------------ SCALE DEFINITION
 ----------------------------------------------------------------------------*/

scale_definition:
    const_expr OP_COMMA const_expr {
        ((struct _Environment *)_environment)->scaleX = $1;
        ((struct _Environment *)_environment)->scaleY = $3;
    };

/*-----------------------------------------------------------------------------
 ------------ OFFSET DEFINITION
 ----------------------------------------------------------------------------*/

offset_definition:
    const_expr OP_COMMA const_expr {
        ((struct _Environment *)_environment)->offsetX = $1;
        ((struct _Environment *)_environment)->offsetY = $3;
    };

/*-----------------------------------------------------------------------------
 ------------ CONST DEFINITION
 ----------------------------------------------------------------------------*/

const_definition_single:
    STRING Identifier OP_ASSIGN const_expr_string_const {
            if ( !((Environment *)_environment)->emptyProcedure ) {
                Constant * c1 = constant_find( _environment, $4 );
                Constant * c = constant_create( _environment, $2 );
                c->valueString = static_string_create( _environment, c1->valueString->value, c1->valueString->size );
                c->type = CT_STRING;
            }
        } | 
    Identifier OP_ASSIGN const_expr_string {
            if ( !((Environment *)_environment)->emptyProcedure ) {
                const_define_string( _environment, $1, $3 );
            }
        } | 
    Identifier OP_ASSIGN const_expr {
            if ( !((Environment *)_environment)->emptyProcedure ) {
                const_define_numeric( _environment, $1, $3 );
            }
        } | 
    POSITIVE Identifier OP_ASSIGN const_expr {
            if ( !((Environment *)_environment)->emptyProcedure ) {
                if ( $4 < 0 ) {
                    CRITICAL_NEGATIVE_CONSTANT( $2, $4 );
                }
                const_define_numeric( _environment, $2, $4 );
            }
        } | 
    Identifier IN OP const_expr OP_COMMA const_expr CP OP_ASSIGN const_expr  {
            if ( !((Environment *)_environment)->emptyProcedure ) {
                if ( $9 < $4 ) {
                    CRITICAL_TOO_LITTLE_CONSTANT( $1 );
                }
                if ( $9 > $6 ) {
                    CRITICAL_TOO_BIG_CONSTANT( $1 );
                }
                const_define_numeric( _environment, $1, $9 );
            }
        } | 
    Identifier IN OSP const_expr OP_COMMA const_expr CP OP_ASSIGN const_expr  {
            if ( !((Environment *)_environment)->emptyProcedure ) {
                if ( $9 <= $4 ) {
                    CRITICAL_TOO_LITTLE_CONSTANT( $1 );
                }
                if ( $9 > $6 ) {
                    CRITICAL_TOO_BIG_CONSTANT( $1 );
                }
                const_define_numeric( _environment, $1, $9 );
            }
        } | 
  Identifier IN OP const_expr OP_COMMA const_expr CSP OP_ASSIGN const_expr  {
            if ( !((Environment *)_environment)->emptyProcedure ) {
                if ( $9 < $4 ) {
                    CRITICAL_TOO_LITTLE_CONSTANT( $1 );
                }
                if ( $9 >= $6 ) {
                    CRITICAL_TOO_BIG_CONSTANT( $1 );
                }
                const_define_numeric( _environment, $1, $9 );
            }
        } | 
    Identifier IN OSP const_expr OP_COMMA const_expr CSP OP_ASSIGN const_expr {
        if ( !((Environment *)_environment)->emptyProcedure ) {
            if ( $9 <= $4 ) {
                CRITICAL_TOO_LITTLE_CONSTANT( $1 );
            }
            if ( $9 >= $6 ) {
                CRITICAL_TOO_BIG_CONSTANT( $1 );
            }
            const_define_numeric( _environment, $1, $9 );
        }
    };

const_definition:
    const_definition_single
    | const_definition_single OP_COMMA const_definition;

positive_const_definition_single:
    Identifier OP_ASSIGN const_expr {
            if ( !((Environment *)_environment)->emptyProcedure ) {
                if ( $3 < 0 ) {
                    CRITICAL_NEGATIVE_CONSTANT( $1, $3 );
                }
                const_define_numeric( _environment, $1, $3 );
            }
    };

positive_const_definition:
    positive_const_definition_single
    | positive_const_definition_single OP_COMMA positive_const_definition;

/*-----------------------------------------------------------------------------
 ------------ SERIAL DEFINITION
 ----------------------------------------------------------------------------*/

serial_function:
    READ as_datatype_mandatory endianess_optional { $$ = serial_read_type( _environment, $2, $3 )->name; } |
    READ OP CP as_datatype_mandatory endianess_optional { $$ = serial_read_type( _environment, $4, $5 )->name; } |
    READ OP expr CP { $$ = serial_read( _environment, $3 )->name; } |
    WRITE OP expr as_datatype_mandatory CP endianess_optional  { $$ = serial_write_type( _environment, $3, $4, $6 )->name; } |
    WRITE OP expr CP { $$ = serial_write( _environment, $3 )->name; };

serial_definition:
    WRITE expr { serial_write( _environment, $2 ); } |
    WRITE OP expr as_datatype_mandatory CP endianess_optional { serial_write_type( _environment, $3, $4, $6 ); };

/*-----------------------------------------------------------------------------
 ------------ JMOVE DEFINITION
 ----------------------------------------------------------------------------*/

jmove_definition:
    expr OP_COMMA Identifier OP_COMMA Identifier OP_COMMA expr OP_COMMA expr { jmove( _environment, $1, $3, $5, $7, $9, $7, $9, NULL, NULL ); } |
    expr OP_COMMA Identifier OP_COMMA Identifier OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr  { jmove( _environment, $1, $3, $5, $7, $9, $11, $13, NULL, NULL ); } |
    expr OP_COMMA Identifier OP_COMMA Identifier OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr { jmove( _environment, $1, $3, $5, $7, $9, $11, $13, $15, $17 ); } |
    OP_COMMA Identifier OP_COMMA Identifier OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr {
        Variable * zero = variable_temporary( _environment, VT_BYTE, "(zero)");
        variable_store( _environment, zero->name, 0 );
        jmove( _environment, zero->name, $2, $4, $6, $8, $10, $12, $14, $16 );
    } | 
    OP_COMMA Identifier OP_COMMA Identifier OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr {
        Variable * zero = variable_temporary( _environment, VT_BYTE, "(zero)");
        variable_store( _environment, zero->name, 0 );
        jmove( _environment, zero->name, $2, $4, $6, $8, $10, $12, NULL, NULL );
    } | 
    OP_COMMA Identifier OP_COMMA Identifier OP_COMMA expr OP_COMMA expr {
        Variable * zero = variable_temporary( _environment, VT_BYTE, "(zero)");
        variable_store( _environment, zero->name, 0 );
        jmove( _environment, zero->name, $2, $4, $6, $8, $6, $8, NULL, NULL );
    };

/*-----------------------------------------------------------------------------
 ------------ LET DEFINITION
 ----------------------------------------------------------------------------*/

let_definition:
    Identifier OP_ASSIGN Identifier {
            parser_array_init( _environment );
        }
        OP indexes CP field_optional {
            if ( $8 ) {
                variable_move_from_array_type_inplace( _environment, $3, $8, $1 );
            } else {
                variable_move_from_array_inplace( _environment, $3, $1 );
            }
            parser_array_cleanup( _environment );
        } | 
    Identifier OP_ASSIGN Identifier OP_PERIOD Identifier { variable_move_from_type_inplace( _environment, $3, $5, $1 ); } |
    Identifier OP Identifier CP OP_PERIOD Identifier OP_ASSIGN Identifier OP Identifier CP OP_PERIOD Identifier {
            Variable * variable = variable_retrieve( _environment, $1 );
            if ( variable->type != VT_TARRAY ) {
                CRITICAL_NOT_ARRAY( $1 );
            }
            if ( variable->arrayType != VT_TYPE ) {
                CRITICAL_VARIABLE_TYPE_NEEDED( $1 );
            }
            Variable * variableIndex = variable_retrieve( _environment, $3 );
            if ( VT_BITWIDTH( variableIndex->type ) == 0 ) {
                CRITICAL_DATATYPE_UNSUPPORTED( "LET", $3 );
            }
            Field * variableField = field_find( variable->typeType, $6 );
            if ( ! variableField ) {
                CRITICAL_UNKNOWN_FIELD_ON_TYPE( $6 );
            }

            Variable * expr = variable_retrieve( _environment, $8 );
            if ( expr->type != VT_TARRAY ) {
                CRITICAL_NOT_ARRAY( $8 );
            }
            if ( expr->arrayType != VT_TYPE ) {
                CRITICAL_VARIABLE_TYPE_NEEDED( $8 );
            }
            Variable * exprIndex = variable_retrieve( _environment, $10 );
            if ( VT_BITWIDTH( exprIndex->type ) == 0 ) {
                CRITICAL_DATATYPE_UNSUPPORTED( "LET", $10 );
            }
            Field * exprField = field_find( expr->typeType, $13 );
            if ( ! exprField ) {
                CRITICAL_UNKNOWN_FIELD_ON_TYPE( $13 );
            }

            if ( strcmp( variable->name, expr->name ) == 0 ) {
                if ( strcmp( variableField->name, exprField->name ) == 0 ) {
                    //
                } else {
                    variable_move_array1_type_fields( _environment, variable->name, variableIndex->name, exprField->name, variableField->name );
                }
            } else {
                variable_move_array1_type( _environment, variable->name, variableIndex->name, variableField->name, variable_move_from_array1_type( _environment, expr->name, exprIndex->name, exprField->name )->name  );
            }

        } | 
    Identifier OP Identifier CP OP_PERIOD Identifier OP_ASSIGN Integer {
            Variable * variable = variable_retrieve( _environment, $1 );
            if ( variable->type != VT_TARRAY ) {
                CRITICAL_NOT_ARRAY( $1 );
            }
            if ( variable->arrayType != VT_TYPE ) {
                CRITICAL_VARIABLE_TYPE_NEEDED( $1 );
            }
            Variable * variableIndex = variable_retrieve( _environment, $3 );
            if ( VT_BITWIDTH( variableIndex->type ) == 0 ) {
                CRITICAL_DATATYPE_UNSUPPORTED( "LET", $3 );
            }
            Field * variableField = field_find( variable->typeType, $6 );
            if ( ! variableField ) {
                CRITICAL_UNKNOWN_FIELD_ON_TYPE( $6 );
            }

            variable_move_array1_type_const( _environment, variable->name, variableIndex->name, variableField->name, $8 );

        };

/*-----------------------------------------------------------------------------
 ------------ COPPER DEFINITION
 ----------------------------------------------------------------------------*/

copper_definition:
  COLOR BACKGROUND const_expr { copper_color_background( _environment, $3 ); } | 
  COLOR BORDER const_expr { copper_color_border( _environment, $3 ); } | 
  COLOR const_expr OP_COMMA const_expr { copper_color( _environment, $2, $4 ); } | 
  MOVE const_expr OP_COMMA const_expr as_datatype { copper_move( _environment, $2, $4, $5 ); } | 
  NOP { copper_nop( _environment ); } | 
  POKE const_expr OP_COMMA const_expr { copper_store( _environment, $2, $4, VT_BYTE ); } | 
  POKED const_expr OP_COMMA const_expr { copper_store( _environment, $2, $4, VT_DWORD ); } | 
  POKEW const_expr OP_COMMA const_expr { copper_store( _environment, $2, $4, VT_WORD ); } | 
  STORE const_expr OP_COMMA const_expr as_datatype { copper_store( _environment, $2, $4, $5 ); } | 
  USE const_expr_string { copper_use( _environment, $2 ); } |
  WAIT LINE const_expr { copper_wait( _environment, $3 ); };

/*-----------------------------------------------------------------------------
 ------------ FLASH DEFINITION
 ----------------------------------------------------------------------------*/

flash_definition_couple:
    expr OP_COMMA expr {
        ((Environment *)_environment)->flashVars[((Environment *)_environment)->flashVarsIndex++] = $1;
        ((Environment *)_environment)->flashVars[((Environment *)_environment)->flashVarsIndex++] = $3;
    };

on_flash_address:
    { $$ = NULL; } | 
    ON expr { $$ = $2; };

flash_definition_couples:
    flash_definition_couple | 
    flash_definition_couple OP_COMMA flash_definition_couples;

flash_definition:
    expr OP_COMMA {
            ((Environment *)_environment)->flashVarsIndex = 0;
        } flash_definition_couples on_flash_address {
            flash( _environment, $1, $5 );
        } | 
    expr OFF { flash_off( _environment, $1 ); };

/*-----------------------------------------------------------------------------
 ------------ FAST DEFINITION
 ----------------------------------------------------------------------------*/

fast_definition:
    { fast( _environment ); };

/*-----------------------------------------------------------------------------
 ------------ SLOW DEFINITION
 ----------------------------------------------------------------------------*/

slow_definition:
    { slow( _environment ); };

/*-----------------------------------------------------------------------------
 ------------ CPUSPEED DEFINITION
 ----------------------------------------------------------------------------*/

cpuspeed_definition:
    expr { cpuspeed( _environment, $1 ); };

/*-----------------------------------------------------------------------------
 ------------ LOAD MOVIE DEFINITION
 ----------------------------------------------------------------------------*/

load_movie_params:
    String { ((Environment *)_environment)->movieFilenames[ ((Environment *)_environment)->movieFilenamesCount++ ] = strdup( $1 ); } |
    String OP_COMMA load_movie_params { ((Environment *)_environment)->movieFilenames[ ((Environment *)_environment)->movieFilenamesCount++ ] = strdup( $1 ); }
    ;

/*-----------------------------------------------------------------------------
 ------------ OVERALL INSTRUCTIONS (SINGLE STATEMENTS, NO COLONS)
 ----------------------------------------------------------------------------*/

statement2nc:
    ADD add_definition | 
    ADDC addc_definition | 
    AFTER after_definition | 
    ALLOW { allow( _environment ); } | 
    ANIMATE animate_definition | 
    ANIMATION animation_definition | 
    ARRAY Identifier {
            } OP_ASSIGN {
            Variable * var = variable_retrieve( _environment, $2 );
            if ( var->type != VT_TARRAY ) {
                CRITICAL_NOT_ARRAY( $2 );
            }
            ((struct _Environment *)_environment)->currentArray = var;

                Variable *currentArray = ((struct _Environment *)_environment)->currentArray;
                currentArray->arrayInitialization = NULL;

        } array_reassign  | 
    ARRAY Identifier {
            
            } OP_ASSIGN_DIRECT {
            Variable * var = variable_retrieve( _environment, $2 );
            if ( var->type != VT_TARRAY ) {
                CRITICAL_NOT_ARRAY( $2 );
            }
            ((struct _Environment *)_environment)->currentArray = var;
                Variable *currentArray = ((struct _Environment *)_environment)->currentArray;
                currentArray->arrayInitialization = NULL;

        } array_reassign | 
    AT at_definition | 
    BANK bank_definition | 
    BAR bar_definition | 
    BEG COPPER { begin_copper( _environment, NULL ); } | 
    BEG COPPER const_expr_string { begin_copper( _environment, $3 ); } | 
    BEG GAMELOOP { begin_gameloop( _environment ); } | 
    BEG STORAGE const_expr_string { begin_storage( _environment, $3, NULL ); } | 
    BEG STORAGE const_expr_string AS const_expr_string { begin_storage( _environment, $3, $5 ); } | 
    BEG TYPE Identifier { begin_type( _environment, $3 ); } |
    BELL bell_definition | 
    BITMAP bitmap_definition | 
    BLIT blit_definition | 
    BLOCK block_definition | 
    BOOM boom_definition | 
    BORDER border_definition | 
    BOTTOM { bottom( _environment ); } | 
    BOX box_definition | 
    CALL Identifier on_targets {
            if ( $3 ) {
                ((struct _Environment *)_environment)->parameters = 0;
                call_procedure( _environment, $2 );
            }
        } | 
    CALL Identifier OSP {
            ((struct _Environment *)_environment)->parameters = 0;
            } values CSP on_targets {
                if ( $7 ) {
                call_procedure( _environment, $2 );
                }
        } | 
    CALL Identifier OSP CSP on_targets {
            if ( $5 ) {
                ((struct _Environment *)_environment)->parameters = 0;
                call_procedure( _environment, $2 );
            }
        } | 
    CASE { case_equals_label( _environment );   } OP_HASH const_expr { case_equals( _environment, $4 ); } |
    CASE {
            case_equals_label( _environment );  
        } expr {
            Variable * expr = variable_retrieve( _environment, $3 );
            if ( expr->initializedByConstant ) {
                case_equals( _environment, expr->value );  
            } else {
                case_equals_var( _environment, $3 );  
            }
        } | 
    CASE ELSE { case_equals_label( _environment );   case_else( _environment ); } | 
    CDOWN { cmove_direct( _environment, 0, 1 ); } | 
    CENTER center_definition | 
    CENTRE center_definition | 
    CGOTO cgoto_definition | 
    CHAIN chain_definition | 
    CHAR char_definition | 
    CHECK check_definition | 
    CIRCLE circle_definition | 
    CLEAR clear_definition | 
    CLEAR KEY { clear_key( _environment ); } | 
    CLEFT { cmove_direct( _environment, -1, 0 ); } | 
    CLINE { cline( _environment, NULL ); } | 
    CLINE expr { cline( _environment, $2 ); } | 
    CLIP clip_definition | 
    CLR clear_definition | 
    CLS { cls( _environment, NULL ); home( _environment ); } | 
    CLS expr { cls( _environment, $2 ); home( _environment ); } | 
    CLS expr OP_COMMA expr OP_COMMA expr OP_COMMA expr { cls_box( _environment, $2, $4, $6, $8 ); } |
    CMOB cmob_definition | 
    CMOVE cmove_definition | 
    COLOR color_definition | 
    COLORMAP colormap_definition | 
    COLOUR color_definition | 
    COLOURMAP colormap_definition | 
    CONFIGURE configure_definitions | 
    CONSOLE console_definition | 
    const_instruction const_definition | 
    COPPER copper_definition | 
    CPUSPEED cpuspeed_definition | 
    CRIGHT { cmove_direct( _environment, 1, 0 ); } | 
    CSET cset_definition | 
    CSPRITE sprite_definition | 
    CUP { cmove_direct( _environment, 0, -1 ); } | 
    DATA data_definition | 
    DEC Identifier field_optional {
                if ( $3 ) {
                    variable_decrement_type( _environment, $2, $3 );
                } else {
                    variable_decrement( _environment, $2 );
                }
        } | 
    DEC TI {
            Variable * ti = get_timer( _environment );
            variable_decrement( _environment, ti->name );
            set_timer( _environment, ti->name );
        } | 

    DEC Identifier OP {
            parser_array_init( _environment );
        } indexes CP field_optional {
            if ( $7 ) {
                variable_decrement_array_type( _environment, $2, $7 );
            } else {
                define_implicit_array_if_needed( _environment, $2 );
                variable_decrement_array( _environment, $2 );
            }
            parser_array_cleanup( _environment );
    } | 
    DEC OSP Identifier CSP field_optional {
            if ( $5 ) {
                Variable * array;
                if ( ! variable_exists( _environment, $3 ) ) {
                    CRITICAL_NOT_ARRAY( $3 );
                }        
                array = variable_retrieve( _environment, $3 );        
                if ( array->type != VT_TARRAY ) {
                    CRITICAL_NOT_ARRAY( $3 );
                }
                parser_array_init( _environment );
                parser_array_index_symbolic( _environment, "PROTOTHREADCT" );
                Variable * temporary = variable_temporary( _environment, VT_WORD, "(tmp)");
                variable_move( _environment, variable_move_from_array_type( _environment, $3, $5 )->name, temporary->name );
                parser_array_cleanup( _environment );
                variable_decrement( _environment, temporary->name );
                parser_array_init( _environment );
                parser_array_index_symbolic( _environment, "PROTOTHREADCT" );
                variable_move_array_type( _environment, $3, $5, temporary->name );
                parser_array_cleanup( _environment );
            } else {
                variable_decrement_mt( _environment, $3 );
            }
      } | 
    DECLARE declare_definition | 
    DEFDGR defdgr_definition | 
    DEFINE define_definitions | 
    DEGREE { ((struct _Environment *)_environment)->floatType.angle = FT_DEGREE; } | 
    DIM dim_definitions | 
    DISABLE INTERRUPT { cpu_di( _environment ); } | 
    DIV div_definition | 
    DLOAD dload_definition | 
    DO { begin_loop( _environment, 1 ); } | 
    DO NULLkw { wait_key( _environment, 1 ); } | 
    DOJO dojo_definition | 
    dojo_definition | 
    DOUBLE BUFFER OFF { double_buffer( _environment, 0 ); } | 
    DOUBLE BUFFER ON { double_buffer( _environment, 1 ); } | 
    DOWNB downb_definition | 
    DOWNW downw_definition | 
    DRAW draw_definition | 
    DSAVE dsave_definition | 
    DTILE draw_tile_definition | 
    DTILES draw_tile_definition | 
    ELLIPSE ellipse_definition | 
    ELSE { else_if_then_label( _environment );   else_if_then( _environment, NULL ); } | 
    ELSE IF { else_if_then_label( _environment ); }  expr THEN { else_if_then( _environment, $4 ); } | 
    ELSEIF { else_if_then_label( _environment ); } expr THEN { else_if_then( _environment, $3 ); } |
    EMPTY TILE OP_ASSIGN expr { variable_move( _environment, $4, "EMPTYTILE" ); } | 
    EMPTYTILE OP_ASSIGN expr { variable_move( _environment, $3, "EMPTYTILE" ); } | 
    ENABLE INTERRUPT { cpu_ei( _environment ); } | 
    END { end( _environment ); } | 
    END COPPER { end_copper( _environment ); } | 
    END GAMELOOP { end_gameloop( _environment ); } | 
    END LOOP { end_loop( _environment, 0 ); } | 
    END PROC { end_procedure( _environment, NULL ); ((struct _Environment *)_environment)->emptyProcedure = 0; } | 
    END PROC OSP expr CSP { end_procedure( _environment, $4 ); ((struct _Environment *)_environment)->emptyProcedure = 0; } | 
    END PROCEDURE { end_procedure( _environment, NULL ); ((struct _Environment *)_environment)->emptyProcedure = 0; } | 
    END PROCEDURE OSP expr CSP { end_procedure( _environment, $4 ); ((struct _Environment *)_environment)->emptyProcedure = 0; } | 
    END STORAGE { end_storage( _environment ); } | 
    END TYPE { end_type( _environment ); } | 
    ENDCOPPER { end_copper( _environment ); } | 
    ENDIF { end_if_then( _environment ); } | 
    ENDPROC { end_procedure( _environment, NULL ); ((struct _Environment *)_environment)->emptyProcedure = 0; } | 
    ENDSELECT { end_select_case( _environment ); } | 
    ENDSTORAGE { end_storage( _environment ); } | 
    ENDTYPE { end_type( _environment ); } | 
    ENVELOPE envelope_definition | 
    ERROR expr { error( _environment, $2 ); } | 
    EVERY every_definition | 
    EXEC exec_definition | 
    EXIT { exit_loop( _environment, 0 );   } | 
    EXIT direct_integer { exit_loop( _environment, $2 ); } | 
    EXIT direct_integer IF expr { exit_loop_if( _environment, $4, $2 ); } | 
    EXIT IF expr { exit_loop_if( _environment, $3, 0 ); } | 
    EXIT IF expr OP_COMMA direct_integer { exit_loop_if( _environment, $3, $5 ); } | 
    EXIT IF expr OP_COMMA Integer { exit_loop_if( _environment, $3, $5 ); } | 
    EXIT Integer { exit_loop( _environment, $2 ); } | 
    EXIT Integer IF expr { exit_loop_if( _environment, $4, $2 ); } | 
    EXIT PROC { exit_procedure( _environment ); } | 
    EXIT PROC IF expr { exit_proc_if( _environment, $4, NULL ); } | 
    EXIT PROC WITH expr IF expr { exit_proc_if( _environment, $6, $4 ); } | 
    EXIT PROCEDURE { exit_procedure( _environment ); } | 
    EXIT PROCEDURE IF expr { exit_proc_if( _environment, $4, NULL ); } | 
    EXIT PROCEDURE WITH expr IF expr { exit_proc_if( _environment, $6, $4 ); } | 
    EXITIF expr { exit_loop_if( _environment, $2, 0 ); } | 
    EXITIF expr OP_COMMA direct_integer { exit_loop_if( _environment, $2, $4 ); } | 
    EXITIF expr OP_COMMA Integer { exit_loop_if( _environment, $2, $4 ); } | 
    FADE fade_definition | 
    FAST fast_definition | 
    FCIRCLE fcircle_definition | 
    FELLIPSE fellipse_definition | 
    FILEX const_expr_string { file_storage( _environment, $2, NULL, FSF_BINARY, 0 ); } | 
    FILEX const_expr_string AS const_expr_string { file_storage( _environment, $2, $4, FSF_BINARY, 0 ); } | 
    FILEX const_expr_string AS const_expr_string CSV OF datatype { file_storage( _environment, $2, $4, FSF_CSV, $7 ); } | 
    FILEX const_expr_string CSV OF datatype { file_storage( _environment, $2, NULL, FSF_CSV, $5 ); } | 
    FILL fill_definitions | 
    FILL SCREEN fill_screen_definition | 
    FLASH flash_definition | 
    FLIP flip_definition | 
    FONT font_definition | 
    FOR Identifier as_datatype_suffix_optional OP_ASSIGN {
            VariableType vt = $3;
            if ( vt == 0 ) {
                vt = ((struct _Environment *)_environment)->defaultVariableType;
            }
            Variable * index;
            if ( variable_exists( _environment, $2 ) ) {
                index = variable_retrieve( _environment, $2 );
            } else {
                if ( ((struct _Environment *)_environment)->optionExplicit ) {
                    CRITICAL_VARIABLE_UNDEFINED( $2 );
                }        
                index = variable_define( _environment, $2, vt, 0 );
            }
            begin_for_prepare( _environment, $2 );
            begin_for_from_prepare( _environment );
        } expr { 
            begin_for_from_assign( _environment, $6 );
        } TO {
            begin_for_to_prepare( _environment );
        } expr {
            begin_for_to_assign( _environment, $10 );
            begin_for_step_prepare( _environment );
        }   step_optional {
            begin_for_step_assign( _environment, $12 );
            begin_for_identifier( _environment, $2 );
        } | 
    FOR OSP Identifier as_datatype_suffix_optional CSP OP_ASSIGN {
            Variable * index;
            if ( variable_exists( _environment, $3 ) ) {
                index = variable_retrieve( _environment, $3 );
                if ( index->type != VT_TARRAY ) {
                    CRITICAL_DATATYPE_MISMATCH( DATATYPE_AS_STRING[ index->type ], DATATYPE_AS_STRING[ $4 ] );
                }
                VariableType vt = $4;
                if ( vt != 0 ) {
                    if ( index->arrayType != vt ) {
                        CRITICAL_DATATYPE_MISMATCH( DATATYPE_AS_STRING[ index->type ], DATATYPE_AS_STRING[ $4 ] );
                    }
                }
            } else {
                if ( ((struct _Environment *)_environment)->optionExplicit ) {
                    CRITICAL_VARIABLE_UNDEFINED( $3 );
                }        
                VariableType vt = $4;
                if ( vt == 0 ) {
                    vt = ((struct _Environment *)_environment)->defaultVariableType;
                }
                index = variable_define( _environment, $3, VT_TARRAY, 0 );
                variable_array_type( _environment, $3, vt );
            }
            begin_for_prepare_mt( _environment, $3 );
            begin_for_from_prepare_mt( _environment );
        } expr { 
            begin_for_from_assign_mt( _environment, $8 );
        } TO {
            begin_for_to_prepare_mt( _environment );
        } expr {
            outline1("; to assign = %s", $12 );
            begin_for_to_assign_mt( _environment, $12 );
            begin_for_step_prepare_mt( _environment );
        }   step_optional {
            begin_for_step_assign_mt( _environment, $14 );
            begin_for_identifier_mt( _environment, $3 );
        } |    
    FORBID { forbid( _environment ); } | 
    FREEZE freeze_definition | 
    FUJINET fujinet_definition | 
    FUNCTION Identifier {
            ((struct _Environment *)_environment)->parameters = 0;
            ((struct _Environment *)_environment)->protothread = 0;
            } OSP parameters CSP {
                ((struct _Environment *)_environment)->emptyProcedure = 0;
                begin_procedure( _environment, $2 );
            } OP_ASSIGN expr {
                end_procedure( _environment, $9 );
        } | 
    FUNCTION Identifier {
            ((struct _Environment *)_environment)->parameters = 0;
            ((struct _Environment *)_environment)->protothread = 0;
            ((struct _Environment *)_environment)->emptyProcedure = 0;
            begin_procedure( _environment, $2 );
            } OP_ASSIGN expr {
                end_procedure( _environment, $5 );
        } | 
    GET get_definition | 
    GLOBAL parameters_expr { global( _environment ); } | 
    GOSUB gosub_definition | 
    GOTO goto_definition | 
    GPRINT gprint_definition | 
    GR LOCATE gr_locate_definition | 
    GR PRINT gprint_definition | 
    GRAPHIC { graphic( _environment ); } | 
    GRAPHICS graphics_definition | 
    HALT { halt( _environment ); } | 
    HIRES hires_definition | 
    HOME { home( _environment ); } | 
    HSCROLL hscroll_definition | 
    Identifier AS datatype { field_type( _environment, $1, $3 ); } | 
    Identifier OP_ASSIGN OP_HASH OSP BufferDefinitionHex CSP {
            Variable * variable = NULL;
                if ( variable_exists( _environment, $1 ) ) {
                    variable = variable_retrieve( _environment, $1 );
                } else {
                    variable = variable_define( _environment, $1, VT_BUFFER, 0 );
                }
                Variable * buffer = parse_buffer_definition( _environment, $5, VT_BUFFER, 1 );
                variable_move( _environment, buffer->name, variable->name );
        } | 
    Identifier OP_ASSIGN BufferDefinitionHex {
            Variable * variable = NULL;
                if ( variable_exists( _environment, $1 ) ) {
                    variable = variable_retrieve( _environment, $1 );
                } else {
                    variable = variable_define( _environment, $1, VT_BUFFER, 0 );
                }
                Variable * buffer = parse_buffer_definition( _environment, $3, VT_BUFFER, 1 );
                variable_move( _environment, buffer->name, variable->name );
        } | 
    Identifier OP_ASSIGN expr {
                Variable * expr = variable_retrieve( _environment, $3 );
                Variable * variable;
                if ( variable_exists( _environment, $1 ) ) {
                    variable = variable_retrieve( _environment, $1 );
                } else {
                    if ( !((struct _Environment *)_environment)->optionExplicit ) {
                        variable = variable_define( _environment, $1, expr->type == VT_STRING ? VT_DSTRING : expr->type, 0 );
                        variable->typeType = expr->typeType;
                        if (variable->typeType) {
                            variable->size = expr->size;
                        }
                    } else {
                        CRITICAL_VARIABLE_UNDEFINED( $1 );
                    }
                }

                if ( expr->type == VT_IMAGE || expr->type == VT_IMAGES || expr->type == VT_SEQUENCE || expr->type == VT_MOVIE ) {
                    expr->usedImage = 1;
                    variable->usedImage = 1;
                }

                if ( expr->initializedByConstant ) {
                    if ( variable->type == VT_FLOAT ) {
                        if ( expr->type != VT_FLOAT ) {
                            variable_store_float( _environment, variable->name, expr->value );
                        } else {
                            variable_store_float( _environment, variable->name, expr->valueFloating );
                        }
                    } else {
                        if ( expr->type != VT_FLOAT ) {
                            variable_store( _environment, variable->name, expr->value );
                        } else {
                            variable_store( _environment, variable->name, expr->valueFloating );
                        }
                    }
                } else {
                    if ( variable->type == VT_TARRAY ) {
                        if ( expr->type != VT_BUFFER && expr->type != VT_TARRAY ) {
                            CRITICAL_CANNOT_ASSIGN_TO_ARRAY( $1, DATATYPE_AS_STRING[expr->type] );
                        }
                        if ( expr->size != variable->size ) {
                            CRITICAL_BUFFER_SIZE_MISMATCH_ARRAY_SIZE( $1, expr->size, variable->size );
                        }
                    }

                    outline2("; move( %d, %d )", variable->size, expr->size );

                    if ( variable->type != expr->type ) {
                        Variable * casted = variable_cast( _environment, expr->name, variable->type );
                        variable_move( _environment, casted->name, variable->name );
                    } else {
                        variable_move( _environment, expr->name, variable->name );
                    }

                }

                variable->frameSize = expr->frameSize;
                variable->frameCount = expr->frameCount;
                variable->offsettingFrames = expr->offsettingFrames;
                if ( variable->offsettingFrames ) {
                    offsetting_add_variable_reference( _environment, variable->offsettingFrames, variable, 0 );
                }
                variable->offsettingSequences = expr->offsettingSequences;
                if ( variable->offsettingSequences ) {
                    offsetting_add_variable_reference( _environment, variable->offsettingSequences, variable, 1 );
                }
        } | 
    Identifier OP_PERIOD Identifier OP_ASSIGN expr { variable_move_type( _environment, $1, $3, $5 ); } | 
    Identifier as_datatype_suffix OP_ASSIGN expr {
                VariableType vt = ((struct _Environment *)_environment)->defaultVariableType;
                if ( $2 != 0 ) {
                    vt = $2;
                }
                Variable * expr = variable_retrieve( _environment, $4 );
                Variable * variable;
                if ( variable_exists( _environment, $1 ) ) {
                    variable = variable_retrieve( _environment, $1 );
                } else {
                    if ( !((struct _Environment *)_environment)->optionExplicit ) {
                        variable = variable_define( _environment, $1, vt, 0 );
                    } else {
                        CRITICAL_VARIABLE_UNDEFINED( $1 );
                    }
                }

                if ( VT_UNSIGN( variable->type ) != VT_UNSIGN( vt ) ) {
                    CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[variable->type], DATATYPE_AS_STRING[vt] );
                }

                if ( variable->type != expr->type ) {
                    Variable * casted = variable_cast( _environment, expr->name, variable->type );
                    variable_move( _environment, casted->name, variable->name );
                } else {
                    variable_move( _environment, expr->name, variable->name );
                }
        } | 
    Identifier {
                parser_array_init( _environment );
                define_implicit_array_if_needed( _environment, $1 );
            } datatype OP indexes CP OP_ASSIGN expr {
                Variable * x = variable_retrieve( _environment, $8 );
                Variable * a = variable_retrieve( _environment, $1 );
                if ( x->type != $3 ) {
                    CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[x->type], DATATYPE_AS_STRING[$3] );
                }
                if ( a->type != VT_TARRAY ) {
                    CRITICAL_NOT_ARRAY( $1 );
                }
                if ( a->arrayType != $3 ) {
                    CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[a->arrayType], DATATYPE_AS_STRING[$3] );
                }
                variable_move_array( _environment, $1, x->name );
                parser_array_cleanup( _environment );
        } | 
    Identifier {
                parser_array_init( _environment );
            }    
            OP indexes CP array_assignment {
                if ( ((struct _Environment *)_environment)->currentFieldName ) {
                    Variable * array = variable_retrieve( _environment, $1 );
                    if ( array->type != VT_TARRAY ) {
                        CRITICAL_NOT_ARRAY( $1 );
                    }
                    variable_move_array_type( _environment, $1, ((struct _Environment *)_environment)->currentFieldName, ((struct _Environment *)_environment)->currentExpression );
                    parser_array_cleanup( _environment );
                } else {
                    define_implicit_array_if_needed( _environment, $1 );
                    Variable * array = variable_retrieve( _environment, $1 );
                    if ( array->type != VT_TARRAY ) {
                        CRITICAL_NOT_ARRAY( $1 );
                    }
                    variable_move_array( _environment, $1, ((struct _Environment *)_environment)->currentExpression );
                    parser_array_cleanup( _environment );
                }
        } | 
    Identifier OP_DOLLAR {
                parser_array_init( _environment );
            } OP indexes CP OP_ASSIGN expr {
                define_implicit_array_if_needed( _environment, $1 );
                Variable * x = variable_retrieve( _environment, $8 );
                Variable * a = variable_retrieve( _environment, $1 );
                if ( x->type != VT_STRING && x->type != VT_DSTRING ) {
                    CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[x->type], DATATYPE_AS_STRING[VT_DSTRING] );
                }
                if ( a->type != VT_TARRAY ) {
                    CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[a->type], DATATYPE_AS_STRING[VT_TARRAY] );
                }
                if ( a->arrayType != VT_DSTRING ) {
                    CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[a->arrayType], DATATYPE_AS_STRING[VT_DSTRING] );
                }
                variable_move_array_string( _environment, $1, x->name );
                parser_array_cleanup( _environment );
        } | 
    Identifier OP_ASSIGN OP_HASH const_expr as_datatype {
                if ( !variable_exists( _environment, $1 ) ) {
                    variable_retrieve_or_define( _environment, $1, $5, $4 );
                }
                variable_store( _environment, $1, $4 );
        } | 
    Identifier OP_ASSIGN_DIRECT expr  { variable_direct_assign( _environment, $1, $3 )->name; } | 
    Identifier OP_COLON {
            char realLabel[MAX_TEMPORARY_STORAGE];
            if (strcmp($1, "q" ) == 0 && ((Environment *)_environment)->vestigialConfig.rchack_ostra_1172) {
                sprintf( realLabel, "lbl%s", $1 );
            } else {
                strcpy( realLabel, $1 );
            }
            label_define_named( _environment, realLabel );
            cpu_label( _environment, realLabel );
            ((Environment *)_environment)->lastDefinedLabel = strdup( realLabel );
            ((Environment *)_environment)->lastDefinedLabelIsNumeric = 0;
        } | 
    Identifier OSP {
            ((struct _Environment *)_environment)->parameters = 0;
            } values CSP on_targets {
            if ( $6 ) {
                call_procedure( _environment, $1 );
            }
        } | 
    Identifier OSP CSP on_targets {
            if ( $4) {
                ((struct _Environment *)_environment)->parameters = 0;
                call_procedure( _environment, $1 );
            }
        } | 
    IF expr GOTO Identifier { if_then( _environment, $2 ); goto_label( _environment, $4 ); end_if_then( _environment ); } | 
    IF expr GOTO Integer { if_then( _environment, $2 ); goto_number( _environment, $4 ); end_if_then( _environment ); } | 
    IF expr THEN { if_then( _environment, $2 ); } | 
    IF expr THEN { if_then( _environment, $2 ); } statement2nc { end_if_then( _environment ); } | 
    IF expr THEN Integer { if_then( _environment, $2 ); goto_number( _environment, $4 ); end_if_then( _environment ); } | 
    IF expr THEN Integer ELSE Integer { if_then( _environment, $2 ); goto_number( _environment, $4 ); else_if_then_label( _environment ); else_if_then( _environment, NULL ); goto_number( _environment, $6 ); end_if_then( _environment ); } | 
    IMAGE const_expr_string image_load_flags using_transparency using_opacity using_background on_bank_implicit to_identifier_optional {
            Variable * v = image_storage( _environment, $2, NULL, ((struct _Environment *)_environment)->currentMode, $3, $3+$4, $5, $6 );
            if ( $8 ) {
                prepare_variable_storage( _environment, $8, v );
            } 
            variable_temporary_remove( _environment, v->name );
        } | 
    IMAGE const_expr_string AS const_expr_string image_load_flags  using_transparency using_opacity using_background on_bank_implicit to_identifier_optional {
                Variable * v = image_storage( _environment, $2, $4, ((struct _Environment *)_environment)->currentMode, $5, $6+$7, $8, $9 );
                if ( $10 ) {
                    prepare_variable_storage( _environment, $10, v );
                }
                variable_temporary_remove( _environment, v->name );
        } | 
    images_or_atlas const_expr_string frame_size images_load_flags  using_transparency using_opacity using_background on_bank_implicit to_identifier_optional {
            Variable * v = images_storage( 
                _environment, 
                $2, NULL, 
                ((struct _Environment *)_environment)->currentMode, 
                ((struct _Environment *)_environment)->frameWidth, ((struct _Environment *)_environment)->frameHeight,
                $6, $5+$6, 
                $7, $8, 
                ((struct _Environment *)_environment)->frameOriginX, ((struct _Environment *)_environment)->frameOriginY, 
                ((struct _Environment *)_environment)->frameOffsetX, ((struct _Environment *)_environment)->frameOffsetY );
            if ( $9 ) {
                prepare_variable_storage( _environment, $9, v );
            }
            variable_temporary_remove( _environment, v->name );
        } | 
    images_or_atlas const_expr_string AS const_expr_string frame_size images_load_flags  using_transparency using_opacity using_background on_bank_implicit to_identifier_optional {
                Variable * v = images_storage( 
                    _environment, 
                    $2, $4, 
                    ((struct _Environment *)_environment)->currentMode, 
                    ((struct _Environment *)_environment)->frameWidth, ((struct _Environment *)_environment)->frameHeight,
                    $6, $7+$8, 
                    $9, $10, 
                    ((struct _Environment *)_environment)->frameOriginX, ((struct _Environment *)_environment)->frameOriginY, 
                    ((struct _Environment *)_environment)->frameOffsetX, ((struct _Environment *)_environment)->frameOffsetY );
                if ( $11 ) {
                    prepare_variable_storage( _environment, $11, v );
                }
                variable_temporary_remove( _environment, v->name );
        } | 
    INC Identifier field_optional {
                if ( $3 ) {
                    variable_increment_type( _environment, $2, $3 );
                } else {
                    variable_increment( _environment, $2 );
                }      
        } | 
    INC Identifier OP {
            parser_array_init( _environment );
        } indexes CP field_optional {
            if ( $7 ) {
                variable_increment_array_type( _environment, $2, $7 );
            } else {
                define_implicit_array_if_needed( _environment, $2 );
                variable_increment_array( _environment, $2 );
            }
            parser_array_cleanup( _environment );
        } | 
    INC OSP Identifier CSP field_optional {
            if ( $5 ) {
                Variable * array;
                if ( ! variable_exists( _environment, $3 ) ) {
                    CRITICAL_NOT_ARRAY( $3 );
                }        
                array = variable_retrieve( _environment, $3 );        
                if ( array->type != VT_TARRAY ) {
                    CRITICAL_NOT_ARRAY( $3 );
                }
                parser_array_init( _environment );
                parser_array_index_symbolic( _environment, "PROTOTHREADCT" );
                Variable * temporary = variable_temporary( _environment, VT_WORD, "(tmp)");
                variable_move( _environment, variable_move_from_array_type( _environment, $3, $5 )->name, temporary->name );
                parser_array_cleanup( _environment );
                variable_increment( _environment, temporary->name );
                parser_array_init( _environment );
                parser_array_index_symbolic( _environment, "PROTOTHREADCT" );
                variable_move_array_type( _environment, $3, $5, temporary->name );
                parser_array_cleanup( _environment );
            } else {
                variable_increment_mt( _environment, $3 );
            }
        } | 
    INC TI {
            Variable * ti = get_timer( _environment );
            variable_increment( _environment, ti->name );
            set_timer( _environment, ti->name );
        } |
    INK ink_definition | 
    INKB inkb_definition | 
    INPUT { ((Environment *)_environment)->lineInput = 0; } input_definition | 
    INSERT insert_definition | 
    INSTRUMENT instrument_definition | 
    INVERSE OFF { CRITICAL_NOT_SUPPORTED("INVERSE"); } | 
    INVERSE ON { CRITICAL_NOT_SUPPORTED("INVERSE"); } | 
    JMOVE jmove_definition | 
    KEY key_definition | 
    KEYGET keyget_definition | 
    KILL kill_definition | 
    LBOTTOM { lbottom( _environment ); } | 
    LEFT OP expr OP_COMMA expr CP OP_ASSIGN expr { variable_string_left_assign( _environment, $3, $5, $8 ); } | 
    LEFTB leftb_definition | 
    LEFTW leftw_definition | 
    LET let_definition | 
    LINE line_definition | 
    LOAD String AS String OP_COMMA Integer on_bank_explicit load_flags { load( _environment, $2, $4, $6, abs($7), $8 ); } | 
    LOAD String OP_COMMA Integer on_bank_explicit load_flags { load( _environment, $2, NULL, $4, abs($5), $6 ); } | 
    LOCATE locate_definition | 
    LOOP {
        if ( is_do_loop( _environment ) ) {
            end_loop( _environment, 1 );  
        } else {
            begin_loop( _environment, 0 );  
        }
    } | 
    LOOP UNTIL expr { end_loop_until( _environment, $3 ); } | 
    LOOP WHILE expr { end_loop_while( _environment, $3 ); } | 
    MEMCLR memclr_definition | 
    MEMCONT memcont_definition | 
    MEMDEF memdef_definition | 
    MEMLEN memlen_definition | 
    MEMLOAD memload_definition | 
    MEMOR memor_definition | 
    MEMORIZE { memorize( _environment ); } | 
    MEMPOS mempos_definition | 
    MEMRESTORE memrestore_definition | 
    MEMSAVE memsave_definition | 
    MID OP expr OP_COMMA expr CP OP_ASSIGN expr { variable_string_mid_assign( _environment, $3, $5, NULL, $8 ); } | 
    MID OP expr OP_COMMA expr OP_COMMA expr CP OP_ASSIGN expr { variable_string_mid_assign( _environment, $3, $5, $7, $10 ); } |
    MMOB mmob_definition | 
    MMOVE memory_video_optional expr TO memory_video_optional expr SIZE expr {
            if ( $2 == 0 ) {
                if ( $5 == 0 ) {
                    mmove_memory_memory( _environment, $3, $6, $8 );
                } else {
                    mmove_memory_video( _environment, $3, $6, $8 );
                }
            } else {
                if ( $5 == 0 ) {
                    mmove_video_memory( _environment, $3, $6, $8 );
                } else {
                    CRITICAL_CANNOT_MMOVE_UNSUPPORTED( )
                }
            }
        } | 
    MOB mob_definition | 
    MOD mod_definition | 
    MOVE move_definition | 
    MOVEMENT movement_definition | 
    MSPRITE sprite_definition | 
    MSPRITE UPDATE { msprite_update( _environment ); } | 
    MUL mul_definition | 
    MULTI multi_definition | 
    MUSIC const_expr_string AS const_expr_string on_bank_explicit to_identifier_optional {
                Variable * v = music_storage( _environment, $2, $4, abs($5) );
                if ( $6 ) {
                    prepare_variable_storage( _environment, $6, v );
                }
                variable_temporary_remove( _environment, v->name );
        } | 
    MUSIC music_definition | 
    NEXT { end_for( _environment ); } | 
    NEXT ANIMATION next_animation_definition |
    NEXT Identifier as_datatype_suffix_optional {
            if ( $3 > 0 ) {
                Variable * index = variable_retrieve_or_define( _environment, $2, $3, 0 );
                if ( index->type != $3 ) {
                    CRITICAL_DATATYPE_MISMATCH( DATATYPE_AS_STRING[ index->type ], DATATYPE_AS_STRING[ $3 ] );
                }
            }
            end_for_identifier( _environment, $2 );
        } | 
    NEXT OSP Identifier as_datatype_suffix_optional CSP {
            if ( $4 > 0 ) {
                Variable * index = variable_retrieve_or_define( _environment, $3, $4, 0 );
                if ( index->type != VT_TARRAY ) {
                    CRITICAL_NOT_ARRAY( $3 );
                }
                if ( index->arrayType != $4 ) {
                    CRITICAL_DATATYPE_MISMATCH( DATATYPE_AS_STRING[ index->type ], DATATYPE_AS_STRING[ $4 ] );
                }
            }
            end_for_identifier( _environment, $3 );
        } | 
    NEXT RASTER next_raster_definition | 
    NOP { cpu_nop(_environment); } | 
    NRM nrm_definition | 
    OFFSET offset_definition | 
    ON on_definition | 
    on_targets AsmSnippet on_targets {
            if ( !((struct _Environment *)_environment)->emptyProcedure ) {
        #if defined(__to8__)
            if ( !((struct _Environment *)_environment)->vestigialConfig.rchack_ccarrots_1163 ) {
        #endif
            if ( ((struct _Environment *)_environment)->tenLinerRulesEnforced ) {
                CRITICAL_10_LINE_RULES_ENFORCED("ASM");
            }
            if ( $1 && $3 ) {
                outline1("%s", $2 );
            }
        #if defined(__to8__)
            }
        #endif
            }
        } | 
    OPTION option_definitions | 
    ORIGIN origin_definitions | 
    OSP Identifier CSP {
                if ( ! ((struct _Environment *)_environment)->procedureName ) {
                    CRITICAL_CANNOT_ACCESS_MULTITHREAD_ARRAY_OUTSIDE_PROCEDURE($2);
                }
                if ( ! ((struct _Environment *)_environment)->protothread ) {
                    CRITICAL_CANNOT_ACCESS_MULTITHREAD_ARRAY_OUTSIDE_PROCEDURE($2);
                }

                parser_array_init( _environment );
                define_implicit_array_if_needed( _environment, $2 );
            } field_optional
            OP_ASSIGN expr {
                parser_array_index_symbolic( _environment, "PROTOTHREADCT" );
                Variable * array = variable_retrieve( _environment, $2 );
                if ( array->type != VT_TARRAY ) {
                    CRITICAL_NOT_ARRAY( $2 );
                }
                if ( $5 ) {
                    Variable * expr = variable_retrieve( _environment, $7 );
                    variable_move_array_type( _environment, $2, $5, expr->name );
                } else {
                    Variable * expr = variable_retrieve_or_define( _environment, $7, array->arrayType, 0 );
                    variable_move_array( _environment, $2, expr->name );
                }
                parser_array_cleanup( _environment );
        } | 
    OSP Identifier OP_DOLLAR CSP {
                parser_array_init( _environment );
                define_implicit_array_if_needed( _environment, $2 );
            } OP_ASSIGN expr {
                parser_array_index_symbolic( _environment, "PROTOTHREADCT" );
                Variable * x = variable_retrieve( _environment, $7 );
                Variable * a = variable_retrieve( _environment, $2 );
                if ( x->type != VT_STRING && x->type != VT_DSTRING ) {
                    CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[x->type], DATATYPE_AS_STRING[VT_DSTRING] );
                }
                if ( a->type != VT_TARRAY ) {
                    CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[a->type], DATATYPE_AS_STRING[VT_TARRAY] );
                }
                if ( a->arrayType != VT_DSTRING ) {
                    CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[a->arrayType], DATATYPE_AS_STRING[VT_DSTRING] );
                }
                variable_move_array_string( _environment, $2, x->name );
                parser_array_cleanup( _environment );
        } | 
    OSP Identifier OP_COLON CSP {
            char realLabel[MAX_TEMPORARY_STORAGE];
            if (strcmp($2, "q" ) == 0 && ((Environment *)_environment)->vestigialConfig.rchack_ostra_1172) {
                sprintf( realLabel, "lbl%s", $2 );
            } else {
                strcpy( realLabel, $2 );
            }
            label_define_named( _environment, realLabel );
            cpu_label( _environment, realLabel );
            ((Environment *)_environment)->lastDefinedLabel = strdup( realLabel );
            ((Environment *)_environment)->lastDefinedLabelIsNumeric = 0;
        } | 
    OUT out_definition | 
    PAINT paint_definition | 
    PALETTE { ((struct _Environment *)_environment)->paletteIndex = 0; } palette_definition | 
    PALETTE1 { ((struct _Environment *)_environment)->paletteIndex = 0; color( _environment, ((struct _Environment *)_environment)->paletteIndex++, $1 ); } palette_definition | 
    PAPER expr { paper( _environment, $2 ); } | 
    parallel_optional PROCEDURE Identifier on_targets {
            ((struct _Environment *)_environment)->parameters = 0;
            ((struct _Environment *)_environment)->protothread = $1;
            ((struct _Environment *)_environment)->emptyProcedure = !$4;
            begin_procedure( _environment, $3 );
        } | 
    parallel_optional PROCEDURE Identifier {
            ((struct _Environment *)_environment)->parameters = 0;
            ((struct _Environment *)_environment)->protothread = $1;
        } OSP parameters CSP on_targets {
            ((struct _Environment *)_environment)->emptyProcedure = !$8;
            begin_procedure( _environment, $3 );
        } | 
    PAUSE pause_definition | 
    PCLS { cls( _environment, NULL ); home( _environment ); } | 
    PCLS expr { cls( _environment, $2 ); home( _environment ); } | 
    PEN expr { pen( _environment, $2 ); } | 
    PLAY play_definition | 
    PLOT plot_definition | 
    PLOTR plotr_definition | 
    PMODE pmode_definition | 
    POINT point_definition | 
    POKE poke_definition | 
    POKED poked_definition | 
    POKEW pokew_definition | 
    POLYLINE polyline_definition | 
    POP { pop( _environment ); } | 
    POP PROC { exit_procedure( _environment ); } | 
    POP PROCEDURE { exit_procedure( _environment ); } | 
    POSITIVE const_instruction positive_const_definition | 
    PRINT { print_newline( _environment ); } | 
    PRINT BUFFER print_buffer_definition | 
    PRINT BUFFER RAW print_buffer_raw_definition |
    PRINT print_definition | 
    PROC Identifier {
            ((struct _Environment *)_environment)->parameters = 0;
            proc( _environment, $2 );
        } | 
    PROC Identifier OSP {
            ((struct _Environment *)_environment)->parameters = 0;
            } values CSP on_targets {
                if ( $7 ) {
                call_procedure( _environment, $2 );
                }
        } | 
    PROC IdentifierSpaced {
            ((struct _Environment *)_environment)->parameters = 0;
            proc( _environment, $2 );
        } | 
    PUT KEY expr { put_key( _environment, $3 ); } | 
    PUT put_definition | 
    QM { print_newline( _environment ); } | 
    QM print_definition | 
    RADIAN { ((struct _Environment *)_environment)->floatType.angle = FT_RADIAN; } | 
    RANDOMIZE { randomize( _environment, NULL ); } | 
    RANDOMIZE expr { randomize( _environment, $2 ); } | 
    RASTER raster_definition | 
    READ read_definition | 
    REC rec_definition | 
    RECT rec_definition | 
    Remark |
    REMEMBER { remember( _environment ); } | 
    REPEAT { begin_repeat( _environment ); } | 
    RESET { reset( _environment ); } | 
    RESOLUTION resolution_definitions | 
    RESPAWN expr on_targets {
            ((struct _Environment *)_environment)->parameters = 0;
            if ( $3 ) {
                respawn_procedure( _environment, $2 );
            }
        } | 
    RESTORE restore_definition | 
    RESUME resume_definition | 
    RETURN { return_label( _environment ); } | 
    RETURN expr { return_procedure( _environment, $2 ); } | 
    RIGHT OP expr OP_COMMA expr CP OP_ASSIGN expr { variable_string_right_assign( _environment, $3, $5, $8 ); } | 
    RIGHTB rightb_definition | 
    RIGHTW rightw_definition | 
    ROT rot_definition | 
    RUN { run( _environment ); } | 
    RUN PARALLEL { run_parallel( _environment ); } | 
    SCALE scale_definition | 
    SCREEN screen_definition | 
    SCREEN SWAP { screen_swap( _environment ); } | 
    SCROLL scroll_definition | 
    SELECT CASE expr { select_case( _environment, $3 ); } | 
    sequence_or_strip const_expr_string AS const_expr_string frame SIZE OP const_expr OP_COMMA const_expr CP sequence_load_flags  using_transparency using_opacity using_background on_bank_implicit to_identifier_optional{
                Variable * v = sequence_storage( 
                    _environment, 
                    $2, $4, 
                    ((struct _Environment *)_environment)->currentMode, 
                    $8, $10, 
                    $12, $13+$14, 
                    $15, $16, 
                    ((struct _Environment *)_environment)->frameOriginX, ((struct _Environment *)_environment)->frameOriginY, 
                    ((struct _Environment *)_environment)->frameOffsetX, ((struct _Environment *)_environment)->frameOffsetY );
                if ( $17 ) {
                    prepare_variable_storage( _environment, $17, v );
                }
                variable_temporary_remove( _environment, v->name );
        } | 
    sequence_or_strip const_expr_string frame SIZE OP const_expr OP_COMMA const_expr CP sequence_load_flags  using_transparency using_opacity using_background on_bank_implicit to_identifier_optional {
                Variable * v = sequence_storage( 
                    _environment, 
                    $2, NULL, 
                    ((struct _Environment *)_environment)->currentMode, 
                    $6, $8, 
                    $10, $11+$12, 
                    $13, $14, 
                    ((struct _Environment *)_environment)->frameOriginX, ((struct _Environment *)_environment)->frameOriginY, 
                    ((struct _Environment *)_environment)->frameOffsetX, ((struct _Environment *)_environment)->frameOffsetY );
                if ( $15 ) {
                    prepare_variable_storage( _environment, $15, v );
                }
                variable_temporary_remove( _environment, v->name );
        } | 
    SERIAL serial_definition | 
    SET LINE expr { ((Environment *)_environment)->lineNeeded = 1; variable_move( _environment, $3, "LINE" ); } | 
    SET TAB expr { text_set_tab( _environment, $3 ); } | 
    SHARED parameters_expr { shared( _environment ); } | 
    SHOOT shoot_definition | 
    SHUFFLE shuffle_definition | 
    SLEEP sleep_definition | 
    SLICE slice_definition | 
    SLOW slow_definition | 
    SOUND sound_definition | 
    SPAWN spawn_definition | 
    SPRITE sprite_definition | 
    STOP stop_definition | 
    STORAGE const_expr_string { begin_storage( _environment, $2, NULL ); } | 
    STORAGE const_expr_string AS const_expr_string { begin_storage( _environment, $2, $4 ); } | 
    STORE OP_HASH const_expr OP_COMMA OP_HASH const_expr as_datatype { copper_store( _environment, $3, $6, $7 ); } | 
    SUSPEND suspend_definition | 
    SWAP swap_definition | 
    SYS sys_definition | 
    TEXT text_definition | 
    TEXTADDRESS OP_ASSIGN expr { variable_move( _environment, $3, "TEXTADDRESS" ); } | 
    TEXTMAP textmap_definition | 
    TI OP_ASSIGN expr { set_timer( _environment, $3 ); } | 
    TILE tile_definition | 
    TILEMAP const_expr_string images_load_flags using_transparency using_opacity using_background on_bank_implicit to_identifier_optional {
                Variable * v = tilemap_storage( _environment, $2, NULL, ((struct _Environment *)_environment)->currentMode, $3, $4+$5, $6, $7 );
                if ( $8 ) {
                    prepare_variable_storage( _environment, $8, v );
                }
                variable_temporary_remove( _environment, v->name );
        } | 
    TILEMAP const_expr_string AS const_expr_string images_load_flags using_transparency using_opacity using_background on_bank_implicit to_identifier_optional {
                Variable * v = tilemap_storage( _environment, $2, $4, ((struct _Environment *)_environment)->currentMode, $5, $6+$7, $8, $9 );
                if ( $10 ) {
                    prepare_variable_storage( _environment, $10, v );
                }
                variable_temporary_remove( _environment, v->name );
        } | 
    TILEMAP tilemap_definition | 
    TILES tiles_definition | 
    TILESET const_expr_string images_load_flags using_transparency using_opacity using_background on_bank_implicit to_identifier_optional {
                Variable * v = tileset_storage( _environment, $2, NULL, ((struct _Environment *)_environment)->currentMode, $3, $4+$5, $6, $7 );
                if ( $8 ) {
                    prepare_variable_storage( _environment, $8, v );
                }
                variable_temporary_remove( _environment, v->name );
        } | 
    TILESET const_expr_string AS const_expr_string images_load_flags  using_transparency using_opacity using_background on_bank_implicit to_identifier_optional {
                Variable * v = tileset_storage( _environment, $2, $4, ((struct _Environment *)_environment)->currentMode, $5, $6+$7, $8, $9 );
                if ( $10 ) {
                    prepare_variable_storage( _environment, $10, v );
                }
                variable_temporary_remove( _environment, v->name );
        } | 
    TIMER OP_ASSIGN expr { set_timer( _environment, $3 ); } | 
    TRAVEL { ((struct _Environment *)_environment)->travelX = NULL;  ((struct _Environment *)_environment)->travelXAR = NULL;  ((struct _Environment *)_environment)->travelY = NULL;  ((struct _Environment *)_environment)->travelYAR = NULL;  } travel_definition | 
    TRIANGLE triangle_definition | 
    TYPE Identifier { begin_type( _environment, $2 ); } | 
    UNFREEZE unfreeze_definition | 
    UNTIL { end_repeat( _environment ); } expr { end_repeat_condition( _environment, $3 ); } | 
    UPB upb_definition | 
    UPW upw_definition | 
    USE use_definition | 
    VAR var_definition | 
    VCENTER vcenter_definition | 
    VCENTRE vcenter_definition | 
    VHCENTER vhcenter_definition | 
    VHCENTRE vhcenter_definition | 
    VOLUME volume_definition | 
    VSCROLL vscroll_definition | 
    WAIT wait_definition | 
    WAVE wave_definition | 
    WEND { end_while( _environment ); } | 
    WHILE {  begin_while( _environment ); } expr { begin_while_condition( _environment, $3 ); } | 
    WRITING writing_definition | 
    XOR xor_definition | 
    YIELD { yield( _environment ); };

statement2:
    |
    statement2nc
    ;

statement: 
    { 
        if ( yylinenoget() == 1 &&
            ((Environment *)_environment)->previousProducedAssemblyLines != 
                ((Environment *)_environment)->producedAssemblyLines &&
                ((Environment *)_environment)->producedAssemblyLines
         ) {
            int producedLines = ((Environment *)_environment)->producedAssemblyLines 
                - ((Environment *)_environment)->previousProducedAssemblyLines;

            outline0("; L:0");   
            outline1("; P:%d", producedLines); 
            adiline2( "P:0:%d:%d", yylinenoget() - 1, producedLines );

            ((Environment *)_environment)->previousProducedAssemblyLines = 
            ((Environment *)_environment)->producedAssemblyLines; 
        }

        outline1("; L:%d", yylinenoget() );   
    } 
    statement2;

statements_no_linenumbers:
    statement { variable_reset( _environment ); interleaved_instructions( _environment ); } | 
    statement OP_COLON { variable_reset( _environment ); interleaved_instructions( _environment ); } statements_no_linenumbers { interleaved_instructions( _environment ); };

statements_with_linenumbers:
    Integer {
            label_define_numeric( _environment, $1 );
            char lineNumber[MAX_TEMPORARY_STORAGE];
            sprintf(lineNumber, "_linenumber%d", $1 );
            cpu_label( _environment, lineNumber);
            ((Environment *)_environment)->lastDefinedLabel = strdup( lineNumber );
            ((Environment *)_environment)->lastDefinedLabelIsNumeric = 1;
            ((Environment *)_environment)->lastDefinedLabelNumeric = $1;
        } statements_no_linenumbers { 

        };

emit_additional_info:  {
            int producedLines = ((Environment *)_environment)->producedAssemblyLines 
                    - ((Environment *)_environment)->previousProducedAssemblyLines;

            outline1("; P:%d", producedLines); 

            adiline2( "P:0:%d:%d", yylinenoget() - 1 - yyconcatlineno, producedLines );
            
            ((Environment *)_environment)->previousProducedAssemblyLines = 
                ((Environment *)_environment)->producedAssemblyLines; 

        };

statements_complex3:
    statements_no_linenumbers emit_additional_info | 
    statements_with_linenumbers emit_additional_info;

statements_complex2:
    statements_complex3;

statements_complex:
    statements_complex2 | 
    statements_complex2 NewLine { yyconcatlineno = 0; } statements_complex;

program : 
    statements_complex { outline1("; L:%d", yylinenoget()); } emit_additional_info;

%%

/*****************************************************************************
 ************ COMPILER MAIN MODULE
 *****************************************************************************/

/*!
    This variable holds the current version of ugBASIC (format: x.y.z).
    Versioning for ugBASIC follows a very precise logic, dictated by the 
    very nature of the project: a constantly evolving software that must 
    support dozens of different platforms. The format used is a variant of 
    Semantic Versioning, generally structured with three digits: `MAJOR.MINOR.BUILD`.

    The MAJOR indicates a radical change in the compiler architecture or in the 
    language itself. The MINOR represents the release of new hardware. The BUILD
    Indicates bug fixes, refinements and/or new functionalities.

    The versioning is important, since ugBASIC works with extremely different 
    target hardware. A version change can affect memory footprint, since it may
    optimize the generated assembly code, allowing the program to use less RAM.
    Since each video chip is managed by the compiler, a new MINOR version may 
    unlock graphics capabilities previously unavailable for a specific machine.
    Although if the author strive to maintain backward compatibility, a MAJOR 
    version jump may require minor modifications to the old ".bas" source code 
    to accommodate new language conventions.

    You can check the version of the compiler you are using directly from 
    the command line by run the compiler without parameters-
 */
char version[MAX_TEMPORARY_STORAGE] = UGBASIC_VERSION;

/*!
    This variable holds the current commit of ugBASIC (format: hexadecimal string).
 */
char revision[MAX_TEMPORARY_STORAGE] = UGBASIC_REVISION;

/*!
 @brief Show usage and exit
 
 When using a CLI (Command Line Interface), you must pass a series of parameters (the 
 source file, the target, any optimization options). If the user makes a syntax error 
 or explicitly requests help, this function intervenes. This function lists all available 
 flags (e.g., `-t` for the target, `-o` for output, `-i` for includes, and so on). It 
 displays a list of all retrocomputers for which  ugBASIC can compile. Finally, 
 terminates the program, returning a status code to the operating system.

 @param _argc The number of parameters given on the command line.
 @param _argv The array of parameters given on the command line.
 */
void show_usage_and_exit( int _argc, char *_argv[] ) {

    printf("--------------------------------------------------\n");
    printf("ugBASIC Compiler v%s [target: %s]\n", UGBASIC_VERSION, targetDescription);
    printf("--------------------------------------------------\n");
    printf("Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)\n\n");
    printf("Licensed under the Apache License, Version 2.0 (the \"License\");\n");
    printf("you may not use this program except in compliance with the License.\n\n");

    printf("usage: %s [options] <source> [<asm>]\n\n", _argv[0] );

    printf("Options and parameters:\n\n" );

    printf("\t<source>     Input filename with ugBASIC source code\n" );
    printf("\t<asm>        Output filename with ASM source code (optional, if '-o' given)\n" );
    printf("\n" );

    printf("\t-1           Enable 10-liners mode\n" );
    printf("\t               It includes an execution shell and it enforces other.\n" );
    printf("\t               10-liners rules.\n" );
    printf("\t-a           Show statistics on assembly listing generated\n" );
    printf("\t-A <file>    Path to app maker\n" );
#if defined(__coco__) || defined(__coco3__) || defined(__cocob__) || defined(__coco3b__)
    printf("\t-b <file>    Path to DECB image tool\n" );
#endif
    printf("\t-c <file>    Output filename with linker configuration\n" );
    printf("\t-C <file>    Path to compiler\n" );
    printf("\t-d           Enable debugging of LOAD IMAGE\n" );
    printf("\t-e <modules> Embed specified modules instead of inline code\n" );
    printf("\t-E           Show stats of embedded modules\n" );
    printf("\t-f           Enable DOJO over virtualized FujiNet\n" );
    printf("\t-F           Enable DOJO over FujiNet\n" );
#if defined(__pc128op__) || defined(__mo5__) || defined(__to8__)
    printf("\t-G <type>    Type of gamma correction on PALETTE generation:\n" );
    printf("\t               none (0): no gamma correction\n" );
    printf("\t               type1 (1): algorithmic\n" );
    printf("\t               type2 (2): by threshold\n" );
#endif
    printf("\t-l <name>    Output filename with list of variables defined\n" );
#if defined(__zx__) || defined(__msx1__) || defined(__coleco__) || defined(__sc3000__) || defined(__sg1000__) || defined(__cpc__) || defined(__c128z__) || defined(__gb__) || defined(__vz200__)
    printf("\t-L <ignored> Output filename with assembly listing file\n" );
#else
    printf("\t-L <listing> Output filename with assembly listing file\n" );
#endif
    printf("\t-o <exe>     Output filename with final executable file for target\n" );
    printf("\t-O <type>    Output file format for target:\n" );
#if defined(__atari__) || defined(__atarixl__)
    printf("\t                xex - executable binary file\n" );
    printf("\t                atr - ATR disk image\n" );
#elif defined(__c64__) || defined(__vic20__)
    printf("\t                prg - program binary file\n" );
    printf("\t                d64 - D64 disk image\n" );
#elif defined(__c64reu__)
    printf("\t                d64 - D64 disk image\n" );
    printf("\t                reu - REU RAM espansion image\n" );
#elif defined(__c128__)
    printf("\t                prg - program binary file\n" );
    printf("\t                d64 - D64 disk image\n" );
#elif defined(__c128z__) || defined(__plus4__) || defined(__c16__)
    printf("\t                prg - program binary file\n" );
#elif defined(__coco__) || defined(__cocob__) || defined(__coco3__) || defined(__coco3b__)
    printf("\t                bin    - COCO binary file\n" );
    printf("\t                dsk    - COCO disk basic (binary loader)\n" );
    printf("\t                dskold - COCO disk basic (BASIC loader)\n" );
#elif defined(__coleco__)
    printf("\t                rom - cartridge ROM\n" );
#elif defined(__cpc__)
    printf("\t                bin - binary image\n" );
    printf("\t                dsk - disk image\n" );
#elif defined(__d32__) || defined(__d32b__) || defined(__d64__) || defined(__d64b__) 
    printf("\t                bin - dragon dos binary file\n" );
#elif defined(__gb__)
    printf("\t                gb - cartridge ROM\n" );
#elif defined(__mo5__)
    printf("\t                k7 - K7 format\n" );
    printf("\t                k7o - K7 format (original algorithm)\n" );
#elif defined(__msx1__)
    printf("\t                rom - cartridge ROM\n" );
    printf("\t                dsk - DSK image\n" );
#elif defined(__pc128op__)
    printf("\t                sddrive - USBDRIVE compatible format\n" );
    printf("\t                k7 - K7 format\n" );
    printf("\t                k7o - K7 format (original algorithm)\n" );
#elif defined(__pc1403__)
    printf("\t                ram - RAM loadable by debugger\n" );
#elif defined(__pccga__)
    printf("\t                com - binary executable\n" );
#elif defined(__sc3000__) || defined(__sg1000__)
    printf("\t                rom - cartridge ROM\n" );
#elif defined(__to8__)
    printf("\t                k7 - K7 format\n" );
#elif defined(__vg5000__)
    printf("\t                k7 - K7 format\n" );
#elif defined(__vz200__)
    printf("\t                vz - file snapshot\n" );
#elif defined(__zx__)
    printf("\t                tap - tape file\n" );
#endif
    printf("\t-p <num>     Maximum number of peep hole optimizations passes (default: 16, 0 = disable)\n" );
    printf("\t-P <file>    Path to profile (-L needed)\n" );
    printf("\t-q <cycles>  Cycles for profiling (default: 1000000)\n" );
#if defined(__c64reu__) || defined(__to8__)
    printf("\t-R <size>    Size of expansion memory (in KB)\n" );
#endif
    printf("\t-s           Enforces sandbox running rules.\n" );
#if defined(__atari__) || defined(__atarixl__)
    printf("\t-t <file>    Path to DIR2ATR tool\n" );
#elif defined(__msx1__)
    printf("\t-t <file>    Path to DSKTOOLS tool\n" );
#elif defined(__pc1403__)
    printf("\t-t <file>    Path to ASLINK tool\n" );
#endif
    printf("\t-T <path>    Path to temporary path\n" );
    printf("\t-V           Output version (example: '%s')\n", version );
    printf("\t-v           Output generated files\n" );
    printf("\t-X <file>    Path to executer\n" );
    printf("\t-W           Enable warnings during compilation\n" );
    printf("\t-y           Enable BISON debugging\n" );
    printf("\n\n" );
    printf("Examples:\n" );
    printf("\tTo generate an assembly starting from basic source:\n" );
    printf("\t\t%s source.bas source.asm\n\n", _argv[0] );
    printf("To generate directly an executable:\n" );
    printf("\t\t%s -O %s -o source.%s source.bas\n\n", _argv[0], defaultExtension, defaultExtension );

    exit(EXIT_FAILURE);
}

/*!
 @brief Main procedure
 
 @param _argc The number of parameters given on the command line.
 @param _argv The array of parameters given on the command line.
 */
int main( int _argc, char *_argv[] ) {

    extern FILE *yyin;
    int flags;
    int nsecs, tfnd;

    Environment * _environment = environment_create();

    environment_setup_embedded( _environment );

    environment_setup_default( _environment );

    environment_parse_command_line( _environment, _argc, _argv );

    _environment->sourceFileName = strdup(_argv[optind] );
    
    environment_setup_retrohack( _environment );

    if ( _environment->tenLinerRulesEnforced ) {
        environment_setup_10liner( _environment );
    }
    
    if ( _environment->tenLinerRulesEnforced ) {
        FILE * fh = fopen( _environment->sourceFileName, "rb" );
        if ( ! fh ) {
            fprintf(stderr, "Unable to open source file: %s (%d - %s)\n", _environment->sourceFileName, errno, strerror(errno) );
            exit(EXIT_FAILURE);
        }
        fseek( fh, 0, SEEK_END );
        int sourceSize = ftell( fh );
        fseek( fh, 0, SEEK_SET );
        char * sourceText = malloc( sourceSize + 1 );
        memset( sourceText, 0, sourceSize + 1 );
        unsigned char utf8check = fgetc( fh );
        if ( utf8check == 0xef ) {
            fseek(fh, 3, SEEK_SET );
            sourceSize -= 3;
        } else {
            fseek(fh, 0, SEEK_SET );
        }
        (void)!fread( sourceText, 1, sourceSize, fh );
        fclose( fh );
        char * escapedSourceText = unescape_string( _environment, sourceText, 1, NULL );
        int i=0;
        for( int c=strlen(escapedSourceText); i<c; ++i ) {
            if ( escapedSourceText[i] == 0x0d ) {
                escapedSourceText[i] = 0x20;
            }
        }
        for( ; i>0; --i ) {
            if ( escapedSourceText[i] != 0x20 && escapedSourceText[i] != 0x0a ) {
                break;
            }
            escapedSourceText[i] = 0;
        }
        Variable * source = variable_define( _environment, "SHELL_SOURCE", VT_BUFFER, 0 );
        variable_store_buffer( _environment, source->name, escapedSourceText, strlen(escapedSourceText), 0 );
        source->printable = 1;
        source->readonly = 1;
    }

    if ( _environment->exeFileName && !_argv[optind+1]) {
        char asmFileName[MAX_TEMPORARY_STORAGE];
        sprintf( asmFileName, "%s.asm", get_temporary_filename( _environment ) );
        _environment->asmFileName = strdup(asmFileName);
    } else {
        _environment->asmFileName = strdup(_argv[optind+1] );
    }
    
    yyin = fopen( _environment->sourceFileName, "r" );
    if ( ! yyin ) {
        fprintf(stderr, "Unable to open source file: %s (%d - %s)\n", _environment->sourceFileName, errno, strerror(errno) );
        exit(EXIT_FAILURE);
    }

    unsigned char utf8check = fgetc( yyin );

    if ( utf8check == 0xef ) {
        fseek(yyin, 3, SEEK_SET );
    } else {
        fseek(yyin, 0, SEEK_SET );
    }

    if ( _environment->additionalInfoFileName ) {
        _environment->additionalInfoFile = fopen( _environment->additionalInfoFileName, "wt" );
    }
    
    filenamestacked[0] = strdup( _environment->sourceFileName );

    begin_compilation( _environment );

    yyparse (_environment);

    end_compilation( _environment );

    target_peephole_optimizer( _environment );

    if ( _environment->exeFileName ) {
        begin_build( _environment );
        end_build( _environment );
    }

    if ( _environment->additionalInfoFile ) {
        fflush( _environment->additionalInfoFile );
        fclose( _environment->additionalInfoFile );
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
        stats_embedded( cpu_compare_and_branch_16bit_const );
        stats_embedded( cpu_compare_and_branch_32bit_const );
        stats_embedded( cpu_compare_and_branch_8bit_const );
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
        stats_embedded( cpu_xor_8bit );
        stats_embedded( cpu_swap_8bit );
        stats_embedded( cpu_not_16bit );
        stats_embedded( cpu_and_16bit );
        stats_embedded( cpu_swap_16bit );
        stats_embedded( cpu_or_16bit );
        stats_embedded( cpu_xor_16bit );
        stats_embedded( cpu_not_32bit );
        stats_embedded( cpu_and_32bit );
        stats_embedded( cpu_or_32bit );
        stats_embedded( cpu_xor_32bit );
        stats_embedded( cpu_swap_32bit );
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
        stats_embedded( cpu_number_to_string );
        stats_embedded( cpu_move_8bit_indirect_with_offset );
        stats_embedded( cpu_bits_to_string );
        stats_embedded( cpu_hex_to_string );
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
        stats_embedded( cpu_sqroot );
    }

    return 0;

}

int yyerror ( Environment * _ignored, const char * _message ) /* Called by yyparse on error */
{
    char * message = strdup(_message);

    if ( _ignored ) {
        message = strreplace( message, "Remark", "remark symbol (REM)" );
        message = strreplace( message, "NewLine", "new line (CR/LF)" );
        message = strreplace( message, "OP_PERIOD", "period (.)" );
        message = strreplace( message, "OP_SEMICOLON", "semicolon (;)" );
        message = strreplace( message, "OP_COLON", "colon (:)" );
        message = strreplace( message, "OP_COMMA", "comma (,)" );
        message = strreplace( message, "OP_MINUS", "minus sign (-)" );
        message = strreplace( message, "OP_EQUAL", "equal sign (==)" );
        message = strreplace( message, "OP_ASSIGN", "equal sign (=)" );
        message = strreplace( message, "OP_LT", "less than operator (<)" );
        message = strreplace( message, "OP_LTE", "less than or equal operator (<=)" );
        message = strreplace( message, "OP_GT", "greater than operator (>)" );
        message = strreplace( message, "OP_GTE", "greater than operator (>=)" );
        message = strreplace( message, "OP_DISEQUAL", "other than operator (<>)" );
        message = strreplace( message, "OP_MULTIPLICATION", "multiplication operator (*)" );
        message = strreplace( message, "OP_MULTIPLICATION2", "multiplication operator (**)" );
        message = strreplace( message, "OP_DOLLAR", "dollar symbol ($)" );
        message = strreplace( message, "OP_DIVISION", "division operator (/)" );
        message = strreplace( message, "OP_DIVISION2", "division operator (\\)" );
        message = strreplace( message, "OP_QM", "question mark (?)" );
        message = strreplace( message, "OP_HASH", "hash operator (#)" );
        message = strreplace( message, "OP_ASSIGN_DIRECT", "assignment operator (:=)" );
        message = strreplace( message, "OP_EXCLAMATION", "exclamation point (!)" );
        message = strreplace( message, "OP_DOLLAR2", "double dollar sing ($$)" );
        message = strreplace( message, "BEG", "BEGIN" );
        message = strreplace( message, "OSP", "open square bracket" );
        message = strreplace( message, "CSP", "closed square bracket" );
        message = strreplace( message, "OGP", "open curly bracket" );
        message = strreplace( message, "CGP", "closed curly bracket" );
        message = strreplace( message, "OP_PERC", "percentage sign (%)" );
        message = strreplace( message, "OP_PERC2", "double percentage sign (%%)" );
        message = strreplace( message, "OP_PLUS", "plus sign (+)" );
        message = strreplace( message, "OP_MINUS", "minus sign (-)" );
        message = strreplace( message, "OP_AMPERSAND", "ampersand sign (&)" );
        message = strreplace( message, "OP_AT", "at sign (@)" );
        message = strreplace( message, "NULLkw", "NULL" );
        message = strreplace( message, "Identifier", "identifier (name)" );
        message = strreplace( message, "IdentifierSpaced", "identifier (name)" );
        message = strreplace( message, "String", "string" );
        message = strreplace( message, "Integer", "integer number" );
        message = strreplace( message, "BufferDefinitionHex", "buffer definition (in hex format)" );
        message = strreplace( message, "RawString", "string" );
        message = strreplace( message, "Float", "floating point number" );
        message = strreplace( message, "Register", "CPU register" );
        message = strreplace( message, "AsmSnippet", "assembly code" );
        message = strreplace( message, "OP", "open parenthesis" );
        message = strreplace( message, "CP", "closed parenthesis" );
    }

    if ( stacked == 0 ) {
      fprintf(stderr,  "*** ERROR: %s at %d column %d (%d)\n", message, yylloc.first_line, yylloc.first_column, (yyposno+1));
    } else {
      fprintf(stderr,  "*** ERROR: %s at %d column %d (%d, %s)\n", message, yylloc.first_line, yylloc.first_column, (yyposno+1), filenamestacked[stacked]);
    }
    
    exit(EXIT_FAILURE);

}

int yywarning ( Environment * _ignored, const char * _message ) /* Called by yyparse on warning */
{
    char * message = strdup(_message);

    if ( _ignored ) {
        message = strreplace( message, "Remark", "remark symbol (REM)" );
        message = strreplace( message, "NewLine", "new line (CR/LF)" );
        message = strreplace( message, "OP_PERIOD", "period (.)" );
        message = strreplace( message, "OP_SEMICOLON", "semicolon (;)" );
        message = strreplace( message, "OP_COLON", "colon (:)" );
        message = strreplace( message, "OP_COMMA", "comma (,)" );
        message = strreplace( message, "OP_MINUS", "minus sign (-)" );
        message = strreplace( message, "OP_EQUAL", "equal sign (==)" );
        message = strreplace( message, "OP_ASSIGN", "equal sign (=)" );
        message = strreplace( message, "OP_LT", "less than operator (<)" );
        message = strreplace( message, "OP_LTE", "less than or equal operator (<=)" );
        message = strreplace( message, "OP_GT", "greater than operator (>)" );
        message = strreplace( message, "OP_GTE", "greater than operator (>=)" );
        message = strreplace( message, "OP_DISEQUAL", "other than operator (<>)" );
        message = strreplace( message, "OP_MULTIPLICATION", "multiplication operator (*)" );
        message = strreplace( message, "OP_MULTIPLICATION2", "multiplication operator (**)" );
        message = strreplace( message, "OP_DOLLAR", "dollar symbol ($)" );
        message = strreplace( message, "OP_DIVISION", "division operator (/)" );
        message = strreplace( message, "OP_DIVISION2", "division operator (\\)" );
        message = strreplace( message, "OP_QM", "question mark (?)" );
        message = strreplace( message, "OP_HASH", "hash operator (#)" );
        message = strreplace( message, "OP_ASSIGN_DIRECT", "assignment operator (:=)" );
        message = strreplace( message, "OP_EXCLAMATION", "exclamation point (!)" );
        message = strreplace( message, "OP_DOLLAR2", "double dollar sing ($$)" );
        message = strreplace( message, "BEG", "BEGIN" );
        message = strreplace( message, "OSP", "open square bracket" );
        message = strreplace( message, "CSP", "closed square bracket" );
        message = strreplace( message, "OGP", "open curly bracket" );
        message = strreplace( message, "CGP", "closed curly bracket" );
        message = strreplace( message, "OP_PERC", "percentage sign (%)" );
        message = strreplace( message, "OP_PERC2", "double percentage sign (%%)" );
        message = strreplace( message, "OP_PLUS", "plus sign (+)" );
        message = strreplace( message, "OP_MINUS", "minus sign (-)" );
        message = strreplace( message, "OP_AMPERSAND", "ampersand sign (&)" );
        message = strreplace( message, "OP_AT", "at sign (@)" );
        message = strreplace( message, "NULLkw", "NULL" );
        message = strreplace( message, "Identifier", "identifier (name)" );
        message = strreplace( message, "IdentifierSpaced", "identifier (name)" );
        message = strreplace( message, "String", "string" );
        message = strreplace( message, "Integer", "integer number" );
        message = strreplace( message, "BufferDefinitionHex", "buffer definition (in hex format)" );
        message = strreplace( message, "RawString", "string" );
        message = strreplace( message, "Float", "floating point number" );
        message = strreplace( message, "Register", "CPU register" );
        message = strreplace( message, "AsmSnippet", "assembly code" );
        message = strreplace( message, "OP", "open parenthesis" );
        message = strreplace( message, "CP", "closed parenthesis" );
    }

    if ( stacked == 0 ) {
      fprintf(stderr,  "WARNING %s at %d column %d (%d)\n", message, yylloc.first_line, yylloc.first_column, (yyposno+1));
    } else {
      fprintf(stderr,  "WARNING %s at %d column %d (%d, %s)\n", message, yylloc.first_line, yylloc.first_column, (yyposno+1), filenamestacked[stacked]);
    }
    
    exit(EXIT_FAILURE);

}

int yylinenoget ( ) {
    return yylloc.first_line;
}
