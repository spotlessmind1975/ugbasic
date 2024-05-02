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
;     FDB $2048
    ; 0 C      C#/Db  D      D#/Eb  E      F      F#/Gb  G      G#/Ab  A      A#/Bb  B
    FDB 3232,  3072,  2912   2688,  2528,  2400,  2256,  2144,  2016,  1888,  1824,  1664
    ; 1 C      C#/Db  D      D#/Eb  E      F      F#/Gb  G      G#/Ab  A      A#/Bb  B
    FDB 1616,  1536,  1456,  1344,  1264,  1200,  1128,  1072,  1008,  0944,  0912,  0832
    ; 2 C      C#/Db  D      D#/Eb  E      F      F#/Gb  G      G#/Ab  A      A#/Bb  B
    FDB 0808,  0768,  0728,  0672,  0632,  0600,  0564,  0536,  0504,  0472,  0456,  0416
    ; 3 C      C#/Db  D      D#/Eb  E      F      F#/Gb  G      G#/Ab  A      A#/Bb  B
    FDB 0404,  0384,  0364,  0336,  0316,  0300,  0282,  0268,  0252,  0236,  0228,  0208
    ; 4 C      C#/Db  D      D#/Eb  E      F      F#/Gb  G      G#/Ab  A      A#/Bb  B
    FDB 0202,  0192,  0182,  0168,  0158,  0150,  0141,  0134,  0126,  0118,  0114,  0104
    ; 5 C      C#/Db  D      D#/Eb  E      F      F#/Gb  G      G#/Ab  A      A#/Bb  B
    FDB 0101,  0096,  0091,  0084,  0079,  0075,  0072,  0067,  0063,  0059,  0057,  0052
    ; 6 C      C#/Db  D      D#/Eb  E      F      F#/Gb  G      G#/Ab  A      A#/Bb  B
    FDB 0049,  0048,  0045,  0042,  0039,  0037,  0036,  0034,  0031,  0029,  0027,  0026
    ; 7 C      C#/Db  D      D#/Eb  E      F      F#/Gb  G      G#/Ab  A      A#/Bb  B
    FDB 0025,  0024,  0023,  0021,  0020,  0019,  0018,  0017,  0016,  0015,  0014,  0013

; C	16.35 Hz	32.70 Hz	65.41 Hz	130.81 Hz	261.63 Hz	523.25 Hz	1046.50 Hz	2093.00 Hz	4186.01 Hz
; C#/Db	17.32 Hz	34.65 Hz	69.30 Hz	138.59 Hz	277.18 Hz	554.37 Hz	1108.73 Hz	2217.46 Hz	4434.92 Hz
; D	18.35 Hz	36.71 Hz	73.42 Hz	146.83 Hz	293.66 Hz	587.33 Hz	1174.66 Hz	2349.32 Hz	4698.63 Hz
; D#/Eb	19.45 Hz	38.89 Hz	77.78 Hz	155.56 Hz	311.13 Hz	622.25 Hz	1244.51 Hz	2489.02 Hz	4978.03 Hz
; E	20.60 Hz	41.20 Hz	82.41 Hz	164.81 Hz	329.63 Hz	659.25 Hz	1318.51 Hz	2637.02 Hz	5274.04 Hz
; F	21.83 Hz	43.65 Hz	87.31 Hz	174.61 Hz	349.23 Hz	698.46 Hz	1396.91 Hz	2793.83 Hz	5587.65 Hz
; F#/Gb	23.12 Hz	46.25 Hz	92.50 Hz	185.00 Hz	369.99 Hz	739.99 Hz	1479.98 Hz	2959.96 Hz	5919.91 Hz
; G	24.50 Hz	49.00 Hz	98.00 Hz	196.00 Hz	392.00 Hz	783.99 Hz	1567.98 Hz	3135.96 Hz	6271.93 Hz
; G#/Ab	25.96 Hz	51.91 Hz	103.83 Hz	207.65 Hz	415.30 Hz	830.61 Hz	1661.22 Hz	3322.44 Hz	6644.88 Hz
; A	27.50 Hz	55.00 Hz	110.00 Hz	220.00 Hz	440.00 Hz	880.00 Hz	1760.00 Hz	3520.00 Hz	7040.00 Hz
; A#/Bb	29.14 Hz	58.27 Hz	116.54 Hz	233.08 Hz	466.16 Hz	932.33 Hz	1864.66 Hz	3729.31 Hz	7458.62 Hz
; B	30.87 Hz	61.74 Hz	123.47 Hz	246.94 Hz	493.88 Hz	987.77 Hz	1975.53 Hz	3951.07 Hz	7902.13 Hz

    ; WE'LL USE 2 BYTES TO HOLD A 16-BIT TONE PERIOD
TONE		RMB	2

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
    ASLA
    LDD A,X
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
