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
;*                        HEX STRING TO BINARY ON 6309                         *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; Convert an hexadecimal string into a binary data fragment.
; Input:
;       X = address of hexadecimal string
;       A = size of hexadecimal string
;       Y = address of destinarion memory area
;       B = size of destination memory area
;
HEX2BINDECODE
    CLRB
    CMPA #'9'
    BCS HEX2BINDECODE09
    CMPA #'F'
    BCS HEX2BINDECODEAF
    CMPA #'f'
    BCS HEX2BINDECODEAF2
    DECB
    RTS

HEX2BINDECODE09
    CLRB
    SUBA #'0'
    CMPA #9
    BCS HEX2BINDECODE09DONE
    DECB
HEX2BINDECODE09DONE
    RTS

HEX2BINDECODEAF
    CLRB
    ADDA #10
    SUBA #'A'
    CMPA #16
    BCS HEX2BINDECODEAFDONE
    DECB
HEX2BINDECODEAFDONE
    RTS

HEX2BINDECODEAF2
    CLRB
    SUBA #'a'
    ADDA #10
    CMPA #16
    BCS HEX2BINDECODEAF2DONE
    DECB
HEX2BINDECODEAF2DONE
    RTS

HEX2BIN
    STA <MATHPTR0
    STB <MATHPTR1

HEX2BINL1
    LDA ,X+
    CMPA #'-'
    BEQ HEX2BINSKIP
    JSR HEX2BINDECODE
    CMPB #$FF
    BEQ HEX2BINFAIL
    STA <MATHPTR2
    DEC <MATHPTR0
    BEQ HEX2BINFAIL
HEX2BINL2
    LDA ,X+
    CMPA #'-'
    BEQ HEX2BINSKIP2
    JSR HEX2BINDECODE
    CMPB #$FF
    BEQ HEX2BINFAIL
    STA <MATHPTR3
    LDA <MATHPTR2
    LSLA 
    LSLA 
    LSLA 
    LSLA 
    ORA <MATHPTR3
    STA ,Y+
    DEC <MATHPTR0
    BEQ HEX2BINDONE
    DEC <MATHPTR1
    BNE HEX2BINL1
    BRA HEX2BINDONE

HEX2BINSKIP2
    DEC <MATHPTR0
    BNE HEX2BINL2
    BRA HEX2BINFAIL

HEX2BINSKIP
    DEC <MATHPTR0
    BNE HEX2BINL1
HEX2BINDONE
    CLRA
    DECA
    RTS

HEX2BINFAIL
    CLRA
    RTS