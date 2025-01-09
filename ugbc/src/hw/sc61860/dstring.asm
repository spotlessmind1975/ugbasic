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

PUSHX:
    LIP 0x04
    EXAM
    PUSH
    LIP 0x05
    EXAM
    PUSH
    RTN

POPX:
    POP
    LIP 0x05
    EXAM
    POP
    LIP 0x04
    EXAM
    RTN

; ------------------------------------------------------------------------------
; DSEQUAL -> C / NC
;       Input: $0c-$0f = descriptor, X = string
;       Output: C = strings are equal / NC = strings are different
;       Saves: X
; ------------------------------------------------------------------------------

DSEQUAL:

    ; Save X

    CALL PUSHX

    ; Check to see if length differs: in this case,
    ; strings are different, by definition.

    LIP 0x0c
    IXL
    CPMA
    JRNZP DSEQUALNO

    ; I = length of the string

    LIP 0x00
    EXAM

    ; Set the address of the string to check,
    ; taking it from the descriptor.
    ; Self modifying code, oh dear!

    LIP 0x0d
    LDM
    LIDP DSEQUALL1ADDRESS
    STD
    LIP 0x0e
    LDM
    LIDP DSEQUALL1ADDRESS+1
    STD

    ; Now we start a loop to check if the
    ; two strings are equal, char by char.

DSEQUALL1:

    LIP 0x03

DSEQUALL1ADDRESS:

    ; Load characteer of target string in B ANIA the
    ; character of descriptor's string in A. If they
    ; are different, the strings are different.

    IXL
    EXAM
    LIDP 0x0000
    LDD
    CPMA
    JRNZP DSEQUALNO

    ; Increment the descriptor's string address.
    ; Self modifying code, oh dear!

    LIDP DSEQUALL1ADDRESS
    LDD
    INCA
    STD
    CPIA 0
    JRNZP DSEQUALL1ADDRESSIDONE
    LIDP DSEQUALL1ADDRESS+1
    LDD
    INCA
    STD
DSEQUALL1ADDRESSIDONE:

    ; Pass to the next character.
    DECI
    JRNZM DSEQUALL1

    ; If we arrived here, the strings are equal.
DSEQUALYES:
    
    ; Restore X

    CALL POPX

    SC
    RTN

DSEQUALNO:

    ; Restore X

    CALL POPX

    RC
    RTN

; ------------------------------------------------------------------------------
; DSFINDEQUAL
;       Input: X = string
;       Output: B = string slot or 0 if no string has been found
; ------------------------------------------------------------------------------

DSFINDEQUAL:

    ; By default, the descriptor 0 is not used, to be able to manage
    ; a "uninitialized" descriptor's string.

    LIA 1
    EXAB

DSFINDEQUALL:

    ; Retrieve the descriptor for the current (B) dynamic string.

    CALL DSDESCRIPTOR

    ; Check if the current dynamic string is a static string.
    ; If so, we move to the logic of the routine.

    LIP 0x0f
    LDM
    ANIA 0xc0
    CPIA 0xc0
    JRZP DSFINDEQUALF1

DSFINDEQUALF2:

    ; The current (B) dynamix string is empty or it is
    ; a dynamic string. So we can move forward to the next
    ; string.

    EXAB
    INCA
    EXAB

    ; We must check if all strings have been cheched.
    ; If not, repeat for the next string.

    LIDP MAXSTRINGS
    LDD
    LIP 0x03
    CPMA
    JPNZ DSFINDEQUALL

DSFINDEQUALNO:

    ; No string found equal to the given one.

    LIA 0
    EXAB

    RTN
    
DSFINDEQUALF1:

    ; Check if the searched string (X) ANIA the string pointed
    ; by the descriptor are equal.

    CALL DSEQUAL

    ; If they are not equal, we must check the next string.

    JPNC DSFINDEQUALF2

DSFINDEQUALYES:

    ; We found it!

    RTN

