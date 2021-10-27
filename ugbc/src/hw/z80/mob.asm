; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License");
;  * you may not use this file eXcept in compliance with the License.
;  * You may obtain a copy of the License at
;  *
;  * http://www.apache.org/licenses/LICENSE-2.0
;  *
;  * Unless required by applicable law or agreed to in writing, software
;  * distributed under the License is distributed on an "AS IS" BASIS,
;  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either eXpress or implied.
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
;*                  MOVABLE OBJECTS UNDER Z80 (generic algorithms)             *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

MOB_COUNT = $10

MOBI: DB 0
MOBX: DW 0
MOBY: DW 0
MOBW: DW 0
MOBH: DW 0
MOBADDR: DW 0
MOBSIZE: DW 0
MOBLASTX: DW 0

DSDESCRIPTOR:
    PUSH HL
    PUSH BC
    LD A, B
    LD C, A
    LD A, 0
    LD B, A
    PUSH BC
    POP HL
    ADD HL, HL
    ADD HL, HL
    ADD HL, HL
    ADD HL, HL
    ADD HL, HL
    PUSH HL
    POP DE
    LD HL, DESCRIPTORS
    ADD HL, DE
    PUSH HL
    POP IX
    POP BC
    POP HL
    RET

; Generic initialization
; MOBINIT(X:indeX,X,y,w,h,draw)
MOBINIT:

    LD (MOBI), B
    
    ; Initialize status
    LD A, 0
    LD (IX), A

    ; Initialize position
    LD A,(MOBX)
    LD (IX+1), A
    LD (IX+5), A
    LD A,(MOBX+1)
    LD (IX+2), A
    LD (IX+5), A
    LD A,(MOBY)
    LD (IX+3), A
    LD (IX+7), A
    LD A,(MOBY+1)
    LD (IX+4), A
    LD (IX+8), A

    ; Initialize size
    LD A,(MOBX)
    LD (IX+9), A
    LD A,(MOBH)
    LD (IX+10), A

    ; Save address of the given data.
    ; Note that specific chipset 
    ; initialization can easily override this.
    LD A,(MOBADDR)
    LD (IX+11), A
    LD A,(MOBADDR+1)
    LD (IX+12), A

    ; Initialize to 0 the space for saving
    ; background (again, this is a chipset specific
    ; initialization routine).
    LD A, 0
    LD (IX+13), A
    LD (IX+14), A

    ; Initialize the chipset specific part
    CALL MOBINITCS

    RET

; MOBSHOW(X:indeX)
MOBSHOW:
    LDA A, (IX)
    OR A, 1
    LD (IX), A
    RET

; MOBHIDE(X:indeX)
MOBHIDE:
    LD A, (IX)
    AND A, $FE
    LD (IX), A
    RET

; MOBSAVE(X:indeX) -> chipset
; MOBRESTORE(X:indeX) -> chipset
; MOBDRAW(X:indeX) -> chipset

MOBADJUST:
    LD A, (IX)
    AND A, 1
    JR Z,MOBADJUSTN
    LD A, (IX)
    OR A, 3
    LD (IX), A
    RET

MOBADJUSTN:
    LD A, (IX)
    AND A, $FC
    LD (IX), A
    RET

; MOBAT(X:indeX, X, y)
MOBAT:
    
    LD (MOBI), B

    LD A, (MOBX)
    LD (IX+1), A
    CP (IX+5)
    JR Z, MOBAT2
    LD A, (IX)
    OR A, 4
    LD (IX), A
MOBAT2:
    LD A, (MOBX+1)
    LD (IX+2), A
    CP (IX+5)
    JR Z, MOBAT3
    LD A, (IX)
    OR A, 4
    LD (IX), A
MOBAT3:
    LD A, (MOBY)
    LD (IX+3), A
    CP (IX+7)
    JR Z, MOBAT4
    LD A, (IX)
    OR A, 8
    LD (IX), A
MOBAT4:
    LD A, (MOBY+1)
    LD (IX+4), A
    LD (IX+8), A
    CP #0
    JR Z, MOBAT5
    LD A, (IX)
    OR A, 8
    LD (IX), A
MOBAT5:
    CALL MOBATCS

    RET

MOBALLOC:
    LD HL, (MOBADDRESS)
    LD DE, (MOBALLOCATED)
    ADD HL, DE
    LD MOBADDR, (HL)

    LD HL, (MOBALLOCATED)
    LD DE, (MOBSIZE)
    ADD HL, DE
    LD MOBADDR, (HL)

    RET

MOBFREE:
    LD HL, (MOBALLOCATED)
    LD DE, (MOBSIZE)
    SUB HL, DE
    LD MOBADDR, (HL)
    RET

MOBDESCRIPTORS:     DEFS    MOB_COUNT * 32
MOBALLOCATED:       DQ   $0

MOBRENDER:

    LD A, (MOBI)
    JR Z, MOBRENDERC
    JP VBL
    
MOBRENDERC:
    ; X = 0
    LD B, 0
    
MOBRENDERL1:
    ; take descriptor X
    LD A, (IX)

    ; unvisibled -> visibled? = $01
    ; visibled? -> unvisibled = $02
    ; moved + visibled? = $0D
    ; moved + unvisibled? = $0E
    ; moved? = $08 or $04
    AND A, 3
    CP 1
    JR Z, MOBRENDERV1
    CP 2
    JR Z, MOBRENDERV1

    ; retake descriptor X
    LD A, (IX)
    AND A, $C
    JR JZ, MOBRENDERV1

    ; ++X
    INC B

    ; X < N ?
    LD A, B
    CP MOB_COUNT
    JR NZ, MOBRENDERL1
    RET

MOBRENDERV1:
    ; LASTX = X
    LD A, B
    LD (MOBLASTX), A

    ; X = N - 1
    LD A, MOB_COUNT
    LD B, A
    DEC B

MOBRENDERL2:
    ; previously visible?
    LD A, (IX)
    AND A, 2
    JR Z, MOBRENDERV2

    LD A, B
    LD (MOBI), A

    ; restore background at pX,py (w,h) save area
    CALL MOBRESTORE

    LD A, (MOBI)
    LD B, A
    
    ; adjust visibility flag
    CALL MOBADJUST
    
MOBRENDERV2:

    ; update positions
    LD A, (IX+1)
    LD (IX+5), A
    LD A, (IX+2)
    LD (IX+6), A
    LD A, (IX+3)
    LD (IX+7), A
    LD A, (IX+4)
    LD (IX+8), A

    ; --X
    DEC B

    ; X >= LASTX
    CP B, MOBLASTX
    JR C, MOBRENDERL2
    JR Z, MOBRENDERL2

    ; Reset the save area to LAST X

MOBRENDERV3:
MOBRENDERL3:
    ; visible ?
    LD A, (IX)
    AND A, 1
    CP #0
    JR Z, MOBRENDERV4

    LD A, B
    LD (MOBI), A

    ; save background at X,y (w,h) to save area
    CALL MOBSAVE

    LD A, (MOBI)
    LD B, A

    ; draw sprite at X,y (w,h) from draw area
    CALL MOBDRAW

    LD A, (MOBI)
    LD B, A

    ; adjust visibility flag
    CALL MOBADJUST

    LD A, (MOBI)
    LD B, A

MOBRENDERV4:
    ; ++X
    DEC B

    ; X < N ?
    CP B, MOB_COUNT 
    JR NC, MOBRENDERL3

    RET