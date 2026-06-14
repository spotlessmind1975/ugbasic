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
;*                        COMPILED IMAGES ROUTINE FOR GTIA                     *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 8 ) )

PUTCIMAGE8CALCPOS:

    LDA IMAGEX
    LSR                        ;lo byte / 2
    LSR                        ;lo byte / 4
    TAX                        ;tbl_8,x index

    LDA IMAGEY
    TAY                         ;tbl_8,y index

    CLC

    LDA PLOT4VBASELO,Y          ;table of $9C40 row base addresses
    ADC PLOT4LO,X              ;+ (4 * Xcell)
    STA PLOTDEST               ;= cell address

    LDA PLOT4VBASEHI,Y          ;do the high byte
    ADC PLOT4HI,X
    STA PLOTDEST+1

    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 9 ) )

PUTCIMAGE9CALCPOS:

    LDA IMAGEX
    LSR                        ;lo byte / 2
    LSR                        ;lo byte / 4
    LSR                        ;lo byte / 8
    TAX                        ;tbl_8,x index

    LDA IMAGEY
    TAY                         ;tbl_8,y index

    CLC

    TXA
    ADC PLOT4VBASELO,Y          ;table of $9C40 row base addresses
    STA PLOTDEST               ;= cell address

    LDA #0
    ADC PLOT4VBASEHI,Y          ;do the high byte
    STA PLOTDEST+1

    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 10 ) )

PUTCIMAGE10CALCPOS:

    LDA IMAGEX
    LSR                        ;lo byte / 2
    LSR                        ;lo byte / 4
    TAX                        ;tbl_8,x index

    LDA IMAGEY
    TAY                         ;tbl_8,y index

    CLC

    TXA
    ADC PLOT5VBASELO,Y          ;table of $9C40 row base addresses
    STA PLOTDEST               ;= cell address

    LDA #0
    ADC PLOT5VBASEHI,Y          ;do the high byte
    STA PLOTDEST+1

    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 11 ) )

PUTCIMAGE11CALCPOS:

    LDA IMAGEX
    LSR                        ;lo byte / 2
    LSR                        ;lo byte / 4
    LSR                        ;lo byte / 8
    TAX                        ;tbl_8,x index

    LDA IMAGEY
    TAY                         ;tbl_8,y index

    CLC

    TXA
    ADC PLOT5VBASELO,Y          ;table of $9C40 row base addresses
    STA PLOTDEST               ;= cell address

    LDA #0
    ADC PLOT5VBASEHI,Y          ;do the high byte
    STA PLOTDEST+1

    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 12 ) )

PUTCIMAGE12CALCPOS:

    LDA IMAGEX
    ROR IMAGEX+1                ;rotate the high byte into carry flag
    ROR                        ;lo byte / 2
    LSR                        ;lo byte / 4
    LSR                        ;lo byte / 8
    TAX                        ;tbl_8,x index

    LDA IMAGEY
    TAY                         ;tbl_8,y index

    CLC

    TXA
    ADC PLOT5VBASELO,Y          ;table of $9C40 row base addresses
    STA PLOTDEST               ;= cell address

    LDA #0
    ADC PLOT5VBASEHI,Y          ;do the high byte
    STA PLOTDEST+1

    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 13 ) )

PUTCIMAGE13CALCPOS:

    LDA IMAGEX
    LSR                        ;lo byte / 2
    LSR                        ;lo byte / 4
    TAX                        ;tbl_8,x index

    LDA IMAGEY
    TAY                         ;tbl_8,y index

    CLC

    TXA
    ADC PLOT6VBASELO,Y          ;table of $9C40 row base addresses
    STA PLOTDEST               ;= cell address

    LDA #0
    ADC PLOT6VBASEHI,Y          ;do the high byte
    STA PLOTDEST+1

    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 14 ) )

PUTCIMAGE14CALCPOS:

    LDA IMAGEX
    LSR                        ;lo byte / 2
    LSR                        ;lo byte / 4
    TAX                        ;tbl_8,x index

    LDA IMAGEY
    TAY                         ;tbl_8,y index

    CLC

    TXA
    ADC PLOT5VBASELO,Y          ;table of $9C40 row base addresses
    STA PLOTDEST               ;= cell address

    LDA #0
    ADC PLOT5VBASEHI,Y          ;do the high byte
    STA PLOTDEST+1

    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 15 ) )

PUTCIMAGE15CALCPOS:

    LDA IMAGEX
    ROR IMAGEX+1                ;rotate the high byte into carry flag
    ROR                        ;lo byte / 2
    LSR                        ;lo byte / 4
    LSR                        ;lo byte / 8
    TAX                        ;tbl_8,x index

    LDA IMAGEY
    TAY                         ;tbl_8,y index

    CLC

    TXA
    ADC PLOT6XVBASELO,Y          ;table of $9C40 row base addresses
    STA PLOTDEST               ;= cell address

    LDA #0
    ADC PLOT6XVBASEHI,Y          ;do the high byte
    STA PLOTDEST+1

    RTS

@ENDIF

