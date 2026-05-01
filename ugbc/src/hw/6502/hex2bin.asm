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
;*                        HEX STRING TO BINARY ON 6502                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; Convert an hexadecimal string into a binary data fragment.
; Input:
;       TMPPTR = address of hexadecimal string
;       X = size of hexadecimal string
;       TMPPTR2 = address of destinarion memory area
;       Y = size of destination memory area
;
HEX2BINDECODE:
    LDX #0
    CMP #'9'
    BCC HEX2BINDECODE09
    CMP #'f'
    BCC HEX2BINDECODEAF
    CMP #'F'
    BCC HEX2BINDECODEAF2
    LDX #$FF
    RTS

HEX2BINDECODE09:
    LDX #0
    SEC
    SBC #'0'
    CMP #9
    BCC HEX2BINDECODE09DONE
    LDX #$FF
HEX2BINDECODE09DONE:
    RTS

HEX2BINDECODEAF:
    LDX #0
    CLC
    ADC #10
    SEC
    SBC #'a'
    CMP #16
    BCC HEX2BINDECODEAFDONE
    LDX #$FF
HEX2BINDECODEAFDONE:
    RTS

HEX2BINDECODEAF2:
    LDX #0
    CLC
    ADC #10
    SEC
    SBC #'A'
    CMP #16
    BCC HEX2BINDECODEAF2DONE
    LDX #$FF
HEX2BINDECODEAF2DONE:
    RTS

HEX2BIN:
    STX <MATHPTR0
    STY <MATHPTR1

    LDY #0
HEX2BINL1:
    LDA (TMPPTR),Y
    INY
    CMP #'-'
    BEQ HEX2BINSKIP
    JSR HEX2BINDECODE
    CPX #$FF
    BEQ HEX2BINFAIL
    STA <MATHPTR2
    DEC <MATHPTR0
    BEQ HEX2BINFAIL
HEX2BINL2:
    LDA (TMPPTR),Y
    INY
    CMP #'-'
    BEQ HEX2BINSKIP2
    JSR HEX2BINDECODE
    CPX #$FF
    BEQ HEX2BINFAIL
    STA <MATHPTR3
    LDA <MATHPTR2
    ROL
    ROL 
    ROL
    ROL
    AND #$F0
    CLC 
    ORA <MATHPTR3
HEX2BINADDR:
    STA $F0F0
    INC HEX2BINADDR+1
    BNE HEX2BINADDR2
    INC HEX2BINADDR+2
HEX2BINADDR2:
    DEC <MATHPTR0
    BEQ HEX2BINDONE
    DEC <MATHPTR1
    BNE HEX2BINL1
    BEQ HEX2BINDONE

HEX2BINSKIP2:
    DEC <MATHPTR0
    BNE HEX2BINL2
    BEQ HEX2BINFAIL

HEX2BINSKIP:
    DEC <MATHPTR0
    BNE HEX2BINL1

HEX2BINDONE:
    LDA #$FF
    RTS

HEX2BINFAIL:
    LDA #0
    RTS