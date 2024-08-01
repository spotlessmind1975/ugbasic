%{

#include "../src/ugbc.h"

int yylex();
int yyerror(Environment *, const char *);
int yydebug=0;
int errors=0;
extern int yylineno;
extern int yyconcatlineno;

int yycolno;
int yyposno;

char * filenamestacked[256];
int yylinenostacked[256];
int yycolnostacked[256];
int yyposnostacked[256];
int stacked = 0;
char * importPath;

char * asmSnippet = NULL;

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
    double floating;
}

%token Remark
%token NewLine 
%token OP_SEMICOLON OP_COLON OP_COMMA OP_PLUS OP_MINUS OP_INC OP_DEC OP_EQUAL OP_ASSIGN OP_LT OP_LTE OP_GT OP_GTE 
%token OP_DISEQUAL OP_MULTIPLICATION OP_MULTIPLICATION2 OP_DOLLAR OP_DIVISION OP_DIVISION2 QM HAS IS OF OP_HASH OP_POW OP_ASSIGN_DIRECT
%token OP_EXCLAMATION OP_DOLLAR2

%token RASTER DONE AT COLOR COLOUR BORDER WAIT NEXT WITH BANK SPRITE DATA FROM OP CP 
%token ENABLE DISABLE HALT ECM BITMAP SCREEN ON OFF ROWS VERTICAL SCROLL VAR AS TEMPORARY 
%token XPEN YPEN PEEK GOTO HORIZONTAL MCM COMPRESS EXPAND LOOP REPEAT WHILE TEXT TILES
%token COLORMAP COLOURMAP SELECT MONOCOLOR MONOCOLOUR MULTICOLOR MULTICOLOUR COLLISION IF THEN HIT BACKGROUND TO RANDOM
%token BYTE WORD POSITION CODE VARIABLES MS CYCLES WIDTH HEIGHT DWORD PEN CLEAR
%token BEG END GAMELOOP ENDIF UP DOWN LEFT RIGHT AND RANDOMIZE GRAPHIC TEXTMAP
%token POINT GOSUB RETURN POP OR ELSE NOT TRUE FALSE DO EXIT WEND UNTIL FOR STEP EVERY
%token MID INSTR UPPER LOWER STR VAL STRING SPACE FLIP CHR ASC LEN MOD ADD MIN MAX SGN
%token SIGNED ABS RND COLORS COLOURS INK TIMER POWERING DIM ADDRESS PROC PROCEDURE CALL OSP CSP
%token SHARED MILLISECOND MILLISECONDS TICK TICKS GLOBAL PARAM PRINT DEFAULT USE
%token PAPER INVERSE REPLACE XOR IGNORE NORMAL WRITING ONLY LOCATE CLS HOME CMOVE
%token CENTER CENTRE TAB SET CUP CDOWN CLEFT CRIGHT CLINE XCURS YCURS MEMORIZE REMEMBER
%token HSCROLL VSCROLL TEXTADDRESS JOY BIN BIT COUNT JOYCOUNT FIRE JUP JDOWN JLEFT JRIGHT JFIRE
%token INKEY SCANCODE SCAN SHIFT SCANSHIFT BOTH SHIFTS NONE LETTER ASTERISK COLON COMMA 
%token COMMODORE CONTROL CRSR CURSOR DELETE EQUAL FUNCTION INSERT ARROW MINUS PERIOD PLUS 
%token POUND RUNSTOP RUN STOP SEMICOLON SLASH KEY STATE KEYSTATE KEYSHIFT CAPSLOCK CAPS LOCK ALT
%token INPUT FREE TILEMAP EMPTY TILE EMPTYTILE PLOT GR CIRCLE DRAW LINE BOX POLYLINE ELLIPSE CLIP
%token BACK DEBUG CAN ELSEIF BUFFER LOAD SIZE IMAGE PUT VISIBLE HIDDEN HIDE SHOW RENDER
%token SQR TI CONST VBL POKE NOP FILL IN POSITIVE DEFINE ATARI ATARIXL C64 DRAGON DRAGON32 DRAGON64 PLUS4 ZX 
%token FONT VIC20 PARALLEL YIELD SPAWN THREAD TASK IMAGES FRAME FRAMES XY YX ROLL MASKED USING TRANSPARENCY
%token OVERLAYED CASE ENDSELECT OGP CGP ARRAY NEW GET DISTANCE TYPE MUL DIV RGB SHADES HEX PALETTE
%token BAR XGRAPHIC YGRAPHIC XTEXT YTEXT COLUMNS XGR YGR CHAR RAW SEPARATOR MSX MSX1 COLECO CSPRITE 
%token TILESET MOVE ROW COLUMN TRANSPARENT DOUBLE RESPAWN HALTED SC3000 SG1000 MEMORY VIDEO MMOVE SWAP
%token BELONG FIRST EXACT PRESSED PC128OP MO5 VARPTR READ WRITE BANKED SEQUENCE MODE UNIQUE C128
%token SOUND BOOM SHOOT BELL NOTE VOLUME PLAY INSTRUMENT AAHS ACCORDION ACOUSTIC AGE AGOGO 
%token ALTO APPLAUSE ATMOSPHERE BAG BANJO BARITONE BASS BASSOON BELLS BIRD BLOWN BOTTLE BOWED BRASS
%token BREATH BRIGHT BRIGHTNESS CALLIOPE CELESTA CELLO CHARANG CHIFF CHOIR CHURCH CLARINET CLAVI CLEAN 
%token CONTRABASS CRYSTAL CYMBAL DISTORTION DRAWBAR DRUM DRUMS DULCIMER ECHOES ELECTRIC ENGLISH ENSEMBLE
%token EXPLOSION FI FIDDLE FIFTHS FINGER FLUTE FRENCH FRET FRETLESS FX GLOCKENSPIEL GOBLINS GRAND GUITAR 
%token GUNSHOT HALO HARMONICA HARMONICS HARP HARPSICHORD HELICOPTER HONKY HORN JAZZ KALIMBA KOTO LEAD
%token MARIMBA MELODIC METALLIC MUSIC MUTED NOISE NYLON OBOE OCARINA OOHS ORCHESTRA ORCHESTRAL ORGAN 
%token OVERDRIVEN PAD PAN PERCUSSIVE PIANO PICCOLO PICK PIPE PIZZICATO POLYSYNTH RAIN RECORDER REED REVERSE 
%token RING ROCK SAWTOOTH SAX SCI SEASHORE SECTION SHAKUHACHI SHAMISEN SHANAI SITAR SLAP SOPRANO SOUNDTRACK
%token SQUARE STEEL STRINGS SWEEP SYNTH SYNTHBRASS SYNTHSTRINGS TAIKO TANGO TELEPHONE TENOR TIMPANI TINKLE
%token TOM TONK TREMOLO TROMBONE TRUMPET TUBA TUBULAR TWEET VIBRAPHONE VIOLA VIOLIN VOICE WARM WHISTLE WOODBLOCK 
%token XYLOPHONE KILL COMPRESSED STORAGE ENDSTORAGE FILEX DLOAD INCLUDE LET CPC INT INTEGER LONG OP_PERC OP_PERC2 OP_AMPERSAND OP_AT
%token EMBEDDED NATIVE RELEASE READONLY DIGIT OPTION EXPLICIT ORIGIN RELATIVE DTILE DTILES OUT RESOLUTION
%token COPEN COCO STANDARD SEMIGRAPHIC COMPLETE PRESERVE BLIT COPY THRESHOLD SOURCE DESTINATION VALUE
%token LBOUND UBOUND BINARY C128Z FLOAT FAST SINGLE PRECISION DEGREE RADIAN PI SIN COS BITMAPS OPACITY
%token ALL BUT VG5000 CLASS PROBABILITY LAYER SLICE INDEX SYS EXEC REGISTER CPU6502 CPU6809 CPUZ80 ASM 
%token STACK DECLARE SYSTEM KEYBOARD RATE DELAY NAMED MAP ID RATIO BETA PER SECOND AUTO COCO1 COCO2 COCO3
%token RESTORE SAFE PAGE PMODE PCLS PRESET PSET BF PAINT SPC UNSIGNED NARROW WIDE AFTER STRPTR ERROR
%token POKEW PEEKW POKED PEEKD DSAVE DEFDGR FORBID ALLOW C64REU LITTLE BIG ENDIAN NTSC PAL VARBANK VARBANKPTR
%token IAF PSG MIDI ATLAS PAUSE RESUME SEEK DIRECTION CONFIGURE STATIC DYNAMIC GMC SLOT SN76489 LOG EXP TO8
%token AUDIO SYNC ASYNC TARGET SJ2 CONSOLE SAVE COMBINE NIBBLE INTERRUPT MSPRITE UPDATE OFFSET JOYSTICK AVAILABLE
%token PROGRAM START JOYX JOYY RETRIES PALETTE1 BLOCK REC HIRES IMPLICIT NULLkw KEYGET NRM NEWLINE WITHOUT TSB
%token VALUES INST CGOTO DUP ENVELOPE

%token A B C D E F G H I J K L M N O P Q R S T U V X Y W Z
%token F1 F2 F3 F4 F5 F6 F7 F8

%token BLACK WHITE RED CYAN VIOLET GREEN BLUE YELLOW ORANGE
%token BROWN LIGHT DARK GREY GRAY MAGENTA PURPLE
%token LAVENDER GOLD TURQUOISE TAN PINK PEACH OLIVE

%token <string> Identifier
%token <string> IdentifierSpaced
%token <string> String
%token <integer> Integer
%token <string> BufferDefinitionHex
%token <string> RawString
%token <floating> Float
%token <string> Register
%token <string> AsmSnippet

%type <string> expr term modula factor exponential expr_math expr_math2
%type <integer> const_expr const_term const_modula const_factor const_expr_math const_expr_math2
%type <string> const_expr_string const_expr_string_const
%type <floating> const_expr_floating
%type <integer> direct_integer
%type <string> random_definition_simple random_definition
%type <string> color_enumeration
%type <string> writing_mode_definition writing_part_definition
%type <string> key_scancode_definition key_scancode_alphadigit key_scancode_function_digit
%type <integer> const_key_scancode_definition const_key_scancode_alphadigit const_key_scancode_function_digit
%type <integer> datatype as_datatype as_datatype_mandatory as_datatype_suffix as_datatype_suffix_optional
%type <integer> halted
%type <integer> optional_integer
%type <string> optional_expr optional_x optional_y optional_x_or_string
%type <string> mandatory_x mandatory_y
%type <integer> target targets
%type <integer> parallel_optional
%type <integer> on_targets
%type <integer> scroll_definition_hdirection scroll_definition_vdirection
%type <integer> load_flags load_flags1 load_flag
%type <integer> tile_load_flags tile_load_flags1 tile_load_flag
%type <integer> image_load_flags image_load_flags1 image_load_flag
%type <integer> images_load_flags images_load_flags1 images_load_flag
%type <integer> sequence_load_flags sequence_load_flags1 sequence_load_flag
%type <integer> put_image_flags put_image_flags1 put_image_flag
%type <integer> blit_image_flags blit_image_flags1 blit_image_flag
%type <integer> flip_image_flags
%type <integer> const_color_enumeration
%type <integer> using_transparency
%type <integer> using_opacity
%type <integer> using_background
%type <integer> memory_video
%type <integer> sprite_flag sprite_flags sprite_flags1
%type <integer> on_bank
%type <integer> note octave const_note
%type <integer> const_instrument
%type <integer> release
%type <integer> readonly_optional
%type <integer> option_explicit origin_direction relative_option option_clip option_read
%type <integer> font_schema
%type <integer> blit_unary_op blit_binary_op blit_operand
%type <integer> blit_expression blit_compounded
%type <integer> precision 
%type <integer> asmio
%type <integer> system
%type <string> padding_tile
%type <integer> op_comma_or_semicolon
%type <integer> read_safeness
%type <integer> line_mode box_mode put_action
%type <string> timer_number timer_number_comma
%type <string> dload_from_offset dload_to_address dload_size_size
%type <string> dsave_to_offset dsave_from_address dsave_size_size
%type <string> to_variable
%type <string> optional_step
%type <integer> music_type
%type <integer> optional_loop
%type <integer> configure_name
%type <integer> option_name
%type <integer> audio_source
%type <integer> PALETTE1

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

const_instrument :
    EXPLOSION { $$ = IMF_INSTRUMENT_EXPLOSION; } |
    ACOUSTIC GRAND PIANO { $$ = IMF_INSTRUMENT_ACOUSTIC_GRAND_PIANO; } |
    BRIGHT ACOUSTIC PIANO { $$ = IMF_INSTRUMENT_BRIGHT_ACOUSTIC_PIANO; } |
    ELECTRIC GRAND PIANO { $$ = IMF_INSTRUMENT_ELECTRIC_GRAND_PIANO; } |
    HONKY TONK PIANO { $$ = IMF_INSTRUMENT_HONKY_TONK_PIANO; } |
    ELECTRIC PIANO "1" { $$ = IMF_INSTRUMENT_ELECTRIC_PIANO1; } |
    ELECTRIC PIANO "2" { $$ = IMF_INSTRUMENT_ELECTRIC_PIANO2; } |
    HARPSICHORD { $$ = IMF_INSTRUMENT_HARPSICHORD; } |
    CLAVI { $$ = IMF_INSTRUMENT_CLAVI; } |
    CELESTA { $$ = IMF_INSTRUMENT_CELESTA; } |
    GLOCKENSPIEL { $$ = IMF_INSTRUMENT_GLOCKENSPIEL; } |
    MUSIC BOX { $$ = IMF_INSTRUMENT_MUSIC_BOX; } |
    VIBRAPHONE { $$ = IMF_INSTRUMENT_VIBRAPHONE; } |
    MARIMBA { $$ = IMF_INSTRUMENT_MARIMBA; } |
    XYLOPHONE { $$ = IMF_INSTRUMENT_XYLOPHONE; } |
    TUBULAR BELLS { $$ = IMF_INSTRUMENT_TUBULAR_BELLS; } |
    DULCIMER { $$ = IMF_INSTRUMENT_DULCIMER; } |
    DRAWBAR ORGAN { $$ = IMF_INSTRUMENT_DRAWBAR_ORGAN; } |
    PERCUSSIVE ORGAN { $$ = IMF_INSTRUMENT_PERCUSSIVE_ORGAN; } |
    ROCK ORGAN { $$ = IMF_INSTRUMENT_ROCK_ORGAN; } |
    CHURCH ORGAN { $$ = IMF_INSTRUMENT_CHURCH_ORGAN; } |
    REED ORGAN { $$ = IMF_INSTRUMENT_REED_ORGAN; } |
    ACCORDION { $$ = IMF_INSTRUMENT_ACCORDION; } |
    HARMONICA { $$ = IMF_INSTRUMENT_HARMONICA; } |
    TANGO ACCORDION { $$ = IMF_INSTRUMENT_TANGO_ACCORDION; } |
    ACOUSTIC GUITAR NYLON { $$ = IMF_INSTRUMENT_ACOUSTIC_GUITAR_NYLON; } |
    ACOUSTIC GUITAR STEEL { $$ = IMF_INSTRUMENT_ACOUSTIC_GUITAR_STEEL; } |
    ELECTRIC GUITAR JAZZ { $$ = IMF_INSTRUMENT_ELECTRIC_GUITAR_JAZZ; } |
    ELECTRIC GUITAR CLEAN { $$ = IMF_INSTRUMENT_ELECTRIC_GUITAR_CLEAN; } |
    ELECTRIC GUITAR MUTED { $$ = IMF_INSTRUMENT_ELECTRIC_GUITAR_MUTED; } |
    OVERDRIVEN GUITAR { $$ = IMF_INSTRUMENT_OVERDRIVEN_GUITAR; } |
    DISTORTION GUITAR { $$ = IMF_INSTRUMENT_DISTORTION_GUITAR; } |
    GUITAR HARMONICS { $$ = IMF_INSTRUMENT_GUITAR_HARMONICS; } |
    ACOUSTIC BASS { $$ = IMF_INSTRUMENT_ACOUSTIC_BASS; } |
    ELECTRIC BASS FINGER { $$ = IMF_INSTRUMENT_ELECTRIC_BASS_FINGER; } |
    ELECTRIC BASS PICK { $$ = IMF_INSTRUMENT_ELECTRIC_BASS_PICK; } |
    FRETLESS BASS { $$ = IMF_INSTRUMENT_FRETLESS_BASS; } |
    SLAP BASS "1" { $$ = IMF_INSTRUMENT_SLAP_BASS_1; } |
    SLAP BASS "2" { $$ = IMF_INSTRUMENT_SLAP_BASS_2; } |
    SYNTH BASS "1" { $$ = IMF_INSTRUMENT_SYNTH_BASS_1; } |
    SYNTH BASS "2" { $$ = IMF_INSTRUMENT_SYNTH_BASS_2; } |
    VIOLIN { $$ = IMF_INSTRUMENT_VIOLIN; } |
    VIOLA { $$ = IMF_INSTRUMENT_VIOLA; } |
    CELLO { $$ = IMF_INSTRUMENT_CELLO; } |
    CONTRABASS { $$ = IMF_INSTRUMENT_CONTRABASS; } |
    TREMOLO STRINGS { $$ = IMF_INSTRUMENT_TREMOLO_STRINGS; } |
    PIZZICATO STRINGS { $$ = IMF_INSTRUMENT_PIZZICATO_STRINGS; } |
    ORCHESTRAL HARP { $$ = IMF_INSTRUMENT_ORCHESTRAL_HARP; } |
    TIMPANI { $$ = IMF_INSTRUMENT_TIMPANI; } |
    STRING ENSEMBLE "1" { $$ = IMF_INSTRUMENT_STRING_ENSEMBLE_1; } |
    STRING ENSEMBLE "2" { $$ = IMF_INSTRUMENT_STRING_ENSEMBLE_2; } |
    SYNTHSTRINGS "1" { $$ = IMF_INSTRUMENT_SYNTHSTRINGS_1; } |
    SYNTHSTRINGS "2" { $$ = IMF_INSTRUMENT_SYNTHSTRINGS_2; } |
    CHOIR AAHS { $$ = IMF_INSTRUMENT_CHOIR_AAHS; } |
    VOICE OOHS { $$ = IMF_INSTRUMENT_VOICE_OOHS; } |
    SYNTH VOICE { $$ = IMF_INSTRUMENT_SYNTH_VOICE; } |
    ORCHESTRA HIT { $$ = IMF_INSTRUMENT_ORCHESTRA_HIT; } |
    TRUMPET { $$ = IMF_INSTRUMENT_TRUMPET; } |
    TROMBONE { $$ = IMF_INSTRUMENT_TROMBONE; } |
    TUBA { $$ = IMF_INSTRUMENT_TUBA; } |
    MUTED TRUMPET { $$ = IMF_INSTRUMENT_MUTED_TRUMPET; } |
    FRENCH HORN { $$ = IMF_INSTRUMENT_FRENCH_HORN; } |
    BRASS SECTION { $$ = IMF_INSTRUMENT_BRASS_SECTION; } |
    SYNTHBRASS "1" { $$ = IMF_INSTRUMENT_SYNTHBRASS_1; } |
    SYNTHBRASS "2" { $$ = IMF_INSTRUMENT_SYNTHBRASS_2; } |
    SOPRANO SAX { $$ = IMF_INSTRUMENT_SOPRANO_SAX; } |
    ALTO SAX { $$ = IMF_INSTRUMENT_ALTO_SAX; } |
    TENOR SAX { $$ = IMF_INSTRUMENT_TENOR_SAX; } |
    BARITONE SAX { $$ = IMF_INSTRUMENT_BARITONE_SAX; } |
    OBOE { $$ = IMF_INSTRUMENT_OBOE; } |
    ENGLISH HORN { $$ = IMF_INSTRUMENT_ENGLISH_HORN; } |
    BASSOON { $$ = IMF_INSTRUMENT_BASSOON; } |
    CLARINET { $$ = IMF_INSTRUMENT_CLARINET; } |
    PICCOLO { $$ = IMF_INSTRUMENT_PICCOLO; } |
    FLUTE { $$ = IMF_INSTRUMENT_FLUTE; } |
    RECORDER { $$ = IMF_INSTRUMENT_RECORDER; } |
    PAN FLUTE { $$ = IMF_INSTRUMENT_PAN_FLUTE; } |
    BLOWN BOTTLE { $$ = IMF_INSTRUMENT_BLOWN_BOTTLE; } |
    SHAKUHACHI { $$ = IMF_INSTRUMENT_SHAKUHACHI; } |
    WHISTLE { $$ = IMF_INSTRUMENT_WHISTLE; } |
    OCARINA { $$ = IMF_INSTRUMENT_OCARINA; } |
    LEAD "1" SQUARE { $$ = IMF_INSTRUMENT_LEAD_1_SQUARE; } |
    LEAD "2" SAWTOOTH { $$ = IMF_INSTRUMENT_LEAD_2_SAWTOOTH; } |
    LEAD "3" CALLIOPE { $$ = IMF_INSTRUMENT_LEAD_3_CALLIOPE; } |
    LEAD "4" CHIFF { $$ = IMF_INSTRUMENT_LEAD_4_CHIFF; } |
    LEAD "5" CHARANG { $$ = IMF_INSTRUMENT_LEAD_5_CHARANG; } |
    LEAD "6" VOICE { $$ = IMF_INSTRUMENT_LEAD_6_VOICE; } |
    LEAD "7" FIFTHS { $$ = IMF_INSTRUMENT_LEAD_7_FIFTHS; } |
    LEAD "8" BASS LEAD { $$ = IMF_INSTRUMENT_LEAD_8_BASS_LEAD; } |
    PAD "1" NEW AGE { $$ = IMF_INSTRUMENT_PAD_1_NEW_AGE; } |
    PAD "2" WARM { $$ = IMF_INSTRUMENT_PAD_2_WARM; } |
    PAD "3" POLYSYNTH { $$ = IMF_INSTRUMENT_PAD_3_POLYSYNTH; } |
    PAD "4" CHOIR { $$ = IMF_INSTRUMENT_PAD_4_CHOIR; } |
    PAD "5" BOWED { $$ = IMF_INSTRUMENT_PAD_5_BOWED; } |
    PAD "6" METALLIC { $$ = IMF_INSTRUMENT_PAD_6_METALLIC; } |
    PAD "7" HALO { $$ = IMF_INSTRUMENT_PAD_7_HALO; } |
    PAD "8" SWEEP { $$ = IMF_INSTRUMENT_PAD_8_SWEEP; } |
    FX "1" RAIN { $$ = IMF_INSTRUMENT_FX_1_RAIN; } |
    FX "2" SOUNDTRACK { $$ = IMF_INSTRUMENT_FX_2_SOUNDTRACK; } |
    FX "3" CRYSTAL { $$ = IMF_INSTRUMENT_FX_3_CRYSTAL; } |
    FX "4" ATMOSPHERE { $$ = IMF_INSTRUMENT_FX_4_ATMOSPHERE; } |
    FX "5" BRIGHTNESS { $$ = IMF_INSTRUMENT_FX_5_BRIGHTNESS; } |
    FX "6" GOBLINS { $$ = IMF_INSTRUMENT_FX_6_GOBLINS; } |
    FX "7" ECHOES { $$ = IMF_INSTRUMENT_FX_7_ECHOES; } |
    FX "8" SCI FI { $$ = IMF_INSTRUMENT_FX_8_SCI_FI; } |
    SITAR { $$ = IMF_INSTRUMENT_SITAR; } |
    BANJO { $$ = IMF_INSTRUMENT_BANJO; } |
    SHAMISEN { $$ = IMF_INSTRUMENT_SHAMISEN; } |
    KOTO { $$ = IMF_INSTRUMENT_KOTO; } |
    KALIMBA { $$ = IMF_INSTRUMENT_KALIMBA; } |
    BAG PIPE { $$ = IMF_INSTRUMENT_BAG_PIPE; } |
    FIDDLE { $$ = IMF_INSTRUMENT_FIDDLE; } |
    SHANAI { $$ = IMF_INSTRUMENT_SHANAI; } |
    TINKLE BELL { $$ = IMF_INSTRUMENT_TINKLE_BELL; } |
    AGOGO { $$ = IMF_INSTRUMENT_AGOGO; } |
    STEEL DRUMS { $$ = IMF_INSTRUMENT_STEEL_DRUMS; } |
    WOODBLOCK { $$ = IMF_INSTRUMENT_WOODBLOCK; } |
    TAIKO DRUM { $$ = IMF_INSTRUMENT_TAIKO_DRUM; } |
    MELODIC TOM { $$ = IMF_INSTRUMENT_MELODIC_TOM; } |
    SYNTH DRUM { $$ = IMF_INSTRUMENT_SYNTH_DRUM; } |
    REVERSE CYMBAL { $$ = IMF_INSTRUMENT_REVERSE_CYMBAL; } |
    GUITAR FRET NOISE { $$ = IMF_INSTRUMENT_GUITAR_FRET_NOISE; } |
    BREATH NOISE { $$ = IMF_INSTRUMENT_BREATH_NOISE; } |
    SEASHORE { $$ = IMF_INSTRUMENT_SEASHORE; } |
    BIRD TWEET { $$ = IMF_INSTRUMENT_BIRD_TWEET; } |
    TELEPHONE RING { $$ = IMF_INSTRUMENT_TELEPHONE_RING; } |
    HELICOPTER { $$ = IMF_INSTRUMENT_HELICOPTER; } |
    APPLAUSE { $$ = IMF_INSTRUMENT_APPLAUSE; } |
    GUNSHOT { $$ = IMF_INSTRUMENT_GUNSHOT; };

frame : FRAME | TILE;

ticks :
    TICK | TICKS;

note :
    C {
        $$ = 0;
    }
    |
    D {
        $$ = 2;
    }
    |
    E {
        $$ = 4;
    }
    |
    F {
        $$ = 5;
    }
    |
    G {
        $$ = 7;
    }
    |
    A {
        $$ = 9;
    }
    |
    B {
        $$ = 11;
    }
    ;

octave :
    Integer {
        $$ = $1;
    };

const_note :
    note {
        $$ = $1 + ( 4 * 12 );
    }
    |
    note octave {
        $$ = $1 + ( $2 * 12 );
    }
    |
    note OP_HASH octave {
        $$ = ( $1 + 1 ) + ( $3 * 12 );
    }
    ;

const_expr_floating :
    Float {
        $$ = $1;
    }
    | IF OP const_expr OP_COMMA const_expr_floating OP_COMMA const_expr_floating CP {
        if ( $3 ) {
            $$ = $5;
        } else {
            $$ = $7;
        }
      };

const_expr_string_const:
    Z OP const_expr CP {

        Constant * c3 = malloc( sizeof( Constant ) );
        memset( c3, 0, sizeof( Constant ) );
        c3->name = malloc( MAX_TEMPORARY_STORAGE );
        memset( c3->name, 0, MAX_TEMPORARY_STORAGE );
        sprintf( c3->name, "tempconst%d", UNIQUE_ID );
        c3->realName = strdup( c3->name );

        c3->valueString = malloc( sizeof( StaticString ) );
        memset( c3->valueString, 0, sizeof( StaticString ) );

        c3->valueString->id = UNIQUE_ID;
        c3->valueString->value = malloc( $3 );
        memset( c3->valueString->value, 0, $3 );
        c3->valueString->size = $3;
        c3->valueString->next = ((Environment *)_environment)->strings;
        ((Environment *)_environment)->strings = c3->valueString;

        c3->type = CT_STRING;
        Constant * constLast = ((Environment *)_environment)->constants;
        if ( constLast ) {
            while( constLast->next ) {
                constLast = constLast->next;
            }
            constLast->next = c3;
        } else {
            ((Environment *)_environment)->constants = c3;
        }

        $$ = c3->name;

    }
    | String {
        int size;
        char * buffer = parse_buffer( _environment, $1, &size, 0 );

        Constant * c3 = malloc( sizeof( Constant ) );
        memset( c3, 0, sizeof( Constant ) );
        c3->name = malloc( MAX_TEMPORARY_STORAGE );
        memset( c3->name, 0, MAX_TEMPORARY_STORAGE );
        sprintf( c3->name, "tempconst%d", UNIQUE_ID );
        c3->realName = strdup( c3->name );

        c3->valueString = malloc( sizeof( StaticString ) );
        memset( c3->valueString, 0, sizeof( StaticString ) );

        c3->valueString->id = UNIQUE_ID;
        c3->valueString->value = buffer;
        c3->valueString->size = size;
        c3->valueString->next = ((Environment *)_environment)->strings;
        ((Environment *)_environment)->strings = c3->valueString;

        c3->type = CT_STRING;
        Constant * constLast = ((Environment *)_environment)->constants;
        if ( constLast ) {
            while( constLast->next ) {
                constLast = constLast->next;
            }
            constLast->next = c3;
        } else {
            ((Environment *)_environment)->constants = c3;
        }

        $$ = c3->name;

    } 
    | Identifier {

        Constant * c1 = constant_find( ((Environment *)_environment)->constants, $1 );
        if ( c1 == NULL ) {
            CRITICAL_UNDEFINED_CONSTANT( $1 );
        }
        if ( c1->type != CT_STRING ) {
            CRITICAL_TYPE_MISMATCH_CONSTANT_STRING( $1 );
        }

        Constant * c3 = malloc( sizeof( Constant ) );
        memset( c3, 0, sizeof( Constant ) );
        c3->name = malloc( MAX_TEMPORARY_STORAGE );
        memset( c3->name, 0, MAX_TEMPORARY_STORAGE );
        sprintf( c3->name, "tempconst%d", UNIQUE_ID );
        c3->realName = strdup( c3->name );

        c3->valueString = malloc( sizeof( StaticString ) );
        memset( c3->valueString, 0, sizeof( StaticString ) );

        c3->valueString->id = UNIQUE_ID;
        c3->valueString->value = malloc( c1->valueString->size );
        memcpy( c3->valueString->value, c1->valueString->value, c1->valueString->size );
        c3->valueString->size = c1->valueString->size;
        c3->valueString->next = ((Environment *)_environment)->strings;
        ((Environment *)_environment)->strings = c3->valueString;

        c3->type = CT_STRING;
        Constant * constLast = ((Environment *)_environment)->constants;
        if ( constLast ) {
            while( constLast->next ) {
                constLast = constLast->next;
            }
            constLast->next = c3;
        } else {
            ((Environment *)_environment)->constants = c3;
        }

        $$ = c3->name;

    }
    | Identifier OP_PLUS const_expr_string_const {

        Constant * c1 = constant_find( ((Environment *)_environment)->constants, $1 );
        Constant * c2 = constant_find( ((Environment *)_environment)->constants, $3 );

        if ( c1 == NULL ) {
            CRITICAL_UNDEFINED_CONSTANT( $1 );
        }
        if ( c1->type != CT_STRING ) {
            CRITICAL_TYPE_MISMATCH_CONSTANT_STRING( $1 );
        }

        Constant * c3 = malloc( sizeof( Constant ) );
        memset( c3, 0, sizeof( Constant ) );
        c3->name = malloc( MAX_TEMPORARY_STORAGE );
        memset( c3->name, 0, MAX_TEMPORARY_STORAGE );
        sprintf( c3->name, "tempconst%d", UNIQUE_ID );
        c3->realName = strdup( c3->name );

        c3->valueString = malloc( sizeof( StaticString ) );
        memset( c3->valueString, 0, sizeof( StaticString ) );

        c3->valueString->id = UNIQUE_ID;
        c3->valueString->value = malloc( c1->valueString->size + c2->valueString->size );
        memcpy( c3->valueString->value, c1->valueString->value, c1->valueString->size );
        memcpy( c3->valueString->value+c1->valueString->size, c2->valueString->value, c2->valueString->size );
        c3->valueString->size = c1->valueString->size + c2->valueString->size;
        c3->valueString->next = ((Environment *)_environment)->strings;
        ((Environment *)_environment)->strings = c3->valueString;

        c3->type = CT_STRING;
        Constant * constLast = ((Environment *)_environment)->constants;
        if ( constLast ) {
            while( constLast->next ) {
                constLast = constLast->next;
            }
            constLast->next = c3;
        } else {
            ((Environment *)_environment)->constants = c3;
        }

        $$ = c3->name;

    }
    | String OP_PLUS const_expr_string_const {

        int size;
        char * buffer = parse_buffer( _environment, $1, &size, 0 );

        Constant * c1 = malloc( sizeof( Constant ) );
        memset( c1, 0, sizeof( Constant ) );
        c1->name = malloc( MAX_TEMPORARY_STORAGE );
        memset( c1->name, 0, MAX_TEMPORARY_STORAGE );
        sprintf( c1->name, "tempconst%d", UNIQUE_ID );
        c1->realName = strdup( c1->name );

        c1->valueString = malloc( sizeof( StaticString ) );
        memset( c1->valueString, 0, sizeof( StaticString ) );

        c1->valueString->id = UNIQUE_ID;
        c1->valueString->value = buffer;
        c1->valueString->size = size;
        c1->valueString->next = ((Environment *)_environment)->strings;
        ((Environment *)_environment)->strings = c1->valueString;

        c1->type = CT_STRING;
        Constant * constLast = ((Environment *)_environment)->constants;
        if ( constLast ) {
            while( constLast->next ) {
                constLast = constLast->next;
            }
            constLast->next = c1;
        } else {
            ((Environment *)_environment)->constants = c1;
        }

        Constant * c2 = constant_find( ((Environment *)_environment)->constants, $3 );

        Constant * c3 = malloc( sizeof( Constant ) );
        memset( c3, 0, sizeof( Constant ) );
        c3->name = malloc( MAX_TEMPORARY_STORAGE );
        memset( c3->name, 0, MAX_TEMPORARY_STORAGE );
        sprintf( c3->name, "tempconst%d", UNIQUE_ID );
        c3->realName = strdup( c3->name );

        c3->valueString = malloc( sizeof( StaticString ) );
        memset( c3->valueString, 0, sizeof( StaticString ) );

        c3->valueString->id = UNIQUE_ID;
        c3->valueString->value = malloc( c1->valueString->size + c2->valueString->size );
        memcpy( c3->valueString->value, c1->valueString->value, c1->valueString->size );
        memcpy( c3->valueString->value+c1->valueString->size, c2->valueString->value, c2->valueString->size );
        c3->valueString->size = c1->valueString->size + c2->valueString->size;
        c3->valueString->next = ((Environment *)_environment)->strings;
        ((Environment *)_environment)->strings = c3->valueString;

        c3->type = CT_STRING;
        constLast = ((Environment *)_environment)->constants;
        if ( constLast ) {
            while( constLast->next ) {
                constLast = constLast->next;
            }
            constLast->next = c3;
        } else {
            ((Environment *)_environment)->constants = c3;
        }

        $$ = c3->name;

    }    
    | Z OP const_expr CP OP_PLUS const_expr_string_const {

        Constant * c1 = malloc( sizeof( Constant ) );
        memset( c1, 0, sizeof( Constant ) );
        c1->name = malloc( MAX_TEMPORARY_STORAGE );
        memset( c1->name, 0, MAX_TEMPORARY_STORAGE );
        sprintf( c1->name, "tempconst%d", UNIQUE_ID );
        c1->realName = strdup( c1->name );

        c1->valueString = malloc( sizeof( StaticString ) );
        memset( c1->valueString, 0, sizeof( StaticString ) );

        c1->valueString->id = UNIQUE_ID;
        c1->valueString->value = malloc( $3 );
        memset( c1->valueString->value, 0, $3 );
        c1->valueString->size = $3;
        c1->valueString->next = ((Environment *)_environment)->strings;
        ((Environment *)_environment)->strings = c1->valueString;

        c1->type = CT_STRING;
        Constant * constLast = ((Environment *)_environment)->constants;
        if ( constLast ) {
            while( constLast->next ) {
                constLast = constLast->next;
            }
            constLast->next = c1;
        } else {
            ((Environment *)_environment)->constants = c1;
        }

        Constant * c2 = constant_find( ((Environment *)_environment)->constants, $6 );

        Constant * c3 = malloc( sizeof( Constant ) );
        memset( c3, 0, sizeof( Constant ) );
        c3->name = malloc( MAX_TEMPORARY_STORAGE );
        memset( c3->name, 0, MAX_TEMPORARY_STORAGE );
        sprintf( c3->name, "tempconst%d", UNIQUE_ID );
        c3->realName = strdup( c3->name );

        c3->valueString = malloc( sizeof( StaticString ) );
        memset( c3->valueString, 0, sizeof( StaticString ) );

        c3->valueString->id = UNIQUE_ID;
        c3->valueString->value = malloc( c1->valueString->size + c2->valueString->size );
        memcpy( c3->valueString->value, c1->valueString->value, c1->valueString->size );
        memcpy( c3->valueString->value+c1->valueString->size, c2->valueString->value, c2->valueString->size );
        c3->valueString->size = c1->valueString->size + c2->valueString->size;
        c3->valueString->next = ((Environment *)_environment)->strings;
        ((Environment *)_environment)->strings = c3->valueString;

        c3->type = CT_STRING;
        constLast = ((Environment *)_environment)->constants;
        if ( constLast ) {
            while( constLast->next ) {
                constLast = constLast->next;
            }
            constLast->next = c3;
        } else {
            ((Environment *)_environment)->constants = c3;
        }

        $$ = c3->name;

    }    
    ;

