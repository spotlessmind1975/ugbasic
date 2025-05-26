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
;*           STARTUP ROUTINE ON THOMSON MO6/OLLIVETTI PC128 PRODEST            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PAGE0 equ $21

; TIMER service routine
PC128IRQ
    PSHS  D
    LDD   #0              ; TI variable
PC128TIMER  set *-2       ; (variable within code)
    ADDD  #1              ; increment
    STD   PC128TIMER      ; write result to TI variable
    LDA   #PAGE0          ; sets the direct page
    TFR   A,DP            ; for ugbc routines
@IF deployed.sn76489mstartup
    JSR   SN76489TIMERMANAGER
@ENDIF
@IF deployed.music
    JSR   MUSICPLAYER
@ENDIF
@IF deployed.timer
    JSR   TIMERMANAGER
@ENDIF
@IF deployed.keyboard && ( keyboardFullSupport || ! keyboardConfig.sync )
    JSR KEYBOARDMANAGER
@ENDIF
    PULS  D
    JMP   >PC128IRQDEF    ; jump to next ISR
PC128IRQN   set *-2       ; (variable within code)

; defaut service routine
PC128IRQDEF
    JMP   >PC128IRQEMPTY  ; jmp to the previous routine
PC128IRQO   set *-2       ; (variable within code)

; empty service routine
PC128IRQEMPTY
    RTI                   ;  by defaut do RTI

PC128OPIRQOINIT     fcb $0

PC128OPSTARTUP
    ORCC #$50
    LDA   PC128OPIRQOINIT
    BNE   PC128OPSTARTUPNOIRQ
    LDA   #1
    STA   PC128OPIRQOINIT    
    LDX   #$2061
    LDA   2,X             ; Is previous TIMERPT enable ?
    BEQ   PC128STARTUP2   ; no ==> keep default return code (RTI)
    LDD   ,X              ; yes ==> backup previous ISR
    STD   PC128IRQO       ;         and chain it at the end of our own
PC128STARTUP2
    LDD   #PC128IRQ       ; install our own ISR
    STD   ,X
PC128OPSTARTUPNOIRQ
    LDA   #PAGE0          ; any non-zero value will do, let's use the one that'll go to DP
    STA   2,X             ; enable the ISR

    TFR   A,DP        ; setup direct-page
    CLRB
    TFR   D,X
    CLRA
PC128STARTUP3 
    STB   ,X+         ; clear direct-page
    DECA
    BNE   PC128STARTUP3

    LDB   #$14            ; shut down cursor
    SWI
    FCB   $02

    ANDCC #$AF

    LDD #$0
PC128STARTUPL1
    ADDD #$1
    STD <MATHPTR0
    CMPD #$3100
    BNE PC128STARTUPL1

    LDA PC128TIMER+1
    CMPA #40
    BLE PC128NTSC

PC128PAL
    LDA #50
    STA TICKSPERSECOND
    JMP PC128STARTUPDONE

PC128NTSC
    LDA #60
    STA TICKSPERSECOND
    JMP PC128STARTUPDONE

PC128STARTUPDONE

    ORCC #$50

    LDB   #0
    STB   $2076
    LDB   $2019
    ORB   #8
    STB   $2019

    LDU #BANKLOAD
    LDB #0
BANKLOADL1
    LDA B,U
    CMPA #$FF
    BEQ BANKLOADL2
    STA BASE_SEGMENT+$E5
    INCB

    PSHS D,Y,X,U
    LDX #$6000

    LDA #1
    SWI
    FCB $22

BANKLOADL1REPEAT

    LDY #$9F00

    LDA #1
    LDB #0
    SWI
    FCB $20

    CMPB #0
    BEQ BANKLOADL1REPEAT
    CMPB #$FF
    BEQ BANKLOADL1END

    CMPX #$6000
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
    FCB   $22
    PULS D,Y,X,U
    JMP BANKLOADL1
BANKLOADL2
    ; INCB
    ; CMPB #7
    ; BNE BANKLOADL1
    LDA #7
    STA BASE_SEGMENT+$E5
    STA BANKSHADOW

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
    LDX PC128TIMER
WAITTIMERL1
    CMPX PC128TIMER
    BEQ WAITTIMERL1
    SUBD #1
    CMPD #0
    BNE WAITTIMER
    RTS
    
