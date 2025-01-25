; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
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
;*                            TEXT ROUTINE ON PC1403                           *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; Write a character.
; Input:    K = x; A = character to write (pc1403 encoded)
TEXTBMCHAR:

    PUSH
    LIA  0x40
	LP   0x05
	EXAM
	LIA  0x60
	LP   0x04
	EXAM
    POP
    PUSH
    INCA
    LIB 0
    ADB
    DECP
    ADB
    DECP
    ADB
    DECP
    ADB
    DECP
    ADB
    DECP
    POP

    LII 5

TEXTBMCHARL2:
 
    CALL CALCPOSG

    LIDP 0x3C00
	LDD
	PUSH
    LIA  0x09
	STD

    DY
    DXL
    IYS

    POP
    LIDP 0x3C00
    STD
    
    LP 0x08
    LDM
    INCA
    EXAM

    DECI
    JRNZM TEXTBMCHARL2

    RTN

; Write a string.
; Input:    $0c0d = address to string to write, N = characters to write
TEXTBM:

	LIDP XCURSYS
	LDD
	EXAB
    LP 0x03
	LDM
	INCA
	STD

    ; y = 0
    LP 0x09
    LIA 0x00
    EXAM

    ; x = x * 5

    LII 0x05
    EXAB
    LIP 0x08
    LIA 0
    EXAM
    EXAB
TEXTBML1:
    ADM 
    DECI
    JRNZM TEXTBML1

    LIP 0x03
    LDM

TEXTBML2:
    LP 0x0c
    LDM
    LP 0x04
    EXAM
    LP 0x0d
    LDM
    LP 0x05
    EXAM
    LIB 0
    LIA 1
    LP 0x0c
    ADB

    DX
    IXL
    
    CALL TEXTBMCHAR

    DECJ
    JRNZM TEXTBML2

    RTN
