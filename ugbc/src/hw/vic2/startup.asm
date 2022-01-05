; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
;*                           STARTUP ROUTINE ON VIC-II                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

VIC2STARTUP:

    SEI
    LDX #$10
    LDA #$33
    STA $01
    LDA #$D0
    STA $FC
    LDY #$00
    STY $FB
    LDA #$90
    STA $FE
    LDY #$00
    STY $FD
VIC2STARTUPL1:
    LDA ($FB),Y
    STA ($FD),Y
    INY
    BNE VIC2STARTUPL1
    INC $FC
    INC $FE
    DEX
    BNE VIC2STARTUPL1
    LDA #$35
    STA $01
    CLI

    ; SET_DATA_DIRECTION();
    LDA $dd02
    ORA #$03
    STA $dd02

    ; SET_BANK(2);
    LDA $dd00
    AND #$fc
    ORA #$01
    STA $dd00

    ; SET_BACKGROUND_COLOR( MR_COLOR_BLACK );
    LDA #0
    STA $d021

    ; SET_VIDEO(MR_SCREEN_DEFAULT);
    LDA $d018
    AND #$0f
    ORA #$10
    STA $d018

    ; SET_BASIC_VIDEO(MR_SCREEN_DEFAULT);
    AND #$84
    STA $0288

    ; SET_CHARSET(MR_TILESET_DEFAULT);
    LDA $d018
    AND #$f1
    ORA #$08
    STA $d018

    ; SET STARTUP CURSOR POSITION    
    LDA #0
    STA $D3
    LDA #0
    STA $D6

    RTS