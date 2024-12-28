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
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; SOURCE: HL, LEN: (IYLR)
; PATTERN: IX, LEN: (IYHR)
; DESTINATION: DE

CPUSTRINGSUB:

    ; Check if source len is zero: if so, we can exit.
    LD A, (IYLR)
    CP 0
    JR Z, CPUSTRINGSUBDONE
    ; Save the source len
    LD B, A

    ; Check if pattern len is zero: if so, we can exit.
    LD A, (IYHR)
    CP 0
    JR Z, CPUSTRINGSUBDONE
    ; Save the pattern len
    LD C, A

    ; Save original pattern's pointer.
    PUSH HL
    LD HL, (IXR)
    LD (IYR), HL
    POP HL

    ; Main comparison loop.
CPUSTRINGSUBL1:
    ; Load the character from the source string. If they are
    ; different from the actual letter of pattern...
    LD A, (HL)

    PUSH HL
    LD HL, (IXR)
    CP (HL)
    POP HL

    ; go to copy it on the target string.
    JR NZ, CPUSTRINGSUBL2

    ; Move ahead on the pattern.
    PUSH HL
    LD HL, (IXR)
    INC HL
    LD (IXR), HL
    POP HL

    ; Move ahead on the original string
    INC HL

    ; Decrement the lenght of original string
    DEC (IYLR)

    ; Decrement the lenght of the pattern.
    DEC (IYHR)

    ; If there are other characters in pattern,
    ; repeat the comparison loop.
    LD A, (IYHR)
    CP 0
    JR NZ, CPUSTRINGSUBL1

    ; Reset the original pointer and length of the pattern
    PUSH HL
    LD HL, (IYR)
    LD (IXR), HL
    POP HL
    LD A, C
    LD (IYHR), A

    ; Restart the loop.
    JMP CPUSTRINGSUBL1

CPUSTRINGSUBL2:
    ; Copy the read character on the target string
    LD (DE), A

    ; Reset the original pointer and length of the pattern
    PUSH HL
    LD HL, (IYR)
    LD (IXR), HL
    POP HL
    LD A, C
    LD (IYHR), A

    ; Go ahead on the original string
    INC HL

    ; Go ahead on the target string
    INC DE

    ; There are characters left on original string?
    DEC B
    LD A, B
    CP 0
    JR NZ, CPUSTRINGSUBL1

CPUSTRINGSUBDONE:    
    ; POP IX

    RET
