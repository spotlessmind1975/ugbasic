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
;*                              DATA DECRYPTION                                *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; DECRYPT
; Decrypt a memory area using a XOR algorithm, with an additional checksum.
;
; Input:
;       X: address of the memory area to decrypt
;       U: address of the key (must be equal to the area to decrypt-1)
;       Y: address of the destination decrypted area 
;       B: size of the memory area to decrypt 
DECRYPT
    LDA B,X
    STA <MATHPTR1
    CLRA
    STA <MATHPTR0
    PSHS D, X, Y
DECRYPTL2
    LDA ,X+
    EORA ,U+
    STA ,Y+
    DECB
    BNE DECRYPTL2
    PULS D, X, Y
DECRYPTL1
    LDA ,Y+
    ADDA <MATHPTR0
    STA <MATHPTR0 
    DECB
    BNE DECRYPTL1
    LDA <MATHPTR0
    CMPA <MATHPTR1
    RTS

