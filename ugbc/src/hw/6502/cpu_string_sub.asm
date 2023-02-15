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
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; SOURCE: TMPPTR, LEN: MATHPTR0
; PATTERN: TMPPTR2, LEN: MATHPTR1
; DESTINATION: MATHPTR4;MATHPTR4+1
; SCRATCH: MATHPTR2, MATHPTR3, MATHPTR6, MATHPTR7

CPUSTRINGSUB:

    ; Check if source len is zero: if so, we can exit.
    LDA MATHPTR0
    BEQ CPUSTRINGSUBDONE
    ; Save the source len
    STA MATHPTR2

    ; Check if pattern len is zero: if so, we can exit.
    LDA MATHPTR1
    BEQ CPUSTRINGSUBDONE
    ; Save the pattern len
    STA MATHPTR3

    ; Save original pattern's pointer.
    LDA TMPPTR2
    STA MATHPTR6
    LDA TMPPTR2+1
    STA MATHPTR7

    LDY #0

    ; Main comparison loop.
CPUSTRINGSUBL1:
    ; Load the character from the source string. If they are
    ; different from the actual letter of pattern...
    LDA (TMPPTR),Y
    CMP (TMPPTR2),Y
    ; go to copy it on the target string.
    BNE CPUSTRINGSUBL2

    ; Move ahead on the pattern.
    INC TMPPTR2
    BNE CPUSTRINGSUBL11
    INC TMPPTR2+1
CPUSTRINGSUBL11:

    ; Move ahead on the original string
    INC TMPPTR
    BNE CPUSTRINGSUBL12
    INC TMPPTR+1
CPUSTRINGSUBL12:

    ; Decrement the lenght of original string
    DEC MATHPTR2

    ; Decrement the lenght of the pattern.
    DEC MATHPTR1

    ; If there are other characters in pattern,
    ; repeat the comparison loop.
    BNE CPUSTRINGSUBL1

    ; Reset the original pointer and length of the pattern
    LDA MATHPTR6
    STA TMPPTR2
    LDA MATHPTR7
    STA TMPPTR2+1
    LDA MATHPTR3
    STA MATHPTR1

    ; Restart the loop.
    JMP CPUSTRINGSUBL1

CPUSTRINGSUBL2:
    ; Copy the read character on the target string
    STA (MATHPTR4), Y

    ; Reset the original pointer and length of the pattern
    LDA MATHPTR6
    STA TMPPTR2
    LDA MATHPTR7
    STA TMPPTR2+1
    LDA MATHPTR3
    STA MATHPTR1

    ; Go ahead on the original string
    INC TMPPTR
    BNE CPUSTRINGSUBL21
    INC TMPPTR+1
CPUSTRINGSUBL21:

    ; Go ahead on the target string
    INC MATHPTR4
    BNE CPUSTRINGSUBL22
    INC MATHPTR4+1
CPUSTRINGSUBL22:

    ; There are characters left on original string?
    DEC MATHPTR0
    BNE CPUSTRINGSUBL1

CPUSTRINGSUBDONE:    
    RTS
