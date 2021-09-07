; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
;  * you may not use this file except in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http:;www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS,
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
;  * See the License for the specific language governing permissions and
;  * limitations under the License.
;  *----------------------------------------------------------------------------
;  * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
;  * (la "Licenza"); è proibito usare questo file se non in conformità alla
;  * Licenza. Una copia della Licenza è disponibile all'indirizzo:
;  *
;  * http:;www.apache.org/licenses/LICENSE-2.0
;  *
;  * Se non richiesto dalla legislazione vigente o concordato per iscritto,
;  * il software distribuito nei termini della Licenza è distribuito
;  * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
;  * implicite. Consultare la Licenza per il testo specifico che regola le
;  * autorizzazioni e le limitazioni previste dalla medesima.
;  ****************************************************************************/
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
;*                                                                             *
;*                      FILL BACKGROUND COLOR SCREEN  FOR 6847                 *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

#define TILEMAP_MODE_INTERNAL       0       ; Alphanumeric Internal	32 × 16	2	512
#define TILEMAP_MODE_EXTERNAL       1       ; Alphanumeric External	32 × 16	2	512

#define TILEMAP_MODE_SEMIGRAPHICS4  2       ; Semigraphics 4	        64 × 32	8	512
#define TILEMAP_MODE_SEMIGRAPHICS6  3       ; Semigraphics 6	        64 × 48	4	512
#define TILEMAP_MODE_SEMIGRAPHICS8  4       ; Semigraphics 8	        64 × 64	2	2048
#define TILEMAP_MODE_SEMIGRAPHICS12  5       ; Semigraphics 12	        64 × 96	1	3072
#define TILEMAP_MODE_SEMIGRAPHICS24  6       ; Semigraphics 24	        64 × 192	1	6144

#define BITMAP_MODE_COLOR1          7       ; Color Graphics 1	64 × 64	4	1024
#define BITMAP_MODE_RESOLUTION1     8       ; Resolution Graphics 1	128 × 64	1 + Black	1024
#define BITMAP_MODE_COLOR2          9       ; Color Graphics 2	128 × 64	4	2048
#define BITMAP_MODE_RESOLUTION2	    10       ; Resolution Graphics 2 128 × 96	1 + Black	1536
#define BITMAP_MODE_COLOR3          11       ; Color Graphics 3	128 × 96	4	3072
#define BITMAP_MODE_RESOLUTION3     12      ; Resolution Graphics 3	128 × 192	1 + Black	3072
#define BITMAP_MODE_COLOR6          13      ; Color Graphics 6	128 × 192	4	6144
#define BITMAP_MODE_RESOLUTION6     14      ; Resolution Graphics 6	256 × 192	1 + Black	6144

BACKCDR:
    LDA _PAPER
    CMPA #0         ; #define COLOR_BLACK					0
    BEQ BACKCDBLACK0    
    CMPA #1         ; #define COLOR_GREEN					1
    BEQ BACKCDGREEN    
    CMPA #2         ; #define COLOR_YELLOW				2
    BEQ BACKCDWHITE    
    CMPA #3         ; #define COLOR_BLUE					3
    BEQ BACKCDBLACK0
    CMPA #4         ; #define COLOR_RED					4
    BEQ BACKCDGREEN    
    CMPA #5         ; #define COLOR_WHITE					5
    BEQ BACKCDWHITE
    CMPA #6         ; #define COLOR_CYAN					6
    BEQ BACKCDWHITE
    CMPA #7         ; #define COLOR_MAGENTA				7
    BEQ BACKCDGREEN
    CMPA #8         ; #define COLOR_ORANGE				8
    BEQ BACKCDGREEN
    JMP BACKCDBLACK0

; BLACK
BACKCDBLACK0:
    LDA $FF22
    ANDA #$F7
    STA $FF22
    LDA #$0
    RTS

; GREEN
BACKCDGREEN:
    LDA $FF22
    ANDA #$F7
    STA $FF22
    LDA #$FF
    RTS

