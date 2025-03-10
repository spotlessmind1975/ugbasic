; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2025 Marco Spedaletti (asimov@mclink.it)
;  *
;  * Licensed under the Apache License, Version 2.0 (the "License
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
;  * (la "Licenza è proibito usare questo file se non in conformità alla
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
;*                             DSAVE ROUTINE ON CPC                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

; HL: filename, B: filename length
; DE: address, IX: size to save
CPCDSAVE:

    PUSH DE
    PUSH HL
    PUSH BC

    CALL CPCIRQSYSTEM

    LD DE, $40
    LD HL, $B0FF
    CALL $BCCB
    POP BC
    POP HL

    LD DE, $C000
    CALL $BC8C
    POP DE

    JR NC, CPCDSAVEERROR

    ; Write the output file directly from store.

    ; Action:
    ; Write the contents of store directly out to the output file.

    ; Entry conditions:
    ; HL contains the address of the data to write (to go into the header).
    LD HL, DE
    
    ; DE contains the length of the data to write (to go into the header).
    PUSH IX
    POP DE

    ; BC contains the entry address (to go into the header).
    LD BC, DE

    ; A contains the file type (to go into the header).
    ; Exit conditions:

    ; If the file was written OK:
    ; Carry true.
    ; Zero false.
    ; A corrupt.

    ; If the stream is not open as expected:
    ; Carry false.
    ; Zero false.
    ; A = error number, #0E.

    ; If failed for any other reason:
    ; Carry false.
    ; Zero true.
    ; A = error number.
    ; Always:
    ; BC, DE, HL, IX and other flags corrupt.
    ; All other registers preserved.

    ; Notes:
    ; After writing the file it must be closed using CAS OUT CLOSE to ensure that the file is written to disc.
    ; It is not possible to change the method for writing files from character output (using CAS OUT CHAR) to direct output (using CAS OUT DIRECT) or vice versa once the method has been chosen. Nor is it possible to directly write a file in two or more parts by calling CAS OUT DIRECT more than once - this will write corrupt data

    CALL $BC98
    
    CALL $BC8F

    JP CPCDSAVEDONE

CPCDSAVEERROR:
    LD (DLOADERROR), A

CPCDSAVEDONE:

    CALL CPCIRQUGBASIC
    
	DI
	LD HL, IRQTIMERVOID
	LD A, L
	LD (IRQTIMERADDR+1), A
	LD A, H
	LD (IRQTIMERADDR+2), A
	EXX
	LD B, $7F
	LD A, (GAVALUE)
	OR A, $0C
	LD (GAVALUE), A
	LD C, A
	OUT (C), C
	EXX
	EI

    CALL RESETPALETTE

    RET

