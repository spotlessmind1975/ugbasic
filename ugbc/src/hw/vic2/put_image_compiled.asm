; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
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
;*                        COMPILED IMAGES ROUTINE FOR VIC2                     *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PUTCIMAGE2CALCPOS:

        LDA IMAGEY
        STA MATHPTR4
        LSR                         ;/ 2
        LSR                         ;/ 4
        LSR                         ;/ 8
        TAY                         ;tbl_8,y index

        CLC

        LDA IMAGEX
        ROR IMAGEX+1                ;rotate the high byte into carry flag
        ROR                        ;lo byte / 2 (rotate C into low byte)
        LSR                        ;lo byte / 4
        LSR                        ;lo byte / 8
        TAX                        ;tbl_8,x index

        CLC

        LDA PLOTVBASELO,Y          ;table of $A000 row base addresses
        ADC PLOT8LO,X              ;+ (8 * Xcell)
        STA PLOTDEST               ;= cell address

        LDA PLOTVBASEHI,Y          ;do the high byte
        ADC PLOT8HI,X
        STA PLOTDEST+1

        TXA
        ADC PLOTCVBASELO,Y          ;table of $8400 row base addresses
        STA PLOTCDEST               ;= cell address

        LDA #0
        ADC PLOTCVBASEHI,Y          ;do the high byte
        STA PLOTCDEST+1

        RTS

PUTCIMAGE3CALCPOS:

        LDA IMAGEY
        STA MATHPTR4
        LSR                         ;/ 2
        LSR                         ;/ 4
        LSR                         ;/ 8
        TAY                         ;tbl_8,y index

        CLC

        LDA IMAGEX
        ROR IMAGEX+1                ;rotate the high byte into carry flag
        ROR                        ;lo byte / 2 (rotate C into low byte)
        LSR                        ;lo byte / 4
        TAX                        ;tbl_8,x index

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

        RTS
    