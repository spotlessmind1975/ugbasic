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

; DSDEFINE(DSADDRHI:DSADDRLO) -> X
DSDEFINE:
    JSR DSFINDFREE
    LDA DESCRIPTORS_STATUS,X
    ORA #$C0
    STA DESCRIPTORS_STATUS,X
DSDEFINEN:
    LDY #0
    LDA (DSADDRLO),Y
    STA DESCRIPTORS_SIZE,X

    CLC
    LDA DSADDRLO
    ADC #1
    STA DSADDRLO
    LDA DSADDRHI
    ADC #0
    STA DSADDRHI

    LDA DSADDRLO
    STA DESCRIPTORS_ADDRESS_LO,X
    LDA DSADDRHI
    STA DESCRIPTORS_ADDRESS_HI,X
    RTS

; DSALLOC(DSSIZE) -> X
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
    STA DESCRIPTORS_SIZE,X
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
    STA DSADDRLO
    LDA DESCRIPTORS_ADDRESS_HI,X
    STA DSADDRHI
    LDA DESCRIPTORS_SIZE,X
    STA DSSIZE
    JSR DSUSING
    JSR DSMALLOC
    LDA DESCRIPTORS_ADDRESS_LO,X
    STA TMPPTR2
    LDA DESCRIPTORS_ADDRESS_HI,X
    STA TMPPTR2+1
    LDA DESCRIPTORS_SIZE,X
    STA DSSIZE
    TAY
DSCOPY:
    LDY DSSIZE
    CPY #0
    BEQ DSWRITED
    LDY #0
DSWRITECOPY:
    LDA (DSADDRLO),Y
    STA (TMPPTR2),Y
    INY
    CPY DSSIZE
    BNE DSWRITECOPY
DSWRITED:
    RTS

; DSRESIZE(X,DSSIZE)
DSRESIZE:
    LDA DSSIZE
    STA DESCRIPTORS_SIZE,X
    RTS

DSUSING2:
    LDA USING
    BEQ DSGT
    JMP DSGW

DSGT:
    LDA #<TEMPORARY
    STA DSBANKLO
    LDA #>TEMPORARY
    STA DSBANKHI
    RTS

DSGW:
    LDA #<WORKING
    STA DSBANKLO
    LDA #>WORKING
    STA DSBANKHI
    RTS

; DSGC()
DSGC:
    LDA #<max_free_string
    STA FREE_STRING
    LDA #>max_free_string
    STA FREE_STRING+1

    JSR DSUSING2

BSGCLOOP0:
    LDX #1
DSGCLOOP:
    LDA DESCRIPTORS_STATUS,X
    AND #$80
    BNE DSGCLOOP2
    LDA DESCRIPTORS_STATUS,X
    AND #$40
    BEQ DSGCLOOP1

    LDA DESCRIPTORS_ADDRESS_LO,X
    STA DSADDRLO
    LDA DESCRIPTORS_ADDRESS_HI,X
    STA DSADDRHI
    LDA DESCRIPTORS_SIZE,X
    STA DSSIZE

    JSR DSUSING2
    JSR DSMALLOC
    
    LDA DESCRIPTORS_ADDRESS_LO,X
    STA TMPPTR2
    LDA DESCRIPTORS_ADDRESS_HI,X
    STA TMPPTR2+1
    LDA DESCRIPTORS_SIZE,X
    STA DSSIZE

    JSR DSCOPY

    JMP DSGCLOOP3

DSGCLOOP1:
    LDA #0
    STA DESCRIPTORS_SIZE, X
    JMP DSGCLOOP3

DSGCLOOP2:
    ; LDA #0
    ; STA DESCRIPTORS_SIZE, X
    JMP DSGCLOOP3

DSGCLOOP3:
    INX
    CPX MAXSTRINGS
    BEQ DSGCEND
    JMP DSGCLOOP
DSGCEND:
    LDX #1
    LDA USING
    EOR #$FF
    STA USING
    RTS

; DSFINDFREE() -> X
DSFINDFREE:
    LDX #1 ; fix -- 0 is used to denote unused slot
DSFINDFREEL:
    LDA DESCRIPTORS_STATUS,X
    AND #$40
    BEQ DSFINDFREEN
    INX
    CPX MAXSTRINGS
    BEQ OUT_OF_MEMORY2
    JMP DSFINDFREEL
DSFINDFREEN:
    RTS

OUT_OF_MEMORY2:
    JMP OUT_OF_MEMORY

; DSMALLOC(DSBANKHI:DSBANKLO,DSSIZE,X)
DSMALLOC:
    LDA DSSIZE
    CMP #0
    BEQ DSMALLOC0

    SEC
    LDA FREE_STRING
    SBC DSSIZE
    STA FREE_STRING
    LDA FREE_STRING+1
    SBC #0
    STA FREE_STRING+1

DSMALLOC0:
    CLC
    LDA DSBANKLO
    ADC FREE_STRING
    STA DSBANKLO
    LDA DSBANKHI
    ADC FREE_STRING+1
    STA DSBANKHI

    LDA DSBANKLO
    STA DESCRIPTORS_ADDRESS_LO,X
    LDA DSBANKHI
    STA DESCRIPTORS_ADDRESS_HI,X    
    LDA DSSIZE
    STA DESCRIPTORS_SIZE,X    

    RTS

; DSCHECKFREE()
DSCHECKFREE:
    LDA #$80
    CMP FREE_STRING+1
    BCC DSCHECKFREEKO

    LDA #$00
    CMP FREE_STRING+1
    BCC DSCHECKFREEOK

    LDA DSSIZE
    CMP FREE_STRING
    BCC DSCHECKFREEOK

DSCHECKFREEKO:    
    JSR DSGC
    JMP DSCHECKFREE
DSCHECKFREEOK:
    RTS

; DSUSING() -> DSBANKHI:DSBANKLO
DSUSING:
    LDA USING
    BEQ DSUSINGW
    JMP DSUSINGT
DSUSINGT:
    LDA #<TEMPORARY
    STA DSBANKLO
    LDA #>TEMPORARY
    STA DSBANKHI
    RTS
DSUSINGW:
    LDA #<WORKING
    STA DSBANKLO
    LDA #>WORKING
    STA DSBANKHI
    RTS

; DSDESCRIPTOR(X) -> DSADDRHI:DSADDRLO:DSSIZE:DSSTATUS
DSDESCRIPTOR:
    LDA DESCRIPTORS_STATUS,X
    STA DSSTATUS
    LDA DESCRIPTORS_ADDRESS_LO,X
    STA DSADDRLO
    LDA DESCRIPTORS_ADDRESS_HI,X
    STA DSADDRHI
    LDA DESCRIPTORS_SIZE,X
    STA DSSIZE
    RTS
  
OUT_OF_MEMORY:
    JMP OUT_OF_MEMORY

USING:
    .BYTE   0
