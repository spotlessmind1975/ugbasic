; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
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
;*                      CONVERT A NUMBER TO A HEXADECIMAL NUMBER               *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; Input: 
;       SI = memory area to convert
;       CL = size of memory area to convert
; Output:
;       DI = location of ASCII string

H2STRING:
    CMP CL, 0
    JNZ H2STRINGA
    RET

H2STRINGA:
    MOV CH, 0
    ADD DI, CX
    DEC DI
    DEC CL
H2STRINGL1:
    MOV AL, [SI]
    CALL H2STRINGBYTE
    MOV [DI], BL
    DEC DI
    MOV [DI], BH
    DEC DI
    INC SI
H2STRINGL1A:
    DEC CL
    CMP CL, 0xFF
    JNZ H2STRINGL1
    RET

H2STRINGBYTE:
    PUSH AX
    SHR AL,1
    SHR AL,1
    SHR AL,1
    SHR AL,1
    CMP AL, 0x0a
    JNC HEX2STRINGA    
HEX2STRING0:
    ADD AL, 48
    MOV BH, AL
    JMP HEX2STRINGLSB
HEX2STRINGA:
    ADD AL, 55
    MOV BH, AL
HEX2STRINGLSB:
    POP AX
    AND AL, 0x0F
    CMP AL, 0x0a
    JNC HEX2STRINGA2
HEX2STRING02:
    ADD AL, 48
    MOV BL, AL
    RET
HEX2STRINGA2:
    ADD AL, 55
    MOV BL, AL
    RET
