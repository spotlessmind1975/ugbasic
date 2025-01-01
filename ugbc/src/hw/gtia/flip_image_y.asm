; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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
;*                          FLIP Y ROUTINE FOR GTIA                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; ----------------------------------------------------------------------------
; - Flip image
; ----------------------------------------------------------------------------

FLIPIMAGEY:

@IF !vestigialConfig.screenModeUnique

    LDA CURRENTMODE
    CMP #8
    BNE FLIPIMAGEY8X
    JMP FLIPIMAGEY8
FLIPIMAGEY8X:
    CMP #9
    BNE FLIPIMAGEY9X
    JMP FLIPIMAGEY9
FLIPIMAGEY9X:
    CMP #10
    BNE FLIPIMAGEY10X
    JMP FLIPIMAGEY10
FLIPIMAGEY10X:
    CMP #11
    BNE FLIPIMAGEY11X
    JMP FLIPIMAGEY11
FLIPIMAGEY11X:
    CMP #13
    BNE FLIPIMAGEY13X
    JMP FLIPIMAGEY13
FLIPIMAGEY13X:
    CMP #15
    BNE FLIPIMAGEY15X
    JMP FLIPIMAGEY15
FLIPIMAGEY15X:
    CMP #12
    BNE FLIPIMAGEY12X
    JMP FLIPIMAGEY12
FLIPIMAGEY12X:
    CMP #14
    BNE FLIPIMAGEY14X
    JMP FLIPIMAGEY14
FLIPIMAGEY14X:
    RTS

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 9 ) )

FLIPIMAGEY9:
    JMP FLIPIMAGEYCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 11 ) )

FLIPIMAGEY11:
    JMP FLIPIMAGEYCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 15 ) )

FLIPIMAGEY15:

    JMP FLIPIMAGEYCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 12 ) )

FLIPIMAGEY12:

    JMP FLIPIMAGEYCOMMON

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 8 ) )

FLIPIMAGEY8:

    JMP FLIPIMAGEYCOMMONC

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 10 ) )

FLIPIMAGEY10:

    JMP FLIPIMAGEYCOMMONC

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 13 ) )

FLIPIMAGEY13:

    JMP FLIPIMAGEYCOMMONC

@ENDIF

@IF !vestigialConfig.screenModeUnique || ( ( currentMode == 14 ) )

FLIPIMAGEY14:

    JMP FLIPIMAGEYCOMMONC

@ENDIF

FLIPIMAGEYCOMMON:

    ; Retrieve the width (in bytes) and the height 
    ; (in bytes) of the image to flip horizontally.

    LDY #0
    LDA (TMPPTR),Y
    STA IMAGEW
    LDY #1
    LDA (TMPPTR),Y
    STA IMAGEW+1
    LSR IMAGEW+1
    ROR IMAGEW
    LSR IMAGEW+1
    ROR IMAGEW
    LSR IMAGEW+1
    ROR IMAGEW
    LDY #2
    LDA (TMPPTR),Y
    STA IMAGEH
    STA IMAGEH2

    ; Move the image pointer ahead of header.

    CLC
    LDA TMPPTR
    ADC #3
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    ; This is the beginning of the line flip loop.

    JMP FLIPIMAGEYCOMMONCL0

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

FLIPIMAGEYCOMMONC:

    ; Retrieve the width (in bytes) and the height 
    ; (in bytes) of the image to flip horizontally.

    LDY #0
    LDA (TMPPTR),Y
    STA IMAGEW
    LDY #1
    LDA (TMPPTR),Y
    STA IMAGEW+1
    LSR IMAGEW+1
    ROR IMAGEW
    LSR IMAGEW+1
    ROR IMAGEW
    LDY #2
    LDA (TMPPTR),Y
    STA IMAGEH
    STA IMAGEH2

    ; Move the image pointer ahead of header.

    CLC
    LDA TMPPTR
    ADC #3
    STA TMPPTR
    LDA TMPPTR+1
    ADC #0
    STA TMPPTR+1

    ; This is the beginning of the line flip loop.

FLIPIMAGEYCOMMONCL0:

    ; Copy the starting line pointer to the ending line pointer.

    LDA TMPPTR
    STA TMPPTR2
    LDA TMPPTR+1
    STA TMPPTR2+1

    LDA IMAGEH
    TAX
    DEX
FLIPIMAGEYCOMMONCL0L:
    ; Move ahead the ending line pointer of 2 x IMAGE WIDTH - 1
    CLC
    LDA TMPPTR2
    ADC IMAGEW
    STA TMPPTR2
    LDA TMPPTR2+1
    ADC IMAGEW+1
    STA TMPPTR2+1
    DEX 
    BNE FLIPIMAGEYCOMMONCL0L

    LDA IMAGEH
    LSR
    TAX 

FLIPIMAGEYCOMMONCL1:
    LDY #0
FLIPIMAGEYCOMMONCLN:
    LDA (TMPPTR2),Y
    PHA
    LDA (TMPPTR),Y
    STA (TMPPTR2),Y
    PLA
    STA (TMPPTR),Y
    INY
    CPY IMAGEW
    BNE FLIPIMAGEYCOMMONCLN

    CLC
    LDA TMPPTR
    ADC IMAGEW
    STA TMPPTR
    LDA TMPPTR+1
    ADC IMAGEW+1
    STA TMPPTR+1

    SEC
    LDA TMPPTR2
    SBC IMAGEW
    STA TMPPTR2
    LDA TMPPTR2+1
    SBC IMAGEW+1
    STA TMPPTR2+1

    ; Decrement the number of lines to flip.

    DEX

    ; If not finished, repeat the loop.

    BNE FLIPIMAGEYCOMMONCL1

    RTS