const_expr_string :
    String {
        $$ = $1;
    }
    | RawString {
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
    | const_expr_math XOR const_expr_math {
        $$ = $1 ? !$3 : $3;
    } 
    | NOT const_expr {
        $$ = ( ! $2 );
    }
    ;

const_expr_math : 
      const_expr_math2
    | const_expr_math2 OP_EQUAL const_expr_math2 {
        $$ = ( $1 == $3 );
    }
    | const_expr_math2 OP_ASSIGN const_expr_math2 {
        $$ = ( $1 == $3 );
    }
    | const_expr_math2 OP_DISEQUAL const_expr_math2 {
        $$ = ( $1 != $3 );
    }
    | const_expr_math2 OP_LT const_expr_math2 {
        $$ = ( $1 < $3 );
    }
    | const_expr_math2 OP_LTE const_expr_math2 {
        $$ = ( $1 <= $3 );
    }
    | const_expr_math2 OP_GT const_expr_math2 {
        $$ = ( $1 > $3 );
    }
    | const_expr_math2 OP_GTE const_expr_math2 {
        $$ = ( $1 >= $3 );
    }
    ;

const_expr_math2: 
      const_term
    | const_expr_math2 OP_PLUS const_term {
        $$ = $1 + $3;
    }
    | const_expr_math2 OP_MINUS const_term {
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
      | DARK RED {
          $$ = COLOR_DARK_RED;
      }
      | LIGHT RED {
          $$ = COLOR_LIGHT_RED;
      }
      | DARK WHITE {
          $$ = COLOR_DARK_WHITE;
      }
      | LIGHT WHITE {
          $$ = COLOR_LIGHT_WHITE;
      }
      | DARK GREY {
          $$ = COLOR_DARK_GREY;
      }
      | GREY {
          $$ = COLOR_GREY;
      }
      | DARK GREEN {
          $$ = COLOR_DARK_GREEN;
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
      | SCREEN WIDTH {
          $$ = ((Environment *)_environment)->screenWidth;
      }
      | PAGE "0" {
          $$ = DOUBLE_BUFFER_PAGE_0;
      }
      | PAGE "1" {
          $$ = DOUBLE_BUFFER_PAGE_1;
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
          Variable * v = variable_retrieve( _environment, $4 );
          if ( v->type == VT_IMAGES && v->originalTileset != NULL ) {
              $$ = v->frameWidth;
          } else {
             CRITICAL_TILE_WIDTH_NO_TILESET( $4 );
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
            if ( v->type != VT_IMAGE && v->type != VT_IMAGES && v->type != VT_SEQUENCE ) {
                CRITICAL_NOT_IMAGE( v->name );
            }
            int overallOffset = 0;
            if ( v->type == VT_IMAGES || v->type == VT_SEQUENCE ) {
                overallOffset = 3;
            }
            if ( !v->valueBuffer ) {
                CRITICAL_NOT_ASSIGNED_IMAGE( v->name );
            }
            IMAGE_GET_WIDTH( v->valueBuffer, overallOffset, $$ );
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
            defined( __c64reu__)
            $$ = 1;
        #else
            $$ = 0;
        #endif
      }
      | BIG ENDIAN {
        #if defined(__coco__) || defined(__d32__) || defined(__d64__) || \
            defined(__pc128op__) || defined(__mo5__) || defined(__coco3__) || \
            defined(__to8__)
            $$ = 1;
        #else
            $$ = 0;
        #endif
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
          Variable * v = variable_retrieve( _environment, $4 );
          if ( v->type == VT_IMAGES && v->originalTileset != NULL ) {
              $$ = v->frameHeight;
          } else {
             CRITICAL_TILE_HEIGHT_NO_TILESET( $4 );
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
            if ( v->type != VT_IMAGE && v->type != VT_IMAGES && v->type != VT_SEQUENCE ) {
                CRITICAL_NOT_IMAGE( v->name );
            }
            int overallOffset = 0;
            if ( v->type == VT_IMAGES || v->type == VT_SEQUENCE ) {
                overallOffset = 3;
            }
            if ( !v->valueBuffer ) {
                CRITICAL_NOT_ASSIGNED_IMAGE( v->name );
            }        
            IMAGE_GET_HEIGHT( v->valueBuffer, overallOffset, $$ );
          } else {
            $$ = 0;
          }
      }
      | UBOUND OP Identifier CP {
          Variable * array = variable_retrieve( _environment, $3 );
          if ( array->type != VT_TARRAY ) {
            CRITICAL_NOT_ARRAY( $3 );
          }
          $$ = array->arrayDimensionsEach[array->arrayDimensions-1];
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
        $$ = array->arrayDimensionsEach[array->arrayDimensions-$5-1];
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
          Constant * c = constant_find( ((Environment *)_environment)->constants, $3 );
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
          Constant * c = constant_find( ((Environment *)_environment)->constants, $1 );
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
          Constant * c = constant_find( ((Environment *)_environment)->constants, $2 );
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

expr : 
      expr_math
    | expr_math AND expr {        
        $$ = variable_and( _environment, $1, $3 )->name;
    } 
    | expr_math OR expr {
        $$ = variable_or( _environment, $1, $3 )->name;
    } 
    | expr_math XOR expr {        
        $$ = variable_xor( _environment, $1, $3 )->name;
    } 
    | NOT expr {
        $$ = variable_not( _environment, $2 )->name;
    }
    ;

expr_math : 
      expr_math2
    | expr_math2 OP_EQUAL expr_math {
        Variable * expr = variable_retrieve( _environment, $3 );
        if ( expr->initializedByConstant ) {
            $$ = variable_compare_const( _environment, $1, expr->value )->name;
        } else {
            $$ = variable_compare( _environment, $1, $3 )->name;
        }
    }
    | expr_math2 OP_ASSIGN expr_math {
        Variable * expr = variable_retrieve( _environment, $3 );
        if ( expr->initializedByConstant ) {
            $$ = variable_compare_const( _environment, $1, expr->value )->name;
        } else {
            $$ = variable_compare( _environment, $1, $3 )->name;
        }
    }
    | expr_math2 OP_DISEQUAL expr_math {
        Variable * expr = variable_retrieve( _environment, $3 );
        if ( expr->initializedByConstant ) {
            $$ = variable_compare_not_const( _environment, $1, expr->value )->name;
        } else {
            $$ = variable_compare_not( _environment, $1, $3 )->name;
        }
    }
    | expr_math2 OP_LT expr_math {
        Variable * expr = variable_retrieve( _environment, $3 );
        if ( expr->initializedByConstant ) {
            $$ = variable_less_than_const( _environment, $1, expr->value, 0 )->name;
        } else {
            $$ = variable_less_than( _environment, $1, $3, 0 )->name;
        }
    }
    | expr_math2 OP_LTE expr_math {
        Variable * expr = variable_retrieve( _environment, $3 );
        if ( expr->initializedByConstant ) {
            $$ = variable_less_than_const( _environment, $1, expr->value, 1 )->name;
        } else {
            $$ = variable_less_than( _environment, $1, $3, 1 )->name;
        }
    }
    | expr_math2 OP_LT OP_HASH const_expr_math2 {
        $$ = variable_less_than_const( _environment, $1, $4, 0 )->name;
    }
    | expr_math2 OP_LTE OP_HASH const_expr_math2 {
        $$ = variable_less_than_const( _environment, $1, $4, 1 )->name;
    }
    | expr_math2 OP_GT expr_math {
        Variable * expr = variable_retrieve( _environment, $3 );
        if ( expr->initializedByConstant ) {
            $$ = variable_greater_than_const( _environment, $1, expr->value, 0 )->name;
        } else {
            $$ = variable_greater_than( _environment, $1, $3, 0 )->name;
        }
    }
    | expr_math2 OP_GTE expr_math {
        Variable * expr = variable_retrieve( _environment, $3 );
        if ( expr->initializedByConstant ) {
            $$ = variable_greater_than_const( _environment, $1, expr->value, 1 )->name;
        } else {
            $$ = variable_greater_than( _environment, $1, $3, 1 )->name;
        }
    }
    | expr_math2 OP_GT OP_HASH const_expr_math2 {
        $$ = variable_greater_than_const( _environment, $1, $4, 0 )->name;
    }
    | expr_math2 OP_GTE OP_HASH const_expr_math2 {
        $$ = variable_greater_than_const( _environment, $1, $4, 1 )->name;
    }
    ;

expr_math2: 
      term
    | expr_math2 OP_PLUS term {
        Variable * v = variable_retrieve( _environment, $1 );
        Variable * expr = variable_retrieve( _environment, $3 );
        if ( expr->initializedByConstant && VT_BITWIDTH(v->type)>1 ) {
            $$ = variable_add_const( _environment, $1, expr->value )->name;
        } else {
            $$ = variable_add( _environment, $1, $3 )->name;
        }
    }
    | expr_math2 OP_MINUS term {
        Variable * v = variable_retrieve( _environment, $1 );
        Variable * expr = variable_retrieve( _environment, $3 );
        if ( expr->initializedByConstant && VT_BITWIDTH(v->type)>1 ) {
            $$ = variable_sub_const( _environment, $1, expr->value )->name;
        } else {
            $$ = variable_sub( _environment, $1, $3 )->name;
        }
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
        Variable * modula = variable_retrieve( _environment, $1 );
        Variable * factor = variable_retrieve( _environment, $3 );
        if ( ( modula->type != VT_FLOAT && factor->type != VT_FLOAT ) && factor->initializedByConstant ) {
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
    } 
    | modula OP_MULTIPLICATION2 direct_integer {
        if ( log2($3) != (int)log2($3) ) {
            CRITICAL_INVALID_MULTIPLICATOR2( $3 );
        }
        $$ = variable_mul2_const( _environment, $1, $3 )->name;
    } 
    | modula OP_MULTIPLICATION2 Integer {
        if ( log2($3) != (int)log2($3) ) {
            CRITICAL_INVALID_MULTIPLICATOR2( $3 );
        }
        $$ = variable_mul2_const( _environment, $1, $3 )->name;
    } 
    | modula OP_DIVISION factor {
        $$ = variable_div( _environment, $1, $3, NULL )->name;
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
      | OP_MINUS factor {
        Variable * expr = variable_retrieve( _environment, $2 );
        if ( expr->type == VT_FLOAT ) {
            Variable * zero = variable_temporary( _environment, VT_FLOAT, "(zero)" );
            variable_store_float( _environment, zero->name, 0 );
            $$ = variable_sub( _environment, zero->name, expr->name )->name;
        } else {
            Variable * zero = variable_temporary( _environment, VT_SIGN( expr->type ), "(zero)" );
            variable_store( _environment, zero->name, 0 );
            $$ = variable_sub( _environment, zero->name, expr->name )->name;
        }
      }
      ;

direct_integer:
    OP_HASH Integer {
        $$ = $2;
    }
    |
    OP_HASH OP_MINUS Integer {
        $$ = -$3;
    }
    | OP_HASH Identifier {
        Constant * c = constant_find( ((struct _Environment *)_environment)->constants, $2 );
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
    | COMPRESSED {
        $$ = FLAG_COMPRESSED;
    }
    | OVERLAYED {
        $$ = FLAG_OVERLAYED;
    }
    | EXACT {
        $$ = FLAG_EXACT;
    };

tile_load_flag :
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
    | ROLL Y {
        $$ = FLAG_ROLL_Y;
    }
    | ROLL XY {
        $$ = FLAG_ROLL_Y | FLAG_ROLL_X;
    }
    | ROLL YX {
        $$ = FLAG_ROLL_Y | FLAG_ROLL_X;
    }
    | TRANSPARENT {
        $$ = FLAG_TRANSPARENCY;
    }
    ;

put_image_flag :
    WITH TRANSPARENCY {
        $$ = FLAG_TRANSPARENCY;
    }
    | DOUBLE Y {
        $$ = FLAG_DOUBLE_Y;
    };

blit_image_flag :
    DOUBLE Y {
        $$ = FLAG_DOUBLE_Y;
    };

load_flag :
    COMPRESSED {
        $$ = FLAG_COMPRESSED;
    };

images_or_atlas :
    IMAGES | ATLAS;

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
    | COMPRESSED {
        $$ = FLAG_COMPRESSED;
    }
    | OVERLAYED {
        $$ = FLAG_OVERLAYED;
    }
    | EXACT {
        $$ = FLAG_EXACT;
    }
    | ROLL X {
        $$ = FLAG_ROLL_X;
    }
    | ROLL Y {
        $$ = FLAG_ROLL_Y;
    }
    | ROLL XY {
        $$ = FLAG_ROLL_Y | FLAG_ROLL_X;
    }
    | ROLL YX {
        $$ = FLAG_ROLL_Y | FLAG_ROLL_X;
    };

sequence_load_flag :
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
    | COMPRESSED {
        $$ = FLAG_COMPRESSED;
    }
    | OVERLAYED {
        $$ = FLAG_OVERLAYED;
    }
    | EXACT {
        $$ = FLAG_EXACT;
    };

put_image_flags1 :
    put_image_flag {
        $$ = $1;
    }
    | put_image_flag put_image_flags1 {
        $$ = $1 | $2;
    };

blit_image_flags1 :
    blit_image_flag {
        $$ = $1;
    }
    | blit_image_flag blit_image_flags1 {
        $$ = $1 | $2;
    };

image_load_flags1 :
    image_load_flag {
        $$ = $1;
    }
    | image_load_flag image_load_flags1 {
        $$ = $1 | $2;
    };

load_flags1 :
    load_flag {
        $$ = $1;
    }
    | load_flag load_flags1 {
        $$ = $1 | $2;
    };

tile_load_flags1 :
    tile_load_flag {
        $$ = $1;
    }
    | tile_load_flag tile_load_flags1 {
        $$ = $1 | $2;
    };

images_load_flags1 :
    images_load_flag {
        $$ = $1;
    }
    | images_load_flag images_load_flags1 {
        $$ = $1 | $2;
    };

sequence_load_flags1 :
    sequence_load_flag {
        $$ = $1;
    }
    | sequence_load_flag sequence_load_flags1 {
        $$ = $1 | $2;
    };

using_transparency :
    {
        $$ = 0x00;
    } 
    | TRANSPARENCY {
        $$ = 0x0f0000 | COLOR_BLACK;
    }
    | TRANSPARENCY const_color_enumeration {
        $$ = 0x0f0000 | $2;
    };

using_opacity :
    {
        $$ = 0x00;
    } 
    | OPACITY {
        $$ = 0xf00000 | ( COLOR_BLACK << 8 );
    }
    | OPACITY const_color_enumeration {
        $$ = 0xf00000 | ( $2 << 8 );
    };

using_background :
    {
        $$ = -1;    
    } 
    | BACKGROUND const_color_enumeration {
        $$ = $2;
    };

tile_load_flags :
    {
        $$ = 0;    
    } 
    | tile_load_flags1 {
        $$ = $1;
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

blit_image_flags :
    {
        $$ = 0;    
    } 
    | blit_image_flags1 {
        $$ = $1;
    };

load_flags :
    {
        $$ = 0;    
    } 
    | load_flags1 {
        $$ = $1;
    };

images_load_flags :
    {
        $$ = 0;    
    } 
    | images_load_flags1 {
        $$ = $1;
    };

sequence_load_flags :
    {
        $$ = 0;    
    } 
    | sequence_load_flags1 {
        $$ = $1;
    };

on_bank :
    {
        $$ = 0;
    }
    | BANKED {
        $$ = 1;
    }
    | BANKED OP const_expr CP {
        $$ = $3;
    };

sprite_flag :
    MULTICOLOR {
        $$ = SPRITE_FLAG_MULTICOLOR;
    }
    | MONOCOLOR {
        $$ = SPRITE_FLAG_MONOCOLOR;
    }
    | EXPAND VERTICAL {
        $$ = SPRITE_FLAG_EXPAND_VERTICAL;
    }
    | COMPRESS VERTICAL {
        $$ = SPRITE_FLAG_COMPRESS_VERTICAL;
    }
    | EXPAND HORIZONTAL {
        $$ = SPRITE_FLAG_EXPAND_HORIZONTAL;
    }
    | COMPRESS HORIZONTAL {
        $$ = SPRITE_FLAG_COMPRESS_HORIZONTAL;
    }
    | IGNORE COLOR const_expr {
        $$ = SPRITE_FLAG_TRANSPARENCY_COLOR | ( $3 & 0x000f );
    };

sprite_flags1 :
    sprite_flag {
        $$ = $1;
    }
    | sprite_flag sprite_flags1 {
        $$ = $1 | $2;
    }
    ;

sprite_flags :
    {
        $$ = 0;    
    } 
    | sprite_flags1 {
        $$ = $1;
    };

random_definition_simple:
      BIT {
        $$ = random_value( _environment, VT_BIT )->name;
    }
    | BYTE {
        $$ = random_value( _environment, VT_BYTE )->name;
    }
    | WORD {
        $$ = random_value( _environment, VT_WORD )->name;
    }
    | INT {
        $$ = random_value( _environment, VT_SWORD )->name;
    }
    | INTEGER {
        $$ = random_value( _environment, VT_SWORD )->name;
    }
    | FLOAT {
        $$ = random_value( _environment, VT_FLOAT )->name;
    }
    | DWORD {
        $$ = random_value( _environment, VT_DWORD )->name;
    }
    | LONG {
        $$ = random_value( _environment, VT_SDWORD )->name;
    }
    | POSITION {
        $$ = random_value( _environment, VT_POSITION )->name;
    }
    | COLOR {
        $$ = random_value( _environment, VT_COLOR )->name;
    }
    | COLOUR {
        $$ = random_value( _environment, VT_COLOR )->name;
    }
    | WIDTH {
        $$ = random_width( _environment )->name;
    }
    | HEIGHT {
        $$ = random_height( _environment )->name;
    };

halted:
    {
        $$ = 0;
    } | HALTED {
        $$ = 1;
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
      | DARK WHITE {
          $$ = variable_temporary( _environment, VT_COLOR, "(color DARK WHITE)" )->name;
          variable_store( _environment, $$, COLOR_DARK_WHITE );
      }
      | LIGHT WHITE {
          $$ = variable_temporary( _environment, VT_COLOR, "(color LIGHT WHITE)" )->name;
          variable_store( _environment, $$, COLOR_LIGHT_WHITE );
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
      | DARK RED {
          $$ = variable_temporary( _environment, VT_COLOR, "(color DARK RED)" )->name;
          variable_store( _environment, $$, COLOR_DARK_RED );
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
      | DARK GREEN {
          $$ = variable_temporary( _environment, VT_COLOR, "(color DARK GREEN)" )->name;
          variable_store( _environment, $$, COLOR_DARK_GREEN );
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
    Integer {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 0)")->name;
        switch( $1 ) {
            case 0:
                variable_store( _environment, $$, KEY_0 );
                break;
            case 1:
                variable_store( _environment, $$, KEY_1 );
                break;
            case 2:
                variable_store( _environment, $$, KEY_2 );
                break;
            case 3:
                variable_store( _environment, $$, KEY_3 );
                break;
            case 4:
                variable_store( _environment, $$, KEY_4 );
                break;
            case 5:
                variable_store( _environment, $$, KEY_5 );
                break;
            case 6:
                variable_store( _environment, $$, KEY_6 );
                break;
            case 7:
                variable_store( _environment, $$, KEY_7 );
                break;
            case 8:
                variable_store( _environment, $$, KEY_8 );
                break;
            case 9:
                variable_store( _environment, $$, KEY_9 );
                break;
        }
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

const_key_scancode_alphadigit :
      "0" {
        $$ = KEY_0;
    }
    | "1" {
        $$ = KEY_1;
    }
    | "2" {
        $$ = KEY_2;
    }
    | "3" {
        $$ = KEY_3;
    }
    | "4" {
        $$ = KEY_4;
    }
    | "5" {
        $$ = KEY_5;
    }
    | "6" {
        $$ = KEY_6;
    }
    | "7" {
        $$ = KEY_7;
    }
    | "8" {
        $$ = KEY_8;
    }
    | "9" {
        $$ = KEY_9;
    }
    | A {
        $$ = KEY_A;
    }
    | B {
        $$ = KEY_B;
    }
    | C {
        $$ = KEY_C;
    }
    | D {
        $$ = KEY_D;
    }
    | E {
        $$ = KEY_E;
    }
    | F {
        $$ = KEY_F;
    }
    | G {
        $$ = KEY_G;
    }
    | H {
        $$ = KEY_H;
    }
    | I {
        $$ = KEY_I;
    }
    | J {
        $$ = KEY_J;
    }
    | K {
        $$ = KEY_K;
    }
    | L {
        $$ = KEY_L;
    }
    | M {
        $$ = KEY_M;
    }
    | N {
        $$ = KEY_N;
    }
    | O {
        $$ = KEY_O;
    }
    | P {
        $$ = KEY_P;
    }
    | Q {
        $$ = KEY_Q;
    }
    | R {
        $$ = KEY_R;
    }
    | S {
        $$ = KEY_S;
    }
    | T {
        $$ = KEY_T;
    }
    | U {
        $$ = KEY_U;
    }
    | V {
        $$ = KEY_V;
    }
    | X {
        $$ = KEY_X;
    }
    | Y {
        $$ = KEY_Y;
    }
    | W {
        $$ = KEY_W;
    }
    | Z {
        $$ = KEY_Z;
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

const_key_scancode_function_digit :
      F1 {
        $$ = KEY_F1;
    }
    | F2 {
        $$ = KEY_F2;
    }
    | F3 {
        $$ = KEY_F3;
    }
    | F4 {
        $$ = KEY_F4;
    }
    | F5 {
        $$ = KEY_F5;
    }
    | F6 {
        $$ = KEY_F6;
    }
    | F7 {
        $$ = KEY_F7;
    }
    | F8 {
        $$ = KEY_F8;
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
    | LEFT {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode LEFT)")->name;
        variable_store( _environment, $$, KEY_LEFT );
    }
    | RIGHT {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode RIGHT)")->name;
        variable_store( _environment, $$, KEY_RIGHT );
    }
    | UP {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode UP)")->name;
        variable_store( _environment, $$, KEY_UP );
    }
    | DOWN {
        $$ = variable_temporary( _environment, VT_BYTE, "(scancode DOWN)")->name;
        variable_store( _environment, $$, KEY_DOWN );
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

const_key_scancode_definition : 
      NONE {
        $$ = KEY_NONE;
    }
    | const_key_scancode_alphadigit {
        $$ = $1;
    }
    | ASTERISK {
        $$ = KEY_ASTERISK;
    }
    | AT {
        $$ = KEY_AT;
    }
    | CLEAR {
        $$ = KEY_CLEAR;
    }
    | COLON {
        $$ = KEY_COLON;
    }
    | COMMA {
        $$ = KEY_COMMA;
    }
    | COMMODORE {
        $$ = KEY_COMMODORE;
    }
    | CONTROL {
        $$ = KEY_CONTROL;
    }
    | CRSR LEFT RIGHT {
        $$ = KEY_CRSR_LEFT_RIGHT;
    }
    | CRSR UP DOWN {
        $$ = KEY_CRSR_UP_DOWN;
    }
    | DELETE {
        $$ = KEY_DELETE;
    }
    | EQUAL {
        $$ = KEY_EQUAL;
    }
    | const_key_scancode_function_digit {
        $$ = $1;
    }
    | HOME {
        $$ = KEY_HOME;
    }
    | INSERT {
        $$ = KEY_INSERT;
    }
    | ARROW LEFT {
        $$ = KEY_LEFT_ARROW;
    }
    | LEFT ARROW {
        $$ = KEY_LEFT_ARROW;
    }
    | LEFT {
        $$ = KEY_LEFT;
    }
    | RIGHT {
        $$ = KEY_RIGHT;
    }
    | UP {
        $$ = KEY_UP;
    }
    | DOWN {
        $$ = KEY_DOWN;
    }
    | ARROW UP {
        $$ = KEY_UP_ARROW;
    }
    | UP ARROW {
        $$ = KEY_UP_ARROW;
    }
    | MINUS {
        $$ = KEY_MINUS;
    }
    | PERIOD {
        $$ = KEY_PERIOD;
    }
    | PLUS {
        $$ = KEY_PLUS;
    }
    | POUND {
        $$ = KEY_POUND;
    }
    | RETURN {
        $$ = KEY_RETURN;
    }
    | RUNSTOP {
        $$ = KEY_RUNSTOP;        
    }
    | RUN STOP {
        $$ = KEY_RUNSTOP;        
    }
    | SEMICOLON {
        $$ = KEY_SEMICOLON;
    }
    | SLASH {
        $$ = KEY_SLASH;        
    }
    | SPACE {
        $$ = KEY_SPACE;        
    };

load_image  : LOAD IMAGE | IMAGE LOAD;
load_images : LOAD images_or_atlas | images_or_atlas LOAD;
load_sequence : LOAD SEQUENCE | SEQUENCE LOAD;
load_tileset  : LOAD TILESET | TILESET LOAD;
load_tilemap  : LOAD TILEMAP | TILEMAP LOAD;

frame_offset : 
    OFFSET OP const_expr OP_COMMA const_expr CP {
        ((struct _Environment *)_environment)->frameOffsetX = $3;
        ((struct _Environment *)_environment)->frameOffsetY = $5;
    }
    |
    {
        ((struct _Environment *)_environment)->frameOffsetX = 0;
        ((struct _Environment *)_environment)->frameOffsetY = 0;
    }
    ;

frame_origin : 
    ORIGIN OP const_expr OP_COMMA const_expr CP {
        ((struct _Environment *)_environment)->frameOriginX = $3;
        ((struct _Environment *)_environment)->frameOriginY = $5;
    }
    |
    {
        ((struct _Environment *)_environment)->frameOriginX = 0;
        ((struct _Environment *)_environment)->frameOriginY = 0;
    }
    ;

frame_size_explicit :
    FRAME SIZE OP const_expr OP_COMMA const_expr CP frame_offset frame_origin {
        ((struct _Environment *)_environment)->frameWidth = $4;
        ((struct _Environment *)_environment)->frameHeight = $6;
    };

frame_size_auto : 
    FRAME SIZE AUTO {
        ((struct _Environment *)_environment)->frameWidth = -1;
        ((struct _Environment *)_environment)->frameHeight = -1;
    };

frame_size_definition :
      frame_size_auto 
    | frame_size_explicit;

frame_size : {
        ((struct _Environment *)_environment)->frameOffsetX = 0;
        ((struct _Environment *)_environment)->frameOffsetY = 0;
        ((struct _Environment *)_environment)->frameOriginX = 0;
        ((struct _Environment *)_environment)->frameOriginY = 0;
    } frame_size_definition;

exponential:
    Identifier as_datatype_suffix_optional {
        parser_array_init( _environment );
    }
      OP indexes CP {
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
        parser_array_cleanup( _environment );
    }
    | OSP Identifier as_datatype_suffix_optional CSP {
        if ( !((struct _Environment *)_environment)->procedureName ) {
            CRITICAL_CANNOT_USE_MULTITASKED_ARRAY($2);
        }
        parser_array_init( _environment );
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
        $$ = variable_move_from_array( _environment, $2 )->name;
        parser_array_cleanup( _environment );
    }
    | Identifier {
        Constant * c = constant_find( ((struct _Environment *)_environment)->constants, $1 );
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
                if ( ((struct _Environment *)_environment)->optionExplicit ) {
                    CRITICAL_VARIABLE_UNDEFINED( $1 );
                } else {
                    $$ = variable_retrieve_or_define( _environment, $1, ((struct _Environment *)_environment)->defaultVariableType, 0 )->name;
                }
            } else {
                $$ = variable_retrieve( _environment, $1 )->name;
            }
        }
    }
    | Identifier as_datatype_suffix {
        Constant * c = constant_find( ((struct _Environment *)_environment)->constants, $1 );
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
    }
    | Integer { 
        $$ = parser_adapted_numeric( _environment, $1 )->name;
      }
    | Float { 
        $$ = variable_temporary( _environment, VT_FLOAT, "(float))" )->name;
        variable_store_float( _environment, $$, $1 );
    }
    | String { 
        $$ = variable_temporary( _environment, VT_STRING, "(string value)" )->name;
        variable_store_string( _environment, $$, $1 );
      }
    | RawString { 
        Variable * variable = variable_temporary( _environment, VT_STRING, "(string value)" );
        variable_store_string( _environment, variable->name, $1 );
        variable->printable = 1;
        $$ = variable->name;
      }
    | OP BIT CP Integer { 
        $$ = variable_temporary( _environment, VT_BIT, "(BIT value)" )->name;
        variable_store( _environment, $$, $4 );
      }
    | OP BYTE CP Integer { 
        $$ = parser_casted_numeric( _environment, VT_BYTE, $4 )->name;
      }
    | OP BYTE CP direct_integer { 
        $$ = parser_casted_numeric( _environment, VT_BYTE, $4 )->name;
      }
    | OP BYTE CP Float { 
        $$ = parser_casted_numeric( _environment, VT_BYTE, (int)$4 )->name;
      }
    | OP BYTE CP OP expr CP { 
        $$ = variable_cast( _environment, $5, VT_BYTE )->name;
      }
    | OP SIGNED BYTE CP Integer { 
        $$ = parser_casted_numeric( _environment, VT_SBYTE, $5 )->name;
      }
    | OP SIGNED BYTE CP Float { 
        $$ = parser_casted_numeric( _environment, VT_SBYTE, (int)$5 )->name;
      }
    | OP SIGNED BYTE CP direct_integer { 
        $$ = parser_casted_numeric( _environment, VT_SBYTE, $5 )->name;
      }
    | OP SIGNED BYTE CP OP expr CP { 
        $$ = variable_cast( _environment, $6, VT_SBYTE )->name;
      }
    | OP WORD CP Integer { 
        $$ = parser_casted_numeric( _environment, VT_WORD, $4 )->name;
      }
    | OP WORD CP Float { 
        $$ = parser_casted_numeric( _environment, VT_WORD, (int)$4 )->name;
      }
    | OP WORD CP direct_integer { 
        $$ = parser_casted_numeric( _environment, VT_WORD, $4 )->name;
      }
    | OP WORD CP OP expr CP { 
        $$ = variable_cast( _environment, $5, VT_WORD )->name;
      }
    | OP SIGNED WORD CP Integer { 
        $$ = parser_casted_numeric( _environment, VT_SWORD, $5 )->name;
    }
    | OP SIGNED WORD CP Float { 
        $$ = parser_casted_numeric( _environment, VT_SWORD, (int)$5 )->name;
    }
    | OP SIGNED WORD CP direct_integer { 
        $$ = parser_casted_numeric( _environment, VT_SWORD, $5 )->name;
      }
    | OP SIGNED WORD CP OP expr CP { 
        $$ = variable_cast( _environment, $6, VT_SWORD )->name;
      }
    | OP FLOAT CP OP expr CP { 
        $$ = variable_cast( _environment, $5, VT_FLOAT )->name;
      }
    | OP DWORD CP Integer { 
        $$ = parser_casted_numeric( _environment, VT_DWORD, $4 )->name;
      }
    | OP DWORD CP Float { 
        $$ = parser_casted_numeric( _environment, VT_DWORD, (int)$4 )->name;
      }
    | OP DWORD CP direct_integer { 
        $$ = parser_casted_numeric( _environment, VT_DWORD, $4 )->name;
      }
    | OP DWORD CP OP expr CP { 
        $$ = variable_cast( _environment, $5, VT_DWORD )->name;
      }
    | OP SIGNED DWORD CP Integer { 
        $$ = parser_casted_numeric( _environment, VT_SDWORD, $5 )->name;
      }
    | OP SIGNED DWORD CP Float { 
        $$ = parser_casted_numeric( _environment, VT_SDWORD, (int)$5 )->name;
      }
    | OP SIGNED DWORD CP direct_integer { 
        $$ = parser_casted_numeric( _environment, VT_SDWORD, $5 )->name;
      }
    | OP FLOAT CP Float { 
        $$ = variable_temporary( _environment, VT_FLOAT, "(float)" )->name;
        variable_store_float( _environment, $$, $4 );
    }
    | OP SIGNED DWORD CP OP expr CP { 
        $$ = variable_cast( _environment, $6, VT_SDWORD )->name;
      }
    | OP POSITION CP Integer { 
        $$ = parser_casted_numeric( _environment, VT_POSITION, $4 )->name;
      }
    | OP POSITION CP Float { 
        $$ = parser_casted_numeric( _environment, VT_POSITION, (int)$4 )->name;
      }
    | OP POSITION CP direct_integer { 
        $$ = parser_casted_numeric( _environment, VT_POSITION, $4 )->name;
      }
    | OP POSITION CP OP expr CP { 
        $$ = variable_cast( _environment, $5, VT_POSITION )->name;
      }
    | OP COLOR CP Integer { 
        $$ = parser_casted_numeric( _environment, VT_COLOR, $4 )->name;
      }
    | OP COLOR CP Float { 
        $$ = parser_casted_numeric( _environment, VT_COLOR, (int)$4 )->name;
      }
    | OP COLOR CP direct_integer { 
        $$ = parser_casted_numeric( _environment, VT_COLOR, $4 )->name;
      }
    | OP COLOR CP OP expr CP { 
        $$ = variable_cast( _environment, $5, VT_COLOR )->name;
      }
    | OP COLOUR CP Integer { 
        $$ = parser_casted_numeric( _environment, VT_COLOR, $4 )->name;
      }
    | OP COLOUR CP Float { 
        $$ = parser_casted_numeric( _environment, VT_COLOR, (int)$4 )->name;
      }
    | OP COLOUR CP direct_integer { 
        $$ = parser_casted_numeric( _environment, VT_COLOR, $4 )->name;
      }
    | OP COLOUR CP OP expr CP { 
        $$ = variable_cast( _environment, $5, VT_COLOR )->name;
      }
    | OP STRING CP Identifier { 
        $$ = variable_cast( _environment, $4, VT_DSTRING )->name;        
      }
    | BufferDefinitionHex { 
        $$ = parse_buffer_definition( _environment, $1, VT_BUFFER, 1 )->name;
      }
    | OP IMAGE CP BufferDefinitionHex { 
        int size;
        char * buffer = parse_buffer( _environment, $4, &size, 1 );
        $$ = image_load_from_buffer( _environment, buffer, size )->name;
      }      
    | OP IMAGE CP RawString { 
        int size;
        char * buffer = parse_buffer( _environment, $4, &size, 0 );
        $$ = image_load_from_buffer( _environment, buffer, size )->name;
      }      
    | OP IMAGE CP Identifier { 
        Constant * c = constant_find( ((Environment *)_environment)->constants, $4 );
        if ( c == NULL ) {
            CRITICAL_UNDEFINED_CONSTANT( $4 );
        }
        if ( c->type != CT_STRING ) {
            CRITICAL_TYPE_MISMATCH_CONSTANT_STRING( $4 );
        }
        $$ = image_load_from_buffer( _environment, c->valueString->value, c->valueString->size )->name;
      }      
    | OP images_or_atlas CP BufferDefinitionHex { 
        int size;
        char * buffer = parse_buffer( _environment, $4, &size, 1 );
        $$ = images_load_from_buffer( _environment, buffer, size )->name;
      }   
    | OP images_or_atlas CP RawString { 
        int size;
        char * buffer = parse_buffer( _environment, $4, &size, 0 );
        $$ = images_load_from_buffer( _environment, buffer, size )->name;
      }   
    | OP images_or_atlas CP Identifier { 
        Constant * c = constant_find( ((Environment *)_environment)->constants, $4 );
        if ( c == NULL ) {
            CRITICAL_UNDEFINED_CONSTANT( $4 );
        }
        if ( c->type != CT_STRING ) {
            CRITICAL_TYPE_MISMATCH_CONSTANT_STRING( $4 );
        }
        $$ = images_load_from_buffer( _environment, c->valueString->value, c->valueString->size )->name;
      }      
    | BETA {
#ifdef __BETA__
         int beta = 1;
#else
         int beta = 0;
#endif
        $$ = variable_temporary( _environment, VT_BYTE, "(BETA value)" )->name;
        variable_store( _environment, $$, beta );
    }
    | PI {
        Variable * pi = variable_temporary( _environment, VT_FLOAT, "(float)" );
        variable_store_float( _environment, pi->name, M_PI );
        $$ = pi->name;
      }
    | PI OP CP {
        Variable * pi = variable_temporary( _environment, VT_FLOAT, "(float)" );
        variable_store_float( _environment, pi->name, M_PI );
        $$ = pi->name;
      }
    | SQR OP expr CP {
        $$ = sqroot( _environment, $3 )->name;
      }
    | LOG OP expr CP {
        $$ = fp_log( _environment, $3 )->name;
      }
    | EXP OP expr CP {
        $$ = fp_exp( _environment, $3 )->name;
      }
    | SIN OP expr CP {
        $$ = fp_sin( _environment, $3 )->name;
      }
    | COS OP expr CP {
        $$ = fp_cos( _environment, $3 )->name;
      }
    | TAN OP expr CP {
        $$ = fp_tan( _environment, $3 )->name;
      }
    | COMBINE NIBBLE OP expr OP_COMMA expr CP {
        $$ = combine_nibble_vars( _environment, $4, $6 )->name;
      }
    | NEW TILESET {
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
      }
    | NEW IMAGE OP const_expr OP_COMMA const_expr CP {        
        $$ = new_image( _environment, $4, $6, ((struct _Environment *)_environment)->currentMode )->name;
      }
    | NEW images_or_atlas OP const_expr OP_COMMA const_expr OP_COMMA const_expr CP {        
        $$ = new_images( _environment, $4, $6, $8, ((struct _Environment *)_environment)->currentMode )->name;
      }
    | NEW SEQUENCE OP const_expr OP_COMMA const_expr OP_COMMA const_expr OP_COMMA const_expr CP {        
        $$ = new_sequence( _environment, $4, $6, $8, $10, ((struct _Environment *)_environment)->currentMode )->name;
      }
    | NEW MUSIC OP const_expr CP {        
        $$ = new_music( _environment, $4 )->name;
    }
    | LOAD OP String CP on_bank load_flags {
        $$ = load( _environment, $3, NULL, 0, $5, $6 )->name;
      }
    | LOAD OP String AS String CP on_bank load_flags {
        $$ = load( _environment, $3, $5, 0, $7, $8 )->name;
      }
    | LOAD OP String OP_COMMA Integer CP on_bank load_flags {
        $$ = load( _environment, $3, NULL, $5, $7, $8 )->name;
      }
    | LOAD OP String AS String OP_COMMA Integer CP on_bank load_flags {
        $$ = load( _environment, $3, $5, $7, $9, $10 )->name;
      }
    | LOAD MUSIC OP String CP on_bank {
        $$ = music_load( _environment, $4, NULL, $6 )->name;
      }
    | LOAD MUSIC OP String AS String CP on_bank {
        $$ = music_load( _environment, $4, $6, $8 )->name;
      }
    | load_sequence OP String AS String CP frame SIZE OP const_expr OP_COMMA const_expr CP sequence_load_flags  using_transparency using_opacity using_background on_bank readonly_optional {
        Variable * sequence = sequence_load( 
            _environment, 
            $3, $5, 
            ((struct _Environment *)_environment)->currentMode, 
            $10, $12, 
            $14, $15+$16, 
            $17, $18, 
            ((struct _Environment *)_environment)->frameOriginX, ((struct _Environment *)_environment)->frameOriginY, 
            ((struct _Environment *)_environment)->frameOffsetX, ((struct _Environment *)_environment)->frameOffsetY );
        sequence->readonly = $19;
        $$ = sequence->name;
      }
    | load_sequence OP String CP frame SIZE OP const_expr OP_COMMA const_expr CP sequence_load_flags  using_transparency using_opacity using_background on_bank readonly_optional {        
        Variable * sequence = sequence_load( 
            _environment, 
            $3, NULL, 
            ((struct _Environment *)_environment)->currentMode, 
            $8, $10, 
            $12, $13+$14, 
            $15, $16, 
            ((struct _Environment *)_environment)->frameOriginX, ((struct _Environment *)_environment)->frameOriginY, 
            ((struct _Environment *)_environment)->frameOffsetX, ((struct _Environment *)_environment)->frameOffsetY );
        sequence->readonly = $17;
        $$ = sequence->name;
      }
    | load_images OP String CP frame_size images_load_flags  using_transparency using_opacity using_background on_bank readonly_optional {
        Variable * images = images_load( _environment, 
            $3, NULL, 
            ((struct _Environment *)_environment)->currentMode, 
            ((struct _Environment *)_environment)->frameWidth, ((struct _Environment *)_environment)->frameHeight, 
            $8, $7+$8, 
            $9, $10, 
            ((struct _Environment *)_environment)->frameOriginX, ((struct _Environment *)_environment)->frameOriginY, 
            ((struct _Environment *)_environment)->frameOffsetX, ((struct _Environment *)_environment)->frameOffsetY );
        images->readonly = $11;
        $$ = images->name;
      }
    | load_images OP String AS String CP frame_size images_load_flags  using_transparency using_opacity using_background on_bank readonly_optional {
        Variable * images = images_load( _environment, 
            $3, $5, 
            ((struct _Environment *)_environment)->currentMode, 
            ((struct _Environment *)_environment)->frameWidth, ((struct _Environment *)_environment)->frameHeight,
            $8, $9+$10, 
            $11, $12, 
            ((struct _Environment *)_environment)->frameOriginX, ((struct _Environment *)_environment)->frameOriginY, 
            ((struct _Environment *)_environment)->frameOffsetX, ((struct _Environment *)_environment)->frameOffsetY );
        images->readonly = $13;
        $$ = images->name;
      }
    | load_tileset OP String CP images_load_flags using_transparency using_opacity using_background on_bank {
        $$ = tileset_load( _environment, $3, NULL, ((struct _Environment *)_environment)->currentMode, $5, $6+$7, $8, $9 )->name;
      }
    | load_tileset OP String AS String CP images_load_flags  using_transparency using_opacity using_background on_bank {
        $$ = tileset_load( _environment, $3, $5, ((struct _Environment *)_environment)->currentMode, $7, $8+$9, $10, $11 )->name;
      }
    | load_tilemap OP String CP images_load_flags using_transparency using_opacity using_background on_bank {
        $$ = tilemap_load( _environment, $3, NULL, ((struct _Environment *)_environment)->currentMode, $5, $6+$7, $8, $9 )->name;
      }
    | load_image OP String CP image_load_flags  using_transparency using_opacity using_background on_bank readonly_optional {
        Variable * image = image_load( _environment, $3, NULL, ((struct _Environment *)_environment)->currentMode, $5, $6+$7, $8, $9 );
        image->readonly = $10;
        $$ = image->name;
      }
    | load_image OP String AS String CP image_load_flags  using_transparency using_opacity using_background on_bank readonly_optional {
        Variable * image = image_load( _environment, $3, $5, ((struct _Environment *)_environment)->currentMode, $7, $8+$9, $10, $11 );
        image->readonly = $12;
        $$ = image->name;
      }
    | load_image OP String OP_COMMA Integer CP image_load_flags  using_transparency using_opacity using_background on_bank readonly_optional {
        Variable * image = image_load( _environment, $3, NULL, $5, $7, $8+$9, $10, $11 );
        image->readonly = $12;
        $$ = image->name;
      }
    | load_image OP String AS String OP_COMMA Integer CP image_load_flags  using_transparency using_opacity using_background on_bank readonly_optional {
        Variable * image = image_load( _environment, $3, $5, $7, $9, $10+$11, $12, $13 );
        image->readonly = $14;
        $$ = image->name;
      }
    | LOAD TILE OP String CP tile_load_flags {
        $$ = tile_load( _environment, $4, $6, NULL, -1 )->name;
      }
    | LOAD TILE OP String OP_COMMA expr CP tile_load_flags {
        $$ = tile_load( _environment, $4, $8, $6, -1 )->name;
      }
    | LOAD TILES OP String CP tile_load_flags {
        $$ = tiles_load( _environment, $4, $6, NULL, -1 )->name;
      }
    | LOAD TILES OP String OP_COMMA expr CP tile_load_flags {
        $$ = tiles_load( _environment, $4, $8, $6, -1 )->name;
      }
    | SIZE OP expr CP {
        Variable * v = variable_retrieve( _environment, $3 );
        switch( v->type ) {
            case VT_IMAGE:
            case VT_IMAGES:
            case VT_SEQUENCE:
            case VT_BUFFER:
            case VT_STRING: 
                break;
            default:
                CRITICAL_SIZE_UNSUPPORTED( $3, DATATYPE_AS_STRING[v->type] );
                break;
        }
        $$ = variable_temporary( _environment, ((struct _Environment *)_environment)->defaultVariableType, "(size)" )->name;
        variable_store( _environment, $$, v->size );
      }
    | color_enumeration { 
        $$ = $1;
      }
    | RGB OP const_expr OP_COMMA const_expr OP_COMMA const_expr CP {
        $$ = variable_temporary( _environment, VT_COLOR, "(color)" )->name;
        if ( ((Environment *)_environment)->currentRgbConverterFunction ) {
            variable_store( _environment, $$, ((Environment *)_environment)->currentRgbConverterFunction( $3, $5, $7 ) );
        } else {
            variable_store( _environment, $$, 0 );
        }
    }
    | DISTANCE OP optional_x OP_COMMA optional_y TO optional_x OP_COMMA optional_y CP {
        $$ = distance( _environment, $3, $5, $7, $9 )->name;
    }
    | READ END {
        $$ = read_end( _environment )->name;
      }
    | PEEK OP expr CP {
        $$ = peek_var( _environment, $3 )->name;
      }
    | PEEKW OP expr CP {
        $$ = peekw_var( _environment, $3 )->name;
      }
    | PEEKD OP expr CP {
        $$ = peekd_var( _environment, $3 )->name;
      }
    | XPEN {
        $$ = xpen( _environment )->name;
      }
    | YPEN {
        $$ = ypen( _environment )->name;
      }
    | XGR {
        $$ = "XGR";
      }
    | YGR {
        $$ = "YGR";
      }
    | INT OP expr CP {
        $$ = variable_int( _environment, $3 )->name;
    }
    | IN OP expr CP {
        $$ = in_var( _environment, $3 )->name;
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
    | TILESET OP expr CP {
        $$ = tileset_of_vars( _environment, $3 )->name;
    }
    | TILEMAP INDEX OP expr OP_COMMA expr OP_COMMA expr CP {
        $$ = tilemap_index_vars( _environment, $4, $6, $8, NULL )->name;
    }
    | TILEMAP INDEX OP expr OP_COMMA expr OP_COMMA expr OP_COMMA expr CP {
        $$ = tilemap_index_vars( _environment, $4, $6, $8, $10 )->name;
    }
    | LEFT OP expr OP_COMMA expr CP {
        $$ = variable_string_left( _environment, $3, $5 )->name;
    }
    | RIGHT OP expr OP_COMMA expr CP {
        $$ = variable_string_right( _environment, $3, $5 )->name;
    }
    | BANK COUNT {
        $$ = bank_get_count( _environment )->name;
    }
    | STRPTR OP expr CP {
        $$ = strptr( _environment, $3 )->name;
    }
    | VARPTR OP Identifier CP {
        $$ = varptr( _environment, $3 )->name;
    }
    | VARBANK OP Identifier CP {
        Variable * variable = variable_retrieve( _environment, $3 );
        Variable * bank = variable_temporary( _environment, VT_BYTE, "(bank)");
        variable_store( _environment, bank->name, variable->bankAssigned );
        $$ = bank->name;
    }
    | VARBANKPTR OP Identifier CP {
        Variable * variable = variable_retrieve( _environment, $3 );
        Variable * ptr = variable_temporary( _environment, VT_ADDRESS, "(ptr)");
        variable_store( _environment, ptr->name, variable->absoluteAddress );
        $$ = ptr->name;
    }
    | BANK OP CP {
        $$ = bank_get( _environment )->name;
    }
    | BANK ADDRESS OP OP_HASH const_expr CP {
        $$ = bank_get_address( _environment, $5 )->name;
    }
    | BANK ADDRESS OP expr CP {
        $$ = bank_get_address_var( _environment, $4 )->name;
    }
    | BANK SIZE OP OP_HASH const_expr CP {
        $$ = bank_get_size( _environment, $5 )->name;
    }
    | BANK SIZE OP expr CP {
        $$ = bank_get_size_var( _environment, $4 )->name;
    }
    | INST OP expr OP_COMMA expr OP_COMMA expr CP {
        $$ = variable_string_inst( _environment, $3, $5, $7 )->name;
    }
    | INSERT OP expr OP_COMMA expr OP_COMMA expr CP {
        $$ = variable_string_insert( _environment, $3, $5, $7 )->name;
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
    | HEX OP expr CP {
        $$ = variable_hex( _environment, $3 )->name;
    }
    | OP_DOLLAR2 OP expr CP {
        $$ = variable_hex( _environment, $3 )->name;
    }
    | STR OP expr CP {
        $$ = variable_string_str( _environment, $3 )->name;
    }
    | OP_PERC2 OP expr CP {
        $$ = variable_bin( _environment, $3, NULL )->name;
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
    | PICK OP expr OP_COMMA const_expr CP {
        $$ = variable_string_pick( _environment, $3, $5 )->name;
    }    
    | ASC OP expr CP {
        $$ = variable_string_asc( _environment, $3 )->name;
    }
    | UBOUND OP expr CP {
        Variable * array = variable_retrieve( _environment, $3 );
        if ( array->type != VT_TARRAY ) {
            CRITICAL_NOT_ARRAY( $3 );
        }
        Variable * value = variable_temporary( _environment, VT_WORD, "(ubound)" );
        variable_store( _environment, value->name, array->arrayDimensionsEach[array->arrayDimensions-1] );
        $$ = value->name;
    }
    | UBOUND OP expr OP_COMMA const_expr CP {
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
        variable_store( _environment, value->name, array->arrayDimensionsEach[array->arrayDimensions-$5-1] );
        $$ = value->name;
    }
    | LBOUND OP expr CP {
        Variable * array = variable_retrieve( _environment, $3 );
        if ( array->type != VT_TARRAY ) {
            CRITICAL_NOT_ARRAY( $3 );
        }
        Variable * value = variable_temporary( _environment, VT_WORD, "(lbound)" );
        variable_store( _environment, value->name, 0 );
        $$ = value->name;
    }
    | LBOUND OP expr OP_COMMA const_expr CP {
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
    }
    | LEN OP expr CP {
        $$ = variable_string_len( _environment, $3 )->name;
    }
    | DUP OP expr OP_COMMA expr CP {
        $$ = variable_string_dup( _environment, $3, $5 )->name;
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
    | POINT OP optional_x OP_COMMA optional_y CP {
        $$ = point( _environment, $3, $5 )->name;
    }
    | MAX OP expr OP_COMMA expr CP {
        $$ = maximum( _environment, $3, $5 )->name;
    }
    | MIN OP expr OP_COMMA expr CP {
        $$ = minimum( _environment, $3, $5 )->name;
    }
    | PARAM OP Identifier on_targets CP  {
        if ( $4 ) {
            $$ = param_procedure( _environment, $3 )->name;
        } else {
            Variable * var = variable_temporary( _environment, VT_WORD, "(temp)" );
            $$ = var->name;
        }
    }
    | PARAM OP_DOLLAR OP Identifier on_targets CP  {
        if ( $5 ) {
            $$ = param_procedure( _environment, $4 )->name;
        } else {
            Variable * var = variable_temporary( _environment, VT_WORD, "(temp)" );
            $$ = var->name;
        }
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
    | halted SPAWN Identifier {
      ((struct _Environment *)_environment)->parameters = 0;
      $$ = spawn_procedure( _environment, $3, $1 )->name;
    }
    | halted SPAWN Identifier OSP {
        ((struct _Environment *)_environment)->parameters = 0;
        } values CSP {
      $$ = spawn_procedure( _environment, $3, $1 )->name;
    }
    | halted SPAWN Identifier OSP CSP {
        ((struct _Environment *)_environment)->parameters = 0;
      $$ = spawn_procedure( _environment, $3, $1 )->name;
    }
    | RESPAWN Identifier {
      ((struct _Environment *)_environment)->parameters = 0;
      $$ = respawn_procedure( _environment, $2 )->name;
    }
    | SGN OP expr CP {
        $$ = sign( _environment, $3 )->name;
    }
    | ABS OP expr CP {
        $$ = absolute( _environment, $3 )->name;
    }
    | TRUE {
        $$ = variable_temporary( _environment, VT_SBYTE, "(true)" )->name;
        variable_store( _environment, $$, 255 );
    }
    | FALSE {
        $$ = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, $$, 0 );
    }
    | COLORS {
        $$ = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, $$, ((Environment *)_environment)->screenColors );
    }
    | COLORS COUNT {
        $$ = variable_temporary( _environment, VT_COLOR, "(COLORS COUNT)" )->name;
        variable_store( _environment, $$, ((Environment *)_environment)->screenColors );
    }
    | COLOR COUNT {
        $$ = variable_temporary( _environment, VT_COLOR, "(COLORS COUNT)" )->name;
        variable_store( _environment, $$, ((Environment *)_environment)->screenColors );
    }
    | COLOURS {
        $$ = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, $$, ((Environment *)_environment)->screenColors );
    }
    | COLOURS COUNT {
        $$ = variable_temporary( _environment, VT_COLOR, "(COLORS COUNT)" )->name;
        variable_store( _environment, $$, ((Environment *)_environment)->screenColors );
    }
    | COLOUR COUNT {
        $$ = variable_temporary( _environment, VT_COLOR, "(COLORS COUNT)" )->name;
        variable_store( _environment, $$, ((Environment *)_environment)->screenColors );
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
    | SCREEN SHADES {
        $$ = variable_temporary( _environment, VT_WORD, "(SCREEN SHADES)" )->name;
        variable_store( _environment, $$, ((Environment *)_environment)->screenShades );
    }
    | SHADES {
        $$ = variable_temporary( _environment, VT_WORD, "(SCREEN SHADES)" )->name;
        variable_store( _environment, $$, ((Environment *)_environment)->screenShades );
    }
    | SCREEN COLORS {
        $$ = variable_temporary( _environment, VT_COLOR, "(SCREEN COLORS)" )->name;
        variable_store( _environment, $$, ((Environment *)_environment)->screenColors );
    }
    | PEN COLORS {
        $$ = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, $$, COLOR_COUNT );
    }
    | SCREEN COLOURS {
        $$ = variable_temporary( _environment, VT_COLOR, "(SCREEN COLORS)" )->name;
        variable_store( _environment, $$, ((Environment *)_environment)->screenColors );
    }
    | PEN COLOURS {
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
    | PAPER COLOURS {
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
    | XTEXT OP expr CP {
        $$ = x_text_get( _environment, $3 )->name;
    }
    | X TEXT OP expr CP {
        $$ = x_text_get( _environment, $4 )->name;
    }
    | YTEXT OP expr CP {
        $$ = y_text_get( _environment, $3 )->name;
    }
    | Y TEXT OP expr CP {
        $$ = y_text_get( _environment, $4 )->name;
    }
    | XGRAPHIC OP expr CP {
        $$ = x_graphic_get( _environment, $3 )->name;
    }
    | X GRAPHIC OP expr CP {
        $$ = x_graphic_get( _environment, $4 )->name;
    }
    | YGRAPHIC OP expr CP {
        $$ = y_graphic_get( _environment, $3 )->name;
    }
    | Y GRAPHIC OP expr CP {
        $$ = y_graphic_get( _environment, $4 )->name;
    }
    | WIDTH {
        $$ = screen_get_width( _environment )->name;
    }
    | COLOR OP expr CP {
        $$ = color_get_vars( _environment, $3 )->name;
    }
    | SCREEN WIDTH {
        $$ = screen_get_width( _environment )->name;
    }
    | SCREEN TILES WIDTH {
        $$ = screen_tiles_get_width( _environment )->name;
    }
    | TILES WIDTH {
        $$ = console_tiles_get_width( _environment )->name;
    }
    | TILES COUNT {
        $$ = screen_tiles_get( _environment )->name;
    }
    | SCREEN COLUMNS {
        $$ = screen_tiles_get_width( _environment )->name;
    }
    | COLUMNS {
        $$ = console_tiles_get_width( _environment )->name;
    }
    | FONT WIDTH {
        $$ = variable_temporary( _environment, VT_POSITION, "(FONT WIDTH)" )->name;
        variable_store( _environment, $$, ((struct _Environment *)_environment)->fontWidth );
    }
    | IMAGES COUNT OP expr CP {
        $$ = variable_temporary( _environment, VT_BYTE, "(frame count)" )->name;
        variable_store( _environment, $$, frames( _environment, $4 ) );
    }
    | frame COUNT OP expr CP {
        $$ = variable_temporary( _environment, VT_BYTE, "(frame count)" )->name;
        variable_store( _environment, $$, frames( _environment, $4 ) );
    }
    | FRAMES OP expr CP {
        $$ = variable_temporary( _environment, VT_BYTE, "(frame count)" )->name;
        variable_store( _environment, $$, frames( _environment, $3 ) );
    }
    | TILE CLASS OP expr OP_COMMA const_expr CP {
        $$ = tile_class( _environment, $4, $6 )->name;
    }
    | TILE PROBABILITY OP expr OP_COMMA const_expr CP {
        $$ = tile_probability( _environment, $4, $6 )->name;
    }
    | TILE BELONG OP expr OP_COMMA expr CP {
        $$ = tile_belong( _environment, $4, $6 )->name;
    }
    | TILE AT OP expr OP_COMMA expr CP {
        $$ = tile_at( _environment, $4, $6 )->name;
    }
    | TILES FIRST OP expr CP {
        $$ = tile_get_first( _environment, $4 )->name;
    }
    | TILEMAP WIDTH OP expr CP {
        $$ = tilemap_get_width( _environment, $4 )->name;
    }
    | TILE WIDTH OP expr CP {
        Variable * v = variable_retrieve( _environment, $4 );
        if ( v->type == VT_IMAGES && v->originalTileset != NULL ) {
            $$ = tileset_tile_get_width( _environment, $4 )->name;
        } else {
            $$ = tile_get_width( _environment, $4 )->name;
        }
    }
    | DLOAD ERROR {
        $$ = variable_temporary( _environment, VT_BYTE, "(DLOAD ERROR)" )->name;
        variable_move( _environment, "DLOADERROR", $$ );
    }
    | DSAVE ERROR {
        $$ = variable_temporary( _environment, VT_BYTE, "(DSAVE ERROR)" )->name;
        variable_move( _environment, "DSAVEERROR", $$ );
    }
    | PAL {
        Variable * pal = variable_temporary( _environment, VT_SBYTE, "PAL" );
        cpu_compare_8bit_const( _environment, "TICKSPERSECOND", 50, pal->realName, 1 );
        $$ = pal->name;
    }
    | NTSC {
        Variable * ntsc = variable_temporary( _environment, VT_SBYTE, "NTSC" );
        cpu_compare_8bit_const( _environment, "TICKSPERSECOND", 60, ntsc->realName, 1 );
        $$ = ntsc->name;
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
    | SCREEN ROWS {
        $$ = screen_tiles_get_height( _environment )->name;
    }
    | ROWS {
        $$ = console_tiles_get_height( _environment )->name;
    }
    | FONT HEIGHT {
        $$ = variable_temporary( _environment, VT_POSITION, "(FONT HEIGHT)" )->name;
        variable_store( _environment, $$, ((struct _Environment *)_environment)->fontHeight );
    }
    | TILEMAP HEIGHT OP expr CP {
        $$ = tilemap_get_height( _environment, $4 )->name;
    }
    | TILE HEIGHT OP expr CP {
        Variable * v = variable_retrieve( _environment, $4 );
        if ( v->type == VT_IMAGES && v->originalTileset != NULL ) {
            $$ = tileset_tile_get_height( _environment, $4 )->name;
        } else {
            $$ = tile_get_height( _environment, $4 )->name;
        }
    }
    | IMAGE HEIGHT OP expr CP {
        $$ = image_get_height( _environment, $4 )->name;
    }
    | TILEMAP Identifier AT OP expr OP_COMMA expr CP {
        $$ = tilemap_at( _environment, $2, $5, $7, NULL )->name;
    }
    | TILEMAP Identifier LAYER expr AT OP expr OP_COMMA expr CP {
        $$ = tilemap_at( _environment, $2, $7, $9, $4 )->name;
    }
    | SCREEN PAGE {
        $$ = screen_page( _environment )->name;
    }
    | VOLUME MIN {
        $$ = variable_temporary( _environment, VT_WORD, "(volume min)" )->name;
        variable_store( _environment, $$, 0 );
    }
    | VOLUME MAX {
        $$ = variable_temporary( _environment, VT_WORD, "(volume max)" )->name;
        variable_store( _environment, $$, 255 );
    }
    | SPRITE COUNT {
        $$ = variable_temporary( _environment, VT_WORD, "(SPRITE COUNT)" )->name;
        variable_store( _environment, $$, SPRITE_COUNT );
    }
    | SPRITE HEIGHT {
        if ( SPRITE_HEIGHT < 0 ) {
            $$ = screen_get_height( _environment )->name;
        } else {
            $$ = variable_temporary( _environment, VT_WORD, "(SPRITE HEIGHT)" )->name;
            variable_store( _environment, $$, SPRITE_HEIGHT );
        }
    }
    | SPRITE WIDTH {
        if ( SPRITE_HEIGHT < 0 ) {
            $$ = screen_get_width( _environment )->name;
        } else {
            $$ = variable_temporary( _environment, VT_WORD, "(SPRITE WIDTH)" )->name;
            variable_store( _environment, $$, SPRITE_WIDTH );
        }
    }
    | SCREEN SPRITE RATIO X {
        $$ = variable_temporary( _environment, VT_POSITION, "(SCREEN SPRITE RATIO X)" )->name;
        variable_store( _environment, $$, SCREEN_SPRITE_RATIO_X );
    }
    | SCREEN SPRITE RATIO Y {
        $$ = variable_temporary( _environment, VT_POSITION, "(SCREEN SPRITE RATIO y)" )->name;
        variable_store( _environment, $$, SCREEN_SPRITE_RATIO_Y );
    }
    | SCREEN BORDER X {
        $$ = variable_temporary( _environment, VT_POSITION, "(SCREEN BORDER X)" )->name;
        variable_store( _environment, $$, SCREEN_BORDER_X );
    }
    | SCREEN BORDER Y {
        $$ = variable_temporary( _environment, VT_POSITION, "(SCREEN BORDER Y)" )->name;
        variable_store( _environment, $$, SCREEN_BORDER_Y );
    }
    | ticks PER SECOND {
        $$ = get_ticks_per_second( _environment )->name;
    }
    | SPRITE X MIN {
        $$ = variable_temporary( _environment, VT_POSITION, "(SPRITE X MIN)" )->name;
        variable_store( _environment, $$, SPRITE_X_MIN );
    }
    | SPRITE MIN X {
        $$ = variable_temporary( _environment, VT_POSITION, "(SPRITE X MIN)" )->name;
        variable_store( _environment, $$, SPRITE_X_MIN );
    }
    | SPRITE MIN Y {
        $$ = variable_temporary( _environment, VT_POSITION, "(SPRITE Y MIN)" )->name;
        variable_store( _environment, $$, SPRITE_Y_MIN );
    }
    | SPRITE Y MIN {
        $$ = variable_temporary( _environment, VT_POSITION, "(SPRITE Y MIN)" )->name;
        variable_store( _environment, $$, SPRITE_Y_MIN );
    }
    | SPRITE X MAX {
        $$ = variable_temporary( _environment, VT_POSITION, "(SPRITE X MAX)" )->name;
        variable_store( _environment, $$, SPRITE_X_MAX );
    }
    | SPRITE MAX X {
        $$ = variable_temporary( _environment, VT_POSITION, "(SPRITE X MAX)" )->name;
        variable_store( _environment, $$, SPRITE_X_MAX );
    }
    | SPRITE MAX Y {
        $$ = variable_temporary( _environment, VT_POSITION, "(SPRITE Y MAX)" )->name;
        variable_store( _environment, $$, SPRITE_Y_MAX );
    }
    | SPRITE Y MAX {
        $$ = variable_temporary( _environment, VT_POSITION, "(SPRITE Y MAX)" )->name;
        variable_store( _environment, $$, SPRITE_Y_MAX );
    }
    | SPRITE OP expr sprite_flags CP {
        $$ = sprite_init( _environment, $3, NULL, $4 )->name;
    }
    | SPRITE OP expr OP_COMMA expr sprite_flags CP  {
        $$ = sprite_init( _environment, $3, $5, $6 )->name;
    }
    | CSPRITE OP expr sprite_flags CP {
        $$ = csprite_init( _environment, $3, NULL, $4 )->name;
    }
    | CSPRITE OP expr OP_COMMA expr sprite_flags CP {
        $$ = csprite_init( _environment, $3, $5, $6 )->name;
    }
    | MSPRITE OP expr sprite_flags CP {
        $$ = msprite_init( _environment, $3, NULL, $4 )->name;
    }
    | MSPRITE OP expr OP_COMMA expr sprite_flags CP {
        $$ = msprite_init( _environment, $3, $5, $6 )->name;
    }
    | PAGE "0" {
        $$ = variable_temporary( _environment, VT_BYTE, "(PAGE 0)" )->name;
        variable_store( _environment, $$, DOUBLE_BUFFER_PAGE_0 );
    }
    | PAGE "1" {
        $$ = variable_temporary( _environment, VT_BYTE, "(PAGE 1)" )->name;
        variable_store( _environment, $$, DOUBLE_BUFFER_PAGE_1 );
    }
    | PAGE A {
        $$ = variable_temporary( _environment, VT_BYTE, "(PAGE 0)" )->name;
        variable_store( _environment, $$, DOUBLE_BUFFER_PAGE_0 );
    }
    | PAGE B {
        $$ = variable_temporary( _environment, VT_BYTE, "(PAGE 1)" )->name;
        variable_store( _environment, $$, DOUBLE_BUFFER_PAGE_1 );
    }
    | IMAGE OP expr frame const_expr CP {
        $$ = image_extract( _environment, $3, $5, NULL )->name;
    }
    | IMAGE OP expr SEQUENCE const_expr frame const_expr CP {
        int sequence = $5;
        $$ = image_extract( _environment, $3, $7, &sequence )->name;
    }
    | IMAGE OP expr frame NAMED Identifier CP {
        Variable * images = variable_retrieve( _environment, $3 );
        int calculatedFrame = find_frame_by_type( _environment, images->originalTileset, $3, $6 );
        $$ = image_extract( _environment, $3, calculatedFrame, NULL )->name;
    }
    | RASTER LINE {
        $$ = get_raster_line( _environment )->name;
    }
    | TI {
        $$ = get_timer( _environment )->name;
    }
    | EMPTYTILE {
        $$ = "EMPTYTILE";
    }
    | EMPTY TILE {
        $$ = "EMPTYTILE";
    }
    | TIMER {
        $$ = get_timer( _environment )->name;
    }
    | PEN OP expr CP {
        $$ = get_pen( _environment, $3 )->name;
    }
    | PEN OP_DOLLAR OP expr CP {
        $$ = get_pen( _environment, $4 )->name;
    }
    | PAPER OP expr CP {
        $$ = get_paper( _environment, $3 )->name;
    }
    | PAPER OP_DOLLAR OP expr CP {
        $$ = get_paper( _environment, $4 )->name;
    }
    | CMOVE OP expr OP_COMMA expr CP {
        $$ = get_cmove( _environment, $3, $5 )->name;
    }
    | CMOVE OP_DOLLAR OP expr OP_COMMA expr CP {
        $$ = get_cmove( _environment, $4, $6 )->name;
    }
    | CUP {
        $$ = get_cmove_direct( _environment, 0, -1 )->name;
    }
    | CUP OP_DOLLAR {
        $$ = get_cmove_direct( _environment, 0, -1 )->name;
    }
    | CDOWN {
        $$ = get_cmove_direct( _environment, 0, 1 )->name;
    }
    | CDOWN OP_DOLLAR {
        $$ = get_cmove_direct( _environment, 0, 1 )->name;
    }
    | CLEFT {
        $$ = get_cmove_direct( _environment, -1, 0 )->name;
    }
    | CLEFT OP_DOLLAR {
        $$ = get_cmove_direct( _environment, -1, 0 )->name;
    }
    | CRIGHT {
        $$ = get_cmove_direct( _environment, 1, 0 )->name;
    }
    | CRIGHT OP_DOLLAR {
        $$ = get_cmove_direct( _environment, 1, 0 )->name;
    }
    | AT OP expr OP_COMMA expr CP {
        $$ = get_at( _environment, $3, $5 )->name;
    }
    | AT OP_DOLLAR OP expr OP_COMMA expr CP {
        $$ = get_at( _environment, $4, $6 )->name;
    }
    | LOCATE OP expr OP_COMMA expr CP {
        $$ = get_at( _environment, $3, $5 )->name;
    }
    | LOCATE OP_DOLLAR OP expr OP_COMMA expr CP {
        $$ = get_at( _environment, $4, $6 )->name;
    }
    | TAB {
        $$ = get_tab( _environment )->name;
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
    | JOY OP OP_HASH const_expr CP {
        $$ = joy( _environment, $4 )->name;
    }
    | JOY OP expr CP {
        $$ = joy_vars( _environment, $3 )->name;
    }
    | JOYX OP OP_HASH const_expr CP {
        $$ = joyx( _environment, $4 )->name;
    }
    | JOYX OP expr CP {
        $$ = joyx_vars( _environment, $3 )->name;
    }
    | JOY X OP OP_HASH const_expr CP {
        $$ = joyx( _environment, $5 )->name;
    }
    | JOY X OP expr CP {
        $$ = joyx_vars( _environment, $4 )->name;
    }
    | JOYY OP OP_HASH const_expr CP {
        $$ = joyy( _environment, $4 )->name;
    }
    | JOYY OP expr CP {
        $$ = joyy_vars( _environment, $3 )->name;
    }
    | JOY Y OP OP_HASH const_expr CP {
        $$ = joyy( _environment, $5 )->name;
    }
    | JOY Y OP expr CP {
        $$ = joyy_vars( _environment, $4 )->name;
    }
    | JUP OP expr CP {
        $$ = joy_direction_semivars( _environment, $3, JOY_UP )->name;
    }
    | JUP OP OP_HASH const_expr CP {
        $$ = joy_direction( _environment, $4, JOY_UP )->name;
    }
    | JDOWN OP expr CP {
        $$ = joy_direction_semivars( _environment, $3, JOY_DOWN )->name;
    }
    | JDOWN OP OP_HASH const_expr CP {
        $$ = joy_direction( _environment, $4, JOY_DOWN )->name;
    }
    | JLEFT OP expr CP {
        $$ = joy_direction_semivars( _environment, $3, JOY_LEFT )->name;
    }
    | JLEFT OP OP_HASH const_expr CP {
        $$ = joy_direction( _environment, $4, JOY_LEFT )->name;
    }
    | JRIGHT OP expr CP {
        $$ = joy_direction_semivars( _environment, $3, JOY_RIGHT )->name;
    }
    | JRIGHT OP OP_HASH const_expr CP {
        $$ = joy_direction( _environment, $4, JOY_RIGHT )->name;
    }
    | JFIRE OP expr CP {
        $$ = joy_direction_semivars( _environment, $3, JOY_FIRE )->name;
    }
    | JFIRE OP OP_HASH const_expr CP {
        $$ = joy_direction( _environment, $4, JOY_FIRE )->name;
    }
    | FIRE OP expr CP {
        $$ = joy_direction_semivars( _environment, $3, JOY_FIRE )->name;
    }
    | FIRE OP OP_HASH const_expr CP {
        $$ = joy_direction( _environment, $4, JOY_FIRE )->name;
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
    | INPUT OP expr CP {
        $$ = input_string( _environment, $3 )->name;
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
    | KEY PRESSED OP OP_HASH const_expr CP {
        $$ = key_pressed( _environment, $5 )->name;
    }
    | KEY PRESSED OP expr CP {
        $$ = key_pressed_var( _environment, $4 )->name;
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
    | NOTE const_note {
        $$ = variable_temporary( _environment, VT_BYTE, "(note)" )->name;
        variable_store( _environment, $$, $2 );
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

bank_expansion_definition_simple :
    OP_HASH const_expr {
        bank_set( _environment, $2 );
    }
    ;

bank_expansion_definition_expression :
    expr {
        bank_set_var( _environment, $1 );
    }
    | READ expr FROM expr TO expr SIZE expr {
        bank_read_vars( _environment, $2, $4, $6, $8 );
    }
    | WRITE expr FROM expr TO expr SIZE expr {
        bank_write_vars( _environment, $4, $2, $6, $8 );
    }
    ;

bank_definition: 
    bank_definition_simple
  | bank_definition_with_payload
  | bank_expansion_definition_simple
  | bank_expansion_definition_expression;

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
  expr OP_COMMA expr {
      color_vars( _environment, $1, $3 );
  }
  | OP_HASH const_expr OP_COMMA expr {
      color_semivars( _environment, $2, $4 );
  }
  | OP_HASH const_expr OP_COMMA OP_HASH const_expr {
      color( _environment, $2, $5 );
  }
  | BORDER direct_integer {
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
  };

color_definition:
    color_definition_simple
  | color_definition_expression;

milliseconds:
    MS
    | MILLISECOND
    | MILLISECONDS;

release :
    {
        $$ = 0;
    }
    | RELEASE {
        $$ = 1;
    }
    ;

wait_definition_simple:
      direct_integer CYCLES parallel_optional {
      wait_cycles( _environment, $1, $3 );
    }
    | direct_integer ticks {
      wait_ticks( _environment, $1 );
    }
    | direct_integer parallel_optional {
      wait_cycles( _environment, $1, $2 );
    }
    | direct_integer milliseconds {
      wait_milliseconds( _environment, $1 );
    }
    | FIRE release {
        begin_loop( _environment );
            exit_loop_if( _environment, joy_direction( _environment, 0, JOY_FIRE )->name, 0 );
        end_loop( _environment );
        if ( $2 ) {
            begin_loop( _environment );
                exit_loop_if( _environment, variable_not( _environment, joy_direction( _environment, 0, JOY_FIRE )->name )->name, 0 );
            end_loop( _environment );
        }
    }
    | FIRE OP OP_HASH const_expr CP release {
        begin_loop( _environment );
            exit_loop_if( _environment, joy_direction( _environment, $4, JOY_FIRE )->name, 0 );
        end_loop( _environment );
        if ( $6 ) {
            begin_loop( _environment );
                exit_loop_if( _environment, variable_not( _environment, joy_direction( _environment, 0, JOY_FIRE )->name )->name, 0 );
            end_loop( _environment );
        }
    }
    | KEY OR FIRE release {
        begin_loop( _environment );
            exit_loop_if( _environment, scancode( _environment )->name, 0 );
            exit_loop_if( _environment, joy_direction( _environment, 0, JOY_FIRE )->name, 0 );
        end_loop( _environment );
        if ( $4 ) {
            begin_loop( _environment );
                exit_loop_if( _environment, variable_not( _environment, variable_or( _environment, joy_direction( _environment, 0, JOY_FIRE )->name, scancode( _environment )->name )->name )->name, 0 );
            end_loop( _environment );
        }
    }
    | KEY OR FIRE OP OP_HASH const_expr CP release {
        begin_loop( _environment );
            exit_loop_if( _environment, scancode( _environment )->name, 0 );
            exit_loop_if( _environment, joy_direction( _environment, $6, JOY_FIRE )->name, 0 );
        end_loop( _environment );
        if ( $8 ) {
            begin_loop( _environment );
                exit_loop_if( _environment, variable_not( _environment, variable_or( _environment, joy_direction( _environment, $6, JOY_FIRE )->name, scancode( _environment )->name )->name )->name, 0 );
            end_loop( _environment );
        }
    }
    | KEY release {
        wait_key( _environment );
        if ( $2 ) {
            begin_loop( _environment );
                Variable * noKey = variable_temporary( _environment, VT_BYTE, "nokey" );
                variable_move( _environment, scancode( _environment )->name, noKey->name );
                exit_loop_if( _environment, 
                    variable_not( _environment, 
                        variable_compare( _environment, 
                            scancode( _environment )->name, 
                            noKey->name 
                        )->name 
                    )->name, 0 
                );
            end_loop( _environment );
        }
    }
    | VBL {
      wait_vbl( _environment, NULL );
    }
    | VBL expr {
      wait_vbl( _environment, $2 );
    }    
    ;

wait_definition_expression:
      expr CYCLES parallel_optional {
      wait_cycles_var( _environment, $1, $3 );
    }
    | expr ticks {
      wait_ticks_var( _environment, $1 );
    }
    | expr milliseconds {
      wait_milliseconds_var( _environment, $1 );
    }
    | FIRE OP expr CP release {
        begin_loop( _environment );
            exit_loop_if( _environment, joy_direction_semivars( _environment, $3, JOY_FIRE )->name, 0 );
        end_loop( _environment );
        if ( $5 ) {
            begin_loop( _environment );
                exit_loop_if( _environment, variable_not( _environment, joy_direction_semivars( _environment, $3, JOY_FIRE )->name )->name, 0 );
            end_loop( _environment );
        }
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

sprite_definition_action_simple:
    MULTICOLOR {
      sprite_multicolor( _environment, ((Environment *)_environment)->currentSpriteNumber );
  }
  | MULTICOLOUR {
      sprite_multicolor( _environment, ((Environment *)_environment)->currentSpriteNumber );
  }
  | MONOCOLOR {
      sprite_monocolor( _environment, ((Environment *)_environment)->currentSpriteNumber );
  }
  | MONOCOLOUR {
      sprite_monocolor( _environment, ((Environment *)_environment)->currentSpriteNumber );
  }
  | COLOR direct_integer {
      sprite_color( _environment, ((Environment *)_environment)->currentSpriteNumber, $2 );
  }
  | COLOUR direct_integer {
      sprite_color( _environment, ((Environment *)_environment)->currentSpriteNumber, $2 );
  }
  | position direct_integer OP_COMMA direct_integer {
      sprite_at( _environment, ((Environment *)_environment)->currentSpriteNumber, $2, $4 );
  }
  | ENABLE {
      sprite_enable( _environment, ((Environment *)_environment)->currentSpriteNumber );
  }
  | ON {
      sprite_enable( _environment, ((Environment *)_environment)->currentSpriteNumber );
  }
  | DISABLE {
      sprite_disable( _environment, ((Environment *)_environment)->currentSpriteNumber );
  }
  | OFF {
      sprite_disable( _environment, ((Environment *)_environment)->currentSpriteNumber );
  }
  | EXPAND VERTICAL {
      sprite_expand_vertical( _environment, ((Environment *)_environment)->currentSpriteNumber );
  }
  | COMPRESS VERTICAL {
      sprite_compress_vertical( _environment, ((Environment *)_environment)->currentSpriteNumber );
  }
  | VERTICAL EXPAND {
      sprite_expand_vertical( _environment, ((Environment *)_environment)->currentSpriteNumber );
  }
  | VERTICAL COMPRESS {
      sprite_compress_vertical( _environment, ((Environment *)_environment)->currentSpriteNumber );
  }
  | EXPAND HORIZONTAL {
      sprite_expand_horizontal( _environment, ((Environment *)_environment)->currentSpriteNumber );
  }
  | COMPRESS HORIZONTAL {
      sprite_compress_horizontal( _environment, ((Environment *)_environment)->currentSpriteNumber );
  }
  | HORIZONTAL EXPAND {
      sprite_expand_horizontal( _environment, ((Environment *)_environment)->currentSpriteNumber );
  }
  | HORIZONTAL COMPRESS {
      sprite_compress_horizontal( _environment, ((Environment *)_environment)->currentSpriteNumber );
  }
  ;

sprite_definition_simple:
    sprite_definition_action_simple
    | sprite_definition_action_simple sprite_definition_simple;

sprite_definition_all_action_simple:
  | ENABLE {
    for( int i=0; i<(SPRITE_COUNT-1); ++i ) {
        sprite_enable( _environment, i );
    }
  }
  | ON {
    for( int i=0; i<(SPRITE_COUNT-1); ++i ) {
        sprite_enable( _environment, i );
    }
  }
  | DISABLE {
    for( int i=0; i<(SPRITE_COUNT-1); ++i ) {
        sprite_disable( _environment, i );
    }
  }
  | OFF {
    for( int i=0; i<(SPRITE_COUNT-1); ++i ) {
        sprite_disable( _environment, i );
    }
  }
  ;

sprite_definition_all_simple:
    sprite_definition_all_action_simple;

sprite_definition_action_expression:
    MULTICOLOR {
      sprite_multicolor_var( _environment, ((Environment *)_environment)->currentSprite );
  }
  | MULTICOLOUR {
      sprite_multicolor_var( _environment, ((Environment *)_environment)->currentSprite );
  }
  | MONOCOLOR {
      sprite_monocolor_var( _environment, ((Environment *)_environment)->currentSprite );
  }
  | MONOCOLOUR {
      sprite_monocolor_var( _environment, ((Environment *)_environment)->currentSprite );
  }
  | COLOR expr {
      sprite_color_vars( _environment, ((Environment *)_environment)->currentSprite, $2 );
  }
  | COLOUR expr {
      sprite_color_vars( _environment, ((Environment *)_environment)->currentSprite, $2 );
  }
  | position expr OP_COMMA expr {
      sprite_at_vars( _environment, ((Environment *)_environment)->currentSprite, $2, $4 );
  }
  | ENABLE {
      sprite_enable_var( _environment, ((Environment *)_environment)->currentSprite );
  }
  | ON {
      sprite_enable_var( _environment, ((Environment *)_environment)->currentSprite );
  }
  | DISABLE {
      sprite_disable_var( _environment, ((Environment *)_environment)->currentSprite );
  }
  | OFF {
      sprite_disable_var( _environment, ((Environment *)_environment)->currentSprite );
  }
  | EXPAND VERTICAL {
      sprite_expand_vertical_var( _environment, ((Environment *)_environment)->currentSprite );
  }
  | COMPRESS VERTICAL {
      sprite_compress_vertical_var( _environment, ((Environment *)_environment)->currentSprite );
  }
  | VERTICAL EXPAND {
      sprite_expand_vertical_var( _environment, ((Environment *)_environment)->currentSprite );
  }
  | VERTICAL COMPRESS {
      sprite_compress_vertical_var( _environment, ((Environment *)_environment)->currentSprite );
  }
  | EXPAND HORIZONTAL {
      sprite_expand_horizontal_var( _environment, ((Environment *)_environment)->currentSprite );
  }
  | COMPRESS HORIZONTAL {
      sprite_compress_horizontal_var( _environment, ((Environment *)_environment)->currentSprite );
  }
  | HORIZONTAL EXPAND {
      sprite_expand_horizontal_var( _environment, ((Environment *)_environment)->currentSprite );
  }
  | HORIZONTAL COMPRESS {
      sprite_compress_horizontal_var( _environment, ((Environment *)_environment)->currentSprite );
  }
  | REPLACE Identifier {
      sprite_init( _environment, $2, ((Environment *)_environment)->currentSprite, 0 )->name;
  }
  | REPLACE Identifier OP sprite_flags CP {
      sprite_init( _environment, $2, ((Environment *)_environment)->currentSprite, $4 )->name;
  };

sprite_definition_expression:
    sprite_definition_action_expression
    | sprite_definition_action_expression sprite_definition_expression;

sprite_definition:
    direct_integer {
        ((Environment *)_environment)->currentSpriteNumber = $1;
    } sprite_definition_simple
  | expr {
        ((Environment *)_environment)->currentSprite = strdup($1);
    } sprite_definition_expression
  | sprite_definition_all_simple;

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
        if ( $2 < 0 ) {
            CRITICAL_TEXTMAP_ADDRESS_NOT_VALID( $2 );
        }
        if ( $2 > 0xffff ) {
            CRITICAL_TEXTMAP_ADDRESS_NOT_VALID( $2 );
        }
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
        tilemap_enable( _environment, 0, 0, 0, 0, 0 );
    }
    | OP optional_integer CP {
        tilemap_enable( _environment, 0, 0, $2, 0, 0 );
    }
    | OP optional_integer OP_COMMA optional_integer CP {
        tilemap_enable( _environment, $2, $4, 0, 0, 0 );
    }
    | OP optional_integer OP_COMMA optional_integer OP_COMMA optional_integer CP {
        tilemap_enable( _environment, $2, $4, $6, 0, 0 );
    }
    | OP optional_integer OP_COMMA optional_integer OP_COMMA optional_integer OP_COMMA optional_integer OP_COMMA optional_integer CP {
        tilemap_enable( _environment, $2, $4, $6, $8, $10 );
    };

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
  }
  | LOAD String tile_load_flags {
        tiles_load( _environment, $2, $3, NULL, -1 );
    };
  | LOAD String TO Integer tile_load_flags {
        tiles_load( _environment, $2, $5, NULL, $4 );
    };

tiles_definition_expression:
    AT expr {
      tiles_at_var( _environment, $2 );
  };

tiles_definition:
    tiles_definition_simple
  | tiles_definition_expression;

font_definition_simple:
    LOAD String tile_load_flags {
        tiles_load( _environment, $2, $3 | FLAG_EXACT, NULL, -1 );
    };
  | LOAD String TO Integer tile_load_flags {
        tiles_load( _environment, $2, $5 | FLAG_EXACT, NULL, $4 );
    };

font_definition:
    font_definition_simple;

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
    OP_HASH const_expr OP_COMMA OP_HASH const_expr {
      screen_type_color_set( _environment, $2, $5 );
  } |  direct_integer {   
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
  | COLUMNS direct_integer {
      screen_columns( _environment, $2 );
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
  | COLUMNS expr {
      screen_columns_var( _environment, $2 );
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

as_datatype_mandatory : 
    AS datatype {
        $$ = $2;
    };

as_datatype : 
    {
        $$ = ((struct _Environment *)_environment)->defaultVariableType;
    }
    | as_datatype_mandatory;

as_datatype_suffix :
      OP_AT {
        $$ = VT_SBYTE;
    }
    | OP_PERC {
        $$ = VT_SWORD;
    }
    | OP_AMPERSAND {
        $$ = VT_SDWORD;
    }
    | OP_EXCLAMATION {
        $$ = VT_FLOAT;
    }
    | OP_DOLLAR {
        $$ = VT_DSTRING;
    }
    ;

as_datatype_suffix_optional : 
    {
        $$ = 0;
    }
    | as_datatype_suffix {
        $$ = $1;
    };

var_definition_simple:
  Identifier as_datatype {
      variable_define( _environment, $1, $2, 0 );
  }
  |
  Identifier as_datatype_suffix {
      variable_define( _environment, $1, $2, 0 );
  }
  | Identifier as_datatype OP_ASSIGN const_expr {
      variable_define( _environment, $1, $2, $4 );
      variable_store( _environment, $1, $4 );
  }
  | Identifier ON Identifier {
      variable_define( _environment, $1, VT_BYTE, 0 );
  }
  | Identifier as_datatype_suffix ON Identifier {
      if ( $2 != 0 ) {
          variable_define( _environment, $1, $2, 0 );        
      } else {
          variable_define( _environment, $1, ((struct _Environment *)_environment)->defaultVariableType, 0 );
      }
  }
  | Identifier ON Identifier OP_ASSIGN direct_integer {
      variable_define( _environment, $1, VT_BYTE, $5 );
      variable_store( _environment, $1, $5 );
  }
  | Identifier ON Identifier OP_ASSIGN expr {
      Variable * v = variable_retrieve( _environment, $5 );
      Variable * d = variable_define( _environment, $1, v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
  | Identifier as_datatype_suffix ON Identifier OP_ASSIGN expr {
      VariableType vt = $2;
      if ( vt == 0 ) {
        vt = ((struct _Environment *)_environment)->defaultVariableType;
      }
      Variable * v = variable_retrieve( _environment, $6 );
      Variable * d = variable_define( _environment, $1, vt, 0 );
      variable_move( _environment, v->name, d->name );
  }
  ;

var_definition_complex:
    var_definition_simple
    | var_definition_simple OP_COMMA var_definition_complex;

restore_definition:
    {
      restore_label( _environment, NULL );
    }
    |
    expr {
        restore_label( _environment, $1 );  
    }
  ;

cgoto_definition:
    expr {
      cgoto( _environment, $1 );
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
    var_definition_complex;

point_definition_simple:
      AT OP direct_integer OP_COMMA direct_integer CP {
        point_at( _environment, $3, $5 );
    }
    ;

point_definition_expression:
      AT OP optional_x OP_COMMA optional_y CP {
        point_at_vars( _environment, $3, $5 );
    };

point_definition:
    point_definition_simple
  | point_definition_expression;

relative_option:
    {
        $$ = 0;
    }
    | RELATIVE {
        $$ = 1;
    };

optional_x_or_string:
    RELATIVE expr {
        $$ = origin_resolution_relative_transform_x( _environment, $2, 1 )->name;
    }
    |
    expr {
        Variable * t = variable_retrieve( _environment, $1 );
        if ( ( t->type == VT_STRING ) || ( t->type == VT_DSTRING ) ) {
            $$ = $1;
        } else {
            $$ = origin_resolution_relative_transform_x( _environment, $1, 0 )->name;
        }
    }
    |
    {
        $$ = origin_resolution_relative_transform_x( _environment, NULL, 0 )->name;
    }
    ;

mandatory_x:
    relative_option expr {
        $$ = origin_resolution_relative_transform_x( _environment, $2, $1 )->name;
    };

mandatory_y:
    relative_option expr {
        $$ = origin_resolution_relative_transform_y( _environment, $2, $1 )->name;
    };

optional_x:
    relative_option expr {
        $$ = origin_resolution_relative_transform_x( _environment, $2, $1 )->name;
    }
    | {
        $$ = origin_resolution_relative_transform_x( _environment, NULL, 0 )->name;
    }
    ;

optional_y:
    relative_option expr {
        $$ = origin_resolution_relative_transform_y( _environment, $2, $1 )->name;
    }
    | {
        $$ = origin_resolution_relative_transform_y( _environment, NULL, 0 )->name;
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
        plot( _environment, $1, $3, resolve_color( _environment, $5 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $1, $3 );
    }
    | optional_x OP_COMMA optional_y {
        plot( _environment, $1, $3, NULL, 0 );
        gr_locate( _environment, $1, $3 );
    };

plot_definition:
    plot_definition_expression;

circle_definition_expression:
    optional_x OP_COMMA optional_y OP_COMMA expr OP_COMMA expr OP_COMMA optional_expr {
        ellipse( _environment, $1, $3, $5, $7, resolve_color( _environment, $9 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $1, $3 );
    }
    | optional_x OP_COMMA optional_y OP_COMMA expr OP_COMMA optional_expr {
        circle( _environment, $1, $3, $5, resolve_color( _environment, $7 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $1, $3 );
    }
    | optional_x OP_COMMA optional_y OP_COMMA expr {
        circle( _environment, $1, $3, $5, NULL, 0 );
        gr_locate( _environment, $1, $3 );
    };

circle_definition:
    circle_definition_expression;

ellipse_definition_expression:
      optional_x OP_COMMA optional_y OP_COMMA expr OP_COMMA expr OP_COMMA optional_expr {
        ellipse( _environment, $1, $3, $5, $7, resolve_color( _environment, $9 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $1, $3 );
    }
    | optional_x OP_COMMA optional_y OP_COMMA expr OP_COMMA expr {
        ellipse( _environment, $1, $3, $5, $7, NULL, 0 );
        gr_locate( _environment, $1, $3 );
    };

ellipse_definition:
    ellipse_definition_expression;

get_definition_expression:
    Identifier as_datatype_suffix_optional {
        if ( $2 != 0 ) {
            if ( $2 != VT_STRING && $2 != VT_DSTRING ) {
                CRITICAL_GET_NEED_STRING( $2 );
            }
        }
        wait_key( _environment );
        Variable * p = variable_retrieve_or_define( _environment, $1, VT_DSTRING, 0 );
        Variable * k = inkey( _environment );
        variable_move( _environment, k->name, p->name );
    }
    | OP optional_x OP_COMMA optional_y CP OP_MINUS OP expr OP_COMMA expr CP OP_COMMA expr {
        get_image( _environment, $13, $2, $4, $8, $10, NULL, NULL, 0 );
        gr_locate( _environment, $2, $4 );
    }
    | OP optional_x OP_COMMA optional_y CP OP_MINUS OP expr OP_COMMA expr CP OP_COMMA expr OP_COMMA G {
        get_image( _environment, $13, $2, $4, $8, $10, NULL, NULL, 1 );
        gr_locate( _environment, $2, $4 );
    }
    | IMAGE expr FROM optional_x OP_COMMA optional_y  {
        get_image( _environment, $2, $4, $6, NULL, NULL, NULL, NULL, 1 );
        gr_locate( _environment, $4, $6 );
    }
    | IMAGE expr frame expr FROM optional_x OP_COMMA optional_y  {
        get_image( _environment, $2, $6, $8, NULL, NULL, $4, NULL, 1 );
        gr_locate( _environment, $6, $8 );
    }
    | IMAGE expr SEQUENCE expr frame expr FROM optional_x OP_COMMA optional_y  {
        get_image( _environment, $2, $8, $10, NULL, NULL, $6, $4, 1 );
        gr_locate( _environment, $8, $10 );
    }
    | BITMAP expr FROM optional_x OP_COMMA optional_y  {
        get_image( _environment, $2, $4, $6, NULL, NULL, NULL, NULL, 0 );
        gr_locate( _environment, $4, $6 );
    }
    | BITMAP expr frame expr FROM optional_x OP_COMMA optional_y  {
        get_image( _environment, $2, $6, $8, NULL, NULL, $4, NULL, 0 );
        gr_locate( _environment, $6, $8 );
    }
    | BITMAP expr SEQUENCE expr frame expr FROM optional_x OP_COMMA optional_y  {
        get_image( _environment, $2, $8, $10, NULL, NULL, $6, $4, 1 );
        gr_locate( _environment, $8, $10 );
    }    
    ;

get_definition:
    get_definition_expression;

slice_source_options: {
        ((struct _Environment *)_environment)->sliceImageX = NULL;
        ((struct _Environment *)_environment)->sliceImageY = NULL;
    }
    |
    FROM expr OP_COMMA expr {
        ((struct _Environment *)_environment)->sliceImageX = $2;
        ((struct _Environment *)_environment)->sliceImageY = $4;
    };

slice_definition_expression:
      IMAGE expr slice_source_options TO Identifier {
        slice_image( _environment, $2, NULL, NULL, $5 );
    }
    | IMAGE expr frame expr slice_source_options TO Identifier {
        slice_image( _environment, $2, $4, NULL, $7 );
    }
    | IMAGE expr frame OP_HASH Identifier slice_source_options TO Identifier {
        Variable * images = variable_retrieve( _environment, $2 );
        Variable * calculatedFrame = calculate_frame_by_type( _environment, images->originalTileset, $2, $5 );
        slice_image( _environment, $2, calculatedFrame->name, NULL, $8 );
    }
    | IMAGE expr SEQUENCE expr frame expr slice_source_options TO Identifier {
        slice_image( _environment, $2, $6, $6, $9 );
    }
    ;

slice_definition:
    slice_definition_expression;

padding_tile:
    {
        $$ = NULL;
    }
    | PAD expr {
        $$ = $2;
    };

put_action : 
    PSET {
        $$ = 0;   
    }
    | PRESET {
        $$ = 1;
    }
    | AND {
        $$ = 2;   
    }
    | OR {
        $$ = 3;
    }
    | NOT {
        $$ = 4;
    };

put_definition_expression:
    OP optional_x OP_COMMA optional_y CP OP_MINUS OP expr OP_COMMA expr CP OP_COMMA expr {
        put_image( _environment, $13, $2, $4, $8, $10, NULL, NULL, FLAG_WITH_PALETTE );
        gr_locate( _environment, $2, $4 );
    }
    | OP optional_x OP_COMMA optional_y CP OP_MINUS OP expr OP_COMMA expr CP OP_COMMA expr OP_COMMA put_action {
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
    }
    | IMAGE expr AT optional_x OP_COMMA optional_y put_image_flags {
        $7 = $7 | FLAG_WITH_PALETTE;
        put_image( _environment, $2, $4, $6, NULL, NULL, NULL, NULL, $7 );
        gr_locate( _environment, $4, $6 );
    }
    |  IMAGE expr frame expr AT optional_x OP_COMMA optional_y put_image_flags {
        $9 = $9 | FLAG_WITH_PALETTE;
        put_image( _environment, $2, $6, $8, NULL, NULL, $4, NULL, $9 );
        gr_locate( _environment, $6, $8 );
    }
    |  IMAGE expr frame OP_HASH Identifier AT optional_x OP_COMMA optional_y put_image_flags {
        $10 = $10 | FLAG_WITH_PALETTE;
        Variable * images = variable_retrieve( _environment, $2 );
        Variable * calculatedFrame = calculate_frame_by_type( _environment, images->originalTileset, $2, $5 );
        put_image( _environment, $2, $7, $9, NULL, NULL, calculatedFrame->name, NULL, $10 );
        gr_locate( _environment, $7, $9 );
    }
    |  IMAGE expr SEQUENCE expr frame expr AT optional_x OP_COMMA optional_y put_image_flags {
        $11 = $11 | FLAG_WITH_PALETTE;
        put_image( _environment, $2, $8, $10, NULL, NULL, $6, $4, $11 );
        gr_locate( _environment, $8, $10 );
    }
    | IMAGE expr put_image_flags {
        $3 = $3 | FLAG_WITH_PALETTE;
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        put_image( _environment, $2, implicitX->name, implicitY->name, NULL, NULL, NULL, NULL, $3 );
    }
    | IMAGE expr frame expr put_image_flags {
        $5 = $5 | FLAG_WITH_PALETTE;
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        put_image( _environment, $2, implicitX->name, implicitY->name, NULL, NULL, $4, NULL, $5 );
    }
    | IMAGE expr frame OP_HASH Identifier put_image_flags {
        $6 = $6 | FLAG_WITH_PALETTE;
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        Variable * images = variable_retrieve( _environment, $2 );
        Variable * calculatedFrame = calculate_frame_by_type( _environment, images->originalTileset, $2, $5 );
        put_image( _environment, $2, implicitX->name, implicitY->name, NULL, NULL, calculatedFrame->name, NULL, $6 );
    }
    | IMAGE expr SEQUENCE expr frame expr put_image_flags {
        $7 = $7 | FLAG_WITH_PALETTE;
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        put_image( _environment, $2, implicitX->name, implicitY->name, NULL, NULL, $6, $4, $7 );
    }
    |
      BITMAP expr AT optional_x OP_COMMA optional_y put_image_flags {
        put_image( _environment, $2, $4, $6, NULL, NULL, NULL, NULL, $7 );
        gr_locate( _environment, $4, $6 );
    }
    | BITMAP expr frame expr AT optional_x OP_COMMA optional_y put_image_flags {
        put_image( _environment, $2, $6, $8, NULL, NULL, $4, NULL, $9 );
        gr_locate( _environment, $6, $8 );
    }
    | BITMAP expr frame OP_HASH Identifier AT optional_x OP_COMMA optional_y put_image_flags {
        Variable * images = variable_retrieve( _environment, $2 );
        Variable * calculatedFrame = calculate_frame_by_type( _environment, images->originalTileset, $2, $5 );
        put_image( _environment, $2, $7, $9, NULL, NULL, calculatedFrame->name, NULL, $10 );
        gr_locate( _environment, $7, $9 );
    }
    | BITMAP expr SEQUENCE expr frame expr AT optional_x OP_COMMA optional_y put_image_flags {
        put_image( _environment, $2, $8, $10, NULL, NULL, $6, $4, $11 );
        gr_locate( _environment, $8, $10 );
    }
    | BITMAP expr put_image_flags {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        put_image( _environment, $2, implicitX->name, implicitY->name, NULL, NULL, NULL, NULL, $3 );
    }
    | BITMAP expr frame expr put_image_flags {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        put_image( _environment, $2, implicitX->name, implicitY->name, NULL, NULL, $4, NULL, $5 );
    }
    | BITMAP expr frame OP_HASH Identifier put_image_flags {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        Variable * images = variable_retrieve( _environment, $2 );
        Variable * calculatedFrame = calculate_frame_by_type( _environment, images->originalTileset, $2, $5 );
        put_image( _environment, $2, implicitX->name, implicitY->name, NULL, NULL, calculatedFrame->name, NULL, $6 );
    }
    | BITMAP expr SEQUENCE expr frame expr put_image_flags {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        put_image( _environment, $2, implicitX->name, implicitY->name, NULL, NULL, $6, $4, $7 );
    }
    | TILE expr AT optional_x OP_COMMA optional_y {
        put_tile( _environment, $2, $4, $6, NULL, NULL );
    }
    | TILEMAP Identifier padding_tile put_image_flags {
        $4 = $4 | FLAG_WITH_PALETTE;
        put_tilemap_vars( _environment, $2, $4, NULL, NULL, NULL, $3 );
    }
    | TILEMAP Identifier padding_tile LAYER expr put_image_flags {
        $6 = $6 | FLAG_WITH_PALETTE;
        put_tilemap_vars( _environment, $2, $6, NULL, NULL, $5, $3 );
    }
    | TILEMAP Identifier padding_tile FROM expr OP_COMMA expr put_image_flags {
        $8 = $8 | FLAG_WITH_PALETTE;
        put_tilemap_vars( _environment, $2, $8, $5, $7, NULL, $3 );
    }
    | TILEMAP Identifier padding_tile LAYER expr FROM expr OP_COMMA expr put_image_flags {
        $10 = $10 | FLAG_WITH_PALETTE;
        put_tilemap_vars( _environment, $2, $10, $7, $9, $5, $3 );
    }
    ;

put_definition:
    put_definition_expression;

blit_unary_op:
    COPY {
        $$ = 1 << ((struct _Environment *)_environment)->currentModeBW;
    }
    | INVERSE {
        $$ = ( 1 << ((struct _Environment *)_environment)->currentModeBW ) + 1;
    }
    | VALUE const_expr {
        $$ = $2 & ( ( 1 << ((struct _Environment *)_environment)->currentModeBW ) - 1 );
    }
    | IGNORE {
        $$ = ( 1 << ((struct _Environment *)_environment)->currentModeBW ) + 2;
    }
    | THRESHOLD {
        $$ = ( 1 << ((struct _Environment *)_environment)->currentModeBW ) + 3;
    }
    ;

blit_binary_op:
    AND {
        $$ = 0;
    }
    | OR {
        $$ = 1;
    }
    | XOR {
        $$ = 2;
    }
    | A {
        $$ = 3;
    }
    | B {
        $$ = 4;
    }
    | COPY A {
        $$ = 3;
    }
    | COPY B {
        $$ = 4;
    }
    | MASKED {
        $$ = 5;
    }
    ;

blit_operand :
    SOURCE {
        $$ = 1;
    }
    | SOURCE Integer {
        $$ = $2;
    }
    | DESTINATION {
        $$ = 0 ;
    }
    ;

blit_sources :
    Identifier {
        ((struct _Environment *)_environment)->blit.sources[((struct _Environment *)_environment)->blit.sourceCount++] = strdup( $1 );
    }
    | Identifier {
        ((struct _Environment *)_environment)->blit.sources[((struct _Environment *)_environment)->blit.sourceCount++] = strdup( $1 );
    } OP_COMMA blit_sources
    ;

blit_expression :
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
        //printf( "( O%2.2x (R%2.2X) ) -> R%2.2x\n", $2, operand, result );
        $$ = result;

    }
    | OP blit_unary_op blit_operand CP {
        // Take a free register for operand
        int operand = cpu_blit_alloc_register( _environment );
        blit_define_compound_operand_to_register( _environment, operand, $3 );
        // Take a free register for result
        int result = cpu_blit_alloc_register( _environment );
        // U ( operand ) -> result
        blit_define_compound_unary( _environment, $2, operand, result );
        // Free operand
        cpu_blit_free_register( _environment, operand );
        //printf( "*( [%2.2x] O%2.2x (R%2.2x) ) -> R%2.2x\n", $2, $3, operand, result );
        $$ = result;
    }
    | OP blit_operand blit_binary_op blit_operand CP {
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
        //printf( "( O%2.2x R%2.2x [%2.2x] O%2.2x R%2.2x ) -> R%2.2x\n", $2, operand1, $3, $4, operand2, result );
        $$ = result;
    }
    ;

blit_compounded :
    blit_expression {
        //printf( "R%2.2x -> R%2.2x\n", $1, $1 );
        // Pass result register
        $$ = $1;
    }
    | OP blit_compounded CP {
        //printf( "(R%2.2x) -> R%2.2x \n", $2, $2 );
        // Pass result register
        $$ = $2;
    }
    | OP blit_unary_op blit_compounded CP {
        // Take a free register for result
        int result = cpu_blit_alloc_register( _environment );
        // B ( result1, result2 ) -> result
        blit_define_compound_unary( _environment, $2, $3, result );
        // Pass result register
        //printf( "( [%2.2x] R%2.2x) -> R%2.2x\n", $2, $3, result );
        $$ = result;
    }
    | OP blit_compounded blit_binary_op blit_compounded CP {
        // Take a free register for result
        int result = cpu_blit_alloc_register( _environment );
        // B ( result1, result2 ) -> result
        blit_define_compound_binary( _environment, $3, $2, $4, result );
        // Pass result register
        //printf( "( R%2.2x [%2.2x] R%2.2x) -> R%2.2x\n", $2, $3, $4, result );
        $$ = result;
    }
    ;

op_assign : 
    OP_ASSIGN 
    | OP_ASSIGN_DIRECT
    ;

blit_definition_define_expression : 
    Identifier AS {
        //printf( "\n\n%s\n", $1 );
        blit_define_begin_compound( _environment, $1 );  
    } blit_compounded {
        //printf( "R%2.2x -> final\n\n", $4 );
        blit_define_end_compound( _environment, $4 );
      }
    | Identifier op_assign blit_unary_op OP_COMMA blit_unary_op OP_COMMA blit_binary_op OP_COMMA blit_unary_op OP_COMMA blit_unary_op OP_COMMA blit_binary_op OP_COMMA blit_unary_op {
        blit_define( _environment, $1, $3, $5, $7, $9, $11, $13, $15 );
      }
    ;

image_or_images : 
    IMAGE | IMAGES | ATLAS
    ;

bitmap_or_bitmaps : 
    BITMAP | BITMAPS
    ;

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

move_definition_expression:
      TILE expr AT optional_x OP_COMMA optional_y {
        move_tile( _environment, $2, $4, $6 );
    }
    ;

move_definition:
    move_definition_expression;

line_mode : 
    {
        $$ = 0;
    }
    | PSET {
        $$ = 0;
    }
    | PRESET {
        $$ = 1;
    };

box_mode : 
    {
        $$ = 0;
    }
    | B {
        $$ = 1;
    }
    | BF {
        $$ = 2;
    };

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
    | optional_x_or_string {
        draw_string( _environment, $1 );
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
    ;

line_definition:
    line_definition_expression;

draw_definition_expression:
    OP expr OP_COMMA expr CP OP_MINUS OP expr OP_COMMA expr CP {
        draw( _environment, $2, $4, $8, $10, NULL, 0 );
        gr_locate( _environment, $8, $10 );
    }
    | OP expr OP_COMMA expr CP OP_MINUS OP expr OP_COMMA expr CP OP_COMMA line_mode {
        Variable * zero = variable_temporary( _environment, VT_BYTE, "(zero)" );
        variable_store( _environment, zero->name, 0 );
        draw( _environment, $2, $4, $8, $10, $13 == 0 ? NULL : color_get_vars( _environment, zero->name )->name, 0 );
        gr_locate( _environment, $8, $10 );
    }
    | OP expr OP_COMMA expr CP OP_MINUS OP expr OP_COMMA expr CP OP_COMMA expr {
        Variable * zero = variable_temporary( _environment, VT_BYTE, "(zero)" );
        variable_store( _environment, zero->name, 0 );
        draw( _environment, $2, $4, $8, $10, resolve_color( _environment, $13 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $8, $10 );
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
    | optional_x_or_string {
        draw_string( _environment, $1 );
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
    };

draw_tile_definition_expression:
      expr ROW expr OP_COMMA expr TO expr OP_COMMA optional_expr {
        draw_tile_row( _environment, $1, $3, $5, $7, $9 );
    }
    | expr ROW expr OP_COMMA expr TO expr  {
        draw_tile_row( _environment, $1, $3, $5, $7, NULL );
    }
    | expr COLUMN expr OP_COMMA expr TO expr OP_COMMA optional_expr {
        draw_tile_column( _environment, $1, $3, $5, $7, $9 );
    }
    | expr COLUMN expr OP_COMMA expr TO expr  {
        draw_tile_column( _environment, $1, $3, $5, $7, NULL );
    };

draw_definition:
    draw_definition_expression;

draw_tile_definition: 
    draw_tile_definition_expression;

box_definition_expression:
    optional_x OP_COMMA optional_y TO optional_x OP_COMMA optional_y OP_COMMA optional_expr {
        box( _environment, $1, $3, $5, $7, resolve_color( _environment, $9 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $5, $7 );
    }
    | optional_x OP_COMMA optional_y TO optional_x OP_COMMA optional_y  {
        box( _environment, $1, $3, $5, $7, NULL, 0 );
        gr_locate( _environment, $5, $7 );
    }
    | TO optional_x OP_COMMA optional_y OP_COMMA optional_expr {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        box( _environment, implicitX->name, implicitY->name, $2, $4, resolve_color( _environment, $6 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $2, $4 );
    }
    | TO optional_x OP_COMMA optional_y  {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        box( _environment, implicitX->name, implicitY->name, $2, $4, NULL, 0 );
        gr_locate( _environment, $2, $4 );
    };

box_definition:
    box_definition_expression;

rec_definition_expression:
    mandatory_x OP_COMMA mandatory_y OP_COMMA expr OP_COMMA expr OP_COMMA expr  {
        Variable * x2 = variable_add( _environment, $1, variable_retrieve_or_define( _environment, $5, VT_POSITION, 0 )->name );
        Variable * y2 = variable_add( _environment, $3, variable_retrieve_or_define( _environment, $7, VT_POSITION, 0 )->name );
        box( _environment, $1, $3, x2->name, y2->name, resolve_color( _environment, $9 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, x2->name, y2->name );
    };

rec_definition:
    rec_definition_expression;

console_definition_simple :
    OFF {
        console( _environment, 0, 0, ((struct _Environment *)_environment)->screenTilesWidth-1, ((struct _Environment *)_environment)->screenTilesHeight-1 );
    }
    | OP_HASH const_expr OP_COMMA OP_HASH const_expr TO OP_HASH const_expr OP_COMMA OP_HASH const_expr {
        console( _environment, $2, $5, $8, $11 );        
    }
    | OP_HASH const_expr OP_COMMA OP_HASH const_expr OP_COMMA OP_HASH const_expr OP_COMMA OP_HASH const_expr {
        console( _environment, $2, $5, $8, $11 );        
    }
    | SAVE OP_HASH const_expr {
        console_save( _environment, $3 );
    }
    | RESTORE OP_HASH const_expr {
        console_restore( _environment, $3 );
    }
    | USE OP_HASH const_expr {
        console_restore( _environment, $3 );
    }
    ;

console_definition_expression :
    expr OP_COMMA expr TO expr OP_COMMA expr {
        console_vars( _environment, $1, $3, $5, $7 );
    }
    | expr OP_COMMA expr OP_COMMA expr OP_COMMA expr {
        console_vars( _environment, $1, $3, $5, $7 );
    }
    | SAVE expr {
        console_save_vars( _environment, $2 );
    }
    | RESTORE expr {
        console_restore_vars( _environment, $2 );
    }
    | USE expr {
        console_restore_vars( _environment, $2 );
    }
    ;

console_definition:
    console_definition_simple
    | console_definition_expression;

bar_definition_expression:
    optional_x OP_COMMA optional_y TO optional_x OP_COMMA optional_y OP_COMMA optional_expr {
        bar( _environment, $1, $3, $5, $7, resolve_color( _environment, $9 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $5, $7 );
    }
    | optional_x OP_COMMA optional_y TO optional_x OP_COMMA optional_y  {
        bar( _environment, $1, $3, $5, $7, NULL, 0 );
        gr_locate( _environment, $5, $7 );
    }
    | TO optional_x OP_COMMA optional_y OP_COMMA optional_expr {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        bar( _environment, implicitX->name, implicitY->name, $2, $4, resolve_color( _environment, $6 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $2, $4 );
    }
    | TO optional_x OP_COMMA optional_y  {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        bar( _environment, implicitX->name, implicitY->name, $2, $4, NULL, 0 );
        gr_locate( _environment, $2, $4 );
    };

bar_definition:
    bar_definition_expression;

block_definition_expression:
    mandatory_x OP_COMMA mandatory_y OP_COMMA mandatory_x OP_COMMA mandatory_y OP_COMMA expr  {
        bar( _environment, $1, $3, $5, $7, resolve_color( _environment, $9 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $5, $7 );
    };

block_definition:
    block_definition_expression;

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
    } polyline_definition_expression_continue
    | TO optional_x OP_COMMA optional_y  {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        draw( _environment, implicitX->name, implicitY->name, $2, $4, NULL, 0 );
        gr_locate( _environment, $2, $4 );
    };

polyline_definition_expression:
      optional_x OP_COMMA optional_y TO optional_x OP_COMMA optional_y OP_COMMA optional_expr {
        draw( _environment, $1, $3, $5, $7, resolve_color( _environment, $9 ), ((Environment *)_environment)->colorImplicit );
        gr_locate( _environment, $5, $7 );
    }
    | optional_x OP_COMMA optional_y TO optional_x OP_COMMA optional_y  {
        draw( _environment, $1, $3, $5, $7, NULL, 0 );
        gr_locate( _environment, $5, $7 );
    }
    | optional_x OP_COMMA optional_y TO optional_x OP_COMMA optional_y  {
        draw( _environment, $1, $3, $5, $7, NULL, 0 );
        gr_locate( _environment, $5, $7 );
    } polyline_definition_expression_continue
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
    | TO optional_x OP_COMMA optional_y  {
        Variable * implicitX = origin_resolution_relative_transform_x( _environment, NULL, 0 );
        Variable * implicitY = origin_resolution_relative_transform_y( _environment, NULL, 0 );
        draw( _environment, implicitX->name, implicitY->name, $2, $4, NULL, 0 );
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
    |
      Integer {
          on_goto_number( _environment, $1 );
          on_goto_end( _environment );
      }
    | Identifier {
        on_goto_index( _environment, $1 );
    } OP_COMMA on_goto_definition
    | Integer {
        on_goto_number( _environment, $1 );
    } OP_COMMA on_goto_definition;

on_gosub_definition:
      Identifier {
          on_gosub_index( _environment, $1 );
          on_gosub_end( _environment );
      }
    | Integer {
          on_gosub_number( _environment, $1 );
          on_gosub_end( _environment );
      }
    | Identifier {
          on_gosub_index( _environment, $1 );
    } OP_COMMA on_gosub_definition
    | Integer {
          on_gosub_number( _environment, $1 );
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
      SCROLL LEFT COLUMN GOSUB Identifier {
        scroll( _environment, 0, 0 );
        on_scroll_gosub( _environment, -1, 0, $5 );
    }
    | SCROLL RIGHT COLUMN GOSUB Identifier {
        scroll( _environment, 0, 0 );
        on_scroll_gosub( _environment, 1, 0, $5 );
    }
    | SCROLL UP ROW GOSUB Identifier {
        scroll( _environment, 0, 0 );
        on_scroll_gosub( _environment, 0, -1, $5 );
    }
    | SCROLL DOWN ROW GOSUB Identifier {
        scroll( _environment, 0, 0 );
        on_scroll_gosub( _environment, 0, 1, $5 );
    }
    | SCROLL LEFT COLUMN CALL Identifier {
        scroll( _environment, 0, 0 );
        on_scroll_call( _environment, -1, 0, $5 );
    }
    | SCROLL RIGHT COLUMN CALL Identifier {
        scroll( _environment, 0, 0 );
        on_scroll_call( _environment, 1, 0, $5 );
    }
    | SCROLL UP ROW CALL Identifier {
        scroll( _environment, 0, 0 );
        on_scroll_call( _environment, 0, -1, $5 );
    }
    | SCROLL DOWN ROW CALL Identifier {
        scroll( _environment, 0, 0 );
        on_scroll_call( _environment, 0, 1, $5 );
    }
    | expr GOTO {
          on_goto( _environment, $1 );
      } on_goto_definition
    | expr PROC {
          on_proc( _environment, $1 );
      } on_proc_definition
    | expr GOSUB {
        on_gosub( _environment, $1 );  
    } on_gosub_definition;

timer_number_comma:
    {
        $$ = NULL;
    }
    | OP_COMMA expr {
        $$ = $2;
    };

timer_number:
    {
        $$ = NULL;
    }
    | expr {
        $$ = $1;
    };

every_definition :
      expr ticks timer_number_comma GOSUB Identifier on_targets {
        if ( $6 ) {
          every_ticks_gosub( _environment, $1, $5, $3 );
        }
    }
    | expr ticks timer_number_comma CALL Identifier on_targets {
        if ( $6 ) {
          every_ticks_call( _environment, $1, $5, $3 );
        }
    }
    | ON timer_number on_targets {
        if ( $3 ) {
          every_on( _environment, $2 );
        }
    }
    | OFF timer_number on_targets {
        if ( $3 ) {
          every_off( _environment, $2 );
        }
    };

after_definition :
      expr ticks timer_number_comma GOSUB Identifier on_targets {
        if ( $6 ) {
          every_ticks_gosub( _environment, $1, $5, $3 );
          every_on( _environment, $3 );
        }
    }
    | expr ticks timer_number_comma CALL Identifier on_targets {
        if ( $6 ) {
          every_ticks_call( _environment, $1, $5, $3 );
          every_on( _environment, $3 );
        }
    };

limits: 
    {
        ((struct _Environment *)_environment)->upperLimit = NULL;
        ((struct _Environment *)_environment)->lowerLimit = NULL;
    }
    | OP_COMMA expr TO expr {
        ((struct _Environment *)_environment)->upperLimit = $2;
        ((struct _Environment *)_environment)->lowerLimit = $4;
    };

add_definition :
    Identifier OP_COMMA expr {
        variable_add_inplace_vars( _environment, $1, $3 );
    }
    | Identifier OP_COMMA OP_HASH const_expr {
        variable_add_inplace( _environment, $1, $4 );
    }
    | Identifier OP_COMMA expr OP_COMMA expr TO expr {
        add_complex_vars( _environment, $1, $3, $5, $7 );
    }
    | Identifier OP_COMMA OP_HASH const_expr OP_COMMA OP_HASH const_expr TO OP_HASH const_expr {
        add_complex( _environment, $1, $4, $7, $10 );
    }
    | OSP Identifier CSP OP_COMMA expr {
        variable_add_inplace_mt( _environment, $2, $5 );
    }
    | OSP Identifier CSP OP_COMMA expr OP_COMMA expr TO expr {
        add_complex_mt( _environment, $2, $5, $7, $9 );
    }
    | Identifier OP {
        parser_array_init( _environment );
    } indexes CP OP_COMMA expr limits {
        add_complex_array( _environment, $1, $7, ((struct _Environment *)_environment)->lowerLimit, ((struct _Environment *)_environment)->upperLimit );
        parser_array_cleanup( _environment );
    }
    ;

swap_definition :
    Identifier as_datatype_suffix_optional OP_COMMA Identifier as_datatype_suffix_optional {
        if ( $2 != $5 ) {
            CRITICAL_CANNOT_SWAP_DIFFERENT_DATATYPES( $1, $4 );
        }
        variable_swap( _environment, $1, $4 );
    }
    ;

perc :
    |
    OP_PERC;

mul_definition :
    Identifier perc OP_COMMA expr {
        variable_move( _environment, variable_mul( _environment, $1, $4 )->name, $1 );
    }
    ;

div_definition :
    Identifier perc OP_COMMA expr {
        variable_move( _environment, variable_div( _environment, $1, $4, NULL )->name, $1 );
    }
    |
    Identifier perc OP_COMMA OP_HASH const_expr {
        if ( log2($5) != (int)log2($5) ) {
            Variable * v = variable_retrieve( _environment, $1 );
            Variable * temporary = variable_temporary( _environment, v->type, "(temp)" );
            variable_store( _environment, v->name, $5 );
            variable_move( _environment, variable_div( _environment, $1, temporary->name, NULL )->name, $1 );
        } else {
            variable_move( _environment, variable_div2_const( _environment, $1, log2($5) )->name, $1 );
        }
    }
    |
    Identifier perc OP_COMMA expr OP_COMMA Identifier perc {
        variable_retrieve_or_define( _environment, $6, ((struct _Environment *)_environment)->defaultVariableType, 0);
        variable_move( _environment, variable_div( _environment, $1, $4, $6 )->name, $1 );
    }
    ;

dimensions :
    {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = -1;
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
    | const_expr {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = $1;
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
    | const_expr OP_COMMA dimensions {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = $1;
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
    ;

datatype : 
    BIT {
        $$ = VT_BIT;
    }
    | BYTE {
        $$ = VT_BYTE;
    }
    | SIGNED BYTE {
        $$ = VT_SBYTE;
    }
    | WORD {
        $$ = VT_WORD;
    }
    | INT {
        $$ = VT_SWORD;
    }
    | INTEGER {
        $$ = VT_SWORD;
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
    | LONG {
        $$ = VT_SDWORD;
    }
    | FLOAT {
        $$ = VT_FLOAT;
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
    | COLOUR {
        $$ = VT_COLOR;
    }
    | STRING {
        $$ = VT_DSTRING;
    }
    | IMAGE {
        $$ = VT_IMAGE;
    }
    | IMAGES {
        $$ = VT_IMAGES;
    }
    | ATLAS {
        $$ = VT_IMAGES;
    }
    | SEQUENCE {
        $$ = VT_SEQUENCE;
    }
    | MUSIC {
        $$ = VT_MUSIC;
    }
    | BLIT {
        $$ = VT_BLIT;
    }
    | SPRITE {
        $$ = VT_SPRITE;
    }
    | MSPRITE {
        $$ = VT_MSPRITE;
    }
    | TILE {
        $$ = VT_TILE;
    }
    | TILES {
        $$ = VT_TILES;
    }
    | TILESET {
        $$ = VT_TILESET;
    }
    | TILEMAP {
        $$ = VT_TILEMAP;
    }
    | BUFFER {
        $$ = VT_BUFFER;
    }
    | TASK {
        $$ = VT_THREAD;
    }
    | THREAD {
        $$ = VT_THREAD;
    };

const_array_definition :
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
    }
    | const_expr_floating {
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
    const_array_definition {

    }
    | const_array_definition {
        
    } OP_COMMA const_array_definitions1;

const_array_definitions : 
    {

    }
    | const_array_definitions1 {

    };

array_assign:
    {
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
    | WITH const_expr {
        ((struct _Environment *)_environment)->currentArray->value = $2;
        if ( ! ((struct _Environment *)_environment)->currentArray->memoryArea ) {
            memory_area_assign( ((struct _Environment *)_environment)->memoryAreas, ((struct _Environment *)_environment)->currentArray );
        }
        if ( ((struct _Environment *)_environment)->currentArray->memoryArea ) {
            variable_store( _environment, ((struct _Environment *)_environment)->currentArray->name, ((struct _Environment *)_environment)->currentArray->value );
        }
    }
    | OP_ASSIGN BufferDefinitionHex {
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
    | OP_ASSIGN LOAD String AS TEXT {

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

                current->value = atoi( valueString );

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

        } else {

            ((struct _Environment *)_environment)->currentArray->arrayInitialization = NULL;

            ((struct _Environment *)_environment)->currentArray->arrayInitialization = malloc( sizeof( Constant ) );
            memset( ((struct _Environment *)_environment)->currentArray->arrayInitialization, 0, sizeof( Constant ) );
            ((struct _Environment *)_environment)->currentArray->size = 1;
            ((struct _Environment *)_environment)->currentArray->valueBuffer = malloc(1);

        }

    }
    | OP_ASSIGN LOAD String AS BINARY {
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
    | OP_ASSIGN {
        Variable *currentArray = ((struct _Environment *)_environment)->currentArray;
        currentArray->arrayInitialization = NULL;
        if ( VT_BITWIDTH( currentArray->arrayType ) == 0 && currentArray->arrayType != VT_FLOAT ) {
            CRITICAL_ARRAY_ASSIGN_DATATYPE_NOT_SUPPORTED( currentArray->name );
        }
    } OP_HASH OGP const_array_definitions CGP {
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
    };

array_reassign:
    BufferDefinitionHex {
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

readonly_optional : 
    {
        $$ = 0;
    }
    | READONLY {
        $$ = 1;
    }
    | READ ONLY {
        $$ = 1;
    };

dim_definition :
    Identifier datatype {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      } OP dimensions CP {
        ((struct _Environment *)_environment)->currentArray = variable_define( _environment, $1, VT_TARRAY, 0 );
        variable_array_type( _environment, $1, $2 );
    } array_assign readonly_optional on_bank {
        Variable * array = variable_retrieve( _environment, $1 );
        array->readonly = $9;
        if ( $10 ) {
            if ( ! banks_store( _environment, array, $10 ) ) {
                CRITICAL_STORAGE_BANKED_OUT_OF_MEMORY( array->name );
            };
        }
    }
    as_datatype_suffix
    |
    Identifier as_datatype_suffix_optional {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      } OP dimensions CP {
        ((struct _Environment *)_environment)->currentArray = variable_define( _environment, $1, VT_TARRAY, 0 );
    } as_datatype {
        if ( $2 ) {
            variable_array_type( _environment, $1, $2 );
        } else {
            variable_array_type( _environment, $1, $8 );
        }
    } array_assign readonly_optional on_bank {
        Variable * array = variable_retrieve( _environment, $1 );
        array->readonly = $11;
        if ( $12 ) {
            if ( ! banks_store( _environment, array, $12 ) ) {
                CRITICAL_STORAGE_BANKED_OUT_OF_MEMORY( array->name );
            };
        }        
    }
    | Identifier WITH const_expr {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      } OP dimensions CP {
        ((struct _Environment *)_environment)->currentArray = variable_define( _environment,  $1, VT_TARRAY, 0 );
        ((struct _Environment *)_environment)->currentArray->value = $3;
        variable_array_type( _environment, $1, ((struct _Environment *)_environment)->defaultVariableType );
        if ( ! ((struct _Environment *)_environment)->currentArray->memoryArea ) {
            memory_area_assign( ((struct _Environment *)_environment)->memoryAreas, ((struct _Environment *)_environment)->currentArray );
        }
        if ( ((struct _Environment *)_environment)->currentArray->memoryArea ) {
            variable_store( _environment, ((struct _Environment *)_environment)->currentArray->name, ((struct _Environment *)_environment)->currentArray->value );
        }
      } readonly_optional on_bank {
        Variable * array = variable_retrieve( _environment, $1 );
        array->readonly = $9;
        if ( $10 ) {
            if ( ! banks_store( _environment, array, $10 ) ) {
                CRITICAL_STORAGE_BANKED_OUT_OF_MEMORY( array->name );
            };
        }        
    }
    | Identifier datatype WITH const_expr {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      } OP dimensions CP {
        ((struct _Environment *)_environment)->currentArray = variable_define( _environment, $1, VT_TARRAY, 0 );
        ((struct _Environment *)_environment)->currentArray->value = $4;
        variable_array_type( _environment, $1, $2 );
        if ( ! ((struct _Environment *)_environment)->currentArray->memoryArea ) {
            memory_area_assign( ((struct _Environment *)_environment)->memoryAreas, ((struct _Environment *)_environment)->currentArray );
        }
        if ( ((struct _Environment *)_environment)->currentArray->memoryArea ) {
            variable_store( _environment, ((struct _Environment *)_environment)->currentArray->name, ((struct _Environment *)_environment)->currentArray->value );
        }
      } readonly_optional on_bank {
        Variable * array = variable_retrieve( _environment, $1 );
        array->readonly = $10;
        if ( $11 ) {
            if ( ! banks_store( _environment, array, $11 ) ) {
                CRITICAL_STORAGE_BANKED_OUT_OF_MEMORY( array->name );
            };
        }        
    }
    | Identifier as_datatype_mandatory {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      } OP dimensions CP as_datatype {
        ((struct _Environment *)_environment)->currentArray = variable_define( _environment, $1, VT_TARRAY, 0 );
        variable_array_type( _environment, $1, ( $7 == ((struct _Environment *)_environment)->defaultVariableType ) ? $2 : $7 );
    } array_assign readonly_optional on_bank {
        Variable * array = variable_retrieve( _environment, $1 );
        array->readonly = $10;
        if ( $11 ) {
            if ( ! banks_store( _environment, array, $11 ) ) {
                CRITICAL_STORAGE_BANKED_OUT_OF_MEMORY( array->name );
            };
        }        
    }
    | Identifier as_datatype_mandatory WITH const_expr {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      } OP dimensions CP {
        ((struct _Environment *)_environment)->currentArray = variable_define( _environment, $1, VT_TARRAY, 0 );
        ((struct _Environment *)_environment)->currentArray->value = $4;
        variable_array_type( _environment, $1, $2 );
        if ( ! ((struct _Environment *)_environment)->currentArray->memoryArea ) {
            memory_area_assign( ((struct _Environment *)_environment)->memoryAreas, ((struct _Environment *)_environment)->currentArray );
        }
        if ( ((struct _Environment *)_environment)->currentArray->memoryArea ) {
            variable_store( _environment, ((struct _Environment *)_environment)->currentArray->name, ((struct _Environment *)_environment)->currentArray->value );
        }
    } readonly_optional on_bank {
        Variable * array = variable_retrieve( _environment, $1 );
        array->readonly = $10;
        if ( $11 ) {
            if ( ! banks_store( _environment, array, $11 ) ) {
                CRITICAL_STORAGE_BANKED_OUT_OF_MEMORY( array->name );
            };
        }        
    }
    ;

dim_definitions :
      var_definition
    | dim_definition
    | dim_definition OP_COMMA dim_definitions
    ;

fill_definition_array :
    Identifier WITH const_expr {
        variable_array_fill( _environment, $1, $3 );
    }
    ;

fill_definitions_array :
      fill_definition_array
    | fill_definition_array OP_COMMA fill_definitions_array

fill_definition :
    expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr {
        fill( _environment, $1, $3, $5, $7, $9, $11 );
    };

fill_definitions :
    fill_definitions_array
    | fill_definition
    ;

indexes :
      expr {
        Variable * expr = variable_retrieve( _environment, $1 );
        if ( expr->initializedByConstant ) {
            parser_array_index_numeric( _environment, expr->value );
        } else {
            parser_array_index_symbolic( _environment, $1 );
        }
    }
    | expr OP_COMMA indexes {
        Variable * expr = variable_retrieve( _environment, $1 );
        if ( expr->initializedByConstant ) {
            parser_array_index_numeric( _environment, expr->value );
        } else {
            parser_array_index_symbolic( _environment, $1 );
        }
    }
    | OP_HASH const_expr {
        parser_array_index_numeric( _environment, $2 );
    }
    | OP_HASH const_expr OP_COMMA indexes {
        parser_array_index_numeric( _environment, $2 );
    }
    ;

parameters : 
    Identifier OP_DOLLAR {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_DSTRING;
          ++((struct _Environment *)_environment)->parameters;
    }
    | Identifier as_datatype {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = $2;
          ++((struct _Environment *)_environment)->parameters;
    }
    | Identifier OP_DOLLAR OP_COMMA parameters {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_DSTRING;
          ++((struct _Environment *)_environment)->parameters;
    }
    | Identifier as_datatype OP_COMMA parameters {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = $2;
          ++((struct _Environment *)_environment)->parameters;
    }
    ;

parameters_expr : 
    Identifier OP_DOLLAR {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_DSTRING;
          ++((struct _Environment *)_environment)->parameters;
    }
    | Identifier as_datatype {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = $2;
          ++((struct _Environment *)_environment)->parameters;
    }
    | Identifier OP_DOLLAR OP_COMMA parameters_expr {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_DSTRING;
          ++((struct _Environment *)_environment)->parameters;
    }
    | Identifier as_datatype OP_COMMA parameters_expr {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = $2;
          ++((struct _Environment *)_environment)->parameters;
    }
    | String {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ++((struct _Environment *)_environment)->parameters;
    }
    | RawString {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ++((struct _Environment *)_environment)->parameters;
    }
    | String OP_COMMA parameters_expr {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ++((struct _Environment *)_environment)->parameters;
    }
    | RawString OP_COMMA parameters_expr {
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

asmio : 
    Register {
        $$ = cpu_register_decode( _environment, $1 );
    }
    | STACK OP BYTE CP {
        $$ = (int)STACK_BYTE;
    }
    | STACK OP WORD CP {
        $$ = (int)STACK_WORD;
    }
    | STACK OP DWORD CP {
        $$ = (int)STACK_DWORD;
    }
    ;

values_asmios :
      asmio OP_ASSIGN expr {
          ((struct _Environment *)_environment)->parametersAsmioEach[((struct _Environment *)_environment)->parameters] = $1;
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $3 );
          ++((struct _Environment *)_environment)->parameters;
    }
    | asmio OP_ASSIGN expr OP_COMMA values_asmios {
          ((struct _Environment *)_environment)->parametersAsmioEach[((struct _Environment *)_environment)->parameters] = $1;
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $3 );
          ++((struct _Environment *)_environment)->parameters;
    }
    | asmio OP_ASSIGN OP_HASH const_expr {
          ((struct _Environment *)_environment)->parametersAsmioEach[((struct _Environment *)_environment)->parameters] = $1;
          ((struct _Environment *)_environment)->parametersValueEach[((struct _Environment *)_environment)->parameters] = $4;
          ++((struct _Environment *)_environment)->parameters;
    }
    | asmio OP_ASSIGN OP_HASH const_expr OP_COMMA values_asmios {
          ((struct _Environment *)_environment)->parametersAsmioEach[((struct _Environment *)_environment)->parameters] = $1;
          ((struct _Environment *)_environment)->parametersValueEach[((struct _Environment *)_environment)->parameters] = $4;
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = NULL;
          ++((struct _Environment *)_environment)->parameters;
    }
    ;

parameters_asmios :
      Identifier as_datatype ON asmio {
          ((struct _Environment *)_environment)->parametersAsmioEach[((struct _Environment *)_environment)->parameters] = $4;
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = $2;
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ++((struct _Environment *)_environment)->parameters;
    }
    | Identifier as_datatype ON asmio {
          ((struct _Environment *)_environment)->parametersAsmioEach[((struct _Environment *)_environment)->parameters] = $4;
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = $2;
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( $1 );
          ++((struct _Environment *)_environment)->parameters;
    } OP_COMMA parameters_asmios
    | OP_HASH const_expr ON asmio {
          ((struct _Environment *)_environment)->parametersAsmioEach[((struct _Environment *)_environment)->parameters] = $4;
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = -1;
          ((struct _Environment *)_environment)->parametersValueEach[((struct _Environment *)_environment)->parameters] = $2;
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = NULL;
          ++((struct _Environment *)_environment)->parameters;
    }
    | OP_HASH const_expr ON asmio  {
          ((struct _Environment *)_environment)->parametersAsmioEach[((struct _Environment *)_environment)->parameters] = $4;
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = -1;
          ((struct _Environment *)_environment)->parametersValueEach[((struct _Environment *)_environment)->parameters] = $2;
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = NULL;
          ++((struct _Environment *)_environment)->parameters;
    } OP_COMMA parameters_asmios
    | OUT Identifier as_datatype ON asmio {
          ((struct _Environment *)_environment)->returnsAsmioEach[((struct _Environment *)_environment)->returns] = $5;
          ((struct _Environment *)_environment)->returnsTypeEach[((struct _Environment *)_environment)->returns] = $3;
          ((struct _Environment *)_environment)->returnsEach[((struct _Environment *)_environment)->returns] = strdup( $2 );
          ++((struct _Environment *)_environment)->returns;
    }
    | OUT Identifier as_datatype ON asmio {
          ((struct _Environment *)_environment)->returnsAsmioEach[((struct _Environment *)_environment)->returns] = $5;
          ((struct _Environment *)_environment)->returnsTypeEach[((struct _Environment *)_environment)->returns] = $3;
          ((struct _Environment *)_environment)->returnsEach[((struct _Environment *)_environment)->returns] = strdup( $2 );
          ++((struct _Environment *)_environment)->returns;
    } OP_COMMA parameters_asmios

    ;

return_parameter_asmios2 : 
    asmio as_datatype {
          ((struct _Environment *)_environment)->returnsAsmioEach[((struct _Environment *)_environment)->returns] = $1;
          ((struct _Environment *)_environment)->returnsTypeEach[((struct _Environment *)_environment)->returns] = $2;
          ((struct _Environment *)_environment)->returnsEach[((struct _Environment *)_environment)->returns] = NULL;
          ++((struct _Environment *)_environment)->returns;
    }
    ;

return_parameter_asmios : 
    | RETURN return_parameter_asmios2;
    ;

return_values_asmios2 : 
    Identifier OP_ASSIGN asmio {
          ((struct _Environment *)_environment)->returnsAsmioEach[((struct _Environment *)_environment)->returns] = $3;
          ((struct _Environment *)_environment)->returnsEach[((struct _Environment *)_environment)->returns] = strdup( $1 );
          ++((struct _Environment *)_environment)->returns;
    }
    | Identifier OP_ASSIGN asmio OP_COMMA return_values_asmios2 {
          ((struct _Environment *)_environment)->returnsAsmioEach[((struct _Environment *)_environment)->returns] = $3;
          ((struct _Environment *)_environment)->returnsEach[((struct _Environment *)_environment)->returns] = strdup( $1 );
          ++((struct _Environment *)_environment)->returns;
    }
    ;

return_values_asmios : 
    | RETURN return_values_asmios2;
    ;

print_buffer_definition :
    OP_AT expr {
        Variable * p = variable_retrieve_or_define( _environment, $2, VT_WORD, 0 );
        Variable * x = variable_temporary( _environment, VT_BYTE, "(x)" );
        Variable * y = variable_div( _environment, p->name, screen_tiles_get_width( _environment )->name, x->name );
        locate( _environment, x->name, y->name );
    }
  | OP_AT expr {
        Variable * p = variable_retrieve_or_define( _environment, $2, VT_WORD, 0 );
        Variable * x = variable_temporary( _environment, VT_BYTE, "(x)" );
        Variable * y = variable_div( _environment, p->name, screen_tiles_get_width( _environment )->name, x->name );
        locate( _environment, x->name, y->name );
    } OP_COMMA print_buffer_raw_definition
  | expr {
        print_buffer( _environment, $1, 1, 1 );
    }
  | expr OP_COMMA {
        print_buffer( _environment, $1, 0, 1 );
        print_tab( _environment, 0 );
  }
  | expr OP_SEMICOLON {
        print_buffer( _environment, $1, 0, 1 );
  }
  | expr OP_COMMA {
        print_buffer( _environment, $1, 0, 1 );
        print_tab( _environment, 0 );
  }  print_buffer_definition
  | expr OP_SEMICOLON  {
        print_buffer( _environment, $1, 0, 0 );
  } print_buffer_definition
  ;

print_buffer_raw_definition :
    OP_AT expr {
        Variable * p = variable_retrieve_or_define( _environment, $2, VT_WORD, 0 );
        Variable * x = variable_temporary( _environment, VT_BYTE, "(x)" );
        Variable * y = variable_div( _environment, p->name, screen_tiles_get_width( _environment )->name, x->name );
        locate( _environment, x->name, y->name );
    }
  | OP_AT expr {
        Variable * p = variable_retrieve_or_define( _environment, $2, VT_WORD, 0 );
        Variable * x = variable_temporary( _environment, VT_BYTE, "(x)" );
        Variable * y = variable_div( _environment, p->name, screen_tiles_get_width( _environment )->name, x->name );
        locate( _environment, x->name, y->name );
    } OP_COMMA print_buffer_raw_definition
  | expr {
        print_buffer( _environment, $1, 1, 0 );
    }
  | expr OP_COMMA {
        print_buffer( _environment, $1, 0, 0 );
        print_tab( _environment, 0 );
  }
  | expr OP_SEMICOLON {
        print_buffer( _environment, $1, 0, 0 );
  }
  | expr OP_COMMA {
        print_buffer( _environment, $1, 0, 0 );
        print_tab( _environment, 0 );
  }  print_buffer_raw_definition
  | expr OP_SEMICOLON  {
        print_buffer( _environment, $1, 0, 0 );
  } print_buffer_raw_definition
  ;

print_definition :
    SPC OP expr CP {
        spc( _environment, $3 );
    }
  | SPC OP expr CP {
        spc( _environment, $3 );
    } print_definition
  | SPC OP expr CP {
        spc( _environment, $3 );
    } OP_COMMA print_definition
  | SPC OP expr CP {
        spc( _environment, $3 );
    } OP_SEMICOLON print_definition
  | OP_AT expr {
        Variable * p = variable_retrieve_or_define( _environment, $2, VT_WORD, 0 );
        Variable * x = variable_temporary( _environment, VT_BYTE, "(x)" );
        Variable * y = variable_div( _environment, p->name, screen_tiles_get_width( _environment )->name, x->name );
        locate( _environment, x->name, y->name );
    }
  | OP_AT expr {
        Variable * p = variable_retrieve_or_define( _environment, $2, VT_WORD, 0 );
        Variable * x = variable_temporary( _environment, VT_BYTE, "(x)" );
        Variable * y = variable_div( _environment, p->name, screen_tiles_get_width( _environment )->name, x->name );
        locate( _environment, x->name, y->name );
    } OP_COMMA print_definition
  | expr {
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

sound_definition_argument :
    OP_HASH const_expr {
        ((struct _Environment *)_environment)->soundNoteValue[((struct _Environment *)_environment)->lastSoundNoteDuration] = $2;
        ++((struct _Environment *)_environment)->lastSoundNoteDuration;
    }
    | OP_HASH const_expr OP_COMMA OP_HASH const_expr {
        ((struct _Environment *)_environment)->soundNoteValue[((struct _Environment *)_environment)->lastSoundNoteDuration] = $2;
        ((struct _Environment *)_environment)->soundDurationValue[((struct _Environment *)_environment)->lastSoundNoteDuration] = $5;
        ++((struct _Environment *)_environment)->lastSoundNoteDuration;
    }
    | expr {
        ((struct _Environment *)_environment)->soundNote[((struct _Environment *)_environment)->lastSoundNoteDuration] = strdup( $1 );
        ++((struct _Environment *)_environment)->lastSoundNoteDuration;
    }
    | expr OP_COMMA expr {
        ((struct _Environment *)_environment)->soundNote[((struct _Environment *)_environment)->lastSoundNoteDuration] = strdup( $1 );
        ((struct _Environment *)_environment)->soundDuration[((struct _Environment *)_environment)->lastSoundNoteDuration] = strdup( $3 );
        ++((struct _Environment *)_environment)->lastSoundNoteDuration;
    };

sound_definition_arguments :
    sound_definition_argument
    | sound_definition_argument OP_SEMICOLON sound_definition_arguments;

sound_definition : 
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
    }
    | sound_definition_arguments ON expr {
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
    }
    | sound_definition_arguments {
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
    }
    | OFF  {
        sound_off( _environment, 0xffff );
    }
    | OFF ON OP_HASH const_expr {
        sound_off( _environment, $4 );
    }
    | OFF ON expr {
        sound_off_var( _environment, $3 );
    }
    ;

instrument_definition_simple :
    OP_HASH const_expr ON OP_HASH const_expr {
        instrument( _environment, $2, $5 );
    }
    | const_instrument ON OP_HASH const_expr {
        instrument( _environment, $1, $4 );
    }
    ;

instrument_definition_expression :
    OP_HASH const_expr ON expr {
        instrument_semi_var( _environment, $2, $4 );
    }
    | const_instrument ON expr {
        instrument_semi_var( _environment, $1, $3 );
    }
    ;

instrument_definition : 
    instrument_definition_simple
    | instrument_definition_expression
    ;

music_type :
    {
        $$ = MUSIC_TYPE_AUTO;
    }
    | IAF {
        $$ = MUSIC_TYPE_IAF;
    }
    | MID {
        $$ = MUSIC_TYPE_MID;
    }
    | PSG {
        $$ = MUSIC_TYPE_PSG;
    }
    | SJ2 {
        $$ = MUSIC_TYPE_SJ2;
    }
    ;

optional_loop:
    {
        $$ = 0;
    }
    | LOOP {
        $$ = 1;
    }
    ;

music_definition_expression:
    expr music_type optional_loop {
        music_var( _environment, $1, $3, $2 );
    }
    | LOOP expr music_type {
        music_var( _environment, $2, 1, $3 );
    }
    | PAUSE {
        music_pause( _environment );
    }
    | RESUME {
        music_resume( _environment );
    }
    | STOP {
        music_stop( _environment );
    }
    | SEEK expr {
        music_seek_var( _environment, $2 );
    }
    ;

music_definition:
    music_definition_expression
    ;

play_definition_simple : 
    OP_HASH const_expr {
        play( _environment, $2, 0, 0xffff );
    }
    | OP_HASH const_expr OP_COMMA OP_HASH const_expr {
        play( _environment, $2, $5, 0xffff );
    }
    | OP_HASH const_expr ON OP_HASH const_expr {
        play( _environment, $2, 0, $5 );
    }
    | OP_HASH const_expr OP_COMMA OP_HASH const_expr ON OP_HASH const_expr {
        play( _environment, $2, $5, $8 );
    }
    | OFF  {
        play_off( _environment, 0xffff );
    }
    | OFF ON OP_HASH const_expr {
        play_off( _environment, $4 );
    }
    ;

play_definition_expression : 
    expr {
        Variable * var = variable_retrieve_or_define( _environment, $1, VT_DWORD, 0 );
        if ( var->type == VT_STRING || var->type == VT_DSTRING ) {
            play_string( _environment, $1 );
        } else {
            play_vars( _environment, $1, NULL, NULL );
        }
    }
    | expr OP_COMMA expr {
        play_vars( _environment, $1, $3, NULL );
    }
    | expr OP_COMMA expr ON expr {
        play_vars( _environment, $1, $3, $5 );
    }
    | expr ON expr {
        play_vars( _environment, $1, NULL, $3 );
    }
    | OFF ON expr {
        play_off_var( _environment, $3 );
    }
    ;

play_definition : 
    play_definition_simple
    | play_definition_expression
    ;

volume_definition_simple : 
    OP_HASH const_expr {
        volume( _environment, $2, 0xffff );
    }
    | OP_HASH const_expr ON OP_HASH const_expr {
        volume( _environment, $2, $5 );
    }
    | OFF  {
        volume_off( _environment, 0xffff );
    }
    | OFF ON OP_HASH const_expr {
        volume_off( _environment, $4 );
    }
    ;

volume_definition_expression : 
    expr {
        volume_vars( _environment, $1, NULL );
    }
    | expr ON expr {
        volume_vars( _environment, $1, $3 );
    }
    | OFF ON expr {
        volume_off_var( _environment, $3 );
    }
    ;

volume_definition : 
    volume_definition_simple
    | volume_definition_expression
    ;

bell_definition_simple : 
    {
        bell( _environment, 400, 1500, 0xffff );
    } 
    | OP_HASH const_expr {
        bell( _environment, $2, 1500, 0xffff );
    }
    | OP_HASH const_expr ON OP_HASH const_expr {
        bell( _environment, $2, 1500, $5 );
    }
    | OP_HASH const_expr OP_COMMA OP_HASH const_expr {
        bell( _environment, $2, $5, 0xffff );
    }
    | OP_HASH const_expr OP_COMMA OP_HASH const_expr ON OP_HASH const_expr {
        bell( _environment, $2, $5, $8 );
    }
    ;

bell_definition_expression : 
    expr {
        bell_vars( _environment, $1, NULL, NULL );
    }
    | expr ON expr {
        bell_vars( _environment, $1, NULL, $3 );
    }
    | expr OP_COMMA expr {
        bell_vars( _environment, $1, $3, NULL );
    }
    | expr OP_COMMA expr ON expr {
        bell_vars( _environment, $1, $3, $5 );
    }
    ;

bell_definition : 
    bell_definition_simple
    | bell_definition_expression
    ;

boom_definition_simple : 
    {
        boom( _environment, 1500, 0xffff );
    }
    | OP_HASH const_expr {
        boom( _environment, $2, 0xffff );
    }
    | OP_HASH const_expr milliseconds {
        boom( _environment, $2, 0xffff );
    }
    | ON OP_HASH const_expr {
        boom( _environment, 1500, $3 );
    }
    | OP_HASH const_expr OP_COMMA ON OP_HASH const_expr {
        boom( _environment, $2, $6 );
    }
    | OP_HASH milliseconds const_expr OP_COMMA ON OP_HASH const_expr {
        boom( _environment, $3, $7 );
    }
    ;

boom_definition_expression : 
    expr {
        boom_var( _environment, $1, NULL );
    }
    | expr milliseconds {
        boom_var( _environment, $1, NULL );
    }
    | ON expr {
        boom_var( _environment, NULL, $2 );
    }
    | expr ON expr {
        boom_var( _environment, $1, $3 );
    }
    | expr milliseconds ON expr {
        boom_var( _environment, $1, $4 );
    }
    ;

boom_definition : 
    boom_definition_simple
    | boom_definition_expression
    ;

shoot_definition_simple : 
    {
        shoot( _environment, 0xffff );
    }
    | OP_HASH const_expr {
        shoot( _environment, $2 );
    }
    ;

shoot_definition : 
    shoot_definition_simple
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
    optional_x OP_COMMA optional_y {
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
        input( _environment, $1, ((struct _Environment *)_environment)->defaultVariableType );
        print_newline( _environment );
      }
    | Identifier OP_DOLLAR {
        input( _environment, $1, VT_DSTRING );
        print_newline( _environment );
      }
    | Identifier OP_SEMICOLON {
        input( _environment, $1, ((struct _Environment *)_environment)->defaultVariableType );
      }
    | Identifier OP_DOLLAR OP_SEMICOLON {
        input( _environment, $1, VT_DSTRING );
      }
    | Identifier {
        input( _environment, $1, ((struct _Environment *)_environment)->defaultVariableType );
      } OP_COMMA input_definition2
    | Identifier OP_DOLLAR {
        input( _environment, $1, VT_DSTRING );
      } OP_COMMA input_definition2
    ;

op_comma_or_semicolon : 
    OP_COMMA {
        $$ = 0;
    }
    | OP_SEMICOLON {
        $$ = 1;
    };

read_safeness :
    SAFE {
        $$ = 1;
    }
    | FAST {
        $$ = 0;
    }
    | {
        $$ = ((struct _Environment *)_environment)->optionReadSafe;
    };

read_definition_single :
     read_safeness Identifier {
        read_data( _environment, $2, $1 );
    }
    | read_safeness Identifier {
        parser_array_init( _environment );
    } OP indexes CP {
        Variable * a = variable_retrieve( _environment, $2 );
        if ( a->type != VT_TARRAY ) {
            CRITICAL_NOT_ARRAY( $2 );
        }
        Variable * read = variable_temporary( _environment, a->arrayType, "(temp for array)" );
        read_data( _environment, read->name, $1 );
        if ( a->arrayType == VT_DSTRING ) {
            variable_move_array_string( _environment, $2, read->name );
        } else {
            variable_move_array( _environment, $2, read->name );
        }
        parser_array_cleanup( _environment );
    }
    | read_safeness Identifier OP_DOLLAR {
        parser_array_init( _environment );
    } OP indexes CP {
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

read_definition :
    read_definition_single
    | read_definition_single OP_COMMA read_definition;

input_definition :
      String op_comma_or_semicolon Identifier {
        Variable * string = variable_temporary( _environment, VT_STRING, "(string value)" );
        variable_store_string( _environment, string->name, $1 );
        if ( $2 == 1 ) {
            Variable * qm = variable_temporary( _environment, VT_STRING, "(string value)" );
            variable_store_string( _environment, qm->name, "?" );
            print( _environment, qm->name, 0 );
        }
        print( _environment, string->name, 0 );
        input( _environment, $3, ((struct _Environment *)_environment)->defaultVariableType );
        print_newline( _environment );
    }
    | String op_comma_or_semicolon Identifier OP_DOLLAR {
        Variable * string = variable_temporary( _environment, VT_STRING, "(string value)" );
        variable_store_string( _environment, string->name, $1 );
        print( _environment, string->name, 0 );
        if ( $2 == 1 ) {
            Variable * qm = variable_temporary( _environment, VT_STRING, "(string value)" );
            variable_store_string( _environment, qm->name, "?" );
            print( _environment, qm->name, 0 );
        }
        Variable * var = variable_retrieve_or_define( _environment, $3, VT_DSTRING, 0 );
        input( _environment, var->name, VT_DSTRING );
        print_newline( _environment );
    }
    | String op_comma_or_semicolon Identifier OP_SEMICOLON {
        Variable * string = variable_temporary( _environment, VT_STRING, "(string value)" );
        variable_store_string( _environment, string->name, $1 );
        print( _environment, string->name, 0 );
        if ( $2 == 1 ) {
            Variable * qm = variable_temporary( _environment, VT_STRING, "(string value)" );
            variable_store_string( _environment, qm->name, "?" );
            print( _environment, qm->name, 0 );
        }
        input( _environment, $3, ((struct _Environment *)_environment)->defaultVariableType );
    }
    | String op_comma_or_semicolon Identifier OP_DOLLAR OP_SEMICOLON {
        Variable * string = variable_temporary( _environment, VT_STRING, "(string value)" );
        variable_store_string( _environment, string->name, $1 );
        print( _environment, string->name, 0 );
        if ( $2 == 1 ) {
            Variable * qm = variable_temporary( _environment, VT_STRING, "(string value)" );
            variable_store_string( _environment, qm->name, "?" );
            print( _environment, qm->name, 0 );
        }
        Variable * var = variable_retrieve_or_define( _environment, $3, VT_DSTRING, 0 );
        input( _environment, var->name, VT_DSTRING );
    }
    | String op_comma_or_semicolon Identifier OP_SEMICOLON {
        Variable * string = variable_temporary( _environment, VT_STRING, "(string value)" );
        variable_store_string( _environment, string->name, $1 );
        print( _environment, string->name, 0 );
        if ( $2 == 1 ) {
            Variable * qm = variable_temporary( _environment, VT_STRING, "(string value)" );
            variable_store_string( _environment, qm->name, "?" );
            print( _environment, qm->name, 0 );
        }
        input( _environment, $3, ((struct _Environment *)_environment)->defaultVariableType );
    }  input_definition2
    | String op_comma_or_semicolon Identifier OP_DOLLAR OP_SEMICOLON {
        Variable * string = variable_temporary( _environment, VT_STRING, "(string value)" );
        variable_store_string( _environment, string->name, $1 );
        print( _environment, string->name, 0 );
        if ( $2 == 1 ) {
            Variable * qm = variable_temporary( _environment, VT_STRING, "(string value)" );
            variable_store_string( _environment, qm->name, "?" );
            print( _environment, qm->name, 0 );
        }
        Variable * var = variable_retrieve_or_define( _environment, $3, VT_DSTRING, 0 );
        input( _environment, var->name, VT_DSTRING );
    }  input_definition2
    | input_definition2
    | RawString op_comma_or_semicolon Identifier {
        Variable * string = variable_temporary( _environment, VT_STRING, "(string value)" );
        variable_store_string( _environment, string->name, $1 );
        string->printable = 1;
        print( _environment, string->name, 0 );
        if ( $2 == 1 ) {
            Variable * qm = variable_temporary( _environment, VT_STRING, "(string value)" );
            variable_store_string( _environment, qm->name, "?" );
            print( _environment, qm->name, 0 );
        }
        input( _environment, $3, ((struct _Environment *)_environment)->defaultVariableType );
        print_newline( _environment );
    }
    | RawString op_comma_or_semicolon Identifier OP_DOLLAR {
        Variable * string = variable_temporary( _environment, VT_STRING, "(string value)" );
        variable_store_string( _environment, string->name, $1 );
        string->printable = 1;
        print( _environment, string->name, 0 );
        if ( $2 == 1 ) {
            Variable * qm = variable_temporary( _environment, VT_STRING, "(string value)" );
            variable_store_string( _environment, qm->name, "?" );
            print( _environment, qm->name, 0 );
        }
        Variable * var = variable_retrieve_or_define( _environment, $3, VT_DSTRING, 0 );
        input( _environment, var->name, VT_DSTRING );
        print_newline( _environment );
    }
    | RawString op_comma_or_semicolon Identifier OP_SEMICOLON {
        Variable * string = variable_temporary( _environment, VT_STRING, "(string value)" );
        variable_store_string( _environment, string->name, $1 );
        string->printable = 1;
        print( _environment, string->name, 0 );
        if ( $2 == 1 ) {
            Variable * qm = variable_temporary( _environment, VT_STRING, "(string value)" );
            variable_store_string( _environment, qm->name, "?" );
            print( _environment, qm->name, 0 );
        }
        input( _environment, $3, ((struct _Environment *)_environment)->defaultVariableType );
    }
    | RawString op_comma_or_semicolon Identifier OP_DOLLAR OP_SEMICOLON {
        Variable * string = variable_temporary( _environment, VT_STRING, "(string value)" );
        variable_store_string( _environment, string->name, $1 );
        string->printable = 1;
        print( _environment, string->name, 0 );
        if ( $2 == 1 ) {
            Variable * qm = variable_temporary( _environment, VT_STRING, "(string value)" );
            variable_store_string( _environment, qm->name, "?" );
            print( _environment, qm->name, 0 );
        }
        Variable * var = variable_retrieve_or_define( _environment, $3, VT_DSTRING, 0 );
        input( _environment, var->name, VT_DSTRING );
    }
    | RawString op_comma_or_semicolon Identifier OP_SEMICOLON {
        Variable * string = variable_temporary( _environment, VT_STRING, "(string value)" );
        variable_store_string( _environment, string->name, $1 );
        string->printable = 1;
        print( _environment, string->name, 0 );
        if ( $2 == 1 ) {
            Variable * qm = variable_temporary( _environment, VT_STRING, "(string value)" );
            variable_store_string( _environment, qm->name, "?" );
            print( _environment, qm->name, 0 );
        }
        input( _environment, $3, ((struct _Environment *)_environment)->defaultVariableType );
    }  input_definition2
    | RawString op_comma_or_semicolon Identifier OP_DOLLAR OP_SEMICOLON {
        Variable * string = variable_temporary( _environment, VT_STRING, "(string value)" );
        variable_store_string( _environment, string->name, $1 );
        string->printable = 1;
        print( _environment, string->name, 0 );
        if ( $2 == 1 ) {
            Variable * qm = variable_temporary( _environment, VT_STRING, "(string value)" );
            variable_store_string( _environment, qm->name, "?" );
            print( _environment, qm->name, 0 );
        }
        Variable * var = variable_retrieve_or_define( _environment, $3, VT_DSTRING, 0 );
        input( _environment, var->name, VT_DSTRING );
    }  input_definition2
  ;

poke_definition : 
      expr OP_COMMA expr {
        poke_var( _environment, $1, $3 );
    };

pokew_definition : 
      expr OP_COMMA expr {
        pokew_var( _environment, $1, $3 );
    };

poked_definition : 
      expr OP_COMMA expr {
        poked_var( _environment, $1, $3 );
    };

font_schema : 
    EMBEDDED {
        $$ = FONT_SCHEMA_EMBEDDED;
    }
    | STANDARD {
        $$ = FONT_SCHEMA_STANDARD;
    }
    | SEMIGRAPHIC {
        $$ = FONT_SCHEMA_SEMIGRAPHIC;
    } 
    | COMPLETE {
        $$ = FONT_SCHEMA_COMPLETE;
    } 
    ;

precision : 
    FAST {
        $$ = FT_FAST;
    }
    | SINGLE {
        $$ = FT_SINGLE;
    }
    ;

audio_source :
    SN76489 {
        $$ = ADN_SN76489;
    };

define_definition :
      COLOR IMPLICIT {
        ((struct _Environment *)_environment)->colorImplicit = 1;
    }
    | COLOR EXPLICIT {
        ((struct _Environment *)_environment)->colorImplicit = 1;
    }
    | CENTER WITH NEWLINE {
        ((struct _Environment *)_environment)->centerWithoutNewLine = 0;
    }
    | CENTER WITHOUT NEWLINE {
        ((struct _Environment *)_environment)->centerWithoutNewLine = 1;
    }
    | CLS IMPLICIT {
        ((struct _Environment *)_environment)->vestigialConfig.clsImplicit = 1;
    }
    | CLS EXPLICIT {
        ((struct _Environment *)_environment)->vestigialConfig.clsImplicit = 0;
    }
    | AUDIO SYNC {
        ((struct _Environment *)_environment)->audioConfig.async = 0;
    }
    | AUDIO ASYNC {
        ((struct _Environment *)_environment)->audioConfig.async = 1;
    }
    | MSPRITE SYNC {
        ((struct _Environment *)_environment)->multiplexingSpriteConfig.async = 0;
    }
    | MSPRITE ASYNC {
        ((struct _Environment *)_environment)->multiplexingSpriteConfig.async = 1;
    }
    | AUDIO TARGET audio_source {
        if ( ! define_audio_target_check( _environment, $3 ) ) {
            CRITICAL_AUDIO_TARGET_UNAVAILABLE( );
        }
        ((struct _Environment *)_environment)->audioConfig.target = $3;
    }
    | FONT font_schema {
        ((struct _Environment *)_environment)->fontConfig.schema = $2;
    }
    | JOYSTICK VALUES DEFAULT {
        ((struct _Environment *)_environment)->joystickConfig.values = 0;
    }
    | JOYSTICK VALUES TSB {
        ((struct _Environment *)_environment)->joystickConfig.values = 1;
    }
    | JOYSTICK RETRIES const_expr {
        if ( $3 < 0 ) {
            CRITICAL_INVALID_JOYSTICK_RETRIES( $3 );
        }
        if ( $3 > 255 ) {
            CRITICAL_INVALID_JOYSTICK_RETRIES( $3 );
        }
        ((struct _Environment *)_environment)->joystickConfig.retries = $3;
    }
    | PROGRAM START const_expr {
        if ( $3 < 0 ) {
            CRITICAL_INVALID_PROGRAM_START( $3 );
        }
        if ( $3 > 0xffff ) {
            CRITICAL_INVALID_PROGRAM_START( $3 );
        }
        ((struct _Environment *)_environment)->program.startingAddress = $3;
    }
    | STRING COUNT const_expr {
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
    | FLOAT PRECISION precision {
        ((struct _Environment *)_environment)->floatType.precision = $3;
    }
    | TASK COUNT const_expr {
        if ( $3 <= 0 ) {
            CRITICAL_INVALID_TASK_COUNT( $3 );
        }
        ((struct _Environment *)_environment)->protothreadConfig.count = $3;
        variable_import( _environment, "PROTOTHREADCOUNT", VT_BYTE, $3 );
    }
    | DEFAULT TYPE datatype {
        ((struct _Environment *)_environment)->defaultVariableType = $3;
    }
    | INPUT SIZE const_expr {
        if ( $3 <= 0 ) {
            CRITICAL_INVALID_INPUT_SIZE( $3 );
        }
        ((struct _Environment *)_environment)->inputConfig.size = $3;
    }    
    | INPUT SEPARATOR const_expr {
        if ( $3 <= 0 ) {
            CRITICAL_INVALID_INPUT_SEPARATOR( $3 );
        }
        ((struct _Environment *)_environment)->inputConfig.separator = $3;
    }    
    | INPUT CURSOR const_expr {
        if ( $3 <= 0 ) {
            CRITICAL_INVALID_INPUT_CURSOR( $3 );
        }
        ((struct _Environment *)_environment)->inputConfig.cursor = $3;
    }    
    | INPUT RATE const_expr {
        if ( $3 <= 0 ) {
            CRITICAL_INVALID_INPUT_RATE( $3 );
        }
        ((struct _Environment *)_environment)->inputConfig.rate = $3;
    }
    | INPUT DELAY const_expr {
        if ( $3 <= 0 ) {
            CRITICAL_INVALID_INPUT_DELAY( $3 );
        }
        ((struct _Environment *)_environment)->inputConfig.delay = $3;
    }
    | SCREEN MODE UNIQUE {
        ((struct _Environment *)_environment)->vestigialConfig.screenModeUnique = 1;
    }    
    | DOUBLE BUFFER ON {
        ((struct _Environment *)_environment)->vestigialConfig.doubleBufferSelected = 1;
        ((struct _Environment *)_environment)->vestigialConfig.doubleBuffer = 1;
    }    
    | DOUBLE BUFFER OFF {
        ((struct _Environment *)_environment)->vestigialConfig.doubleBufferSelected = 1;
        ((struct _Environment *)_environment)->vestigialConfig.doubleBuffer = 0;
    }    
    | PALETTE PRESERVE {
        ((struct _Environment *)_environment)->vestigialConfig.palettePreserve = 1;
    }    
    | PALETTE NOT PRESERVE {
        ((struct _Environment *)_environment)->vestigialConfig.palettePreserve = 0;
    }    
    | BLIT blit_definition_define_expression
    | KEYBOARD RATE const_expr {
        if ( $3 <= 0 ) {
            CRITICAL_INVALID_INPUT_RATE( $3 );
        }
        ((struct _Environment *)_environment)->inputConfig.rate = $3;
    }
    | KEYBOARD DELAY const_expr {
        if ( $3 <= 0 ) {
            CRITICAL_INVALID_INPUT_DELAY( $3 );
        }
        ((struct _Environment *)_environment)->inputConfig.delay = $3;
    }
    | PAINT BUFFER const_expr {
        if ( $3 <= 0 ) {
            CRITICAL_INVALID_PAINT_BUFFER( $3 );
        }
        ((struct _Environment *)_environment)->paintBucketSize = $3;
    }
    ;

configure_name :
    GMC {
        $$ = HN_GMC;
    }
    | SN76489 {
        $$ = HN_SN76489;
    };

option_name :
    SLOT {
        $$ = HPN_SLOT;
    }
    | ADDRESS {
        $$ = HPN_ADDRESS;
    };

configure_set_static_option :
    option_name OP_ASSIGN const_expr {
        OptionParameterValue * actual = malloc( sizeof( OptionParameterValue ) );
        memset( actual, 0, sizeof( OptionParameterValue ) );
        actual->parameter = $1;
        actual->value = $3;
        actual->next = ((struct _Environment *)_environment)->optionParameters;
        ((struct _Environment *)_environment)->optionParameters = actual;
    };

configure_set_static_options :
    configure_set_static_option
    | configure_set_static_option OP_COMMA configure_set_static_options;

static_optional :
    STATIC | ;

configure_static_definitions :
    static_optional configure_name {
        ((struct _Environment *)_environment)->optionParameters = NULL;
    } SET configure_set_static_options {
        OptionParameterValue * actual = ((struct _Environment *)_environment)->optionParameters;
        while( actual ) {
            configure_set_value( _environment, $2, actual->parameter, actual->value );
            actual = actual->next;
        }
    };

configure_set_dynamic_option :
    option_name OP_ASSIGN expr {
        OptionParameterValue * actual = malloc( sizeof( OptionParameterValue ) );
        memset( actual, 0, sizeof( OptionParameterValue ) );
        actual->parameter = $1;
        actual->valueName = strdup( $3 );
        actual->next = ((struct _Environment *)_environment)->optionParameters;
        ((struct _Environment *)_environment)->optionParameters = actual;
    };

configure_set_dynamic_options :
    configure_set_dynamic_option
    | configure_set_dynamic_option OP_COMMA configure_set_dynamic_options;

configure_dynamic_definitions :
    DYNAMIC configure_name {
        ((struct _Environment *)_environment)->optionParameters = NULL;
    } SET configure_set_dynamic_options {
        OptionParameterValue * actual = ((struct _Environment *)_environment)->optionParameters;
        while( actual ) {
            configure_set_value_var( _environment, $2, actual->parameter, actual->valueName );
            actual = actual->next;
        }
    };

configure_definitions :
    configure_static_definitions
    | configure_dynamic_definitions;

system : {
        $$ = 0;
    }
    | SYSTEM {
        $$ = 1;
    };

procedure : 
    PROCEDURE | PROC;

declare_definition :
  system procedure Identifier AT const_expr on_targets {
      ((struct _Environment *)_environment)->parameters = 0;
      ((struct _Environment *)_environment)->returns = 0;
      if ( $6 ) {
           declare_procedure( _environment, $3, $5, $1 );
      }
  }
  | system procedure Identifier AT const_expr {
      ((struct _Environment *)_environment)->parameters = 0;
      ((struct _Environment *)_environment)->returns = 0;
    } OP parameters_asmios CP on_targets {
      if ( $10 ) {
           declare_procedure( _environment, $3, $5, $1 );
      }
  }
  | system FUNCTION Identifier AT const_expr {
      ((struct _Environment *)_environment)->parameters = 0;
      ((struct _Environment *)_environment)->returns = 0;
  } return_parameter_asmios on_targets {
      if ( $8 ) {
           declare_procedure( _environment, $3, $5, $1 );
      }
  }
  | system FUNCTION Identifier AT const_expr {
      ((struct _Environment *)_environment)->parameters = 0;
      ((struct _Environment *)_environment)->returns = 0;
    } OP parameters_asmios CP return_parameter_asmios on_targets {
      if ( $11 ) {
           declare_procedure( _environment, $3, $5, $1 );
      }
  }
  ;

define_definitions :
      define_definition
    | define_definition OP_COMMA define_definitions;

target : 
    CPUZ80 {
        #if defined(__c128z__) || defined(__vg5000__) || defined(__zx__) || \
            defined(__coleco__) || defined(__cpc__) || defined(__sc3000__) || \
            defined(__sc3000__) || defined(__sg1000__) ||  defined(__msx1__)
            $$ = 1;
        #else
            $$ = 0;
        #endif
    }
    | CPU6809 {
        #if defined(__coco__) || defined(__d32__) || defined(__d64__) || \
            defined(__pc128op__) || defined(__mo5__) || defined(__coco3__) || \
            defined(__to8__)
            $$ = 1;
        #else
            $$ = 0;
        #endif
    }
    | CPU6502 {
        #if defined(__atari__) || defined(__atarixl__) || defined(__c64__) || \
            defined(__c128__) || defined(__plus4__) || defined(__vic20__) || \
            defined( __c64reu__)
            $$ = 1;
        #else
            $$ = 0;
        #endif
    }
    | ATARI {
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
    C64REU {
        #ifdef __c64reu__
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
    VG5000 {
        #ifdef __vg5000__
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
    CPC {
        #ifdef __cpc__
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
    COCO1 {
        #if defined(__coco__)
            $$ = 1;
        #else
            $$ = 0;
        #endif
    }
    |
    COCO2 {
        #if defined(__coco__)
            $$ = 1;
        #else
            $$ = 0;
        #endif
    }
    |
    COCO3 {
        #if defined(__coco3__)
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
    TO8 {
        #ifdef __to8__
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
    JOYSTICK AVAILABLE {
        #if JOY_COUNT > 0
            $$ = 1;
        #else
            $$ = 0;
        #endif
    }    
    |
    JOY AVAILABLE {
        #if JOY_COUNT > 0
            $$ = 1;
        #else
            $$ = 0;
        #endif
    }    
    |
    JOYSTICK NOT AVAILABLE {
        #if JOY_COUNT > 0
            $$ = 0;
        #else
            $$ = 1;
        #endif
    }    
    |
    JOY NOT AVAILABLE {
        #if JOY_COUNT > 0
            $$ = 0;
        #else
            $$ = 1;
        #endif
    }    
    ;

targets :
     target {
         $$ = $1;
     }
     | target OP_COMMA targets {
        $$ = $1 || $3;
     };

parallel_optional: 
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
    }
    | ON ALL BUT targets {
        $$ = ( $4 ) ? 0 : 1;
    };

scroll_definition_hdirection :
    LEFT {
        $$ = -1;
    }
    |
    RIGHT {
        $$ = 1;
    };

scroll_definition_vdirection :
    UP {
        $$ = -1;
    }
    |
    DOWN {
        $$ = 1;
    };

scroll_definition : 
      scroll_definition_hdirection scroll_definition_vdirection {
        scroll( _environment, $1, $2 );
    }
    | scroll_definition_hdirection {
        scroll( _environment, $1, 0 );
    }
    | scroll_definition_vdirection {
        scroll( _environment, 0, $1 );
    }
    ;

palette_definition:
    OP_HASH const_expr {
        color( _environment, ((struct _Environment *)_environment)->paletteIndex++, $2 );
    }
    | expr {
        color_semivars( _environment, ((struct _Environment *)_environment)->paletteIndex++, $1 );
    }
    | OP_HASH const_expr {
        color( _environment, ((struct _Environment *)_environment)->paletteIndex++, $2 );
    } OP_COMMA palette_definition
    | expr {
        color_semivars( _environment, ((struct _Environment *)_environment)->paletteIndex++, $1 );
    } OP_COMMA palette_definition;

use_definition:
    TILESET expr {
        use_tileset( _environment, $2 );
    };

memory_video :
    {
        $$ = 0;
    }
    | MEMORY {
        $$ = 0;
    }
    | VIDEO {
        $$ = 1;
    };

const_instruction :
    CONST
    | SHARED CONST
    | CONST SHARED
    | GLOBAL CONST
    | CONST GLOBAL
    ;

option_explicit : 
    {
        $$ = 1;
    }
    | ON {
        $$ = 1;
    }
    | OFF {
        $$ = 0;
    };

option_clip : 
    {
        $$ = 1;
    }
    | ON {
        $$ = 1;
    }
    | OFF {
        $$ = 0;
    };

option_read : 
    SAFE {
        $$ = 1;
    }
    | FAST {
        $$ = 0;
    }
    | {
        $$ = 1;
    };

option_definitions :
     EXEC AS GOSUB {
        ((struct _Environment *)_environment)->optionExecAsGosub = 1;
    }
    | EXEC AS GOTO {
        ((struct _Environment *)_environment)->optionExecAsGosub = 0;
    }
     CALL AS GOSUB {
        ((struct _Environment *)_environment)->optionCallAsGoto = 0;
    }
    | CALL AS GOTO {
        ((struct _Environment *)_environment)->optionCallAsGoto = 1;
    }
    | TYPE WIDE {
        ((struct _Environment *)_environment)->defaultNarrowType = 0;
    }
    | TYPE NARROW {
        ((struct _Environment *)_environment)->defaultNarrowType = 1;
    }
    | TYPE SIGNED {
        ((struct _Environment *)_environment)->defaultUnsignedType = 0;
    }
    | DEFAULT TYPE datatype {
        ((struct _Environment *)_environment)->defaultVariableType = $3;
    }
    | TYPE UNSIGNED {
        ((struct _Environment *)_environment)->defaultUnsignedType = 1;
    }
    | EXPLICIT option_explicit {
        ((struct _Environment *)_environment)->optionExplicit = $2;
    }
    | READ option_read {
        ((struct _Environment *)_environment)->optionReadSafe = $2;
    };
    | CLIP option_clip {
        ((struct _Environment *)_environment)->optionClip = $2;
    };

origin_direction :
    {
        $$ = 1;
    }
    | DOWN {
        $$ = 1;
    }
    | UP {
        $$ = -1;
    };

origin_definitions :
    expr OP_COMMA expr origin_direction {
        ((struct _Environment *)_environment)->originUsed = 1;
        variable_move( ((struct _Environment *)_environment), $1, "ORIGINX" );
        variable_move( ((struct _Environment *)_environment), $3, "ORIGINY" );
        ((struct _Environment *)_environment)->originYDirection = $4;
    }
    ;

resolution_definitions :
    expr OP_COMMA expr {
        ((struct _Environment *)_environment)->resolutionUsed = 1;
        variable_move( ((struct _Environment *)_environment), $1, "RESOLUTIONX" );
        variable_move( ((struct _Environment *)_environment), $3, "RESOLUTIONY" );
    }
    ;

out_definition : 
    expr OP_COMMA expr {
        out_var( _environment, $1, $3 );
    }
    ;

tile_definition : 
    LOAD String TO Integer tile_load_flags {
        tile_load( _environment, $2, $5, NULL, $4 );
    };

sys_definition :
    expr on_targets {
        if ( $2 ) {
            sys_var( _environment, $1 );
        }
    }
    | OP_HASH const_expr on_targets {
        if ( $3 ) {
            sys( _environment, $2 );
        }
    }
    | expr WITH {
      ((struct _Environment *)_environment)->parameters = 0;
      ((struct _Environment *)_environment)->returns = 0;
    } values_asmios return_values_asmios on_targets {
        if ( $6 ) {
            sys_var( _environment, $1 );
        }
    }
    | OP_HASH const_expr WITH {
      ((struct _Environment *)_environment)->parameters = 0;
      ((struct _Environment *)_environment)->returns = 0;
    } values_asmios return_values_asmios on_targets {
        if ( $7 ) {
            sys( _environment, $2 );
        }
    }
    ;

exec_definition :
    sys_definition
    | IdentifierSpaced {
        if (  ((struct _Environment *)_environment)->optionExecAsGosub ) {
            call_procedure( _environment, $1 );
        } else {
            goto_label( _environment, $1 );
        }
    };

data_definition_single :
    const_expr {
        data_numeric( _environment, $1 );
    }
    | const_expr_floating {
        data_floating( _environment, $1 );
    }
    | const_expr_string {
        data_string( _environment, $1 );
    };

data_definition_data :
    data_definition_single
    | data_definition_single OP_COMMA data_definition_data
    | LOAD String AS TEXT {

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
    }
    ;

data_definition :
    {
        ((struct _Environment *)_environment)->dataDataType = 0;
    } data_definition_data
    | as_datatype_mandatory {
        ((struct _Environment *)_environment)->dataDataType = $1;
    } data_definition_data;

clear_definition : 
    const_expr {
        if ( $1 <= 0 ) {
            CRITICAL_INVALID_STRING_SPACE( $1 );
        }
        ((struct _Environment *)_environment)->dstring.space = $1;
        clear( _environment );
    }
    ;

pmode_definition :
    OP_HASH const_expr OP_COMMA OP_HASH const_expr {
        pmode( _environment, $2, $5 );
    };

paint_definition :
    expr OP_COMMA expr OP_COMMA expr  {
        Variable * color = sbpen_get( _environment, $5 );
        paint_vars( _environment, $1, $3, color->name, NULL );
    } 
    | OP expr OP_COMMA expr CP {
        paint_vars( _environment, $2, $4, NULL, NULL );
    }
    | OP expr OP_COMMA expr CP OP_COMMA expr {
        paint_vars( _environment, $2, $4, $7, NULL );
    }
    | OP expr OP_COMMA expr CP OP_COMMA OP_COMMA expr {
        paint_vars( _environment, $2, $4, NULL, $8 );
    }
    | OP expr OP_COMMA expr CP OP_COMMA expr OP_COMMA expr {
        paint_vars( _environment, $2, $4, $7, $9 );
    }    
    ;

border_definition :
    expr {
        color_border_var( _environment, $1 );
    };

dsave_to_offset :
    {
        $$ = NULL;
    }
    |
    TO expr {
        $$ = $2;
    };

dsave_from_address :
    {
        $$ = NULL;
    }
    |
    FROM expr {
        $$ = $2;
    };

dsave_size_size :
    {
        $$ = NULL;
    }
    |
    SIZE expr {
        $$ = $2;
    };

dsave_definition :
    expr dsave_to_offset dsave_from_address dsave_size_size {
        dsave( _environment, $1, $2, $3, $4 );
    };

dload_from_offset :
    {
        $$ = NULL;
    }
    |
    FROM expr {
        $$ = $2;
    };

dload_to_address :
    {
        $$ = NULL;
    }
    |
    TO expr {
        $$ = $2;
    };

dload_size_size :
    {
        $$ = NULL;
    }
    |
    SIZE expr {
        $$ = $2;
    };

dload_definition :
    expr dload_from_offset dload_to_address dload_size_size {
        dload( _environment, $1, $2, $3, $4 );
    };

to_variable : 
    {
        $$ = NULL;
    }
    | TO Identifier {
        $$ = $2;
    };

defdgr_definition :
    OP_DOLLAR OP expr CP OP_ASSIGN expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr {
        defdgr_vars( _environment, $3, $6, $8, $10, $12, $14, $16, $18, $20 );
    }
    | OP expr CP OP_ASSIGN expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr {
        defdgr_vars( _environment, $2, $5, $7, $9, $11, $13, $15, $17, $19 );
    };

optional_step :
    {
        $$ = NULL;
    }
    | STEP expr {
        $$ = $2;
    };

flip_image_flags :
    X {
        $$ = FLAG_FLIP_X;
    }
    | Y {
        $$ = FLAG_FLIP_Y;
    }
    | XY {
        $$ = FLAG_FLIP_X | FLAG_FLIP_Y;
    }
    | YX {
        $$ = FLAG_FLIP_X | FLAG_FLIP_Y;
    };

flip_definition:
    IMAGE expr flip_image_flags {
        flip_image_vars_direction( _environment, $2, NULL, NULL, $3 );
    }
    | IMAGE expr frame OP_HASH Identifier flip_image_flags {
        Variable * images = variable_retrieve( _environment, $2 );
        Variable * calculatedFrame = calculate_frame_by_type( _environment, images->originalTileset, $2, $5 );
        flip_image_vars_direction( _environment, $2, calculatedFrame->name, NULL, $6 );
    }
    | IMAGE expr SEQUENCE expr frame expr flip_image_flags {
        flip_image_vars_direction( _environment, $2, $6, $4, $7 );
    }
    | IMAGE expr frame expr flip_image_flags {
        flip_image_vars_direction( _environment, $2, $4, NULL, $5 );
    }

    | flip_image_flags IMAGE expr {
        flip_image_vars_direction( _environment, $3, NULL, NULL, $1 );
    }
    | flip_image_flags IMAGE expr frame OP_HASH Identifier {
        Variable * images = variable_retrieve( _environment, $3 );
        Variable * calculatedFrame = calculate_frame_by_type( _environment, images->originalTileset, $3, $6 );
        flip_image_vars_direction( _environment, $3, calculatedFrame->name, NULL, $1 );
    }
    | flip_image_flags IMAGE expr SEQUENCE expr frame expr {
        flip_image_vars_direction( _environment, $3, $7, $5, $1 );
    }
    | flip_image_flags IMAGE expr frame expr {
        flip_image_vars_direction( _environment, $3, $5, NULL, $1 );
    }
    
    | IMAGE expr DIRECTION expr {
        flip_image_vars_indirection( _environment, $2, NULL, NULL, $4 );
    }
    | IMAGE expr frame OP_HASH Identifier DIRECTION expr {
        Variable * images = variable_retrieve( _environment, $2 );
        Variable * calculatedFrame = calculate_frame_by_type( _environment, images->originalTileset, $2, $5 );
        flip_image_vars_indirection( _environment, $2, calculatedFrame->name, NULL, $7 );
    }
    | IMAGE expr SEQUENCE expr frame expr DIRECTION expr {
        flip_image_vars_indirection( _environment, $2, $6, $4, $8 );
    }
    | IMAGE expr frame expr DIRECTION expr {
        flip_image_vars_indirection( _environment, $2, $4, NULL, $6 );
    }

    | DIRECTION expr IMAGE expr {
        flip_image_vars_indirection( _environment, $4, NULL, NULL, $2 );
    }
    | DIRECTION expr IMAGE expr frame OP_HASH Identifier {
        Variable * images = variable_retrieve( _environment, $4 );
        Variable * calculatedFrame = calculate_frame_by_type( _environment, images->originalTileset, $4, $7 );
        flip_image_vars_indirection( _environment, $4, calculatedFrame->name, NULL, $2 );
    }
    | DIRECTION expr IMAGE expr SEQUENCE expr frame expr {
        flip_image_vars_indirection( _environment, $4, $8, $6, $2 );
    }
    | DIRECTION expr IMAGE expr frame expr {
        flip_image_vars_indirection( _environment, $4, $6, NULL, $2 );
    }
    ;

thread_identifiers :
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
    }
    | expr OP_COMMA thread_identifiers {
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

kill_definition : {
        ((struct _Environment *)_environment)->lastThreadIdentifierUsed = 0;
        memset( ((struct _Environment *)_environment)->threadIdentifier, 0, MAX_TEMPORARY_STORAGE * sizeof( char * ) );
    } thread_identifiers on_targets {
      if ( $3 ) {
        for( int i=0; i<((struct _Environment *)_environment)->lastThreadIdentifierUsed; ++i ) {
          kill_procedure( _environment, ((struct _Environment *)_environment)->threadIdentifier[i] );
        }
      }
    };

spawn_definition :
  Identifier on_targets {
      if ( $2 ) {
        ((struct _Environment *)_environment)->parameters = 0;
        spawn_procedure( _environment, $1, 0 );
      }
  }
  | Identifier OSP {
      ((struct _Environment *)_environment)->parameters = 0;
    } values CSP on_targets {
      if ( $6 ) {
          spawn_procedure( _environment, $1, 0 );
      }
  }
  | Identifier OSP CSP on_targets {
      ((struct _Environment *)_environment)->parameters = 0;
      if ( $4 ) {
          spawn_procedure( _environment, $1, 0 );
      }
  }
  | Identifier OP_COMMA Identifier on_targets {
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
  }
  | Identifier OP_COMMA Identifier OSP {
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
  }
  | Identifier OP_COMMA Identifier OSP CSP on_targets {
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

hires_definition_expression :
    expr OP_COMMA expr {
        bitmap_enable( _environment, 0, 0, 0 );
        sbpen_set( _environment, 1, $1 );
        sbpen_set( _environment, 0, $3 );
        paper( _environment, $3 );
        cls( _environment, NULL );
    };

hires_definition : 
    hires_definition_expression;

keyget_definition :
    Identifier as_datatype_suffix_optional {
        if ( $2 != 0 ) {
            if ( $2 != VT_STRING && $2 != VT_DSTRING ) {
                CRITICAL_GET_NEED_STRING( $2 );
            }
        }
        wait_key( _environment );
        Variable * p = variable_retrieve_or_define( _environment, $1, VT_DSTRING, 0 );
        Variable * k = inkey( _environment );
        variable_move( _environment, k->name, p->name );
    };

at_definition :
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
    };

nrm_definition :
    {
        tilemap_enable( _environment, 0, 0, 0, 0, 0 );
        cls( _environment, NULL );
    };

char_definition :
    mandatory_x OP_COMMA mandatory_y OP_COMMA expr OP_COMMA expr OP_COMMA expr {
        char_at( _environment, $1, $3, $5, $7, $9 );
    };

center_definition : 
  | expr OP_SEMICOLON {
      center( _environment, $1, 0, NULL);
  }
  | expr {
      center( _environment, $1, 1, NULL );
  }
  | expr OP_COMMA expr {
      center( _environment, $1, 1, $3 );
  }
  | AT OP expr OP_COMMA expr CP expr OP_COMMA expr {
      locate( _environment, $3, $5 );
      center( _environment, $7, 0, $9 );
  }
  ;

insert_definition : 
    expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr {
        insert( _environment, $1, $3, $5, $7, $9, $11 );
    };

envelope_definition :
    expr OP_COMMA expr OP_COMMA expr OP_COMMA expr OP_COMMA expr {
        envelope( _environment, $1, $3, $5, $7, $9 );
    }

pause_definition :
    expr {
        pause_seconds( _environment, NULL, $1 );
    }
    | expr OP_COMMA expr {
        pause_seconds( _environment, $1, $3 );
    };

statement2nc:
    BANK bank_definition
  | RASTER raster_definition
  | NEXT RASTER next_raster_definition
  | COLOR color_definition
  | COLOUR color_definition
  | PALETTE {
      ((struct _Environment *)_environment)->paletteIndex = 0;
  } palette_definition
  | PALETTE1 {
      ((struct _Environment *)_environment)->paletteIndex = 0;
      color( _environment, ((struct _Environment *)_environment)->paletteIndex++, $1 );
  } palette_definition
  | PAUSE pause_definition
  | WAIT wait_definition
  | SPRITE sprite_definition
  | CSPRITE sprite_definition
  | MSPRITE sprite_definition
  | MSPRITE UPDATE {
      msprite_update( _environment );
  }
  | NRM nrm_definition
  | HIRES hires_definition
  | KEYGET keyget_definition
  | BITMAP bitmap_definition
  | TEXTMAP textmap_definition
  | TILEMAP tilemap_definition
  | TEXT text_definition
  | TILE tile_definition
  | TILES tiles_definition
  | FONT font_definition
  | COLORMAP colormap_definition
  | COLOURMAP colormap_definition
  | SCREEN screen_definition
  | POINT point_definition
  | PLOT plot_definition
  | CIRCLE circle_definition
  | ELLIPSE ellipse_definition
  | DRAW draw_definition
  | DTILE draw_tile_definition
  | DTILES draw_tile_definition
  | LINE line_definition
  | PUT put_definition
  | DEFDGR defdgr_definition
  | BLIT blit_definition
  | FLIP flip_definition
  | MOVE move_definition
  | GET get_definition
  | SLICE slice_definition
  | BOX box_definition
  | REC rec_definition
  | CONSOLE console_definition
  | BAR bar_definition
  | BLOCK block_definition
  | POLYLINE polyline_definition
  | CLIP clip_definition
  | USE use_definition
  | SET LINE expr {
      variable_move( _environment, $3, "LINE" );
  }
  | INK ink_definition
  | VAR var_definition
  | LET var_definition
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
  | MUL mul_definition
  | DIV div_definition
  | POKE poke_definition
  | POKEW pokew_definition
  | POKED poked_definition
  | NOP {
      outline0( "NOP" );
  }
  | RUN {
    run( _environment );
  }
  | DLOAD dload_definition
  | DSAVE dsave_definition
  | SWAP swap_definition
  | OUT out_definition
  | DATA data_definition
  | READ read_definition
  | RESTORE restore_definition
  | CLEAR clear_definition
  | PMODE pmode_definition
  | PAINT paint_definition
  | AT at_definition
  | CHAR char_definition
  | ENVELOPE envelope_definition
  | INSERT insert_definition
  | PRINT print_definition
  | BORDER border_definition
  | PRINT BUFFER print_buffer_definition
  | PRINT BUFFER RAW print_buffer_raw_definition
  | PRINT {
      print_newline( _environment );
  }
  | DEBUG expr {
      print( _environment, $2, 0 );
  }
  | INPUT input_definition
  | QM print_definition
  | QM {
      print_newline( _environment );
  }
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
  | SCROLL scroll_definition
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
  | CENTRE center_definition
  | CENTER center_definition
  | CLS {
      cls( _environment, NULL );
      home( _environment );
  }
  | CLS expr {
      cls( _environment, $2 );
  }
  | PCLS {
      cls( _environment, NULL );
  }
  | PCLS expr {
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
  | OP_INC TI {
      Variable * ti = get_timer( _environment );
      variable_increment( _environment, ti->name );
      set_timer( _environment, ti->name );
  }
  | OP_DEC TI {
      Variable * ti = get_timer( _environment );
      variable_decrement( _environment, ti->name );
      set_timer( _environment, ti->name );
  }
  | OP_INC Identifier OP {
        parser_array_init( _environment );
    } indexes CP {
        variable_increment_array( _environment, $2 );
        parser_array_cleanup( _environment );
  }
  | OP_DEC Identifier OP {
        parser_array_init( _environment );
    } indexes CP {
        variable_decrement_array( _environment, $2 );
        parser_array_cleanup( _environment );
  }
  | OP_INC OSP Identifier CSP {
        variable_increment_mt( _environment, $3 );
  }
  | OP_DEC OSP Identifier CSP {
        variable_decrement_mt( _environment, $3 );
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
  | IF expr GOTO Integer {
      if_then( _environment, $2 );
      goto_number( _environment, $4 );
      end_if_then( _environment );  
  }
  | IF expr THEN Integer {
      if_then( _environment, $2 );
      goto_number( _environment, $4 );
      end_if_then( _environment );  
  }
  | IF expr THEN Integer ELSE Integer {
      if_then( _environment, $2 );
      goto_number( _environment, $4 );
      else_if_then_label( _environment );  
      else_if_then( _environment, NULL );  
      goto_number( _environment, $6 );
      end_if_then( _environment );  
  }
  | IF expr THEN  {
      if_then( _environment, $2 );
  } statement2nc {
      end_if_then( _environment );  
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
  } OP_HASH const_expr {
      case_equals( _environment, $4 );  
  }
  | CASE {
      case_equals_label( _environment );  
  } expr {
      case_equals_var( _environment, $3 );  
  }
  | CASE ELSE {
      case_equals_label( _environment );  
      case_else( _environment );  
  }
  | ENDSELECT {
      end_select_case( _environment );  
  }
  | DO NULLkw {
      wait_key( _environment );
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
  | UNTIL {
      end_repeat( _environment );  
  } expr {
      end_repeat_condition( _environment, $3 );  
  }
  | EXIT {
      exit_loop( _environment, 0 );  
  }
  | EXIT PROC {
      exit_procedure( _environment );
  }
  | EXIT PROCEDURE {
      exit_procedure( _environment );
  }
  | POP PROC {
      exit_procedure( _environment );
  }
  | POP PROCEDURE {
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
  | FOR Identifier as_datatype_suffix_optional OP_ASSIGN {
    VariableType vt = $3;
    if ( vt == 0 ) {
        vt = ((struct _Environment *)_environment)->defaultVariableType;
    }
    Variable * index;
    if ( variable_exists( _environment, $2 ) ) {
        index = variable_retrieve( _environment, $2 );
    } else {
        index = variable_define( _environment, $2, vt, 0 );
    }
    begin_for_prepare( _environment );
    begin_for_from_prepare( _environment );
  } expr { 
      begin_for_from_assign( _environment, $6 );
  } TO {
      begin_for_to_prepare( _environment );
  } expr {
      begin_for_to_assign( _environment, $10 );
      begin_for_step_prepare( _environment );
  }   optional_step {
      begin_for_step_assign( _environment, $12 );
      begin_for_identifier( _environment, $2 );
  }
  | FOR OSP Identifier as_datatype_suffix_optional CSP OP_ASSIGN {
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
        VariableType vt = $4;
        if ( vt == 0 ) {
            vt = ((struct _Environment *)_environment)->defaultVariableType;
        }
        index = variable_define( _environment, $3, VT_TARRAY, 0 );
        variable_array_type( _environment, $3, vt );
     }
     begin_for_prepare_mt( _environment );
     begin_for_from_prepare_mt( _environment );
  } expr { 
      begin_for_from_assign_mt( _environment, $8 );
  } TO {
      begin_for_to_prepare_mt( _environment );
  } expr {
      outline1("; to assign = %s", $12 );
      begin_for_to_assign_mt( _environment, $12 );
      begin_for_step_prepare_mt( _environment );
  }   optional_step {
      begin_for_step_assign_mt( _environment, $14 );
      begin_for_identifier_mt( _environment, $3 );
  }
  | NEXT {
      end_for( _environment );
  }
  | NEXT Identifier as_datatype_suffix_optional {
    if ( $3 > 0 ) {
        Variable * index = variable_retrieve_or_define( _environment, $2, $3, 0 );
        if ( index->type != $3 ) {
            CRITICAL_DATATYPE_MISMATCH( DATATYPE_AS_STRING[ index->type ], DATATYPE_AS_STRING[ $3 ] );
        }
      }
      end_for_identifier( _environment, $2 );
  }
  | NEXT OSP Identifier as_datatype_suffix_optional CSP {
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
  }
  | parallel_optional PROCEDURE Identifier on_targets {
        ((struct _Environment *)_environment)->parameters = 0;
      ((struct _Environment *)_environment)->protothread = $1;
        ((struct _Environment *)_environment)->emptyProcedure = !$4;
        begin_procedure( _environment, $3 );
  }
  | parallel_optional PROCEDURE Identifier {
      ((struct _Environment *)_environment)->parameters = 0;
      ((struct _Environment *)_environment)->protothread = $1;
    } OSP parameters CSP on_targets {
      ((struct _Environment *)_environment)->emptyProcedure = !$8;
      begin_procedure( _environment, $3 );
  }
  | SHARED parameters_expr {
      shared( _environment );
  }
  | GLOBAL parameters_expr {
      global( _environment );
  }
  | END PROC {
      end_procedure( _environment, NULL );
      ((struct _Environment *)_environment)->emptyProcedure = 0;
  }
  | END PROCEDURE {
      end_procedure( _environment, NULL );
      ((struct _Environment *)_environment)->emptyProcedure = 0;
  }
  | END PROC OSP expr CSP {
      end_procedure( _environment, $4 );
      ((struct _Environment *)_environment)->emptyProcedure = 0;
  }
  | END PROCEDURE OSP expr CSP {
      end_procedure( _environment, $4 );
      ((struct _Environment *)_environment)->emptyProcedure = 0;
  }
  | PROC Identifier {
      ((struct _Environment *)_environment)->parameters = 0;
      proc( _environment, $2 );
  }
  | PROC IdentifierSpaced {
      ((struct _Environment *)_environment)->parameters = 0;
      proc( _environment, $2 );
  }  
  | EXEC exec_definition
  | SYS sys_definition
  | on_targets AsmSnippet on_targets {
    if ( ((struct _Environment *)_environment)->tenLinerRulesEnforced ) {
        CRITICAL_10_LINE_RULES_ENFORCED("ASM");
    }
    if ( $1 && $3 ) {
        outline1("%s", $2 );
    }
  }
  | CALL Identifier on_targets {
      if ( $3 ) {
        ((struct _Environment *)_environment)->parameters = 0;
        call_procedure( _environment, $2 );
      }
  }
  | Identifier OSP {
      ((struct _Environment *)_environment)->parameters = 0;
    } values CSP on_targets {
      if ( $6 ) {
          call_procedure( _environment, $1 );
      }
  }
  | Identifier OSP CSP on_targets {
      if ( $4) {
         ((struct _Environment *)_environment)->parameters = 0;
         call_procedure( _environment, $1 );
      }
  }
  | PROC Identifier OSP {
      ((struct _Environment *)_environment)->parameters = 0;
    } values CSP on_targets {
        if ( $7 ) {
          call_procedure( _environment, $2 );
        }
  }
  | CALL Identifier OSP {
      ((struct _Environment *)_environment)->parameters = 0;
    } values CSP on_targets {
        if ( $7 ) {
          call_procedure( _environment, $2 );
        }
  }
  | CALL Identifier OSP CSP on_targets {
      if ( $5 ) {
          ((struct _Environment *)_environment)->parameters = 0;
          call_procedure( _environment, $2 );
      }
  }
  | SPAWN spawn_definition
  | RESPAWN expr on_targets {
      ((struct _Environment *)_environment)->parameters = 0;
      if ( $3 ) {
          respawn_procedure( _environment, $2 );
      }
  }
  | KILL kill_definition
  | YIELD {
      yield( _environment );
  }
  | FORBID {
      forbid( _environment );
  }
  | ALLOW {
      allow( _environment );
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
  | OSP Identifier OP_COLON CSP {
    label_define_named( _environment, $2 );
    cpu_label( _environment, $2 );
    ((Environment *)_environment)->lastDefinedLabel = strdup( $2 );
    ((Environment *)_environment)->lastDefinedLabelIsNumeric = 0;
  } 
  | Identifier OP_COLON {
    label_define_named( _environment, $1 );
    cpu_label( _environment, $1 );
    ((Environment *)_environment)->lastDefinedLabel = strdup( $1 );
    ((Environment *)_environment)->lastDefinedLabelIsNumeric = 0;
  } 
  | LOAD String OP_COMMA Integer on_bank load_flags {
    load( _environment, $2, NULL, $4, $5, $6 );
  }
  | LOAD String AS String OP_COMMA Integer on_bank load_flags {
    load( _environment, $2, $4, $6, $7, $8 );
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
  | DEGREE {
     ((struct _Environment *)_environment)->floatType.angle = FT_DEGREE;
  }
  | RADIAN {
     ((struct _Environment *)_environment)->floatType.angle = FT_RADIAN;
  }
  | BELL bell_definition
  | BOOM boom_definition
  | SHOOT shoot_definition
  | SOUND sound_definition
  | PLAY play_definition
  | MUSIC music_definition
  | INSTRUMENT instrument_definition
  | VOLUME volume_definition
  | HALT {
      halt( _environment );
  }
  | END {
      end( _environment );
  }
  | ON on_definition
  | GOTO goto_definition
  | CGOTO cgoto_definition
  | GOSUB gosub_definition
  | EVERY every_definition
  | AFTER after_definition
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
  | BEG STORAGE const_expr_string {
        begin_storage( _environment, $3, NULL );
  }
  | STORAGE const_expr_string {
        begin_storage( _environment, $2, NULL );
  }
  | BEG STORAGE const_expr_string AS const_expr_string {
        begin_storage( _environment, $3, $5 );
  }
  | STORAGE const_expr_string AS const_expr_string {
        begin_storage( _environment, $2, $4 );
  }
  | FILEX const_expr_string {
        file_storage( _environment, $2, NULL );
  }
  | FILEX const_expr_string AS const_expr_string {
        file_storage( _environment, $2, $4 );
  }
  | IMAGE const_expr_string image_load_flags using_transparency using_opacity using_background on_bank to_variable {
        Variable * v = image_storage( _environment, $2, NULL, ((struct _Environment *)_environment)->currentMode, $3, $3+$4, $5, $6 );
        if ( $8 ) {
            prepare_variable_storage( _environment, $8, v );
        } 
        variable_temporary_remove( _environment, v->name );
  }
  | IMAGE const_expr_string AS const_expr_string image_load_flags  using_transparency using_opacity using_background on_bank to_variable {
        Variable * v = image_storage( _environment, $2, $4, ((struct _Environment *)_environment)->currentMode, $5, $6+$7, $8, $9 );
        if ( $10 ) {
            prepare_variable_storage( _environment, $10, v );
        }
        variable_temporary_remove( _environment, v->name );
  }
  | images_or_atlas const_expr_string frame_size images_load_flags  using_transparency using_opacity using_background on_bank to_variable {
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
  }
  | images_or_atlas const_expr_string AS const_expr_string frame_size images_load_flags  using_transparency using_opacity using_background on_bank to_variable {
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
  }
  | SEQUENCE const_expr_string AS const_expr_string frame SIZE OP const_expr OP_COMMA const_expr CP sequence_load_flags  using_transparency using_opacity using_background on_bank to_variable{
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
  }
  | SEQUENCE const_expr_string frame SIZE OP const_expr OP_COMMA const_expr CP sequence_load_flags  using_transparency using_opacity using_background on_bank to_variable {
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
  }
  | MUSIC const_expr_string AS const_expr_string on_bank to_variable {
        Variable * v = music_storage( _environment, $2, $4, $5 );
        if ( $6 ) {
            prepare_variable_storage( _environment, $6, v );
        }
        variable_temporary_remove( _environment, v->name );
  }
  | TILESET const_expr_string images_load_flags using_transparency using_opacity using_background on_bank to_variable {
        Variable * v = tileset_storage( _environment, $2, NULL, ((struct _Environment *)_environment)->currentMode, $3, $4+$5, $6, $7 );
        if ( $8 ) {
            prepare_variable_storage( _environment, $8, v );
        }
        variable_temporary_remove( _environment, v->name );
  }
  | TILESET const_expr_string AS const_expr_string images_load_flags  using_transparency using_opacity using_background on_bank to_variable {
        Variable * v = tileset_storage( _environment, $2, $4, ((struct _Environment *)_environment)->currentMode, $5, $6+$7, $8, $9 );
        if ( $10 ) {
            prepare_variable_storage( _environment, $10, v );
        }
        variable_temporary_remove( _environment, v->name );
  }
  | TILEMAP const_expr_string images_load_flags using_transparency using_opacity using_background on_bank to_variable {
        Variable * v = tilemap_storage( _environment, $2, NULL, ((struct _Environment *)_environment)->currentMode, $3, $4+$5, $6, $7 );
        if ( $8 ) {
            prepare_variable_storage( _environment, $8, v );
        }
        variable_temporary_remove( _environment, v->name );
  }
  | TILEMAP const_expr_string AS const_expr_string images_load_flags using_transparency using_opacity using_background on_bank to_variable {
        Variable * v = tilemap_storage( _environment, $2, $4, ((struct _Environment *)_environment)->currentMode, $5, $6+$7, $8, $9 );
        if ( $10 ) {
            prepare_variable_storage( _environment, $10, v );
        }
        variable_temporary_remove( _environment, v->name );
  }
  | ENDSTORAGE {
        end_storage( _environment );
  }
  | DECLARE declare_definition
  | DEFINE define_definitions
  | OPTION option_definitions
  | CONFIGURE configure_definitions
  | ORIGIN origin_definitions
  | RESOLUTION resolution_definitions
  | DIM dim_definitions
  | FILL fill_definitions
  | const_instruction STRING Identifier OP_ASSIGN const_expr_string_const {
        if ( !((Environment *)_environment)->emptyProcedure ) {
            Constant * c1 = constant_find( ((Environment *)_environment)->constants, $5 );

            Constant * c3 = malloc( sizeof( Constant ) );
            memset( c3, 0, sizeof( Constant ) );
            c3->name = strdup( $3 );
            c3->realName = strdup( $3 );

            c3->valueString = malloc( sizeof( StaticString ) );
            memset( c3->valueString, 0, sizeof( StaticString ) );

            c3->valueString->id = UNIQUE_ID;
            c3->valueString->value = malloc( c1->valueString->size );
            memcpy( c3->valueString->value, c1->valueString->value, c1->valueString->size );
            c3->valueString->size = c1->valueString->size;
            c3->valueString->next = ((Environment *)_environment)->strings;
            ((Environment *)_environment)->strings = c3->valueString;

            c3->type = CT_STRING;
            Constant * constLast = ((Environment *)_environment)->constants;
            if ( constLast ) {
                while( constLast->next ) {
                    constLast = constLast->next;
                }
                constLast->next = c3;
            } else {
                ((Environment *)_environment)->constants = c3;
            }

            // const_emit( _environment, c1->name );
        }
  }
  | const_instruction Identifier OP_ASSIGN const_expr_string {
        if ( !((Environment *)_environment)->emptyProcedure ) {
            const_define_string( _environment, $2, $4 );
        }
  }
  | const_instruction Identifier OP_ASSIGN const_expr {
        if ( !((Environment *)_environment)->emptyProcedure ) {
            const_define_numeric( _environment, $2, $4 );
        }
  }
  | const_instruction POSITIVE Identifier OP_ASSIGN const_expr {
        if ( !((Environment *)_environment)->emptyProcedure ) {
            if ( $5 < 0 ) {
                CRITICAL_NEGATIVE_CONSTANT( $3, $5 );
            }
            const_define_numeric( _environment, $3, $5 );
        }
  }
  | POSITIVE const_instruction Identifier OP_ASSIGN const_expr {
        if ( !((Environment *)_environment)->emptyProcedure ) {
            if ( $5 < 0 ) {
                CRITICAL_NEGATIVE_CONSTANT( $3, $5 );
            }
            const_define_numeric( _environment, $3, $5 );
        }
  }
  | const_instruction Identifier IN OP const_expr OP_COMMA const_expr CP OP_ASSIGN const_expr  {
        if ( !((Environment *)_environment)->emptyProcedure ) {
            if ( $10 < $5 ) {
                CRITICAL_TOO_LITTLE_CONSTANT( $2 );
            }
            if ( $10 > $7 ) {
                CRITICAL_TOO_BIG_CONSTANT( $2 );
            }
            const_define_numeric( _environment, $2, $10 );
        }
  }
  | const_instruction Identifier IN OSP const_expr OP_COMMA const_expr CP OP_ASSIGN const_expr  {
        if ( !((Environment *)_environment)->emptyProcedure ) {
            if ( $10 <= $5 ) {
                CRITICAL_TOO_LITTLE_CONSTANT( $2 );
            }
            if ( $10 > $7 ) {
                CRITICAL_TOO_BIG_CONSTANT( $2 );
            }
            const_define_numeric( _environment, $2, $10 );
        }
  }
  | const_instruction Identifier IN OP const_expr OP_COMMA const_expr CSP OP_ASSIGN const_expr  {
        if ( !((Environment *)_environment)->emptyProcedure ) {
            if ( $10 < $5 ) {
                CRITICAL_TOO_LITTLE_CONSTANT( $2 );
            }
            if ( $10 >= $7 ) {
                CRITICAL_TOO_BIG_CONSTANT( $2 );
            }
            const_define_numeric( _environment, $2, $10 );
        }
  }
  | const_instruction Identifier IN OSP const_expr OP_COMMA const_expr CSP OP_ASSIGN const_expr {
        if ( !((Environment *)_environment)->emptyProcedure ) {
            if ( $10 <= $5 ) {
                CRITICAL_TOO_LITTLE_CONSTANT( $2 );
            }
            if ( $10 >= $7 ) {
                CRITICAL_TOO_BIG_CONSTANT( $2 );
            }
            const_define_numeric( _environment, $2, $10 );
        }
  }
  | TI OP_ASSIGN expr {
        set_timer( _environment, $3 );
  }
  | TIMER OP_ASSIGN expr {
        set_timer( _environment, $3 );
  }
  | ENABLE INTERRUPT {
      cpu_ei( _environment );
  }
  | DISABLE INTERRUPT {
      cpu_di( _environment );
  }
  | DOUBLE BUFFER ON {
      double_buffer( _environment, 1 );
  }
  | DOUBLE BUFFER OFF {
      double_buffer( _environment, 0 );
  }
  | SCREEN SWAP {
      screen_swap( _environment );
  }
  | MMOVE memory_video expr TO memory_video expr SIZE expr {
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
  }
  | Identifier OP_ASSIGN expr {
        Variable * expr = variable_retrieve( _environment, $3 );
        Variable * variable;
        if ( variable_exists( _environment, $1 ) ) {
            variable = variable_retrieve( _environment, $1 );
        } else {
            if ( !((struct _Environment *)_environment)->optionExplicit ) {
                variable = variable_define( _environment, $1, expr->type == VT_STRING ? VT_DSTRING : expr->type, 0 );
#if defined(__c64__) || defined(__c64reu__) || defined(__c128__)
                if ( variable->type == VT_IMAGE || variable->type == VT_IMAGES || variable->type == VT_IMAGE ) {
                    expr->usedImage = 1;
                    variable->usedImage = 1;
                }
#endif
            } else {
                CRITICAL_VARIABLE_UNDEFINED( $1 );
            }
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
                if ( expr->type != VT_BUFFER ) {
                    CRITICAL_CANNOT_ASSIGN_TO_ARRAY( $1, DATATYPE_AS_STRING[expr->type] );
                }
                if ( expr->size != variable->size ) {
                    CRITICAL_BUFFER_SIZE_MISMATCH_ARRAY_SIZE( $1, expr->size, variable->size );
                }
            }

            if ( variable->type != expr->type ) {
                Variable * casted = variable_cast( _environment, expr->name, variable->type );
                variable_move( _environment, casted->name, variable->name );
            } else {
                variable_move( _environment, expr->name, variable->name );
            }

        }

  }
  | Identifier as_datatype_suffix OP_ASSIGN expr {
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
  }
  | Identifier OP_ASSIGN OP_HASH const_expr as_datatype {
        if ( !variable_exists( _environment, $1 ) ) {
            variable_retrieve_or_define( _environment, $1, $5, $4 );
        }
        variable_store( _environment, $1, $4 );
  }
  | Identifier OP_ASSIGN_DIRECT expr  {
        variable_direct_assign( _environment, $1, $3 )->name;
  }
  | ARRAY Identifier {
      
    } OP_ASSIGN {
      Variable * var = variable_retrieve( _environment, $2 );
      if ( var->type != VT_TARRAY ) {
          CRITICAL_NOT_ARRAY( $2 );
      }
      ((struct _Environment *)_environment)->currentArray = var;
  } array_reassign 
  | ARRAY Identifier {
      
    } OP_ASSIGN_DIRECT {
      Variable * var = variable_retrieve( _environment, $2 );
      if ( var->type != VT_TARRAY ) {
          CRITICAL_NOT_ARRAY( $2 );
      }
      ((struct _Environment *)_environment)->currentArray = var;
  } array_reassign
  | Identifier {
        parser_array_init( _environment );
    }    
      OP indexes CP OP_ASSIGN expr {
        Variable * array = variable_retrieve( _environment, $1 );
        if ( array->type != VT_TARRAY ) {
            CRITICAL_NOT_ARRAY( $1 );
        }
        Variable * expr = variable_retrieve_or_define( _environment, $7, array->arrayType, 0 );
        variable_move_array( _environment, $1, expr->name );
        parser_array_cleanup( _environment );
  }
  | Identifier OP_DOLLAR {
        parser_array_init( _environment );
    } OP indexes CP OP_ASSIGN expr {
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
  }
  | Identifier {
        parser_array_init( _environment );
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
  }
  | OSP Identifier CSP {
        parser_array_init( _environment );
    }
      OP_ASSIGN expr {
        parser_array_index_symbolic( _environment, "PROTOTHREADCT" );
        Variable * array = variable_retrieve( _environment, $2 );
        if ( array->type != VT_TARRAY ) {
            CRITICAL_NOT_ARRAY( $2 );
        }
        Variable * expr = variable_retrieve_or_define( _environment, $6, array->arrayType, 0 );
        variable_move_array( _environment, $2, expr->name );
        parser_array_cleanup( _environment );
  }
  | OSP Identifier OP_DOLLAR CSP {
        parser_array_init( _environment );
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
  }
  | OSP Identifier CSP {
        parser_array_init( _environment );
    } datatype OP_ASSIGN expr {
        parser_array_index_symbolic( _environment, "PROTOTHREADCT" );
        Variable * x = variable_retrieve( _environment, $7 );
        Variable * a = variable_retrieve( _environment, $2 );
        if ( x->type != $5 ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[x->type], DATATYPE_AS_STRING[$5] );
        }
        if ( a->type != VT_TARRAY ) {
            CRITICAL_NOT_ARRAY( $2 );
        }
        if ( a->arrayType != $5 ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[a->arrayType], DATATYPE_AS_STRING[$5] );
        }
        variable_move_array( _environment, $2, x->name );
        parser_array_cleanup( _environment );
  }
  | Remark
  ;

statement2:
    statement2nc
    |
    ;

statement: 
    { 
        if ( yylineno == 1 &&
            ((Environment *)_environment)->previousProducedAssemblyLines != 
                ((Environment *)_environment)->producedAssemblyLines &&
                ((Environment *)_environment)->producedAssemblyLines
         ) {
            int producedLines = ((Environment *)_environment)->producedAssemblyLines 
                - ((Environment *)_environment)->previousProducedAssemblyLines;

            outline0("; L:0");   
            outline1("; P:%d", producedLines); 
            adiline2( "P:0:%d:%d", yylineno - 1, producedLines );

            ((Environment *)_environment)->yylineno = yylineno;

            ((Environment *)_environment)->previousProducedAssemblyLines = 
            ((Environment *)_environment)->producedAssemblyLines; 
        }

        outline1("; L:%d", ((Environment *)_environment)->yylineno);   
    } 
    statement2;

statements_no_linenumbers:
      statement { ((Environment *)_environment)->yylineno = yylineno; variable_reset( _environment ); interleaved_instructions( _environment ); }
    | statement OP_COLON { ((Environment *)_environment)->yylineno = yylineno; variable_reset( _environment ); interleaved_instructions( _environment ); } statements_no_linenumbers { interleaved_instructions( _environment ); }
    ;

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
        ((Environment *)_environment)->yylineno = yylineno;
    };

emit_additional_info: {

    int producedLines = ((Environment *)_environment)->producedAssemblyLines 
            - ((Environment *)_environment)->previousProducedAssemblyLines;

    outline1("; P:%d", producedLines); 

    adiline2( "P:0:%d:%d", ((Environment *)_environment)->yylineno - 1 - yyconcatlineno, producedLines );
    
    ((Environment *)_environment)->previousProducedAssemblyLines = 
        ((Environment *)_environment)->producedAssemblyLines; 

};

statements_complex3:
    statements_no_linenumbers emit_additional_info
    | statements_with_linenumbers emit_additional_info
    ;

statements_complex2:
    { variable_set( _environment ); } statements_complex3;

statements_complex:
      statements_complex2
    | statements_complex2 NewLine { yyconcatlineno = 0; } statements_complex
    ;

program : 
  statements_complex 
  { ++yylineno; ((Environment *)_environment)->yylineno = yylineno; outline1("; L:%d", yylineno); }
  emit_additional_info;

%%

char version[MAX_TEMPORARY_STORAGE] = "1.16.3";

void show_usage_and_exit( int _argc, char *_argv[] ) {

#if defined(__atari__) 
    char target[MAX_TEMPORARY_STORAGE] = "ATARI 400/800";
#elif defined(__atarixl__) 
    char target[MAX_TEMPORARY_STORAGE] = "ATARI XL";
#elif __c128__
    char target[MAX_TEMPORARY_STORAGE] = "Commodore 128 (MOS 8510 native)";
#elif __c128z__
    char target[MAX_TEMPORARY_STORAGE] = "Commodore 128 (ZILOG Z80 native)";
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
#elif __to8__
    char target[MAX_TEMPORARY_STORAGE] = "Thomson TO8";
#elif __mo5__
    char target[MAX_TEMPORARY_STORAGE] = "Thomson MO5";
#elif __vic20__
    char target[MAX_TEMPORARY_STORAGE] = "Commodore VIC-20";
#elif __msx1__
    char target[MAX_TEMPORARY_STORAGE] = "MSX 1";
#elif __coleco__
    char target[MAX_TEMPORARY_STORAGE] = "ColecoVision";
#elif __sc3000__
    char target[MAX_TEMPORARY_STORAGE] = "SEGA SC-3000";
#elif __sg1000__
    char target[MAX_TEMPORARY_STORAGE] = "SEGA SG-1000";
#elif __cpc__
    char target[MAX_TEMPORARY_STORAGE] = "Amstrad CPC664";
#elif __vg5000__
    char target[MAX_TEMPORARY_STORAGE] = "Philips VG5000";
#elif __coco__
    char target[MAX_TEMPORARY_STORAGE] = "TRS-80 Color Computer";
#elif __coco3__
    char target[MAX_TEMPORARY_STORAGE] = "TRS-80 Color Computer 3";
#elif __c64reu__
    char target[MAX_TEMPORARY_STORAGE] = "Commodore 64 + REU";
#endif

    printf("--------------------------------------------------\n");
    printf("ugBASIC Compiler v%s [target: %s]\n", version, target);
    printf("--------------------------------------------------\n");
    printf("Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)\n\n");
    printf("Licensed under the Apache License, Version 2.0 (the \"License\");\n");
    printf("you may not use this program except in compliance with the License.\n\n");

    printf("usage: %s [options] <source>\n\n", _argv[0] );

    printf("Options and parameters:\n" );
    printf("\t<source>     Input filename with ugBASIC source code\n" );
    printf("\t<asm>        Output filename with ASM source code (optional if '-o' given)\n" );
    printf("\t-a           Show statistics on assembly listing generated\n" );
    printf("\t-d           Enable debugging of LOAD IMAGE\n" );
    printf("\t-p <num>     Maximum number of peep hole optimizations passes (default: 16, 0 = disable)\n" );
    printf("\t-C <file>    Path to compiler\n" );
    printf("\t-A <file>    Path to app maker\n" );
    printf("\t-T <path>    Path to temporary path\n" );
    printf("\t-X <file>    Path to executer\n" );
    printf("\t-P <file>    Path to profile (-L needed)\n" );
    printf("\t-q <cycles>  Cycles for profiling (default: 1000000)\n" );
#if defined(__c64reu__) || defined(__to8__)
    printf("\t-R <size>    Size of expansion memory (in KB)\n" );
#endif
    printf("\t-c <file>    Output filename with linker configuration\n" );
#if defined(__coco__) || defined(__coco3__)
    printf("\t-b <file>    Path to DECB image tool\n" );
#endif
#if defined(__atari__) || defined(__atarixl__)
    printf("\t-t <file>    Path to DIR2ATR tool\n" );
#endif
#if defined(__msx1__)
    printf("\t-t <file>    Path to DSKTOOLS tool\n" );
#endif
#if defined(__pc128op__) || defined(__mo5__) || defined(__to8__)
    printf("\t-G <type>    Type of gamma correction on PALETTE generation:\n" );
    printf("\t               none (0): no gamma correction\n" );
    printf("\t               type1 (1): algorithmic\n" );
    printf("\t               type2 (2): by threshold\n" );
#endif
    printf("\t-1           Include source code into the executable\n" );
    printf("\t             and an execution shell. It enforces other.\n" );
    printf("\t             10-liners rules.\n" );
    printf("\t-s           Enforces sandbox running rules.\n" );
    printf("\t-o <exe>     Output filename with final executable file for target\n" );
    printf("\t-O <type>    Output file format for target:\n" );
#if __atari__ 
    printf("\t                xex - executable binary file\n" );
    printf("\t                atr - ATR disk image\n" );
    #define defaultExtension "xex"
#elif __atarixl__ 
    printf("\t                xex - executable binary file\n" );
    printf("\t                atr - ATR disk image\n" );
    #define defaultExtension "xex"
#elif __c64__
    printf("\t                prg - program binary file\n" );
    printf("\t                d64 - D64 disk image\n" );
    #define defaultExtension "prg"
#elif __c128__
    printf("\t                prg - program binary file\n" );
    printf("\t                d64 - D64 disk image\n" );
    #define defaultExtension "prg"
#elif __c128z__
    printf("\t                prg - program binary file\n" );
    #define defaultExtension "prg"
#elif __plus4__
    printf("\t                prg - program binary file\n" );
    #define defaultExtension "prg"
#elif __zx__
    printf("\t                tap - tape file\n" );
    #define defaultExtension "tap"
#elif __coco__
    printf("\t                bin - COCO binary file\n" );
    printf("\t                dsk - COCO disk basic\n" );
    #define defaultExtension "bin"
#elif __coco3__
    printf("\t                bin - COCO binary file\n" );
    printf("\t                dsk - COCO disk basic\n" );
    #define defaultExtension "bin"
#elif __d32__
    printf("\t                bin - dragon dos binary file\n" );
    #define defaultExtension "bin"
#elif __d64__
    printf("\t                bin - dragon dos binary file\n" );
    #define defaultExtension "bin"
#elif __pc128op__
    printf("\t                k7o - K7 format (original algorithm)\n" );
    printf("\t                k7 - K7 format\n" );
    #define defaultExtension "k7"
#elif __to8__
    printf("\t                k7 - K7 format\n" );
    #define defaultExtension "k7"
#elif __mo5__
    printf("\t                k7o - K7 format (original algorithm)\n" );
    printf("\t                k7 - K7 format\n" );
    #define defaultExtension "k7"
#elif __vic20__
    printf("\t                prg - program binary file\n" );
    printf("\t                d64 - D64 disk image\n" );
    #define defaultExtension "prg"
#elif __msx1__
    printf("\t                rom - cartridge ROM\n" );
    printf("\t                dsk - DSK image\n" );
    #define defaultExtension "rom"
#elif __coleco__
    printf("\t                rom - cartridge ROM\n" );
    #define defaultExtension "rom"
#elif __sc3000__
    printf("\t                rom - cartridge ROM\n" );
    #define defaultExtension "rom"
#elif __sg1000__
    printf("\t                rom - cartridge ROM\n" );
    #define defaultExtension "rom"
#elif __cpc__
    printf("\t                dsk - disk image\n" );
    #define defaultExtension "dsk"
#elif __vg5000__
    printf("\t                k7 - K7 format\n" );
    #define defaultExtension "k7"
#elif __c64reu__
    printf("\t                d64 - D64 disk image\n" );
    printf("\t                reu - REU RAM espansion image\n" );
    #define defaultExtension "d64"
#endif
    printf("\t-l <name>    Output filename with list of variables defined\n" );
    printf("\t-e <modules> Embed specified modules instead of inline code\n" );
#if defined(__zx__) || defined(__msx1__) || defined(__coleco__) || defined(__sc3000__) || defined(__sg1000__) || defined(__cpc__) || defined(__c128z__)
    printf("\t-L <ignored> Output filename with assembly listing file\n" );
#else
    printf("\t-L <listing> Output filename with assembly listing file\n" );
#endif
    printf("\t-E           Show stats of embedded modules\n" );
    printf("\t-W           Enable warnings during compilation\n" );
    printf("\t-V           Output version (example: '%s')\n", version );
    printf("\t-v           Output generated files\n" );
    printf("\n\n" );
    printf("Examples:\n" );
    printf("\tTo generate an assembly starting from basic source:\n" );
    printf("\t\t%s source.bas source.asm\n\n", _argv[0] );
    printf("To generate directly an executable:\n" );
    printf("\t\t%s -O %s -o source.%s source.bas\n\n", _argv[0], defaultExtension, defaultExtension );

    exit(EXIT_FAILURE);
}

int main( int _argc, char *_argv[] ) {
    extern FILE *yyin;
    int flags, opt;
    int nsecs, tfnd;
    Environment * _environment = malloc(sizeof(Environment));
    memset( _environment, 0, sizeof(Environment));

    setup_embedded( _environment );

    _environment->optionClip = 1;
    _environment->optionReadSafe = 1;
    _environment->warningsEnabled = 0;

    _environment->defaultVariableType = VT_SWORD;

    _environment->peepholeOptimizationLimit = 16;

    _environment->floatType.precision = FT_FAST;

    _environment->temporaryPath = get_default_temporary_path( );

    _environment->protothreadConfig.count = PROTOTHREAD_DEFAULT_COUNT;

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
#elif __coco__
    _environment->outputFileType = OUTPUT_FILE_TYPE_DSK;
#elif __coco3__
    _environment->outputFileType = OUTPUT_FILE_TYPE_DSK;
#elif __d32__
    _environment->outputFileType = OUTPUT_FILE_TYPE_BIN;
#elif __d64__
    _environment->outputFileType = OUTPUT_FILE_TYPE_BIN;
#elif __pc128op__
    _environment->outputFileType = OUTPUT_FILE_TYPE_K7_NEW;
#elif __to8__
    _environment->outputFileType = OUTPUT_FILE_TYPE_K7_NEW;
#elif __mo5__
    _environment->outputFileType = OUTPUT_FILE_TYPE_K7_NEW;
#elif __vic20__
    _environment->outputFileType = OUTPUT_FILE_TYPE_PRG;
#elif __msx1__
    _environment->outputFileType = OUTPUT_FILE_TYPE_ROM;
#elif __coleco__
    _environment->outputFileType = OUTPUT_FILE_TYPE_ROM;
#elif __sc3000__
    _environment->outputFileType = OUTPUT_FILE_TYPE_ROM;
#elif __sg1000__
    _environment->outputFileType = OUTPUT_FILE_TYPE_ROM;
#elif __cpc__
    _environment->outputFileType = OUTPUT_FILE_TYPE_DSK;
#elif __c128__
    _environment->outputFileType = OUTPUT_FILE_TYPE_PRG;
#elif __c128z__
    _environment->outputFileType = OUTPUT_FILE_TYPE_PRG;
#elif __vg5000__
    _environment->outputFileType = OUTPUT_FILE_TYPE_K7_NEW;
#elif __c64reu__
    _environment->outputFileType = OUTPUT_FILE_TYPE_PRG;
#endif

    while ((opt = getopt(_argc, _argv, "@1a:A:b:c:C:dD:Ee:G:Ii:l:L:o:O:p:P:q:R:st:T:VvWw:X:")) != -1) {
        switch (opt) {
                case '@':
                    show_troubleshooting_and_exit( _environment, _argc, _argv );
                case 'a':
                    if ( ! _environment->listingFileName ) {
                        char listingFileName[MAX_TEMPORARY_STORAGE];
                        sprintf( listingFileName, "%s.lst", get_temporary_filename( _environment ) );
                        _environment->listingFileName = strdup(listingFileName);
                    }
                    _environment->analysis = 1;
                    break;
                case 'c':
                    _environment->configurationFileName = strdup(optarg);
                    break;
                case 'C':
                    _environment->compilerFileName = strdup(optarg);
                    if( access( _environment->compilerFileName, F_OK ) != 0 ) {
                        CRITICAL("Compiler not found.");
                    }
                    break;
                case 'w':
                    _environment->cmdFileName = strdup(optarg);
                    if( access( _environment->cmdFileName, F_OK ) != 0 ) {
                        CRITICAL("Replaced cmd.exe not found.");
                    }
                    break;
                case 'b':
                    _environment->decbFileName = strdup(optarg);
                    if( access( _environment->decbFileName, F_OK ) != 0 ) {
                        CRITICAL("Image tool not found.");
                    }
                    break;
                case 'X':
                    _environment->executerFileName = strdup(optarg);
                    if( access( _environment->executerFileName, F_OK ) != 0 ) {
                        CRITICAL("Executer not found.");
                    }
                    break;
                case 'P':
                    _environment->profileFileName = strdup(optarg);
                    break;
                case 'A':
                    _environment->appMakerFileName = strdup(optarg);
                    if( access( _environment->appMakerFileName, F_OK ) != 0 ) {
                        CRITICAL("App maker no found.");
                    }
                    break;
                case 'i':
                    importPath = strdup(optarg);
                    break;
                case 't':
#if defined(__atari__) || defined(__atarixl__)
                    _environment->dir2atrFileName = strdup(optarg);
                    if( access( _environment->dir2atrFileName, F_OK ) != 0 ) {
                        CRITICAL("dir2atr tool not found.");
                    }
#endif
#if defined(__msx1__)
                    _environment->dsktoolsFileName = strdup(optarg);
                    if( access( _environment->dsktoolsFileName, F_OK ) != 0 ) {
                        CRITICAL("dsktools tool not found.");
                    }
#endif
                    break;
                case 'T':
                    _environment->temporaryPath = strdup(optarg);
                    break;
                case 'o':
                    _environment->exeFileName = strdup(optarg);
                    break;
                case 'd':
                    _environment->debugImageLoad = 1;
                    break;
                case 'v':
                    _environment->outputGeneratedFiles = 1;
                    break;
                case 'G':
                    if ( strcmp( optarg, "none") == 0 || atoi( optarg ) == 0 ) {
                        _environment->gammaCorrection = GAMMA_CORRECTION_NONE;
                    } else if ( strcmp( optarg, "type1") == 0 || atoi( optarg ) == 1 ) {
                        _environment->gammaCorrection = GAMMA_CORRECTION_TYPE1;
                    } else if ( strcmp( optarg, "type2") == 0 || atoi( optarg ) == 2 ) {
                        _environment->gammaCorrection = GAMMA_CORRECTION_TYPE2;
                    }
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
                        _environment->outputFileType = OUTPUT_FILE_TYPE_TAP;
                    } else if ( strcmp( optarg, "rom") == 0 ) {
                        _environment->outputFileType = OUTPUT_FILE_TYPE_ROM;
                    } else if ( strcmp( optarg, "d64") == 0 ) {
                        _environment->outputFileType = OUTPUT_FILE_TYPE_D64;
                    } else if ( strcmp( optarg, "dsk") == 0 ) {
                        _environment->outputFileType = OUTPUT_FILE_TYPE_DSK;
                    } else if ( strcmp( optarg, "atr") == 0 ) {
                        _environment->outputFileType = OUTPUT_FILE_TYPE_ATR;
                    } else if ( strcmp( optarg, "reu") == 0 ) {
                        _environment->outputFileType = OUTPUT_FILE_TYPE_REU;
                    } else {
                        CRITICAL2("Unknown output format", optarg);
                    }
                    break;
                case 'D':
                    _environment->additionalInfoFileName = strdup(optarg);
                    if ( ! _environment->listingFileName ) {
                        char * p = malloc( strlen( _environment->additionalInfoFileName ) + MAX_TEMPORARY_STORAGE );
                        strcpy( p, _environment->additionalInfoFileName );
                        char * q = strrchr( p, '.' );
                        if ( q ) {
                            strcpy( q, ".listing" );
                        } 
                        _environment->listingFileName = p;
                    }
                    break;
                case 'W':
                    _environment->warningsEnabled = 1;
                    break;
                case 'I':
                    CRITICAL("Option -I has been removed, see bug#641" );
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
                case 'p':
                    _environment->peepholeOptimizationLimit = atoi(optarg);
                    break;
                case 'R':
                    _environment->ramSize = atoi(optarg);
                    break;
                case 'q':
                    _environment->profileCycles = atoi(optarg);
                    break;
                case 'V':
                    fprintf(stderr, "%s", version );
                    exit(0);
                    break;
                case '1':
                    _environment->tenLinerRulesEnforced = 1;
                    break;
                case 's':
                    _environment->sandbox = 1;
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
                        parse_embedded( p, cpu_compare_and_branch_16bit_const );
                        parse_embedded( p, cpu_compare_and_branch_32bit_const );
                        parse_embedded( p, cpu_compare_and_branch_8bit_const );
                        parse_embedded( p, cpu_compare_and_branch_char_const );
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
                        parse_embedded( p, cpu_swap_8bit );
                        parse_embedded( p, cpu_not_16bit );
                        parse_embedded( p, cpu_and_16bit );
                        parse_embedded( p, cpu_or_16bit );
                        parse_embedded( p, cpu_xor_16bit );
                        parse_embedded( p, cpu_not_16bit );
                        parse_embedded( p, cpu_and_16bit );
                        parse_embedded( p, cpu_or_16bit );
                        parse_embedded( p, cpu_swap_16bit );
                        parse_embedded( p, cpu_xor_16bit );
                        parse_embedded( p, cpu_not_32bit );
                        parse_embedded( p, cpu_and_32bit );
                        parse_embedded( p, cpu_or_32bit );
                        parse_embedded( p, cpu_xor_32bit );
                        parse_embedded( p, cpu_swap_32bit );
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
                        parse_embedded( p, cpu_number_to_string );
                        parse_embedded( p, cpu_move_8bit_indirect_with_offset );
                        parse_embedded( p, cpu_bits_to_string );
                        parse_embedded( p, cpu_hex_to_string );
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
                        parse_embedded( p, cpu_sqroot );

                        p = strtok(NULL, ",");
                    }

                    }
                    break;
                default: /* '?' */
                    show_usage_and_exit( _argc, _argv );
                }
    }

    if ( ! _argv[optind] ) {
        show_usage_and_exit( _argc, _argv );
    }

    if ( ! _argv[optind+1] && !_environment->exeFileName ) {
        show_usage_and_exit( _argc, _argv );
    }

    _environment->sourceFileName = strdup(_argv[optind] );

    if ( _environment->tenLinerRulesEnforced ) {
        FILE * fh = fopen( _environment->sourceFileName, "rb" );
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
        fprintf(stderr, "Unable to open source file: %s\n", _environment->sourceFileName );
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

    yydebug = 1;
    errors = 0;
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

int yyerror (Environment * _ignored, const char *s) /* Called by yyparse on error */
{
    if ( stacked == 0 ) {
      fprintf(stderr,  "*** ERROR: %s at %d column %d (%d)\n", s, yylineno, (yycolno+1), (yyposno+1));
    } else {
      fprintf(stderr,  "*** ERROR: %s at %d column %d (%d, %s)\n", s, yylineno, (yycolno+1), (yyposno+1), filenamestacked[stacked]);
    }
      exit(EXIT_FAILURE);
}

