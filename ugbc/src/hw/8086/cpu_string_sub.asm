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
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; SOURCE: SI, LEN: CL
; PATTERN: DX, LEN: CH
; DESTINATION: DI

CPUSTRINGSUB:

    ; ; Check if source len is zero: if so, we can exit.
    ; LD A, CL
    ; CP 0
    CMP CL, 0
    JZ CPUSTRINGSUBDONE
    ; JR Z, CPUSTRINGSUBDONE
    ; ; Save the source len
    ; LD B, A
    MOV BL, CL

    ; ; Check if pattern len is zero: if so, we can exit.
    ; LD A, CH
    ; CP 0
    CMP CH, 0
    JZ CPUSTRINGSUBDONE
    ; JR Z, CPUSTRINGSUBDONE
    ; ; Save the pattern len
    ; LD C, A
    LD BH, CH

    ; ; Save original pattern's pointer.
    ; PUSH DX
    PUSH DX

    ; Main comparison loop.
CPUSTRINGSUBL1:
    ; ; Load the character from the source string. If they are
    ; ; different from the actual letter of pattern...
    ; LD A, (SI)
    MOV AL, [SI]
    ; CP (DX)
    PUSH DI
    MOV DI, DX
    CMP AL, [DI]
    POP DX
    ; ; go to copy it on the target string.
    ; JR NZ, CPUSTRINGSUBL2
    JNZ CPUSTRINGSUBL2

    ; ; Move ahead on the pattern.
    INC DX

    ; ; Move ahead on the original string
    INC SI

    ; ; Decrement the lenght of original string
    DEC CL

    ; ; Decrement the lenght of the pattern.
    DEC CH

    ; ; If there are other characters in pattern,
    ; ; repeat the comparison loop.
    ; LD A, CH
    ; CP 0
    CMP CH, 0
    JNZ CPUSTRINGSUBL1
    ; JR NZ, CPUSTRINGSUBL1

    ; ; Reset the original pointer and length of the pattern
    ; POP DX
    POP DX
    ; PUSH DX
    PUSH DX
    ; LD A, C
    ; LD CH, A
    MOV CH, BH

    ; ; Restart the loop.
    ; JMP CPUSTRINGSUBL1
    JP CPUSTRINGSUBL1

CPUSTRINGSUBL2:
    ; ; Copy the read character on the target string
    ; LD (DI), A
    MOV [DI], AL

    ; ; Reset the original pointer and length of the pattern
    ; POP DX
    POP DX
    ; PUSH DX
    PUSH DX
    ; LD A, C
    ; LD CH, A
    MOV CH, BH

    ; ; Go ahead on the original string
    ; INC SI
    INC SI

    ; ; Go ahead on the target string
    ; INC DI
    INC DI

    ; ; There are characters left on original string?
    ; DIC B
    DEC BL
    ; LD A, B
    ; CP 0
    CMP BL, 0
    ; JR NZ, CPUSTRINGSUBL1
    JNZ CPUSTRINGSUBL1

CPUSTRINGSUBDONE:    
    ; POP DX
    POP DX

    RET