; ------------------------------------------------------------------------------
; DSDEFINE
;       Input: X = string
;       Output: B = string slot
; ------------------------------------------------------------------------------

DSDEFINE:

    ; Save X

    CALL PUSHX

    ; Try to check if another string like this has been already defined.

    CALL DSFINDEQUAL

    ; If the string descriptor is zero, it means that there is
    ; no another string like this. Otherwise, we do not need to do
    ; anything else.

    LIP 0x03
    LDM
    CPIA 0
    JRNZP DSDEFINEE

    ; There is no another string like this. So we must
    ; find out a free dynamic string slot.

    CALL DSFINDFREE

    ; Prepare descriptor for this string.

    IXL 
    LIP 0x0c
    EXAM
    LIP 0x04
    EXAM
    LIP 0x0d
    EXAM
    LIP 0x05
    EXAM
    LIP 0x0e
    EXAM
    LIA 0xc0
    LIP 0x0f
    EXAM

    ; Save the descriptor, for later use.

    CALL DSDESCRIPTORSAVE

DSDEFINEE:

    ; Restore X
    
    CALL POPX

    RTN

; ------------------------------------------------------------------------------
; DSALLOC
;       Input: K = size
;       Output: B = string slot
; ------------------------------------------------------------------------------

DSALLOC:

    ; First of all, we try to find out a free slot to use.

    CALL DSFINDFREE

    ; Retrieve the descriptor for this slot.

    CALL DSDESCRIPTOR

    ; Update the flag's status

    LIP 0x0f
    LDM
    ORIA 0x40
    EXAM

    ; Update the descriptor.

    CALL DSDESCRIPTORSAVE

    ; Check if there is enough space in string area.

    CALL DSCHECKFREE

    ; Retrieve the working area to use (WORKING / TEMPORARY)
    
    CALL DSUSING

    ; Allocate enough space to store the string.
    
    CALL DSMALLOC

    RTN

; $00	I	 	Indexes
; $01	J
; $02	A	 	Accumulators
; $03	B
; $04	Xl
; $05	Xh
; $06	Yl
; $07	Yh
; $08	K
; $09	L
; $0a	M
; $0b	N
; $0c	[ IX ]
; $0d   [ IX+1 ]
; $0e
; $0f

; ------------------------------------------------------------------------------
; DSFREE
;       Input: B = string slot
;       Output: 
; ------------------------------------------------------------------------------

DSFREE:

    ; Retrieve the descriptor for the current (B) slot.

    CALL DSDESCRIPTOR

    ; Update the flag.

    LIA 0
    LIP 0x0f
    EXAM
    
    ; Update the descriptor.

    CALL DSDESCRIPTORSAVE

    RTN

; ------------------------------------------------------------------------------
; DSWRITE
;       Input: B = string slot
;       Output: 
; ------------------------------------------------------------------------------

DSWRITE:

    ; Retrieve the descriptor for the current (B) slot

    CALL DSDESCRIPTOR

    ; Check if it is already writable.

    LIP 0x0f
    LDM
    ANIA 0x80
    CPIA 0x00
    JRZP DSWRITED

    ; No, it is not. So we must make it writable.

    ; First of all, save the slot.

    EXAB
    PUSH

    ; Then, try to check if enough space is available.

    LIP 0x0c
    LDM
    CALL DSCHECKFREE

    ; Now, we must make this descriptor for a writable string.

    LIP 0x0f
    LDM
    ANIA 0x7f
    EXAM

    ; Next, take down the address of the static string
    ; ANIA put it on the X register.

    LIP 0x0d
    LDM
    LIP 0x04
    EXAM
    LIP 0x0e
    LDM
    LIP 0x05
    EXAM

    ; LD D, B
