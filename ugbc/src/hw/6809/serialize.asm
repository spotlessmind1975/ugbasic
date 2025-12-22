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
;*                 DATA SERIALIZATION WITH SAFENESS AND ENCRYPTION             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

SERIALIZELOOKUPTABLE
    fcb     "ABCDEFGHIJKLMNOPQRSTUVWXYZ012345"
SERIALIZELOOKUPPARITY
    fcb     0, 1, 1, 0, 1, 0, 0, 1
    fcb     1, 0, 0, 1, 0, 1, 1, 0

; SERIALIZE
; Serialize a piece of data with a given secret key, following
; the encryption algoritm.
;
; Input:
;       X = address of the memory area to serialize
;       MATHPTR0 = size of the memory area (up to 64 bytes)
;       U = address of the secret key to use (size = B * 2)
; Output:
;       Y = address where to put the serialized data (size = B * 2)
SERIALIZE
    LDB <MATHPTR0
    PSHS D,X,Y,U
    ; Algorithm to code:
    ;
    ;   1. For each byte of the source data:
    ;       1.a. take hi nibble (-> hi)
    LDA ,X
    LSRA
    LSRA
    LSRA
    LSRA

    ;       1.c. calculate parity of hi nibble (p(hi0) = p(hi) = p)
    LSRB
    ;       1.b. shift left 1 bit (-> hi0 )
    ;       1.d. store the first byte (-> 000hhiip )
    LSLA
    STA ,Y+
    ;       1.e. take lo nibble (-> lo)
    LDA ,X
    ANDA #$0f
    ;       1.g. calculate parity of lo nibble (p(lo0) = p(lo) = p)
    LDU #SERIALIZELOOKUPPARITY
    LDB A,U
    LSRB
    ;       1.f. shift left 1 bit (-> lo0 )
    ;       1.h. store the second byte (-> 000hhiip )    
    LSLA
    STA ,Y+
    LEAX 1, X
    DEC <MATHPTR0
    BNE SERIALIZE

    PULS D,X,Y,U
    LSLB
    PSHS D,X,Y,U

    ;   2. For each byte of the destination data:
SERIALIZEL1
    ;       2.a. read a byte from destination data
    LDA ,Y
    ;       2.b. read a byte from the secret key
    ;       2.c. do a xor between bytes
    XOR ,U+
    ;       2.d. store the byte into the destination data
    STA ,Y+
    DECB
    BNE SERIALIZEL1

    PULS D,X,Y,U

    LDX #SERIALIZELOOKUPTABLE

SERIALIZEL2
    ;   3. For each byte of the destination data:
    LDA ,Y
    ;       3.a. read a byte from the destination data
    LDA A,X
    ;       3.b. do a look up into the translation table
    STA ,Y+
    ;       3.c. write the the letter to the destination data
    DECB 
    BNE SERIALIZEL2
    ;

    RTS

SERIALIZEUNLOOKUP
    PSHS X
    LDB #0
    LDX #SERIALIZELOOKUPTABLE
SERIALIZEUNLOOKUPL1
    CMPA B,X
    BEQ SERIALIZEUNLOOKUPFOUND
    INCB
    CMPB #32
    BNE SERIALIZEUNLOOKUPL1
SERIALIZEUNLOOKUPFOUND
    PULS X
    RTS

; UNSERIALIZE
; Unserialize a piece of data with a given secret key, following
; the decryption algoritm.
;
; Input:
;       X = address of the memory area to unserialize
;       MATHPTR0 = size of the original area (up to 64 bytes)
;       Y = address where to put the unserialized data (size = B)
;       U = address of the secret key to use (size = B * 2)
UNSERIALIZE
    LDB <MATHPTR0
    LSLB
    PSHS D,X,Y
UNSERIALIZEL1
    ; Algorithm to code:
    ;
    ;   1. For each byte of the source data:
    ;       1.a. read a letter from the source data
    LDA ,X
    ;       1.b. do a look up into the translation table
    BSR SERIALIZEUNLOOKUP
    ;       1.c. write the the byte to the source data
    STA ,X+
    DECB
    BNE UNSERIALIZEL1

    PULS D,X,Y
    PSHS D,X,Y

UNSERIALIZEL2
    ;   2. For each byte of the source data:
    ;       2.a. read a byte from source data
    LDA ,X
    ;       2.b. read a byte from the secret key
    ;       2.c. do a xor between bytes
    XOR ,U+
    ;       2.d. store the byte into the source data    
    STA ,X+
    DECB
    BNE UNSERIALIZEL2

    PULS D,X,Y

    LSRB
    STB <MATHPTR0

UNSERIALIZEL3
    ;   3. For each two bytes of the source data:
    ;       3.a. take first byte 
    LDA ,X
    ;       3.b. take first bit and store it
    ;       3.c. shift right the byte
    LSRA
    STA <MATHPTR2
    ;       3.d. calculate the parity of the byte
    LDU #SERIALIZELOOKUPPARITY
    LDB A,U
    ;       3.e. if different from stored bit -> ERROR    
    XORB ,X+
    ANDB #1
    BNE UNSERIALIZEFAIL

    ;       3.f. take second byte 
    LDA ,X
    ;       3.g. take second bit and store it
    ;       3.h. shift right the byte
    LSRA
    STA <MATHPTR3
    ;       3.i. calculate the parity of the byte
    LDU #SERIALIZELOOKUPPARITY
    LDB A,U
    ;       3.j. if different from stored bit -> ERROR    
    XORB ,X+
    ANDB #1
    BNE UNSERIALIZEFAIL
    ;       3.k. build the final byte
    LDA <MATHPTR2
    LSLA
    LSLA
    LSLA
    LSLA
    ORA <MATHPTR3
    STA ,Y+
    ;       3.l. store the byte on the destination area.
    DEC <MATHPTR0
    BNE UNSERIALIZEL3
    ;
    RTS
