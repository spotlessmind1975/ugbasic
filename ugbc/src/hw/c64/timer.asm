; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
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
;*                            TIMER ROUTINES ON C64                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TIMERMANAGER:

    ; First of all, we have to save the actual state of registers

    PHP
    PHA
    LDA TIMERRUNNING
    BEQ TIMERMANAGERGO
    PLA
    PLP
    RTS

TIMERMANAGERGO:
    TXA
    PHA
    TYA
    PHA

    LDA #1
    STA TIMERRUNNING

    ; loop through every specific timer status
    ; looking to the specific bit in the TIMERSTATUS
    ; control word.
    LDA TIMERSTATUS

    ; Up to 8 timers.
    LDX #0

TIMERMANAGERL1:

    ; Move the first bit into the carry.
    LSR

    ; If the carry is cleared, move to the next timer. 
    BCC TIMERMANAGERL2

    ; Disable the EVERY call for this timer.
    LDY #0
    JSR TIMERSETSTATUS
    
    PHA

    ; Retrieve the actual time counter, using the current
    ; index (X-1). The Y will be the offset starting from
    ; the TIMERCOUNTER base address: 
    ;
    ;       TIMERCOUNTER + (X-1) * 2 -> Y = (X-1) * 2
    ;
    TXA
    ASL
    TAY

    LDA #<TIMERCOUNTER
    STA MATHPTR0
    LDA #>TIMERCOUNTER
    STA MATHPTR0+1

    ; Now we are going to check if the timer is not zero.
    ; If not zero, we must decrement the counter.
    INY
    LDA (MATHPTR0), Y
    BNE TIMERMANAGERL2AH
    DEY
    LDA (MATHPTR0), Y
    BNE TIMERMANAGERL2AL

    ; Ok the counter is zero. So we must reset to the
    ; value we received previously, and call the routine.

    LDA #<TIMERINIT
    STA MATHPTR2
    LDA #>TIMERINIT
    STA MATHPTR2+1
    LDA (MATHPTR2), Y
    STA (MATHPTR0), Y
    INY
    LDA (MATHPTR2), Y
    STA (MATHPTR0), Y
    DEY

TIMERMANAGERJMP2:
    LDA #<TIMERADDRESS
    STA MATHPTR2
    LDA #>TIMERADDRESS
    STA MATHPTR2+1

    ; Now we are going to check if the address
    ; to call is zero. In this case, we must
    ; avoid to jump to it.
    INY
    LDA (MATHPTR2), Y
    BNE TIMERMANAGERJMP2AH
    DEY
    LDA (MATHPTR2), Y
    BNE TIMERMANAGERJMP2AL

    JMP TIMERMANAGERL2AL

TIMERMANAGERJMP:
    JMP $0000

TIMERMANAGERJMP2AH:
    DEY
TIMERMANAGERJMP2AL:
    LDA (MATHPTR2), Y
    STA TIMERMANAGERJMP+1
    INY
    LDA (MATHPTR2), Y
    STA TIMERMANAGERJMP+2
    DEY

    PHA
    TXA
    PHA
    TYA
    PHA

    JSR TIMERMANAGERJMP

    PLA
    TAY
    PLA
    TAX
    PLA

    ; If we reach this line, we are going to decrement the
    ; counter since it is not zero.
TIMERMANAGERL2AH:
    ; Move to the LSB
    DEY
TIMERMANAGERL2AL:
    ; 16 bit decrement
    LDA (MATHPTR0), Y
    SEC
    SBC #1
    STA (MATHPTR0), Y
    LDA (MATHPTR0), Y
    CMP #$FF
    BNE TIMERMANAGERL2ALD
    INY
    LDA (MATHPTR0), Y
    SEC
    SBC #1
    STA (MATHPTR0), Y
TIMERMANAGERL2ALD:

    PLA

    ; If we reach this line, we are going to check the next timer.
TIMERMANAGERL2:
    INX
    CPX #8
    BNE TIMERMANAGERL1

    ; Finally, restore the actual state of registers

    LDA #0
    STA TIMERRUNNING
    
    PLA
    TAY
    PLA
    TAX
    PLA
    PLP

    RTS

; TIMERSETSTATUS(X,Y)
TIMERSETSTATUS:
    LDA #1
    CPX #0
    BEQ TIMERSETSTATUSDONE
TIMERSETSTATUSL1:
    ASL
    DEX
    BNE TIMERSETSTATUSL1
TIMERSETSTATUSDONE:
    CPY #$0
    BEQ TIMERSETSTATUS0
TIMERSETSTATUS1:
    ORA TIMERSTATUS
    STA TIMERSTATUS
    RTS
TIMERSETSTATUS0:
    EOR #$FF
    AND TIMERSTATUS
    STA TIMERSTATUS
    RTS

; TIMERSETCOUNTER(X,MATHPTR2:MATHPTR3)
TIMERSETCOUNTER:
    LDA #<TIMERCOUNTER
    STA MATHPTR0
    LDA #>TIMERCOUNTER
    STA MATHPTR0+1

    TXA
    ASL
    TAY

    LDA MATHPTR2
    STA (MATHPTR0),Y
    INY
    LDA MATHPTR3
    STA (MATHPTR0),Y

    RTS

; TIMERSETINIT(X,MATHPTR2:MATHPTR3)
TIMERSETINIT:
    LDA #<TIMERINIT
    STA MATHPTR0
    LDA #>TIMERINIT
    STA MATHPTR0+1

    TXA
    ASL
    TAY

    LDA MATHPTR2
    STA (MATHPTR0),Y
    INY
    LDA MATHPTR3
    STA (MATHPTR0),Y

    RTS

; TIMERSETADDRESS(X,MATHPTR2:MATHPTR3)
TIMERSETADDRESS:
    LDA #<TIMERADDRESS
    STA MATHPTR0
    LDA #>TIMERADDRESS
    STA MATHPTR0+1

    TXA
    ASL
    TAY

    LDA MATHPTR2
    STA (MATHPTR0),Y
    INY
    LDA MATHPTR3
    STA (MATHPTR0),Y

    RTS
