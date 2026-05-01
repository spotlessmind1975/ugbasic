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
;*                        HEX STRING TO BINARY ON SM83                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; Convert an hexadecimal string into a binary data fragment.
; Input:
;       HL = address of hexadecimal string
;       C = size of hexadecimal string
;       DE = address of destinarion memory area
;       B = size of destination memory area
;
HEX2BINDECODE:
    CP '9'
    JR C, HEX2BINDECODE09
    CP 'F'
    JR C, HEX2BINDECODEAF
    CP 'f'
    JR C, HEX2BINDECODEAF2
    LD A, $ff
    LD (IXLR), A
    RET

HEX2BINDECODE09:
    SUB '0'
    CP 9
    JR C, HEX2BINDECODE09DONE
    LD A, $ff
    LD (IXLR), A
HEX2BINDECODE09DONE:
    RET

HEX2BINDECODEAF:
    ADD 10
    SUB 'A'
    CP 16
    JR C, HEX2BINDECODEAFDONE
    LD A, $ff
    LD (IXLR), A
HEX2BINDECODEAFDONE:
    RET

HEX2BINDECODEAF2:
    SUB 'a'
    ADD 10
    CP 16
    JR C, HEX2BINDECODEAF2DONE
    LD A, $ff
    LD (IXLR), A
HEX2BINDECODEAF2DONE:
    RET

HEX2BIN:
    LD A, 0
    LD (IXLR), A
HEX2BINL1:
    LD A, (HL)
    INC HL
    CP '-'
    JR Z, HEX2BINSKIP
    CALL HEX2BINDECODE 
    LD (IYHR), A
    LD A, (IXLR)
    CP $FF
    JR Z, HEX2BINFAIL
    DEC C
    JR Z, HEX2BINFAIL
HEX2BINL2:
    LD A, (HL)
    INC HL
    CP '-'
    JR Z, HEX2BINSKIP2
    CALL HEX2BINDECODE
    LD (IYLR), A
    LD A, (IXLR)
    CP $FF
    JR Z, HEX2BINFAIL
    AND A
    LD A, (IYHR)
    SLA A
    SLA A
    SLA A
    SLA A
    PUSH BC
    LD B, A
    LD A, (IYLR)
    OR B
    POP BC
    LD (DE), A
    INC DE
    DEC C
    JR Z, HEX2BINDONE
    DEC B
    JR NZ, HEX2BINL1
    JR HEX2BINDONE

HEX2BINSKIP2:
    DEC C
    JR NZ, HEX2BINL2
    JR HEX2BINFAIL

HEX2BINSKIP:
    DEC C
    JR NZ, HEX2BINL1
HEX2BINDONE:
    LD A, $FF
    RET

HEX2BINFAIL:
    LD A, 0
    RET