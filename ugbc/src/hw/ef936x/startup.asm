; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
;  * you may not use this file except in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
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
;*                          STARTUP ROUTINE ON EF936X                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CPUMEMMOVE
    CMPU #0
    BEQ CPUMEMMOVEDONE
CPUMEMMOVEL1
    LDA ,Y+
    STA ,X+
    LEAU -1,U
    CMPU #$0
    BNE CPUMEMMOVEL1
CPUMEMMOVEDONE
    RTS
    
EF936XSTARTUP
    LDU #COMMONPALETTE
    LDY #(BASE_SEGMENT+$DA)
    LDX #16
    ; LDA #0
    ; STA 1,Y
    CLR (BASE_SEGMENT+$DB)
EF936XSTARTUPL1
    PULU D
    STB ,Y
    STA ,Y
    LEAX -1,X
    BNE EF936XSTARTUPL1

@IF vestigialConfig.clsImplicit
	JSR CLS
@ENDIF

    RTS

    ; ===========[ VERTICAL BLANK ]===========
    ; ==   Wait for vertical blank routine  ==
    ; ==    (possibily at) given scanline   ==
    ; ========================================

WAITVBLSCANLINE

    ; Save registers.

	PSHS D

    ; Check if scanline counter is ready
    ; Scanline counter is ready if the conditional
    ; branch to wait for entering drawing area is
    ; a BNE branch.
    
    LDA WAITVBL0
    CMPA #$26
    BEQ WAITVBLSCANLINESKIP

    ; Set the scanline counter

    LDA #$4F
    STA WAITVBLSCREENWAITL1
    LDD #$C3FF
    STD WAITVBLSCREENWAITL1+1
    LDD #$FF10
    STD WAITVBLSCREENWAITL1+3
    LDD #$8300
    STD WAITVBLSCREENWAITL1+5
    LDD #$0027
    STD WAITVBLSCREENWAITL1+7

    ; Update the conditional branch to unconditional,
    ; since to wait for a specific scanline we must
    ; be sure to count from the beginning of the
    ; drawing area.

    LDA #$26
    STA WAITVBL0

WAITVBLSCANLINESKIP

    ; Retrieve the parameter from B register.

    PULS D
    
    ; Actually, each scan line at 50 Hz lasts
    ; 64 μs. Each cycle on Motorola 6809 at 1 Mhz
    ; lasts 1 μs. So we must wait 64 cycles for
    ; each scanline requested. The counter routine
    ; lasts 64 cycles. 
    ;
    ; D = 1 -> t = 12 cycles
    ; D = 2 -> t = 64 cycles
    ; D = 3 -> t = 54 cycles

    JMP WAITVBL

    ; ENTRY POINT

WAITVBLSCREEN

    ; Save registers.

	PSHS D

    ; Check if screen counter is ready
    ; Screen counter is ready if the conditional
    ; branch to wait for entering drawing area is
    ; a BRN branch

    LDA WAITVBL0
    CMPA #$26
    BNE WAITVBLSCREENSKIP

    ; Reset the screen counter

    LDA #$12
    STD WAITVBLSCREENWAITL1
    LDD #$1212
    STD WAITVBLSCREENWAITL1+1
    LDD #$1212
    STD WAITVBLSCREENWAITL1+3
    LDD #$1212
    STD WAITVBLSCREENWAITL1+5
    LDD #$1221
    STD WAITVBLSCREENWAITL1+7

    LDA #$21
    STA WAITVBL0
   
WAITVBLSCREENSKIP

    PULS D

    ; Wait for ending of screen generation.

WAITVBL

    ; Let's disable interrupts.

	ORCC #$50

    ; First of all, we check if we are 
    ; inside a drawing area.

    LDA BASE_SEGMENT+$E7
    ANDA #$80

    ; CASE SCREEN (jump = BRN // BEQ)
    ;   let's wait for the next drawing area
    ;   if we are outside the drawing area.

    ; CASE SCANLINE (jump = BNE // BEQ)
    ;   let's wait anyway for the next drawing area.

WAITVBL0
    BRN WAITVBLSCREENINSIDE

    BEQ WAITVBLSCREENOUTSIDE

    ; Busy loop to wait - 
    ; while we are inside the drawing area.

WAITVBLSCREENWAITL1X

    ; CASE SCREEN
    ; We loose 30 μs but it is not very important.
    ;
    ; CASE SCANLINE
    ; We entered this routine with a 9-12 μs delay.
    ; So we must wait at most (64 - (9-12) ) = 55-42 μs
    ; at the very first step. Since the first loop
    ; will take 12 μs, we can wait 30 μs.
    ;
    ; PULS #0       ->  5 cycles
    FCB $35, $00
    ; PULS #0       ->  5 cycles
    FCB $35, $00
    ; PULS #0       ->  5 cycles
    FCB $35, $00
    ; PULS #0       ->  5 cycles
    FCB $35, $00
    ; PULS #0       ->  5 cycles
    FCB $35, $00
    ; PULS #0       ->  5 cycles
    FCB $35, $00

WAITVBLSCREENWAITL1

    ; The "NOP area" is used to leave space
    ; for actual counter routine. On wait for
    ; vertical blank on an entire screen, the
    ; routine is simple. On wait for a specific
    ; scanline, the routine follows:
    ;
    ; CLRA                  ->  2 cycles
    ; SUBD #-1              ->  4 cycles
    ; CMPD #0               ->  5 cycles
    ; BEQ exit loop         ->  3 cycles
    ;                          -----------
    ;                          14 cycles
    ;
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    BRN WAITVBLSCREENWAITL1DONE
    FCB $35, $00
    ; PULS #0               ->  5 cycles
    ; LDA (register)        ->  4 cycles
    ; ANDA #$80             ->  2 cycles
    ; BNE (loop)            ->  3 cycles
    ;                          ---------
    ;                          14 cycles
    ;
    LDA BASE_SEGMENT+$E7
    ANDA #$80
    BNE WAITVBLSCREENWAITL1

WAITVBLSCREENWAITL1DONE
    ; We get out of drawing area, let's
    ; enable again the interupt and
    ; go ahead.

    ANDCC #$AF

    RTS

WAITVBLSCREENINSIDE

    ; Busy loop to wait - 
    ; we must wait for exiting the drawing area.

WAITVBLSCREENWAITL3
    LDA BASE_SEGMENT+$E7
    ANDA #$80
    BNE WAITVBLSCREENWAITL3

WAITVBLSCREENOUTSIDE

    ; Busy loop to wait - 
    ; we must wait for entering the drawing area.

WAITVBLSCREENWAITL2
    ; LDA (register)        ->  4 cycles
    LDA BASE_SEGMENT+$E7
    ; ANDA #$80             ->  2 cycles
    ANDA #$80
    ; BEQ (loop)            ->  3 cycles
    BEQ WAITVBLSCREENWAITL2

    ; We entered the drawing area with a delay 
    ; from 5 cycles (5 μs) to 9 cycles (9 μs).
    ; To start the scanline detection will
    ; take additional 3 cycles (3 μs), so
    ; we will loose 8-12 μs.
    ;
    ; BRA (label)           ->  3 cycles
    BRA WAITVBLSCREENWAITL1X
