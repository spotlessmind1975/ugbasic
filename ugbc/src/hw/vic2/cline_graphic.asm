; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2024 Marco Spedaletti (asimov@mclink.it)
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
;*                      CLEAR LINE ROUTINE FOR VIC-II                          *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CLINEG:
    LDA TEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA TEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1
    LDA COLORMAPADDRESS
    STA COPYOFCOLORMAPADDRESS
    LDA COLORMAPADDRESS+1
    STA COPYOFCOLORMAPADDRESS+1

    LDX CHARACTERS
    LDY #$0
CLINEGLOOP2:
CLINEGSP0:

    TXA
    PHA
    TYA
    PHA

    LDX CLINEX
    LDY CLINEY

    CLC

    LDA PLOTVBASELO,Y          ;table of $A000 row base addresses
    ADC PLOT8LO,X              ;+ (8 * Xcell)
    STA PLOTDEST               ;= cell address

    LDA PLOTVBASEHI,Y          ;do the high byte
    ADC PLOT8HI,X
    STA PLOTDEST+1

    CLC

    TXA
    ADC PLOTCVBASELO,Y          ;table of $8400 row base addresses
    STA PLOTCDEST               ;= cell address

    LDA #0
    ADC PLOTCVBASEHI,Y          ;do the high byte
    STA PLOTCDEST+1

    CLC

    TXA
    ADC PLOTC2VBASELO,Y          ;table of $8400 row base addresses
    STA PLOTC2DEST               ;= cell address

    LDA #0
    ADC PLOTC2VBASEHI,Y          ;do the high byte
    STA PLOTC2DEST+1

    LDY #0
    TYA
    PHA
CLINEGSP0L1:
    LDA CURRENTMODE
    CMP #3
    BEQ CLINEGSP0L1B3

CLINEGSP0L1B2:
    LDA #0
    STA (PLOTDEST),Y
    JMP CLINEGSP0L1X

CLINEGSP0L1B3:
    LDA #0
    STA (PLOTDEST),Y
    JMP CLINEGSP0L1X

CLINEGSP0L1X:
    INY
    CPY #8
    BNE CLINEGSP0L1
 
    LDA CURRENTMODE
    CMP #3
    BEQ CLINEGC3

    LDY #0
    LDA (PLOTCDEST),Y
    AND #$0F
    ORA _PEN
    STA (PLOTCDEST),Y
    LDA (PLOTCDEST),Y
    AND #$f0
    ORA _PAPER
    STA (PLOTCDEST),Y
    JMP CLINEGF

CLINEGC3:
    LDY #0
    LDA _PEN
    STA (PLOTC2DEST),Y
    LDA #0
    STA (PLOTCDEST),Y
    LDA _PEN
    ASL
    ASL
    ASL
    ASL
    ORA (PLOTCDEST),Y
    STA (PLOTCDEST),Y
    JMP CLINEGF

CLINEGF:
    PLA
    PLA
    TAY
    PLA
    TAX
    JMP CLINEGINCX

CLINEGINCX:
    INC CLINEX
    LDA CLINEX
    CMP CONSOLEX2
    BCS CLINEGNEXT2
    JMP CLINEGNEXT
CLINEGNEXT2:
    RTS
CLINEGNEXT:
    INY
    DEX
    BEQ CLINEGEND
    JMP CLINEGLOOP2
CLINEGEND:
    RTS
