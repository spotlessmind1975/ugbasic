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
;*                     1 BIT AUDIO SUPPORT FOR TRS-80 COCO 1/2                 *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

COCOAUDIO1FREQTABLE
    ; 0     C       C#/Db   D       D#/Eb   E       F       F#/Gb   G       G#/Ab   A       A#/Bb   B
    FDB     1700,   1600,   1520,   1430,   1350,   1275,   1200,   1135,   1075,   1010,   955,    905
    ; 1     C       C#/Db   D       D#/Eb   E       F       F#/Gb   G       G#/Ab   A       A#/Bb   B
    FDB     850,    804,    758,    717,    676,    638,    603,    568,    536,    506,    478,    451
    ; 2     C       C#/Db   D       D#/Eb   E       F       F#/Gb   G       G#/Ab   A       A#/Bb   B
    FDB     425,    402,    379,    358,    338,    319,    301,    284,    268,    253,    239,    225
    ; 3     C       C#/Db   D       D#/Eb   E       F       F#/Gb   G       G#/Ab   A       A#/Bb   B
    FDB     213,    201,    190,    179,    169,    159,    150,    142,    134,    126,    119,    113
    ; 4     C       C#/Db   D       D#/Eb   E       F       F#/Gb   G       G#/Ab   A       A#/Bb   B
    FDB     107,    100,    95,     89,     85,     80,     75,     71,     67,     63,     59,     56
    ; 5     C       C#/Db   D       D#/Eb   E       F       F#/Gb   G       G#/Ab   A       A#/Bb   B
    FDB     53,     50,     47,     45,     42,     40,     38,     36,     33,     31,     29,     28
    ; 6     C       C#/Db   D       D#/Eb   E       F       F#/Gb   G       G#/Ab   A       A#/Bb   B
    FDB     26,     25,     24,     22,     21,     20,     19,     18,     17,     16,     15,     14
    ; 7     C       C#/Db   D       D#/Eb   E       F       F#/Gb   G       G#/Ab   A       A#/Bb   B
    FDB     13,     12,     11,     11,     10,     10,     9,      9,      8,      8,      8,      7

    ; WE'LL USE 2 BYTES TO HOLD A 16-BIT TONE PERIOD
TONE		RZB	2

COCOAUDIO1STARTUP
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

    RTS

COCOAUDIO1BELL
    ; OKAY THE BASIC SETUP IS DONE NOW LET'S MAKE SOME NOISE WITH IT
    LDX	#COCOAUDIO1FREQTABLE
    LSLB
    ABX
    LDD ,X

    ORCC #$50

    TFR D, X
    STD	TONE

    ; A ONEBIT SOUND IS A REPEATING ON OFF PATTERN
    ; AND THE TONE IS CONTROLLED BY THE PERIOD OF TIME BETWEEN ON-TO-OFF-TO-ON AGAIN
    ; SO LETS TURN ON THE ONEBIT FOR "A WHILE" DEFINED BY TONE PERIOD

COCOAUDIO1BELLBITON
    LDA	PIA1BD
    ORA	#%00000010
    STA	PIA1BD

    ; ONCE THE NOISE STARTS WE SPEND "SOME TIME" LETTING IT MAKE NOISE
    ; THE TIME IS DEFINED AS COUNTER OF SOME SORT
    ; HERE A SIMPLE COUNTDOWN LOOP HOGS UP THE CPU

    LDX	TONE
COCOAUDIO1BELLLOOPON
    LEAY -1, Y
    BEQ COCOAUDIOBELLEND
    LEAX -1, X
    BNE	COCOAUDIO1BELLLOOPON

    ; SO NOT WE'VE PLAYED THE NOISE FOR A WHILE LET'S CREATE AN EQUAL SILENCE

COCOAUDIO1BELLBITOFF
    LDA	PIA1BD
    ANDA #%11111101
    STA	PIA1BD

    ; ONCE THE NOISE STOPS WE SPEND "SOME TIME" ENJOYING THE SILENCE
    ; AGAIN WE DEFINE THE SILENT PERIOD USING A COUNTDOWN

    LDX	TONE
