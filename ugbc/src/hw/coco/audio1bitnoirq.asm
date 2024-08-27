; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License
;  * you may not use this file eXcept in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS,
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either eXpress or implied.
;  * See the License for the specific language governing permissions and
;  * limitations under the License.
;  *----------------------------------------------------------------------------
;  * Concesso in licenza secondo i termini della Licenza Apache, versione 2.0
;  * (la "Licenza è proibito usare questo file se non in conformità alla
;  * Licenza. Una copia della Licenza è disponibile all'indirizzo:
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Se non richiesto dalla legislazione vigente o concordato per iscritto,
;  * il software distribuito nei termini della Licenza è distribuito
;  * "COSì COM'è", SENZA GARANZIE O CONDIZIONI DI ALCUN TIPO, esplicite o
;  * implicite. Consultare la Licenza per il testo specifico che regola le
;  * autorizzazioni e le limitazioni previste dalla medesima.
;  ****************************************************************************/
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
;*                                                                             *
;*                 2 VOICE SQUAREWAVE PATTERN PLAYER FOR COCO 1/2              *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

;********************************************
; Original algorithm:
; 2 voice squarewave pattern player 
; (C) Simon Jonassen (invisible man)
;
; FREE FOR ALL - USE AS YOU SEE FIT, JUST
; REMEBER WHERE IT ORGINATED AND GIVE CREDIT
;********************************************

ZERO        EQU     $0000

;********************************************
;* Main
;********************************************
AUDIO1BITNOIRQ

    ; FIRST WE'RE GOING TO SETUP THE COCO PIAS FOR ONE-BIT SOUND ONEBIT
    ; STEP 1: DISABLE SNDEN LINE SILENCING DAC
    ; YOU DO THIS ANYWAY FOR READING JOYSTICKS TOO
    LDA	PIA1BC
    ANDA #%11110111
    STA	PIA1BC
		
    ; STEP 2: CONFIGURE PIA1 PORT B DATA REGISTER TO DATA DIR REGISTER
    LDA	PIA1BC
    ANDA #%11111011
    STA	PIA1BC

    ; STEP 3: NOW CONFIGURE PIA1 PORT B SO BIT 2 IS OUTPUT NOT INPUT
    ; I SUSPECT TANDY NEVER BOTHERED TO UPDATE PORT AFTER RESETS
    LDA	PIA1BD
    ORA	#%00000010
    STA	PIA1BD

    ; STEP 4: SET PIA1 PORT B REGISTER BACK TO DATA PORT FROM DATA DIR
    LDA	PIA1BC
    ORA	#%00000100
    STA	PIA1BC

    ORCC #$50

;********************************************
; double note values to save shifts
; on the sequencer
;********************************************

    JMP AUDIO1BITNOIRQDPVAL

    ALIGN $0100, $00

AUDIO1BITNOIRQDPVAL
    PSHS DP
    LDD #*
    TFR A, DP
AUDIO1BITNOIRQSETDP

;********************************************
;* 1 bit at $ff22
;********************************************
    LDA $ff23
    ANDA #$fb
    STA $ff23
    
    LDB $ff22
    ORB #$02
    STB $ff22

    ORA #$04
    STA $ff23
    LDA $ff22

;********************************************
; PLAYER ROUTINE
;********************************************

AUDIO1BITNOIRQNOTE
    DEC <AUDIO1BITNOIRQFRAMES           ;wait to sequence
    BNE AUDIO1BITNOIRQDONOTE
    LDA $ff03                           ;check for vblank 
    BPL AUDIO1BITNOIRQDONOTE            ;no - go play note
    LDA $ff02                           ;ack vblank
    LDA #2
    STA <AUDIO1BITNOIRQFRAMES

;********************************************
; SEQUENCER
;********************************************

AUDIO1BITNOIRQOLDU
    LDU #ZERO                   ;save pattern position

AUDIO1BITNOIRQCURNOTE
    PULU D                      ;load 2 notes from pattern
AUDIO1BITNOIRQCURNOTEENDZIX
    CMPU #ZERO                  ; end of tune?
    BNE AUDIO1BITNOIRQPLNOTE
AUDIO1BITNOIRQZIX
    PULS DP
    ANDCC #$AF
    RTS

AUDIO1BITNOIRQPLNOTE            ;restore pattern position to start
    STU AUDIO1BITNOIRQOLDU+1
    STA <AUDIO1BITNOIRQFRQ1+2
    STB <AUDIO1BITNOIRQFRQ2+2
AUDIO1BITNOIRQFRQ1
    LDX #AUDIO1BITNOIRQFREQTAB  ;get the right freq
    LDX ,X
    STX <AUDIO1BITNOIRQFREQ+1   ;store
AUDIO1BITNOIRQFRQ2
    LDX #AUDIO1BITNOIRQFREQTAB  ;get the right freq
    LDX ,X
    STX <AUDIO1BITNOIRQFREQ2+1  ;store
    BRA AUDIO1BITNOIRQNOTE

;********************************************
; NOTE ROUTINE
;********************************************

AUDIO1BITNOIRQDONOTE
    LDB #2
AUDIO1BITNOIRQHS
    LDA $ff01                   ;check hsync irq (timing)
    BPL AUDIO1BITNOIRQHS
    LDA $ff00                   ;ack
    DECB
    BNE AUDIO1BITNOIRQHS
AUDIO1BITNOIRQSUM
    LDD #ZERO
AUDIO1BITNOIRQFREQ
    ADDD #ZERO
    STD <AUDIO1BITNOIRQSUM+1
AUDIO1BITNOIRQSUM2
    LDD #ZERO
    BCS AUDIO1BITNOIRQFREQ2     ;tripped on overflow from above summation
    ADDD <AUDIO1BITNOIRQFREQ2+1 ;add the new freq (ch2)
    STD <AUDIO1BITNOIRQSUM2+1   ;store it
    BCS AUDIO1BITNOIRQBITON     ;carry (overflow on above add)
AUDIO1BITNOIRQBITOFF
    LDA #0                      ;turn off 1bit
    STA $ff22                   ; set the hardware
    BRA AUDIO1BITNOIRQNOTE
AUDIO1BITNOIRQFREQ2
    ADDD #ZERO                  ;our 1st SUM tripped an overflow
    STD <AUDIO1BITNOIRQSUM2+1   ;and we store back to sum #2
AUDIO1BITNOIRQBITON
    LDA #2                      ;and we set the bit
    STA $ff22                   ;set the hardware
    BRA AUDIO1BITNOIRQNOTE

AUDIO1BITNOIRQFRAMES    fdb $0

;******************************************************
;equal tempered 12 note per octave frequency table
;
; HSYNC/2 (7.875Khz)
;******************************************************
    
    ALIGN $0100, $00

AUDIO1BITNOIRQFREQTAB
    fdb	0,141,149,158,167,177,188,199,211,223,237,251
    fdb	266,282,298,316,335,355,376,398,422,447,474,502			
    fdb	532,563,597,632,670,710,752,796,844,894,947,1003	
    fdb	1063,1126,1193,1264,1339,1419,1503,1593,1688,1788,1894,2007
    fdb	2126,2253,2387,2529,2679,2838,3007,3186,3375,3576,3789,4014
    fdb	4252,4505,4773,5057,5358,5676,6014,6371,6750,7152,7577,8028
    fdb	8505,9011,9546,10114,10716,11353,12028,12743,13501,14303,15154,16055
    fdb	17010,18021,19093,20228,21431,22705,24056,25486,27001,28607,30308,32110
