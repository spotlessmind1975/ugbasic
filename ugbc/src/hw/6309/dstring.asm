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
;*                DINAMYC STRING MANAGEMENT WITH GARBAGE COLLECTION            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; DSEQUAL(X=descriptor,Y=string) -> C / NC
DSEQUAL
    PSHS D
    PSHS Y
    LDB ,Y
    CMPB ,X
    BNE DSEQUALNO
    LEAY 1, Y
    LDB , X
    LDD 1, X
    TFR D, X
DSEQUALL1
    LDA , X+
    CMPA , Y+
    BNE DSEQUALNO
    DECB
    BNE DSEQUALL1
DSEQUALYES
    PULS Y
    PULS D
    ORCC #$01
    RTS
DSEQUALNO
    PULS Y
    PULS D
    ANDCC #$FE
    RTS

; DSFINDEQUAL(Y) -> B / 0
DSFINDEQUAL
    PSHS  A
    LDB   #1; // fix denote 0 as "unused slot"
DSFINDEQUALL
    JSR   DSDESCRIPTOR
    LDA   3,X
    ANDA  #$C0
    CMPA  #$C0
    BEQ   DSFINDEQUALF1
DSFINDEQUALF2
    INCB
    CMPB  #MAXSTRINGS
    BNE   DSFINDEQUALL
DSFINDEQUALNO
    LDB #0
    PULS  A,PC
DSFINDEQUALF1
    JSR DSEQUAL
    BCC DSFINDEQUALF2
DSFINDEQUALYES
    PULS  A,PC

; DSDEFINE(Y) -> B
DSDEFINE
    BSR   DSFINDEQUAL
    CMPB  #0
    BNE   DSDEFINEE
    BSR   DSFINDFREE
    BSR   DSDESCRIPTOR
    LDA   ,Y+
    STA , X
    STY 1, X
    LDA #$C0
    STA 3, X
DSDEFINEE
    RTS

OUT_OF_MEMORY
    BRA   OUT_OF_MEMORY

; DSFREE(B)
DSFREE
    BSR   DSDESCRIPTOR
    CLRA
    STA 3, X
    STA , X
    RTS

; DSWRITE(B)
DSWRITE
    BSR   DSDESCRIPTOR
    LDA 3, X
    BPL   DSWRITED
    ANDA #$7F
    STA 3, X
    LDA , X
    BSR   DSCHECKFREE
DSWRITEOK
    LDY 1, X
    PSHS Y
    JSR   DSUSINGALLOC
    PULS Y
    LDU 1, X
DSCOPY
    LDA , X
    
DSWRITECOPY
    BEQ DSWRITED
    PSHS B
DSWRITECOPYL
    LDB   ,Y+
    STB   ,U+
    DECA
    BNE DSWRITECOPYL 
    PULS  B,PC
DSWRITED
    RTS

; DSRESIZE(B,A)
DSRESIZE
    BSR   DSDESCRIPTOR
    STA , X
    CMPA #$0
    BNE DSRESIZEDONE
    LDA 3,X
    ORA #$80
    STA 3,X
DSRESIZEDONE
    RTS

; DSFINDFREE() -> B
DSFINDFREE
    PSHS  A
    LDB   #1; // fix denote 0 as "unused slot"
DSFINDFREEL
    BSR   DSDESCRIPTOR
    LDA   3,X
    ANDA  #$40
    BEQ   DSFINDFREEN
    INCB
    CMPB  #MAXSTRINGS
    BNE   DSFINDFREEL
    BRA   OUT_OF_MEMORY   
DSFINDFREEN
    PULS  A,PC

; DSDESCRIPTOR(B) -> X
DSDESCRIPTOR
    LDX   #DESCRIPTORS
    ABX
    ABX
    ABX
    ABX
    RTS

; DSCHECKFREE()
DSCHECKFREE
    PSHS  A,B
    STA   DSCHECKFREE2x
DSCHECKFREE2
    LDD   FREE_STRING
DSCHECKFREE2x SET *+3
    CMPD  #$0000
    BGE   DSCHECKFREEOK
DSCHECKFREEKO
    BSR   DSGC
    BRA   DSCHECKFREE2
DSCHECKFREEOK
    PULS  A,B,PC

; DSGC()
DSGC
    PSHS X
    LDD #(max_free_string-1)
    STD FREE_STRING

    LDA USING
    BNE   DSGW
    LDU #TEMPORARY
    BRA   BSGCLOOP0
DSGW
    LDU #WORKING
BSGCLOOP0
    LDB #1
DSGCLOOP
    PSHS A,B
    BSR   DSDESCRIPTOR
    LDA 3, X
    BMI   DSGCLOOP2
    ANDA #$40
    BEQ DSGCLOOP1
    LDA , X
    CMPA #$0
    BEQ DSGCLOOP3
    LDY 1, X
    LDA , X
    BSR   DSUSINGALLOC
    LDU 1, X
    LDA , X
    LBSR  DSWRITECOPY
    BRA   DSGCLOOP3
DSGCLOOP1
;    CLRA       (A already = 0 here)
    STA , X
;    BRA   DSGCLOOP3
DSGCLOOP2
    ; LDA #0
    ; STA , X
DSGCLOOP3
    PULS A,B
    INCB
    CMPB #MAXSTRINGS
    BNE DSGCLOOP
DSGCEND
    COM   USING
    PULS  X,PC

;OUT_OF_MEMORY2
;    SYNC
;    BRA OUT_OF_MEMORY

; DSALLOC(A) -> B
DSALLOC
    PSHS A
    BSR   DSFINDFREE
    BSR   DSDESCRIPTOR
    LDA 3, X
    ORA   #$40
    STA   3,X
    PULS A
    BSR   DSCHECKFREE
DSALLOCOK

DSUSINGALLOC
    BSR   DSUSING
;    BRA   DSMALLOC

; DSMALLOC(U,A,B)
DSMALLOC
    PSHS  U
    BSR   DSDESCRIPTOR
    STA , X

    PSHS  D

    LDD FREE_STRING
    SUBB  ,S
    SBCA  #0
    STD   FREE_STRING
    ADDD  2,S
    STD   1,X
    
    PULS  U,D,PC

; DSUSING() -> U
DSUSING
    TST   USING
    BEQ DSUSINGW
    LDU #TEMPORARY
    RTS
DSUSINGW
    LDU #WORKING
    RTS

USING 
    FCB   0
    
DSINIT
    LDY #((stringscount*4+stringsspace*2))
    LDX #DESCRIPTORS
DSINITL1
    STA ,X+
    LEAY -1, Y
    CMPY #$0
    BNE DSINITL1
    RTS

