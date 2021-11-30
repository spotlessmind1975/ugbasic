; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
    LDD   #1          ; increment 
PC128TIMER  set *+1   ; (variable within code)
    ADDD  #0          ; add value of TI variable
    STD   PC128TIMER  ; write result to TI variable
    LDX   #0          ; get next ISR
PC128IRQN   set *-2   ; (variable within code)
    BEQ   PC128IRQ2   ; any defined ?
    LDA   #PAGE0
    TFR   A,DP        ; sets the basic DP
    JMP   ,X          ; yes ==> call it
PC128IRQ2
    JMP   >PC128IRQEND  ; no ==> jmp to the old one
PC128IRQO   set *-2   ; (variable within code)
PC128IRQEND
    RTI               ;  by defaut do RTI
    
PC128OPSTARTUP
    LDX   #$2061
    LDA   2,X         ; Is previous TIMERPT enable ?
    BEQ   PC128STARTUP2 ; no ==> keep default return code (RTI)
    LDD   ,X          ; yes ==> backup previous ISR
    STD   PC128IRQO   ;         and chain it at the end of our own
PC128STARTUP2    
    LDD   #PC128IRQ   ; install our own ISR
    STD   ,X
    LDA   #PAGE0      ; any non-zero value will do, let's use the one that'll go to DP
    STA   2,X         ; enable the ISR

    TFR   A,DP        ; setup direct-page
    CLRB
    TFR   D,X
    CLRA
MO5STARTUP3 
    STB   ,X+         ; clear direct-page
    DECA
    BNE   MO5STARTUP3
    
    LDB   #$14        ; shut down cursor
    SWI
    FCB   $02

    RTS
