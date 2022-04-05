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
;*                       CLEAR SCREEN ROUTINE FOR EF936X                       *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                     mc6809 optimization by Samuel Devulder                  *
;*               added support for double buffering by Marco Spedaletti        *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

CLS
    PSHS  DP

@IF vestigialConfig.screenModeUnique

@ELSE
    LDA CURRENTMODE
    BEQ CLS0
    DECA
    BEQ CLS1
    DECA
    BEQ CLS2
    DECA
    BEQ CLS3
    DECA
    BEQ CLS4
    PULS DP,PC
@ENDIF

@IF ( !vestigialConfig.screenModeUnique ) || ( currentMode == 2 )
CLS2
    CLRA
    LDB _PAPER
    LSRB
    SBCA #0

    LSRB
    LDB #1-1 ; important not 0 or else the optimzer will CLRB which clears the carry
    SBCB #0

    LDU #0
    LEAU B,U
    TFR A,B
    BRA CLSG
@ENDIF


@IF ( !vestigialConfig.screenModeUnique ) || ( currentMode == 3 )
CLS3
    LDA _PAPER
    ANDA #$0F
    LDB #$11
    MUL
    TFR B,A
    TFR D,U
    BRA CLSG
@ENDIF

@IF ( ! vestigialConfig.screenModeUnique ) || ( ( currentMode == 0 ) || ( currentMode == 1 ) || ( currentMode == 4 ) )
CLS0
CLS1
CLS4
    LDA _PEN
    ASLA
    ASLA
    ASLA
    ASLA
    STA ,-S
    LDA _PAPER
    ANDA #$0F
    ORA ,S+
    TFR A,B
    LDU #0
@ENDIF

CLSG
@IF vestigialConfig.doubleBufferSelected

@ELSE
    ; Check if double buffering is active -- in case,
    ; whe should use a different version.
    PSHS D
    LDA DOUBLEBUFFERENABLED
    CMPA #0
    BEQ CLSGORIG
    PULS D
@ENDIF


; ----------------------------------------------
; Version active on double buffering ON
; ----------------------------------------------

@IF ( !vestigialConfig.doubleBufferSelected ) || ( vestigialConfig.doubleBuffer )

    LDY BITMAPADDRESS
CLSGDB
    STA ,Y+
    CMPY #$7FFF 
    BNE CLSGDB
    LDA #0
CLSGDB2
    STA ,Y+
    CMPY #$9FFF 
    BNE CLSGDB2
    PULS DP,PC

@ENDIF

; ----------------------------------------------
; Version active on double buffering OFF
; ----------------------------------------------

@IF ( !vestigialConfig.doubleBufferSelected ) || ( !vestigialConfig.doubleBuffer )

CLSGORIG
    PULS D
    LDX BITMAPADDRESS
    LEAX 10,X
    PSHS D,U
    LDD CURRENTFRAMESIZE
    LEAU D,X
    STU CLSGL2+1
    LDA #$A7
    TFR A,DP
    LDA <$C0
    ANDA #$FE
    STA <$C0

    PULS D,U
CLSGL1
    INC <$C0
    STU -10,X
    STU -8,X
    STU -6,X
    STU -4,X
    STU -2,X
    STU ,X
    STU 2,X
    STU 4,X
    STU 6,X
    STU 8,X
    DEC <$C0
    STD -10,X
    STD -8,X
    STD -6,X
    STD -4,X
    STD -2,X
    STD ,X
    STD 2,X
    STD 4,X
    STD 6,X
    STD 8,X
    LEAX 20,X
CLSGL2
    CMPX #$5555
    BLO CLSGL1
    PULS DP,PC

@ENDIF