DSWRITEOK:
    ; LD C, (IX+1)
    ; LD B, (IX+2)
    ; PUSH BC

    ; Retrieve the active string area.

    CALL DSUSING

    ; Alloc a string with same size for the given slot.

    LIP 0x0c
    LDM
    POP
    CALL DSMALLOC

    ; Now retrieve the address of the new string,
    ; ANIA put it on the Y register.

    LIP 0x0d
    LDM
    LIP 0x06
    EXAM
    LIP 0x0e
    LDM
    LIP 0x07
    EXAM

DSCOPY:

    ; Take the number of the characters of this string.

    LIP 0x0c
    LDM

    ; If zero, no copy is needed.

    CPIA 0x00
    JRZP DSWRITED

    ; I = number of characters

    LIP 0x00
    EXAM

DSWRITECOPY:

    ; Copy all the characters 

    IXL
    IYS
    DECI
    JRNZM DSWRITECOPY

DSWRITED:

    RTN

; ------------------------------------------------------------------------------
; RESIZE
;       Input: B = string slot, K = new size
;       Output: 
; ------------------------------------------------------------------------------

DSRESIZE:

    ; Retrieve the descriptor for this string slot.

    CALL DSDESCRIPTOR

    ; Change the size inside the descriptor.

    LIP 0x08
    LDM
    LIP 0x0c
    EXAM

    ; If the size is non zero, we finished.

    LIP 0x08
    LDM
    JRNZP DSRESIZEDONE

    ; If the size is zero, we can consider the slot as "empty".

    LIP 0x0f
    LDM
    ORIA 0x80
    EXAM

DSRESIZEDONE:

    ; Update the descriptor.

    CALL DSDESCRIPTORSAVE

    RTN

; ------------------------------------------------------------------------------
; DSGC
;       Input:
;       Output: 
; ------------------------------------------------------------------------------

DSGC:

    ; Reset the free string space.

    LIDP FREE_STRING
    LIA max_free_string
    STD
    LIDP FREE_STRING+1
    LIA >max_free_string
    STD

    ; Use the complement string area to perform garbage collection.

    LIDP USING
    LDD
    CPIA 0x00
    JRZP DSGT
    JRNZP DSGW
DSGT:
    LIDP TEMPORARY
    DY
    IY
    JP BSGCLOOP0
DSGW:
    LIDP WORKING
    DY
    IY
BSGCLOOP0:

    ; Starts from the first slot.

    LIA 0x01
    EXAB

DSGCLOOP:

    ; Retrieve the descriptor for the current (B) slot

    CALL DSDESCRIPTOR

    ; Check if is a static string. In this case,
    ; the space is not effectively occupied.
    ; So we can go ahead with the next slot.

    LIP 0x0f
    LDM
    ANIA 0x80
    CPIA 0x00
    JRNZP DSGCLOOP2

    ; Next, we check if it is effectively used.
    ; If it is not used, it can go ahead with the next slot.

    LIP 0x0f
    LDM
    ANIA 0x40
    CPIA 0x00
    JRZP DSGCLOOP2

    ; It is used but it is an empty string?
    ; In this case, we can go ahead with the next slot.

    LIP 0x0c
    LDM
    CPIA 0x00
    JRZP DSGCLOOP3

    ; Next, take down the address of the static string
    ; ANIA put it on the X register.

    LIP 0x0d
    LDM
    LIP 0x04
    EXAM
    LIP 0x0e
    LDM
    LIP 0x05
    EXAM

    ; Allocate a new string for this slot, with the same
    ; size of the original one.

    LIP 0x0c
    LDM
    LIP 0x08
    EXAM
    CALL DSMALLOC

    ; Now retrieve the address of the new string,
    ; ANIA put it on the Y register.

    LIP 0x0d
    LDM
    LIP 0x06
    EXAM
    LIP 0x0e
    LDM
    LIP 0x07
    EXAM

    ; Copy the old string in the new string

    LIP 0x08
    LDM
    LIP 0x00
    EXAM

    CALL DSWRITECOPY

    JP DSGCLOOP3

DSGCLOOP2:
    JP DSGCLOOP3

