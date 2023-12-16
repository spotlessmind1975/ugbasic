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
;*                            TIMER ROUTINES ON DRAGON 32                      *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

TIMERMANAGER

    ; First of all, we have to save the actual state of registers

    PSHS D
    LDA TIMERRUNNING
    BEQ TIMERMANAGERGO
    PULS D
    RTS

TIMERMANAGERGO

    PSHS X
    PSHS Y
    PSHS U
    PSHS DP

    ; Next, we update the RUNNING flag.
    LDA #1
    STA TIMERRUNNING

    ; loop through every specific timer status
    ; looking to the specific bit in the TIMERSTATUS
    ; control word.
    LDA TIMERSTATUS

    ; Up to 8 timers.
    LDB #0

TIMERMANAGERL1

    ; Move the first bit into the carry.
    LSRA

    ; If the carry is cleared, move to the next timer. 
    BCC TIMERMANAGERL2

    ; Disable the EVERY call for this timer.
    CLR MATHPTR0
    JSR TIMERSETSTATUS
    
    PSHS D
    PSHS X
    PSHS Y
    PSHS U

    ; Retrieve the actual time counter, using the current
    ; index (X-1). The Y will be the offset starting from
    ; the TIMERCOUNTER base address: 
    ;
    ;       TIMERCOUNTER + (X-1) * 2 -> Y = (X-1) * 2
    ;
    LSLB
    CLRA

    ; Now we are going to check if the timer is not zero.
    ; If not zero, we must decrement the counter.
    LDX #TIMERCOUNTER
    LEAX D, X
    LDY #TIMERINIT
    LEAY D, Y
    LDU #TIMERADDRESS
    LEAU D, U

    LDD ,X
    CMPD #0
    BNE TIMERMANAGERL2A
    
    ; Ok the counter is zero. So we must reset to the
    ; value we received previously, and call the routine.

    LDD , Y
    STD , X

TIMERMANAGERJMP2

    ; Now we are going to check if the address
    ; to call is zero. In this case, we must
    ; avoid to jump to it.

    LDD , U
    CMPD #0
    BNE TIMERMANAGERJMP2A

    JMP TIMERMANAGERL2A

TIMERMANAGERADD     fdb $0
TIMERMANAGERJMP
    JMP [TIMERMANAGERADD]

TIMERMANAGERJMP2A
    LDD , U
    STD TIMERMANAGERADD

    PSHS D
    PSHS X
    PSHS Y
    PSHS U
    PSHS DP

    JSR TIMERMANAGERJMP

    PULS DP
    PULS U
    PULS Y
    PULS X
    PULS D

    ; If we reach this line, we are going to decrement the
    ; counter since it is not zero.
TIMERMANAGERL2A
    LDD , X
    SUBD #1
    STD , X

TIMERMANAGERL2ALD

    PULS U
    PULS Y
    PULS X
    PULS D

    ; If we reach this line, we are going to check the next timer.
TIMERMANAGERL2
    INCB
    CMPB #8
    BNE TIMERMANAGERL1

    ; Finally, restore the actual state of registers

    LDA #0
    STA TIMERRUNNING
    
    PULS DP
    PULS U
    PULS Y
    PULS X
    PULS D

    RTS

; TIMERSETSTATUS(B,MATHPTR0)
TIMERSETSTATUS
    LDA #1
    CMPB #0
    BEQ TIMERSETSTATUSDONE
TIMERSETSTATUSL1
    ASLA
    DECB
    BNE TIMERSETSTATUSL1
TIMERSETSTATUSDONE
    LDB MATHPTR0
    CMPB #$0
    BEQ TIMERSETSTATUS0
TIMERSETSTATUS1
    ORA TIMERSTATUS
    STA TIMERSTATUS
    RTS
TIMERSETSTATUS0
    EORA #$FF
    ANDA TIMERSTATUS
    STA TIMERSTATUS
    RTS

; TIMERSETCOUNTER(B,MATHPTR2:MATHPTR3)
TIMERSETCOUNTER
    PSHS D
    PSHS X
    LDX #TIMERCOUNTER
    ASLB
    CLRA
    LEAX D, X
    LDD MATHPTR2
    STD , X
    PULS X
    PULS D
    RTS

; TIMERSETINIT(B,MATHPTR2:MATHPTR3)
TIMERSETINIT
    PSHS D
    PSHS X
    LDX #TIMERINIT
    ASLB
    CLRA
    LEAX D, X
    LDD MATHPTR2
    STD , X
    PULS X
    PULS D
    RTS

; TIMERSETADDRESS(B,MATHPTR2:MATHPTR3)
TIMERSETADDRESS
    PSHS D
    PSHS X
    LDX #TIMERADDRESS
    ASLB
    CLRA
    LEAX D, X
    LDD MATHPTR2
    STD , X
    PULS X
    PULS D
    RTS