; BLACK
BACKCDBLACK1:
    LDA $FF22
    ORA #$08
    STA $FF22
    LDA #$0
    RTS

; WHITE
BACKCDWHITE:
    LDA $FF22
    ORA #$08
    STA $FF22
    LDA #$FF
    RTS

BACKCD0X:

BACK:
    LDA CURRENTMODE
    CMPA #0
    BNE BACK6847N0X
    JMP BACK6847N0
BACK6847N0X:
    CMPA #1
    BNE BACK6847N1X
    JMP BACK6847N1
BACK6847N1X:
    CMPA #2
    BNE BACK6847N2X
    JMP BACK6847N2
BACK6847N2X:
    CMPA #3
    BNE BACK6847N3X
    JMP BACK6847N3
BACK6847N4X:
    CMPA #4
    BNE BACK6847N4X
    JMP BACK6847N4
BACK6847N4X:
    CMPA #5
    BNE BACK6847N5X
    JMP BACK6847N5
BACK6847N5X:
    CMPA #6
    BNE BACK6847N6X
    JMP BACK6847N6
BACK6847N6X:
    CMPA #7
    BNE BACK6847N7X
    JMP BACK6847N7
BACK6847N7X:
    CMPA #8
    BNE BACK6847N8X
    JMP BACK6847N8
BACK6847N8X:
    CMPA #9
    BNE BACK6847N9X
    JMP BACK6847N9
BACK6847N9X:
    CMPA #10
    BNE BACK6847N10X
    JMP BACK6847N10
BACK6847N10X:
    CMPA #11
    BNE BACK6847N11X
    JMP BACK6847N11
BACK6847N11X:
    CMPA #12
    BNE BACK6847N12X
    JMP BACK6847N12
BACK6847N12X:
    CMPA #13
    BNE BACK6847N13X
    JMP BACK6847N13
BACK6847N13X:
    CMPA #14
    BNE BACK6847N14X
    JMP BACK6847N14
BACK6847N14X:
    RTS

; ALPHANUMERIC DISPLAY MODES – All alphanumeric modes occupy an 8 x 12 
; dot character matrix box and there are 32 x 16 character boxes per TV frame. 
; Each horizontal dot (dot-clock) corresponds to one half the period duration of
; the 3.58 MHz clock and each vertical dot is one scan line. One of two colors 
; for the lighted dots may be selected by the color set select pin (pin 39). 
; An internal ROM will generate 64 ASCII display characters in a standard 5 x 7 box. 
; Six bits of the eight-bit data word are used for the ASCII character generator 
; and the two bits not used are used to implement inverse video and mode 
; switching to semigraphics – 4, – 8, – 12, or – 24.
BACK6847N0
BACK6847N1
    LDA EMPTYTILE
    LDB #5
    STB CHARACTERS
    JMP BACK6847FILLT

; The ALPHA SEMIGRAPHICS – 4 mode translates bits 0 through 3 into a 4 x 6 dot 
; element in the standard 8 x 12 dot box. Three data bits may be used to select
; one of eight colors for the entire character box. The extra bit is used to 
; switch to alphanumeric. A 512 byte display memory is required. A density of 
; 64 x 32 elements is available in the display area. The element area is four
; dot-clocks wide by six lines high.
BACK6847N2
    LDA _PAPER
    ANDA #$07
    LSLA
    LSLA
    LSLA
    LSLA    
    LDB #5
    STB CHARACTERS
    JMP BACK6847FILLT

; The ALPHA SEMIGRAPHICS – 6 mode maps six 4 x 4 dot elements into the standard
; 8 x 12 dot alphanumeric box, a screen density of 64 x 48 elements is available. 
; Six bits are used to generate this map and two data bits may be used to select 
; one of four colors in the display box. A 512 byte display memory is required. 
; The element area is four dot-clocks wide by four lines high.
BACK6847N3
    LDA _PAPER
    ANDA #$03
    LSLA
    LSLA
    LSLA
    LSLA
    LSLA
    LSLA
    LDB #5
    STB CHARACTERS
    JMP BACK6847FILLT

