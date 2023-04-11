; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2023 Marco Spedaletti (asimov@mclink.it)
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

; bit   index      address
; 0     1          $02c4
; 1     2          $02c5
; 2     4          $02c6
; 3     8          $02c7
; 4     16         $02c8
PALETTEPRESERVEUSED:
    .byte $00

@MACRO PALETTEPRESERVE2C4 value, increment
@@
@@  LDA PALETTEPRESERVEUSED
@@  AND #$1
@@  CMP #$1
@@  BEQ PALETTEPRESERVE1_label
@@
@@  LDA value
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
@@  BNE PALETTEPRESERVE1_label2
@@
@@  INC LASTCOLOR 
@@
@@PALETTEPRESERVE1_label2:
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
@@  BNE PALETTEPRESERVE2_label2
@@
@@  INC LASTCOLOR 
@@
@@PALETTEPRESERVE2_label2:
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
@@  BNE PALETTEPRESERVE4_label2
@@
@@  INC LASTCOLOR 
@@
@@PALETTEPRESERVE4_label2:
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
@@  BNE PALETTEPRESERVE8_label2
@@
@@  INC LASTCOLOR 
@@
@@PALETTEPRESERVE8_label2:
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
@@  BNE PALETTEPRESERVE16_label2
@@
@@  INC LASTCOLOR 
@@
@@PALETTEPRESERVE16_label2:
@@
@ENDMACRO

@ELSE

@MACRO PALETTEPRESERVE2C4 value, increment
@@
@@  LDA value
@@  STA $02C4
@@
@@  LDA increment
@@  CMP #$1
@@  BNE PALETTEPRESERVE1_label2
@@
@@  INC LASTCOLOR 
@@
@@PALETTEPRESERVE1_label2:
@@
@ENDMACRO

@MACRO PALETTEPRESERVE2C5 value, increment
@@
@@  LDA value
@@  STA $02C5
@@
@@  LDA increment
@@  CMP #$1
@@  BNE PALETTEPRESERVE2_label2
@@
@@  INC LASTCOLOR 
@@
@@PALETTEPRESERVE2_label2:
@@
@ENDMACRO

@MACRO PALETTEPRESERVE2C6 value, increment
@@
@@  LDA value
@@  STA $02C6
@@
@@  LDA increment
@@  CMP #$1
@@  BNE PALETTEPRESERVE4_label2
@@
@@  INC LASTCOLOR 
@@
@@PALETTEPRESERVE4_label2:
@@
@ENDMACRO

@MACRO PALETTEPRESERVE2C7 value, increment
@@
@@  LDA value
@@  STA $02C7
@@
@@  LDA increment
@@  CMP #$1
@@  BNE PALETTEPRESERVE8_label2
@@
@@  INC LASTCOLOR 
@@
@@PALETTEPRESERVE8_label2:
@@
@ENDMACRO

@MACRO PALETTEPRESERVE2C8 value, increment
@@
@@  LDA value
@@  STA $02C8
@@
@@  LDA increment
@@  CMP #$1
@@  BNE PALETTEPRESERVE16_label2
@@
@@  INC LASTCOLOR 
@@
@@PALETTEPRESERVE16_label2:
@@
@ENDMACRO

@ENDIF