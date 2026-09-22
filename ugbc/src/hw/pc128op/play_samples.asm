; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
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
;*                           PLAY SAMPLES ON PC128OP                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PLAYSAMPLES

    ORCC #$50

    LDA $A7CF
    ANDA #$FB 
    STA $A7CF
    LDB #$3F
    STB $A7CD
    ORA #$04
    STA $A7CF

PLAYSAMPLESL1
    LDA ,X+
    BEQ PLAYSAMPLESDONE

    PSHS D
    ANDA #$0F
    LSLA
    LSLA
    STA $A7CD

    NOP
    BRA PLAYSAMPLESNOP
PLAYSAMPLESNOP

    LDB #20
PLAYSAMPLESL2L
    DECB
    BNE PLAYSAMPLESL2L

    PULS D
    ANDA #$F0
    LSRA
    LSRA
    STA $A7CD

    LDB #20
PLAYSAMPLESL2H
    DECB
    BNE PLAYSAMPLESL2H

    JMP PLAYSAMPLESL1
PLAYSAMPLESDONE

    LDA #$0
    STA $A7CF
    STB $A7CD

    ANDCC #$AF
    RTS

PLAYSAMPLESEXP

    ORCC #$50

    STB <MATHPTR0
    STB BASE_SEGMENT+$E5

    LDA $A7CF
    ANDA #$FB 
    STA $A7CF
    LDB #$3F
    STB $A7CD
    ORA #$04
    STA $A7CF

PLAYSAMPLESEXPL1
    LDA ,X+
    BEQ PLAYSAMPLESEXPDONE

    PSHS D
    ANDA #$0F
    LSLA
    LSLA
    STA $A7CD

    NOP
    BRA PLAYSAMPLESNOPEXP
PLAYSAMPLESNOPEXP

    LDB #18
PLAYSAMPLESEXPL2L
    DECB
    BNE PLAYSAMPLESEXPL2L

    PULS D
    ANDA #$F0
    LSRA
    LSRA
    STA $A7CD

    LDB #18
PLAYSAMPLESEXPL2H
    DECB
    BNE PLAYSAMPLESEXPL2H

    CMPX #$8fff
    BNE PLAYSAMPLESEXPL1NO
    LDX #$6000
    LDB <MATHPTR0
    INCB	
    STB BASE_SEGMENT+$E5
    STB <MATHPTR0
    JMP PLAYSAMPLESEXPL1
PLAYSAMPLESEXPL1NO
    NOP
    NOP
    NOP
    NOP
    NOP
    JMP PLAYSAMPLESEXPL1
PLAYSAMPLESEXPDONE
    LDA #7
    STA BASE_SEGMENT+$E5

    LDA #$0
    STA $A7CF
    STB $A7CD

    ANDCC #$AF
    RTS
