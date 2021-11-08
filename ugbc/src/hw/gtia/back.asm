; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
;*                      FILL BACKGROUND COLOR SCREEN FOR GTIA                  *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

BACK:
    LDA CURRENTMODE
    CMP #9
    BNE BACKANTIC9X
    JMP BACKANTIC9
BACKANTIC9X:
    CMP #10
    BNE BACKANTIC10X
    JMP BACKANTIC10
BACKANTIC10X:
    CMP #11
    BNE BACKANTIC11X
    JMP BACKANTIC11
BACKANTIC11X:
    CMP #13
    BNE BACKANTIC13X
    JMP BACKANTIC13
BACKANTIC13X:
    CMP #15
    BNE BACKANTIC15X
    JMP BACKANTIC15
BACKANTIC15X:
    CMP #12
    BNE BACKANTIC12X
    JMP BACKANTIC12
BACKANTIC12X:
    CMP #14
    BNE BACKANTIC14X
    JMP BACKANTIC14
BACKANTIC14X:
    CMP #2
    BNE BACKANTIC2X
    JMP BACKANTIC2
BACKANTIC2X:
    CMP #6
    BNE BACKANTIC6X
    JMP BACKANTIC6
BACKANTIC6X:    
    CMP #7
    BNE BACKANTIC7X
    JMP BACKANTIC7
BACKANTIC7X:    
    CMP #3
    BNE BACKANTIC3X
    JMP BACKANTIC3
BACKANTIC3X:    
    CMP #4
    BNE BACKANTIC4X
    JMP BACKANTIC4
BACKANTIC4X:    
    CMP #5
    BNE BACKANTIC5X
    JMP BACKANTIC5
BACKANTIC5X:
    CMP #8
    BNE BACKANTIC8X
    JMP BACKANTIC8
BACKANTIC8X:
    RTS

; GRAPHICS 0                    SETCOLOR     Register
; Character luminance              1           709
; Background                       2           710
; Border (BAK)                     4           712

; GRAPHICS 8                 SETCOLOR       COLOR   Register
; One color, two luminances
; Graphics luminance            1             1       709
; Background color              2             0       710
; Border                        4            --       712

BACKANTIC2:
BACKANTIC3:
    LDA _PAPER
    STA $02C6
    RTS


; GRAPHICS 1 and 2              SETCOLOR     Register
; Uppercase and numbers            0           708
; Lowercase characters             1           709
; Inverse uppercase                2           710
; Inverse lowercase                3           711
; Background, border               4           712

; GRAPHICS 3, 5, 7           SETCOLOR       COLOR   Register
; Four color modes
; Graphics point or             0             1       708
; fill area                     1             2       709
;                               2             3       710
; Background, border            4             0       712

; GRAPHICS 4, 6              SETCOLOR       COLOR   Register
; Two color modes
; Graphics point                0             1       708
; Background, border            4             0       712

BACKANTIC4:
BACKANTIC5:
BACKANTIC6:
BACKANTIC7:
BACKANTIC8:
BACKANTIC9:
BACKANTIC11:
BACKANTIC12:
BACKANTIC13:
BACKANTIC10:
BACKANTIC14:
BACKANTIC15:
    LDA _PAPER
    STA $02C8
    RTS

