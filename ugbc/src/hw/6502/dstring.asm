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

; DSDEFINE($23:$22) -> X
DSDEFINE:
    JSR DSFINDFREE
    LDA DESCRIPTORS_STATUS,X
    ORA #$C0
    STA DESCRIPTORS_STATUS,X
DSDEFINEN:
    LDY #0
    LDA ($22),Y
    STA DESCRIPTORS_SIZE,X

    CLC
    LDA $22
    ADC #1
    STA $22
    LDA $23
    ADC #0
    STA $23

    LDA $22
    STA DESCRIPTORS_ADDRESS_LO,X
    LDA $23
    STA DESCRIPTORS_ADDRESS_HI,X
    RTS

; DSALLOC($21) -> X
DSALLOC:
    JSR DSFINDFREE

    LDA DESCRIPTORS_STATUS,X
    ORA #$40
    STA DESCRIPTORS_STATUS,X

    JSR DSCHECKFREE

DSALLOCOK:
    JSR DSUSING
    JSR DSMALLOC
    RTS

; DSFREE(X)
DSFREE:
    LDA #$0
    STA DESCRIPTORS_STATUS,X
    RTS

; DSWRITE(X)
DSWRITE:
    LDA DESCRIPTORS_STATUS,X
    AND #$80
    BEQ DSWRITED
    LDA DESCRIPTORS_STATUS,X
    AND #$7F
    STA DESCRIPTORS_STATUS,X
    JSR DSCHECKFREE
DSWRITEOK:
    LDA DESCRIPTORS_ADDRESS_LO,X
    STA $22
    LDA DESCRIPTORS_ADDRESS_HI,X
    STA $23
    LDA DESCRIPTORS_SIZE,X
    STA $21
    JSR DSUSING
    JSR DSMALLOC
    LDA DESCRIPTORS_ADDRESS_LO,X
    STA $24
    LDA DESCRIPTORS_ADDRESS_HI,X
    STA $25
    LDA DESCRIPTORS_SIZE,X
    STA $21
    TAY
DSCOPY:
    LDY #0
DSWRITECOPY:
    LDA ($22),Y
    STA ($24),Y
    INY
    CPY $21
    BNE DSWRITECOPY
DSWRITED:
    RTS

; DSGC()
DSGC:
    LDA #<max_free_string
    STA FREE_STRING
    LDA #>max_free_string
    STA FREE_STRING+1

    LDA USING
    BEQ DSGT
    JMP DSGW

DSGT:
    LDA #<TEMPORARY
    STA $30
    LDA #>TEMPORARY
    STA $31
    JMP BSGCLOOP0

DSGW:
    LDA #<WORKING
    STA $30
    LDA #>WORKING
    STA $31
    JMP BSGCLOOP0

BSGCLOOP0:
    LDX #0
DSGCLOOP:
    LDA DESCRIPTORS_STATUS,X
    AND #$40
    BEQ DSGCLOOP2

    LDA DESCRIPTORS_ADDRESS_LO,X
    STA $22
    LDA DESCRIPTORS_ADDRESS_HI,X
    STA $23

    JSR DSMALLOC
    
    LDA DESCRIPTORS_ADDRESS_LO,X
    STA $24
    LDA DESCRIPTORS_ADDRESS_HI,X
    STA $25

    JSR DSWRITECOPY

    JMP DSGCLOOP3

DSGCLOOP2:
    LDA #0
    STA DESCRIPTORS_SIZE, X
    JMP DSGCLOOP3

DSGCLOOP3:
    INX
    BEQ DSGCEND
    JMP DSGCLOOP
DSGCEND:
    LDX #0
    LDA USING
    EOR #$FF
    STA USING
    RTS

; DSFINDFREE() -> X
DSFINDFREE:
    LDX #0
DSFINDFREEL:
    LDA DESCRIPTORS_STATUS,X
    AND #$40
    BEQ DSFINDFREEN
    INX
    BEQ OUT_OF_MEMORY2
    JMP DSFINDFREEL
DSFINDFREEN:
    RTS

OUT_OF_MEMORY2:
    JMP OUT_OF_MEMORY

; DSMALLOC($31:$30,$21,X)
DSMALLOC:
    SEC
    LDA FREE_STRING
    SBC $21
    STA FREE_STRING
    LDA FREE_STRING+1
    SBC #0
    STA FREE_STRING+1

    CLC
    LDA $30
    ADC FREE_STRING
    STA $30
    LDA $31
    ADC FREE_STRING+1
    STA $31

    LDA $30
    STA DESCRIPTORS_ADDRESS_LO,X
    LDA $31
    STA DESCRIPTORS_ADDRESS_HI,X    
    LDA $21
    STA DESCRIPTORS_SIZE,X    

    RTS

; DSCHECKFREE()
DSCHECKFREE:
    LDA #0
    CMP FREE_STRING+1
    BCC DSCHECKFREEOK
    LDA $21
    CMP FREE_STRING
    BCC DSCHECKFREEOK
    JSR DSGC
    JMP DSCHECKFREE
DSCHECKFREEOK:
    RTS

; DSUSING() -> $31:$30
DSUSING:
    LDA USING
    BEQ DSUSINGW
    JMP DSUSINGT
DSUSINGT:
    LDA #<TEMPORARY
    STA $30
    LDA #>TEMPORARY
    STA $31
    RTS
DSUSINGW:
    LDA #<WORKING
    STA $30
    LDA #>WORKING
    STA $31
    RTS

; DSDESCRIPTOR(X) -> $23:$22:$21:$20
DSDESCRIPTOR:
    LDA DESCRIPTORS_STATUS,X
    STA $20
    LDA DESCRIPTORS_ADDRESS_LO,X
    STA $22
    LDA DESCRIPTORS_ADDRESS_HI,X
    STA $23
    LDA DESCRIPTORS_SIZE,X
    STA $21
    RTS
  
OUT_OF_MEMORY:
    JMP OUT_OF_MEMORY


MAXSTRINGS:     .BYTE 255

DESCRIPTORS_STATUS:
    .RES    255
DESCRIPTORS_ADDRESS_LO:
    .RES    255
DESCRIPTORS_ADDRESS_HI:
    .RES    255
DESCRIPTORS_SIZE:
    .RES    255

WORKING:
    .RES     1024
TEMPORARY:
    .RES     1024
USING:
    .BYTE   0
    
FREE_STRING:
    .WORD   max_free_string
