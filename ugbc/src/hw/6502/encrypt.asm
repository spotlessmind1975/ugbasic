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
;*                              DATA ENCRYPTION                                *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; ENCRYPT
; Encrypt a memory area using a XOR algorithm, with an additional checksum.
;
; Input:
;       TMMPTR: address of the memory area to encrypt
;       TMMPTR2: address of the key (must be equal to the area to encrypt)
;       MATHPTR45: address of the destination area encrypted
;       MATHPTR6: size of the memory area to encrypt
;       MATHPTR7: size of the key encrypt
ENCRYPT:
    LDA MATHPTR7
    CMP MATHPTR6
    BEQ ENCRYPTLS 
    BCC ENCRYPTLS 
    LDA MATHPTR6
    STA MATHPTR7
ENCRYPTLS:
    STA MATHPTR3
    SEI
    LDA #0
    STA MATHPTR0
    LDY #0
    CLC
ENCRYPTL1:
    LDA (TMPPTR),Y
    ADC MATHPTR0
    STA MATHPTR0 
    INY
    CPY MATHPTR6
    BNE ENCRYPTL1
    LDY #0
ENCRYPTL2:
    LDA (TMPPTR), Y
    EOR (TMPPTR2), Y
    STA (MATHPTR4), Y
    DEC MATHPTR3
    LDA MATHPTR3
    BNE ENCRYPTL2A
    LDA MATHPTR7
    STA MATHPTR3
    SEC
    LDA TMPPTR2
    SBC MATHPTR3
    STA TMPPTR2
    LDA TMPPTR2+1
    SBC #0
    STA TMPPTR2+1
ENCRYPTL2A:
    INY
    CPY MATHPTR6
    BNE ENCRYPTL2
    LDA <MATHPTR0
    STA (MATHPTR4), Y
    CLI
    RTS
