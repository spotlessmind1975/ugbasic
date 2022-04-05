; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2022 Marco Spedaletti (asimov@mclink.it)
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
;*                      DOUBLE BUFFER ROUTINE ON EF936X                        *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

ONSWITCHTILEMAPVOID
    RTS

ONSWITCHTILEMAP
    JMP ONSWITCHTILEMAPVOID

DOUBLEBUFFERINIT
    ; by Dino Florenzi
    TFR S,X
    PSHS X
    LDD #$A000
    SUBD ,S
    TFR D, U
    LDX #$A000
    LDS #$2000
    LEAX -1, X
    LEAS -1, S
DOUBLEBUFFERINITSTACK
    LDA , X
    STA , S
    LEAX -1, X
    LEAS -1, S
    LEAU -1, U
    CMPU #0
    BNE DOUBLEBUFFERINITSTACK
    LEAS 1, S

    LDA #1
    STA DOUBLEBUFFERENABLED
    JSR SWITCHTILEMAP0
    JSR CLS
    JSR SWITCHTILEMAP1
    JSR CLS
    JSR SWITCHTILEMAP0
    RTS

DOUBLEBUFFERCLEANUP
    TFR S,X
    PSHS X
    LDD #$1FFF
    SUBD ,S
    TFR D, U
    LDX #$2000
    LDS #$A000
    LEAX -1, X
    LEAS -1, S
DOUBLEBUFFERCLEANUPSTACK
    LDA , X
    STA , S
    LEAX -1, X
    LEAS -1, S
    LEAU -1, U
    CMPU #0
    BNE DOUBLEBUFFERCLEANUPSTACK
    LEAS 1, S

    LDD $0000
    STD BITMAPADDRESS
    STA DOUBLEBUFFERENABLED
DOUBLEBUFFERCLEANUP2
    LDB #$00
    STB $A7DD
    LDB #$00
    STB $A7E5
    STB BANKSHADOW
    JSR ONSWITCHTILEMAP
    LDA #$0
    STA TILEMAPVISIBLE
    RTS

SWITCHTILEMAP
    LDA TILEMAPVISIBLE
    BEQ SWITCHTILEMAP1

SWITCHTILEMAP0
    LDB #$80
    STB $A7DD
    LDB #$03
    STB $A7E5
    STB BANKSHADOW
    JSR ONSWITCHTILEMAP
    LDA #$0
    STA TILEMAPVISIBLE
    LDD #$6000
    STD BITMAPADDRESS
    RTS

SWITCHTILEMAP1
    LDB #$C0
    STB $A7DD
    LDB #$02
    STB $A7E5
    STB BANKSHADOW
    JSR ONSWITCHTILEMAP
    LDA #$1
    STA TILEMAPVISIBLE
    LDD #$6000
    STD BITMAPADDRESS
    RTS
    