; The ALPHA SEMIGRAPHICS – 8 mode maps eight 4 x 3 dot elements into the 
; standard 8 x 12 dot box. This mode requires four memory locations per box 
; and each memory location may specify one of eight colors or black. 
; A 2048 byte display memory is required. A density of 64 x 64 elements is 
; available in the display area. The element area is four dot-clocks wide 
; by three lines high.
BACK6847N4
    RTS

; The ALPHA SEMIGRAPHICS – 12 mode maps twelve 4 x 2 dot elements into the 
; standard 8 x 12 dot box. This mode requires six memory locations per box and 
; each memory location may specify one of eight colors or black. A 3072 byte 
; display memory is required. A density of 64 x 96 elements is available in the
; display area. The element area is four dot-clocks wide by two lineshigh.
BACK6847N5
    RTS

; The ALPHA SEMIGRAPHICS – 24 mode maps twenty-four 4 x 1 dot elements into 
; the standard 8 x 12 dot box. This mode requires twelve memory locations 
; per box and each memory location may specify one of eight colors or black. 
; A 6144 byte display memory is required. A density of 64 x 192
; elements is available in the display are. The element area is four 
; dot-clocks wide by one line high.
BACK6847N6
    RTS

; The 64 x 64 Color Graphics mode generates a display matrix of 64 
; elements wide by 64 elements high. Each element may be one of four 
; colors. A 1K x 8 display memory is required. Each pixel equals 
; four dot-clocks by three scan lines.
BACK6847N7
    LDA _PAPER
    ANDA #$03
    TFR A, B
    LSLB
    LSSB
    ORA B
    LSLB
    LSSB
    ORA B
    LSLB
    LSSB
    ORA B
    LDB #8
    STB CHARACTERS
    JMP BACK6847FILLT

; The 128 x 64 Graphics Mode generates a matrix 128 elements wide 
; by 64 elements high. Each element may be either ON or OFF. However, 
; the entire display may be one of two colors, selected by using the 
; color set select pin. A 1K x 8 display memory is required. Each 
; pixel equals two dotclocks by three scan lines.
BACK6847N8
    JSR BACKCDR
    LDB #8
    STB CHARACTERS
    JMP BACK6847FILLT

; The 128 x 64 Color Graphics mode generates a display matrix 128 
; elements wide by 64 elements high. Each element may be one of four 
; colors. A 2K x 8 display memory is required. Each pixel equals
; two dot-clocks by three scan lines.
BACK6847N9
    LDA _PAPER
    ANDA #$03
    TFR A, B
    LSLB
    LSSB
    ORA B
    LSLB
    LSSB
    ORA B
    LSLB
    LSSB
    ORA B
    LDB #16
    STB CHARACTERS
    JMP BACK6847FILLT

; The 128 x 96 Graphics mode generates a display matrix 128 
; elements wide by 96 elements high. Each element may be either 
; ON or OFF. However, the entire display may be one of two colors
; selected by using the color select pin. A 2K x 8 display memory 
; is required. Each pixel equals two dot-clocks by two scan lines.
BACK6847N10
    JSR BACKCDR
    LDB #16
    STB CHARACTERS
    JMP BACK6847FILLT

; The 128 x 96 Color Graphics mode generates a display 128 elements 
; wide by 96 elements high. Each element may be one of four colors. 
; A 3K x 8 display memory is required. Each pixel equals two 
; dot-clocks by two scan lines.
BACK6847N11
    LDA _PAPER
    ANDA #$03
    TFR A, B
    LSLB
    LSSB
    ORA B
    LSLB
    LSSB
    ORA B
    LSLB
    LSSB
    ORA B
    LDB #24
    STB CHARACTERS
    JMP BACK6847FILLT

; The 128 x 192 Graphics mode generates a display matrix 128 elements 
; wide by 192 elements high. Each element may be either ON or OFF,
; but the ON elements may be one of two colors selected with color 
; set select pin. A 3K x 8 display memory is required. Each pixel 
; equals two dot-clocks by one scan line.
BACK6847N12
    JSR BACKCDR
    LDB #24
    STB CHARACTERS
    JMP BACK6847FILLT

