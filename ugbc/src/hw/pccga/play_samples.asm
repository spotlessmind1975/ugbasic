; /*****************************************************************************
;  * ugBASIC - an isomorphic BASIC language compiler for retrocomputers        *
;  *****************************************************************************
;  * Copyright 2021-2026 Marco Spedaletti (asimov@mclink.it)
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
;*                            PLAY SAMPLES ON PCCGA                            *
;*                                                                             *
;*                             by Marco Spedaletti                             *
;*                                                                             *
;* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

PLAYSAMPLES:
    ; --- 1. Configurazione del Timer 2 del PIT ---
    ; Invia la Control Word 10110000b (0xB0) alla porta 43h:
    ; Selezione del Canale 2, accesso LSB/MSB, Modalità 0 (Iniezione ad impulso singolo), formato binario.
    MOV AL, 0x0B0
    OUT 43h, AL

    ; --- 2. Abilitazione dell'altoparlante ---
    ; Legge lo stato della porta 61h, imposta i bit 0 e 1 per connettere il Timer 2 all'altoparlante.
    IN AL, 0x61
	OR AL, 0x03
	OUT 0x61, AL

PLAYSAMPLESL1:
	LODSB

	CMP AL, 0
	JZ PLAYSAMPLESDONE

	PUSH AX
	AND AL, 0x0F
	NOP
	NOP
	OUT 0x42, AL
	MOV AL, 0
	OUT 0x42, AL

	PUSH CX
	MOV CX, 0x00ff
PLAYSAMPLESL2L:
	LOOP PLAYSAMPLESL2L
	POP CX

	POP AX
	SHR AL
	SHR AL
	SHR AL
	SHR AL
	OUT 0x42, AL
	MOV AL, 0
	OUT 0x42, AL

	PUSH CX
	MOV CX, 0x00ff
PLAYSAMPLESL2L:
	LOOP PLAYSAMPLESL2L
	POP CX
	
	JMP PLAYSAMPLESL1

PLAYSAMPLESDONE:
	IN AL, 0x61
	AND AL, 0x61
	OUT 0x61, AL
	RET
	