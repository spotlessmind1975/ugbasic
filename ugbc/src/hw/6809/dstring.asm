; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
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
;*                DINAMYC STRING MANAGEMENT WITH GARBAGE COLLECTION            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; DSDEFINE(Y) -> B
DSDEFINE
    JSR DSFINDFREE
    JSR DSDESCRIPTOR
    LDA , Y
    LEAY 1, Y
    STA , X
    STY 1, X
    LDA #$C0
    STA 3, X
    RTS

; DSALLOC(A) -> B
DSALLOC
    PSHS A
    JSR DSFINDFREE
    JSR DSDESCRIPTOR
    LDA 3, X
    ORA #$40
    STA 3, X
    PULS A
    JSR DSCHECKFREE
DSALLOCOK
    JSR DSUSING
    JSR DSMALLOC
    RTS

; DSFREE(B)
DSFREE
    JSR DSDESCRIPTOR
    LDA #0
    STA 3, X
    LDA #0
    STA , X
    RTS

; DSWRITE(B)
DSWRITE
    JSR DSDESCRIPTOR
    LDA 3, X
    ANDA #$80
    CMPA #0
    BEQ DSWRITED
    LDA 3, X
    ANDA #$7F
    STA 3, X
    LDA , X
    JSR DSCHECKFREE
DSWRITEOK
    LDY 1, X
    PSHS Y
    JSR DSUSING
    JSR DSMALLOC
    PULS Y
    LDU 1, X
DSCOPY
    LDA , X
DSWRITECOPY
    CMPA #0
    BEQ DSWRITED
    PSHS B
    DECA
DSWRITECOPYL
    LDB A,Y
    STB A,U 
    DECA
    CMPA #$FF
    BNE DSWRITECOPYL 
    PULS B
DSWRITED
    RTS

; DSRESIZE(B,A)
DSRESIZE
    JSR DSDESCRIPTOR
    STA , X
    RTS

; DSGC()
DSGC
    PSHS X
    LDA #(max_free_string-1)
    LDB #0
    STD FREE_STRING

    LDA USING
    CMPA #0
    BEQ DSGT
    JMP DSGW
DSGT
    LDU #TEMPORARY
    JMP BSGCLOOP0
DSGW
    LDU #WORKING
    JMP BSGCLOOP0
BSGCLOOP0
    LDB #1
DSGCLOOP
    PSHS A,B
    JSR DSDESCRIPTOR
    LDA 3, X
    ANDA #$80
    BNE DSGCLOOP2
    LDA 3, X
    ANDA #$40
    BEQ DSGCLOOP1
    LDY 1, X
    LDA , X
    JSR DSUSING
    JSR DSMALLOC
    LDU 1, X
    LDA , X
    JSR DSWRITECOPY
    JMP DSGCLOOP3
DSGCLOOP1
    LDA #0
    STA , X
    JMP DSGCLOOP3
DSGCLOOP2
    ; LDA #0
    ; STA , X
    JMP DSGCLOOP3
DSGCLOOP3
    PULS A,B
    INCB
    CMPB #$7F
    BNE DSGCLOOP
DSGCEND
    LDA USING
    EORA #$FF
    STA USING
    PULS X
    RTS

; DSFINDFREE() -> B
DSFINDFREE
    PSHS A
    LDB #1; // fix denote 0 as "unused slot"
DSFINDFREEL
    JSR DSDESCRIPTOR
    LDA 3, X
    ANDA #$40
    CMPA #0
    BEQ DSFINDFREEN
    INCB
    CMPB #$7F
    BNE DSFINDFREEL
    JMP OUT_OF_MEMORY   
DSFINDFREEN
    PULS A
    RTS

OUT_OF_MEMORY2
    SYNC
    JMP OUT_OF_MEMORY

; DSMALLOC(U,A,B)
DSMALLOC
    PSHS U,Y
    JSR DSDESCRIPTOR
    STA , X
    PSHS A,B
    TFR A, B
    LDA #0
    ANDCC #$FE
    EORA #$FF
    EORB #$FF
    ANDCC #$FE
    ADDD #1
    LDY FREE_STRING
    LEAY D, Y
    STY FREE_STRING
    TFR U, D
    LEAY D, Y
    PULS A,B
    STY 1, X
    PULS U,Y
    RTS

; DSCHECKFREE()
DSCHECKFREE
    PSHS A,B
    TFR A, B
    LDA #0
    STD MATHPTR0
DSCHECKFREE2
    LDD FREE_STRING
    CMPD MATHPTR0
    BLT DSCHECKFREEKO
    JMP DSCHECKFREEOK
DSCHECKFREEKO
    JSR DSGC
    JMP DSCHECKFREE2
DSCHECKFREEOK
    PULS A,B
    RTS

; DSUSING() -> U
DSUSING
    PSHS A
    LDA USING
    CMPA #0
    BEQ DSUSINGW
    JMP DSUSINGT
DSUSINGT
    LDU #TEMPORARY
    PULS A
    RTS
DSUSINGW
    LDU #WORKING
    PULS A
    RTS

; DSDESCRIPTOR(B) -> X
DSDESCRIPTOR
    PSHS A,B
    LDX #DESCRIPTORS
    LDA #4
    MUL
    LEAX D, X
    PULS A,B
    RTS

OUT_OF_MEMORY
    JMP OUT_OF_MEMORY

USING               fcb 0
    
