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
;*                      SCAN CODE ROUTINE FOR MSX1                             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

SCANCODE:
    PUSH BC
    LD HL,SCANCODEKM
    LD D, 10
    LD B, 0
SCANCODEROW:
    LD E, 8
    IN A, ($AA)
    AND $F0
    OR B
    OUT ($AA), A
    IN A, ($A9)
SCANCODE1:
    SRL A
    JR NC,SCANCODE2
    INC HL
    DEC E
    JR NZ,SCANCODE1
    DEC D
    INC B
    JR NZ,SCANCODEROW
    AND A
    POP BC
    RET
SCANCODE2:
    LD A, (HL)
    POP BC
    RET

SCANCODEKM:
    DB "0", "1", "2", "3", "4", "5", "6", "7"
    DB "8", "9", "-", "=", "\\","[", "]", ";"
    DB "\"","~", "<", ">", "?", $00, "a", "b"
    DB "c", "d", "e", "f", "g", "h", "i", "j"
    DB "k", "l", "m", "n", "o", "p", "q", "r"
    DB "s", "t", "u", "v", "w", "x", "y", "z"
    DB $81, $82, $83, $84, $85, $F1, $F2, $F3
    DB $F4, $F5, $27, $09, $08, $86, $87, $0D
    DB " ", $88, $89, $90, $91, $92, $93, $94
    DB "*", "+", "/", "0", "1", "2", "3", "4"
    DB "5", "6", "7", "8", "9", "-", ",", "."

SCANCODEKMS:
    DB ")", "!", "@", "#", "$", "%", "^", "&"
    DB "*", "(", "_", "+", "|", "{", "}", ":"
    DB "'", "`", ",", ".", "/", $00, "A", "B"
    DB "C", "D", "E", "F", "G", "H", "I", "J"
    DB "K", "L", "M", "N", "O", "P", "Q", "R"
    DB "S", "T", "U", "V", "W", "X", "Y", "Z"
    DB $81, $82, $83, $84, $85, $F1, $F2, $F3
    DB $F4, $F5, $27, $09, $08, $86, $87, $0D
    DB " ", $88, $89, $90, $91, $92, $93, $94
    DB "*", "+", "/", "0", "1", "2", "3", "4"
    DB "5", "6", "7", "8", "9", "-", ",", "."
