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
;*                       PREPROCESSING FOR GTIA HARDWARE                       *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

@IF vestigialConfig.palettePreserve == 1

FINDLASTCOLORUSED:
    LDA PALETTEPRESERVEUSED
    BEQ FINDLASTCOLORUSEDNONE
    LDX #1
FINDLASTCOLORUSEDL1:
    LSR
    BCC FINDLASTCOLORUSEDFOUND
    INX
    JMP FINDLASTCOLORUSEDL1

FINDLASTCOLORUSEDNONE:
    LDA #4
    RTS

FINDLASTCOLORUSEDFOUND:
    TXA
    RTS

@MACRO PALETTEPRESERVE2C4 value, increment
@@
@@  LDA PALETTEPRESERVEUSED
@@  AND #$1
@@  CMP #$1
@@  BEQ PALETTEPRESERVE1_label
@@
@@  LDA value
@@  CMP #$FF
@@  BEQ PALETTEPRESERVE1_labelb2
@@  STA $02C4
@@
@@  LDA PALETTEPRESERVEUSED
@@  ORA #$1
@@  STA PALETTEPRESERVEUSED
@@
@@PALETTEPRESERVE1_label:
@@
@@  LDA increment
@@  CMP #$1
@@  BNE PALETTEPRESERVE1_labelb2
@@
@@PALETTEPRESERVE1_labelb2:
@@
@ENDMACRO

@MACRO GETPALETTEPRESERVE2C4
@@
@@  LDA PALETTEPRESERVEUSED
@@  AND #$1
@@  CMP #$1
@@  BNE GETPALETTEPRESERVE1_label
@@
@@  LDA $02C4
@@
@@  JMP GETPALETTEPRESERVE1_labelb2
@@
@@GETPALETTEPRESERVE1_label:
@@
@@  LDA #$FF
@@
@@GETPALETTEPRESERVE1_labelb2:
@@
@ENDMACRO

@MACRO PALETTEPRESERVE2C5 value, increment
@@
@@  LDA PALETTEPRESERVEUSED
@@  AND #$2
@@  CMP #$2
@@  BEQ PALETTEPRESERVE2_label
@@
@@  LDA value
@@  CMP #$FF
@@  BEQ PALETTEPRESERVE2_labelb2
@@  STA $02C5
@@
@@  LDA PALETTEPRESERVEUSED
@@  ORA #$2
@@  STA PALETTEPRESERVEUSED
@@
@@PALETTEPRESERVE2_label:
@@
@@  LDA increment
@@  CMP #$1
@@  BNE PALETTEPRESERVE2_labelb2
@@
@@PALETTEPRESERVE2_labelb2:
@@
@ENDMACRO

@MACRO GETPALETTEPRESERVE2C5
@@
@@  LDA PALETTEPRESERVEUSED
@@  AND #$2
@@  CMP #$2
@@  BNE GETPALETTEPRESERVE2_label
@@
@@  LDA $02C5
@@
@@  JMP GETPALETTEPRESERVE2_labelb2
@@
@@GETPALETTEPRESERVE2_label:
@@
@@  LDA #$FF
@@
@@GETPALETTEPRESERVE2_labelb2:
@@
@ENDMACRO

@MACRO PALETTEPRESERVE2C6 value, increment
@@
@@  LDA PALETTEPRESERVEUSED
@@  AND #$4
@@  CMP #$4
@@  BEQ PALETTEPRESERVE4_label
@@
@@  LDA value
@@  CMP #$FF
@@  BEQ PALETTEPRESERVE4_labelb2
@@  STA $02C6
@@
@@  LDA PALETTEPRESERVEUSED
@@  ORA #$4
@@  STA PALETTEPRESERVEUSED
@@
@@PALETTEPRESERVE4_label:
@@
@@  LDA increment
@@  CMP #$1
@@  BNE PALETTEPRESERVE4_labelb2
@@
@@PALETTEPRESERVE4_labelb2:
@@
@ENDMACRO

@MACRO GETPALETTEPRESERVE2C6
@@
@@  LDA PALETTEPRESERVEUSED
@@  AND #$4
@@  CMP #$4
@@  BNE GETPALETTEPRESERVE4_label
@@
@@  LDA $02C6
@@
@@  JMP GETPALETTEPRESERVE4_labelb2
@@
@@GETPALETTEPRESERVE4_label:
@@
@@  LDA #$FF
@@
@@GETPALETTEPRESERVE4_labelb2:
@@
@ENDMACRO

@MACRO PALETTEPRESERVE2C7 value, increment
@@
@@  LDA PALETTEPRESERVEUSED
@@  AND #$8
@@  CMP #$8
@@  BEQ PALETTEPRESERVE8_label
@@
@@  LDA value
@@  CMP #$FF
@@  BEQ PALETTEPRESERVE8_labelb2
@@  STA $02C7
@@
@@  LDA PALETTEPRESERVEUSED
@@  ORA #$8
@@  STA PALETTEPRESERVEUSED
@@
@@PALETTEPRESERVE8_label:
@@
@@  LDA increment
@@  CMP #$1
@@  BNE PALETTEPRESERVE8_labelb2
@@
@@PALETTEPRESERVE8_labelb2:
@@
@ENDMACRO

