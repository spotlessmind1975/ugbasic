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
;*                          STARTUP ROUTINE ON THOMSON MO5                     *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PAGE0 equ $21

; TIMER service routine
MO5IRQ
    LDD   #0            ; TI variable
MO5TIMER  set *-2       ; (variable within code)
    ADDD  #1            ; increment
    STD   MO5TIMER      ; write result to TI variable
    LDA   #PAGE0        ; sets the direct page
    TFR   A,DP          ; for ugbc routines
@IF deployed.timer
    JSR   TIMERMANAGER
@ENDIF
@IF deployed.keyboard
    JSR   KEYBOARDMANAGER
@ENDIF
    JMP   >MO5IRQDEF    ; jump to next ISR
MO5IRQN   set *-2       ; (variable within code)

; defaut service routine
MO5IRQDEF
    JMP   >MO5IRQEMPTY  ; jmp to the previous routine
MO5IRQO   set *-2       ; (variable within code)

; empty service routine
MO5IRQEMPTY
    RTI                 ;  by defaut do RTI

MO5IRQOINIT   fcb $0

MO5STARTUP
    LDA   MO5IRQOINIT
    BNE   MO5STARTUPNOIRQ
    LDA   #1
    STA   MO5IRQOINIT
    LDX   #$2061
    LDA   2,X           ; Is previous TIMERPT enable ?
    BEQ   MO5STARTUP2   ; no ==> keep default return code (RTI)
    LDD   ,X            ; yes ==> backup previous ISR
    STD   MO5IRQO       ;         and chain it at the end of our own
MO5STARTUP2
    LDD   #MO5IRQ       ; install our own ISR
    STD   ,X
    
MO5STARTUPNOIRQ

    LDA   #PAGE0        ; any non-zero value will do, let's use the one that'll go to DP
    STA   2,X           ; enable the ISR

    TFR   A,DP        ; setup direct-page
    CLRB
    TFR   D,X
    CLRA
MO5STARTUP3 
    STB   ,X+         ; clear direct-page
    DECA
    BNE   MO5STARTUP3

    LDB   #$14          ; shut down cursor
    SWI
    FCB   $02

    LDD #$0
MO5STARTUPL1
    ADDD #$1
    STD <MATHPTR0
    CMPD #$3100
    BNE MO5STARTUPL1

    LDA MO5TIMER+1
    CMPA #0A
    BLE MO5NTSC

MO5PAL
    LDA #50
    STA TICKSPERSECOND
    JMP MO5STARTUPDONE

MO5NTSC
    LDA #60
    STA TICKSPERSECOND
    JMP MO5STARTUPDONE

MO5STARTUPDONE

    ORCC #$50

    ; LDB   #0
    ; STB   $2076
    ; LDB   $2019
    ; ORB   #8
    ; STB   $2019

@IF expansionBanks

    LDU #BANKLOAD
    LDB #0
BANKLOADL1
    LDA B,U
    CMPA #$FF
    BEQ BANKLOADL2
    STA $A7CB
    INCB

    PSHS D,Y,X,U
    LDX #$B000

    LDA #1
    SWI
    FCB $22

BANKLOADL1REPEAT

    LDY #$EF00

    LDA #1
    LDB #0
    SWI
    FCB $20

    CMPB #0
    BEQ BANKLOADL1REPEAT
    CMPB #$FF
    BEQ BANKLOADL1END

    CMPX #$B000
    BNE BANKLOADL1MV

    LEAY 6,Y

    LDU #$00F9
    JMP BANKLOADL1MV2

BANKLOADL1MV

    LEAY 1,Y
    LDU #$00FE

BANKLOADL1MV2
    LDA ,Y+
    STA ,X+
    LEAU -1, U
    CMPU #0
    BNE BANKLOADL1MV2

    JMP BANKLOADL1REPEAT

BANKLOADL1END
    LDA #0
    SWI
    FCB $22
    PULS D,Y,X,U
    JMP BANKLOADL1
BANKLOADL2
    LDA #$00
    STA $A7CB
    STA BANKSHADOW

@ENDIF

    ANDCC #$AF

    JSR DATAPREPARATION

@IF sysCallUsed

SYSCALLDONE

@ENDIF

    RTS

@IF sysCallUsed

SYSCALL
SYSCALL0
    JSR $0000
    BRA SYSCALLDONE

@ENDIF

WAITTIMER
    LDX MO5TIMER
WAITTIMERL1
    CMPX MO5TIMER
    BEQ WAITTIMERL1
    SUBD #1
    CMPD #0
    BNE WAITTIMER
    RTS
    