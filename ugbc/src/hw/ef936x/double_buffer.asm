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
;     ; by Dino Florenzi
;     TFR S,X
;     PSHS X
;     LDD #STACKEND
;     SUBD ,S
;     TFR D, U
;     LDX #STACKEND
;     LDS #$2000
;     LEAX -1, X
;     LEAS -1, S
; DOUBLEBUFFERINITSTACK
;     LDA , X
;     STA , S
;     LEAX -1, X
;     LEAS -1, S
;     LEAU -1, U
;     CMPU #0
;     BNE DOUBLEBUFFERINITSTACK
;     LEAS 1, S

@IF TO8

	LDB	$6181
 	ORB	#$50
 	STB	$6081
    STB BASE_SEGMENT+$E7
    LDB #%0110000
    STB BASE_SEGMENT+$E6
    
@ENDIF

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
    LDD #STACKEND
    SUBD #1
    SUBD ,S
    TFR D, U
    LDX #$2000
    LDS #STACKEND
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
    STB BASE_SEGMENT+$DD
    LDB #$00
    ; STB BASE_SEGMENT+$E5
    STB BANKSHADOW
    JSR ONSWITCHTILEMAP
    LDA #$0
    STA TILEMAPVISIBLE
    RTS

SWITCHTILEMAP
    LDA TILEMAPVISIBLE
    BEQ SWITCHTILEMAP1

SWITCHTILEMAP0

@IF TO8

    LDB #$00
 	STB	BASE_SEGMENT+$DD
    LDB #$62
 	STB	BASE_SEGMENT+$E6
 	CLR	BASE_SEGMENT+$CF

@ELSE

    LDB #$80
    STB BASE_SEGMENT+$DD
    LDB #$03
    ; STB BASE_SEGMENT+$E5
    STB BANKSHADOW

@ENDIF

    JSR ONSWITCHTILEMAP

@IF TO8

    LDD #$0000
    STD BITMAPADDRESS

@ELSE

    LDD #$6000
    STD BITMAPADDRESS

@ENDIF

    LDA #$0
    STA TILEMAPVISIBLE

    RTS

SWITCHTILEMAP1

@IF TO8

 	LDB #$80
 	STB	BASE_SEGMENT+$DD
 	LDB #$60
 	STB	BASE_SEGMENT+$E6
 	CLR	BASE_SEGMENT+$CF

@ELSE

    LDB #$C0
    STB BASE_SEGMENT+$DD
    LDB #$02
    ; STB BASE_SEGMENT+$E5
    STB BANKSHADOW

@ENDIF

    JSR ONSWITCHTILEMAP

@IF TO8

    LDD #$0000
    STD BITMAPADDRESS

@ELSE

    LDD #$6000
    STD BITMAPADDRESS

@ENDIF

    LDA #$1
    STA TILEMAPVISIBLE
    
    RTS
    