DSGCLOOP3:

    ; Move into the next slot

    EXAB
    INCA
    EXAB

    ; We must check if all strings have been collected.
    ; If not, repeat for the next slot.

    LIDP MAXSTRINGS
    LDD
    LIP 0x03
    CPMA
    JRNZM DSGCLOOP

DSGCEND:

    ; We must change the string space.

    LIDP USING
    LDD
    CPIA 0
    JRZP DSGCEND0

    LIA 0x00
    STD

DSGCEND0:
    LIA 0x01
    STD

    RTN

; ------------------------------------------------------------------------------
; DSFINDFREE
;       Input:
;       Output: B = slot number
; ------------------------------------------------------------------------------

; DSFINDFREE() -> B
DSFINDFREE:

    ; By default, the descriptor 0 is not used, to be able to manage
    ; a "uninitialized" descriptor's string.

    LIA 1
    EXAB

DSFINDFREEL:

    ; Retrieve the descriptor for this dynamic string slot.

    CALL DSDESCRIPTOR

    ; We must check if the string is free.
    ; If the bit 6 is 0, it means that the slot is free.
    ; In this case, we return the current string slot (B).

    LIP 0x0f
    LDM
    ANIA 0x40
    CPIA 0x00
    JRZP DSFINDFREEN

    ; Move to the next slot.

    EXAB
    INCA
    EXAB

    ; We must check if all slots have been cheched.
    ; If not, repeat for the next slot.

    LIDP MAXSTRINGS
    LDD
    LIP 0x03
    CPMA
    JPNZ DSFINDEQUALL

    ; Out of memory!

    JP OUT_OF_MEMORY

DSFINDFREEN:

    ; We found a slot, return it.

    RTN

OUT_OF_MEMORY2:
    JP OUT_OF_MEMORY

; ------------------------------------------------------------------------------
; DSMALLOC
;       Input: Y = working / temporary area, K = number of characters, B = slot
;       Output:
; ------------------------------------------------------------------------------

DSMALLOC:

    ; Save the slot
    
    EXAB
    PUSH

    ; Retrieve the descriptor for the given slot.

    CALL DSDESCRIPTOR

    ; Calculate the starting address.

    PUSH
    LIDP FREE_STRING+1
    LDD
    EXAB
    LIDP FREE_STRING
    LDD
    LIP 0x06
    ADB
    LIA 0
    EXAB
    POP
    LIP 0x08
    LDM
    LIP 0x06
    SBB

    ; Update the descriptor.

    LIP 0x0c
    EXAM
    LIP 0x06
    LDM
    LIP 0x0d
    EXAM
    LIP 0x07
    LDM
    LIP 0x0e
    EXAM

    ; Save the updated descriptor

    POP
    CALL DSDESCRIPTORSAVE

    RTN

; ------------------------------------------------------------------------------
; DSCHECKFREE
;       Input: K = size to check
;       Output:
; ------------------------------------------------------------------------------

DSCHECKFREE:

DSCHECKFREE2:

    ; First of all, we check if there is enough space in the remaining 
    ; string space.

    LIP 0x08
    LDM
    LIP 0x01
    EXAM
    LIA 0
    LIP 0x00
    EXAM

    LIDP FREE_STRING+1
    LDD
    EXAB
    LIDP FREE_STRING
    LDD
    EXAB
    
DSCHECKFREE2CP:
	LP	1
	CPMA
	JRZP	DSCHECKFREE2CPLT16U2
	JRNCP	DSCHECKFREE2CPLT16U1
	JP DSCHECKFREEOK

DSCHECKFREE2CPLT16U2:
	LP	0
	EXAB
	CPMA
	JRNCP	DSCHECKFREE2CPLT16U1
	JRZP	DSCHECKFREE2CPLT16U1
	JP DSCHECKFREEOK

DSCHECKFREE2CPLT16U1:

DSCHECKFREEKO:

    ; Not enough space remaining: try to do some string
    ; garbage collection.

    CALL DSGC

    ; Try again

    JP DSCHECKFREE2