; The 128 x 192 Color Graphics mode generates a display 128 elements 
; wide by 192 elements high. Each element may be one of four colors.
; A 6K x 8 display memory is required. Each pixel equals two dot-clocks 
; by one scan line.
BACK6847N13
    LDA _PAPER
    ANDA #$03
    TFR A, B
    LSLB
    LSSB
    ORA B
    LSLB
    LSSB
    ORA B
    LSLB
    LSSB
    ORA B
    LDB #48
    STB CHARACTERS
    JMP BACK6847FILLT

; The 256 x 192 Graphics mode generates a display 256 elements wide by 
; 192 elements high. Each element may be either ON or OFF, but the ON 
; element may be one of two colors selected with the color set select pin. 
; A 6K x 8 display memory is required. Each pixel equals one 
; dot-clock by one scan line.
BACK6847N14
    JSR BACKCDR
    LDB #24
    STB CHARACTERS
    JMP BACK6847FILLT

BACK6847FILLT
    LDX TEXTADDRESS
    STX COPYOFTEXTADDRESS
    LDY CHARACTERS
    LDB #$7F
BACK6847FILLT2
    STA , X
    LEAX 1, X
    DECB
    CMPB #$7F
    BNE BACK6847FILLT2
    LDB #$7F
    LEAY -1, Y
    CMPY #0 
    BNE BACK6847FILLT2
    LDA #$FF 
    RTS




        case BITMAP_MODE_COLOR6            ; Color Graphics 6	128 × 192	4	6144
            ; Full graphic 6-C 1 1 1 0 1 1 0 128x192x4 $1800(6144)
            VDG_GRAPH;
            SAM_V2_SET;
            SAM_V1_SET;
            SAM_V0_CLR;
            cpu_store_16bit( _environment, "CURRENTWIDTH", 128 );
            cpu_store_16bit( _environment, "CURRENTHEIGHT", 192 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 0 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 32 );
            cpu_store_8bit( _environment, "CURRENTSL", 32 );
            break;

        case BITMAP_MODE_RESOLUTION6       ; Resolution Graphics 6	256 × 192	1 + Black	6144            break;
            ; Full graphic 6-R 1 1 1 1 1 1 0 256x192x2 $1800(6144)
            VDG_GRAPH;
            SAM_V2_SET;
            SAM_V1_SET;
            SAM_V0_CLR;
            SAM_V2_SET;
            SAM_V1_SET;
            SAM_V0_SET;
            cpu_store_16bit( _environment, "CURRENTWIDTH", 128 );
            cpu_store_16bit( _environment, "CURRENTHEIGHT", 192 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAIN", 0 );
            cpu_store_8bit( _environment, "TEXTBLOCKREMAINPW", 32 );
            cpu_store_8bit( _environment, "CURRENTSL", 32 );
            break;


BACK6847N2
BACK6847N3
    LDA _PAPER
    STA $02C6
    RTS


; GRAPHICS 1 and 2              SETCOLOR     Register
; Uppercase and numbers            0           708
; Lowercase characters             1           709
; Inverse uppercase                2           710
; Inverse lowercase                3           711
; Background, border               4           712

; GRAPHICS 3, 5, 7           SETCOLOR       COLOR   Register
; Four color modes
; Graphics point or             0             1       708
; fill area                     1             2       709
;                               2             3       710
; Background, border            4             0       712

; GRAPHICS 4, 6              SETCOLOR       COLOR   Register
; Two color modes
; Graphics point                0             1       708
; Background, border            4             0       712

BACK6847N4
BACK6847N5
BACK6847N6
BACK6847N7
BACK6847N8
BACK6847N9
BACK6847N11
BACK6847N12
BACK6847N13
BACK6847N10
BACK6847N14
BACK6847N15
    LDA _PAPER
    STA $02C8
    RTS

