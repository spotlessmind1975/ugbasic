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
;*                      CONVERT A NUMBER TO A HEXADECIMAL NUMBER               *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
;
; Input: 
;       HL = memory area to convert
;       C = size of memory area to convert
; Output:
;       DE = location of ASCII string

H2STRING:
    LD A, C
    CP 0
    JR NZ, H2STRINGA
    RET

H2STRINGA:
    LD B, 0
    PUSH HL
    LD HL, DE
    ADD HL, BC
    ADD HL, BC
    LD DE, HL
    POP HL
    DEC DE
    DEC C
H2STRINGL1:
    LD A, (HL)
    CALL H2STRINGBYTE
    LD A, (IXLR)
    LD (DE), A
    DEC DE
    LD A, (IXHR)
    LD (DE), A
    DEC DE
    INC HL
H2STRINGL1A:
    DEC C
    LD A, C
    CP $FF
    JR NZ, H2STRINGL1
    RET

H2STRINGBYTE:
    PUSH AF
    SRL A
    SRL A
    SRL A
    SRL A
    CP $0a
    JR NC, HEX2STRINGA    
HEX2STRING0:
    ADD 48
    LD (IXHR), A
    JR HEX2STRINGLSB
HEX2STRINGA:
    ADD 55
    LD (IXHR), A
HEX2STRINGLSB:
    POP AF
    AND $0F
    CP $0A
    JR NC, HEX2STRINGA2
HEX2STRING02:
    ADD 48
    LD (IXLR), A
    RET
HEX2STRINGA2:
    ADD 55
    LD (IXLR), A
    RET