@MACRO GETPALETTEPRESERVE2C7
@@
@@  LDA PALETTEPRESERVEUSED
@@  AND #$8
@@  CMP #$8
@@  BNE GETPALETTEPRESERVE8_label
@@
@@  LDA $02C7
@@
@@  JMP GETPALETTEPRESERVE8_labelb2
@@
@@GETPALETTEPRESERVE8_label:
@@
@@  LDA #$FF
@@
@@GETPALETTEPRESERVE8_labelb2:
@@
@ENDMACRO

@MACRO PALETTEPRESERVE2C8 value, increment
@@
@@  LDA PALETTEPRESERVEUSED
@@  AND #$10
@@  CMP #$10
@@  BEQ PALETTEPRESERVE16_label
@@
@@  LDA value
@@  CMP #$FF
@@  BEQ PALETTEPRESERVE16_labelb2
@@  STA $02C8
@@
@@  LDA PALETTEPRESERVEUSED
@@  ORA #$10
@@  STA PALETTEPRESERVEUSED
@@
@@PALETTEPRESERVE16_label:
@@
@@  LDA increment
@@  CMP #$1
@@  BNE PALETTEPRESERVE16_labelb2
@@
@@PALETTEPRESERVE16_labelb2:
@@
@ENDMACRO

@MACRO GETPALETTEPRESERVE2C8
@@
@@  LDA PALETTEPRESERVEUSED
@@  AND #$10
@@  CMP #$10
@@  BNE GETPALETTEPRESERVE16_label
@@
@@  LDA $02C8
@@
@@  JMP GETPALETTEPRESERVE16_labelb2
@@
@@GETPALETTEPRESERVE16_label:
@@
@@  LDA #$FF
@@
@@GETPALETTEPRESERVE16_labelb2:
@@
@ENDMACRO

@ELSE

FINDLASTCOLORUSED:
    INC LASTCOLOR
    LDA LASTCOLOR
    CMP #4
    BEQ FINDLASTCOLORUSEDNONE
    RTS
FINDLASTCOLORUSEDNONE:
    DEC LASTCOLOR
    LDA #3
    RTS

@MACRO PALETTEPRESERVE2C4 value, increment
@@
@@  LDA value
@@  CMP #$FF
@@  BEQ PALETTEPRESERVE1_labelb2
@@  STA $02C4
@@
@@  LDA increment
@@  CMP #$1
@@  BNE PALETTEPRESERVE1_labelb2
@@
@@PALETTEPRESERVE1_labelb2:
@@
@ENDMACRO

@MACRO GETPALETTEPRESERVE2C4
@@
@@  LDA $02C4
@@
@ENDMACRO

@MACRO PALETTEPRESERVE2C5 value, increment
@@
@@  LDA value
@@  CMP #$FF
@@  BEQ PALETTEPRESERVE2_labelb2
@@  STA $02C5
@@
@@  LDA increment
@@  CMP #$1
@@  BNE PALETTEPRESERVE2_labelb2
@@
@@PALETTEPRESERVE2_labelb2:
@@
@ENDMACRO

@MACRO GETPALETTEPRESERVE2C5
@@
@@  LDA $02C5
@@
@ENDMACRO

@MACRO PALETTEPRESERVE2C6 value, increment
@@
@@  LDA value
@@  CMP #$FF
@@  BEQ PALETTEPRESERVE4_labelb2
@@  STA $02C6
@@
@@  LDA increment
@@  CMP #$1
@@  BNE PALETTEPRESERVE4_labelb2
@@
@@PALETTEPRESERVE4_labelb2:
@@
@ENDMACRO

@MACRO GETPALETTEPRESERVE2C6
@@
@@  LDA $02C6
@@
@ENDMACRO

@MACRO PALETTEPRESERVE2C7 value, increment
@@
@@  LDA value
@@  CMP #$FF
@@  BEQ PALETTEPRESERVE8_labelb2
@@  STA $02C7
@@
@@  LDA increment
@@  CMP #$1
@@  BNE PALETTEPRESERVE8_labelb2
@@
@@PALETTEPRESERVE8_labelb2:
@@
@ENDMACRO

@MACRO GETPALETTEPRESERVE2C7
@@
@@  LDA $02C7
@@
@ENDMACRO

@MACRO PALETTEPRESERVE2C8 value, increment
@@
@@  LDA value
@@  CMP #$FF
@@  BEQ PALETTEPRESERVE16_labelb2
@@  STA $02C8
@@
@@  LDA increment
@@  CMP #$1
@@  BNE PALETTEPRESERVE16_labelb2
@@
@@PALETTEPRESERVE16_labelb2:
@@
@ENDMACRO

@MACRO GETPALETTEPRESERVE2C8
@@
@@  LDA $02C8
@@
@ENDMACRO

@ENDIF