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
;*           STARTUP ROUTINE ON THOMSON MO6/OLLIVETTI TO8 PRODEST            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PAGE0 equ $61

; TIMER service routine
TO8IRQ
    PSHS  D
    LDD   #0              ; TI variable
TO8TIMER  set *-2       ; (variable within code)
    ADDD  #1              ; increment
    STD   TO8TIMER      ; write result to TI variable
    LDA   #PAGE0          ; sets the direct page
    TFR   A,DP            ; for ugbc routines
    JSR   KBDMANAGER
@IF deployed.timer
    JSR   TIMERMANAGER
@ENDIF
    PULS  D
    JMP   >TO8IRQDEF    ; jump to next ISR
TO8IRQN   set *-2       ; (variable within code)

; defaut service routine
TO8IRQDEF
    JMP   >TO8IRQEMPTY  ; jmp to the previous routine
TO8IRQO   set *-2       ; (variable within code)

; empty service routine
TO8IRQEMPTY
    RTI                   ;  by defaut do RTI

TO8IRQOINIT     fcb $0

TO8STARTUP
    ORCC #$50
    LDA   TO8IRQOINIT
    BNE   TO8STARTUPNOIRQ
    LDA   #1
    STA   TO8IRQOINIT    
    LDX   #$6027
    LDA   2,X             ; Is previous TIMERPT enable ?
    BEQ   TO8STARTUP2   ; no ==> keep default return code (RTI)
    LDD   ,X              ; yes ==> backup previous ISR
    STD   TO8IRQO       ;         and chain it at the end of our own
TO8STARTUP2
    LDD   #TO8IRQ       ; install our own ISR
    STD   ,X
    LDD   #2500
    STD   $E7C6
TO8STARTUPNOIRQ
    LDA   #PAGE0          ; any non-zero value will do, let's use the one that'll go to DP
    STA   2,X             ; enable the ISR

    TFR   A,DP        ; setup direct-page
    CLRB
    TFR   D,X
    CLRA
TO8STARTUP3 
    STB   ,X+         ; clear direct-page
    DECA
    BNE   TO8STARTUP3

    LDA $6019
    ANDA #$FB
    STA $6019

    LDA #1
    STA $6073

    ANDCC #$AF

    LDD #$0
TO8STARTUPL1
    ADDD #$1
    STD <MATHPTR0
    CMPD #$3100
    BNE TO8STARTUPL1

    LDA TO8TIMER+1
    CMPA #40
    BLE TO8NTSC

TO8PAL
    LDA #50
    STA TICKSPERSECOND
    JMP TO8STARTUPDONE

TO8NTSC
    LDA #60
    STA TICKSPERSECOND
    JMP TO8STARTUPDONE

TO8STARTUPDONE

    ORCC  #$50

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
    LBEQ BANKLOADL2

    STA $E7E5
    INCB

    PSHS D,Y,X,U

    ; motor on

    LDA #1
    STA $6029
    JSR $E815
    LBCS BANKLOADL2

    LDX #$A000

    ; move forward to the first data block

    LDU #50

BANKLOADL1SKIP
    LDA #2
    STA $6029
    JSR $E815
    LBCS BANKLOADL2
    LEAU -1, U
    CMPU #0
    LBNE BANKLOADL1SKIP

BANKLOADL1SIZE

    ; read size

    LDA #2
    STA $6029
    JSR $E815
    LBCS BANKLOADL2

    ; read bytes

    CLRA
    SUBD #5
    TFR D, U

    ; skip

    LDA #2
    STA $6029
    JSR $E815
    LBCS BANKLOADL2
    JSR $E815
    LBCS BANKLOADL2
    JSR $E815
    LBCS BANKLOADL2
    JSR $E815
    LBCS BANKLOADL2
    JSR $E815
    LBCS BANKLOADL2

BANKLOADL1REPEAT

    LDA #2
    STA $6029
    JSR $E815
    LBCS BANKLOADL2
    STB ,X+
    LEAU -1, U
    CMPU #0
    BNE BANKLOADL1REPEAT

    ; skip checksum

    LDA #2
    STA $6029
    JSR $E815

BANKLOADL1END

    ; move forward to the next data type

    LDU #14

    ; read last block?

    LDA #2
    STA $6029
    JSR $E815
    BCS BANKLOADL2

    CMPB #$DC
    BEQ BANKLOADL2SKIP

    LEAU -2, U

BANKLOADL2SKIP
    LDA #2
    STA $6029
    JSR $E815
    BCS BANKLOADL2
    LEAU -1, U
    CMPU #0
    BNE BANKLOADL2SKIP

    ; end of data?
    
    CMPB #$FF
    BEQ BANKLOADLEOD

    ; read size 

    LDA #2
    STA $6029
    JSR $E815
    CLRA
    TFR D, U

    ; read next block

    JMP BANKLOADL1REPEAT

BANKLOADLEOD

    LDA #2
    STA $6029
    JSR $E815

    LDA #2
    STA $6029
    JSR $E815

    PULS D,Y,X,U

    LDA #$1F
    STA $E7E5

    JMP BANKLOADL1

BANKLOADL2

    LDA #16
    STA $6029
    JSR $E815

    LDA #$1F
    STA $E7E5

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
    LDX TO8TIMER
WAITTIMERL1
    CPX TO8TIMER
    BEQ WAITTIMERL1
    SUBD #1
    CMPD #0
    BNE WAITTIMER
    RTS
    