COCOAUDIO1BELLLOOPOFF
    LEAY -1, Y
    BEQ COCOAUDIOBELLEND
    LEAX -1,X
    BNE	COCOAUDIO1BELLLOOPOFF

    ; OKAY WE'VE HAD A PERIOD WITH SOUND ON THEN OFF IN EQUAL MEASURE
    ; FROM HERE ON OUT THE SKY AND OUR IMAGINATION IS THE LIMIT
    ; FOR THIS SIMPLE DEMONSTRATION, WE CAN UPDATE THE TONE VALUE AND LOOP
    ; THIS WILL CREATE A RISING OR FALLING TONE DEPENDING ON HOW WE UPDATE
    ; THE VALUE - MAKING THE TONE PERIOD SMALLER MAKES FOR A RISING SOUND

    ; LDX	TONE
    ; LEAX -1,X
    ; STX	TONE

    BRA	COCOAUDIO1BELLBITON

COCOAUDIOBELLEND
    ANDCC #$AF

    RTS

COCOAUDIO1SHOOT
    LDY #$1000   
COCOAUDIO1BOOM
    ; OKAY THE BASIC SETUP IS DONE NOW LET'S MAKE SOME NOISE WITH IT
    JSR CPURANDOM
    ANDA #$0
    ORB #$20
    STD	TONE

    ; A ONEBIT SOUND IS A REPEATING ON OFF PATTERN
    ; AND THE TONE IS CONTROLLED BY THE PERIOD OF TIME BETWEEN ON-TO-OFF-TO-ON AGAIN
    ; SO LETS TURN ON THE ONEBIT FOR "A WHILE" DEFINED BY TONE PERIOD

COCOAUDIO1BOOMBITON
    LDA	PIA1BD
    ORA	#%00000010
    STA	PIA1BD

    ; ONCE THE NOISE STARTS WE SPEND "SOME TIME" LETTING IT MAKE NOISE
    ; THE TIME IS DEFINED AS COUNTER OF SOME SORT
    ; HERE A SIMPLE COUNTDOWN LOOP HOGS UP THE CPU

    LDX	TONE
COCOAUDIO1BOOMLOOPON
    LEAY -1, Y
    BEQ COCOAUDIO1BOOMEND
    LEAX -1, X
    BNE	COCOAUDIO1BOOMLOOPON

    ; SO NOT WE'VE PLAYED THE NOISE FOR A WHILE LET'S CREATE AN EQUAL SILENCE

    JSR CPURANDOM
    ANDA #$0
    ORB #$40
    STD	TONE

COCOAUDIO1BOOMBITOFF
    LDA	PIA1BD
    ANDA #%11111101
    STA	PIA1BD

    ; ONCE THE NOISE STOPS WE SPEND "SOME TIME" ENJOYING THE SILENCE
    ; AGAIN WE DEFINE THE SILENT PERIOD USING A COUNTDOWN

    LDX	TONE
COCOAUDIO1BOOMLOOPOFF
    LEAY -1, Y
    BEQ COCOAUDIO1BOOMEND
    LEAX -1,X
    BNE	COCOAUDIO1BOOMLOOPOFF

    ; OKAY WE'VE HAD A PERIOD WITH SOUND ON THEN OFF IN EQUAL MEASURE
    ; FROM HERE ON OUT THE SKY AND OUR IMAGINATION IS THE LIMIT
    ; FOR THIS SIMPLE DEMONSTRATION, WE CAN UPDATE THE TONE VALUE AND LOOP
    ; THIS WILL CREATE A RISING OR FALLING TONE DEPENDING ON HOW WE UPDATE
    ; THE VALUE - MAKING THE TONE PERIOD SMALLER MAKES FOR A RISING SOUND

    ; LDX	TONE
    ; LEAX -1,X
    ; STX	TONE

    BRA	COCOAUDIO1BOOMBITON

COCOAUDIO1BOOMEND
    RTS
