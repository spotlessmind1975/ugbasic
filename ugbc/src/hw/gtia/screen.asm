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
;*                      CHARACTER AT GIVEN POSITION ON GTIA                    *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; ******************************************************************************
; COMMON FUNCTIONS
; ******************************************************************************
; Write a char to the text screen.
; Input: A - screencode to print
;        COPYOFTEXTADDRESS - pointer to the interested screen memory
;        Y - offset inside the screen
; Output: -
SCREENTMWRITECHAR:
    STA (COPYOFTEXTADDRESS),Y
    INC COPYOFTEXTADDRESS
    BNE SCREENTMWRITECHARL1
    INC COPYOFTEXTADDRESS+1
SCREENTMWRITECHARL1:
    RTS

; ******************************************************************************
; ENTRY POINT
; ******************************************************************************

SCREEN:

SCREENTMGO:
    LDA TEXTADDRESS
    STA COPYOFTEXTADDRESS
    LDA TEXTADDRESS+1
    STA COPYOFTEXTADDRESS+1

    LDA CURRENTMODE
    CMP #2
    BNE SCREENTMANTIC2X
    JMP SCREENTMANTICX
SCREENTMANTIC2X:
    CMP #6
    BNE SCREENTMANTIC6X
    JMP SCREENTMANTICX
SCREENTMANTIC6X:    
    CMP #7
    BNE SCREENTMANTIC7X
    JMP SCREENTMANTICX
SCREENTMANTIC7X:    
    CMP #3
    BNE SCREENTMANTIC3X
    JMP SCREENTMANTICX
SCREENTMANTIC3X:    
    CMP #4
    BNE SCREENTMANTIC4X
    JMP SCREENTMANTICX
SCREENTMANTIC4X:    
    CMP #5
    BNE SCREENTMANTIC5X
    JMP SCREENTMANTICX
SCREENTMANTIC5X:
    RTS

SCREENTMANTICX:
    JSR CALCPOST

    LDY #0
    LDA (COPYOFTEXTADDRESS),Y

    RTS