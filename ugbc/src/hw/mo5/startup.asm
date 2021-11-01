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
;*                          STARTUP ROUTINE ON DRAGON 32                       *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

MO5TIMER      fdb $0
MO5IRQO       fdb MO5IRQ3
MO5IRQN       fdb $0

MO5IRQ
    LDD   MO5TIMER
    ADDD  #1
    STD   MO5TIMER
    LDX   MO5IRQN
    BEQ   MO5IRQ2
    JSR   ,X
MO5IRQ2
    JMP   [MO5IRQO]
MO5IRQ3
    RTI
    
MO5STARTUP
    LDX   #$2061
    LDA   2,X
    BEQ   MO5STARTUP2
    LDD   ,X
    STD   MO5IRQO
MO5STARTUP2    
    LDD   #MO5IRQ
    STD   ,X
;   LDA   #1   <== any non zero will do, but since $00xx point to video ram, we know for sure that A=highbyte(MO5IRQ) will never be 0 ;)
    STA   2,X

    LDA   #$20
    TFR   A,DP
    RTS