DSCHECKFREEOK:

    RTN

; ------------------------------------------------------------------------------
; DSUSING
;       Input: 
;       Output: Y = area string to use
; ------------------------------------------------------------------------------

DSUSING:

    ; The USING variable stores the actual string area to use.
    ; 0 = WORKING; 1 = temporary

    LIDP USING
    LDD
    CPIA 0
    JRZP DSUSINGW
    JRNZP DSUSINGT
DSUSINGT:
    LIDP TEMPORARY
    DY
    IY
    RTN
DSUSINGW:
    LIDP WORKING
    DY
    IY
    RTN

; ------------------------------------------------------------------------------
; DSDESCRIPTOR
;       Input: B = number of descriptor
;       Output: $0c-$0f = descriptor
; ------------------------------------------------------------------------------

DSDESCRIPTOR:

    ; Save A ANIA X registers

    PUSH
    CALL PUSHX

    ; X = DESCRIPTORS

    LIA DESCRIPTORS
    LIP 0x04
    EXAM
    LIA > DESCRIPTORS
    LIP 0x05
    EXAM

    ; X = X + (size of descriptor) x B
    ;  B <-> A -> (B,0) <-> (0,B)
    ;          -> X = X + (0,B) + (0,B) + (0,B) + (0,B) = X + 4 x (0,B)
    LIA 0
    EXAB

    ; we must save previous B value!
    PUSH 

    LIP 0x04
    ADB
    LIP 0x04
    ADB
    LIP 0x04
    ADB
    LIP 0x04
    ADB

    ; DP = X

    DX
    IX

    LIP 0x0c
    LII 4
    MVWD

    ; we must restore previous B value!
    POP
    EXAB

    ; Restore X ANIA A registers

    CALL POPX
    POP

    RTN

; ------------------------------------------------------------------------------
; DSDESCRIPTORSAVE
;       Input: B = number of descriptor, $0c-$0f = descriptor
;       Output:
; ------------------------------------------------------------------------------

DSDESCRIPTORSAVE:

    ; Save A register

    PUSH

    ; Y = DESCRIPTORS

    LIA DESCRIPTORS
    LIP 0x06
    EXAM
    LIA > DESCRIPTORS
    LIP 0x07
    EXAM

    ; Y = Y + (size of descriptor) x B
    ;  B <-> A -> (B,0) <-> (0,B)
    ;          -> Y = Y + (0,B) + (0,B) + (0,B) + (0,B) = Y + 4 x (0,B)

    LIA 0
    EXAB

    ; we must save previous B value!
    PUSH 
    
    LIP 0x06
    ADB
    LIP 0x06
    ADB
    LIP 0x06
    ADB
    LIP 0x06
    ADB

    ; DP = Y

    DY

    LIP 0x0c
    LDM
    IYS
    LIP 0x0d
    LDM
    IYS
    LIP 0x0e
    LDM
    IYS
    LIP 0x0f
    LDM
    IYS

    ; Restore previous B value!

    POP 
    EXAB

    ; Restore A register

    POP

    RTN

OUT_OF_MEMORY:
    JP OUT_OF_MEMORY

; ------------------------------------------------------------------------------
; DSINIT
;       Input:
;       Output:
; ------------------------------------------------------------------------------

DSINIT:

    LIA stringscount
    LIDP MAXSTRINGS
    STD
    LIA stringsspace
    LIDP FREE_STRING
    STD
    LIA >stringsspace
    LIDP FREE_STRING+1
    STD

    LIA 0
    LIDP DESCRIPTORS
    LII (stringscount*4+stringsspace*2)
    FILD 
    LIJ >(stringscount*4+stringsspace*2)
    LIP 0x01
    LDM
    CPIA 0
    JRZP DSINITDONE
DSINITL1:
    DECJ
    JRNZM DSINITL1
DSINITDONE:
    RTN
